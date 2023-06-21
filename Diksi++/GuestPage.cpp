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
	cout << "�� ����� ��� ����������" << endl;
	cout << "1: ���������� ����" << endl;
	cout << "2: �������� ����� ���������" << endl;
	cout << "3: ��������� �����" << endl;
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
			//��������� �����
		}
	}
	else
	{
		cout << "������� �������� ������" << endl;
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
		cout << counter << ") ������������: " << m.name << "\t���: " << m.gramm << "\t��������: " << m.info << "\t����� �������������: " << m.cookTime << "\t����: " << m.cost << endl;
		counter++;
	}
	vector<MenuLi> VectorMenu;
	for (MenuLi m : menus)
	{
		VectorMenu.push_back(m);
	}
	cout << "�������� �����: ";
	cin >> Snumber;
	try
	{
		number = stoi(Snumber);

	}
	catch (exception ex)
	{
		cout << "������� ������ ��� ������!" << endl;
		StartPageG();
	}

	try
	{
		Item.pr = VectorMenu[number - 1].name;
	}
	catch (exception ex)
	{
		cout << "������ ������ ��� � �������!" << endl;
		StartPageG();
	}
	for (item p : cart.prs)
	{
		if (p.pr == Item.pr)
		{
			cout << "����� ����� ��� ������� � ����� �������" << endl;
			StartPageG();
		}
	}
	cout << "������� ����������: ";
	cin >> Squentity;
	try
	{
		quentity = stoi(Squentity);
		if (quentity < 1)
		{
			cout << "�������� ��� ������" << endl;
			StartPageG();
		}
	}
	catch (exception ex)
	{
		cout << "�������� ��� ������" << endl;
		StartPageG();
	}

	ings = VectorMenu[number - 1].structure;//������� ������ ��������� �� ������� ��������� �����
	bool check = false;
	for (string ing : ings)
	{
		for (WH wh : whs)
		{
			if (ing == wh.pr)
			{
				if (wh.quentity < quentity)
				{
					checkQuentity = false; // �������� �� ����������� ������
				}
				check = true;
			}
		}
		if (!check)
		{
			cout << "���������� ������������ ��� ������� �����" << endl;
			StartPageG();
		}
	}
	cout << "����� ��������" << endl;
	Item.quentity = quentity;
	cost = VectorMenu[number - 1].cost * quentity;

	cart.cost += cost;
	cart.prs.push_back(Item);
	StartPageG();
}

void giveOrder()
{
	int quent = 0;
	cout << "��� ����� ������� ���������" << endl;
	cout << "� ���� �������:" << endl;
	for (item it : cart.prs)
	{
		cout << it.pr << "\t� ����������: " << it.quentity << endl;
		quent = quent + it.quentity;
	}
	cout << "��� ��� �� �����: " << cart.cost << endl;
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
		this_thread::sleep_for(chrono::seconds(10)); // �������� 
		cout << "����� � ������� �� �����" << std::endl; // �������� ������������
	}
	
}

void Wait() {
	string s;
	thread newThread(Waits); // ������� ����� ����� � �������� � ���� ������� myFunction
	newThread.join(); // ����, ���� ����� ����� �������� ���� ������
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
