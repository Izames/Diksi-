#include "waiter.h"
#include <iostream>
#include "orders.h"
using namespace std;

void StartPageW()
{
	string choice;
	cout << "вы вошли как официант" << endl;
	cout << "список заказов:" << endl;
	list<orders> ords = ODes();
	for (orders ord : ords)
	{
		cout << "\tсписок заказов: ";
		if (ord.status == "gived to waiter")
		{
			for (string pr : ord.Rorders)
			{
				cout << pr << " ";
			}
			cout << endl;
		}
	}
	cout << "введите 1 чтобы передать их повару, или 2, чтобы вернуться в окно регистрации" << endl;
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
			//возвращение на регистрацию
		}
	}
	else
	{
		StartPageW();
	}
}
