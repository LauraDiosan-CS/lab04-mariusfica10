#include <iostream>
#include "Bank.h"
#include "Repo.h"
#include "Tests.h"
#include "Service.h"
#include "UI.h"
#include <cstring>
using namespace std;

//desc: functia principala cu functionalitatile cheltuielilor bancare
//in: - 
//out: 0
int main()
{
	
	testAdd();
	testRepo();
	testeConstructor();
	testGetter();
	testSetter();
	testService();
	
	cout << endl << endl << endl;

	int ok = 1;
	int option;
	Service ser;
	UI ui;
	while (ok == 1)
	{

		ui.printMenu();
		cin >> option;
		if (option == 1)
		{
			ui.add(ser);

		}
		if (option == 2)
		{
			ui.getAll(ser);
		}

		if (option == 3)
		{
			ui.getSize(ser);
		}
		/*
		nu face parte din lab 4
		if (option == 5)
		{
			int resultLen;

			resultLen = 0;
			Bank result[5];
			Bank* initialBank = r.getAll();
			int len = r.getSize();
			filterBank(initialBank, len, result, resultLen);

			for (int i = 0; i < resultLen; i++)
				cout << result[i];

		}
		*/

		if (option == 4)
		{
			ui.remove(ser);
		}
		if (option == 5)
		{
			ui.update(ser);
		}
		if (option == 6)
		{
			ui.filter(ser);
		}
		if (option == 7)
		{
			ui.stats(ser);
		}
		if (option == 8)
		{
			ui.filter2(ser);
		}
		if (option == 9)
		{
			cout << ":'( ";
		}
		if (option == 10)
			ok = 0;


	}
	return 0;
}