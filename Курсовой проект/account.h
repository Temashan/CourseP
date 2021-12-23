#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class Account
{
protected:
	string login;
	string password;
public:

	string GetLogin();
	string GetPass();

	void SetLogin(string _login);
	void SetPass(string _password);
};

string Encrypt(string);
string Decrypt(string);

int InputInt();
double InputDouble();


