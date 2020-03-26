#include "Operations.h"
#include <string.h>

//nu face parte din lab 4
void filterBank(Bank banks[], int n, Bank result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++)
	{
		if (banks[i].getDay() > 5)
		{
			result[resultLen++] = banks[i];
		}
	}
}

void filterBankWithRepo(Repo repo, int n, Bank result[], int& resultLen)
{
	resultLen = 0;
	Bank* initialBanks = repo.getAll();
	return filterBank(initialBanks, n, result, resultLen);
}
