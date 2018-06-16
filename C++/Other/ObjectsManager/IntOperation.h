#pragma once

class IntOperation
{
public:
	IntOperation(int id) : id(id) {};
	virtual ~IntOperation() {};
	virtual int getId() { return id; };
private:
	int id;
};