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
#include <cassert>
#include <cmath>

// Constants for calculating gravity.
constexpr double RADIUS_EARTH = 6378000.0;  // meters
constexpr double GRAVITY_SEA = 9.80665;     // meters/second^2

/***************************************************
 * SATELLITE NON-DEFAULT CONSTRUCTOR
 * Constructor from all parameters passed in
 ***************************************************/
Satellite::Satellite(const Position& pos, const Velocity& velocity, const Angle& direction, double angularVelocity, double radius) : dead(false)
{
   this->velocity = velocity;
   this->pos = pos;
   this->direction = direction;
   this->angularVelocity = angularVelocity;
   this->radius = radius;
}

/***************************************************
 * SATELLITE NON-DEFAULT CONSTRUCTOR
 * Constructor from position and velocity
 ***************************************************/
Satellite::Satellite(const Position& pos, const Velocity& vel) : Satellite()
{
   this->pos = pos;
   this->velocity = vel;
}

/***************************************************
 * SATELLITE COPY CONSTRUCTOR
 * Constructor from other Satellite
 ***************************************************/
Satellite::Satellite(const Satellite& rhs)
{
   this->velocity = rhs.velocity;
   this->pos = rhs.pos;
   this->direction = rhs.direction;
   this->angularVelocity = rhs.angularVelocity;
   this->dead = rhs.dead;
   this->radius = rhs.radius;
}

/***************************************************
 * SATELLITE : HEIGHT_ABOVE_EARTH
 * Distance to the surface of the earth
 ***************************************************/
double Satellite::heightAboveEarth() const
{
   double x = pos.getMetersX();
   double y = pos.getMetersY();
   double height = sqrt(x * x + y * y) - RADIUS_EARTH;
   assert(height > 0);  // Height is 0 when touching surface of earth.
   return height;
}

/***************************************************
 * SATELLITE : GRAVITY_AT_HEIGHT
 * Gravatational acceleration at height
 ***************************************************/
double Satellite::gravityAtHeight(double h) const
{
   return GRAVITY_SEA * (RADIUS_EARTH / (RADIUS_EARTH + h)) * (RADIUS_EARTH / (RADIUS_EARTH + h));
}

/***************************************************
 * SATELLITE : GET_GRAVITY
 * Gets gravity for the satellite's position relative
 * to the earth
 ***************************************************/
double Satellite::getGravity() const
{
   return gravityAtHeight(heightAboveEarth());
}

/***************************************************
 * SATELLITE : DIRECTION_OF_PULL
 * Get the direction toward the earth (position 0,0)
 ***************************************************/
double Satellite::directionOfPull() const
{
   return atan2(0 - pos.getMetersX(), 0 - pos.getMetersY());
}

/***************************************************
 * SATELLITE : MOVE
 * Update the satellite's position in space
 ***************************************************/
void Satellite::move(double deltaTime)
{
   double gravity = getGravity();

   double angle = directionOfPull();
   double ddx = gravity * sin(angle);
   double ddy = gravity * cos(angle);
   Acceleration accel(ddx, ddy);

   velocity.add(accel, deltaTime);
   pos.add(velocity, accel, deltaTime);
}
