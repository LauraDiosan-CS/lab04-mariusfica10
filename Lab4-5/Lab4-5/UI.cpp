#include "UI.h"
#include "Tools.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <time.h>
using namespace std;

UI::UI()
{
	this->undoList = new Service[100];
	this->size = 0;
}

UI::~UI()
{
}

void UI::printMenu()
{
	cout << "Selectare optiune: " << endl;
	cout << "1. Adaugare " << endl;
	cout << "2. Afisare toate" << endl;
	cout << "3. Afisare numar cheltuieli bancare" << endl;
	cout << "4. Stergeri/filtrari" << endl;
	cout << "5. Update dupa ID" << endl;
	cout << "6. Filtrare" << endl;
	cout << "7. Statistici" << endl;
	cout << "8. filtrari" << endl;
	cout << "9. Undo" << endl;
	cout << "10. exit" << endl;
	cout << endl;
}

void UI::add(Service& s)
{
	cout << "1. Adaugare cu toate atributele"<<endl;
	cout << "2. Adaugare fara id" << endl;
	cout << "3. Adaufare fara id si zi" << endl;
	char type[10];
	char desc[10];
	int day = {}, money = {}, id = {};

	char command[50];

	cin.getline(command, 50);
	cin.getline(command, 50);

	char* token = NULL;
	char* context = NULL;

	token = strtok_s(command, " ", &context);
	int i = 0;
	char* elem[10];
	while (token)
	{
		elem[i] = token;
		i++;
		token = strtok_s(NULL, " ", &context);
	}
	if (i == 5)
	{
		int unu = parseInt(elem[0]);
		int doi = parseInt(elem[1]);
		int trei = parseInt(elem[2]);
		char* patru = elem[3];
		char* cinci = elem[4];

		Bank b(unu, doi, trei, patru, cinci);
		s.addBank(b);

		
	}
	if (i == 4)
	{
		int	unu = rand() % 100 + 1;
		int doi = parseInt(elem[0]);
		int trei = parseInt(elem[1]);
		char* patru = elem[2];
		char* cinci = elem[3];

		Bank b(unu, doi, trei, patru, cinci);
		s.addBank(b);
		
	}
	if (i == 3)
	{
		int	unu = rand() % 100 + 1;
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		int Month = newtime.tm_mon - 1;
		int doi = Month;
		int trei = parseInt(elem[0]);
		char* patru = elem[1];
		char* cinci = elem[2];

		Bank b(unu, doi, trei, patru, cinci);
		s.addBank(b);
		
	}
}
void UI::getAll(Service& s)
{
	for (int i = 0; i < s.getSize(); i++)
	{
		cout << s.getAll()[i].getID() << " " << s.getAll()[i].getDay() << " " << s.getAll()[i].getMoney() << " " << s.getAll()[i].getType() << " " << s.getAll()[i].getDesc() << endl;
	}
	cout << endl;
}


void UI::getSize(Service& s)
{
	cout << s.getSize();
	cout << endl;
}

void UI::remove(Service& s)
{
	char command[50];
	
	cout << "1. stergere dupa ID" << endl << "2. stergere plati dupa zi" << endl << "3. stergere dupa interval de zile" << endl << "4. stergere dupa tip de plata in/out"<< endl;

	cin.getline(command, 50);

	cin.getline(command, 50);

	cout << endl;

	char* token = NULL;
	char* context = NULL;
	token = strtok_s(command, " ", &context);
	int i = 1;
	int ok = 0;
	int first;
	int last;
	int in = 0;
	int out = 0;
	while (token)
	{
		if (strcmp(token, "in") == 0 and i == 1)
		{
			for (int j = 0; j < s.getSize(); j++)
			{
				if (strcmp(s.getAll()[j].getType(), "in") == 0)
				{
					s.deleteBank(s.getAll()[j].getID());
				}
			}
			in = 1;
			break;
		}

		if (strcmp(token, "out") == 0 and i == 1)
		{
			for (int j = 0; j < s.getSize(); j++)
			{
				if (strcmp(s.getAll()[j].getType(), "out") == 0)
				{
					s.deleteBank(s.getAll()[j].getID());
				}
			}
			in = 1;
			break;
		}

		if (isdigit(token[0]) and ok == 0)
		{
			first = parseInt(token);
			ok = 1;
		}

		if (isdigit(token[0]) and ok == 1)
		{
			last = parseInt(token);
			ok = 2;
		}

		if (ok == 2)
		{
			for (int j = 0; j < s.getSize(); j++)
			{
				if (s.getAll()[j].getDay() <=  last and first <= s.getAll()[j].getDay())
				{
					s.deleteBank(s.getAll()[j].getID());
				}
			}
		}

		if (ok == 1)
		{
			s.deleteBank(s.getAll()[i].getID());
		}

		i++;
		token = strtok_s(NULL, " ", &context);
	}
	
	cout << endl;
	

}

void UI::update(Service& s)
{
	cout << "1. Update dupa toate atributele" << endl;
	cout << "2. Update fara id" << endl;
	cout << "3. Adaufare fara id si zi" << endl;
	char type[10];
	char desc[10];
	int day = {}, money = {}, id = {};

	char command[50];

	cin.getline(command, 50);
	cin.getline(command, 50);

	char* token = NULL;
	char* context = NULL;

	token = strtok_s(command, " ", &context);
	int i = 0;
	char* elem[10];
	while (token)
	{
		elem[i] = token;
		i++;
		token = strtok_s(NULL, " ", &context);
	}
	if (i == 5)
	{
		int unu = parseInt(elem[0]);
		int doi = parseInt(elem[1]);
		int trei = parseInt(elem[2]);
		char* patru = elem[3];
		char* cinci = elem[4];

		Bank b(unu, doi, trei, patru, cinci);
		s.addBank(b);
	}
	if (i == 4)
	{

		int doi = parseInt(elem[0]);
		int trei = parseInt(elem[1]);
		char* patru = elem[2];
		char* cinci = elem[3];
		int unu;
		for (int i = 0; i < s.getSize(); i++)
		{
			if (strcmp(s.getAll()[i].getType(), patru) == 0 and trei == s.getAll()[i].getMoney() and strcmp(s.getAll()[i].getDesc(), cinci) == 0 and doi == s.getAll()[i].getDay())
			{
				unu = s.getAll()[i].getID();
			}
		}
		Bank b(unu, doi, trei, patru, cinci);
		s.addBank(b);

	}
	if (i == 3)
	{
		int trei = parseInt(elem[0]);
		char* patru = elem[1];
		char* cinci = elem[2];
		int unu;
		int doi;
		for (int i = 0; i < s.getSize(); i++)
		{
			if (strcmp(s.getAll()[i].getType(), patru) == 0 and trei == s.getAll()[i].getMoney() and strcmp(s.getAll()[i].getDesc(), cinci) == 0)
			{
				unu = s.getAll()[i].getID();
				doi = s.getAll()[i].getDay();
			}
		}
		Bank b(unu, doi, trei, patru, cinci);
		s.addBank(b);

	}
}

void UI::filter(Service& s)
{
	int resultLen;
	char command[50];
	resultLen = 0;
	Bank result[5];
	Bank* initialBank = s.getAll();
	int len = s.getSize();
	
	cout << "1. filtru dupa tip(in/out)" << endl;
	cout << "2. </>/= suma de bani" << endl;
	cout << "3. sold ul unei zi" << endl ;

	cin.getline(command, 50); 
	cin.getline(command, 50);

	cout << endl;
	char* token = NULL;
	char* context = NULL;
	token = strtok_s(command, " ", &context);
	int sold = 0;
	int in = 0;
	int out = 0;
	int sum = 0; 
	int day = 0; 
	int dif = 0;
	int comp = 0;
	while (token)
	{
		if (strcmp(token, "sold") == 0)
		{
			sold = 1;
		}

		if (strcmp(token, "in") == 0)
		{
			in = 1;
		}

		if (strcmp(token, "out") == 0)
		{
			out = 1;
		}

		if (isdigit(token[0]))
		{
			sum = parseInt(token);
		}

		if (isdigit(token[0]) and sold!=0)
		{
			day = parseInt(token);
		}

		if (strcmp(token, "<") == 0)
		{
			comp = 1;
		}

		if (strcmp(token, "<") == 0)
		{
			comp = 2;
		}

		if (strcmp(token, "<") == 0)
		{
			comp = 3;
		}

		token = strtok_s(NULL, " ", &context);
	}

	s.filterBank(initialBank, len, result, resultLen, sold, in, out, sum, day, dif, comp);

	cout << endl;

	for (int i = 0; i < resultLen; i++)
		cout << result[i];

	cout << endl;

	if (dif != 0)
		cout << "sold: " << dif;
}



void UI::stats(Service& s)
{
	cout << "1. sum in" << endl;
	cout << "2. max out" << endl;
	char command[50];

	cin.getline(command, 50);

	cin.getline(command, 50);

	cout << endl;

	char* token = NULL;
	char* context = NULL;
	token = strtok_s(command, " ", &context);
	int ord = 0;
	int in = 0;
	int out = 0;
	int day = 0;
	int caz = 0;
	Bank* initialBank = s.getAll();
	int sum = 0;
	int	n = s.getSize();
	while (token)
	{
		if (strcmp(token, "sum") == 0)
			ord = 1;
		if (strcmp(token, "in") == 0)
			in = 1;
		if (strcmp(token, "out") == 0)
			out = 1;
		if (strcmp(token, "max") == 0)
			ord = 2;
		if (isdigit(token[0]))
			day = parseInt(token);

		token = strtok_s(NULL, " ", &context);
		
	}

	if (day != 0 and out != 0 and ord == 2)
		caz = 1;
	else
		caz = 2;

	s.stats(initialBank, n, caz, day, sum);

	cout << sum << endl;
}

void UI::filter2(Service& s)
{
	cout << "1. Pastreaza tranzactii de tip in"<< endl;
	cout << "2. Pastrare tranzactii de tip in sub valoare" << endl;
	char command[50];

	cin.getline(command, 50);

	cin.getline(command, 50);

	cout << endl;

	char* token = NULL;
	char* context = NULL;
	token = strtok_s(command, " ", &context);
	int in = 0;
	int out = 0;
	int sum = 0;
	while (token)
	{
		if (strcmp(token, "in") == 0)
			in = 1;

		if (strcmp(token, "in") == 0)
			out = 1;

		if (isdigit(token[0]))
			 sum = parseInt(token);

		token = strtok_s(NULL, " ", &context);
	}
	int caz = 0;
	if (in == 1 and sum == 0)
	{
		for (int j = 0; j < s.getSize(); j++)
		{
			if (strcmp(s.getAll()[j].getType(), "in") != 0)
			{
				s.deleteBank(s.getAll()[j].getID());
			}
		}
	}
	if (in == 1 and sum != 0)
	{
		for (int j = 0; j < s.getSize(); j++)
		{
			if (strcmp(s.getAll()[j].getType(), "in") == 0)
			{
				{
					if(s.getAll()[j].getMoney() > sum)
					s.deleteBank(s.getAll()[j].getID());
				}
			}
		}
	}
	if (out == 1 and sum == 0)
	{
		for (int j = 0; j < s.getSize(); j++)
		{
			if (strcmp(s.getAll()[j].getType(), "out") != 0)
			{
				s.deleteBank(s.getAll()[j].getID());
			}
		}
	}
	if (out == 1 and sum != 0)
	{
		for (int j = 0; j < s.getSize(); j++)
		{
			if (strcmp(s.getAll()[j].getType(), "out") == 0)
			{
				{
					if (s.getAll()[j].getMoney() > sum)
						s.deleteBank(s.getAll()[j].getID());
				}
			}
		}
	}
	
}
