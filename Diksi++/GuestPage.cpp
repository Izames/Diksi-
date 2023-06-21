#include "GuestPage.h"
#include <iostream>
#include "Menu.h"
#include <vector>
#include <chrono>
#include <thread>
#include "storage.h"
#include "orders.h"
#include "finance.h"
using namespace std;
struct item
{
	string pr;
	int quentity;
};
struct Cart
{
	double cost;
	list<item> prs;
};

Cart cart;
bool th = true;

void Wait();
void Waits();
void giveOrder();
void GViewM();
void giveOrder();
void Waits();
void Wait();
void RedactStorage();

void StartPageG()
{
	string choice;
	cout << "вы вошли как посетитель" << endl;
	cout << "1: посмотреть меню" << endl;
	cout << "2: передать заказ официанту" << endl;
	cout << "3: вернуться назад" << endl;
	cin >> choice;
	if (choice == "1" || choice == "2" || choice == "3")
	{
		if (choice == "1")
		{
			GViewM();
		}
		else if (choice == "2")
		{
			giveOrder();
		}
		else
		{
			//вернуться назад
		}
	}
	else
	{
		cout << "введены неверные данные" << endl;
		StartPageG();
	}
}
void GViewM()
{
	int counter = 1;
	item Item;
	string Snumber;
	string Squentity;
	int number;
	int quentity;
	double cost = 0;
	list<string> ings;
	bool checkQuentity = true;
	list<MenuLi> menus = MDes();
	list<WH> whs = WHDes();
	for (MenuLi m : menus)
	{
		cout << counter << ") наименование: " << m.name << "\tвес: " << m.gramm << "\tописание: " << m.info << "\tвремя приготовления: " << m.cookTime << "\tцена: " << m.cost << endl;
		counter++;
	}
	vector<MenuLi> VectorMenu;
	for (MenuLi m : menus)
	{
		VectorMenu.push_back(m);
	}
	cout << "выберите пункт: ";
	cin >> Snumber;
	try
	{
		number = stoi(Snumber);

	}
	catch (exception ex)
	{
		cout << "неверно введен тип данных!" << endl;
		StartPageG();
	}

	try
	{
		Item.pr = VectorMenu[number - 1].name;
	}
	catch (exception ex)
	{
		cout << "такого товара нет в наличии!" << endl;
		StartPageG();
	}
	for (item p : cart.prs)
	{
		if (p.pr == Item.pr)
		{
			cout << "такой заказ уже имеется в вашей корзине" << endl;
			StartPageG();
		}
	}
	cout << "введите количество: ";
	cin >> Squentity;
	try
	{
		quentity = stoi(Squentity);
		if (quentity < 1)
		{
			cout << "неверный тип данных" << endl;
			StartPageG();
		}
	}
	catch (exception ex)
	{
		cout << "неверный тип данных" << endl;
		StartPageG();
	}

	ings = VectorMenu[number - 1].structure;//получил список продуктов из которых готовится блюдо
	bool check = false;
	for (string ing : ings)
	{
		for (WH wh : whs)
		{
			if (ing == wh.pr)
			{
				if (wh.quentity < quentity)
				{
					checkQuentity = false; // проверка на возможность заказа
				}
				check = true;
			}
		}
		if (!check)
		{
			cout << "недостаток ингридиентов для данного блюда" << endl;
			StartPageG();
		}
	}
	cout << "пункт добавлен" << endl;
	Item.quentity = quentity;
	cost = VectorMenu[number - 1].cost * quentity;

	cart.cost += cost;
	cart.prs.push_back(Item);
	StartPageG();
}

void giveOrder()
{
	int quent = 0;
	cout << "ваш заказ передан официанту" << endl;
	cout << "в него входили:" << endl;
	for (item it : cart.prs)
	{
		cout << it.pr << "\tв количестве: " << it.quentity << endl;
		quent = quent + it.quentity;
	}
	cout << "все это на сумму: " << cart.cost << endl;
	list<string> x;
	for (item i : cart.prs)
	{
		x.push_back(i.pr);
	}
	OSer("give kitchen", x);
	finances s = FDes();
	FSer(s.budget + cart.cost, s.sell_pr + quent, s.spent, s.summ_sell_pr + cart.cost);
	list<WH> whs = WHDes();

	RedactStorage();
	Wait();
}


void Waits() {
	while (th)
	{
		this_thread::sleep_for(chrono::seconds(10)); // задержка 
		cout << "заказ в статусе на кухне" << std::endl; // ожидание пользователя
	}
	
}

void Wait() {
	string s;
	thread newThread(Waits); // Создаем новый поток и передаем в него функцию myFunction
	newThread.join(); // Ждем, пока новый поток завершит свою работу
	cin >> s;
	th = false;
}
struct ingses
{
	string name;
	int quent;
};
struct unitses
{
	string name;
	int quent;
};

void RedactStorage()
{
	list<ingses> ings;
	ingses ing;
	list<MenuLi> ML = MDes();
	list<unitses> units;
	list<WH> whs = WHDes();
	for (item it : cart.prs)
	{
		units.push_back({ {it.pr }, {it.quentity}});
	}
	for (MenuLi punkt : ML)
	{
		for (unitses unit : units)
		{
			if (unit.name == punkt.name)
			{
				for (string i : punkt.structure)
				{
					ing.name = i;
					ing.quent = unit.quent;
					ings.push_back(ing);
				}
			}
		}
	}
	for (WH wh : whs)
	{
		for (ingses i : ings)
		{
			if (i.name == wh.pr)
			{
				updateWH(i.name, wh.cost, i.quent, false);
			}
		}
	}
}
