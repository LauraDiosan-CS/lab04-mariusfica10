#pragma once
#include "Bank.h"

class Repo {
private:
	Bank Banks[101];
	int n;
public:
	Repo();
	~Repo();
	void addBank(Bank b);
	Bank* getAll();
	int getSize();
};