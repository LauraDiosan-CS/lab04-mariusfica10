#include "Repo.h"
#include "Tests.h"
#include "Service.h"
#include<assert.h>
#include<cstring>
#include<iostream>
using namespace std;
Repo r;
Service s;

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
	Bank c(1, 5, 5, (char*)"da", (char*)"nu");
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
	Bank c(2, 5, 5, (char*)"da", (char*)"nu");
	r.addBank(c);
	assert(r.getSize() == 1);
	cout << "add checked!";
	cout << endl;

}


//constructori pentru operatiile din repository de stocare
void testRepo()
{
	assert(r.getSize() == 1);
	Bank* Banks;
	Bank a(3, 1, 1, (char*)"da", (char*)"nu");
	Bank b(4, 2, 2, (char*)"pizza", (char*)"poate");
	Bank d(5, 3, 3, (char*)"mc", (char*)"sigur");
	//add
	r.addBank(a);
	r.addBank(b);
	r.addBank(d);
	//read
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
	//delete
	r.deleteBank(4);

	assert(r.getSize() == 3);

	char* tip1 = new char[10];
	char* desc1 = new char[10];

	char* tip2 = new char[10];
	char* desc2 = new char[10];

	strcpy_s(tip1, sizeof "dada", "dada");
	strcpy_s(desc1, sizeof "nunu", "nunu");

	strcpy_s(tip2, sizeof "dadada", "dadada");
	strcpy_s(desc2, sizeof "nununu", "nununu");

	Bank b6(12, 12, 12, tip1, desc1);
	Bank b7(12, 12, 12, tip2, desc2);
	// update
	r.addBank(b6);

	r.updateBank(12, b7);

	assert(r.getAll()[3] == b7);

	cout << "Repository checked !";
	cout << endl;

}

//teste pentru constructori si operatori
void testeConstructor()
{
	Bank g(6, 10, 10, (char*)"mare", (char*)"mic");
	Bank g2 = g;
	Bank g3;
	g3 = g2;
	g == g2;
	assert(g2.getDay() == 10);
	assert(g3.getDay() == 10);

	cout << "Constructor checked !";
	cout << endl;
}

void testService()
{
	Bank a(10, 10, 10, (char*)"nu", (char*)"mare");
	s.addBank(a);
	s.updateBank(10, 11, 11, (char*)"nu", (char*)"mare");
	assert(s.getAll()[0].getMoney() == 11);
	assert(s.getAll()[0].getMoney() == 11);
	s.deleteBank(10);
	assert(s.getSize() == 0);
	cout << "Service checked! "<<endl;

}