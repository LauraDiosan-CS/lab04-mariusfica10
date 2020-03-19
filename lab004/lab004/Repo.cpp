#include "Repo.h"

Repo::Repo() 
{
	this->n = 0;
}
Repo::~Repo() 
{
	this->n = 0;
}
void Repo::addBank(Bank b) 
{
	this->Banks[this->n++] = b;
}

Bank* Repo::getAll() 
{
	return this->Banks;
}

int Repo::getSize()
{
	return this->n;
}