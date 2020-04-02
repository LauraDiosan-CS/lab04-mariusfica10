#include "Repo.h"
//clasa repository


//Desc: creeaza un obiect de tip Repo
//In: -
//Out: o instanta a clasei Repo
Repo::Repo()
{
	this->n = 0;
}

//Desc: distruge un obiect de tip Repo
//In: obiectul curent
//Out: -
Repo::~Repo()
{
	this->n = 0;
}

//Desc: adauga o cheltuiala bancara in Repo
//In: un obiect b de tip Bank
//Out: -
void Repo::addBank(Bank b)
{
	this->Banks[this->n++] = b;
}

//Desc: sterge o cheltuiala Bancara(Bank) din Repo
//In: un obiect b de tip Bank
//Out: -
void Repo::deleteBank(int nr)
{
	for (int i = 0; i < n; i++)
		if (this->Banks[i].getID() == nr)
			for (int k = i; k < n - 1; k++)
				this->Banks[k] = this->Banks[k + 1];
	this->n--;
}


void Repo::updateBank(int nr, Bank b)
{
	for (int i = 0; i < n; i++)
		if (this->Banks[i].getID() == nr)
			this->Banks[i] = b;
}



//Desc: acceseaza lista de cheltuieli bancare a unui repo
//In: un obiect de tip repo
//Out: lista de cheltuieli bancare
Bank* Repo::getAll()
{
	return this->Banks;
}

//Desc: acceseaza lungimea listei de cheltuieli unui repo
//In: un obiect de tip repo
//Out: lungimea listei de cheltuieli bancare 
int Repo::getSize()
{
	return this->n;
}