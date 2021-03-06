// InheritancesDefaultArguments.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>

class SuperA
{
public:
	virtual void print(int x = 5)
	{
		std::cout << "Super Class A, default variable x =" << x << std::endl;
	}
};


class SubA : public SuperA
{
public:
	virtual void print(int x = 10) override
	{
		std::cout << "Sub Class B, default variable x =" << x << std::endl;
	}
};


#define default_val_super 15
#define default_val_sub 20


class SuperB
{
public:
	virtual void print(int x = default_val_super)
	{
		std::cout << "Super Class B, default variable x =" << x << std::endl;
	}
};


class SubB : public SuperB
{
public:
	virtual void print(int x = default_val_sub) override
	{
		std::cout << "Sub Class B, default variable x =" << x << std::endl;
	}
};


int main()
{
	SuperA mySuperA;
	SubA mySubA;
	SuperA& mySuperARefToSubA = mySubA;
	mySuperA.print();
	mySubA.print();
	mySuperARefToSubA.print();

	SuperB mySuperB;
	SubB mySubB;
	SuperB& mySuperBRefToSubB = mySubB;
	mySuperB.print();
	mySubB.print();
	mySuperBRefToSubB.print();

	std::getchar();

	/* Output ----
		Super Class A, default variable x = 5
		Sub Class B, default variable x = 10
		Sub Class B, default variable x = 5
		Super Class B, default variable x = 15
		Sub Class B, default variable x = 20
		Sub Class B, default variable x = 15
	---- */
    return 0;
}

