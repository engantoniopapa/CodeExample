#include "stdafx.h"
#include <math.h> 
#include "Point2_Imp.h"

double Point2_Imp::distance()
{
	double distance = sqrt(pow((m_p2.getX() - m_p1.getX()), 2) + pow((m_p2.getY() - m_p1.getY()), 2));
	return distance;
}


template<class S>
double Point2T_Imp<S>::distance()
{
	double distance = sqrt(pow((m_p2.getX() - m_p1.getX()), 2) + pow((m_p2.getY() - m_p1.getY()), 2));
	return distance;
}