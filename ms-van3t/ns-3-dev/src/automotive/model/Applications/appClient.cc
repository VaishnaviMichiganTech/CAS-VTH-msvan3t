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

  
*/
#include "appClient.h"

#include "ns3/CAM.h"
#include "ns3/DENM.h"
#include "ns3/vdpTraci.h"
#include "ns3/socket.h"

namespace ns3
{
  NS_LOG_COMPONENT_DEFINE("appClient");

  NS_OBJECT_ENSURE_REGISTERED(appClient);

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
  appClient::GetTypeId (void)
  {
    static TypeId tid =
        TypeId ("ns3::appClient")
        .SetParent<Application> ()
        .SetGroupName ("Applications")
        .AddConstructor<appClient> ()
        .AddAttribute ("PrintSummary",
            "To print summary at the end of simulation",
            BooleanValue(false),
            MakeBooleanAccessor (&appClient::m_print_summary),
            MakeBooleanChecker ())
        .AddAttribute ("SendCam",
            "If it is true, the branch sending the CAM is activated.",
            BooleanValue (true),
            MakeBooleanAccessor (&appClient::m_send_cam),
            MakeBooleanChecker ())
        .AddAttribute ("RealTime",
            "To compute properly timestamps",
            BooleanValue(false),
            MakeBooleanAccessor (&appClient::m_real_time),
            MakeBooleanChecker ())
        .AddAttribute ("CSV",
            "CSV log name",
            StringValue (),
            MakeStringAccessor (&appClient::m_csv_name),
            MakeStringChecker ())
        .AddAttribute ("Speed",
            "Speed of vehicles [m/s]",
            DoubleValue (),
            MakeDoubleAccessor (&appClient::m_speed),
            MakeDoubleChecker <double> ())
        .AddAttribute ("ServerAddr",
            "Ip Addr of the server",
            Ipv4AddressValue("10.0.0.1"),
            MakeIpv4AddressAccessor (&appClient::m_server_addr),
            MakeIpv4AddressChecker ())
        .AddAttribute ("Evasive-meneuver",
            "If true, vehicles will try to avoid collisions",
            BooleanValue(false),
            MakeBooleanAccessor (&appClient::m_evasive_maneuver),
            MakeBooleanChecker ())
        .AddAttribute ("Time-val",
            "Value to compute the size of the safety radius",
             DoubleValue (),
             MakeDoubleAccessor (&appClient::m_time_val),
             MakeDoubleChecker <double> ())
        .AddAttribute ("Client",
            "TraCI client for SUMO",
            PointerValue (0),
            MakePointerAccessor (&appClient::m_client),
            MakePointerChecker<TraciClient> ());
        return tid;
  }

  appClient::appClient ()
  {
    NS_LOG_FUNCTION(this);
    m_client = nullptr;
    m_print_summary = true;
    m_already_print = false;
    m_speed = 13.89;
    m_denm_received = 0;
    m_cumulated_delay = 0;


    m_evasive_maneuver = false;
    m_status=FREE;
    m_time_val=10;
  }

  appClient::~appClient ()
  {
    NS_LOG_FUNCTION(this);
  }

  void
  appClient::DoDispose (void)
  {
    NS_LOG_FUNCTION(this);
    Application::DoDispose ();
  }

  void
  appClient::StartApplication (void)
  {
    NS_LOG_FUNCTION(this);
    m_id = m_client->GetVehicleId (this->GetNode ());

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

    /* Create the socket for TX and RX */
    TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");

    /* Socket used to send CAMs and receive DENMs */
    m_socket = Socket::CreateSocket (GetNode (), tid);

    /* Bind the socket to receive packets coming from every IP */
    InetSocketAddress local = InetSocketAddress (Ipv4Address::GetAny (), 9);
    if (m_socket->Bind (local) == -1)
      {
        NS_FATAL_ERROR ("Failed to bind client socket");
      }

    /* Connect it to the server */
    // Set the socket to send to the server
    InetSocketAddress remote = InetSocketAddress (m_server_addr, 9);
    m_socket->Connect(remote);

    /* Make the callback to handle received DENMs */
    m_socket->SetRecvCallback (MakeCallback (&DENBasicService::receiveDENM, &m_denService));

    /* Set sockets, callback and station properties in DENBasicService */
    m_denService.setStationProperties (std::stol(m_id.substr (3)), type);
    m_denService.addDENRxCallback (std::bind(&appClient::receiveDENM,this,std::placeholders::_1,std::placeholders::_2));
    m_denService.setRealTime(m_real_time);

    /* Set sockets, callback, station properties and TraCI VDP in CABasicService */
    m_caService.setSocketTx (m_socket);
    m_caService.setStationProperties (std::stol(m_id.substr (3)), type);

    VDPTraCI traci_vdp(m_client,m_id);
    m_caService.setVDP(traci_vdp);

    m_caService.setRealTime(m_real_time);

    /* Create CSV file, if requested */
    if (!m_csv_name.empty ())
      {
        m_csv_ofstream.open (m_csv_name+"-"+m_id+".csv",std::ofstream::trunc);
        m_csv_ofstream << "self_type,self_id,other_type,other_id,current_time,self_lon,self_lat,self_speed,collision_lon,collision_lat,distance_to_the_collision,detection_time,delivery_delay" << std::endl;
      }

    /* Schedule CAM dissemination */
    std::srand(Simulator::Now().GetNanoSeconds ());
    if (m_send_cam)
      {
         double desync = ((double)std::rand()/RAND_MAX);
         m_caService.startCamDissemination(desync);
      }
  }

  void
  appClient::StopApplication ()
  {
    NS_LOG_FUNCTION(this);
    Simulator::Remove(m_sendCamEvent);

    uint64_t cam_sent;

    if (!m_csv_name.empty ())
      {
        m_csv_ofstream << ",,,,,,,,,," << std::endl;
        m_csv_ofstream << "number_of_denm_received,average_latency" << std::endl;
        m_csv_ofstream << m_denm_received << "," <<  (double)m_cumulated_delay/m_denm_received << std::endl;

        m_csv_ofstream.close ();
      }

    cam_sent = m_caService.terminateDissemination ();
    m_denService.cleanup();
    m_check_event.Cancel ();

    if (m_print_summary && !m_already_print)
      {
        std::cout << "INFO-" << m_id
                  << ",CAM-SENT:" << cam_sent
                  << ",DENM-RECEIVED:" << m_denm_received
                  << std::endl;
        m_already_print=true;
      }
  }

  void
  appClient::StopApplicationNow ()
  {
    NS_LOG_FUNCTION(this);
    StopApplication ();
  }

  void
  appClient::receiveDENM (denData denm, Address from)
  {
    m_denm_received++;

    libsumo::TraCIPosition pos =  m_client->TraCIAPI::vehicle.getPosition (m_id);
    pos = m_client->TraCIAPI::simulation.convertXYtoLonLat (pos.x,pos.y);
    double dist = distanceEarth((double)denm.getDenmMgmtLatitude ()/DOT_ONE_MICRO, (double)denm.getDenmMgmtLongitude ()/DOT_ONE_MICRO, pos.x, pos.y);

    m_cumulated_delay += compute_timestampIts (m_real_time) - (long)denm.getDenmMgmtDetectionTime ();
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
                     << (long)denm.getDenmSituationData_asn_types ().eventType.subCauseCode << ","
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
      evasiveManeuver (denm);
  }

  void
  appClient::evasiveManeuver(denData denm)
  {
    /* Compute safety radius */
    double speed = m_client->TraCIAPI::vehicle.getSpeed (m_id);
    double acceleration = m_client->TraCIAPI::vehicle.getAcceleration (m_id);
    m_safety_radius = speed * m_time_val + 0.5 * acceleration * m_time_val * m_time_val;

    /* Compute distance from collision */
    libsumo::TraCIPosition pos =  m_client->TraCIAPI::vehicle.getPosition (m_id);
    pos = m_client->TraCIAPI::simulation.convertXYtoLonLat (pos.x,pos.y);
    double latDenm = (double)denm.getDenmMgmtLatitude ()/DOT_ONE_MICRO;
    double lonDenm = (double)denm.getDenmMgmtLongitude ()/DOT_ONE_MICRO;
    double distance_from_collision = distanceEarth(latDenm, lonDenm, pos.x, pos.y);

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
    m_check_event = Simulator::Schedule(Seconds(1),&appClient::checkCollisionDist, this, latDenm, lonDenm, distance_from_collision);
  }

  void
  appClient::checkCollisionDist(double latDenm, double lonDenm, double prevDist)
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
        m_check_event = Simulator::Schedule(Seconds(1),&appClient::checkCollisionDist, this, latDenm, lonDenm, distance_from_collision);
    }

  }
}





