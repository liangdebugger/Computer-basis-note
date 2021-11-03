#include "queue.h"

void Queue::MakeEmpty()
{
	Node* p = head;
	while (size)
	{
		Node* the_next = p->next->next;
		delete p->next;
		p->next = the_next;
		--size;
	}
	front = rear = nullptr;
}

bool Queue::IsEmpty() const
{
	return size == 0;
}

Queue::~Queue()
{
	MakeEmpty();
	delete head;
}

void Queue::Enqueue(int x)
{
	Node* p = new Node;
	p->data = x;
	if (IsEmpty())
		head->next = front = rear = p;
	else
	{
		rear->next = p;
		rear = p;
	}
	++size;
}

int Queue::Dequeue()
{
	if (IsEmpty())
		throw std::runtime_error("dequeue on empty queue");
	Node* p = new Node;
	int x = front->data;
	p = front->next;
	delete front;
	head->next = front = p;
	--size;
	return x;
}

std::istream& operator>>(std::istream& is, Queue& que)
{
	int x;
	while (is >> x)
	{
		que.Enqueue(x);
	}
	return is;
}
std::ostream& operator<<(std::ostream& os, Queue& que)
{
	Node* p = que.head->next;
	int cnt = que.size;
	while (cnt)
	{
		os << p->data << " ";
		p = p->next;
		--cnt;
	}
	return os;
}
