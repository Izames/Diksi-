#pragma once

#include <string>
#include <iostream>
#include <list>
using namespace std;

struct finances {
    double budget;
    double summ_sell_pr;
    int sell_pr;
    double spent;
};
void FSer(double budget, double summ_sell_pr, int sell_pr, double spent);
finances FDes();
