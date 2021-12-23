#pragma once
#include "person.h"

class Employee : public Person
{
protected:
	Adress adress;
	string name;

public:
	Employee();
	Employee(Employee& obj);

	string GetName();
	void SetName(string);

	Adress GetAdress();
	void SetAdress(Adress);

	void AddRecord();
	void ShowRecords();
	void DeleteRecord();
	void EditRecord();
	void SearchRecord();
	void SortRecord();
	void FilterRecord();
	void EditAccount();

	void ShowHistory();

	static int ReadFromFile(Employee*&);
	static void WriteToFile(Employee*&, int);

	static void ShowPersons();
	static void ShowPersons(Employee*, int);


	friend ostream& operator<<(ostream& o, Employee obj);
	friend istream& operator>>(istream& i, Employee& obj);
};
