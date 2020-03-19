#include "Repo.h"
#include "Tests.h"
#include<assert.h>
#include<iostream>
Repo r;

void testGetter()
{
	assert(r.getAll()[1].getDay() == 1);
	cout << "getter checked! ";
	cout << endl;
}

void testSetter()
{
	Bank c(5, 5, (char*)"da", (char*)"nu");
	r.getAll()[2].setMoney(25);
	assert(r.getAll()[2].getMoney() == 25);
	cout << "setter checked! ";
	cout << endl;
}

void testAdd()
{
	assert(r.getSize() == 0);
	Bank c(5, 5, (char*)"da", (char*)"nu");
	r.addBank(c);
	assert(r.getSize() == 1);
	cout << "add checked!";
	cout<<endl;

}

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

void testeConstructor()
{
	Bank g(10, 10, (char*)"mare", (char*)"mic");
	Bank g2 = g;
	Bank g3;
	g3 = g2;
	g == g2;
	cout << "constructor checked !";
	cout << endl;
}