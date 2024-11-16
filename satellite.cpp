/***********************************************************************
 * Source File:
 *    Satellite
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The base class for all orbital objects
 ************************************************************************/

#include "angle.h"
#include "position.h"
#include "satellite.h"
#include "velocity.h"
#include <cmath>

constexpr double RADIUS_EARTH = 6378000.0;  // meters
constexpr double GRAVITY_SEA = 9.80665;     // meters/second^2


Satellite::Satellite(const Velocity& velocity, const Position& pos, const Angle& direction, double angularVelocity, double radius) : dead(false)
{
   this->velocity = velocity;
   this->pos = pos;
   this->direction = direction;
   this->angularVelocity = angularVelocity;
   this->radius = radius;
}

Satellite::Satellite(const Position& pos) : Satellite()
{
   this->pos = pos;
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
   double a = getGravity();

   double angle = directionOfPull();  // direction in radians
   double ddx = a * sin(angle);
   double ddy = a * cos(angle);

   pDemo->ptGPS.setDX(motionConstantChange(pDemo->ptGPS.getDX(), ddx, tpf));
   pDemo->ptGPS.setDY(motionConstantChange(pDemo->ptGPS.getDY(), ddy, tpf));

   pDemo->ptGPS.setMetersX(distance(pDemo->ptGPS.getMetersX(), pDemo->ptGPS.getDX(), ddx, tpf));
   pDemo->ptGPS.setMetersY(distance(pDemo->ptGPS.getMetersY(), pDemo->ptGPS.getDY(), ddy, tpf));
}
