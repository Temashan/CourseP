#pragma once
#include "employee.h"
#include "record.h"
#include "admin.h"

namespace MyMeny
{
	template <class T>
	class Menu
	{
		T per;

	public:
		Menu() {};
		Menu(const T&);
		T getPer();
		T SetPer(T);
		void MENU();


	};

	Menu<Employee>::Menu(const Employee&);
	Menu<Person>::Menu(const Person&);
	Menu<Admin>::Menu(const Admin&);

	template <class T>
	Menu<T>::Menu(const T& obj)
	{
		per = obj;
	}

	template <class T>
	T Menu<T>::getPer()
	{
		return per;
	}

	template <class T>
	T Menu<T>::SetPer(T obj)
	{
		swap(obj, per);
		return obj;
	}

	template <class T>
	void Menu<T>::MENU()
	{
		return;
	}

	void Menu<Admin>::MENU()
	{
		bool exit = false;
		while (!exit)
		{
			Account* a = NULL;
			int na = 0;
			Admin admin(per);

			Employee* arrD = NULL;
			int nD = Employee::ReadFromFile(arrD);
			Employee* arrP = NULL;
			int nP = Employee::ReadFromFile(arrP);

			a = new Account[2 + nD + nP];
			a[0] = admin;
			for (int i = 1; i < nD + 1; i++)
			{
				a[i] = arrD[i - 1];
			}
			for (int i = 1 + nD; i < 1 + nD + nP; i++)
			{
				a[i] = arrP[i - 1 - nD];
			}
			if (arrD)
				delete[] arrD;
			if (arrP)
				delete[] arrP;
			na = 1 + nD + nP;

			system("cls");
			cout << "\t\t�������� ��������:" << endl;
			cout << "\t\t1.����������� ������ ��������\n";
			cout << "\t\t2.����������� ������ ��������\n";
			cout << "\t\t3.�������� ������� ���������� ���������\n";
			cout << "\t\t4.�������� ������� �������\n";
			cout << "\t\t5.������� ������� ���������� ���������\n";
			cout << "\t\t6.������� ������� �������\n";
			cout << "\t\t7.�����\n";
			char choise;
			cin >> choise;
			system("cls");
			switch (choise)
			{
			case '1':
			{
				Employee::ShowPersons();
				system("pause");
				break;
			}
			case '2':
			{
				Person::ShowPersons();
				system("pause");
				break;
			}
			case '3':
			{
				Employee* arr = NULL;
				int n = Employee::ReadFromFile(arr);
				if (!n)
				{
					arr = new Employee[2];
				}
				cout << "������� �����" << endl;
				bool correct = false;
				string str;
				do
				{
					correct = true;
					cin >> str;
					for (int i = 0; i < na; i++)
					{
						if (str == a[i].GetLogin())
						{
							cout << "����� ����� ��� ����������" << endl;
							correct = false;
							break;
						}
					}
				} while (!correct);

				arr[n].SetLogin(str);
				cout << "������� ������" << endl;
				cin >> str;
				arr[n].SetPass(str);

				FIO fio;
				cout << "������� ��� " << endl;
				fio = InputFIO();
				arr[n].SetFIO(fio);

				cout << "������� �������� ���������" << endl;
				getline(cin, str);
				arr[n].SetName(str);

				cout << "������� ����� ���������" << endl;
				Adress adr;
				adr = InputAdr();

				arr[n].SetAdress(adr);

				n++;

				Employee::WriteToFile(arr, n);
				delete[] arr;
				break;
			}
			case '4':
			{
				Person* arr = NULL;
				int n = Person::ReadFromFile(arr);
				if (!n)
				{
					arr = new Person[2];
				}
				cout << "������� �����" << endl;
				bool correct = false;
				string str;
				do
				{
					correct = true;
					cin >> str;
					for (int i = 0; i < na; i++)
					{
						if (str == a[i].GetLogin())
						{
							cout << "����� ����� ��� ����������" << endl;
							correct = false;
							break;
						}
					}
				} while (!correct);

				arr[n].SetLogin(str);
				cout << "������� ������" << endl;
				cin >> str;
				arr[n].SetPass(str);

				FIO fio;
				cout << "������� ���" << endl;
				fio = InputFIO();
				arr[n].SetFIO(fio);

				n++;

				Person::WriteToFile(arr, n);
				delete[] arr;

				break;
			}
			case '5':
			{
				Employee* arr = NULL;
				int n = Employee::ReadFromFile(arr);
				if (!n)
				{
					cout << "��� ���������" << endl;
					system("pause");
					break;
				}

				Employee::ShowPersons(arr, n);

				int num = 0;
				cout << "�������� ����� ���������� ��������" << endl;
				while (num<1 || num>n)
				{
					num = InputInt();
					if (num<1 || num>n)
					{
						cout << "������ ������ �������� ���" << endl;
					}
				}
				num--;

				Adress adr = arr[num].GetAdress();

				for (int i = num; i < n - 1; i++)
				{
					arr[i] = arr[i + 1];
				}
				n--;
				Employee::WriteToFile(arr, n);
				delete[] arr;

				Record* arrRec = NULL;
				n = Record::ReadFromFile(arrRec);
				if (n)
				{
					for (int i = 0; i < n; i++)
					{
						if (arrRec[i].GetAdr() == adr)
						{
							for (int j = i; j < n - 1; j++)
							{
								arrRec[j] = arrRec[j + 1];
							}
							i--;
							n--;
						}
					}
				}
				Record::WriteToFile(arrRec, n);
				break;
			}
			case '6':
			{
				Person* arr = NULL;
				int n = Person::ReadFromFile(arr);
				if (!n)
				{
					cout << "��� ���������" << endl;
					system("pause");
					break;
				}

				Person::ShowPersons(arr, n);

				int num = 0;
				cout << "�������� ����� ���������� ��������" << endl;
				while (num<1 || num>n)
				{
					num = InputInt();
					if (num<1 || num>n)
					{
						cout << "������ ������ �������� ���" << endl;
					}
				}
				num--;

				FIO fio = arr[num].GetFIO();

				for (int i = num; i < n - 1; i++)
				{
					arr[i] = arr[i + 1];
				}
				n--;
				Person::WriteToFile(arr, n);
				delete[] arr;

				break;
			}
			case '7':
			{
				exit = true;
				break;
			}
			default:
			{
				cout << "������ �����, ��������� ��� ���" << endl;
				system("pause");
			}
			}
			if (a)
				delete[] a;
		}
	}

	void Menu<Employee>::MENU()
	{
		bool exit = false;
		while (!exit)
		{
			system("cls");
			cout << "\t\t����� ���������� ," << per.GetFIO().F << " " << per.GetFIO().I[0] << "." << per.GetFIO().O[0] << "." << "!\n\n\n";
			cout << "\t\t�������� ��������:\n";
			cout << "\t\t1.������� ������ � ���������\n";
			cout << "\t\t2.����������� ������ ������� � ���������\n";
			cout << "\t\t3.������� ������ � ���������\n";
			cout << "\t\t4.������������� ������ � ���������\n";
			cout << "\t\t5.������ ������ � ���������\n";
			cout << "\t\t6.����������� ������ � ���������\n";
			cout << "\t\t7.����������� ������ � ���������\n";
			cout << "\t\t8.�������� ���������� � ���������\n";
			cout << "\t\t9.�������� ������� ���������\n";
			cout << "\t\t0.�����\n";
			char choise;
			cin >> choise;
			system("cls");
			switch (choise)
			{
			case '1':
			{
				per.AddRecord();
				break;
			}
			case '2':
			{
				per.ShowRecords();
				system("pause");
				break;
			}
			case '3':
			{
				per.DeleteRecord();
				break;
			}
			case '4':
			{
				per.EditRecord();
				break;
			}
			case '5':
			{
				per.SearchRecord();
				break;
			}
			case '6':
			{
				per.SortRecord();
				break;
			}
			case '7':
			{
				per.FilterRecord();
				break;
			}
			case '8':
			{
				per.EditAccount();
				break;
			}
			case '9':
			{
				per.ShowHistory();
				break;
			}
			case '0':
			{
				exit = true;
				break;
			}
			default:
				cout << "������!\n";
				system("pause");
				break;
			}
		}
	}

	void Menu<Person>::MENU()
	{
		bool exit = false;
		while (!exit)
		{
			system("cls");
			cout << "\t\t����� ���������� ," << per.GetFIO().F << " " << per.GetFIO().I[0] << "." << per.GetFIO().O[0] << "." << "!\n\n\n";
			cout << "\t\t�������� ��������:" << endl;
			cout << "\t\t1.����������� ������ ��������\n";
			cout << "\t\t2.����������� ������ ���������\n";
			cout << "\t\t3.������ ������ � ���������\n";
			cout << "\t\t4.����������� ������ � ���������\n";
			cout << "\t\t5.����������� ������ � ���������\n";
			cout << "\t\t6.�������� ���������� ��������\n";
			cout << "\t\t7.�����\n";
			char choise;
			cin >> choise;
			system("cls");
			switch (choise)
			{
			case '1':
			{
				Employee::ShowPersons();
				system("pause");
				break;
			}
			case '2':
			{
				per.ShowRecords();
				system("pause");
				break;
			}
			case '3':
			{
				per.SearchRecord();
				break;
			}
			case '4':
			{
				per.SortRecord();
				break;
			}
			case '5':
			{
				per.FilterRecord();
				break;
			}
			case '6':
			{
				per.EditAccount();
				break;
			}
			case '7':
			{
				exit = true;
				break;
			}
			default:
				cout << "������!\n";
				system("pause");
				break;
			}
		}
	}
}
