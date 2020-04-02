#include "Service.h"
#include "Repo.h"


using namespace std;


//Desc: creeaza un obiect de tip Service
//In: -
//Out: o instanta a clasei Service
Service::Service()
{

}

//Desc: distruge un obiect de tip Service
//In: obiectul curent
//Out: -
Service::~Service()
{

}

//Desc: adauga o cheltuiala in repo
//In: atributele unui obiect id,day,money,type,desc
//Out: -
void Service::addBank(Bank& b)
{
	this->r.addBank(b);
}

//Desc: acceseaza lista de cheltuieli bancare a unui repo
//In: un obiect de tip service
//Out: lista de cheltuieli bancare
Bank* Service::getAll()
{
	return this->r.getAll();
}

//Desc: sterge o cheltuiala din repo, dupa id
//In: id de sters
//Out: -
void Service::deleteBank(int id)
{
	this->r.deleteBank(id);
}

//Desc:modifica o cheltuiala bancara dupa id dat
//In: int - id, id2,day, money
//	  char* -type,desc 
//Out: -
void Service::updateBank(int id, int day, int money, char* type, char* desc)
{
	Bank b(id, day, money, type, desc);
	this->r.updateBank(id, b);
}

//Desc: acceseaza lungimea listei de cheltuieli bancare unui repo din service
//In: un obiect de tip Service
//Out: lungimea listei de cheltuieli bancare 
int Service::getSize()
{
	return this->r.getSize();
}

//desc: filtare pentru afisare dupa o anumita proprietate
//in: banks, lista de obiecte bank
//    n, lungimea de obiecte din lista
//	  resultp[],lista in care se pun elem cu prop data
//    resultLen, lungimea listei cu elem care au prop data
//    sold,in,out,sum,day,comp, int ajuta la trecerea din comanda de tip string
//out: -
void Service::filterBank(Bank banks[], int n, Bank result[], int& resultLen, int sold, int in, int out , int sum, int day, int &dif, int comp)
{
	resultLen = 0;
	if (sold == 0 and in == 1 and out == 0 and sum == 0 and day == 0 and comp == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(banks[i].getType(), "in") == 0)
			{
				result[resultLen++] = banks[i];
			}
		}
	}
	if (sold == 1 and in == 0 and out == 0 and sum == 0 and day != 0 and comp == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (banks[i].getDay() == day)
			{
				result[resultLen++] = banks[i];
				if (strcmp(banks[i].getType(), "in") == 0)
				{
					dif += banks[i].getMoney();
				}
				if (strcmp(banks[i].getType(), "out") == 0)
				{
					dif += banks[i].getMoney();
				}
			}
		}
	}
	if (sold == 0 and in == 0 and out == 0 and sum == 1 and day == 0 and comp != 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (comp == 1)
			{
				if(banks[i].getMoney() < sum)
				result[resultLen++] = banks[i];
			}
			if (comp == 2)
			{
				if (banks[i].getMoney() == sum)
					result[resultLen++] = banks[i];
			}
			if (comp == 3)
			{
				if (banks[i].getMoney() > sum)
					result[resultLen++] = banks[i];
			}
		}
	}
}

/*
void Service::filterBankWithRepo(Repo repo, int n, Bank result[], int& resultLen, int sold, int in, int out, int sum, int day, int &dif, int comp)
{
	resultLen = 0;
	Bank* initialBanks = repo.getAll();
	return filterBank(initialBanks, n, result, resultLen,  sold,  in,  out,  sum,  day,  dif, comp);
}
*/

/*
desc: obtinere sum/max
in: banks[] lista obiecte, len lungime
    caz, ajuta la tranzitia dintre comanda string si program
	sum, rezultatul dupa functie
out:
*/
void Service::stats(Bank banks[], int len , int caz, int day, int& sum)
{
	if (caz == 1)
	{
		for (int i = 0; i < len; i++)
			if (strcmp(banks[i].getType(), "in") == 0)
				sum += banks[i].getMoney();

	}
	if (caz == 2)
	{
		for(int i=0;i<len; i++)
			if (strcmp(banks[i].getType(), "out") == 0)
			{
				if (banks[i].getMoney() > sum)
				{
					sum = banks[i].getMoney();
				}
			}
	}

}


