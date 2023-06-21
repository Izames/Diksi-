#include "storage.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include "AdminPage.h"
using namespace nlohmann;

void WHSer(string pr, int quentity, double cost)
{
    list<WH> prs = WHDes();
    prs.push_back({ pr, quentity, cost });
    // сериализация в JSON
    json j;
    for (const WH& p : prs)
    {
        j.push_back({ {"pr", p.pr}, {"quentity", p.quentity}, {"cost", p.cost}});
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\storage.json");
    outfile << j.dump();
}

list<WH> WHDes()
{
    ifstream infile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\storage.json");
    json j2;
    infile >> j2;
    list<WH> prs;
    for (const auto& it : j2) {
        WH p;
        p.pr = it["pr"].get<string>();
        p.quentity = it["quentity"].get<int>();
        p.cost = it["cost"].get<double>();
        prs.push_back(p);
    }
    return prs;
}

void updateWH(string pr, double cost, int quentity, bool plus) // в случае, если товар имеется, идет обращение к данной функции и ее изменение
{
    list<WH> prs = WHDes();
    for (WH pro : prs)
    {
        if (pro.pr == pr)
        {
            if (plus)
            {
                pro.quentity += quentity;
            }
            else 
            {
                pro.quentity -= quentity;
            }
            pro.cost = cost;
            break;
        }
    }
    json j;
    for (const WH& p : prs)
    {
        j.push_back({ {"pr", p.pr}, {"quentity", p.quentity}, {"cost", p.cost} });
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\storage.json");
    outfile << j.dump();
}

