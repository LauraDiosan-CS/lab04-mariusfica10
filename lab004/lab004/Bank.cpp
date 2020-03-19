#include "Bank.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Bank::Bank()
{
	this->day = 0;
	this->money = 0;
	this->type = NULL;
	this->desc = NULL;
}

Bank::Bank(int day, int money, char* type, char* desc)
{
	this->day = day;

	this->money = money;
	
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, 1 + strlen(type), type);
	
	this->desc = new char[strlen(desc) + 1];
	strcpy_s(this->desc, 1 + strlen(desc), desc);
}

Bank::Bank(const Bank& b)
{
	this->day = b.day;
	
	this->money = b.money;

	this->type = new char[strlen(b.type) + 1];
	strcpy_s(this->type, 1 + strlen(b.type), b.type);

	this->desc = new char[strlen(b.desc) + 1];
	strcpy_s(this->desc, 1 + strlen(b.desc), b.desc);
	

}

Bank::~Bank()
{
	if (this->type)
	{
		delete[] this->type;
		this->type = NULL;
	}

	if (this->desc)
	{
		delete[] this->desc;
		this->desc = NULL;
	}
}

int Bank::getDay() {
	return this->day;
}

int Bank::getMoney() {
	return this->money;
}

char* Bank::getType() {
	return this->type;
}

char* Bank::getDesc() {
	return this->desc;
}

void Bank::setDay(int day)
{
	this->day = day;
}

void Bank::setMoney(int money)
{
	this->money = money;
}

void Bank::setType(char* type)
{
	if (this->type) {
		delete[] this->type;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

void Bank::setDesc(char* desc)
{
	if (this->desc) {
		delete[] this->desc;
	}
	this->desc = new char[strlen(desc) + 1];
	strcpy_s(this->desc, strlen(desc) + 1, desc);
}

Bank& Bank::operator=(const Bank& b) {
	this->setDay(b.day);
	this->setMoney(b.money);
	this->setDesc(b.desc);
	this->setType(b.type);
	return *this;
}

bool Bank:: operator==(const Bank& b) {
	return strcmp(this->type, b.type) == 0 && strcmp(this->desc, b.desc) == 0 &&  this->day == b.day && this->money == b.money;
}

ostream& operator<<(ostream& os, const Bank& b)
{
	os << b.day << " " << b.money << " " << b.type << " " << b.desc;
	return os;
}