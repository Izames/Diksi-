#include "Products.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include "AdminPage.h"

using namespace nlohmann;

void to_json(json& j, const Product& p) {
    j = json{ {"id", p.id}, {"name", p.name}, {"cost", p.cost}};
}

void from_json(const json& j, Product& p) {
    j.at("id").get_to(p.id);
    j.at("name").get_to(p.name);
    j.at("cost").get_to(p.cost);
}

list<Product> PDes()
{
    ifstream infile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\product.json");
    json j2;
    infile >> j2;
    list<Product> products2;
    for (const auto& it : j2) {
        Product p;
        p.id = it["id"].get<int>();
        p.name = it["name"].get<string>();
        p.cost = it["cost"].get<double>();
        products2.push_back(p);
    }
    return products2;
}

void deleteProducts(int index)
{
    string choice;
    vector<Product> Ulist;
    list<Product> Ulist1 = PDes();
    list<Product> Ulist2;
    for (Product pr : Ulist1)
    {
        Ulist.push_back(pr);
    }
    try
    {
        Ulist.erase(Ulist.begin() + (index - 1));
        for (Product x : Ulist)
        {
            Ulist2.push_back(x);
        }
        json j;
        for (const Product& p : Ulist2)
        {
            j.push_back({ {"id", p.id}, {"name", p.name}, {"cost", p.cost} });
        }
        std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\product.json");
        outfile << j.dump();
    }
    catch (exception ex)
    {
        cout << "Ошибка!" << endl;
        DeletePR();
    }
    cout << "введите 1 чтобы удалить еще одного, или нажмите enter: ";
    std::cin >> choice;
    if (choice == "1")
    {
        DeletePR();
    }
    else
    {
        WorkWithPR();
    }
}

void PSer(int id, string name, double cost)
{
    list<Product> products = PDes();
    products.push_back({ id, name, cost});
    // сериализация в JSON
    json j;
    for (const Product& p : products)
    {
        j.push_back({ {"id", p.id}, {"name", p.name}, {"cost", p.cost} });
    }
    std::ofstream outfile("C:\\Users\\geday\\OneDrive\\Рабочий стол\\product.json");
    outfile << j.dump();
}
