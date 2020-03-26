#pragma once
#include "Bank.h"
#include "Repo.h"

// nu face parte din lab4
void filterBank(Bank banks[], int n, Bank result[], int& resultLen);
void filterBankWithRepo(Repo repo, int n, Bank result[], int& resultLen);