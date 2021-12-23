#pragma once
#include "admin.h"
#include "employee.h"
#include "record.h"

string Admin::defaultLogin = "111";
string Admin::defaultPassword = "111";

bool Admin::LoadFromFile()
{
	ifstream fin("admin.txt", ios_base::in);
	if (fin.is_open())
	{
		fin >> login >> password;
		fin.close();
		return true;
	}
	else
	{
		return false;
	}
}

void Admin::SaveToFile()
{
	ofstream fout("admin.txt", ios_base::trunc);
	if (fout.is_open())
	{
		fout << login << " " << password;
		fout.close();
	}
}

Admin::Admin()
{
	login = defaultLogin;
	password = Encrypt(defaultPassword);
}

void Admin::Init()
{
	cout << "¬ведите логин\n";
	cin >> login;
	cout << "¬ведите пароль\n";
	cin >> password;
	password = Encrypt(password);
	SaveToFile();
}
