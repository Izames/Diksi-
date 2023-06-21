#include "finance.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

using namespace nlohmann;


void to_json(nlohmann::json& j, const finances& p) {
    j = nlohmann::json{ {"budget", p.budget}, {"sell_pr", p.sell_pr}, {"spent", p.spent}, {"summ_sell_pr", p.summ_sell_pr}};
}

void from_json(const json& j, finances& p) {
    j.at("budget").get_to(p.budget);
    j.at("sell_pr").get_to(p.sell_pr);
    j.at("spent").get_to(p.spent);
    j.at("summ_sell_pr").get_to(p.summ_sell_pr);
}

void FSer(double budget, double summ_sell_pr, int sell_pr, double spent)
{
    finances p =  { budget, summ_sell_pr, sell_pr, spent };
    // сериализация в JSON
    json j = p;
    string jstr = j.dump();
    ofstream file("C:\\Users\\geday\\OneDrive\\Рабочий стол\\finances.json");
    file << jstr;
}

finances FDes()
{
    ifstream file2("C:\\Users\\geday\\OneDrive\\Рабочий стол\\finances.json");
    json j2;
    file2 >> j2;
    file2.close();

    finances p2 = j2.get<finances>();

    return p2;
}
