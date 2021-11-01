#include "stack.h"

/*Stack::Stack()
{
	head->data = 0;
	head->next = NULL;
}*/

Stack::~Stack()
{
	MakeEmpty();
	delete head; 
}

bool Stack::IsEmpty() const
{ 
	return (head->next == nullptr);
}

size_t Stack::Size() const
{
	size_t count = 0;                  
	Node* p = head->next;           
	while (p != NULL)              
	{
		count++;
		p = p->next;                
	}   
	return count;
}

void Stack::MakeEmpty()
{
	head->next = NULL;
}

void Stack::Push(int item)
{
	Node* the_next = head->next;
	Node* p = new Node;
	p->data = item;
	head->next = p; 
	p->next = the_next;
}

void Stack::Pop()
{
	if (IsEmpty())
	{
		throw std::runtime_error("Empty Stack");
	}
	else 
	{
		Node* first = head->next;
		head->next = head->next->next;
		delete first;
	}
}

int Stack::Top() const
{
	return head->next->data;
}


std::istream& operator>>(std::istream& is, Stack& stk)
{
	int x;
	while (is >> x) 
		stk.Push(x);
	return is;
}

std::ostream& operator<<(std::ostream& os, Stack& stk)
{
	while (!stk.IsEmpty()) 
	{
		os << stk.Top() << " ";
		stk.Pop();
	}
	return os;
}
