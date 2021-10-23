#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FindMajor(const vector<int>& A)
{
	vector<int> B;
	int Majorint;
	int length = A.size();
	if (length == 2)
	{
		if (A[0] == A[1])
			return A[0];
		else
			return -1;
	}
	if (!(length % 2))
	{
		for (int i = 0; i != length; i += 2)
		{
			if (A[i] == A[i + 1])
				B.push_back(A[i]);
		}
		return FindMajor(B);
	}
	else
	{
		int ans = FindMajor(vector<int>(A.begin(), A.end() - 1));
		return ((ans == -1) ? A[length - 1] : ans);
	}
}
int main()
{
	vector<int> Vint = { 3,3,4,2,4,4,2,4,4 };
	cout << FindMajor(Vint) << endl;
}
