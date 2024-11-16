/***********************************************************************
 * Header File:
 *    SATELLITE
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Everything we need to know about satellites
 ************************************************************************/
#pragma once

#include "unitTest.h"

class TestSatellite : public UnitTest
{
public:
   void run()
   {

      isDead_dead();
      isDead_alive();
      getPosition_zero();
      getPosition_middle();
      getSpeed_zero();
      getSpeed_left();
      getSpeed_right();
      getSpeed_up();
      getSpeed_down();
      getSpeed_diagonal();
      move_noTime();
      move_time();

      report("Satellite");
   }
private:
   void isDead_dead();
   void isDead_alive();
   void getPosition_zero();
   void getPosition_middle();
   void getSpeed_zero();
   void getSpeed_left();
   void getSpeed_right();
   void getSpeed_up();
   void getSpeed_down();
   void getSpeed_diagonal();
   void move_noTime();
   void move_time();
};