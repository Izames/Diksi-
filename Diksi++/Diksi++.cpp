#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <functional>
#include <stdlib.h>
#include <list>
#include <vector>

#include "Menu.h"
#include"Staffs.h"
#include "GuestPage.h"
#include "AdminPage.h"
#include "WHManager.h"
#include "Supplier.h"
#include "buhgalter.h"
#include "chef.h"
#include "waiter.h"
#include "request.h"

void authorizate();
void guest();
int main() 
{ 
    SetConsoleCP(1251);
    setlocale(0, "");
    string choose = "";
    cout << "Добро пожаловать в Дикси-Ресторан. Для начала выберите:\n1:Авторизация\n2:Войти как гость" << endl;
    cin >> choose;
    if (choose != "1" && choose != "2") 
    {
        cout << "Введено неверное значение!" << endl;
        main();
    }
    else
    {
        if (choose == "1") 
        {
            authorizate();
        }
        else 
        {
            guest();
        }
    }
    
    // Чтение JSON из файла и десериализация в объект Person


}
void authorizate()
{

    string login;
    string password;
    system("cls");
    cout << "Вы в окне авторизации!" << endl;
    cout << "введите логин: ";
    cin >> login;
    cout << "введите пароль: ";
    cin >> password;
    hash<string> hasher;
    size_t hash = hasher(password);
    int hashpassword;
    hashpassword = hash;
    string Hpassword = to_string(hashpassword);
    list<User> accounts = Des();
    for (User pers : accounts)
    {
        if (login == pers.login && Hpassword == pers.password) 
        {
            if (pers.role == "Admin") 
            {
                StartPage();
                main();
            }
            else if (pers.role == "warehouse")
            {
                StartPageWH();
                main();
            }
            else if (pers.role == "provider")
            {
                StartPageS();
                main();
            }
            else if (pers.role == "buhgalter")
            {
                StartPageB();
                main();
            }
            else if (pers.role == "cooker")
            {
                StartPageC();
                main();
            }
            else if (pers.role == "waiter")
            {
                StartPageW();
                main();
            }
        }
    }
    main();
}
void guest()
{
    StartPageG();
    main();
}

