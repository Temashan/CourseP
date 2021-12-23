#pragma once
#include "account.h"
using namespace std;
class Admin : public Account
{
	static string defaultLogin;
	static string defaultPassword;
public:
	Admin();
	void Init();
	bool LoadFromFile();
	void SaveToFile();
};