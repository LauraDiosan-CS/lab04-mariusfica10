#include "Service.h"
#include <cstddef>
#include <string.h>
#include <iostream>
#include <ostream>

using namespace std;

Service::Service()
{

}

Service::~Service()
{

}

void Service::addBank(int id,int day, int money, char* type, char* desc)
{
	Bank b(id, day, money, type, desc);
	this->r.addBank(b);
}

Bank* Service::getAll()
{
	return this->r.getAll();
}

void Service::deleteBank(int id)
{
	this->r.deleteBank(id);
}

void Service::updateBank(int id, int id2, int day, int money, char* type, char* desc)
{
	Bank b(id, day, money, type, desc);
	this->r.updateBank(id2, b);
}

int Service::getSize()
{
	return this->r.getSize();
}