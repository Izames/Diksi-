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
	cout << "�� ����� ��� ���������" << endl;
	cout << "1: ���������� ������" << endl;
	cout << "2: ���������� �������� ������" << endl;
	cout << "3: ���������� �������" << endl;
	cout << "4: ��������� �����" << endl;
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
			//��������� �����
		}
	}
	else
	{
		cout << "������� �������� ������" << endl;
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
			cout << "�������: " << r.pr << "\t����������: " << r.quentity << "\t���������: " << r.cost << endl;

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
			cout << "�������: " << r.pr << "\t����������: " << r.quentity << "\t���������: " << r.cost << endl;

		}
	}
	StartPageB();
}
void ViewF()
{
	finances fncs = FDes();
	cout << "������: " << fncs.budget << "\t���������� ��������� ���������: " << fncs.sell_pr << "\t���������� ����� ���������: " << fncs.summ_sell_pr << "\t���������: " << fncs.spent << endl;
	StartPageB();
}