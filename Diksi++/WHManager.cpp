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
	cout << "�� ����� ��� ��������� ��������" << endl;
	cout << "�������� ��������" << endl;
	cout << "1: ���������� ������ ��������� �� ������" << endl;
	cout << "2: ������� ������ �� ��������" << endl;
	cout << "3: �����" << endl;
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
			//����������� � ������� ����
		}
	}
	else
	{
		cout << "�������� ��������" << endl;
		StartPageWH();
	}
}
void ViewPr()
{
	list<WH> products = WHDes();
	for (WH pr : products)
	{
		cout << "�������: " << pr.pr << "\t ����������: " << pr.quentity << "\t��������� ������� ���� �� �����: " << pr.cost << endl;
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
	cout << "������� ������ ��� ������" << endl;
	cout << "�������� ����� ��������" << endl;
	list<Product> prs = PDes();
	for (Product pr : prs)
	{
		cout << pr.id << ") ������������ ��������: " << pr.name << "\t���� �� �����: " << pr.cost << endl;
	}
	cout << "�����: ";
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
			cout << "�� ������ �������" << endl;
			StartPageWH();
		}
	}
	catch (exception ex)
	{
		cout << "������� ������� ������" << endl;
		StartPageWH();
	}
	cout << "������� ����������: ";
	std::cin >> Scount;
	try
	{
		quentity = stoi(Scount);
	}
	catch (exception ex)
	{
		cout << "������� ������� ������" << endl;
		StartPageWH();
	}
	cost = cost * quentity;
	finances bud = FDes();
	if (bud.budget >= cost)
	{
		RSer(name, quentity, cost, false);
		cout << "������ �������!" << endl;
		StartPageWH();
	}
	else
	{
		cout << "������������ �������" << endl;
		StartPageWH();
	}
	
}