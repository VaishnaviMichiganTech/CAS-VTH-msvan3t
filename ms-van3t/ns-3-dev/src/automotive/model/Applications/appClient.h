#ifndef APPCLIENT_H
#define APPCLIENT_H

#include "ns3/traci-client.h"
#include "ns3/application.h"
#include "ns3/asn_utils.h"

#include "ns3/denBasicService.h"
#include "ns3/caBasicService.h"

#define EARTH_RADIUS 6371.0

namespace ns3 {

class appClient : public Application
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);

  appClient ();

  virtual ~appClient ();

  void receiveDENM(denData denm, Address from);

  void StopApplicationNow ();

protected:
  virtual void DoDispose (void);

private:

  DENBasicService m_denService; //!< DEN Basic Service object
  CABasicService m_caService; //!< CA Basic Service object

  Ptr<Socket> m_socket; //!< Client socket

  virtual void StartApplication (void);
  virtual void StopApplication (void);

  void TriggerCam(void);

  Ptr<TraciClient> m_client; //!< TraCI client
  std::string m_id; //!< vehicle id
  bool m_send_cam; //!< To decide if CAM dissemination is active or not
  bool m_real_time; //!< To decide wheter to use realtime scheduler
  std::string m_csv_name; //!< CSV log file name
  std::ofstream m_csv_ofstream;
  bool m_print_summary; //!< To print a small summary when vehicle leaves the simulation
  bool m_already_print; //!< To avoid printing two summary
  Ipv4Address m_server_addr; //!< Remote addr

  EventId m_sendCamEvent; //!< Event to send the CAM
  std::string m_this_type;

  double m_speed;

  bool m_evasive_maneuver;
  void evasiveManeuver(denData denm);
  void checkCollisionDist(double latDenm, double lonDenm, double prevDist);
  typedef enum {
    FREE=0,
    CONTROLLED=1,
  } vehicle_status_t;
  vehicle_status_t m_status;
  double m_safety_radius;
  double m_time_val;
  EventId m_check_event;

  /* Counters */
  int m_denm_received;
  long m_cumulated_delay;
};

} // namespace ns3

#endif /* APPCLIENT_H */

