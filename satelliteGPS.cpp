/***********************************************************************
 * Source File:
 *    GPS
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The GPS satellite which inherits from the base Satellite
 ************************************************************************/

#include "satelliteGPS.h"
#include "uiDraw.h"

/*********************************************
 * GPS : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void GPS::draw(ogstream& gout)
{
   gout.drawGPS(pos, direction.getDegrees());
}
