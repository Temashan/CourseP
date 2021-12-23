#pragma once
#include "person.h"

Person::Person()
{
}

Person::Person(Person& o)
{
	login = o.login;
	password = o.password;
	fio = o.fio;
}

void Person::ShowRecords()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);
	if (!nRec)
	{
		cout << "Ещё нет ни одной записи\n";
		system("pause");
		return;
	}
	Record* arrInd = new Record[nRec + 2];
	int n = 0;
	for (int i = 0; i < nRec; i++)
	{
		if (arrRec[i].GetClient() == this->fio)
		{
			arrInd[n] = arrRec[i];
			n++;
		}
	}
	Record::ShowRecords(arrRec, nRec);
	delete[] arrRec;
	delete[] arrInd;
	return;
}

void Person::SearchRecord()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!nRec)
	{
		cout << "Ещё нет ни одной записи\n";
		system("pause");
		return;
	}
	bool work = true;
	while (work)
	{
		system("cls");
		Record* arr = new Record[nRec];
		int nRecFound = 0;
		cout << "Выберите поле для поиска" << endl;
		cout << "1.Название гостиницы" << endl;
		cout << "2.Адрес гостиницы" << endl;
		cout << "3.Выход" << endl;
		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			string f;
			cout << "Введите название гостиницы" << endl;
			getline(cin, f);
			getline(cin, f);
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetHotel() == f && arrRec[i].GetClient() == fio)
				{
					arr[nRecFound] = arrRec[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "Записей не найдено" << endl;
				system("pause");
			}
			break;
		}
		case '2':
		{
			Adress adr;
			cout << "Введите адрес гостиницы" << endl;
			adr = InputAdr();
			for (int i = 0; i < nRec; i++)
			{
				if (arrRec[i].GetAdr() == adr && arrRec[i].GetClient() == fio)
				{
					arr[nRecFound] = arrRec[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "Записей не найдено" << endl;
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
			cout << "Ошибка. Повторите ввод" << endl;
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

void Person::SortRecord()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!nRec)
	{
		cout << "Нет записей\n";
		system("pause");
		return;
	}
	Record* arrInd = new Record[nRec + 2];
	int n = 0;
	for (int i = 0; i < nRec; i++)
	{
		if (arrRec[i].GetClient() == this->fio)
		{
			arrInd[n] = arrRec[i];
			n++;
		}
	}
	if (!n)
	{
		cout << "Нет записей\n";
		system("pause");
		delete[] arrRec;
		delete[] arrInd;
		return;
	}
	bool work = true;
	while (work)
	{
		system("cls");
		cout << "Выберите поле для сортировки" << endl;
		cout << "1.Название гостиницы" << endl;
		cout << "2.Адрес гостиницы" << endl;
		cout << "3.Дата заселения" << endl;
		cout << "4.Дата выселения" << endl;
		cout << "5.Выход" << endl;
		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arrInd[i].GetHotel().c_str(), arrInd[j].GetHotel().c_str()) == 1)
					{
						swap(arrInd[i], arrInd[j]);
					}
				}
			}
			Record::ShowRecords(arrInd, n);
			system("pause");
			break;
		}
		case '2':
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (strcmp(arrInd[i].GetAdr().GetStreet().c_str(), arrInd[j].GetAdr().GetStreet().c_str()) == 1)
					{
						swap(arrInd[i], arrInd[j]);
					}
				}
			}
			Record::ShowRecords(arrInd, n);
			system("pause");
			break;
		}
		case '3':
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arrInd[i].GetStart() > arrInd[j].GetStart())
					{
						swap(arrInd[i], arrInd[j]);
					}
				}
			}
			Record::ShowRecords(arrInd, n);
			system("pause");
			break;
		}
		case '4':
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					if (arrInd[i].GetEnd() > arrInd[j].GetEnd())
					{
						swap(arrInd[i], arrInd[j]);
					}
				}
			}
			Record::ShowRecords(arrInd, n);
			system("pause");
			break;
		}
		case '5':
		{
			work = false;
			break;
		}
		default:
		{
			cout << "Ошибка. Повторите ввод" << endl;
			system("pause");
			break;
		}
		}
	}
	delete[] arrRec;
	delete[] arrInd;
	return;
}

void Person::FilterRecord()
{
	system("cls");
	Record* arrRec = NULL;
	int nRec = Record::ReadFromFile(arrRec);

	if (!nRec)
	{
		cout << "Нет записей\n";
		system("pause");
		return;
	}

	Record* arrInd = new Record[nRec + 2];
	int n = 0;
	for (int i = 0; i < nRec; i++)
	{
		if (arrRec[i].GetClient() == this->fio)
		{
			arrInd[n] = arrRec[i];
			n++;
		}
	}
	if (!n)
	{
		cout << "Нет записей\n";
		system("pause");
		delete[] arrRec;
		delete[] arrInd;
		return;
	}
	bool work = true;
	while (work)
	{
		Record* arr = new Record[nRec];
		int nRecFound = 0;
		system("cls");
		cout << "Выберите поле для фильтрации" << endl;
		cout << "1.Дата заселения" << endl;
		cout << "2.Дата выселения" << endl;
		cout << "3.Выход" << endl;
		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			Date a, b;
			cout << "Введите диапазон дат" << endl;
			cout << "От:" << endl;
			a = InputDate();
			cout << "До:" << endl;
			b = InputDate();
			if (a > b)swap(a, b);
			for (int i = 0; i < n; i++)
			{
				if (arrInd[i].GetStart() >= a && arrInd[i].GetStart() <= b)
				{
					arr[nRecFound] = arrInd[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "Записей не найдено" << endl;
				system("pause");
			}
			break;
		}
		case '2':
		{
			Date a, b;
			cout << "Введите диапазон дат" << endl;
			cout << "От:" << endl;
			a = InputDate();
			cout << "До:" << endl;
			b = InputDate();
			if (a > b)swap(a, b);
			for (int i = 0; i < n; i++)
			{
				if (arrInd[i].GetEnd() >= a && arrInd[i].GetEnd() <= b)
				{
					arr[nRecFound] = arrInd[i];
					nRecFound++;
				}
			}
			if (nRecFound == 0)
			{
				cout << "Записей не найдено" << endl;
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
		{
			cout << "Ошибка. Повторите ввод" << endl;
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
	delete[] arrInd;
	return;
}

int Person::ReadFromFile(Person*& arr)
{
	if (arr != NULL)
	{
		delete[] arr;
	}
	int n = 0;
	ifstream f;
	f.open("person.txt", ios_base::in);
	f >> n;
	if (n == 0)
	{
		f.close();
		ofstream fout;
		fout.open("person.txt", ios_base::trunc);
		fout << 0 << endl;
		fout.close();
		return n;
	}
	arr = new Person[n + 1];
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	f.close();
	WriteToFile(arr, n);
	return n;
}

void Person::WriteToFile(Person*& arr, int n)
{
	ofstream fout;
	fout.open("person.txt", ios_base::trunc);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr[i] << endl;
	}
	fout.close();
}

void Person::EditAccount()
{
	Person* arr = NULL;
	int n = Person::ReadFromFile(arr);
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (this->GetFIO() == arr[i].GetFIO())
		{
			index = i;
			break;
		}
	}

	bool work = true;
	while (work)
	{
		system("cls");
		cout << "Выберите поле для редактирования" << endl;
		cout << "1.Фамилия" << endl;
		cout << "2.Имя" << endl;
		cout << "3.Отчество" << endl;
		cout << "4.Выход" << endl;
		char choise;
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case '1':
		{
			cout << "Введите фамилию " << endl;
			string str;
			bool correct = false;
			while (!correct)
			{
				correct = true;
				getline(cin, str, '\n');
				getline(cin, str, '\n');
				for (int i = 0; i < str.length(); i++)
				{
					if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || proverka(str[i])))
					{
						correct = false;
						break;
					}
				}
				if (correct)
				{
					for (int i = 1; i < str.length(); i++)
					{
						if (!proverka(str[i]))
							str[i] = tolower(str[i]);
					}
					if (!proverka(str[0]))
						str[0] += 'A' - 'a';
				}
				else
				{
					cout << "Некорректный ввод" << endl;
				}
			}
			fio.F = str;
			break;
		}
		case '2':
		{
			cout << "Введите имя " << endl;
			string str;
			bool correct = false;
			while (!correct)
			{
				correct = true;
				getline(cin, str, '\n');
				getline(cin, str, '\n');
				for (int i = 0; i < str.length(); i++)
				{
					if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || proverka(str[i])))
					{
						correct = false;
						break;
					}
				}
				if (correct)
				{
					for (int i = 1; i < str.length(); i++)
					{
						if (!proverka(str[i]))
							str[i] = tolower(str[i]);
					}
					if (!proverka(str[0]))
						str[0] += 'A' - 'a';
				}
				else
				{
					cout << "Некорректный ввод" << endl;
				}
			}
			fio.I = str;
			break;
		}
		case '3':
		{
			cout << "Введите отчество " << endl;
			string str;
			bool correct = false;
			while (!correct)
			{
				correct = true;
				getline(cin, str, '\n');
				getline(cin, str, '\n');
				for (int i = 0; i < str.length(); i++)
				{
					if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || proverka(str[i])))
					{
						correct = false;
						break;
					}
				}
				if (correct)
				{
					for (int i = 1; i < str.length(); i++)
					{
						if (!proverka(str[i]))
							str[i] = tolower(str[i]);
					}
					if (!proverka(str[0]))
						str[0] += 'A' - 'a';
				}
				else
				{
					cout << "Некорректный ввод" << endl;
				}
			}
			fio.O = str;
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
		{
			cout << "Ошибка. Повторите ввод" << endl;
			system("pause");
		}
		}
	}
	arr[index] = *this;

	delete[] arr;
}

void Person::ShowPersons()
{
	Person* arr = NULL;
	int n = Person::ReadFromFile(arr);
	ShowPersons(arr, n);
	delete[] arr;
}

void Person::ShowPersons(Person* arr, int n)
{
	if (n)
	{
		puts("********************************");
		puts("| № | Фамилия | Имя | Отчество |");
		puts("********************************");
		for (int i = 0; i < n; i++)
		{
			printf("|%3d|%7s|%5s|%10s|\n", i + 1, arr[i].fio.F.c_str(), arr[i].fio.I.c_str(), arr[i].fio.O.c_str());
			puts("********************************");
		}
	}
	else
	{
		cout << "Записей нет" << endl;
	}
}

void Person::SetFIO(FIO f)
{
	fio = f;
}

FIO Person::GetFIO()
{
	return fio;
}

ostream& operator<<(ostream& o, Person obj)
{
	o << obj.login << " " << obj.password << endl;
	o << obj.fio;
	return o;
}

istream& operator>>(istream& in, Person& obj)
{
	in >> obj.login >> obj.password >> obj.fio;
	return in;
}