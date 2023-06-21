#include "Menu.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include "AdminPage.h"

using namespace nlohmann;
using json = nlohmann::json;





void MSer(string name, int gramm, list<string> structure, string info, string cookTime, double cost)
{
    list<MenuLi> menus = MDes();
    menus.push_back({ name, gramm, structure, info, cookTime, cost }) ;
    // сериализация в JSON
    json j;
    for (const MenuLi& p : menus)
    {
        json ingridients;
        for ( const string& ingridient : p.structure)
        {
            ingridients.push_back(ingridient);
        }
        j.push_back({ {"name", p.name}, {"gramm", p.gramm}, {"structure", ingridients}, {"info", p.info}, {"cookTime", p.cookTime}, {"cost", p.cost} });
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\menu.json");
    outfile << j.dump(4);
}
list<MenuLi> MDes()
{
    ifstream infile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\menu.json");
    json j2;
    infile >> j2;
    list<MenuLi> menus2;
    for (const auto& it : j2) {
        MenuLi p;
        p.name = it["name"].get<string>();
        p.gramm = it["gramm"].get<int>();
        const auto& ingridients = it["structure"];
        for (const auto& ingridient : ingridients)
        {
            const string& ing_str = ingridient.get<string>();
            p.structure.push_back(ing_str);
        }
        p.info = it["info"].get<string>();
        p.cookTime = it["cookTime"].get<string>();
        p.cost = it["cost"].get<double>();
        menus2.push_back(p);
    }
    return menus2;
}

void deleteMenu(int index)
{
    string choice;
    vector<MenuLi> Ulist;
    list<MenuLi> Ulist1 = MDes();
    list<MenuLi> Ulist2;
    for (MenuLi users : Ulist1)
    {
        Ulist.push_back(users);
    }
    try
    {
        Ulist.erase(Ulist.begin() + (index - 1));
        for (MenuLi x : Ulist)
        {
            Ulist2.push_back(x);
        }
        json j;
        for (const MenuLi& p : Ulist2)
        {
            j.push_back({ {"name", p.name}, {"gramm", p.gramm}, {"structure", p.structure}, {"info", p.info}, {"cookTime", p.cookTime}, {"cost", p.cost} });
        }
        std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\menu.json");
        outfile << j.dump();
    }
    catch (exception ex)
    {
        cout << "Ошибка!" << endl;
        DeleteM();
    }
    cout << "введите 1 чтобы удалить еще одного, или нажмите enter: ";
    std::cin >> choice;
    if (choice == "1")
    {
        DeleteM();
    }
    else
    {
        WorkWithMenu();
    }
}
