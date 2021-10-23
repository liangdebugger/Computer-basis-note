#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool JudgePrime(size_t n)
{
	if (n <= 1)
		return false;
	for (size_t i = 2; i < sqrt(n); ++i)
	{
		if (!(n % i))
			return false;
	}
	return true;

}
int main()
{
	size_t n;
	cout << "请输入一个无符号数" << endl;
	cin >> n;
	cout << n << ((JudgePrime(n)) ? "是素数":"不是素数" )<< endl;
	return 0;
}
