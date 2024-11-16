/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS satellite which inherits from the base Satellite
 ************************************************************************/

#pragma once
#include "satellite.h"
#include <cassert>
#include <vector>

#define NOT_IMPLEMENTED false

class Position;
class Velocity;
class ogstream;

/***************************************************
 * GPS
 * The GPS type derived from Satellite
 ***************************************************/
class GPS : public Satellite
{
public:
   GPS() : Satellite() { }
   GPS(const Position& pos, const Velocity& vel) : Satellite(pos, vel) { }
   ~GPS() {}

   void draw(ogstream& gout) override;
   void destroy(const std::vector<Satellite*>& satellites) override { assert(NOT_IMPLEMENTED); }
};

