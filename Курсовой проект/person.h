#pragma once
#include "account.h"
#include "record.h"
#include "fio.h"
#include "adress.h"
#include "date.h"

class Person : public Account
{
protected:
	FIO fio;
public:
	Person();
	Person(Person& o);
	void ShowRecords();
	virtual void SearchRecord();
	virtual void SortRecord();
	virtual void FilterRecord();
	virtual void EditAccount();

	static int ReadFromFile(Person*&);
	static void WriteToFile(Person*&, int);

	static void ShowPersons();
	static void ShowPersons(Person*, int);

	friend ostream& operator<<(ostream& o, Person obj);
	friend istream& operator>>(istream& i, Person& obj);

	void SetFIO(FIO f);
	FIO GetFIO();
};
