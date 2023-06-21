#include "orders.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>

using namespace nlohmann;

void OSer(string status, list<string> Rorders)
{
    list<orders> listOrders = ODes();
    listOrders.push_back({ status, Rorders });
    // сериализация в JSON
    json j;
    for (const orders& p : listOrders)
    {
        json prs;
        for (const string& pr : p.Rorders)
        {
            prs.push_back(pr);
        }
        j.push_back({ {"status", p.status}, {"Rorders", p.Rorders} });
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\orders.json");
    outfile << j.dump(4);
}

list<orders> ODes()
{
    ifstream infile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\orders.json");
    json j2;
    infile >> j2;
    list<orders> orderes2;
    for (const auto& it : j2) {
        orders p;
        p.status = it["status"].get<string>();
        const auto& prs = it["Rorders"];
        for (const auto& pr : prs)
        {
            const string& pr_str = pr.get<string>();
            p.Rorders.push_back(pr_str);
        }
        orderes2.push_back(p);
    }
    return orderes2;
}

void updateO(string status)
{
    list<orders> listOrders = ODes();
    list<orders> listOrders2;
    for (orders ord : listOrders)
    {
        ord.status = status;
        listOrders2.push_back(ord);
    }
    json j;
    for (const orders& p : listOrders2)
    {
        json prs;
        for (const string& pr : p.Rorders)
        {
            prs.push_back(pr);
        }
        j.push_back({ {"status", p.status}, {"Rorders", p.Rorders} });
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\orders.json");
    outfile << j.dump(4);
}

void updateO1(string status, int index)
{
    list<orders> listOrders = ODes();
    list<orders> listOrders2;
    int counter = 0;
    for (orders ord : listOrders)
    {
        if (counter == index) 
        {
            ord.status = status;
            listOrders2.push_back(ord);
        }
    }
    json j;
    for (const orders& p : listOrders2)
    {
        json prs;
        for (const string& pr : p.Rorders)
        {
            prs.push_back(pr);
        }
        j.push_back({ {"status", p.status}, {"Rorders", p.Rorders} });
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\orders.json");
    outfile << j.dump(4);
}
