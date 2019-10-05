#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int _sizeText = 80;
const char* FILENAME = ".\\file.txt";
const int _sizeListUnit = 10;

class Unit
{
public:
	Unit() :ID(++_Id)
	{ 
		memset(text, 0, _sizeText);
	}

	Unit(const char* source) :Unit()
	{
		setText(source);
	}

	void setText(const char* source)
	{
		strncpy_s(text, source, _sizeText);
	}

private:
	int ID;
	char text[_sizeText];
	static int _Id;
};

int Unit::_Id = 0;

int main()
{
	std::ofstream outfile;
	std::ifstream infile;

	//Save unit
	Unit* unit1 = new Unit("Single Test");
	outfile.open(FILENAME, std::ofstream::trunc);
	outfile.write((char*)unit1, sizeof(Unit));
	outfile.close();

	std::cout << "Single Unit saved in: " << FILENAME << " - Press a key to continue" << std::endl;
	getchar();

	//Load unit
	Unit* unit2 = new Unit();
	infile.open(FILENAME);
	infile.read((char*)unit2, sizeof(Unit));
	infile.close();

	std::cout << "Single Unit load from: " << FILENAME << " - Press a key to continue" << std::endl;
	getchar();

	//Save Unit array
	Unit* units1 = new Unit[_sizeListUnit];

	for (int i = 0; i < _sizeListUnit; i++)
	{
		std::string temp_str = "Single Test" + std::to_string(i);
		units1[i].setText(temp_str.c_str());
	}

	outfile.open(FILENAME, std::ofstream::trunc);
	outfile.write((char*)units1, sizeof(Unit) * _sizeListUnit);
	outfile.close();

	std::cout << "Array Units saved in: " << FILENAME << " - Press a key to continue" << std::endl;
	getchar();

	//Load Unit array
	Unit* units2 = new Unit[_sizeListUnit];

	infile.open(FILENAME);
	infile.read((char*)units2, sizeof(Unit) * _sizeListUnit);
	infile.close();

	std::cout << "Array Units loaded from: " << FILENAME << " - Press a key to exit" << std::endl;
	getchar();

	return 0;
}

