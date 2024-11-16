/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Jared Davey, Brock Hoskins, Nathan Bird
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

 // for the unit tests
class TestAngle;
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestProjectile;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
public:
   // for the unit tests
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestProjectile;

   // Constructors
   Angle()                  : radians(0.0)         {}
   Angle(const Angle& rhs)  : radians(rhs.radians) {}
   Angle(double degrees)    : radians(0.0)         { setDegrees(degrees); }

   // Getters
   double getDegrees() const { return radians * (180.0 / M_PI); }
   double getRadians() const { return radians; }

   //         dx 
   //    +-------/
   //    |      /
   // dy |     /
   //    |    / 1.0
   //    | a /
   //    |  /
   //    | /
   // dy = cos a
   // dx = sin a
   double getDx()            const { return sin(radians); }
   double getDy()            const { return cos(radians); }
   bool   isRight()          const { return radians >= 0.0 && 
	                                        radians < M_PI;    }
   bool   isLeft()           const { return radians > M_PI_2 && 
	                                        radians < 2 * M_PI; }


   // Setters
   void setDegrees(double degrees) { radians = 
	                                 normalize(degrees * M_PI / 180.0); }
   void setRadians(double radians) { this->radians = normalize(radians); }    
   void setUp()                    { radians = 0.0; }
   void setDown()                  { radians = M_PI; }
   void setRight()                 { radians = M_PI_2; }
   void setLeft()                  { radians = 3 * M_PI_2; }
   void reverse()                  { radians = normalize(radians + M_PI); }
   Angle& add(double delta)        { radians = 
	                                 normalize(radians + delta); return *this;}

   // set based on the components
   //         dx
   //     +-------/
   //     |      /
   //  dy |     /
   //     |    /
   //     | a /
   //     |  /
   //     | /
   void setDxDy(double dx, double dy) { radians = normalize(atan2(dx, dy)); }
   Angle operator+(double degrees)
                     const { return Angle(*this).add(degrees * M_PI / 180.0); }

private:

   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};
