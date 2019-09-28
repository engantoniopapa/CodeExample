#pragma once

#ifdef MAKEDLL
#define EXPORT __declspec(dllexport)
#else
#  define EXPORT __declspec(dllimport)
#endif

class Point2_Imp;
class EXPORT Point2
{
public:
	Point2(double x1, double y1, double x2, double y2);
	double distance();
private:
	Point2_Imp* imp_;
};


template<class T>
class Point2T_Imp;

template<class T>
class  Point2T
{
public:
	Point2T(T x1, T y1, T x2, T y2);
	double distance();
private:
	Point2T_Imp<T>* imp_;
};
