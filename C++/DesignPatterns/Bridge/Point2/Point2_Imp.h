#pragma once
#include "Point.h"

class Point2_Imp
{
public:
	Point2_Imp(double x1, double y1, double x2, double y2) : m_p1(x1, y1), m_p2(x2, y2) { ; }
	double distance();
private:
	Point m_p1;
	Point m_p2;
};

template<class T>
class Point2T_Imp
{
public:
	Point2T_Imp(T x1, T y1, T x2, T y2) : m_p1(x1, y1), m_p2(x2, y2) { ; }
	double distance();
private:
	PointT<T> m_p1;
	PointT<T> m_p2;
};