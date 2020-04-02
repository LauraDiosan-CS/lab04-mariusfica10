//clasa banca cu toate tipurile de constructori si operatori
#include "Bank.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;


//Desc: creeaza un obiect de tip cheltuiala bancara(Bank)
//In: -
//Out: o instanta a clasei cheltuiala bancara(Bank)
Bank::Bank()
{
	this->id = 0;
	this->day = 0;
	this->money = 0;
	this->type = NULL;
	this->desc = NULL;
}



//Desc: creeaza un obiect de tip cheltuiala bancar(Bank)
//In: id, int - id cheltuiala bancara
//	  zi, int - ziua in care a fost facuta cheltuiala bancara
//	  bani, int - bani pentru cheltuiala bancara
//    tip, char* - int/out din contul bancar
//	  desc, char* - descriere cheltuiala bancara 
//Out: o instanta a clasei cheltuiala bancara(Bank) cu atributele id,zi,bani,tip,descriere
Bank::Bank(int id, int day, int money, char* type, char* desc)
{
	this->id = id;

	this->day = day;

	this->money = money;

	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, 1 + strlen(type), type);

	this->desc = new char[strlen(desc) + 1];
	strcpy_s(this->desc, 1 + strlen(desc), desc);
}

//Desc: creeaza un obiect de tip Bank
//In: un obiect cheltuiala bancara(Bank)
//Out: o instanta a clasei cheltuiala bancara(Bank) cu atributele obiectului dat ca parametru
Bank::Bank(const Bank& b)
{
	this->id = b.id;

	this->day = b.day;

	this->money = b.money;

	this->type = new char[strlen(b.type) + 1];
	strcpy_s(this->type, 1 + strlen(b.type), b.type);

	this->desc = new char[strlen(b.desc) + 1];
	strcpy_s(this->desc, 1 + strlen(b.desc), b.desc);


}

//Desc: distruge un obiect de tip cheltuiala bancara(Bank)
//In: obiectul curent
//Out: 
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

//Desc: Acceseaza id-ul unei cheltuieli
//In: o cheltuiala
//Out: id-ul cheltuielii
int Bank::getID() {
	return this->id;
}

//Desc: Acceseaza ziua unei cheltuieli
//In: o cheltuiala
//Out: ziua cheltuielii
int Bank::getDay() {
	return this->day;
}

//Desc: Acceseaza banii alocati cheltuielii bancare
//In: o cheltuiala
//Out: banii alocati
int Bank::getMoney() {
	return this->money;
}

//Desc: Acceseaza tipul cheltuielii bancare(in/out)
//In: o cheltuiala
//Out: tipul acesteia
char* Bank::getType() {
	return this->type;
}
//Desc: Acceseaza descrierea cheltuielii bancare
//In: o cheltuiala
//Out: descrierea acesteia
char* Bank::getDesc() {
	return this->desc;
}

//Desc: schimba id-ul unei cheltuieli bancare
//In: o cheltuiala bancara si un id int
//Out: cheltuiala bancara cu id-ul schimbat
void Bank::setID(int id)
{
	this->id = id;
}

//Desc: schimba ziua unei cheltuieli bancare
//In: o cheltuiala bancara si o zi int
//Out: cheltuiala bancara cu zi schimbata
void Bank::setDay(int day)
{
	this->day = day;
}

//Desc: schimba banii alocati unei cheltuieli bancare
//In: o cheltuiala bancara si o suma de bani int
//Out: cheltuiala bancara cu suma de bani schimbata
void Bank::setMoney(int money)
{
	this->money = money;
}

//Desc: schimba tipul unei cheltuieli bancare
//In: o cheltuiala bancara si un tip char*
//Out: cheltuiala bancara cu tipul schimbat
void Bank::setType(char* type)
{
	if (this->type)
	{
		delete[] this->type;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

//Desc: schimba descrierea unei cheltuieli bancare
//In: o cheltuiala bancara si un descriere char*
//Out: cheltuiala bancara cu descriere schimbata
void Bank::setDesc(char* desc)
{
	if (this->desc)
	{
		delete[] this->desc;
	}
	this->desc = new char[strlen(desc) + 1];
	strcpy_s(this->desc, strlen(desc) + 1, desc);
}

//operator de copiere valoare
Bank& Bank::operator=(const Bank& b) {
	this->setID(b.id);
	this->setDay(b.day);
	this->setMoney(b.money);
	this->setDesc(b.desc);
	this->setType(b.type);
	return *this;
}

//desc: operator egalitate obiecte Bank
//in: const obiect de tip Bank
//out: true/false
bool Bank:: operator==(const Bank& b) {
	return strcmp(this->type, b.type) == 0 && strcmp(this->desc, b.desc) == 0 && this->day == b.day && this->money == b.money && this->id == b.id;
}

//desc: operator afisare obiect
//in: os, const obiect de tip Bank
//out: os
ostream& operator<<(ostream& os, const Bank& b)
{
	os << b.id << " " << b.day << " " << b.money << " " << b.type << " " << b.desc;
	return os;
}