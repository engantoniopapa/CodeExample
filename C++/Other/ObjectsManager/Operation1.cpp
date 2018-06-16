#include "stdafx.h"
#include <iostream>
#include "Operation1.h"

IntOperation* Operation1::create(int id)
{
	std::cout << "Create Op1 - id: " << id << std::endl;
	return (new Operation1(id));
}

