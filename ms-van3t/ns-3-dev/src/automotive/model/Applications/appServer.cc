/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 * Edited by Francesco Raviglione and Marco Malinverno, Politecnico di Torino
 * (francescorav.es483@gmail.com)
 * (marco.malinverno@polito.it)
*/
#include "appServer.h"

#include "ns3/CAM.h"
#include "ns3/DENM.h"
#include "ns3/socket.h"

namespace ns3
{
  NS_LOG_COMPONENT_DEFINE("appServer");

  NS_OBJECT_ENSURE_REGISTERED(appServer);

  TypeId
  appServer::GetTypeId (void)
  {
    static TypeId tid =
        TypeId ("ns3::appServer")
        .SetParent<Application> ()
        .SetGroupName ("Applications")
        .AddConstructor<appServer> ()
        .AddAttribute ("AggregateOutput",
           "If it is true, the server will print every second an aggregate output about cam and denm",
           BooleanValue (false),
           MakeBooleanAccessor (&appServer::m_aggregate_output),
           MakeBooleanChecker ())
        .AddAttribute ("RealTime",
           "To compute properly timestamps",
           BooleanValue(false),
           MakeBooleanAccessor (&appServer::m_real_time),
           MakeBooleanChecker ())
        .AddAttribute ("CSV",
            "CSV log name.",
            StringValue (),
            MakeStringAccessor (&appServer::m_csv_name),
            MakeStringChecker ())
        .AddAttribute ("T2C",
            "T2C threshold for the CAS.",
            DoubleValue (),
            MakeDoubleAccessor (&appServer::m_t2c_threshold),
            MakeDoubleChecker <double> ())
        .AddAttribute ("Client",
           "TraCI client for SUMO",
           PointerValue (0),
           MakePointerAccessor (&appServer::m_client),
           MakePointerChecker<TraciClient> ());
        return tid;
  }

  appServer::appServer ()
  {
    NS_LOG_FUNCTION(this);
    m_client = nullptr;
    m_cam_received = 0;
    m_denm_sent = 0;
    m_t2c_threshold = 5;
  }

  appServer::~appServer ()
  {
    NS_LOG_FUNCTION(this);
  }

  void
  appServer::DoDispose (void)
  {
    NS_LOG_FUNCTION(this);
    Application::DoDispose ();
  }

  void
  appServer::StartApplication (void)
  {
    NS_LOG_FUNCTION(this);

    /* TX socket for DENMs and RX socket for CAMs (one socket only is necessary) */
    TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");

    m_socket = Socket::CreateSocket (GetNode (), tid);

    // Bind the socket to receive packets coming from every IP
    InetSocketAddress local_denm = InetSocketAddress (Ipv4Address::GetAny (), 9);
    if (m_socket->Bind (local_denm) == -1)
      {
        NS_FATAL_ERROR ("Failed to bind server socket");
      }
    m_socket->SetRecvCallback (MakeCallback (&CABasicService::receiveCam, &m_caService));

    /* Set sockets, callback and station properties in DENBasicService */
    m_denService.setSocketTx (m_socket);

    // Setting a station ID (for instance, 777888999)
    m_denService.setStationProperties (777888999, StationType_roadSideUnit);

    /* Set callback and station properties in CABasicService (which will only be used to receive CAMs) */
    m_caService.setStationProperties (777888999, StationType_roadSideUnit);
    m_caService.addCARxCallback (std::bind(&appServer::receiveCAM,this,std::placeholders::_1,std::placeholders::_2));

    if (!m_csv_name.empty ())
      {
        m_csv_ofstream_cam.open (m_csv_name+"-server.csv",std::ofstream::trunc);
        m_csv_ofstream_cam << "cam_received,denm_sent,average_cam_delay,cumulate_delay" << std::endl;
      }

    /* If aggregate output is enabled, start it */
    if (m_aggregate_output)
      m_aggegateOutputEvent = Simulator::Schedule (Seconds(1), &appServer::aggregateOutput, this);

    /* Set the callbac so that the collision detectr can directly trigger DENM */
    m_collisionAvoidanceSystem.sendDENMCallback (std::bind(&appServer::TriggerDenm,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4,std::placeholders::_5,std::placeholders::_6,std::placeholders::_7));
    m_collisionAvoidanceSystem.setT2CThreshold (m_t2c_threshold);
    m_collisionAvoidanceSystem.setRealTime (m_real_time);
  }

  void
  appServer::StopApplication ()
  {
    NS_LOG_FUNCTION(this);
    Simulator::Cancel (m_aggegateOutputEvent);

    double avg_delay = m_cumulate_delay/m_cam_received;
    m_denService.cleanup();

    if (!m_csv_name.empty ())
      {
        m_csv_ofstream_cam << m_cam_received << "," << m_denm_sent << "," << avg_delay << "," << m_cumulate_delay << std::endl;
        m_csv_ofstream_cam.close ();
      }

    if (m_aggregate_output)
      std::cout << Simulator::Now () << "," << m_cam_received  << "," << m_denm_sent << std::endl;
  }

  void
  appServer::StopApplicationNow ()
  {
    NS_LOG_FUNCTION(this);
    StopApplication ();
  }

  void
  appServer::TriggerDenm (Address from, long other, long other_type, double t2c, double s2c, double x, double y)
  {
    denData data;
    ActionID_t actionid;
    DENBasicService_error_t trigger_retval;
    denData::denDataSituation situationdata;

    memset(&situationdata,0,sizeof(denData::denDataSituation));

    libsumo::TraCIPosition collision_position = m_client->TraCIAPI::simulation.convertXYtoLonLat (x,y);

    /* Build DENM data */
    data.setDenmMandatoryFields (compute_timestampIts (m_real_time),collision_position.x*DOT_ONE_MICRO,collision_position.y*DOT_ONE_MICRO);
    situationdata.informationQuality = InformationQuality_highest;
    CauseCodeType type_of_collision=CauseCodeType_dangerousSituation;
    switch (other_type)
    {
      case StationType_passengerCar:
        type_of_collision=CauseCodeType_collisionRisk;
        break;
      case StationType_cyclist:
        type_of_collision=CauseCodeType_collisionWithCyclist;
        break;
      case StationType_pedestrian:
        type_of_collision=CauseCodeType_collisionWithPedestrian;
        break;
      default:
        break;
    }
    situationdata.eventType.causeCode = type_of_collision;
    situationdata.eventType.subCauseCode = other;
    data.setDenmSituationData_asn_types (situationdata);

    m_socket->Connect (from);

    trigger_retval=m_denService.appDENM_trigger(data,actionid);
    if(trigger_retval!=DENM_NO_ERROR)
      {
        NS_LOG_ERROR("Cannot trigger DENM. Error code: " << trigger_retval);
      }
    else
      {
        m_denm_sent++;
      }
    data.denDataFree ();
   }

  void
  appServer::receiveCAM (CAM_t *cam, Address address)
  {
    m_cam_received++;

    /* Send the converted values to the collision detector */
    cam_information_t cam_info;

    cam_info.id = (long)cam->header.stationID;

    double lat = (double)cam->cam.camParameters.basicContainer.referencePosition.latitude/DOT_ONE_MICRO;
    double lon = (double)cam->cam.camParameters.basicContainer.referencePosition.longitude/DOT_ONE_MICRO;
    libsumo::TraCIPosition xy_pos = m_client->TraCIAPI::simulation.convertLonLattoXY (lon,lat);
    cam_info.position = std::make_pair(xy_pos.x,xy_pos.y);
    cam_info.speed = (double)cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.speed.speedValue/CENTI;
    cam_info.acceleration = (double)cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.longitudinalAcceleration.longitudinalAccelerationValue/DECI;
    cam_info.angle = (double)cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.heading.headingValue/DECI;
    cam_info.timestamp = (long)cam->cam.generationDeltaTime;
    cam_info.width = (double)cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.vehicleWidth/DECI;
    cam_info.length = (double)cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.vehicleLength.vehicleLengthValue/DECI;
    cam_info.type = (long)cam->cam.camParameters.basicContainer.stationType;
    cam_info.addr = address;

    m_collisionAvoidanceSystem.UpdateMaps (cam_info);

    long gen_time = (long)cam->cam.generationDeltaTime;

    int msg_delay = (compute_timestampIts (m_real_time)%65535 - gen_time);
    if (msg_delay>0)
      m_cumulate_delay += msg_delay;
    else
      m_cam_received=m_cam_received-1;

    ASN_STRUCT_FREE(asn_DEF_CAM,cam);
  }

  void
  appServer::aggregateOutput()
  {
    std::cout << Simulator::Now () << "," << m_cam_received << "," << m_denm_sent << std::endl;
    m_aggegateOutputEvent = Simulator::Schedule (Seconds(1), &appServer::aggregateOutput, this);
  }

}







