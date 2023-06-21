#include "AdminPage.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Staffs.h"
#include "Products.h"
#include "Menu.h"

using namespace std;

void WorkWithStaff();
void ViewStaff();
void AddStaff();
void DeleteStaff();

void WorkWithPR();
void ViewPR();
void AddPR();
void DeletePR();

void DeleteM();
void AddM();
void ViewM();
void WorkWithMenu();

void StartPage()
{
	system("cls");
	cout << "Выберите действие: " << endl;
	cout << "1: список сотрудников" << endl;
	cout << "2: список меню" << endl;
	cout << "3: список продуктов" << endl;
	cout << "4: назад" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "2" || choice == "3"|| choice == "4") 
	{
		switch (stoi(choice))
		{
			case 1:
				WorkWithStaff();
				break;
			case 2:
				WorkWithMenu();
				break;
			case 3:
				WorkWithPR();
				break;
			case 4:
				//вернуться назад
				break;
			default:
				cout << "неверно введены данные" << endl;
				StartPage();
				break;
		}
	}
	else 
	{
		cout << "Введены неверные данные!" << endl;
		StartPage();
	}
}

void WorkWithStaff()
{
	cout << "Что хотите сделать?" << endl;
	cout << "1: посмотреть список" << endl;
	cout << "2: добавить сотрудника" << endl;
	cout << "3: удалить сотрудника" << endl;
	cout << "4: назад" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "2" || choice == "3" || choice == "4") 
	{
		if (choice == "1") 
		{
			ViewStaff();
		}
		else if (choice == "2") 
		{
			AddStaff();
		}
		else if (choice == "3") 
		{
			DeleteStaff();
		}
		else if (choice == "4") 
		{
			StartPage();
		}
	}
	else 
	{
		cout << "Введены неверные данные!" << endl;
		WorkWithStaff();
	}
}
void ViewStaff() 
{
	list<User> StaffList = Des();
	int counter = 1;
	for (User user : StaffList) 
	{
		cout<< counter << ") Роль: " << user.role << "\tФамилия: " << user.surname << "\tИмя: " << user.name << "\tОтчество: " << user.thirdname << "\tЛогин: " << user.login << "\tpassword: " << user.password << endl;
		counter++;
	}
	WorkWithStaff();
}
void AddStaff() 
{
	string role;
	string surname;
	string name;
	string thirdname;
	string login;
	string password;
	string choice;
	cout << "Введите данные пользователя" << endl;
	cout << "Введите роль пользователя. Admin, warehouse, provider, buhgalter, cooker, waiter: ";
	cin >> role;
	if (role == "Admin" || role == "warehouse" || role == "provider" || role == "buhgalter" || role == "cooker" || role == "waiter")
	{
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << "Введите имя: ";
		cin >> name;
		cout << "введите отчество: ";
		cin >> thirdname;
		cout << "Введите логин: ";
		cin >> login;
		cout << "Введите пароль: ";
		cin >> password;
		Ser(role, surname, name, thirdname, login, password);
		cout << " Пользователь успешно добавлен! Хотите добавить еще одного, или вернуться назад?" << endl;
		cout << "1:добавить" << endl;
		cout << "2:другое действие" << endl;
		cin >> choice;
		if (choice == "1")
		{
			AddStaff();
		}
		else
		{
			WorkWithStaff();
		}
	}
	else
	{
		cout << "Неверно введены данные" << endl;
		AddStaff();
	}
}
void DeleteStaff()
{
	string index;
	string choice;
	int user;
	cout << "Введите номер сотрудника, которого хотите удалить: ";
	cin >> index;
	try 
	{
		user = stoi(index);
	}
	catch (exception ex)
	{
		cout << "Неверно введены данные" << endl;
		DeleteStaff();
	}
	deleteStaff(user);
}




void WorkWithPR()
{
	cout << "Что хотите сделать?" << endl;
	cout << "1: посмотреть список" << endl;
	cout << "2: добавить продукт" << endl;
	cout << "3: удалить продукт" << endl;
	cout << "4: назад" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "2" || choice == "3" || choice == "4")
	{
		if (choice == "1")
		{
			ViewPR();
		}
		else if (choice == "2")
		{
			AddPR();
		}
		else if (choice == "3")
		{
			DeletePR();
		}
		else if (choice == "4")
		{
			StartPage();
		}
	}
	else
	{
		cout << "Введены неверные данные!" << endl;
		WorkWithPR();
	}
}
void ViewPR()
{
	list<Product> PRList = PDes();
	int counter = 1;
	for (Product pr : PRList)
	{
		cout << counter << ") Айди: " << pr.id << "\tНаименование: " << pr.name << "\tЦенв: " << pr.cost << endl;
		counter++;
	}
	WorkWithPR();
}
void AddPR()
{
	string choice;
	int id;
	string Scost;
	string name;
	double cost;
	cout << "Введите данные продукта" << endl;
	cout << "Введите стоимость продукта: ";
	cin >> Scost;

	list<Product> PRlist = PDes();
	for (Product p : PRlist) 
	{
		id = p.id;
	}
	id = id + 1;
	try
	{
		cost = stod(Scost);
	}
	catch (exception ex)
	{
		cout << "ошибка" << endl;
		AddPR();
	}

	cout << "Введите наименование: ";
	cin >> name;
	PSer(id, name, cost);
	cout << " Продукт успешно добавлен! Хотите добавить еще одного, или вернуться назад?" << endl;
	cout << "1:добавить" << endl;
	cout << "2:другое действие" << endl;
	cin >> choice;
	if (choice == "1")
	{
		AddPR();
	}
	else
	{
		WorkWithPR();
	}
}
void DeletePR()
{
	string index;
	string choice;
	int pr;
	cout << "Введите номер товара, которого хотите удалить: ";
	cin >> index;
	try
	{
		pr = stoi(index);
	}
	catch (exception ex)
	{
		cout << "Неверно введены данные" << endl;
		DeletePR();
	}
	deleteProducts(pr);
}



void WorkWithMenu()
{
	cout << "Что хотите сделать?" << endl;
	cout << "1: посмотреть список" << endl;
	cout << "2: добавить пункт" << endl;
	cout << "3: удалить пункт" << endl;
	cout << "4: назад" << endl;
	string choice;
	cin >> choice;
	if (choice == "1" || choice == "2" || choice == "3" || choice == "4")
	{
		if (choice == "1")
		{
			ViewM();
		}
		else if (choice == "2")
		{
			AddM();
		}
		else if (choice == "3")
		{
			DeleteM();
		}
		else if (choice == "4")
		{
			StartPage();
		}
	}
	else
	{
		cout << "Введены неверные данные!" << endl;
		WorkWithMenu();
	}
}

void ViewM()
{
	list<MenuLi> MList = MDes();
	int counter = 1;
	for (MenuLi menu : MList)
	{
		cout << counter << ") наименование: " << menu.name << "\tграммовка: " << menu.gramm << "\tингридиенты: ";
		for (string pr : menu.structure) 
		{
			cout << pr << " ";
		}
		cout << "\t:Описание " << menu.info << "\tВремя готовки: " << menu.cookTime << "\tСтоимость: " << menu.cost << endl;
		counter++;
	}
	WorkWithMenu();
}

void AddM()
{
	string name;
	int gramm;
	string Sgramm;
	list<string> structure;
	string info;
	string cookTime;
	double cost;
	string Scost;
	string Sid;
	int id;
	cout << "Введите данные для пункта меню" << endl;
	cout << "Введите наименование нового блюда: " << endl;
	cin.seekg(cin.eof());
	getline(cin, name);
	cout << "Введите граммовку нового блюда: ";
	cin >> Sgramm;
	try
	{
		gramm = stod(Sgramm);
	}
	catch (exception ex)
	{
		cout << "Вы ввели неверный формат грамм" << endl;
		AddM();
	}
	cout << "Выберите ингрилиенты для блюда из существующих" << endl;
	list<Product> prs = PDes();
	for (Product pr : prs)
	{
		cout << pr.id << ") " << pr.name << endl;
	}
	string choice;
	while (true) 
	{
		cout << "Введите id: ";
		cin >> Sid;
		try 
		{
			id = stoi(Sid);
			bool x = true;
			for (Product pr : prs)
			{
				if (id == pr.id) 
				{
					structure.push_back(pr.name);
					cout << "продукт " << pr.name << " успешно добавлен" << endl;
					x = false;
				}
			}
			if (x)
			{
				cout << "товар не найден" << endl;
			}
		}
		catch (exception ex)
		{
			cout << "какие-то введенные вами данные неверны" << endl;
		}
		cout << "хотите добавить еще один продукт? Введите 1 для продолжения" << endl;
		cin >> choice;
		if (choice != "1")
		{
			break;
		}
	}
	cin.seekg(cin.eof());
	cout << "введите описание: ";
	getline(cin, info);
	cin.seekg(cin.eof());
	cout << "Введите время готовки: ";
	getline(cin, info);
	cin.seekg(cin.eof());
	while (true) 
	{
		cout << "Введите стоимость: ";
		cin >> Scost;
		cin.seekg(cin.eof());
		try
		{
			cost = stod(Scost);
			break;
		}
		catch (exception ex)
		{
			cout << "введены неверные данные" << endl;
		}
	}
	MSer(name, gramm, structure, info, cookTime, cost);
	WorkWithMenu();
}
void DeleteM()
{
	string index;
	string choice;
	int user;
	cout << "Введите номер пункта, которого хотите удалить: ";
	cin >> index;
	try
	{
		user = stoi(index);
	}
	catch (exception ex)
	{
		cout << "Неверно введены данные" << endl;
		DeleteStaff();
	}
	deleteMenu(user);
}