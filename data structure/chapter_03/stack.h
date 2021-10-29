#ifndef STACK_H
#define STACK_H

#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

class Stack 
{
	friend std::istream& operator>>(std::istream&, Stack&);
	friend std::ostream& operator<<(std::ostream&, const Stack&);

public:
	Stack() = default;
	Stack(const Stack&) = delete;;
	Stack& operator=(Stack) = delete;;
	~Stack();

	bool IsEmpty() const { return head->next == nullptr; }
	void MakeEmpty();
	void Push(int);
	int Top() const;
	void Pop();
	size_t Size();
	

private:
	Node* head = new Node;
};

#endif
