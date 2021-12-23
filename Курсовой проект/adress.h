#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class Adress {

	int house;
	string street;

public:

	Adress();
	Adress(string str, int hs);
	Adress(const Adress& D);

	string GetStreet();
	int GetHouse();

	void SetStreet(string s);
	void SetHouse(int h);

	friend ostream& operator<<(ostream& os, const Adress& D);
	friend istream& operator>>(istream& is, Adress& D);

	bool operator==(Adress);
};

int InputInt();
Adress InputAdr();
