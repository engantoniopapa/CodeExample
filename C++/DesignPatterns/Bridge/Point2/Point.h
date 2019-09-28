#pragma once

class Point
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
};

template<class T>
class PointT
{
private:
	T m_x;
	T m_y;

public:
	PointT(T x, T y) : m_x(x), m_y(y) { ; }
	PointT() :Point(0, 0) { ; }
	double getX() { return m_x; }
	double getY() { return m_y; }
	void setX(T x) { m_x = x; }
	void setY(T y) { m_y = y; }
};