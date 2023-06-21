#include "Supplier.h"
#include <iostream>
#include <list>
#include "request.h"
#include "storage.h";
#include "finance.h"
using namespace std;
void ViewRq();
void AcceptRq();
void StartPageS()
{
	string choice;
	cout << "¬ы вошли как поставщик" << endl;
	cout << "1: посмотреть за€вки" << endl;
	cout << "2: одобрить все за€вки" << endl;
	cout << "3: назад" << endl;
	cin >> choice;
	if (choice == "1" || choice == "2" || choice == "3")
	{
		if (choice == "1")
		{
			ViewRq();
		}
		else if (choice == "2")
		{
			AcceptRq();
		}
		else
		{
			//вернутьс€ назад
		}
	}
	else
	{
		cout << "введены неверные данные" << endl;
		StartPageS();
	}
}
void ViewRq()
{
	list<req> reqs = RDes();
	for (req r : reqs)
	{
		if (r.status == false)
		{
			cout << "продукт: " << r.pr << "\tколичество: " << r.quentity << "\tстоимость: " << r.cost << endl;
		}
	}
	StartPageS();
}
void AcceptRq()
{
	int minusBudget = 0;
	int selled = 0;
	updateR();
	cout << "все за€вки одобрены!" << endl;
	list<WH> whO = WHDes(); //существующий список склада
	list<WH> wh; // временный список склада
	WH x;
	
	list<req> reqs = RDes();
	for (req r : reqs)
	{
		x.cost = r.cost / r.quentity;
		x.pr = r.pr;
		x.quentity = r.quentity;
		wh.push_back(x);
		minusBudget = minusBudget + r.cost;
		selled = selled + x.quentity;
	}
	finances fin = FDes();
	fin.budget = fin.budget - minusBudget;
	fin.sell_pr = selled;
	fin.spent = fin.spent + minusBudget;
	FSer(fin.budget, fin.summ_sell_pr, fin.sell_pr, fin.spent);
	bool check = false;
	for (WH w : wh)
	{
		for (WH i : whO)
		{
			if (w.pr == i.pr) 
			{
				check = true;
			}
		}
		if (check)
		{
			updateWH(w.pr, w.cost, w.quentity, true);
		}
		else
		{
			WHSer(w.pr, w.quentity, w.cost);
		}
		check = false;
	}
	
	StartPageS();
}