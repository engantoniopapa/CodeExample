#include "stdafx.h"
#include <iostream>
#include "Operation2.h"

IntOperation* Operation2::create(int id)
{
	std::cout << "Create Op2 - id: " << id << std::endl;
	return (new Operation2(id));
}
