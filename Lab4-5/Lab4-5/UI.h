#pragma once
#include "Bank.h"
#include "Repo.h"
#include "Service.h"

class UI
{
private:
	Service s;
	Service* undoList;
	int size;
public:
	UI();
	~UI();
	void printMenu();
	void add(Service& s);
	void getAll(Service& s);
	void getSize(Service& s);
	void remove(Service& s);
	void update(Service& s);
	void removeUpgrade(Service& s);
	void filter(Service& s);
	void stats(Service& s);
	void filter2(Service& s);
	
};