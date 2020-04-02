#include<cstring>
#include "Tools.h"

//desc : pow of a number, one digit
//in: integers x(the number to be powered),y(the power of x*10)
//out: integer 10*x^y
int powInt(int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        x *= 10;
    }
    return x;
}


//desc: converting a string to a number
//in: char* , the string we want to convert
//out: int, the string as an integer
int parseInt(char* n)
{
    int sum = 0;
    int len = strlen(n);
    for (int x = 0; x < len; x++)
    {
        int nr = n[len - (x + 1)] - '0';
        sum = sum + powInt(nr, x);
    }
    return sum;
}