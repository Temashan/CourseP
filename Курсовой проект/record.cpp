#pragma once
#include "record.h"

Record::Record()
{
	hotel = "---";
	number = 0;
}

Record::Record(const Record& o)
{
	start = o.start;
	end = o.end;
	hotel = o.hotel;
	adress = o.adress;
	number = o.number;
	client = o.client;
}

Record::Record(FIO _fio, Date& _start, Date& _end, int _numb, string _nameApt, Adress _adr)
{
	start = _start;
	number = _numb;
	end = _end;
	hotel = _nameApt;
	adress = _adr;
	client = _fio;
}

Date Record::GetStart()
{
	return start;
}

void Record::SetStart(Date d)
{
	start = d;
}

Date Record::GetEnd()
{
	return end;
}

void Record::SetEnd(Date d)
{
	end = d;
}

string Record::GetHotel()
{
	return hotel;
}

void Record::SetHotel(string a)
{
	hotel = a;
}

string Record::GetType()
{
	return type;
}

void Record::SetType(string a)
{
	type = a;
}

FIO Record::GetClient()
{
	return client;
}

void Record::SetClient(FIO n)
{
	client = n;
}

Adress Record::GetAdr()
{
	return adress;
}

void Record::SetAdr(Adress a)
{
	adress = a;
}

int Record::GetNumb()
{
	return number;
}

void Record::SetNumb(int c)
{
	number = c;
}

int Record::ReadFromFile(Record*& arr)
{
	if (arr != NULL)
	{
		delete[] arr;
	}
	int n = 0;
	ifstream f;
	f.open("record.txt", ios_base::in);
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("record.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	arr = new Record[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	f.close();
	WriteToFile(arr, n);
	return n;
}

void Record::WriteToFile(Record* arr, int n)
{
	ofstream fout;
	fout.open("record.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr[i] << endl;
	}
	fout.close();
}

void Record::ShowRecords(Record* arr, int n)
{
	if (n)
	{
		cout << "*********************************************************************************************************************" << endl;
		cout << "| № |Название гостиницы| Номер |  Тип номера  |   ФИО клиента   |   Адрес гостиницы   |Дата заселения|Дата выселения|" << endl;
		cout << "*********************************************************************************************************************" << endl;
		for (int i = 0; i < n; i++)
		{
			printf("|%3d|%14s|%7d|%14s|%12s %c.%c.|ул.%13s %4d|  %02d.%02d.%04d  | %02d.%02d.%04d |\n", i + 1, arr[i].hotel.c_str(), arr[i].number, arr[i].type.c_str(), arr[i].client.F.c_str(), arr[i].client.I[0], arr[i].client.O[0], arr[i].adress.GetStreet().c_str(), arr[i].adress.GetHouse(), arr[i].start.GetDay(), arr[i].start.GetMonth(), arr[i].start.GetYear(), arr[i].end.GetDay(), arr[i].end.GetMonth(), arr[i].end.GetYear());
			cout << "*********************************************************************************************************************" << endl;
		}
	}
	else
	{
		cout << "Записей нет" << endl;
	}
}

istream& operator>>(istream& i, Record& a)
{
	i >> a.client >> a.type;
	getline(i, a.hotel);
	getline(i, a.hotel);
	i >> a.adress >> a.number >> a.start >> a.end;
	return i;
}

ostream& operator<<(ostream& o, Record& a)
{
	o << a.client << " " << a.type << "\n" << a.hotel << "\n" << a.adress << " " << a.number << " " << a.start << " " << a.end;
	return o;
}