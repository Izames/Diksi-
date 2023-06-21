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
	cout << "�� ����� ��� �����" << endl;
	cout << "������ �������:" << endl;
	list<orders> ords = ODes();
	for (orders ord : ords)
	{
		cout << counter << ") ";
		cout  << "������ ����: ";
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
	cout << "������� ����� ������ � �������� ������ ����������, ��� �� 0 ��� ����������� �����: ";
	cin >> choice;
	try
	{
		num = stoi(choice);
	}
	catch (exception ex)
	{
		cout << "������� ������� ������" << endl;
		StartPageC();
	}
	if (num == 0)
	{
		//����������� �����
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
		cout << "����� �� ����������" << endl;
		StartPageC();
	}
	cout << "�������� �������" << endl;
	updateO1("cooking", dish);
	for (string ord : Vords[dish].Rorders)
	{
		punkts.push_back(ord);
	}
	for (string ord : punkts) // ������� ������� ����
	{
		for (MenuLi ml : mls) // �������� ���� ����
		{
			if (ml.name == ord)
			{
				for (string ing : ml.structure)// ��������� �����������
				{
					for (Product pr : prs)
					{
						if (pr.name == ing)
						{
							while (CookNotSucceful) // ��������� ����
							{
								cout << "������� - " << pr.id << endl;
								cin >> ScookNum;
								try
								{
									cookNum = stoi(ScookNum);
								}
								catch (exception ex)
								{
									cout << "�������� ������" << endl;
								}
								if (cookNum != pr.id)
								{
									cout << "�������� ��������! �� ����������" << endl;
								}
								else 
								{
									cout << "�����!" << endl;
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
	cout << "������� ���������!" << endl;
	updateO1("gived to waiter", dish);
	StartPageC();
}