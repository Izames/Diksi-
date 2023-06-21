#include "JsonSerDes.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>

using namespace nlohmann;



void to_json(json& j, const User& p) {
    j = json{ {"role", p.role}, {"surname", p.surname}, {"name", p.name}, {"thirdname", p.thirdname}, {"login", p.login}, {"password", p.password}};
}

void from_json(const json& j, User& p) {
    j.at("role").get_to(p.role);
    j.at("surname").get_to(p.surname);
    j.at("name").get_to(p.name);
    j.at("thirdname").get_to(p.thirdname);
    j.at("login").get_to(p.login);
    j.at("password").get_to(p.password);
}

list<User> Des()
{
    ifstream infile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\person.json");
    json j2;
    infile >> j2;
    list<User> persons2;
    for (const auto& it : j2) {
        User p;
        p.role = it["role"].get<string>();
        p.surname = it["surname"].get<string>();
        p.name = it["name"].get<string>();
        p.thirdname = it["thirdname"].get<string>();
        p.login = it["login"].get<string>();
        p.password = it["password"].get<string>();
        persons2.push_back(p);
    }
    return persons2;
}

void Ser(string role, string surname, string name, string thirdname, string login, string password)
{
    hash<string> hasher;
    size_t hash = hasher("password");
    int hashpassword;
    hashpassword = hash;

    list<User> persons = Des();
    persons.push_back({role, surname, name, thirdname, login, to_string(hashpassword)});
    // сериализация в JSON
    json j;
    for (const User& p : persons) 
    {
        j.push_back({ {"role", p.role}, {"surname", p.surname}, {"name", p.name}, {"thirdname", p.thirdname}, {"login", p.login}, {"password", p.password} });
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\person.json");
    outfile << j.dump(); 
}
