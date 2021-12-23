#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "adress.h"

Adress::Adress() {
	street = "---";
	house = 0;
}

Adress::Adress(string str, int hs)
{
	street = str;
	house = hs;
}

Adress::Adress(const Adress& a)
{
	street = a.street;
	house = a.house;
}

string Adress::GetStreet()
{
	return street;
}

int Adress::GetHouse()
{
	return house;
}

void Adress::SetStreet(string s)
{
	street = s;
}

void Adress::SetHouse(int h)
{
	house = h;
}

ostream& operator<<(ostream& os, const Adress& D)
{
	os << D.street << "  " << D.house;
	return os;
}

istream& operator>>(istream& is, Adress& D)
{
	is >> D.street >> D.house;
	return is;
}

bool Adress::operator==(Adress a)
{
	return street == a.street && house == a.house;
}

Adress InputAdr()
{
	Adress a;
	cout << "Введите улицу" << endl;
	string str;
	cin >> str;
	a.SetStreet(str);
	int house = -1;
	cout << "Введите номер дома" << endl;
	while (house <= 0)
	{
		house = InputInt();
		if (house <= 0)
		{
			cout << "Номер дома должен быть больше 0" << endl;
		}
	}
	a.SetHouse(house);
	return a;
}