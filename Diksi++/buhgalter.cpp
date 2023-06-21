#include "buhgalter.h"
#include <iostream>
#include <list>
#include "request.h"
#include "finance.h"

using namespace std;

void BViewRq();
void ViewARq();
void ViewF();

void StartPageB()
{
	string choice;
	cout << "вы вошли как бухгалтер" << endl;
	cout << "1: посмотреть заявки" << endl;
	cout << "2: посмотреть принятые заявки" << endl;
	cout << "3: посмотреть финансы" << endl;
	cout << "4: вернуться назад" << endl;
	cin >> choice;
	if (choice == "1" || choice == "2" || choice == "3" || choice == "4")
	{
		if (choice == "1")
		{
			BViewRq();
		}
		else if (choice == "2")
		{
			ViewARq();
		}
		else if (choice == "3")
		{
			ViewF();
		}
		else
		{
			//вернуться назад
		}
	}
	else
	{
		cout << "введены неверные данные" << endl;
		StartPageB();
	}
}

void BViewRq()
{
	list<req> reqs = RDes();
	for (req r : reqs)
	{
		if (r.status == false)
		{
			cout << "продукт: " << r.pr << "\tколичество: " << r.quentity << "\tстоимость: " << r.cost << endl;

		}
	}
	StartPageB();
}
void ViewARq()
{
	list<req> reqs = RDes();
	for (req r : reqs)
	{
		if (r.status == true)
		{
			cout << "продукт: " << r.pr << "\tколичество: " << r.quentity << "\tстоимость: " << r.cost << endl;

		}
	}
	StartPageB();
}
void ViewF()
{
	finances fncs = FDes();
	cout << "бюджет: " << fncs.budget << "\tколичество проданных продуктов: " << fncs.sell_pr << "\tполученная сумма продуктов: " << fncs.summ_sell_pr << "\tпотрачено: " << fncs.spent << endl;
	StartPageB();
}