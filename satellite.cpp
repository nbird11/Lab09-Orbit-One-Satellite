/***********************************************************************
 * Source File:
 *    Satellite
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The base class for all orbital objects
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"
#include "position.h"
#include "satellite.h"
#include "velocity.h"
#include <cmath>

constexpr double RADIUS_EARTH = 6378000.0;  // meters
constexpr double GRAVITY_SEA = 9.80665;     // meters/second^2

Satellite::Satellite(const Position& pos, const Velocity& velocity, const Angle& direction, double angularVelocity, double radius) : dead(false)
{
   this->velocity = velocity;
   this->pos = pos;
   this->direction = direction;
   this->angularVelocity = angularVelocity;
   this->radius = radius;
}

Satellite::Satellite(const Position& pos, const Velocity& vel) : Satellite()
{
   this->pos = pos;
   this->velocity = vel;
}

Satellite::Satellite(const Satellite& rhs)
{
   this->velocity = rhs.velocity;
   this->pos = rhs.pos;
   this->direction = rhs.direction;
   this->angularVelocity = rhs.angularVelocity;
   this->dead = rhs.dead;
   this->radius = rhs.radius;
}

double Satellite::heightAboveEarth() const
{
   double x = pos.getMetersX();
   double y = pos.getMetersY();
   return sqrt(x*x + y*y) - RADIUS_EARTH;
}

double Satellite::gravityAtHeight(double h) const
{
   return GRAVITY_SEA * (RADIUS_EARTH / (RADIUS_EARTH + h)) * (RADIUS_EARTH / (RADIUS_EARTH + h));
}

double Satellite::getGravity() const
{
   return gravityAtHeight(heightAboveEarth());
}

double Satellite::directionOfPull() const
{
   return atan2(pos.getMetersX(), pos.getMetersY());
}

void Satellite::move(double deltaTime)
{
   Acceleration acceleration(direction, getGravity());

   velocity.add(acceleration, deltaTime);
   pos.add(velocity, acceleration, deltaTime);

   direction.add(angularVelocity);
}
