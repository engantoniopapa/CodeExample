#include "stdafx.h"
#include <math.h>
#define MAKEDLL
#include "Point.h"

double Point::distance(double x, double y)
{
	double distance = sqrt(pow((m_x - x), 2) + pow((m_y - y), 2));
	return distance;
}