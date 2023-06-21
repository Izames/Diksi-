#pragma once

#include <string>
#include <iostream>
#include <list>
using namespace std;

struct Product {
    int id;
    string name;
    double cost;
};
void PSer(int id, string name, double cost);
list<Product> PDes();
void deleteProducts(int index);
