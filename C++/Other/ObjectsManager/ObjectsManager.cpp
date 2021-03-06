// ObjectsManager.cpp
//

#include "stdafx.h"
#include <iostream>
#include "ObjectsManager.h"
#include "Operation1.h"
#include "Operation2.h"

ObjectsManager* ObjectsManager::s_instance = nullptr;
std::mutex ObjectsManager::singleton_mutex;

void ObjectsManager::setUp()
{
	m_listObject =
	{
		{ 1,{ Operation1::create(10) } },
		{ 2,{ Operation2::create(20) } },
		{ 13,{ Operation1::create(130) } },
		{ 14,{ Operation2::create(140) } }
	};
}
ObjectsManager* ObjectsManager::get_instance()
{
	if (s_instance == nullptr)
	{
		std::lock_guard<std::mutex> guard(singleton_mutex);
		if (s_instance == nullptr)
		{
			s_instance = new ObjectsManager();
			std::cout << "Created ObjectsManager" << std::endl;
		}
	}
	return s_instance;
}

void ObjectsManager::destroy_instance()
{
	if (s_instance != nullptr)
	{
		delete s_instance;
		std::cout << "Deleted ObjectsManager" << std::endl;
	}
}

IntOperation* ObjectsManager::getObject(int id)
{
	std::map<int, EntryObject>::const_iterator it = m_listObject.find(id);
	if (it != m_listObject.end())
	{
		return (it->second).ptr;
	}
	return nullptr;
}

bool ObjectsManager::isObject(int id)
{
	std::map<int, EntryObject>::const_iterator it = m_listObject.find(id);

	return it != m_listObject.end();
}
