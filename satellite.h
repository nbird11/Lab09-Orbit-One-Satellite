/***********************************************************************
 * Header File:
 *    Satellite
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The base class for all orbital objects
 ************************************************************************/

#include "angle.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "velocity.h"
#include <cassert>
#include <vector>
#pragma once

class TestSatellite;
class TestGPS;

/***************************************************
 * SATELLITE
 * The abstract satellite type
 ***************************************************/
class Satellite
{
public:
   friend TestSatellite;
   friend TestGPS;

   // Constructors
   Satellite() : velocity(Velocity()), pos(Position()), direction(Angle()),
                 angularVelocity(0.0), dead(false), radius(0.0) {}
   Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double angularVel, double radius);
   Satellite(const Position& pos, const Velocity& vel);
   Satellite(const Satellite& rhs);

   // Getters
   double getRadius()     const { return radius;              }
   Position getPosition() const { return pos;                 }
   double getSpeed()      const { return velocity.getSpeed(); }
   bool isDead()          const { return dead;                }
   
   // Setters
   void kill() { dead = true; }

   virtual void move(double time);
   virtual void draw(ogstream& gout) = 0;
   virtual void destroy(const std::vector<Satellite*>& satellites) = 0;
   virtual void input(const Interface* pUI) {}
   
private:
   double heightAboveEarth() const;
   double gravityAtHeight(double h) const;
   double getGravity() const;
   double directionOfPull() const;

protected:
   Velocity velocity;
   Position pos;
   Angle direction;
   double angularVelocity;
   bool dead;
   double radius;
};

/***************************************************
 * SATELLITE DERIVED
 * A simple derived class so we can test Satellite.
 ***************************************************/
class SatelliteDerived : public Satellite
{
public:
   SatelliteDerived() : Satellite() { }
   SatelliteDerived(const Position& p, const Velocity& v) : Satellite(p, v) { }
   ~SatelliteDerived() { }

   virtual void draw(ogstream& gout) { assert(false); }
   virtual void destroy(const std::vector<Satellite*>& satellites) { assert(false); }
   virtual void input(const Interface* pUI) { assert(false); }
};

class SatelliteDummy : public Satellite
{
public:
   SatelliteDummy() : Satellite() { }
   ~SatelliteDummy() { }

   double getRadius()     const { assert(false); return radius;   }
   Position getPosition() const { assert(false); return pos;      }
   double   getSpeed()    const { assert(false); return velocity.getSpeed(); }
   bool isDead()          const { assert(false); return dead;     }

   void kill() { assert(false); }

   virtual void move(double time) { assert(false); }
   virtual void draw(ogstream& gout) { assert(false); }
   virtual void destroy(const std::vector<Satellite*>& satellites) { assert(false); }
   virtual void input(const Interface* pUI) { assert(false); }
};

class SatelliteStub : public SatelliteDummy
{
public:
   SatelliteStub() : SatelliteDummy() { }
   ~SatelliteStub() { }

   double getRadius()     const { assert(false); return radius;   }
   Position getPosition() const { assert(false); return pos;      }
   double   getSpeed()    const { assert(false); return velocity.getSpeed(); }
   bool isDead()          const { assert(false); return dead;     }

   void kill() { assert(false); }

   virtual void move(double time) { assert(false); }
   virtual void draw(ogstream& gout) { assert(false); }
   virtual void destroy(const std::vector<Satellite*>& satellites) { assert(false); }
   virtual void input(const Interface* pUI) { assert(false); }
};
