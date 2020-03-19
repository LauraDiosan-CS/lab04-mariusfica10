#include <iostream>
#include "Bank.h"
#include "Repo.h"
#include "Tests.h"
using namespace std;

void menu()
{
	cout << "Select option: " << endl;
	cout << "1. Adauga cheltuiala " << endl;
	cout << "2. Afisare cheltuieli" << endl;
	cout << "3. Afisati numar de cheltuieli" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
}

int main()
{
	testAdd();
	testRepo();
	testeConstructor();
	testGetter();
	testSetter();
	char type[10];
	char desc[10];
	int day = {}, money = {};
	int ok = 1;
	Repo r;
	while (ok == 1)
	{

		menu();

		int option;

		cin >> option;
		if (option == 1)
		{
			cout << "Introduceti ziua: ";
			cin >> day;
			cout << "Introduceti suma de bani: ";
			cin >> money;
			cout << "Introduceti tipul de cheltuiala:  ";
			cin >> type;
			cout << "Introduceti descrierea: ";
			cin >> desc;
			cout << endl;

			Bank g(day, money, type, desc);
			r.addBank(g);

			cout << endl;

		}
		if (option == 2)
		{
			for (int i = 0; i < r.getSize(); i++)
			{
				cout << r.getAll()[i].getDay() << " " << r.getAll()[i].getMoney() << " " << r.getAll()[i].getType() << " " << r.getAll()[i].getDesc()<<endl;
			}
			cout << endl;

		}

		if (option == 3)
		{
			cout << "Numarul de cheltuieli este " << r.getSize() << endl;
			cout << endl;

			cout << endl;
		}

		if (option == 4)
			ok = 0;

	}
	
}