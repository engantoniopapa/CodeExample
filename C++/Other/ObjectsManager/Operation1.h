#pragma once

#include "IntOperation.h"

class Operation1 : public IntOperation
{
public:
	Operation1(int id) : IntOperation(id) {};
	static IntOperation* create(int id);

private:
	int id;
};

