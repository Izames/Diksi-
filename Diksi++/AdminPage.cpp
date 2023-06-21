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
	cout << "�������� ��������: " << endl;
	cout << "1: ������ �����������" << endl;
	cout << "2: ������ ����" << endl;
	cout << "3: ������ ���������" << endl;
	cout << "4: �����" << endl;
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
				//��������� �����
				break;
			default:
				cout << "������� ������� ������" << endl;
				StartPage();
				break;
		}
	}
	else 
	{
		cout << "������� �������� ������!" << endl;
		StartPage();
	}
}

void WorkWithStaff()
{
	cout << "��� ������ �������?" << endl;
	cout << "1: ���������� ������" << endl;
	cout << "2: �������� ����������" << endl;
	cout << "3: ������� ����������" << endl;
	cout << "4: �����" << endl;
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
		cout << "������� �������� ������!" << endl;
		WorkWithStaff();
	}
}
void ViewStaff() 
{
	list<User> StaffList = Des();
	int counter = 1;
	for (User user : StaffList) 
	{
		cout<< counter << ") ����: " << user.role << "\t�������: " << user.surname << "\t���: " << user.name << "\t��������: " << user.thirdname << "\t�����: " << user.login << "\tpassword: " << user.password << endl;
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
	cout << "������� ������ ������������" << endl;
	cout << "������� ���� ������������. Admin, warehouse, provider, buhgalter, cooker, waiter: ";
	cin >> role;
	if (role == "Admin" || role == "warehouse" || role == "provider" || role == "buhgalter" || role == "cooker" || role == "waiter")
	{
		cout << "������� �������: ";
		cin >> surname;
		cout << "������� ���: ";
		cin >> name;
		cout << "������� ��������: ";
		cin >> thirdname;
		cout << "������� �����: ";
		cin >> login;
		cout << "������� ������: ";
		cin >> password;
		Ser(role, surname, name, thirdname, login, password);
		cout << " ������������ ������� ��������! ������ �������� ��� ������, ��� ��������� �����?" << endl;
		cout << "1:��������" << endl;
		cout << "2:������ ��������" << endl;
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
		cout << "������� ������� ������" << endl;
		AddStaff();
	}
}
void DeleteStaff()
{
	string index;
	string choice;
	int user;
	cout << "������� ����� ����������, �������� ������ �������: ";
	cin >> index;
	try 
	{
		user = stoi(index);
	}
	catch (exception ex)
	{
		cout << "������� ������� ������" << endl;
		DeleteStaff();
	}
	deleteStaff(user);
}




void WorkWithPR()
{
	cout << "��� ������ �������?" << endl;
	cout << "1: ���������� ������" << endl;
	cout << "2: �������� �������" << endl;
	cout << "3: ������� �������" << endl;
	cout << "4: �����" << endl;
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
		cout << "������� �������� ������!" << endl;
		WorkWithPR();
	}
}
void ViewPR()
{
	list<Product> PRList = PDes();
	int counter = 1;
	for (Product pr : PRList)
	{
		cout << counter << ") ����: " << pr.id << "\t������������: " << pr.name << "\t����: " << pr.cost << endl;
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
	cout << "������� ������ ��������" << endl;
	cout << "������� ��������� ��������: ";
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
		cout << "������" << endl;
		AddPR();
	}

	cout << "������� ������������: ";
	cin >> name;
	PSer(id, name, cost);
	cout << " ������� ������� ��������! ������ �������� ��� ������, ��� ��������� �����?" << endl;
	cout << "1:��������" << endl;
	cout << "2:������ ��������" << endl;
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
	cout << "������� ����� ������, �������� ������ �������: ";
	cin >> index;
	try
	{
		pr = stoi(index);
	}
	catch (exception ex)
	{
		cout << "������� ������� ������" << endl;
		DeletePR();
	}
	deleteProducts(pr);
}



void WorkWithMenu()
{
	cout << "��� ������ �������?" << endl;
	cout << "1: ���������� ������" << endl;
	cout << "2: �������� �����" << endl;
	cout << "3: ������� �����" << endl;
	cout << "4: �����" << endl;
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
		cout << "������� �������� ������!" << endl;
		WorkWithMenu();
	}
}

void ViewM()
{
	list<MenuLi> MList = MDes();
	int counter = 1;
	for (MenuLi menu : MList)
	{
		cout << counter << ") ������������: " << menu.name << "\t���������: " << menu.gramm << "\t�����������: ";
		for (string pr : menu.structure) 
		{
			cout << pr << " ";
		}
		cout << "\t:�������� " << menu.info << "\t����� �������: " << menu.cookTime << "\t���������: " << menu.cost << endl;
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
	cout << "������� ������ ��� ������ ����" << endl;
	cout << "������� ������������ ������ �����: " << endl;
	cin.seekg(cin.eof());
	getline(cin, name);
	cout << "������� ��������� ������ �����: ";
	cin >> Sgramm;
	try
	{
		gramm = stod(Sgramm);
	}
	catch (exception ex)
	{
		cout << "�� ����� �������� ������ �����" << endl;
		AddM();
	}
	cout << "�������� ����������� ��� ����� �� ������������" << endl;
	list<Product> prs = PDes();
	for (Product pr : prs)
	{
		cout << pr.id << ") " << pr.name << endl;
	}
	string choice;
	while (true) 
	{
		cout << "������� id: ";
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
					cout << "������� " << pr.name << " ������� ��������" << endl;
					x = false;
				}
			}
			if (x)
			{
				cout << "����� �� ������" << endl;
			}
		}
		catch (exception ex)
		{
			cout << "�����-�� ��������� ���� ������ �������" << endl;
		}
		cout << "������ �������� ��� ���� �������? ������� 1 ��� �����������" << endl;
		cin >> choice;
		if (choice != "1")
		{
			break;
		}
	}
	cin.seekg(cin.eof());
	cout << "������� ��������: ";
	getline(cin, info);
	cin.seekg(cin.eof());
	cout << "������� ����� �������: ";
	getline(cin, info);
	cin.seekg(cin.eof());
	while (true) 
	{
		cout << "������� ���������: ";
		cin >> Scost;
		cin.seekg(cin.eof());
		try
		{
			cost = stod(Scost);
			break;
		}
		catch (exception ex)
		{
			cout << "������� �������� ������" << endl;
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
	cout << "������� ����� ������, �������� ������ �������: ";
	cin >> index;
	try
	{
		user = stoi(index);
	}
	catch (exception ex)
	{
		cout << "������� ������� ������" << endl;
		DeleteStaff();
	}
	deleteMenu(user);
}