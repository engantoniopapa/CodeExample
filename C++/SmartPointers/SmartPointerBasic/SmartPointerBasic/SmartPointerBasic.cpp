// SmartPointerBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

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
	std::cout << "My namne is: " << m_name << " " << m_surname << " - " << postFix << std::endl;
}

void TestU_c(std::unique_ptr<Employee> p)
{
	p->print("TestU_c");
	std::cout << std::endl;
	return;
}
void TestU_r(std::unique_ptr<Employee>& p)
{
	p->print("TestU_r");
	std::cout << std::endl;
	return;
}

void TestS_c(std::shared_ptr<Employee> p)
{
	p->print("TestS_c");
	std::cout << "use_counter = " << p.use_count() << std::endl << std::endl;
	return;
}

void TestS_r(std::shared_ptr<Employee>& p)
{
	p->print("TestS_r");
	std::cout << "use_counter = " << p.use_count() << std::endl << std::endl;
	return;
}

int main()
{
	Employee* asuka = new Employee("Asuka", "Langley");
	std::unique_ptr<Employee> rei_11u(new Employee("Rei_11u", "Ayanami"));
	auto rei_14u = std::make_unique<Employee>("Rei_14u", "Ayanami"); //C++14

	std::shared_ptr<Employee> rei_11s(new Employee("Rei_11s", "Ayanami"));
	auto rei_14s = std::make_shared<Employee>("Rei_14s", "Ayanami"); //C++14

	std::cout << "****** C++11 ****** " << std::endl;
	//the reference will not change the pointer owner
	TestU_r(rei_11u);
	TestS_r(rei_11s);

	//TestU_1(rei_11u); error we cannot copy the unique_ptr	
	TestS_c(rei_11s);

	std::cout << "---- using std::move ----" << std::endl;
	TestU_c(std::move(rei_11u)); // the pointer will be move so the owner, any other access to this pointer after this line will lead to an error  
	TestS_c(std::move(rei_11s)); // the pointer will be move so the owner, any other access to this pointer after this line will lead to an error  
	std::cout << "****************** " << std::endl << std::endl;

	std::cout << "****** C++14 ****** " << std::endl;
	//the reference will not change the pointer owner
	TestU_r(rei_14u);
	TestS_r(rei_14s);

	//TestU_1(rei_14u); error we cannot copy the unique_ptr	
	TestS_c(rei_14s);

	std::cout << "---- using std::move ----" << std::endl;
	TestU_c(std::move(rei_14u)); // the pointer will be move so the owner, any other access to this pointer after this line will lead to an error  
	TestS_c(std::move(rei_14s)); // the pointer will be move so the owner, any other access to this pointer after this line will lead to an error  
	std::cout << "****************** " << std::endl << std::endl;

	std::getchar();
	return 0;
}