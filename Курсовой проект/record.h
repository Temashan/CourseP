#pragma once
#include "person.h"
#include "date.h"
#include "fio.h"
#include "adress.h"

class Record
{
	int number;
	string type;
	Date start;
	Date end;

	FIO client;

	string hotel;
	Adress adress;

public:
	Record();
	Record(const Record&);
	Record(FIO, Date&, Date&, int, string, Adress);

	FIO GetClient();
	void SetClient(FIO);

	Date GetStart();
	void SetStart(Date);

	Date GetEnd();
	void SetEnd(Date);

	string GetHotel();
	void SetHotel(string);

	string GetType();
	void SetType(string);

	Adress GetAdr();
	void SetAdr(Adress);

	int GetNumb();
	void SetNumb(int);

	static int ReadFromFile(Record*&);
	static void WriteToFile(Record*, int);

	static void ShowRecords(Record*, int);

	friend istream& operator>>(istream&, Record&);
	friend ostream& operator<<(ostream&, Record&);
};