#pragma once

#include <string>
#include <iostream>
#include <list>
using namespace std;

struct MenuLi {
    string name;
    int gramm;
    list<string> structure;
    string info;
    string cookTime;
    double cost;
};
void MSer(string name, int gramm, list<string> structure, string info, string cookTime, double cost);
list<MenuLi> MDes();
void deleteMenu(int index);
