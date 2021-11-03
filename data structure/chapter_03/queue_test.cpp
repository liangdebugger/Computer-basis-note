#include "queue.h"

using namespace std;
int main()
{
	Queue stk;
	//Stack lst = new Stack();

	cin >> stk;
	cout << endl;

	stk.Dequeue();
	cout << endl;

	stk.Enqueue(7);
	cout << stk;
	cout << endl;
}
