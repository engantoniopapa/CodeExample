#pragma once

#include "IntOperation.h"

class Operation2 : public IntOperation
{
public:
	Operation2(int id) : IntOperation(id) {};
	static IntOperation* create(int id);

private:
	int id;
};

