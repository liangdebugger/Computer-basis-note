#include "stack_array.h"

using namespace std;
int main()
{
	Stack_array stk;
	//Stack lst = new Stack();

	cin >> stk;
	cout << endl;

	stk.Pop();
	cout << endl;

	stk.Push(7);
	cout << stk;
	cout << endl;
}
