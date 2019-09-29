#include "pch.h"
#include <iostream>
#include <string>

template<class K, class V>
class HashNode
{
private:
	K m_key;
	V m_value;
	HashNode<K, V>* m_nextNode;
	HashNode<K, V>* m_prevNode;

public:
	HashNode(K key, V val, HashNode<K, V>* prevNode) :m_key(key), m_value(val), m_prevNode(prevNode), m_nextNode(nullptr) {};
	HashNode(K key, V val) :m_key(key), m_value(val), m_prevNode(nullptr), m_nextNode(nullptr) {};
	HashNode() :m_key(0), m_value(0), m_prevNode(nullptr), m_nextNode(nullptr) {};

	K getKey() { return m_key; }
	V getValue() { return m_value; }
	void setKey(K& key) { m_key = key; }
	void setValue(V& val) { m_value = val; }

	HashNode<K, V>* getNextNode() { return m_nextNode; }
	void SetNextNode(HashNode<K, V>* nextNode) { m_nextNode = nextNode; }

	HashNode<K, V>* getPrevNode() { return m_prevNode; }
	void SetPrevNode(HashNode<K, V>* prevNode) { m_prevNode = prevNode; }
};

template<class K, class V>
class HashTable
{
private:
	HashNode<K, V> **m_table;
	int m_capacity = 200; //HasTable size

public:
	HashTable(int capacity = 100)
		:m_capacity(capacity)
	{
		m_table = new HashNode<K, V>*[m_capacity];
		for (int i = 0; i < m_capacity; i++)
		{
			m_table[i] = nullptr;
		}
	}

	~HashTable()
	{
		for (int i = 0; i < m_capacity; i++)
		{
			HashNode<K, V>* node = m_table[i];

			while (node != nullptr)
			{
				HashNode<K, V>* next = node->getNextNode();
				delete node;
				node = next;
			}
		}
		delete[] m_table;
	}

	K hashFunc(const K& key) { return key % m_capacity; }

	int insert(const K& key, const V& val)
	{
		K index = hashFunc(key);

		if (m_table[index] == nullptr)
		{
			m_table[index] = new HashNode<K, V>(key, val);
		}
		else
		{
			HashNode<K, V>* node = m_table[index];
			HashNode<K, V>* prev = nullptr;

			while (node != nullptr)
			{
				prev = node;
				node = node->getNextNode();
			}
			node = new HashNode<K, V>(key, val, prev);
			prev->SetNextNode(node);
		}
		return index;
	}

	bool remove(const K& key, const V& val)
	{
		K index = hashFunc(key);

		if (m_table[index] == nullptr)
		{
			return false;
		}
		else
		{
			HashNode<K, V>* node = m_table[index];
			HashNode<K, V>* prev = nullptr;

			while (node != nullptr)
			{
				if (node->getValue() == val)
				{
					if (prev != nullptr)
					{
						prev->SetNextNode(node->getNextNode());
					}

					if (node->getNextNode() != nullptr)
					{
						HashNode<K, V>* next = node->getNextNode();
						next->SetPrevNode(prev);
					}

					if (node == m_table[index])
					{
						m_table[index] = nullptr;
					}

					delete node;
					return true;
				}
				prev = node;
				node = node->getNextNode();
			}
		}
		return false;
	}

	HashNode<K, V>* get(const K& key, const V& val)
	{
		K index = hashFunc(key);

		if (m_table[index] == nullptr)
		{
			return nullptr;
		}
		else
		{
			HashNode<K, V>* node = m_table[index];

			while (node != nullptr)
			{
				if (node->getValue() == val)
				{
					return node;
				}
				node = node->getNextNode();
			}
		}
		return nullptr;
	}

	void print()
	{
		for (int i = 0; i < m_capacity; i++)
		{
			HashNode<K, V>* node = m_table[i];

			if (node != nullptr)
			{
				std::cout << "[" << node->getKey() << "]: " << node->getValue();
				node = node->getNextNode();
			}
			while (node != nullptr)
			{
				std::cout << ", " << node->getValue();
				node = node->getNextNode();
			}
			if (m_table[i] != nullptr)
			{
				std::cout << std::endl;
			}
		}
	}

};

int main()
{
	HashTable<int, std::string> HTable;
	HTable.insert(1, "Good ");
	HTable.insert(1, "Morning");
	HTable.insert(2, "How are");
	HTable.insert(2, "you?");
	HTable.insert(5, "Fine");

	HTable.print();

	HTable.remove(5, "Fine");
	HTable.insert(5, "So");

	HashNode<int, std::string>* node = HTable.get(5, "So");
	HTable.insert(node->getKey(), node->getValue());
	HTable.print();

	getchar();
}
