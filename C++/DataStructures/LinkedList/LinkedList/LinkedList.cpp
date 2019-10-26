#include "pch.h"
#include <iostream>
#include <map>

template <class T>
class DNode
{
public:
	DNode<T>() = default;
	DNode<T>(T& data, DNode<T> *prev = nullptr, DNode<T> *next = nullptr)
		: m_data(data), m_pPrev(prev), m_pNext(next) {};
	virtual ~DNode<T>() {};

	bool operator==(const T data)
	{
		return (data == m_data);
	}
	bool operator==(const DNode<T>& node)
	{
		return (node.m_data == m_data);
	}

	DNode<T> *m_pPrev = nullptr;
	DNode<T> *m_pNext = nullptr;
	T m_data;
};

template<class T>
std::ostream& operator<<(std::ostream& os, DNode<T>& node)
{
	os << "[ " << node.m_data << " ]";
	return os;
}

template<class T>
class DLinkedList 
{
public:
	void appendToTail(T data);
	bool removeElement(T data);
	DNode<T>* removeNode(DNode<T>* pNode);
	void removeDuplicate();

	template<class T>
	friend std::ostream& operator<<(std::ostream& ios, DLinkedList<T>& list);

private:
	DNode<T>* m_pHeadNode = nullptr;
};

template<class T>
void DLinkedList<T>::appendToTail(T data)
{
	if (m_pHeadNode == nullptr)
	{
		m_pHeadNode = new DNode<T>(data);
		return;
	}

	DNode<T>* iter_node = m_pHeadNode;
	while (iter_node->m_pNext != nullptr)
	{
		iter_node = iter_node->m_pNext;
	}
	iter_node->m_pNext = new DNode<T>(data, iter_node);
}


//return the pointer to the next node
template<class T>
DNode<T>* DLinkedList<T>::removeNode(DNode<T>* pNode)
{
	if (pNode == nullptr)
	{
		return nullptr; 
	}

	DNode<T>* pNext = pNode->m_pNext;

	//prev
	if (pNode->m_pPrev != nullptr)
	{
		pNode->m_pPrev->m_pNext = pNext;
	}

	//next
	if (pNext != nullptr)
	{
		pNext->m_pPrev = pNode->m_pPrev;
	}
	delete pNode;
	pNode = nullptr;

	return pNext;
}

template<class T>
bool DLinkedList<T>::removeElement(T data)
{
	if (m_pHeadNode == nullptr)
	{
		return false;
	}

	DNode<T>* iter_node = m_pHeadNode;
	while (iter_node != nullptr)
	{
		if (*iter_node == data)
		{
			removeNode(iter_node);
			break;
		}
		iter_node = iter_node->m_pNext;
	}
	return false;
}

template<class T>
void DLinkedList<T>::removeDuplicate()
{
	if (m_pHeadNode == nullptr)
	{
		return ;
	}

	std::map<T, int> dMap;

	DNode<T>* iter_node = m_pHeadNode;
	while (iter_node != nullptr)
	{
		if (dMap.count(iter_node->m_data) > 0)
		{
			iter_node = removeNode(iter_node);
		}
		else
		{
			dMap.insert(std::make_pair(iter_node->m_data, 1));
			iter_node = iter_node->m_pNext;
		}
	}
}

template<class T>
std::ostream& operator<<(std::ostream& os, DLinkedList<T>& list)
{
	os << "{ ";
	DNode<T>* iter_node = list.m_pHeadNode;
	while (iter_node != nullptr)
	{
		os << *iter_node << " ";
		iter_node = iter_node->m_pNext;
	}
	os << " }";

	return os;
}

int main()
{
	DLinkedList<int> DllInt;
	DllInt.appendToTail(1);
	DllInt.appendToTail(3);
	DllInt.appendToTail(7);
	DllInt.appendToTail(1);
	DllInt.appendToTail(5);
	DllInt.appendToTail(2);
	DllInt.appendToTail(7);
	DllInt.appendToTail(1);
	DllInt.appendToTail(4);

	std::cout << "Doubly Linked List:" << std::endl;
    std::cout << DllInt << std::endl << std::endl;

	DllInt.removeElement(3);
	DllInt.removeElement(5);
	DllInt.removeElement(11);

	std::cout << "After Removing 3,5,11:" << std::endl;
	std::cout << DllInt << std::endl << std::endl;

	std::cout << "After Removing Duplicates:" << std::endl;
	DllInt.removeDuplicate();
	std::cout << DllInt << std::endl << std::endl;
	
	return 0;
}

