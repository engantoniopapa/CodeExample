// AbstractFactory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <atomic>
#include <vector>

#define PEACE

class Unit
{
public:
	Unit()
	{
		m_id = ++_population;
	}
	virtual ~Unit() {};
	virtual void action() =0;

protected:
	static unsigned long int _population;
	int m_id;
};

unsigned long int Unit::_population = 0;


class Farmer : public Unit
{
public:
	Farmer(double strength, double life) :m_strength(strength), m_life(life) {};
	virtual ~Farmer() {};
	virtual void action() override
	{
		std::cout << "ID[" << m_id << "] Farmer, food kg/day: " << m_strength * m_life << std::endl;
	}

protected:
	double m_strength;
	double m_life;
};


class Hunter : public Unit
{
public:
	Hunter(double aim, double life) :m_aim(aim), m_life(life) {};
	virtual ~Hunter() {};
	virtual void action() override
	{
		std::cout << "ID[" << m_id << "] Hunter, food kg/day: " << m_aim * m_life << std::endl;
	}

protected:
	double m_aim;
	double m_life;
};


class Hoplite : public Unit
{
public:
	Hoplite(double strength,  double life) :m_strength(strength), m_life(life){};
	virtual ~Hoplite() {};
	virtual void action() override
	{
		std::cout << "ID[" << m_id << "] Hoplite, stats: power = " << m_strength * m_life << std::endl;
	}

protected:
	double m_strength;
	double m_life;
};


class Archer : public Unit
{
public:
	Archer(double aim, double life) :m_aim(aim), m_life(life) {};
	virtual ~Archer() {};
	virtual void action() override
	{
		std::cout << "ID[" << m_id << "] Archer, stats: power = " << m_aim * m_life << std::endl;
	}

protected:
	double m_aim;
	double m_life;
};

//Building: Barrack[Hoplite,Archer] TowerHall[Farmer,Hunter]
class Building 
{
public:
	virtual Unit* createFootUnit(double strength, double life) = 0;
	virtual Unit* createArcheryUnit(double aim, double life) = 0;
};

class Barrack : public Building
{
public:
	virtual Unit* createFootUnit(double strength, double life) override
	{
		return new Hoplite(strength,life);
	}

	virtual Unit* createArcheryUnit(double aim, double life) override
	{
		return new Archer(aim, life);
	}
};

class TowerHall : public Building
{
public:
	virtual Unit* createFootUnit(double strength, double life) override
	{
		return new Farmer(strength, life);
	}

	virtual Unit* createArcheryUnit(double aim, double life) override
	{
		return new Hunter(aim, life);
	}
};


int main()
{
#ifdef PEACE
	Building* factory = new TowerHall;
#else if WAR
	Building* factory = new Barrack;
#endif

	std::vector<Unit*> unit;

	unit.push_back(factory->createFootUnit(3,10));   // new Foot Unit;
	unit.push_back(factory->createArcheryUnit(4, 7)); // new Archery Unit;
	unit.push_back(factory->createFootUnit(4, 7));    // new Foot Unit;
	unit.push_back(factory->createArcheryUnit(6, 4)); // new Archery Unit;

	for (std::vector<Unit*>::iterator itr_unit = unit.begin(); itr_unit != unit.end(); ++itr_unit)
	{
		(*itr_unit)->action();
	}

	getchar();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
