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
#include <vector>
#pragma once

class testSatellite;
class Satellite
{
public:
    friend ::testSatellite;

   // Constructors
   Satellite() : velocity(Velocity()), pos(Position()), direction(Angle()),
                 angularVelocity(0.0), dead(false), radius(0.0) {}
   Satellite(const Velocity& vel, const Position& pos, const Angle& angle, double angularVel, double radius);
   Satellite(const Position& pos);
   Satellite(const Satellite& rhs);

   // Getters
   double getRadius()     const { return radius;   }
   Position getPosition() const { return pos;      }
   bool isDead()          const { return dead;     }
   Velocity getSpeed()    const { return velocity; }

   // Setters
   void kill() { dead = true; }

   virtual void move(double time);
   virtual void draw(const ogstream& gout)                         = 0;
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

