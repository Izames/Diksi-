#pragma once

#include <string>
#include <iostream>
#include <list>
using namespace std;

struct req {
    string pr;
    int quentity;
    double cost;
    bool status;
};
void RSer(string pr, int quentity, double cost, bool status);
list<req> RDes();
void updateR();
