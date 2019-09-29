// Observer.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <vector>
#include <typeinfo>

class Observer;
class Event
{
public:
	Event() : m_val(0) { ; }
	void setEvent(int val)
	{
		m_val = val;
		notify();
	}

	void attachObsever(std::shared_ptr<Observer> ptr_ob)
	{
		m_views.push_back(ptr_ob);
	}

	virtual void notify() = 0;

protected:
	std::vector<std::shared_ptr<Observer>> m_views;
	int m_val;
};

class Observer : public std::enable_shared_from_this<Observer>
{
public:
	Observer(std::shared_ptr<Event> ptr, double sensitivity) : m_pEvent(ptr), m_sensitivity(sensitivity) { ; }
	
	void attachEvent()
	{
		// Has to be copied into a shared_ptr before usage
		auto sptr = m_pEvent.lock();
		sptr->attachObsever(shared_from_this());
	}
	
	virtual void update(int val) = 0;

protected:
	double getSensitivity()
	{
		return m_sensitivity;
	}

	std::shared_ptr<Event> getEvent()
	{
		// Has to be copied into a shared_ptr before usage
		auto sptr = m_pEvent.lock();
		return sptr;
	}

private:
	double m_sensitivity;
	std::weak_ptr<Event> m_pEvent;
};



class LaserSensor : public Observer
{
public:
	LaserSensor(std::shared_ptr<Event> ptr, double sensitivity, int nLaser)
		: Observer(ptr, sensitivity), m_numberLaser(nLaser) { ;	}
	void update(int val) override
	{
		double totalSensitivity = getSensitivity() - (0.1 * m_numberLaser);

		if (totalSensitivity < val)
		{
			std::cout << "Laser Sensor: Found a thief!" << std::endl;
		}
		else
		{
			std::cout << "Laser Sensor: Found a fly!" << std::endl;
		}
	}

protected:
	int m_numberLaser;
};

class CameraSensor : public Observer
{
public:
	CameraSensor(std::shared_ptr<Event> ptr, double sensitivity, double precision)
		: Observer(ptr, sensitivity), m_Pixelprecision(precision) { ; }

	void update(int val) override
	{
		double totalSensitivity = getSensitivity() - (0.1 * m_Pixelprecision);

		if (totalSensitivity < val)
		{
			std::cout << "Camera Sensor: Found a thief!" << std::endl;
		}
		else
		{
			std::cout << "Camera Sensor: Found a fly!" << std::endl;
		}
	}

protected:
	double m_Pixelprecision;
};

class Night : public Event
{
public:
	void notify()
	{
		for (int i = 0; i < m_views.size(); ++i)
		{
			int val = m_val;

			if(typeid(*m_views[i]) == typeid(CameraSensor))
			{
				val *= 2;
				std::cout << "Night["<< val <<"] -> CameraSensor" << std::endl;
				m_views[i]->update(val);
			}
			else if (typeid(*m_views[i]) == typeid(LaserSensor))
			{
				val *= 3;
				std::cout << "Night[" << val << "] -> LaserSensor" << std::endl;
				m_views[i]->update(val);
			}
			else
			{
				m_views[i]->update(val);
			}
		}
	}
};

int main()
{
	std::shared_ptr<Night> night = std::make_shared<Night>();
	std::shared_ptr<CameraSensor> cam1 = std::make_shared<CameraSensor>(night, 6, 2);
	std::shared_ptr<LaserSensor> laser1 = std::make_shared<LaserSensor>(night, 6, 4);
	std::shared_ptr<CameraSensor> cam2 = std::make_shared<CameraSensor>(night, 8, 2);

	cam1->attachEvent();
	laser1->attachEvent();
	cam2->attachEvent();

	night->setEvent(2);
}

