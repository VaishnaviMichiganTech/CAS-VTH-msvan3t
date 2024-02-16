#ifndef COLLISIONAVOIDANCESYSTEM_H_
#define COLLISIONAVOIDANCESYSTEM_H_

#include <map>
#include <vector>
#include <cmath>
#include "ns3/asn_utils.h"
#include "ns3/socket.h"
#include <functional>

#define NO_COLLISION -1
#define PI 3.14159265

//unit measure CAM
#define CENTI               100
#define DOT_ONE_MICRO       10000000
#define MICRO               1000000

namespace ns3
{

  typedef struct _cam_information {
    long id;
    std::pair <double,double> position;
    double speed;
    double acceleration;
    double angle;
    long timestamp;
    long seq;
    double width;
    double length;
    Address addr;
    long type;
  } cam_information_t;

  typedef struct _s2c_ret {
    double s2c;
    double x_med;
    double y_med;
  } s2c_ret_t;

  typedef struct _check_collision_ret {
    double s2c;
    double t2c;
    double x_med;
    double y_med;
  } check_collision_ret_t;

  class CollisionAvoidanceSystem {
    public:
        void UpdateMaps (cam_information_t cam);
        void setT2CThreshold (double t2c) 
        {m_t2c_threshold=t2c;}
        void sendDENMCallback(std::function<void(Address,long,long,double,double,double,double)> send_callback) {m_DENMsendCallback=send_callback;}
        void setRealTime(bool real_time) {m_real_time = real_time;}

    private:
        double m_t2c_threshold;
        long m_max_pos_error = 0;
        double angular_threshold = 0.17;
        bool m_real_time;

        //Maps used to save vehicles values
        std::map <long, std::pair <double, double>> m_veh_positions;
        std::map <long, std::pair <double, double>> m_veh_speed;
        std::map <long, std::pair <double, double>> m_veh_acceleration;
        std::map <long, double> m_veh_angle;
        std::map <long, long> m_veh_last_update;
        std::map <long, long> m_veh_cam_generation_time;
        std::map <long, Address> m_veh_address;
        std::map <long, double> m_veh_width;
        std::map <long, double> m_veh_length;
        std::map <long, long> m_veh_type;

        struct timespec compute_timestamp();
        void PrintCAMinfo(cam_information_t cam);
        bool CollisionType (double vx1, double vy1, double vx2, double vy2);
        bool IsInRange (double p1x, double p1y, double p2x, double p2y,
                       double speed1x, double speed1y, double speed2x, double speed2y);
        check_collision_ret_t CheckCollision(double x1, double y1, double dx1, double dy1, double ax1, double ay1,
                                                  double x2,double y2,double dx2,double dy2, double ax2, double ay2, double s2c);
        double TimeToCollision (double x1, double y1, double vx1, double vy1, double ax1, double ay1,
                               double x2, double y2, double vx2, double vy, double ax2, double ay2);
        s2c_ret_t SpaceToCollision (double x1, double y1, double vx1, double vy1, double ax1, double ay1,
                                double x2, double y2, double vx2, double vy2, double ax2, double ay2,
                                double t2c);
        void IterateAndCheck(long id);
        double ComputeS2C(double width,double length);
        std::function<void(Address,long,long,double,double,double,double)> m_DENMsendCallback;
  };
}

#endif

