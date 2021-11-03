#include "stack_array.h"

Stack_array::Stack_array():maxSize(MaxSize), TopOfStack(-1)
{
	arrays = new int[MaxSize];
}

Stack_array::~Stack_array()
{
	delete[] arrays;
}

bool Stack_array::IsEmpty()
{
	return (TopOfStack == -1);
}
void Stack_array::Push(int data)
{
	if (TopOfStack == 100)
		throw std::runtime_error("no space");
	arrays[TopOfStack + 1] = data;
	++TopOfStack;
}

int Stack_array::Pop()
{
	if (IsEmpty())
		throw std::runtime_error("pop on empty stack");
	int res = arrays[TopOfStack];
	--TopOfStack;
	return res;
}

void Stack_array::MakeEmpty()
{
	while (TopOfStack != -1)
	{
		--TopOfStack;
	}
}

std::istream& operator>>(std::istream& is, Stack_array& stk)
{
	int x;
	while (is >> x)
		stk.Push(x);
	return is;
}

std::ostream& operator<<(std::ostream& os, Stack_array& stk)
{
	int index = stk.TopOfStack;
	while (index != -1)
	{
		os << stk.arrays[index]<<" ";
		--index;
	}
	os << std::endl;
	return os;
}
