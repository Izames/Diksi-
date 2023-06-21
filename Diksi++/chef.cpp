#include "chef.h"
#include "orders.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <list>
#include "Products.h"
using namespace std;

void Cooking(int dish);

void StartPageC()
{
	int counter = 1;
	string choice;
	int num;
	cout << "вы вошли как повар" << endl;
	cout << "список заказов:" << endl;
	list<orders> ords = ODes();
	for (orders ord : ords)
	{
		cout << counter << ") ";
		cout  << "список блюд: ";
		if (ord.status == "give kitchen")
		{
			for (string pr : ord.Rorders)
			{
				cout << pr << " ";
			}
			cout << endl;
		}
		counter++;
	}
	cout << "введите номер заказа к которому хотите приступить, или же 0 для возвращения назад: ";
	cin >> choice;
	try
	{
		num = stoi(choice);
	}
	catch (exception ex)
	{
		cout << "неверно введены данные" << endl;
		StartPageC();
	}
	if (num == 0)
	{
		//возвращение назад
	}
	else
	{
		Cooking(num-1);
	}
}
void Cooking(int dish)
{
	bool CookNotSucceful = true;
	string ScookNum;
	int cookNum;
	list<orders> ords = ODes();
	vector<orders> Vords;
	list<string> punkts;
	list<MenuLi> mls = MDes();
	list<Product> prs = PDes();
	for (orders o : ords)
	{
		Vords.push_back(o);
	}
	try
	{
		Vords[dish];
	}
	catch (exception ex)
	{
		cout << "блюдо не обнаружено" << endl;
		StartPageC();
	}
	cout << "начинаем готовку" << endl;
	updateO1("cooking", dish);
	for (string ord : Vords[dish].Rorders)
	{
		punkts.push_back(ord);
	}
	for (string ord : punkts) // перебор заказов меню
	{
		for (MenuLi ml : mls) // просмотр ориг меню
		{
			if (ml.name == ord)
			{
				for (string ing : ml.structure)// выявление игридиентов
				{
					for (Product pr : prs)
					{
						if (pr.name == ing)
						{
							while (CookNotSucceful) // валидация айди
							{
								cout << "Введите - " << pr.id << endl;
								cin >> ScookNum;
								try
								{
									cookNum = stoi(ScookNum);
								}
								catch (exception ex)
								{
									cout << "неверный формат" << endl;
								}
								if (cookNum != pr.id)
								{
									cout << "неверное значение! вы порезались" << endl;
								}
								else 
								{
									cout << "верно!" << endl;
									CookNotSucceful = false;
								}
							}
						}
						CookNotSucceful = true;
					}
				}
			}
		}
	}
	cout << "готовка выполнена!" << endl;
	updateO1("gived to waiter", dish);
	StartPageC();
}