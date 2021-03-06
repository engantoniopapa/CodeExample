// Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Singleton.hpp"
#include <iostream>
#include <string>


//Singleton1 - lazy initialization, no thread safe:
Singleton1* Singleton1::s_instance = nullptr;

Singleton1* Singleton1::get_instance()
{
	if (s_instance == nullptr)
	{
		s_instance = new Singleton1();
		std::cerr << "Create Dynamic Memory for Singleton1" << std::endl;
	}

	return s_instance;
}

void Singleton1::destroy_instance()
{
	if (s_instance != nullptr)
	{
		delete s_instance;
	}
}

void Singleton1::do_something()
{
	std::cerr << "Class name: " << static_cast<std::string> (typeid(this).name()) << std::endl;
}
//end Singleton1

//Singleton2 - lazy initialization, thread safe:
Singleton2* Singleton2::s_instance = nullptr;
std::mutex Singleton2::singleton_mutex;


Singleton2* Singleton2::get_instance()
{
	std::lock_guard<std::mutex> guard(singleton_mutex);
	if (s_instance == nullptr)
	{
		s_instance = new Singleton2();
		std::cerr << "Create Dynamic Memory for Singleton2" << std::endl;
	}

	return s_instance;
}

void Singleton2::destroy_instance()
{
	std::lock_guard<std::mutex> guard(singleton_mutex);
	if (s_instance != nullptr)
	{
		delete s_instance;
	}
}

void Singleton2::do_something()
{
	std::cerr << "Class name: " << static_cast<std::string> (typeid(this).name()) << std::endl;
}
//end Singleton2


//Singleton3 - lazy initialization, thread safe with Double-Checked Locking Pattern:
Singleton3* Singleton3::s_instance = nullptr;
std::mutex Singleton3::singleton_mutex;

Singleton3* Singleton3::get_instance()
{
	if (s_instance == nullptr)
	{
		std::lock_guard<std::mutex> guard(singleton_mutex);
		if (s_instance == nullptr)
		{
			s_instance = new Singleton3();
			std::cerr << "Create Dynamic Memory for Singleton3" << std::endl;
		}
	}
	return s_instance;
}

void Singleton3::destroy_instance()
{
	if (s_instance != nullptr)
	{
		std::lock_guard<std::mutex> guard(singleton_mutex);
		if (s_instance == nullptr)
		{
			delete s_instance;
		}
	}
}

void Singleton3::do_something()
{
	std::cerr << "Class name: " << static_cast<std::string> (typeid(this).name()) << std::endl;
}
//end Singleton3


//Singleton4 - lazy initialization, thread safe with once flag:
Singleton4* Singleton4::s_instance = nullptr;
std::once_flag Singleton4::onceFlag;

void Singleton4::initSingleton()
{
	std::cerr << "Create Dynamic Memory for Singleton4" << std::endl;
	s_instance = new Singleton4();
}

Singleton4* Singleton4::get_instance()
{
	// you can create just one time the singleton
	std::call_once(onceFlag, initSingleton);
	return s_instance;
}

void Singleton4::delSingleton()
{
	delete s_instance;
} 

void Singleton4::destroy_instance()
{
	if (s_instance != nullptr)
	{
		std::call_once(onceFlag, delSingleton);
	}
}

void Singleton4::do_something()
{
	std::cerr << "Class name: " << static_cast<std::string> (typeid(this).name()) << std::endl;
}