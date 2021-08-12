//Exercise 1.3 :

#include<iostream>
using namespace std;

void PrintDigit(size_t N)
{
	cout << N;
}

void PrintOut(int N)
{
	if (N < 0)
	{
		N = -N;
		cout << "-";
	}
	if (N >= 10)
		PrintOut(N / 10);
	PrintDigit(N % 10);
}

void PrintOut(double N, size_t precision)  
{
	if (N < 0) {
		cout << '-';
		N = -N;
	}
	int integer_part = static_cast<int>(N);
	PrintOut(integer_part);
	cout << '.';
	double float_part = N - integer_part;
	int dou_to_int = static_cast<int>(float_part * pow(10, precision));
	PrintOut(dou_to_int);
}

int main()
{
	PrintOut(-42);
	cout << endl;
	PrintOut(-88.888, 2);
	cout << endl;
	return 0;
}
