#include "list.h"
using namespace std;

int main()
{
	LinkList lst;

	cin >> lst;
	cout << lst << endl;
	cout << lst.Size() << endl;
	cout << endl;

	lst.Insert(8);
	cout << lst << endl;
	cout << lst.Size() << endl;
	cout << endl;

	lst.Insert(7,6);
	cout << lst << endl;
	cout << lst.Size() << endl;
	cout << endl;

	lst.Delete(2);
	cout << lst << endl;
	
}
