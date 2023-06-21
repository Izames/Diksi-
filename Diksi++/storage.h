#pragma once

#include <string>
#include <iostream>
#include <list>
using namespace std;

struct WH {
    string pr;
    int quentity;
    double cost;
};
void WHSer(string pr, int quentity, double cost);
list<WH> WHDes();
void updateWH(string pr, double cost, int quentity, bool plus);
