#include "pch.h"
#include "Point.h"

TEST(TestCaseName, TestName)
{
	Point p1(1.1, 1.1);
	double distance = p1.distance(1.1, 2.2);
	EXPECT_EQ(distance, 1.1);
}