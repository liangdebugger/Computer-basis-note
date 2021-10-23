#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double max3(double a, double b, double c)
{
	double ret = ((a > b) ? a : b);
	return ((ret > c) ? ret : c);
}

double min3(double a, double b, double c)
{
	double ret = ((a < b) ? a : b);
	return ((ret < c) ? ret : c);
}

double max2(double a, double b)
{
	return ((a > b) ? a : b);
}

double MaxMulti(const vector<double>& Vd)
{
	double MaxMultiSubs = INT_MIN;
	double ThisMax = 1.0, ThisMin = 1.0;
	for (auto beg = Vd.cbegin(); beg != Vd.cend(); ++beg)
	{
		double ThisMax1 = ThisMax;
		ThisMax = max3((*beg), (ThisMax * (*beg)), (ThisMin * (*beg)));
		ThisMin = min3((*beg), (ThisMax1 * (*beg)), (ThisMin * (*beg)));
		MaxMultiSubs = max2(ThisMax, MaxMultiSubs);
	}
	
	return MaxMultiSubs;
}
int main()
{
	vector<double> Vd;
	cout << "请输入double序列" << endl;
	double over;
	while (cin >> over)
		Vd.push_back(over);
	cout << MaxMulti(Vd) << endl;
}
