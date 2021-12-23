#pragma once
#include "menu.h"
#include <stdio.h>
#include <Windows.h>

using namespace MyMeny;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	system("color 02");
	while (true)
	{
		Admin admin;
		if (!admin.LoadFromFile())
		{
			cout << "Это первый вход. Зарегистрируйте администратора" << endl;
			admin.Init();
			Menu<Admin> mnu(admin);
			mnu.MENU();

		}

		Person* arrP = NULL;
		int nP = Person::ReadFromFile(arrP);
		Employee* arrE = NULL;
		int nE = Employee::ReadFromFile(arrE);

		system("cls");

		cout << "ДОБРО ПОЖАЛОВАТЬ!!!" << endl;	
		cout << "1.Вход под администратором" << endl;
		cout << "2.Вход под сотрудником гостиницы" << endl;
		cout << "3.Вход под клиентом" << endl;
		cout << "4.Выход" << endl;
		int choise = InputInt();
		switch (choise)
		{
		case 1:
		{
			cout << "Введите логин" << endl;
			string login;
			cin >> login;
			if (login == "5")
			{
				break;
			}
			cout << "Введите пароль" << endl;
			char c = 0;
			char str[70];
			int it = 0;
			do
			{
				c = _getch();
				if (c == '\b')
				{
					if (it != 0)
					{
						cout << "\b \b";
						it--;
					}
				}
				else if (c == 13)
				{
					str[it] = '\0';
					it++;
				}
				else
				{
					str[it] = c;
					it++;
					printf("*");
				}

			} while (c != 13);
			string password = str;
			bool loged = false;
			if (admin.GetLogin() == login && admin.GetPass() == password)
			{
				loged = true;
				Menu<Admin> mnu(admin);
				mnu.MENU();
			}
			if (!loged)
			{
				system("cls");
				cout << "Логин или пароль неверный" << endl;
				system("pause");
			}
			break;
		}
		case 2:
		{
			cout << "Введите логин" << endl;
			string login;
			cin >> login;
			if (login == "5")
			{
				break;
			}
			cout << "Введите пароль" << endl;
			char c = 0;
			char str[70];
			int it = 0;
			do
			{
				c = _getch();
				if (c == '\b')
				{
					if (it != 0)
					{
						cout << "\b \b";
						it--;
					}
				}
				else if (c == 13)
				{
					str[it] = '\0';
					it++;
				}
				else
				{
					str[it] = c;
					it++;
					printf("*");
				}

			} while (c != 13);
			string password = str;
			bool loged = false;
			for (int i = 0; i < nE; i++)
			{
				if (arrE[i].GetLogin() == login && arrE[i].GetPass() == password)
				{
					loged = true;
					Menu<Employee> mnu(arrE[i]);
					mnu.MENU();
				}
			}
			if (!loged)
			{
				system("cls");
				cout << "Логин или пароль неверный" << endl;
				system("pause");
			}
			break;
		}
		case 3:
		{
			cout << "Введите логин" << endl;
			string login;
			cin >> login;
			if (login == "5")
			{
				break;
			}
			cout << "Введите пароль" << endl;
			char c = 0;
			char str[70];
			int it = 0;
			do
			{
				c = _getch();
				if (c == '\b')
				{
					if (it != 0)
					{
						cout << "\b \b";
						it--;
					}
				}
				else if (c == 13)
				{
					str[it] = '\0';
					it++;
				}
				else
				{
					str[it] = c;
					it++;
					printf("*");
				}

			} while (c != 13);
			string password = str;
			bool loged = false;
			for (int i = 0; i < nP; i++)
			{
				if (arrP[i].GetLogin() == login && arrP[i].GetPass() == password)
				{
					loged = true;
					Menu<Person> mnu(arrP[i]);
					mnu.MENU();
				}
			}
			if (!loged)
			{
				system("cls");
				cout << "Логин или пароль неверный" << endl;
				system("pause");
			}
			break;
		}
		case 4:
		{
			return 0;
			break;
		}
		default:
		{

			cout << "Некорректный ввод" << endl;
			system("pause");
			break;
		}
		}

	}
	return 0;
}