// 选择问题:求一个长度为n的序列中第k个最小元素
//Exercise 1.1 :
//编写程序解决选择问题，令k - 2

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	int N;
	cout << "请输入序列长度" << endl;
	cin >> N;
	int k = N / 2;
	vector<int> Vint;
	srand((unsigned)time(NULL));
	for (int i = 0; i != N; ++i)
	{
		Vint.push_back(rand());
	}
	clock_t starttime, endtime;
	starttime = clock();
	sort(Vint.begin(), Vint.end());
	endtime = clock();
	cout << "第"<<k<<"个元素为:" << Vint[k - 1] << endl;

	cout << "花费" << (double)(endtime - starttime) / CLOCKS_PER_SEC << "秒" << endl;
}
