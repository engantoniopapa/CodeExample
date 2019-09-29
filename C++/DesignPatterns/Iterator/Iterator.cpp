#include "pch.h"
#include <iostream>
#include <string>

template<class T>
class Container
{
public:
	Container(int capacity = 10) : m_capacity(capacity), m_size(0)
	{
		m_items = new T[m_capacity];
	}

	~Container()
	{
		delete[] m_items;
	}

	Container(const Container<T>& obj) : m_capacity(obj.m_capacity), m_size(obj.m_size)
	{
		m_items = new T[m_capacity];
		for (int i = 0; i < m_size; ++i)
		{
			m_items[i] = obj.m_items[i];
		}
	}

	template<class T>
	friend class ContainerIter;
	T pop()
	{
		if (m_size > 0)
		{
			return m_items[m_size--];
		}
		return T{};
	}

	bool push(T item)
	{
		if (m_size < m_capacity)
		{
			m_items[m_size++] = item;
			return true;
		}
		return false;
	}

	bool isEmpty()
	{
		return (m_size == 0);
	}

	bool isFull()
	{
		return (m_size == m_capacity);
	}

private:
	T* m_items;
	int m_capacity;
	int m_size;
};

template<class T>
class ContainerIter
{
public:
	ContainerIter(Container<T>& container) : m_container(container), m_index(0) { ; }

	void operator++()
	{
		++m_index;
	}

	T operator*()
	{
		if (m_index < m_container.m_size)
		{
			return m_container.m_items[m_index];
		}
		return T{};
	}

	bool end()
	{
		return m_index == m_container.m_size;
	}

private:
	const Container<T>& m_container;
	int m_index;
};

template<class T>
bool operator==(Container<T>& c1, Container<T>& c2)
{
	ContainerIter<T> itr1(c1), itr2(c2);
	
	for (; !itr1.end(); ++itr1, ++itr2)
	{
		if (*itr1 != *itr2)
			return false;
	}

	return itr2.end();
}

int main()
{
	Container<std::string> c1;
	c1.push("Hello ");
	c1.push("how ");
	c1.push("are ");
	c1.push("you? ");

	Container<std::string> c2(c1), c3(c1), c4(c1), c5(c1);
	c3.pop();
	c5.pop();
	c4.push("Fine ");
	c5.push("No bad ");

	std::cout << "c1 == c2 is " << (c1 == c2) << std::endl;
	std::cout << "c1 == c3 is " << (c1 == c3) << std::endl;
	std::cout << "c1 == c4 is " << (c1 == c4) << std::endl;
	std::cout << "c1 == c5 is " << (c1 == c5) << std::endl;
}

