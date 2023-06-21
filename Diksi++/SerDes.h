#pragma once
#include <string>
using namespace std;
class SerDes 
{
	public:
		void ser(string role, string surname, string name, string thirdname, string login, string password);
		void des();

};
