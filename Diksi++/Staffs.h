#pragma once

#include <string>
#include <iostream>
#include <list>
using namespace std;

struct User {
    string role;
    string surname;
    string name;
    string thirdname;
    string login;
    string password;
};
void Ser(string role, string surname, string name, string thirdname, string login, string password);
list<User> Des();
void deleteStaff(int index);