// Bridge.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include "Point2.h"


int main()
{
	Point2 p2_1(1, 1, 2, 2);	
	std::cout << "D[(1,1),(2,2)]: " << p2_1.distance() << std::endl;

	Point2 p2_2(1.1, 1.1, 2.2, 2.2);
	std::cout << "D[(1.1,1.1),(2.2,2.2)]: " << p2_2.distance() << std::endl;

	getchar();
}
