#include "Repo.h"
#include "Tests.h"
#include<assert.h>
#include<cstring>
#include<iostream>
using namespace std;
Repo r;


//testeaza luarea unei valori
void testGetter()
{
	//tests for all getters
	assert(r.getAll()[1].getDay() == 1);
	assert(r.getAll()[1].getMoney() == 1);
	assert(strcmp(r.getAll()[1].getDesc(), "nu") == 0);
	assert(strcmp(r.getAll()[1].getType(), "da") == 0);
	cout << "getters checked! ";
	cout << endl;
}

//testeaza setarea unei valori
void testSetter()
{
	Bank c(5, 5, (char*)"da", (char*)"nu");
	//tests for all setters
	r.getAll()[2].setMoney(25);
	r.getAll()[2].setDay(20);
	r.getAll()[2].setType((char*)"in");
	r.getAll()[2].setDesc((char*)"nu stiu");
	assert(r.getAll()[2].getMoney() == 25);
	assert(r.getAll()[2].getDay() == 20);
	assert(strcmp(r.getAll()[2].getDesc(), "nu stiu") == 0);
	assert(strcmp(r.getAll()[2].getType(), "in") == 0);
	cout << "setters checked! ";
	cout << endl;
}


//teste pentru adaugare de cheltuiala in repo
void testAdd()
{
	assert(r.getSize() == 0);
	Bank c(5, 5, (char*)"da", (char*)"nu");
	r.addBank(c);
	assert(r.getSize() == 1);
	cout << "add checked!";
	cout<<endl;

}


//constructori pentru operatiile din repository de stocare
void testRepo()
{
	assert(r.getSize() == 1);
	Bank* Banks;
	Bank a(1, 1, (char*)"da", (char*)"nu");
	Bank b(2, 2, (char*)"pizza", (char*)"poate");
	Bank d(3, 3, (char*)"mc", (char*)"sigur");
	r.addBank(a);
	r.addBank(b);
	r.addBank(d);
	Banks = r.getAll();
	assert(r.getSize() == 4);
	Bank b1;
	Bank b2;
	Bank b3;

	b1 = a;
	b2 = b;
	b3 = d;

	assert(Banks[1] == a);
	assert(Banks[2] == b);
	assert(Banks[3] == d);

	cout << "getAll&getSize checked !";
	cout << endl;

}

//teste pentru constructori si operatori
void testeConstructor()
{
	Bank g(10, 10, (char*)"mare", (char*)"mic");
	Bank g2 = g;
	Bank g3;
	g3 = g2;
	g == g2;
	assert(g2.getDay() == 10);
	assert(g3.getDay() == 10);

	cout << "constructor checked !";
	cout << endl;
}