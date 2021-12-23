#pragma once
#include "employee.h"


Employee::Employee() :Person()
{
	name = "---";
}

Employee::Employee(Employee& obj) : Person((Person&)obj)
{
	adress = obj.adress;
	name = obj.name;
}

void Employee::AddRecord()
{
	system("cls");

	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!arrRec)
	{
		arrRec = new Record[2];
	}

	Person* arr = NULL;
	int nPer = Person::ReadFromFile(arr);
	if (!nPer)
	{
		cout << "��� �� ������ �������" << endl;
		delete[] arrRec;
		delete[] arr;
		system("pause");
		return;
	}
	Person::ShowPersons();
	int n = 0;
	cout << "�������� �������" << endl;
	while (n <= 0 || n > nPer)
	{
		n = InputInt();
	}
	arrRec[nRec].SetClient(arr[n - 1].GetFIO());

	arrRec[nRec].SetHotel(name);
	arrRec[nRec].SetAdr(adress);

	int numb = -1;
	cout << "������� �����" << endl;
	while (numb <= 0)
	{
		numb = InputInt();
		if (numb <= 0)
		{
			cout << "����� ������ ���� ������ 0" << endl;
		}
	}
	arrRec[nRec].SetNumb(numb);

	cout << "������� ���� ���������" << endl;
	Date date;
	date = InputDate();
	arrRec[nRec].SetStart(date);

	Date date1;

	cout << "������� ���� ���������" << endl;
	do{
		date1 = InputDate();
		if ((date1 < date))
		{
			cout << "���� ��������� ������ ���� ����� ���� ���������" << endl;
		}
	} while ((date1 < date));
	arrRec[nRec].SetEnd(date1);

	cout << "������� ��� ������\n1.��������(35�./����)\n2.����(60�./����)\n3.�������������(100�./����)" << endl;
	int cost = 0;
	switch (InputInt())
	{
	case 1:
	{
		arrRec[nRec].SetType("��������");
		cost = 35;
		break;
	}
	case 2:
	{
		arrRec[nRec].SetType("����");
		cost = 60;
		break;
	}
	case 3:
	{
		arrRec[nRec].SetType("�������������");
		cost = 100;
		break;
	}
	}
	Date s = arrRec[nRec].GetStart();
	Date e = arrRec[nRec].GetEnd();
	int days = (e.GetYear() - s.GetYear()) * 365 + (e.GetMonth() - s.GetMonth()) * 30 + (e.GetDay() - s.GetDay());
	int sum = days * cost;
	system("cls");
	cout << "����� ������� ���������, � ������ " << sum << " ���." << endl;
	system("pause");
	nRec++;

	Record::WriteToFile(arrRec, nRec);
	delete[] arrRec;
}

void Employee::ShowRecords()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!nRec)
	{
		cout << "������� �� �������\n";
		system("pause");
		return;
	}

	Record* arr = new Record[nRec];
	int nRecInd = 0;
	for (int i = 0; i < nRec; i++)
	{
		if (adress == arrRec[i].GetAdr())
		{
			arr[nRecInd] = arrRec[i];
			nRecInd++;
		}
	}
	if (!nRecInd)
	{
		cout << "������� �� �������\n";
		system("pause");
		delete[] arrRec;
		delete[] arr;
		return;
	}

	Record::ShowRecords(arr, nRecInd);
	delete[] arrRec;
	delete[] arr;
	return;
}

void Employee::DeleteRecord()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	Record* arrDel = NULL;
	int nDel = 0;
	ifstream f;
	f.open(this->login + "record.txt", ios_base::in);
	f >> nDel;
	if (nDel == 0)
	{
		f.close();
		ofstream fout;
		fout.open(this->login + "record.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
	}
	arrDel = new Record[nDel + 1];
	for (int i = 0; i < nDel; i++)
	{
		f >> arrDel[i];
	}
	f.close();



	if (!nRec)
	{
		cout << "������� �� �������\n";
		system("pause");
		return;
	}

	Record* arrInd = new Record[nRec];
	int nRecInd = 0;

	Record* arrOther = new Record[nRec];
	int nRecOther = 0;

	for (int i = 0; i < nRec; i++)
	{
		if (adress == arrRec[i].GetAdr())
		{
			arrInd[nRecInd] = arrRec[i];
			nRecInd++;
		}
		else
		{
			arrOther[nRecOther] = arrRec[i];
			nRecOther++;
		}
	}
	if (!nRecInd)
	{
		cout << "������� �� �������\n";
		system("pause");
		delete[] arrRec;
		delete[] arrInd;
		delete[] arrOther;
		return;
	}

	Record::ShowRecords(arrInd, nRecInd);

	int num = 0;
	cout << "������� ����� ������ ��� ��������" << endl;
	while (num<1 || num>nRecInd)
	{
		num = InputInt();
		if (num<1 || num>nRecInd)
		{
			cout << "������ �����" << endl;
		}
	}
	num--;
	arrDel[nDel] = arrInd[num];
	nDel++;
	for (int i = num; i < nRecInd - 1; i++)
	{
		arrInd[i] = arrInd[i + 1];
	}
	nRecInd--;

	int index = 0;
	for (int i = 0; i < nRecOther; i++)
	{
		arrRec[index] = arrOther[i];
		index++;
	}
	for (int i = 0; i < nRecInd; i++)
	{
		arrRec[index] = arrInd[i];
		index++;
	}
	Record::WriteToFile(arrRec, index);

	ofstream fout;
	fout.open(this->login + "record.txt", ios_base::trunc);
	fout << nDel << endl;
	for (int i = 0; i < nDel; i++)
	{
		fout << arrDel[i] << endl;
	}
	fout.close();

	delete[] arrRec;
	delete[] arrDel;
	delete[] arrInd;
	delete[] arrOther;
}

void Employee::ShowHistory()
{
	Record* arrDel = NULL;
	int nDel = 0;
	ifstream f;
	f.open(this->login + "record.txt", ios_base::in);
	f >> nDel;
	if (nDel == 0)
	{
		f.close();
		ofstream fout;
		fout.open(this->login + "record.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		cout << "������� ���" << endl;
		system("pause");
	}
	arrDel = new Record[nDel + 1];
	for (int i = 0; i < nDel; i++)
	{
		f >> arrDel[i];
	}
	f.close();

	Record::ShowRecords(arrDel, nDel);
	system("pause");
	delete[] arrDel;
}

void Employee::EditRecord()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!nRec)
	{
		cout << "������� �� �������\n";
		system("pause");
		return;
	}

	Record* arrInd = new Record[nRec];
	int nRecInd = 0;

	Record* arrOther = new Record[nRec];
	int nRecOther = 0;

	for (int i = 0; i < nRec; i++)
	{
		if (adress == arrRec[i].GetAdr())
		{
			arrInd[nRecInd] = arrRec[i];
			nRecInd++;
		}
		else
		{
			arrOther[nRecOther] = arrRec[i];
			nRecOther++;
		}
	}
	if (!nRecInd)
	{
		cout << "������� �� �������\n";
		system("pause");
		delete[] arrRec;
		delete[] arrInd;
		delete[] arrOther;
		return;
	}

	Record::ShowRecords(arrInd, nRecInd);

	int num = 0;
	cout << "������� ����� ������ ��� ��������������" << endl;
	while (num<1 || num>nRecInd)
	{
		num = InputInt();
		if (num<1 || num>nRecInd)
		{
			cout << "������ �����" << endl;
		}
	}
	num--;
	Record temp(arrInd[num]);
	bool work = true;
	while (work)
	{
		cout << "�������� ���� ��� ��������������" << endl;
		cout << "1.������" << endl;
		cout << "2.�����" << endl;
		cout << "3.���� ���������" << endl;
		cout << "4.���� ���������" << endl;
		cout << "5.�����" << endl;

		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			Person* arr = NULL;
			int nPer = Person::ReadFromFile(arr);
			if (!nPer)
			{
				cout << "��� �� ������ �������" << endl;
				delete[] arr;
				system("pause");
			}
			Person::ShowPersons();
			int n = 0;
			cout << "�������� �������" << endl;
			while (n <= 0 || n > nPer)
			{
				n = InputInt();
			}
			temp.SetClient(arr[n - 1].GetFIO());
			break;
		}
		case '2':
		{
			int numb = -1;
			cout << "������� �����" << endl;
			while (numb <= 0)
			{
				numb = InputInt();
				if (numb <= 0)
				{
					cout << "����� ������ ���� ������ 0" << endl;
				}
			}
			temp.SetNumb(num);
			break;
		}
		case '3':
		{
			Date date;
			while (!(date > temp.GetEnd()))
			{
				date = InputDate();
				if (!(date > temp.GetEnd()))
				{
					cout << "���� ��������� ������ ���� ������ ���� ���������" << endl;
				}
			}
			temp.SetStart(date);

			break;
		}
		case '4':
		{
			Date date;
			while (!(date < temp.GetStart()))
			{
				date = InputDate();
				if (!(date < temp.GetStart()))
				{
					cout << "���� ��������� ������ ���� ����� ���� ���������" << endl;
				}
			}
			temp.SetEnd(date);

			break;
		}
		case '5':
		{
			work = false;
			break;
		}
		default:
		{
			cout << "������. ��������� ����" << endl;
			system("pause");
		}
		}
	}
	arrInd[num] = temp;
	int index = 0;
	for (int i = 0; i < nRecOther; i++)
	{
		arrRec[index] = arrOther[i];
		index++;
	}
	for (int i = 0; i < nRecInd; i++)
	{
		arrRec[index] = arrInd[i];
		index++;
	}
	Record::WriteToFile(arrRec, nRec);

	delete[] arrRec;
	delete[] arrInd;
	delete[] arrOther;
}

void Employee::SearchRecord()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!nRec)
	{
		cout << "������� �� �������\n";
		system("pause");
		return;
	}
	bool work = true;
	while (work)
	{
		system("cls");
		Record* arr = new Record[nRec];
		int nRecFound = 0;
		cout << "�������� ���� ��� ������" << endl;
		cout << "1.��� �������" << endl;
		cout << "2.����� �������" << endl;
		cout << "3.�����" << endl;
		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			FIO f = InputFIO();
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetClient() == f && arrRec[i].GetAdr() == adress)
				{
					arr[nRecFound] = arrRec[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "������� �� �������" << endl;
				system("pause");
			}
			break;
		}
		case '2':
		{
			int f = 0;
			cout << "������� ����� �������" << endl;
			while (f <= 0)
			{
				f = InputInt();
				if (f <= 0)
				{
					cout << "����� ������ ���� ������ 0" << endl;
				}
			}
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetNumb() == f && arrRec[i].GetAdr() == adress)
				{
					arr[nRecFound] = arrRec[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "������� �� �������" << endl;
				system("pause");
			}
			break;
		}
		case '3':
		{
			work = false;
			break;
		}
		default:
			cout << "������. ��������� ����" << endl;
			system("pause");
			break;
		}
		system("cls");
		if (nRecFound > 0)
		{
			Record::ShowRecords(arr, nRecFound);
			system("pause");
		}
		delete[] arr;

	}
	delete[] arrRec;
	return;
}

void Employee::SortRecord()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!nRec)
	{
		cout << "������� �� �������\n";
		system("pause");
		return;
	}

	Record* arr = new Record[nRec];
	int nRecInd = 0;
	for (int i = 0; i < nRec; i++)
	{
		if (adress == arrRec[i].GetAdr())
		{
			arr[nRecInd] = arrRec[i];
			nRecInd++;
		}
	}
	if (!nRecInd)
	{
		cout << "������� �� �������\n";
		system("pause");
		delete[] arrRec;
		delete[] arr;
		return;
	}

	bool work = true;
	while (work)
	{
		cout << "�������� ���� ��� ����������" << endl;
		cout << "1.����� �������" << endl;
		cout << "2.���� ���������" << endl;
		cout << "3.���� ���������" << endl;
		cout << "4.�����" << endl;
		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			for (int i = 0; i < nRecInd; i++)
			{
				for (int j = i; j < nRecInd; j++)
				{
					if (arr[i].GetNumb() > arr[j].GetNumb())
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			Record::ShowRecords(arr, nRecInd);
			system("pause");
			break;
		}
		case '2':
		{
			for (int i = 0; i < nRecInd; i++)
			{
				for (int j = i; j < nRecInd; j++)
				{
					if (arr[i].GetStart() > arr[j].GetStart())
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			Record::ShowRecords(arr, nRecInd);
			system("pause");
			break;
		}
		case '3':
		{
			for (int i = 0; i < nRecInd; i++)
			{
				for (int j = i; j < nRecInd; j++)
				{
					if (arr[i].GetEnd() > arr[j].GetEnd())
					{
						swap(arr[i], arr[j]);
					}
				}
			}
			Record::ShowRecords(arr, nRecInd);
			system("pause");
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
		{
			cout << "������. ��������� ����" << endl;
			system("pause");
			break;
		}
		}
	}
	delete[] arrRec;
	delete[] arr;
	return;
}

void Employee::FilterRecord()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!nRec)
	{
		cout << "������� �� �������\n";
		system("pause");
		return;
	}

	bool work = true;
	while (work)
	{
		Record* arr = new Record[nRec];
		int nRecFound = 0;
		system("cls");
		cout << "�������� ���� ��� ����������" << endl;
		cout << "1.����� �������" << endl;
		cout << "2.���� ���������" << endl;
		cout << "3.���� ���������" << endl;
		cout << "4.�����" << endl;
		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			int a, b;
			cout << "������� �������� �������" << endl;
			cout << "��:" << endl;
			a = InputInt();
			cout << "��:" << endl;
			b = InputInt();
			if (a > b)swap(a, b);
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetNumb() >= a && arrRec[i].GetNumb() <= b && adress == arrRec[i].GetAdr())
				{
					arr[nRecFound] = arrRec[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "������� �� �������" << endl;
				system("pause");
			}
			break;
		}
		case '2':
		{
			Date a, b;
			cout << "������� �������� ���" << endl;
			cout << "��:" << endl;
			a = InputDate();
			cout << "��:" << endl;
			b = InputDate();
			if (a > b)swap(a, b);
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetStart() >= a && arrRec[i].GetStart() <= b && adress == arrRec[i].GetAdr())
				{
					arr[nRecFound] = arrRec[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "������� �� �������" << endl;
				system("pause");
			}
			break;
		}
		case '3':
		{
			Date a, b;
			cout << "������� �������� ���" << endl;
			cout << "��:" << endl;
			a = InputDate();
			cout << "��:" << endl;
			b = InputDate();
			if (a > b)swap(a, b);
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetEnd() >= a && arrRec[i].GetEnd() <= b && adress == arrRec[i].GetAdr())
				{
					arr[nRecFound] = arrRec[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "������� �� �������" << endl;
				system("pause");
			}
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
		{
			cout << "������. ��������� ����" << endl;
			system("pause");
			break;
		}
		}
		system("cls");
		if (nRecFound > 0)
		{
			Record::ShowRecords(arr, nRecFound);
			system("pause");
		}
		delete[] arr;
	}
	delete[] arrRec;
	return;
}

int Employee::ReadFromFile(Employee*& arr)
{
	if (arr != NULL)
	{
		delete[] arr;
	}
	int n = 0;
	ifstream f;
	f.open("employee.txt", ios_base::in);
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("employee.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	arr = new Employee[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	f.close();
	WriteToFile(arr, n);
	return n;
}

void Employee::WriteToFile(Employee*& arr, int n)
{
	ofstream fout;
	fout.open("employee.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr[i] << endl;
	}
	fout.close();
}

void Employee::EditAccount()
{
	Employee* arr = NULL;
	int n = Employee::ReadFromFile(arr);
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->GetFIO() == arr[i].GetFIO() && this->GetAdress() == arr[i].GetAdress())
		{
			index = i;
			break;
		}
	}

	bool work = true;
	while (work)
	{
		system("cls");
		cout << "�������� ���� ��� ��������������" << endl;
		cout << "1.��� �������������" << endl;
		cout << "2.�������� ���������" << endl;
		cout << "3.����� ���������" << endl;
		cout << "4.�����" << endl;
		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			FIO fio;
			cout << "������� ��� ������������� " << endl;
			fio = InputFIO();
			SetFIO(fio);
			break;
		}
		case '2':
		{
			cout << "������� �������� ���������" << endl;
			string name;
			getline(cin, name);
			getline(cin, name);

			Record* arrRec = NULL;
			int nRec = Record::ReadFromFile(arrRec);
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetHotel() == GetName())
				{
					arrRec[i].SetHotel(name);
				}
			}
			Record::WriteToFile(arrRec, n);

			this->SetName(name);
			break;
		}
		case '3':
		{
			cout << "������� ����� ���������" << endl;
			Adress adr;
			cin >> adr;

			Record* arrRec = NULL;
			int nRec = Record::ReadFromFile(arrRec);
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetAdr() == GetAdress())
				{
					arrRec[i].SetAdr(adr);
				}
			}
			Record::WriteToFile(arrRec, n);

			this->SetAdress(adr);
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
		{
			cout << "������. ��������� ����" << endl;
			system("pause");
		}
		}
	}
	arr[index] = *this;

	delete[] arr;
}

ostream& operator<<(ostream& o, Employee obj)
{
	o << obj.fio << "\n" << obj.name << "\n" << obj.adress << endl << obj.login << " " << obj.password;
	return o;
}

istream& operator>>(istream& in, Employee& obj)
{
	in >> obj.fio;
	getline(in, obj.name);
	getline(in, obj.name);
	in >> obj.adress >> obj.login >> obj.password;
	return in;
}

string Employee::GetName()
{
	return name;
}

void Employee::SetName(string n)
{
	name = n;
}

Adress Employee::GetAdress()
{
	return adress;
}

void Employee::SetAdress(Adress adr)
{
	adress = adr;
}

void Employee::ShowPersons()
{
	Employee* arr = NULL;
	int n = Employee::ReadFromFile(arr);
	Employee::ShowPersons(arr, n);
	delete[] arr;
}

void Employee::ShowPersons(Employee* arr, int n)
{
	if (!n)
	{
		cout << "������� ���" << endl;
		return;
	}

	cout << "**********************************************************************" << endl;
	cout << "| � |   ��� �������������   |�������� ���������|        �����        |" << endl;
	cout << "**********************************************************************" << endl;
	for (int i = 0; i < n; i++)
	{
		printf("|%3d|    %12s %c.%c.  | %16s |��.%13s %4d|\n", i + 1, arr[i].fio.F.c_str(), arr[i].fio.I[0], arr[i].fio.O[0], arr[i].name.c_str(), arr[i].adress.GetStreet().c_str(), arr[i].adress.GetHouse());
		cout << "**********************************************************************" << endl;
	}
}