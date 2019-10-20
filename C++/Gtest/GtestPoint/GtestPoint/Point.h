#pragma once

#ifdef MAKEDLL
#define EXPORT __declspec(dllexport)
#else
#  define EXPORT __declspec(dllimport)
#endif

class EXPORT Point
{
private:
	double m_x;
	double m_y;

public:
	Point(double x, double y) : m_x(x), m_y(y) { ; }
	Point() :Point(0, 0) { ; }
	double getX() { return m_x; }
	double getY() { return m_y; }
	void setX(double x) { m_x = x; }
	void setY(double y) { m_y = y; }
	double distance(double x, double y);
};

