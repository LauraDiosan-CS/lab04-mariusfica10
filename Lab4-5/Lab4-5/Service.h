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
	void addBank(Bank& b);
	void deleteBank(int nr);
	void updateBank(int nr, int day, int money, char* type, char* desc);
	Bank* getAll();
	Bank read(int nr);
	int getSize();
	void filterBank(Bank banks[], int n, Bank result[], int& resultLen, int sold, int in, int out, int sum, int day, int& dif,int comp);
	void filterBankWithRepo(Repo repo, int n, Bank result[], int& resultLen, int sold, int in, int out, int sum, int day, int& dif, int comp);
	void stats(Bank banks[], int len, int caz,int day, int& sum);
	void undo();
};