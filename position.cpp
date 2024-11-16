/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Nathan Bird, Brock Hoskins, Jared Davey
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "acceleration.h"
#include "position.h"
#include "velocity.h"
#include <iosfwd>
#include <iostream>

/******************************************
 * Position : CONSTURCTOR
 * Position from x and y
 *****************************************/
Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
 * Position : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

/******************************************
 * Position : ADD
 * update position from velocity, acceleration
 * and time
 *****************************************/
void Position::add(const Velocity& v, const Acceleration& a, double time)
{
   x += (v.getDX() * time) + ((.5 * a.getDDX()) * (time * time));
   y += (v.getDY() * time) + ((.5 * a.getDDY()) * (time * time));
}

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}
   
/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}
