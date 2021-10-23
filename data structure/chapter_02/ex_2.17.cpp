#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

long int pow(int x, int exp)
{
	long int ret = 1;
	while (exp>1)
	{
		if (exp % 2)
			ret *= x;
		x *= x;
		exp >>= 1;
	}
	return x*ret;
}
int main()
{
	cout << pow(2, 10) << endl;
}
