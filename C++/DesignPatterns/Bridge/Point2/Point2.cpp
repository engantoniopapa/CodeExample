#include "stdafx.h"
#define MAKEDLL
#include "Point2.h"
#include "Point2_Imp.h"

Point2::Point2(double x1, double y1, double x2, double y2)
{
	imp_ = new Point2_Imp(x1, y1, x2, y2);
}

double Point2::distance()
{
	return imp_->distance();
}

template<class T>
Point2T<T>::Point2T(T x1, T y1, T x2, T y2)
{
	imp_ = new Point2T_Imp<T>(x1, y1, x2, y2);
}

template<class T>
double Point2T<T>::distance()
{
	return imp_->distance();
}