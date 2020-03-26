#pragma once
#include "Repo.h"
#include "Bank.h"


// service class with constructor,destructor and crud repo operations
class Service
{
	Repo r;
public:
	Service();
	~Service();
	void addBank(int id, int day, int money, char* type, char* desc);
	void deleteBank(int nr);
	void updateBank(int nr, int id, int day, int money, char* type, char* desc);
	Bank* getAll();
	int getSize();
};