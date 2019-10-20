#include "pch.h"
#include <iostream>
#include <initializer_list>
#include <vector>

template <class T>
class ListItems
{
private:
	std::vector<T> m_ListItems;

public:
	ListItems(std::initializer_list<T> args);

	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const ListItems<T> &data); //works with: cout << data1 << data2
};

template <class T>
struct SimpleStruct
{
	T x;
	T y;
};

template <class T>
ListItems<T>::ListItems(std::initializer_list<T> args) : m_ListItems(args.begin(), args.end())
{
	//different way to inizialize via initializer_list:
	//m_ListItems.insert(cend(m_ListItems), cbegin(args), cend(args));
}

//works with: cout << data1 << data2
template <class T>
std::ostream& operator<<(std::ostream& os, const SimpleStruct<T> &data)
{
	os << data.x << ", " << data.y;
	return os;
}

// C++ template to print vector container elements 
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	os << "(";
	for (unsigned int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << ", ";
	}
	os << ")";
	return os;
}

//works with: cout << data1 << data2
template <class T>
std::ostream& operator<<(std::ostream& os, const ListItems<T> &data)
{
	os << "List Items: [";

	for (auto item : data.m_ListItems)
	{
		os << " |" << item << "| ";
	}
	os << "]";
	return os;
}



int main()
{

	ListItems<int> l1 = { 1,2,3 };
	std::cout << "int Type => " << l1 << std::endl;
	
	ListItems<double> l2({ 1.1,2.2,3.3 });
	std::cout <<"double Type => " << l2 << std::endl;

	SimpleStruct<int> s1 = { 4,5 };
	ListItems<SimpleStruct<int>> l3({ s1, s1 });
	std::cout << "SimpleStruct<int> Type => " << l3 << std::endl;

	std::vector<double> v1 = { 5.5,6.6,7.7 };
	ListItems<std::vector<double>> l4({v1, v1});
	std::cout << "std::vector<double> Type => " << l4 << std::endl;

	//Error
	//double a1[3] = { 5.5,6.6,7.7 };
	//ListItems<double [3]> l5({ a1, a1 });
	//std::cout << l5 << std::endl;

	return 0;
}

