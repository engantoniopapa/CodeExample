#include "stdafx.h"
#include <iostream>
#include "ObjectsManager.h"
#include "IntOperation.h"

int main()
{
	ObjectsManager *objManager = ObjectsManager::get_instance();
	objManager->setUp();

	if (objManager->isObject(1))
	{
		IntOperation* p_operation = objManager->getObject(1);
		std::cout << "The object with id = 1 has this internal id = " << p_operation->getId() << std::endl;
	}

	ObjectsManager::destroy_instance();

	system("Pause");

	return 0;
}