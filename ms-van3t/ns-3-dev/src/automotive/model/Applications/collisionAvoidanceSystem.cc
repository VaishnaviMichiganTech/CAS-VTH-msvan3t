#include "collisionAvoidanceSystem.h"

#include "ns3/CAM.h"
#include "ns3/DENM.h"

#include <iostream>   // std::cout
#include <sstream>    // std::stringstream
#include <sys/time.h> // struct timeval
#include <unistd.h>   // write()

using namespace ns3;

// ETSI message IDs (ETSI TS 102 894-2 V1.3.1 (2018-08))
#define DENM_MESSAGE_ID 				1
#define CAM_MESSAGE_ID 					2
#define POI_MESSAGE_ID 					3
#define SPATEM_MESSAGE_ID				4
#define MAPEM_MESSAGE_ID 				5
#define IVIM_MESSAGE_ID 				6
#define EVRSR_MESSAGE_ID				7
#define TISTPGTRANSACTION_MESSAGE_ID                    8
#define SREM_MESSAGE_ID 				9
#define SSEM_MESSAGE_ID 				10
#define EVCSN_MESSAGE_ID 				11
#define SAEM_MESSAGE_ID 				12
#define RTCMEM_MESSAGE_ID 				13



  // Constants and Parameters for CACC
const double Ka = 1;  // Feedback gain of the acceleration term for CACC vehicles
const double Kv = 0.58; // s^-1

const double Ks = 0.1; // s^-2
const double amin = -3; // Minimum deceleration m/s^2
const double amax = 2;  // Maximum acceleration m/s^2
const double rho_jam = 4; // veh/m

//change and experiment with different rho_jam
const double ck = 1;  // veh
const double cv = 0.05; // s^2/m
const double ca = 0.3; // s^3/m
const double t0 = 1.4; // s
const double vfree = 120 / 3.6; // m/s (converted from km/h)
const double delta_x0 = 0; // m
const double th_max = 2.2; // s
const double th_min = 0.2; // s
  

void
CollisionAvoidanceSystem::UpdateMaps (cam_information_t cam)
{
  double posx = cam.position.first;
  double posy = cam.position.second;
  double speed_abs = cam.speed;
  double angle = cam.angle;
  double acc_abs = cam.acceleration;

  // Angle conversion and speed calculation
  double angle_rad = angle*PI/180;
  double vx = std::sin(angle_rad) * speed_abs;
  double vy = std::cos(angle_rad) * speed_abs;
  double ax = std::sin(angle_rad) * acc_abs;
  double ay = std::cos(angle_rad) * acc_abs;

  std::pair <double, double> pos = std::make_pair(posx,posy);
  std::pair <double, double> speed = std::make_pair(vx, vy);
  std::pair <double, double> accel = std::make_pair(ax, ay);

  // Update tables' values
  m_veh_positions[cam.id] = pos;
  m_veh_speed[cam.id] = speed;
  m_veh_acceleration[cam.id] = accel;
  m_veh_angle[cam.id] = angle;
  m_veh_last_update[cam.id] = compute_timestampIts (m_real_time);
  m_veh_cam_generation_time[cam.id] = cam.timestamp;
  m_veh_width[cam.id] = cam.width;
  m_veh_length[cam.id] = cam.length;
  m_veh_address[cam.id] = cam.addr;
  m_veh_type[cam.id] = cam.type;
  

  CollisionAvoidanceSystem::IterateAndCheck(cam.id);
}


// CHanges V: Function to calculate the time headway based on improved VTH STrategy


double calculateTimeHeadway(double vf, double vp, double ap)
{
  double th = ck*(1.0/(rho_jam * ( vfree - vf))) - (cv* (vp - vf)) - ca * ap;

return th;
}

//changes V: FUnction to calculate desired safety gap

double calculateDesiredSafetyGap(double vf, double timeHeadway)
{
 double sd_2 = timeHeadway * vf + delta_x0;
 
 return sd_2;
}



//changesV: function to calculate the desired acceleration in SC mode


double CalculateSCModeAcceleration(double ap, double vp, double vf, double s, double sd) {
    double asc = Ka * ap + Kv * (vp - vf) + Ks * (s - sd);
    // Limiting acceleration and deceleration for driver comfort
    asc = std::max(amin, std::min(asc, amax));
    return asc;
}



void
CollisionAvoidanceSystem::IterateAndCheck(long vehicle_id1)
{
  // Retrieve the vehicle informations
  std::pair <double, double> pos1 = m_veh_positions[vehicle_id1];
  std::pair <double, double> speed1 = m_veh_speed[vehicle_id1];
  std::pair <double, double> accel1 = m_veh_acceleration[vehicle_id1];
  long type1 = m_veh_type[vehicle_id1];

  // Variables needed to store the "other" vehicle informations
  long vehicle_id2;
  std::pair <double, double> pos2, speed2, accel2;

  // Iterate among all the members inside the "m_veh_positions" map
  for(std::map <long, std::pair <double, double>>::iterator it = m_veh_positions.begin(); it!=m_veh_positions.end(); it++)
  {
  
  
  
      vehicle_id2 = it->first;
      // Do not check the vehicle with itself
      if (vehicle_id1 == vehicle_id2)
        continue;
        
        double th = 1.0;
        double vf1 = sqrt(pow(speed1.first,2) + pow(speed1.second,2)); // speed of vehicle 1
        double vf2 = sqrt(pow(speed2.first,2) + pow(speed2.second,2)); //speed of vehicle 2
        double delta_x0 = 1.0; //Minimum safety gap when vehicles are completely stopped
        double lp = m_veh_length[vehicle_id2];
        
        double sd = th * vf1 + delta_x0 - lp; 
        
        
        

      long type2=m_veh_type[vehicle_id2];

      /* Never check among vulnerable users */
      if (type1 != (long)StationType_passengerCar && type2 != (long)StationType_passengerCar)
        continue;


      // Check if the information are outdated
      long vehlastupdate;
      vehlastupdate=m_veh_last_update[vehicle_id2];
      long time_elapsed = (compute_timestampIts (m_real_time) - vehlastupdate);

      if (time_elapsed > 3000)
        continue;

      // Retrieve all the informations stored in the maps
      pos2 = m_veh_positions[vehicle_id2];
      speed2 = m_veh_speed[vehicle_id2];
      accel2 = m_veh_acceleration[vehicle_id2];

      // Speed check -> do not check vehicles too slow, they will be managed by SUMO
      //if (sqrt (pow(speed2.first,2)+pow(speed2.second,2)) < m_speed_threshold)
      //  continue;

      // Call the collision detector with these informations
      // If the two vehicles are set to be on a collision course (pile-up collision not detected!)
      if(CollisionAvoidanceSystem::CollisionType (speed1.first,speed1.second,speed2.first,speed2.second))
      {
          if (CollisionAvoidanceSystem::IsInRange (pos1.first,pos1.second,pos2.first,pos2.second,speed1.first,speed1.second,speed2.first,speed2.second))
          {
              /* Compute the s2c threshld by using the length of the longer vehicle and the other vehicle's width */
          
              double maxLength = std::max(m_veh_length[vehicle_id1],m_veh_length[vehicle_id2]);
              double width = (maxLength == m_veh_width[vehicle_id1]) ? m_veh_width[vehicle_id2] : m_veh_width[vehicle_id1];
              double s2c = CollisionAvoidanceSystem::ComputeS2C (maxLength,sd);
              
              //changes start V
              // CHAngesV: we are iterating in the for loop for different vehicle positions
      
             double distance_new = sqrt(pow(pos2.first - pos1.first, 2) + pow(pos2.second - pos1.second, 2));
             
             // Calculate time headway and desired safety gap
             double timeHeadway_revised = calculateTimeHeadway(speed1.first, speed2.first, accel2.first);
             double desiredSafetyGap_revised = calculateDesiredSafetyGap(speed1.first, timeHeadway_revised);
      
              // Check for potential collision based on safety gap
        
            // Calculate t2c and s2c using the CheckCollision function
                check_collision_ret_t t2c_s2c = CollisionAvoidanceSystem::CheckCollision(
                pos1.first, pos1.second, speed1.first, speed1.second, accel1.first, accel1.second,
                pos2.first, pos2.second, speed2.first, speed2.second, accel2.first, accel2.second,
                desiredSafetyGap_revised);
                
              //CHanges end V
              //205,208,209,210,211 are commented
              
             // check_collision_ret_t t2c_s2c;
              
              
              //t2c_s2c = CollisionAvoidanceSystem::CheckCollision (pos1.first,pos1.second,speed1.first,
                //                                                 speed1.second,accel1.first,accel1.second,
                  //                                              pos2.first,pos2.second,speed2.first,speed2.second,
                    //                                              accel2.first,accel2.second,s2c);
              if(t2c_s2c.t2c>0)
              {
                  m_DENMsendCallback(m_veh_address[vehicle_id1],vehicle_id2,type2,t2c_s2c.t2c,t2c_s2c.s2c,t2c_s2c.x_med,t2c_s2c.y_med);
                  m_DENMsendCallback(m_veh_address[vehicle_id2],vehicle_id1,type1,t2c_s2c.t2c,t2c_s2c.s2c,t2c_s2c.x_med,t2c_s2c.y_med);
              }
              }// this is the end for the if(distance_new<desiredSAfetyGAp)
          }
        }// for the if of sd>0
      
      
      
      //written this on line 187
      // CHAngesV: we are iterating in the for loop for different vehicle positions
      
     // double distance_new = sqrt(pow(pos2.first - pos1.first, 2) + pow(pos2.second - pos1.second, 2));
      
      // Calculate time headway and desired safety gap
       // double timeHeadway_revised = calculateTimeHeadway(speed1.first, speed2.first, accel2.first);
       // double desiredSafetyGap_revised = calculateDesiredSafetyGap(speed1.first, timeHeadway_revised);
      
      // Check if the vehicles are in SC mode (distance <= 50m)
        //if (desiredSafetyGap_revised <= 50) {
           // double sd_1 = desiredSafetyGap_revised(calculateTimeHeadway(vf, vp, ap), vf);
           // double asc = CalculateSCModeAcceleration(accel2.first, speed2.first, speed1.first, distance, sd_1);
            
            
            // Check for potential collision based on safety gap
       // if (distance_new < desiredSafetyGap_revised) {
            // Calculate t2c and s2c using the CheckCollision function
           // check_collision_ret_t t2c_s2c = CollisionAvoidanceSystem::CheckCollision(
             //   pos1.first, pos1.second, speed1.first, speed1.second, accel1.first, accel1.second,
               // pos2.first, pos2.second, speed2.first, speed2.second, accel2.first, accel2.second,
                //desiredSafetyGap_revised);

            
            
            
      
   
   
   
   
   //ChangesV: This change is to check if the 
}

bool
CollisionAvoidanceSystem::CollisionType(double vx1, double vy1, double vx2, double vy2)
{
  /* Function that finds out if the collision is a rear-end or a crossroad-collision.
   * It returns 0 if the collision is a rear-end, 1 otherwise.
   */

  // Compute the module of their speed
  double vel1 = sqrt(pow(vx1,2) + pow(vy1,2));
  double vel2 = sqrt(pow(vx2,2) + pow(vy2,2));
  // Compute the angle of their speed:
  double angle1 = acos(vx1/vel1);
  double angle2 = acos(vx2/vel2);

  if(abs(angle1-angle2)<angular_threshold)
          return false;

  return true;
}

bool
CollisionAvoidanceSystem::IsInRange(double p1x, double p1y,
			     double p2x, double p2y,
			     double speed1x, double speed1y,
			     double speed2x, double speed2y)
{
  /* Function that checks if the distance between the two vehicles is small enough to call the collision detection
   * algortithm, i.e., if the two entities cannot in t2c_threshold be close enough, it is useless to call the detector.
   */

  // Compute in t2c_threshold the future position of the two entities
  double fut_pos1x = p1x + speed1x*1.5*m_t2c_threshold;
  double fut_pos1y = p1y + speed1y*1.5*m_t2c_threshold;
  double fut_pos2x = p2x + speed2x*1.5*m_t2c_threshold;
  double fut_pos2y = p2y + speed2y*1.5*m_t2c_threshold;

  // The distance traveled (in [m]) by the two entities in t2c_threshold
  double side1 = sqrt((fut_pos1x-p1x)*(fut_pos1x-p1x) + (fut_pos1y-p1y)*(fut_pos1y-p1y));
  double side2 = sqrt((fut_pos2x-p2x)*(fut_pos2x-p2x) + (fut_pos2y-p2y)*(fut_pos2y-p2y));
  // Save in "side" the biggest distance traveled between the two
  double side = std::max(side1,side2);

  // Compute the "range action" of the faster vehicle. Basically, what it is done, it is computed the
  // hypotenuse considering a rect-triangle having equal catetis, equal to "side"
  double max_dist = sqrt(2*side*side);
  // Compute a second distance, the between the two entities at this time
  double dist = sqrt((p1x-p2x)*(p1x-p2x) + (p1y-p2y)*(p1y-p2y));

  // If "dist" is lower than "max_dist" then the two entities cannot collide in a time lower than
  // t2c_threshold --> it is returned true and the detector (i.e., CheckCollision) is not called
  if (dist < max_dist)
    return true;
  else
    return false;
}

double
CollisionAvoidanceSystem::ComputeS2C(double length, double width)
{
  return sqrt(pow(width/2,2)+pow(length+(width/2)+(m_max_pos_error*2),2));
}

// commentV: no changes in this yet, as we are calling checkcollision with newer calculated desiredsafetygap
check_collision_ret_t
CollisionAvoidanceSystem::CheckCollision(double x1, double y1,
				  double dx1, double dy1,
				  double ax1, double ay1,
				  double x2, double y2,
				  double dx2, double dy2,
				  double ax2, double ay2,
				  double s2c_threshold)
{
  check_collision_ret_t t2c_s2c;
  
  // Calculate the current distance between the vehicles
    double currentDistance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
      
        
    
    if (currentDistance < s2c_threshold) {
        // Set t2c to a very small value indicating immediate action is needed
        t2c_s2c.t2c = 0; // or a very small positive value
        t2c_s2c.s2c = currentDistance;
        return t2c_s2c;
    }
    
    
    

  // Get the time to collision (t2c) (i.e., time from now needed to the two vehicles to get minimum distance)
  double t2c = TimeToCollision(x1, y1, dx1, dy1, ax1, ay1,
                              x2, y2, dx2, dy2, ax2, ay2);
                              
                              
  
                              

  // If the t2c returned is 'NO_COLLISION' or larger than the threshold, then we do not have any collision
  if(t2c == NO_COLLISION || t2c > m_t2c_threshold)
  {
          t2c_s2c.t2c = NO_COLLISION;
          t2c_s2c.s2c = NO_COLLISION;
          return t2c_s2c;
  }

  // Otherwise, we get the space to collision (s2c) (i.e., the space between the two vehicles at now+t2c)
  s2c_ret_t s2c_struct = SpaceToCollision(x1, y1, dx1, dy1, ax1, ay1, x2, y2, dx2, dy2, ax2, ay2, t2c);
    
    double s2c = s2c_struct.s2c;
    
    
  // If the s2c returned is larger than the threshold, this means that when the two entities reach the closest point of approach,
  // the distance between the two is sufficiently safety
  if(s2c_struct.s2c>s2c_threshold)
  {
          t2c_s2c.t2c = NO_COLLISION;
          t2c_s2c.s2c = NO_COLLISION;
          return t2c_s2c;
  }

  // If the code arrives here, it means that both s2c and t2c are lower than the respective thresholds.
  // In this case a collision could occur thus it is needed to generate an alert.
  t2c_s2c.t2c = t2c;
  t2c_s2c.s2c = s2c_struct.s2c;
  t2c_s2c.x_med = s2c_struct.x_med;
  t2c_s2c.y_med = s2c_struct.y_med;
  return t2c_s2c;
  
  //changesV: 

 if (s2c < s2c_threshold) {
        // A potential collision is detected, set t2c and s2c in the return structure
        t2c_s2c.t2c = t2c;
        t2c_s2c.s2c = s2c;
        t2c_s2c.x_med = s2c_struct.x_med;
        t2c_s2c.y_med = s2c_struct.y_med;
    }

    return t2c_s2c;
  
  //ENd of changesV
}

double
CollisionAvoidanceSystem::TimeToCollision(double x1, double y1,
				   double vx1, double vy1,
				   double ax1, double ay1,
				   double x2, double y2,
				   double vx2, double vy2,
				   double ax2, double ay2)
{
  // Compute distance (in components) between the two entities parsed
  double delta_x = x1-x2;
  double delta_y = y1-y2;

  // Compute difference of speed (in components) of the two entities parsed
  double delta_vx = vx1-vx2;
  double delta_vy = vy1-vy2;

  // Here we compute three elements needed to compute t2c.
  double t2c_x = -delta_x*delta_vx;
  double t2c_y = -delta_y*delta_vy;
  double t2c_v = (delta_vx*delta_vx)+(delta_vy*delta_vy);

  double delta_ax = ax1 - ax2;
  double delta_ay = ay1 - ay2;

   /*
  * t2c_x and t2c_y are scalar products of vectors and help in finding the heading of the entities. Indeed, if at least one
  * of the two is negative, then the two vehicles are getting far apart (e.g., if t2c_x<0, it means that along the x-component
  * the two vehicles are getting far apart).
  * Consequently, a first thing to do is to check if both t2c_x>=0 and t2c_y>=0 are greater than 0. If so, a possible risk of
  * collision could exist. Moreover, a third element to check is t2c_v. Since t2c is computed as follow:
  * t2c = (t2c_x+t2c_y)/t2c_v
  * from a mathematical point of view, it is important to check that it is different from 0. From a physical point of view, if
  * t2c_v is null, it could mean two things:
  *   + the two cars do not move (i.e., vx1=vy1=vx2=vy2=0) --> so, no collision risk;
  *   + the two cars are on the same lane (one behind the other) and they move at the same speed (e.g., vx1=vx2=0, vy1=vy2). In this
  *     case again, no collision risk.
  * Consequently, we compute t2c only if:
  *   + the vehicles are moving (t2c_v>0);
  *   + the vehicles are not one behind the other moving at the same speed (t2c_v>0);
  *   + the vehicles are approaching (BOTH t2c_x and t2c_y > 0)
  */

  double t2c;

  // Compute t2c
  if(t2c_x>=0 && t2c_y>=0 && t2c_v!=0)
          t2c = (t2c_x+t2c_y)/t2c_v;
  else
          t2c = NO_COLLISION;

  
  // Calculate t2c using the new formula
  double jam_density = 1.0; // Set the jam density (ρjam) to an appropriate value
   // Desired minimum space between vehicles (2 meters)
  double min_desired_space = 1.0;
  double free_flow_speed = 1.0; // Set the free flow speed (vfree) to an appropriate value
  double vehicle_speed = sqrt(pow(vx1, 2) + pow(vy1, 2)); // Calculate the speed/velocity of the vehicle
  // Controller parameters (you may need to tune these)
  double Kp = 0.01; // Proportional gain
  double Ki = 0.1; // Integral gain

  // Static variables to maintain integral state
  static double integral = 0;

  // Calculate the current space between vehicles
  double current_space = vehicle_speed * t2c;

  // Calculate the error (the difference between the desired and current space)
  double error = min_desired_space - current_space;

  // Update the integral state
  integral += error;

  // Calculate the control input (adjustment to free_flow_speed)
  double control_input = Kp * error + Ki * integral;

  // Adjust the free_flow_speed based on the control input
  double adjusted_free_flow_speed = free_flow_speed + control_input;
  
  // Ensure that free_flow_speed does not go below zero
  if (adjusted_free_flow_speed < 0) {
    adjusted_free_flow_speed = 0;
  }



  if (t2c != NO_COLLISION)
  {
    t2c = 1 / (jam_density * (free_flow_speed - vehicle_speed));
  }
  
  
  
  if(abs(delta_ax)<0.05 && abs(delta_ay)<0.05)
  {
          //TODO: Casi con le svolte: * Caso scontro frontale all'incrocio
          //                          * Classico incrocio

          return t2c;
  }
  else // acceleration branch
    {
          // third degree equation coefficients
          double A, B, C, D;
          // third degree simplified equation coefficients
          double P, Q, det; //det distinguishes the case with real solutions and with imaginary solutions
           //Y is the solution of the simplified third degree equation from which we get t1; by Ruffini we get t2 and t3.
           //t_min is the non-negative lowest t among the t1, t2, t3

	  double Y, t1, t2, t3, t_min;
	  t_min = NO_COLLISION;

	  //TODO: Casi con le svolte: * Caso scontro frontale all'incrocio

	  if(t2c != NO_COLLISION)
	  {
		  A = pow(delta_ax,2) + pow(delta_ay,2);
		  B = 3*(delta_vx*delta_ax + delta_vy*delta_ay);
		  C = 2*(pow(delta_vx,2) + pow(delta_vy,2) + delta_x*delta_ax + delta_y*delta_ay);
		  D = 2*(delta_x*delta_vx + delta_y*delta_vy);
		  P = (C/A) - (pow(B,2)/(3*pow(A,2)));
		  Q = (D/A) - ((B*C)/(3*pow(A,2))) + ((2*pow(B,3))/(27*pow(A,3)));
		  det=(pow(Q,2)/4)+(pow(P,3)/27);

		  // A1, B1, C1 --> Ruffini coefficient of the second degree equation
		  // det1 --> determinant of the second degree equation
		  double A1, B1, C1, det1;

		  // if Q = 0 --> rear-end collision
		  if(abs(Q)<0.0001)
		  {
			  Y = 0; // if Q=0 then Y=0
			  t1 = -(B/(3*A)); // so with Y=0, t1 is computed in this way

			  // Apply Ruffini with t1
			  A1 = A;
			  B1 = B + (A1*t1);
			  C1 = C + (B1*t1);
			  // Compute the determinant for the second and third zeros (t2, t3)
			  det1 = pow(B1,2) - 4*A1*C1;
			  // Positive determinant --> 3 solutions (computed as follows)
			  if(det1>0)
			  {
				  //compute the second and third zeros
				  t2 = (-B1-sqrt(det1)) / (2*A1);
				  t3 = (-B1+sqrt(det1)) / (2*A1);
			  }
			  // Negative determinant --> single solution
			  else
			  {
				  t2 = NO_COLLISION;
				  t3 = NO_COLLISION;
			  }
		  } //end if Q = 0 --> rear-end collision
		  else //if Q!=0 (crossing collisions)
		  {
			  //if the determinant of Y is positive => real solutions
			  if(det>0)
			  {
				  Y=cbrt(-(Q/2) + sqrt(det)) + cbrt(-(Q/2) - sqrt(det));
				  t1=Y-(B/(3*A));

				  // Apply Ruffini with t1
				  A1 = A;
				  B1 = B + (A1*t1);
				  C1 = C + (B1*t1);
				  // Compute the determinant for the second and third zeros (t2, t3)
				  det1 = pow(B1,2) - 4*A1*C1;
				  // Positive determinant --> 3 solutions (computed as follows)
				  if(det1>0)
				  {
					  //compute the second and third zeros
					  t2 = (-B1-sqrt(det1)) / (2*A1);
					  t3 = (-B1+sqrt(det1)) / (2*A1);
				  }
				  // Negative determinant --> single solution
				  else
				  {
					  t2 = NO_COLLISION;
					  t3 = NO_COLLISION;
				  }
			  }//end if the determinant of Y is positive => real solutions
			  else //complex solutions
			  {
				  // Define real and imaginary part, besides the teta angle
				  double real, imm, teta;
				  // Define the three solutions
				  double Y1, Y2, Y3;

				  // Compute the real and imaginary part of the solution
				  real = -Q/2;
				  imm = sqrt(-det);
				  // If the real part is positive
				  if(real>0)
					  teta = atan(imm/real);
				  else //negative real part
					  teta = atan(imm/real)+PI;
				  // Compute the three solutions
				  Y3 = 2 * sqrt(-P/3) * cos(teta/3);
				  t3 = Y3 - (B/(3*A));
				  Y2 = 2 * sqrt(-P/3) * cos((teta+2*PI)/3);
				  t2 = Y2 - (B/(3*A));
				  Y1 = 2 * sqrt(-P/3) * cos((teta+4*PI)/3);
				  t1 = Y1 - (B/(3*A));
			  }//end if complex solutions
		  }//end if Q!=0 (crossing collisions)

		   /*Now we have the three solutions i.e., the times in which the distance is minimum. It is time to find the
		    * smallest non-negative value
		    */
		  // CASE: Paraboloid (single minimum in t1)
		  
		  
		  
		  if(t2==NO_COLLISION && t3==NO_COLLISION)
		  {
			  if(t1<0)
				  t_min = NO_COLLISION;
			  else
				  t_min = t1;
		  }
		  // CASE: 2 MINIMUM POINTS (in t2 and t3)
		  else if(t2!=NO_COLLISION && t3!=NO_COLLISION)
		  {
			  if(t2<0 && t3<0)
				  t_min = NO_COLLISION;
			  else if(t2<0 && t3>0)
				  t_min = t3;
			  else if(t2>0 && t3<0)
				  t_min = t2;
			  else if(t2>0 && t3>0)
			  {
				  if(t2<t3)
					  t_min=t2;
				  else
					  t_min=t3;
			  }
		  }
          
          
              // ChangesV: NOw here, before tm_min is outputted, there is an option of recalculating t_min. 
		   //Now we have the minimum time to collision
		  return t_min;
	  }
	  else
		  return NO_COLLISION;
  }

  return NO_COLLISION; //it should never arrive here

}

s2c_ret_t
CollisionAvoidanceSystem::SpaceToCollision(double x1, double y1,
				    double vx1, double vy1,
				    double ax1, double ay1,
				    double x2, double y2,
				    double vx2, double vy2,
				    double ax2, double ay2,
				    double t2c)
{
	// Define the positions of the two vehicles at t2c (considering speed and acceleration)
	double next_x1, next_y1, next_x2, next_y2;
	next_x1 = x1 + (t2c*vx1) + 0.5*(pow(t2c,2)*ax1);
	next_y1 = y1 + (t2c*vy1) + 0.5*(pow(t2c,2)*ay1);
	next_x2 = x2 + (t2c*vx2) + 0.5*(pow(t2c,2)*ax2);
	next_y2 = y2 + (t2c*vy2) + 0.5*(pow(t2c,2)*ay2);

	// Compute the distance between the two vehicles at t2c
	s2c_ret_t ret_struct;
	ret_struct.s2c = sqrt((next_x1-next_x2)*(next_x1-next_x2) + (next_y1-next_y2)*(next_y1-next_y2));
	ret_struct.x_med = (next_x1+next_x2)/2;
	ret_struct.y_med = (next_y1+next_y2)/2;

	return ret_struct;
}

void
CollisionAvoidanceSystem::PrintCAMinfo(cam_information_t cam)
{
  std::cout << "CAMinfo:" << std::endl;
  std::cout << "id:" << cam.id << std::endl;
  std::cout << "posx:" << cam.position.first << " posy:" << cam.position.second  << std::endl;
  std::cout << "speed:" << cam.speed << std::endl;
  std::cout << "acceleration:" << cam.acceleration << std::endl;
  std::cout << "angle:" <<  cam.angle << std::endl;
  std::cout << "timestamp:" << cam.timestamp <<std::endl;
  std::cout << "seq:" << cam.seq << std::endl;
}

struct timespec
CollisionAvoidanceSystem::compute_timestamp ()
{
  struct timespec tv;
  clock_gettime (CLOCK_MONOTONIC, &tv);
  return tv;
}

