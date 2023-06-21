#pragma once

#include <string>
#include <iostream>
#include <list>
using namespace std;

struct orders {
    string status;
    list<string> Rorders;
};
void OSer(string status, list<string> Rorders);
list<orders> ODes();
void updateO(string status);
void updateO1(string status, int index);