/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

 /************************************
  * ANGLE : NORMALIZE
  ************************************/
double Angle::normalize(double radians) const
{
    if (radians >= 2.0 * M_PI)
    {
        double multiples = floor(radians / (2.0 * M_PI));
        return radians - ((2.0 * M_PI) * multiples);
    }
    else if (radians < 0.0)
    {
        double multiples = ceil(-radians / (2.0 * M_PI));
        return radians + ((M_PI * 2.0) * multiples);
    }
    assert(radians >= 0 && radians < 2 * M_PI);

    return radians;
}
