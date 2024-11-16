/***********************************************************************
 * Source File:
 *    TEST SATELLITE
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Test cases to ensure the satellite functions completely as
 *    a base class.
 **********************************************************************/
#pragma once

#include "position.h"
#include "satellite.h"
#include "testSatellite.h"
#include "unitTest.h"
#include "velocity.h"

 /*****************************************************************
  *****************************************************************
  * GETTERS
  *****************************************************************
  *****************************************************************/

 /*********************************************
 * name:    IS DEAD
 * input:   dead = True
 * output:  true
 *********************************************/
void TestSatellite::isDead_dead()
{  // setup
   SatelliteDerived s;
   bool b = false;
   s.dead = true;

   // exercise
   b = s.isDead();

   // verify
   assertUnit(b == true);
}  // teardown

/*********************************************
* name:    IS NOT DEAD
* input:   dead = False
* output:  false
*********************************************/
void TestSatellite::isDead_alive()
{  // setup
   SatelliteDerived s;
   bool b = true;
   s.dead = false;

   // exercise
   b = s.isDead();

   // verify
   assertUnit(b == false);
}  // teardown

/*********************************************
* name:    GET POSITION while at ZERO
* input:   pos=(0.0, 0.0)
* output:  pos=(0.0, 0.0)
*********************************************/
void TestSatellite::getPosition_zero()
{  // setup
   SatelliteDerived s;
   s.pos.x = 0.0;
   s.pos.y = 0.0;
   Position pos;
   pos.x = 1.2;
   pos.y = 3.4;

   // exercise
   pos = s.getPosition();

   // verify
   assertEquals(pos.x, 0.0);
   assertEquals(pos.y, 0.0);
   assertEquals(s.pos.x, 0.0);
   assertEquals(s.pos.y, 0.0);
} // teardown

/*********************************************
* name:    GET POSITION while at MIDDLE of screen
* input:   pos=(55.5, 66.6)
* output:  pos=(55.5, 66.6)
*********************************************/
void TestSatellite::getPosition_middle()
{  // setup
   SatelliteDerived s;
   s.pos.x = 55.5;
   s.pos.y = 66.6;
   Position pos;
   pos.x = 0.0;
   pos.y = 0.0;

   // exercise
   pos = s.getPosition();

   // verify
   assertEquals(pos.x, 55.5);
   assertEquals(pos.y, 66.6);
   assertEquals(s.pos.x, 55.5);
   assertEquals(s.pos.y, 66.6);
}  // teardown

/*********************************************
* name:    GET SPEED while STATIONARY
* input:   v=(0.0, 0.0)
* output:  0.0
*********************************************/
void TestSatellite::getSpeed_zero()
{  // setup
   SatelliteDerived s;
   s.velocity.dx = 0.0;
   s.velocity.dy = 0.0;
   double speed = 1.2;

   // exercise
   speed = s.getSpeed();

   // verify

   assertEquals(speed, 0.0);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 0.0);
}  // teardown

/*********************************************
* name:    GET SPEED while flying RIGHT
* input:   v=(11.11, 0.0)
* output:  11.11
*********************************************/
void TestSatellite::getSpeed_right()
{  // setup
   SatelliteDerived s;
   s.velocity.dx = 11.11;
   s.velocity.dy = 0.0;
   double speed = 0.0;

   // exercise
   speed = s.getSpeed();

   // verify
   assertEquals(speed, 11.11);
   assertEquals(s.velocity.dx, 11.11);
   assertEquals(s.velocity.dy, 0.0);
}  // teardown

/*********************************************
* name:    GET SPEED while flying LEFT
* input:   v=(-11.11, 0.0)
* output:  11.11
*********************************************/
void TestSatellite::getSpeed_left()
{  // setup
   SatelliteDerived s;
   s.velocity.dx = -11.11;
   s.velocity.dy = 0.0;
   double speed = 0.0;

   // exercise
   speed = s.getSpeed();

   // verify
   assertEquals(speed, 11.11);
   assertEquals(s.velocity.dx, -11.11);
   assertEquals(s.velocity.dy, 0.0);
}  // teardown

/*********************************************
* name:    GET SPEED while flying UP
* input:   v=(0.0, 22.2)
* output:  22.2
*********************************************/
void TestSatellite::getSpeed_up()
{  // setup
   SatelliteDerived s;
   s.velocity.dx = 0.0;
   s.velocity.dy = 22.22;
   double speed = 0.0;

   // exercise
   speed = s.getSpeed();

   // verify
   assertEquals(speed, 22.22);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 22.22);
}  // teardown

/*********************************************
* name:    GET SPEED while flying DOWN
* input:   v=(0.0, -22.2)
* output:  22.2
*********************************************/
void TestSatellite::getSpeed_down()
{  // setup
   SatelliteDerived s;
   s.velocity.dx = 0.0;
   s.velocity.dy = -22.22;
   double speed = 0.0;

   // exercise
   speed = s.getSpeed();

   // verify
   assertEquals(speed, 22.22);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, -22.22);
}  // teardown

/*********************************************
* name:    GET SPEED while flying DIAGONAL
* input:   v=(30.0, 40.0)
* output:  50.0
*********************************************/
void TestSatellite::getSpeed_diagonal()
{  // setup
   SatelliteDerived s;
   s.velocity.dx = 30.0;
   s.velocity.dy = 40.0;
   double speed = 0.0;

   // exercise
   speed = s.getSpeed();

   // verify
   assertEquals(speed, 50.0);
   assertEquals(s.velocity.dx, 30.0);
   assertEquals(s.velocity.dy, 40.0);
} // teardown

/*****************************************************************
*****************************************************************
* MOVE
*****************************************************************
*****************************************************************/

/*********************************************
* name:    GET POSITION of Satellite after moving with no time.
* input:   move(0)
* output:  x=50,000km, y=50,000km
*********************************************/
void TestSatellite::move_noTime()
{
   // setup
   SatelliteDerived s;
   s.pos.x = 5000000000.0;
   s.pos.y = 5000000000.0;
   s.velocity.dx = 30.0;
   s.velocity.dy = 30.0;
   double time = 0;

   // exercise
   s.move(time);

   //verify
   assertEquals(time, 0);
   assertEquals(s.velocity.dx, 30.0);
   assertEquals(s.velocity.dy, 30.0);
   assertEquals(s.pos.x, 5000000000.0);
   assertEquals(s.pos.y, 5000000000.0);
} // teardown

/*********************************************
* name:    GET POSITION of Satellite after moving with time.
* input:   move(3)
* output:  x != 50,000km, y != 50,000km
*********************************************/
void TestSatellite::move_time()
{
   // setup
   SatelliteDerived s;
   s.pos.x = 50000000.0;
   s.pos.y = 50000000.0;
   s.velocity.dx = 30.0;
   s.velocity.dy = 30.0;
   double time = 3;

   // exercise
   s.move(time);

   //verify
   assertEquals(time, 3);
   assertUnit(s.pos.x != 50000000.0);
   assertUnit(s.pos.y != 50000000.0);
} // teardown

