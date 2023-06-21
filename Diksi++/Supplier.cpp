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
	cout << "�� ����� ��� ���������" << endl;
	cout << "1: ���������� ������" << endl;
	cout << "2: �������� ��� ������" << endl;
	cout << "3: �����" << endl;
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
			//��������� �����
		}
	}
	else
	{
		cout << "������� �������� ������" << endl;
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
			cout << "�������: " << r.pr << "\t����������: " << r.quentity << "\t���������: " << r.cost << endl;
		}
	}
	StartPageS();
}
void AcceptRq()
{
	int minusBudget = 0;
	int selled = 0;
	updateR();
	cout << "��� ������ ��������!" << endl;
	list<WH> whO = WHDes(); //������������ ������ ������
	list<WH> wh; // ��������� ������ ������
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