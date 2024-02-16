#include "ns3/automotive-module.h"
#include "ns3/traci-module.h"
#include "ns3/lte-helper.h"
#include "ns3/config-store.h"
#include "ns3/internet-module.h"
#include "ns3/lte-module.h"
#include "ns3/sumo_xml_parser.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/yans-wifi-helper.h"

using namespace ns3;
NS_LOG_COMPONENT_DEFINE("v2i-lte");

int
main (int argc, char *argv[])
{
  std::string sumo_folder = "src/automotive/examples/sumo-files/";
  std::string mob_trace = "cars.rou.xml";
  std::string sumo_config ="src/automotive/examples/sumo-files/map.sumo.cfg";
  double t2c_threshold = 5;
  double speed = 50;

  /*** 0.a App Options ***/
  bool verbose = true;
  bool realtime = false;
  bool sumo_gui = true;
  bool aggregate_out = false;
  double sumo_updates = 0.01;
  bool send_cam = true;
  std::string csv_name;
  bool print_summary = false;
  bool evasive_maneuver = false;
  double time_val = 10;

  /*** 0.b LENA Options ***/
  double interPacketInterval = 100;
  bool useCa = false;

  uint16_t numberOfNodes;
  uint32_t nodeCounter = 0;

  xmlDocPtr rou_xml_file;

  double simTime = 100;

  CommandLine cmd;

  /* Cmd Line option for vehicular application */
  cmd.AddValue ("realtime", "Use the realtime scheduler or not", realtime);
  cmd.AddValue ("sumo-gui", "Use SUMO gui or not", sumo_gui);
  cmd.AddValue ("server-aggregate-output", "Print an aggregate output for server", aggregate_out);
  cmd.AddValue ("sumo-updates", "SUMO granularity", sumo_updates);
  cmd.AddValue ("send-cam", "Enable car to send cam", send_cam);
  cmd.AddValue ("sumo-folder","Position of sumo config files",sumo_folder);
  cmd.AddValue ("mob-trace", "Name of the mobility trace file", mob_trace);
  cmd.AddValue ("sumo-config", "Location and name of SUMO configuration file", sumo_config);
  cmd.AddValue ("csv-log", "Name of the CSV log file", csv_name);
  cmd.AddValue ("t2c", "t2c threshold", t2c_threshold);
  cmd.AddValue ("speed", "Speed of vehicles [km/h]", speed);
  cmd.AddValue ("evasive-maneuver", "If true, the vehicles will try to avoid collisions", evasive_maneuver);
  cmd.AddValue ("time-val", "Time value to compute the size of the safety radius (in case evasive maneuver is actuated)", time_val);

  /* Cmd Line option for Lena */
  cmd.AddValue("interPacketInterval", "Inter packet interval [ms]", interPacketInterval);
  cmd.AddValue("useCa", "Whether to use carrier aggregation", useCa);

  cmd.AddValue("sim-time", "Total duration of the simulation [s]", simTime);

  cmd.Parse (argc, argv);

  if (verbose)
    {
      LogComponentEnable ("v2i-lte", LOG_LEVEL_INFO);
      LogComponentEnable ("CABasicService", LOG_LEVEL_INFO);
      LogComponentEnable ("DENBasicService", LOG_LEVEL_INFO);
    }

  /* Carrier aggregation for LTE */
  if (useCa)
   {
     Config::SetDefault ("ns3::LteHelper::UseCa", BooleanValue (useCa));
     Config::SetDefault ("ns3::LteHelper::NumberOfComponentCarriers", UintegerValue (2));
     Config::SetDefault ("ns3::LteHelper::EnbComponentCarrierManager", StringValue ("ns3::RrComponentCarrierManager"));
   }

  /* Use the realtime scheduler of ns3 */
  if(realtime)
      GlobalValue::Bind ("SimulatorImplementationType", StringValue ("ns3::RealtimeSimulatorImpl"));

  /*** 0.b Read from the mob_trace the number of vehicles that will be created.
   *       The number of vehicles is directly parsed from the rou.xml file, looking at all
   *       the valid XML elements of type <vehicle>
  ***/
  NS_LOG_INFO("Reading the .rou file...");
  std::string path = sumo_folder + mob_trace;

  /* Load the .rou.xml document */
  xmlInitParser();
  rou_xml_file = xmlParseFile(path.c_str ());
  if (rou_xml_file == NULL)
    {
      NS_FATAL_ERROR("Error: unable to parse the specified XML file: "<<path);
    }
  numberOfNodes = XML_rou_count_vehicles(rou_xml_file);

  xmlFreeDoc(rou_xml_file);
  xmlCleanupParser();

  if(numberOfNodes==-1)
    {
      NS_FATAL_ERROR("Fatal error: cannot gather the number of vehicles from the specified XML file: "<<path<<". Please check if it is a correct SUMO file.");
    }
  NS_LOG_INFO("The .rou file has been read: " << numberOfNodes << " vehicles will be present in the simulation.");

  /* Set the simulation time (in seconds) */
  NS_LOG_INFO("Simulation will last " << simTime << " seconds");
  ns3::Time simulationTime (ns3::Seconds(simTime));

  /*** 1. Create LTE objects
       the network topology created is the following:

       UEs->(LTE CHANNEL)->enB->(SGW->PGW)->RemoteHost
                                  ^EPC^
   ***/
  Ptr<LteHelper> lteHelper = CreateObject<LteHelper> ();
  Ptr<PointToPointEpcHelper>  epcHelper = CreateObject<PointToPointEpcHelper> ();
  lteHelper->SetEpcHelper (epcHelper);

  ConfigStore inputConfig;
  inputConfig.ConfigureDefaults();

  Ptr<Node> pgw = epcHelper->GetPgwNode ();

  /*** 2. Create (and configure) the remote host that will gather the CAM and send the DENM ***/
  NodeContainer remoteHostContainer;
  remoteHostContainer.Create (1);
  Ptr<Node> remoteHost = remoteHostContainer.Get (0);
  InternetStackHelper internet;
  internet.Install (remoteHostContainer);

  /* Connect the remote host to the packet gateway and create the Internet */
  PointToPointHelper p2ph;
  p2ph.SetDeviceAttribute ("DataRate", DataRateValue (DataRate ("10Gb/s")));
  p2ph.SetDeviceAttribute ("Mtu", UintegerValue (1500));
  p2ph.SetChannelAttribute ("Delay", TimeValue (Seconds (0.005)));
  NetDeviceContainer internetDevices = p2ph.Install (pgw, remoteHost);
  Ipv4AddressHelper ipv4h;
  ipv4h.SetBase ("10.0.0.0", "255.0.0.0");
  Ipv4InterfaceContainer internetIpIfaces = ipv4h.Assign (internetDevices);
  /* interface 0 is localhost, 1 is the p2p device */
  Ipv4Address remoteHostAddr = internetIpIfaces.GetAddress (1);

  Ipv4StaticRoutingHelper ipv4RoutingHelper;
  Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());
  remoteHostStaticRouting->AddNetworkRouteTo (Ipv4Address ("7.0.0.0"), Ipv4Mask ("255.0.0.0"), 1);

  /*** 3. Create containers for UEs and eNB ***/
  NodeContainer ueNodes;
  NodeContainer enbNodes;
  enbNodes.Create(1);
  ueNodes.Create(numberOfNodes);

  /*** 4. Create and install mobility (SUMO will be attached later) ***/
  /*** 6. Setup Mobility and position node pool ***/
  MobilityHelper mobility;
  mobility.Install(enbNodes);
  mobility.Install(ueNodes);

  /* Set the eNB to a fixed position */
  Ptr<MobilityModel> mobilityeNBn = enbNodes.Get (0)->GetObject<MobilityModel> ();
  mobilityeNBn->SetPosition (Vector (0, 0, 20.0)); // set eNB to fixed position

  /*** 5. Install LTE Devices to the nodes + assign IP to UE***/
  NetDeviceContainer enbLteDevs = lteHelper->InstallEnbDevice (enbNodes);
  NetDeviceContainer ueLteDevs = lteHelper->InstallUeDevice (ueNodes);

  /* Install the IP stack on the UEs */
  internet.Install (ueNodes);
  Ipv4InterfaceContainer ueIpIface;

  ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (ueLteDevs));
  /* Assign IP address to UEs */
  for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
    {
      Ptr<Node> ueNode = ueNodes.Get (u);
      /* Set the default gateway for the UE */
      Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ueNode->GetObject<Ipv4> ());
      ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);
    }

  for (uint16_t i = 0; i < numberOfNodes; i++)
      {
        lteHelper->Attach (ueLteDevs.Get(i), enbLteDevs.Get(0));
        /* side effect: the default EPS bearer will be activated */
      }

  /*** 6. Setup Traci and start SUMO ***/
  Ptr<TraciClient> sumoClient = CreateObject<TraciClient> ();
  sumoClient->SetAttribute ("SumoConfigPath", StringValue (sumo_config));
  sumoClient->SetAttribute ("SumoBinaryPath", StringValue (""));    // use system installation of sumo
  sumoClient->SetAttribute ("SynchInterval", TimeValue (Seconds (sumo_updates)));
  sumoClient->SetAttribute ("StartTime", TimeValue (Seconds (0.0)));
  sumoClient->SetAttribute ("SumoGUI", (BooleanValue) sumo_gui);
  sumoClient->SetAttribute ("SumoPort", UintegerValue (3400));
  sumoClient->SetAttribute ("PenetrationRate", DoubleValue (1.0));
  sumoClient->SetAttribute ("SumoLogFile", BooleanValue (false));
  sumoClient->SetAttribute ("SumoStepLog", BooleanValue (false));
  sumoClient->SetAttribute ("SumoSeed", IntegerValue (10));
  sumoClient->SetAttribute ("SumoAdditionalCmdOptions", StringValue ("--verbose true"));
  sumoClient->SetAttribute ("SumoWaitForSocket", TimeValue (Seconds (1.0)));
  sumoClient->SetAttribute ("SumoAdditionalCmdOptions", StringValue ("--collision.action warn --collision.check-junctions --error-log=sumo-errors-or-collisions.xml"));

  /*** 7. Create and Setup application for the server ***/
  AppServerHelper appServerHelper;
  appServerHelper.SetAttribute ("Client", (PointerValue) sumoClient);
  appServerHelper.SetAttribute ("RealTime", BooleanValue(realtime));
  appServerHelper.SetAttribute ("AggregateOutput", BooleanValue(aggregate_out));
  appServerHelper.SetAttribute ("CSV", StringValue(csv_name));
  appServerHelper.SetAttribute ("T2C", DoubleValue(t2c_threshold));

  ApplicationContainer AppServer = appServerHelper.Install (remoteHostContainer.Get (0));

  AppServer.Start (Seconds (0.0));
  AppServer.Stop (simulationTime - Seconds (0.1));

  /*** 8. Setup interface and application for dynamic nodes ***/
  AppClientHelper appClientHelper;
  appClientHelper.SetAttribute ("ServerAddr", Ipv4AddressValue(remoteHostAddr));
  appClientHelper.SetAttribute ("Client", (PointerValue) sumoClient); // pass TraciClient object for accessing sumo in application
  appClientHelper.SetAttribute ("SendCam", BooleanValue(send_cam));
  appClientHelper.SetAttribute ("PrintSummary", BooleanValue(print_summary));
  appClientHelper.SetAttribute ("RealTime", BooleanValue(realtime));
  appClientHelper.SetAttribute ("CSV", StringValue(csv_name));
  appClientHelper.SetAttribute ("Speed", DoubleValue(speed/3.6));
  appClientHelper.SetAttribute ("Evasive-meneuver", BooleanValue(evasive_maneuver));
  appClientHelper.SetAttribute ("Time-val", DoubleValue(time_val));


  /* callback function for node creation */
  
  //std::function<Ptr<Node> ()> setupNewWifiNode = [&] () -> Ptr<Node>
  STARTUP_FCN setupNewWifiNode = [&](std::string vehicleID) -> Ptr<Node>
    {
      if (nodeCounter >= ueNodes.GetN())
        NS_FATAL_ERROR("Node Pool empty!: " << nodeCounter << " nodes created.");

      /* don't create and install the protocol stack of the node at simulation time -> take from "node pool" */
      Ptr<Node> includedNode = ueNodes.Get(nodeCounter);
      ++nodeCounter; // increment counter for next node

      /* Install Application */
      ApplicationContainer ClientApp = appClientHelper.Install (includedNode);
      ClientApp.Start (Seconds (0.0));
      ClientApp.Stop (simulationTime - Simulator::Now () - Seconds (0.1));

      return includedNode;
    };

  /* callback function for node shutdown */
  //std::function<void (Ptr<Node>)> shutdownWifiNode = [] (Ptr<Node> exNode)
  SHUTDOWN_FCN shutdownWifiNode = [] (Ptr<Node> exNode,std::string vehicleID)
    {
      /* stop all applications */
      Ptr<appClient> appClient_ = exNode->GetApplication(0)->GetObject<appClient>();

      if(appClient_)
        appClient_->StopApplicationNow ();

       /* set position outside communication range */
      Ptr<ConstantPositionMobilityModel> mob = exNode->GetObject<ConstantPositionMobilityModel>();
      mob->SetPosition(Vector(-1000.0+(rand()%25),320.0+(rand()%25),250.0));// rand() for visualization purposes

      /* NOTE: further actions could be required for a safe shut down! */
    };

  /* start traci client with given function pointers */
  sumoClient->SumoSetup (setupNewWifiNode, shutdownWifiNode);

  /* To enable statistics collection of LTE module */
  //lteHelper->EnableTraces ();

  /*** 9. Start Simulation ***/
  Simulator::Stop (simulationTime);

  Simulator::Run ();
  Simulator::Destroy ();

  return 0;
}
