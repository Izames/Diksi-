#include "request.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>

using namespace nlohmann;

void RSer(string pr, int quentity, double cost, bool status)
{
    list<req> prs = RDes();
    prs.push_back({ pr, quentity, cost });
    // сериализация в JSON
    json j;
    for (const req& p : prs)
    {
        j.push_back({ {"pr", p.pr}, {"quentity", p.quentity}, {"cost", p.cost}, {"status", p.status}});
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\request.json");
    outfile << j.dump();
}

list<req> RDes()
{
    ifstream infile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\request.json");
    json j2;
    infile >> j2;
    list<req> prs;
    for (const auto& it : j2) {
        req p;
        p.pr = it["pr"].get<string>();
        p.quentity = it["quentity"].get<int>();
        p.cost = it["cost"].get<double>();
        p.status = it["status"].get<bool>();
        prs.push_back(p);
    }
    return prs;
}

void updateR() // заявки и поставки
{
    list<req> reqs = RDes();
    list<req> reqs2;
    for (req r : reqs)
    {
        r.status = true;
        reqs2.push_back(r);
    }
    json j;
    for (const req& p : reqs2)
    {
        j.push_back({ {"pr", p.pr}, {"quentity", p.quentity}, {"cost", p.cost}, {"status", p.status} });
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\request.json");
    outfile << j.dump();
}
