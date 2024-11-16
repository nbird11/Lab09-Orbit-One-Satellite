/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Nathan Bird, Brock Hoskins, Jared Davey
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

// for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestSatellite;

// for add()
class Acceleration;
class Angle;

/*********************************************
 * Velocity
 * I feel the need, the need for speed
 *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestSatellite;


public:
   // constructors
   Velocity() : dx(0.0), dy(0.0) { }
   Velocity(double dx, double dy) : dx(dx), dy(dy) { }

   // getters
   virtual double getDX()       const { return dx; }
   virtual double getDY()       const { return dy; }
   virtual double getSpeed()    const;
   virtual Angle  getAngle()    const;

   // setters
   virtual void setDX(double dx) { this->dx = dx; }
   virtual void setDY(double dy) { this->dy = dy; }
   virtual void set(const Angle& angle, double magnitude);
   virtual void addDX(double dx) { setDX(getDX() + dx); }
   virtual void addDY(double dy) { setDY(getDY() + dy); }
   virtual void add(const Acceleration& acceleration, double time);
   virtual void addV(const Velocity& rhs)
   {
      this->dx = dx + rhs.dx;
      this->dy = dy + rhs.dy;
   }
   virtual void reverse()
   {
      this->dx = -dx;
      this->dy = -dy;
   }

private:
   double dx;           // horizontal velocity
   double dy;           // verticacl velocity
};

#include <cassert>
/*********************************************
 * VelocityDummy
 * A Dummy double for velocity. This does nothing but assert.
 * Stubs will be derived from this for the purpose of making
 * isolated unit tests.
 *********************************************/
class VelocityDummy : public Velocity
{
public:
   // getters
   double    getDX()    const { assert(false); return 0.0; }
   double    getDY()    const { assert(false); return 0.0; }
   double    getSpeed() const { assert(false); return 0.0; }
   Angle     getAngle() const;

   // setters
   void setDX(double dx) { assert(false); }
   void setDY(double dy) { assert(false); }
   void setDxDy(double dx, double dy) { assert(false); }
   void setDirection(const Angle& direction) { assert(false); }
   void setSpeed(double speed) { assert(false); }
   void set(const Angle& angle, double magnitude) { assert(false); }
   void add(const Acceleration& a, double t) { assert(false); }
   void addDX(double dx) { assert(false); }
   void addDY(double dy) { assert(false); }
   void addV(const Velocity& v) { assert(false); }
   void reverse() { assert(false); }
};