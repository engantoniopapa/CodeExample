// SmartPointerBasic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <memory>
#include <iostream>

class Employee
{
public:
	Employee(std::string name = "John", std::string surname = "Doe");
	void print(std::string postFix);

private:
	std::string m_name;
	std::string  m_surname;
};

Employee::Employee(std::string name, std::string surname)
{
	m_name = std::move(name);
	m_surname = std::move(surname);
}

void Employee::print(std::string postFix)
{
	std::cout << "My namne is: " << m_name << " " << m_surname << " - " <<postFix <<std::endl;
}

void TestU_c(std::unique_ptr<Employee> p)
{
	p->print("TestU_1");
	return;
}
void TestU_r(std::unique_ptr<Employee>& p)
{
	p->print("TestU_2");
	return;
}

void TestS_c(std::shared_ptr<Employee> p)
{
	p->print("TestS_1");
	return;
}

void TestS_r(std::shared_ptr<Employee>& p)
{
	p->print("TestS_2");
	return;
}

int main()
{
	Employee* asuka = new Employee("Asuka", "Langley");
	std::unique_ptr<Employee> rei_11u(new Employee("Rei_11u", "Ayanami"));
	auto rei_14u = std::make_unique<Employee>("Rei_14u", "Ayanami"); //C++14

	std::shared_ptr<Employee> rei_11s(new Employee("Rei_11s", "Ayanami"));
	auto rei_14s = std::make_shared<Employee>("Rei_14s", "Ayanami"); //C++14

	//the reference will not change the pointer owner
	TestU_r(rei_11u);
	TestS_r(rei_11s);

	//TestU_1(rei_11u); error we cannot copy the unique_ptr	
	TestU_c(std::move(rei_11u)); // the pointer will be move so the owner, any other access to this pointer after this line will lead to an error  
	TestS_c(rei_11s);

	std::getchar();
    return 0;
}

