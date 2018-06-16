#pragma once

#include <mutex>
#include <map>

class IntOperation;

class ObjectsManager
{
private:
	static ObjectsManager* s_instance;
	static std::mutex singleton_mutex;
	ObjectsManager() { m_listObject.clear();};

public:
	static ObjectsManager* get_instance();
	static void destroy_instance();
	~ObjectsManager() {};
	ObjectsManager(const ObjectsManager&) = delete;
	ObjectsManager operator=(const ObjectsManager&) = delete;

public:
	void setUp();
	IntOperation * getObject(int id);
	bool isObject(int id);

private:
	class EntryObject
	{
	public:
		IntOperation * ptr;
	};

	std::map<int, EntryObject>  m_listObject;
};
