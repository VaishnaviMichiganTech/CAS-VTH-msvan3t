/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright 2007 University of Washington
 *
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

 * Edited by Marco Malinverno, Politecnico di Torino (marco.malinverno@polito.it)
 *worked on ms-van3t: Vaishnavi Balambeed: vhbalamb@mtu.edu
*/
#include "appSample.h"

#include "ns3/CAM.h"
#include "ns3/DENM.h"

namespace ns3
{

  NS_LOG_COMPONENT_DEFINE("appSample");

  NS_OBJECT_ENSURE_REGISTERED(appSample);

  // This function converts decimal degrees to radians
  double deg2rad(double deg) {
    return (deg * M_PI / 180);
  }

  //  This function converts radians to decimal degrees
  double rad2deg(double rad) {
    return (rad * 180 / M_PI);
  }
  /**
    * Returns the distance between two points on the Earth.
    * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
    * @param lat1d Latitude of the first point in degrees
    * @param lon1d Longitude of the first point in degrees
    * @param lat2d Latitude of the second point in degrees
    * @param lon2d Longitude of the second point in degrees
    * @return The distance between the two points in meters
    */
   double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
     double lat1r, lon1r, lat2r, lon2r, u, v;
     lat1r = deg2rad(lat1d);
     lon1r = deg2rad(lon1d);
     lat2r = deg2rad(lat2d);
     lon2r = deg2rad(lon2d);
     u = sin((lat2r - lat1r)/2);
     v = sin((lon2r - lon1r)/2);
     return 2.0 * EARTH_RADIUS * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v)) * 1000;
   }

  TypeId
  appSample::GetTypeId (void)
  {
    static TypeId tid =
        TypeId ("ns3::appSample")
        .SetParent<Application> ()
        .SetGroupName ("Applications")
        .AddConstructor<appSample> ()
        .AddAttribute ("RealTime",
            "To compute properly timestamps",
            BooleanValue(false),
            MakeBooleanAccessor (&appSample::m_real_time),
            MakeBooleanChecker ())
        .AddAttribute ("IpAddr",
            "IpAddr",
            Ipv4AddressValue ("10.0.0.1"),
            MakeIpv4AddressAccessor (&appSample::m_ipAddress),
            MakeIpv4AddressChecker ())
        .AddAttribute ("SendCam",
            "If it is true, the facility sending CAMs is activated.",
            BooleanValue (true),
            MakeBooleanAccessor (&appSample::m_send_cam),
            MakeBooleanChecker ())
        .AddAttribute ("SendDenm",
            "If true, emergency vehicle broadcast DENMs",
            BooleanValue(true),
            MakeBooleanAccessor (&appSample::m_send_denm),
            MakeBooleanChecker ())
        .AddAttribute ("PrintSummary",
            "To print summary at the end of simulation",
            BooleanValue(false),
            MakeBooleanAccessor (&appSample::m_print_summary),
            MakeBooleanChecker ())
        .AddAttribute ("CSV",
            "CSV log name",
            StringValue (),
            MakeStringAccessor (&appSample::m_csv_name),
            MakeStringChecker ())
        .AddAttribute ("Speed",
            "Speed of vehicles [m/s]",
            DoubleValue (),
            MakeDoubleAccessor (&appSample::m_speed),
            MakeDoubleChecker <double> ())
        .AddAttribute ("Model",
            "Physical and MAC layer communication model",
            StringValue (""),
            MakeStringAccessor (&appSample::m_model),
            MakeStringChecker ())
        .AddAttribute ("Silent",
            "If true, DENMs corresponding to collision will not be transmitted",
            BooleanValue(false),
            MakeBooleanAccessor (&appSample::m_silent),
            MakeBooleanChecker ())
        .AddAttribute ("Evasive-meneuver",
            "If true, vehicles will try to avoid collisions",
            BooleanValue(false),
            MakeBooleanAccessor (&appSample::m_evasive_maneuver),
            MakeBooleanChecker ())
        .AddAttribute ("Time-val",
            "Value to compute the size of the safety radius",
             DoubleValue (),
             MakeDoubleAccessor (&appSample::m_time_val),
             MakeDoubleChecker <double> ())
        .AddAttribute ("T2C",
            "T2C threshold for the CAS.",
            DoubleValue (),
            MakeDoubleAccessor (&appSample::m_t2c_threshold),
            MakeDoubleChecker <double> ())
        .AddAttribute ("Client",
            "TraCI client for SUMO",
            PointerValue (0),
            MakePointerAccessor (&appSample::m_client),
            MakePointerChecker<TraciClient> ());
        return tid;
  }

  appSample::appSample ()
  {
    NS_LOG_FUNCTION(this);
    m_client = nullptr;
    m_print_summary = true;
    m_already_print = false;
    m_speed = 13.89;
    m_t2c_threshold = 5;

    m_denm_sent = 0;
    m_cam_received = 0;
    m_denm_received = 0;
    m_denm_intertime = 0;

    m_evasive_maneuver = false;
    m_status=FREE;
    m_time_val=10;
  }

  appSample::~appSample ()
  {
    NS_LOG_FUNCTION(this);
  }

  void
  appSample::DoDispose (void)
  {
    NS_LOG_FUNCTION(this);
    Application::DoDispose ();
  }

  void
  appSample::StartApplication (void)
  {
    NS_LOG_FUNCTION(this);

    /* Save the vehicles informations */
    m_id = m_client->GetVehicleId (this->GetNode ());
    m_type = m_client->TraCIAPI::vehicle.getVehicleClass (m_id);

    /* Set the speed of the vehicle */
    m_client->TraCIAPI::vehicle.setSpeed (m_id,m_speed);

    StationType type;
    std::string sumoType = m_client->TraCIAPI::vehicle.getVehicleClass (m_id);
    if(sumoType=="passenger")
    {
      type=StationType_passengerCar;
      m_this_type="vehicle";
    }
    else if(sumoType=="pedestrian")
    {
      m_this_type="pedestrian";
      type=StationType_pedestrian;
    }
    else if(sumoType=="bicycle")
    {
      type=StationType_cyclist;
      m_this_type="cyclist";
    }
    else
      NS_FATAL_ERROR("Cannot parse correct vehicle type:" << m_client->TraCIAPI::vehicle.getVehicleClass (m_id));

    m_max_speed = m_client->TraCIAPI::vehicle.getMaxSpeed (m_id);
    /* Set the speed of the vehicle */

    /* Create the Sockets for TX and RX */
    TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");

    /* TX socket for DENMs */
    m_socket_tx_denm = Socket::CreateSocket (GetNode (), tid);
    if (m_socket_tx_denm->Bind () == -1)
      {
        NS_FATAL_ERROR ("Failed to bind client socket");
      }

    if(m_model=="80211p")
      m_socket_tx_denm->Connect (InetSocketAddress (Ipv4Address::GetBroadcast (),19));
    else if(m_model=="cv2x")
      m_socket_tx_denm->Connect (InetSocketAddress(m_ipAddress,19));
    else
      NS_FATAL_ERROR ("No communication model set - check simulation script");
    m_socket_tx_denm->SetAllowBroadcast (true);
    m_socket_tx_denm->ShutdownRecv();

    /* TX socket for CAMs */
    m_socket_tx_cam = Socket::CreateSocket (GetNode (), tid);
    if (m_socket_tx_cam->Bind () == -1)
      {
        NS_FATAL_ERROR ("Failed to bind client socket");
      }

    if(m_model=="80211p")
      m_socket_tx_cam->Connect (InetSocketAddress (Ipv4Address::GetBroadcast (),20));
    else if(m_model=="cv2x")
      m_socket_tx_cam->Connect (InetSocketAddress(m_ipAddress,20));
    else
      NS_FATAL_ERROR ("No communication model set - check simulation script");
    m_socket_tx_cam->SetAllowBroadcast (true);
    m_socket_tx_cam->ShutdownRecv();

    /* RX socket for DENMs */
    m_socket_rx_denm = Socket::CreateSocket (GetNode (), tid);
    if (m_socket_rx_denm->Bind (InetSocketAddress (Ipv4Address::GetAny (), 19)) == -1)
      {
        NS_FATAL_ERROR ("Failed to bind client socket for DENMs");
      }
    /* Make the callback to handle received packets */
    m_socket_rx_denm->SetRecvCallback (MakeCallback (&DENBasicService::receiveDENM, &m_denService));

    /* RX socket for CAMs */
    m_socket_rx_cam = Socket::CreateSocket (GetNode (), tid);
    if (m_socket_rx_cam->Bind (InetSocketAddress (Ipv4Address::GetAny (), 20)) == -1)
      {
        NS_FATAL_ERROR ("Failed to bind client socket for CAMs");
      }
    /* Make the callback to handle received packets */
    m_socket_rx_cam->SetRecvCallback (MakeCallback (&CABasicService::receiveCam, &m_caService));

    /* Set sockets, callback and station properties in DENBasicService */
    m_denService.setSocketTx (m_socket_tx_denm);
    m_denService.setStationProperties (std::stol(m_id.substr (3)), type);
    m_denService.addDENRxCallback (std::bind(&appSample::receiveDENM,this,std::placeholders::_1,std::placeholders::_2));
    m_denService.setRealTime (m_real_time);

    /* Set sockets, callback, station properties and TraCI VDP in CABasicService */
    m_caService.setSocketTx (m_socket_tx_cam);
    m_caService.setStationProperties (std::stol(m_id.substr (3)), type);
    m_caService.addCARxCallback (std::bind(&appSample::receiveCAM,this,std::placeholders::_1,std::placeholders::_2));
    m_caService.setRealTime (m_real_time);

    VDPTraCI traci_vdp(m_client,m_id);
    m_caService.setVDP(traci_vdp);

    /* Schedule CAM dissemination */
    std::srand(Simulator::Now().GetNanoSeconds ());
    if (m_send_cam)
      {
         double desync = ((double)std::rand()/RAND_MAX);
         m_caService.startCamDissemination(desync);
      }

    if (!m_csv_name.empty ())
      {
        m_csv_ofstream.open (m_csv_name+"-"+m_id+".csv",std::ofstream::trunc);
        m_csv_ofstream << "self_type,self_id,other_type,other_id,type,current_time,self_lon,self_lat,self_speed,collision_lon,collision_lat,distance_to_the_collision,detection_time,delivery_delay" << std::endl;
      }

    /* Set the callback so that the collision detector can directly trigger DENM */
    m_collisionAvoidanceSystem.sendDENMCallback (std::bind(&appSample::TriggerDenm,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4,std::placeholders::_5,std::placeholders::_6,std::placeholders::_7));
    m_collisionAvoidanceSystem.selfDENMCallback (std::bind(&appSample::SelfDenm,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4,std::placeholders::_5,std::placeholders::_6));
    m_collisionAvoidanceSystem.setT2CThreshold (m_t2c_threshold);
    m_collisionAvoidanceSystem.setRealTime (m_real_time);
    m_collisionAvoidanceSystem.setSumoId (m_id);
    m_collisionAvoidanceSystem.setSilent (m_silent);
    m_collisionAvoidanceSystem.setID (std::stol(m_id.substr (3)));
    m_collisionAvoidanceSystem.setSumoClient (m_client);
    m_collisionAvoidanceSystem.setThisType ((long)type);
  }

  void
  appSample::StopApplication ()
  {
    NS_LOG_FUNCTION(this);
    Simulator::Remove(m_speed_ev);
    Simulator::Remove(m_send_denm_ev);
    Simulator::Remove(m_send_cam_ev);
    Simulator::Remove(m_update_denm_ev);

    uint64_t cam_sent;

    if (!m_csv_name.empty ())
      {
        m_csv_ofstream.close ();
      }

    cam_sent = m_caService.terminateDissemination ();
    m_denService.cleanup();
    m_check_event.Cancel ();

    if (m_print_summary && !m_already_print)
      {
        std::cout << "INFO-" << m_id
                  << ",DENM-SENT:" << m_denm_sent
                  << ",CAM-SENT:" << cam_sent
                  << ",DENM-RECEIVED:" << m_denm_received
                  << ",CAM-RECEIVED:" << m_cam_received
                  << std::endl;
        m_already_print=true;
      }
  }

  void
  appSample::StopApplicationNow ()
  {
    NS_LOG_FUNCTION(this);
    StopApplication ();
  }

  void
  appSample::TriggerDenm (long otherId, long other_type, long recipientId, double t2c, double s2c, double x, double y)
  {
    /* Build DENM data */
    ActionID_t actionid;
    denData data;
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
    situationdata.eventType.subCauseCode = recipientId;
    situationdata.linkedCause = (sCauseCode_t*) calloc(1,sizeof(sCauseCode_t));
    situationdata.linkedCause->causeCode = type_of_collision;
    situationdata.linkedCause->subCauseCode = otherId;

    data.setDenmSituationData_asn_types (situationdata);

    trigger_retval=m_denService.appDENM_trigger (data,actionid);
    if(trigger_retval!=DENM_NO_ERROR)
      {
        NS_LOG_ERROR("Cannot trigger DENM. Error code: " << trigger_retval);
      }
    else
      {
        m_denm_sent++;
      }
    data.denDataFree ();
    free(situationdata.linkedCause);
  }

  void
  appSample::SelfDenm(long other_id, long other_type, double t2c, double s2c, double x, double y)
  {
    libsumo::TraCIPosition thisPos =  m_client->TraCIAPI::vehicle.getPosition (m_id);
    thisPos = m_client->TraCIAPI::simulation.convertXYtoLonLat (thisPos.x,thisPos.y);
    libsumo::TraCIPosition collisionPos =  m_client->TraCIAPI::simulation.convertXYtoLonLat (x,y);
    double dist = distanceEarth(collisionPos.x, collisionPos.y, thisPos.x, thisPos.y);

    std::string other_type_str = "unknown";

    switch (other_type)
    {
      case (StationType_passengerCar):
        other_type_str="vehicle";
        break;
      case (StationType_cyclist):
        other_type_str="cyclist";
        break;
      case (StationType_pedestrian):
        other_type_str="pedestrian";
        break;
      default:
        break;
    }

    if (!m_csv_name.empty ())
    {
      m_csv_ofstream << m_this_type << ","
                     << m_id << ","
                     << other_type_str << ","
                     << other_id << ","
                     << "internal,"
                     << m_client->TraCIAPI::simulation.getTime () << ","
                     << thisPos.x << ","
                     << thisPos.y << ","
                     << m_client->TraCIAPI::vehicle.getSpeed (m_id) << ","
                     << collisionPos.y << ","
                     << collisionPos.x << ","
                     << dist << ","
                     << compute_timestampIts (m_real_time) << ","
                     << 0 << std::endl;
    }
    if(m_evasive_maneuver)
      {
        evasiveManeuver (collisionPos.y,collisionPos.x);
      }
  }

  void
  appSample::receiveCAM (CAM_t *cam, Address address)
  {
    /* Implement CAM strategy here */
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
   cam_info.type = (long)cam->cam.camParameters.basicContainer.stationType;
   cam_info.length = (double)cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.vehicleLength.vehicleLengthValue/DECI;

   cam_info.addr = address;

   m_collisionAvoidanceSystem.UpdateMaps (cam_info);

   long gen_time = (long)cam->cam.generationDeltaTime;

   int msg_delay = (compute_timestampIts (m_real_time)%65535 - gen_time);
   if (msg_delay>0)
     m_cumulate_delay += msg_delay;
   else
     m_cam_received=m_cam_received-1;

   // Free the received CAM data structure
   ASN_STRUCT_FREE(asn_DEF_CAM,cam);
  }

  void
  appSample::receiveDENM (denData denm, Address from)
  {
    long recipient = (long)denm.getDenmSituationData_asn_types ().eventType.subCauseCode;
    long other_id = (long)denm.getDenmSituationData_asn_types ().linkedCause->subCauseCode;

    /* In subcausecode there's the actual recipient of the message. */
    if(std::stol(m_id.substr (3)) != recipient)
      return;
    else
    {
        m_denm_received++;
        libsumo::TraCIPosition pos =  m_client->TraCIAPI::vehicle.getPosition (m_id);
        pos = m_client->TraCIAPI::simulation.convertXYtoLonLat (pos.x,pos.y);
        double dist = distanceEarth((double)denm.getDenmMgmtLatitude ()/DOT_ONE_MICRO, (double)denm.getDenmMgmtLongitude ()/DOT_ONE_MICRO, pos.x, pos.y);
        m_cumulate_delay += compute_timestampIts (m_real_time) - (long)denm.getDenmMgmtDetectionTime ();
        std::string other_type = "unknown";

        switch (denm.getDenmSituationData_asn_types ().eventType.causeCode)
        {
          case (CauseCodeType_collisionRisk):
            other_type="vehicle";
            break;
          case (CauseCodeType_collisionWithCyclist):
            other_type="cyclist";
            break;
          case (CauseCodeType_collisionWithPedestrian):
            other_type="pedestrian";
            break;
          default:
            break;
        }

        if (!m_csv_name.empty ())
        {
          m_csv_ofstream << m_this_type << ","
                         << m_id << ","
                         << other_type << ","
                         << other_id << ","
                         << "external,"
                         << m_client->TraCIAPI::simulation.getTime () << ","
                         << pos.x << ","
                         << pos.y << ","
                         << m_client->TraCIAPI::vehicle.getSpeed (m_id) << ","
                         << (double)denm.getDenmMgmtLongitude ()/DOT_ONE_MICRO << ","
                         << (double)denm.getDenmMgmtLatitude ()/DOT_ONE_MICRO << ","
                         << dist << ","
                         << (double)denm.getDenmMgmtDetectionTime () << ","
                         << compute_timestampIts (m_real_time) - (long)denm.getDenmMgmtDetectionTime () << std::endl;
        }
        if(m_evasive_maneuver)
          {
            double lon=(double)denm.getDenmMgmtLongitude ()/DOT_ONE_MICRO;
            double lat=(double)denm.getDenmMgmtLatitude ()/DOT_ONE_MICRO;
            evasiveManeuver (lon,lat);
          }
    }
  }

  void
  appSample::evasiveManeuver(double lon, double lat)
  {
    /* Compute safety radius */
    double speed = m_client->TraCIAPI::vehicle.getSpeed (m_id);
    double acceleration = m_client->TraCIAPI::vehicle.getAcceleration (m_id);
    m_safety_radius = speed * m_time_val + 0.5 * acceleration * m_time_val * m_time_val;

    /* Compute distance from collision */
    libsumo::TraCIPosition pos =  m_client->TraCIAPI::vehicle.getPosition (m_id);
    pos = m_client->TraCIAPI::simulation.convertXYtoLonLat (pos.x,pos.y);

    double distance_from_collision = distanceEarth(lat, lon, pos.x, pos.y);

    double coeff_speed = distance_from_collision/m_safety_radius;
    /* Now extract a random value between -0.1 and 0.2 to add to the coefficient so that the two vehicles do not slow down exactly at the same way */
    std::srand(Simulator::Now ().GetMilliSeconds ());
    double random = -0.1 + (double)(rand()) / ((double)(RAND_MAX/(0.3)));
    coeff_speed=coeff_speed+random;
//    std::cout << "Random extracted: " << random << std::endl;
//    std::cout << "Coefficient extracted: " << coeff_speed << std::endl;
    /* If the coeff is greater than 1, keep it to 1*/
    if(coeff_speed>1)
      coeff_speed=1;
    else if(coeff_speed<0)
      coeff_speed=0.001;
    double newSpeed=coeff_speed*m_speed;
    /* If the new speed is less than 10 km/h, keep it to 10 km/h*/
    if(newSpeed<2.77)
      newSpeed=2.77;
//    std::cout<<"new speed:" << newSpeed << std::endl;
    m_client->TraCIAPI::vehicle.setSpeed (m_id,newSpeed);
    m_status=CONTROLLED;

    m_check_event.Cancel ();
    m_check_event = Simulator::Schedule(Seconds(1),&appSample::checkCollisionDist, this, lat, lon, distance_from_collision);
  }
  void
  appSample::checkCollisionDist(double latDenm, double lonDenm, double prevDist)
  {
    /* Compute distance from collision */
    libsumo::TraCIPosition pos =  m_client->TraCIAPI::vehicle.getPosition (m_id);
    pos = m_client->TraCIAPI::simulation.convertXYtoLonLat (pos.x,pos.y);
    double distance_from_collision = distanceEarth(latDenm, lonDenm, pos.x, pos.y);
    /* If the distance is increasing then you can go back to normal speed */
    if (prevDist<distance_from_collision)
    {
        m_client->TraCIAPI::vehicle.setSpeed (m_id,m_speed);
        m_status=FREE;
        m_check_event.Cancel ();
    }
    else
    {
        m_check_event = Simulator::Schedule(Seconds(1),&appSample::checkCollisionDist, this, latDenm, lonDenm, distance_from_collision);
    }

  }
}





