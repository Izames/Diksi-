#include "waiter.h"
#include <iostream>
#include "orders.h"
using namespace std;

void StartPageW()
{
	string choice;
	cout << "�� ����� ��� ��������" << endl;
	cout << "������ �������:" << endl;
	list<orders> ords = ODes();
	for (orders ord : ords)
	{
		cout << "\t������ �������: ";
		if (ord.status == "gived to waiter")
		{
			for (string pr : ord.Rorders)
			{
				cout << pr << " ";
			}
			cout << endl;
		}
	}
	cout << "������� 1 ����� �������� �� ������, ��� 2, ����� ��������� � ���� �����������" << endl;
	cin >> choice;
	if (choice == "1" || choice == "2")
	{
		if (choice == "1")
		{
			updateO("ready");
			StartPageW();
		}
		else
		{
			//����������� �� �����������
		}
	}
	else
	{
		StartPageW();
	}
}
