#include "WHManager.h"
#include <iostream>
#include <list>
#include "storage.h">
#include "Products.h"
#include "request.h"
#include "finance.h"
using namespace std;

void ViewPr();
void Addrq();

void StartPageWH()
{
	string choice;
	cout << "вы вошли как складской менеджер" << endl;
	cout << "выберите действие" << endl;
	cout << "1: посмотреть список продуктов на складе" << endl;
	cout << "2: создать заявку на продукты" << endl;
	cout << "3: назад" << endl;
	std::cin >> choice;
	if (choice == "1" || choice == "2" || choice == "3")
	{
		if (choice == "1")
		{
			ViewPr();
		}
		else if (choice == "2")
		{
			Addrq();
		}
		else
		{
			//возвращение в главное меню
		}
	}
	else
	{
		cout << "неверное значение" << endl;
		StartPageWH();
	}
}
void ViewPr()
{
	list<WH> products = WHDes();
	for (WH pr : products)
	{
		cout << "продукт: " << pr.pr << "\t количество: " << pr.quentity << "\tпродуктов данного типа на сумму: " << pr.cost << endl;
	}
	StartPageWH();
}
void Addrq()
{
	bool check = true;
	string Scount;
	string name;
	string Snumber;
	int number;
	int quentity;
	double cost;
	cout << "Введмте данные для заявки" << endl;
	cout << "Выберите номер продукта" << endl;
	list<Product> prs = PDes();
	for (Product pr : prs)
	{
		cout << pr.id << ") наименование продукта: " << pr.name << "\tцена за штуку: " << pr.cost << endl;
	}
	cout << "номер: ";
	std::cin >> Snumber;
	try
	{
		number = stoi(Snumber);
		for (Product pr : prs)
		{
			if (pr.id == number) 
			{
				name = pr.name;
				cost = pr.cost;
				check = false;
			}
		}
		if (check)
		{
			cout << "не найден продукт" << endl;
			StartPageWH();
		}
	}
	catch (exception ex)
	{
		cout << "неверно введены данные" << endl;
		StartPageWH();
	}
	cout << "введите количество: ";
	std::cin >> Scount;
	try
	{
		quentity = stoi(Scount);
	}
	catch (exception ex)
	{
		cout << "неверно введены данные" << endl;
		StartPageWH();
	}
	cost = cost * quentity;
	finances bud = FDes();
	if (bud.budget >= cost)
	{
		RSer(name, quentity, cost, false);
		cout << "заявка создана!" << endl;
		StartPageWH();
	}
	else
	{
		cout << "недостаточно средств" << endl;
		StartPageWH();
	}
	
}