#include "queue_array.h"

Queue_array::Queue_array() :front(0), rear(0), size(0) 
{
	arrays = new int[MaxSize];
}

void Queue_array::MakeEmpty()
{
	front = rear = 0;
	size = 0;
}

bool Queue_array::IsEmpty() const
{
	return size == 0;
}

bool Queue_array::IsFull() const
{
	return size == MaxSize;
}

Queue_array::~Queue_array()
{
	MakeEmpty();
	delete[] arrays;
}

void Queue_array::Enqueue(int x)
{
	if (IsFull())
		throw std::runtime_error("Enqueue on full queue");
	if (IsEmpty())
		arrays[rear] = x;
	else if (++rear == MaxSize)
		rear = 0;
	arrays[rear] = x;
	++size;
}

int Queue_array::Dequeue()
{
	if (IsEmpty())
		throw std::runtime_error("dequeue on empty queue");
	int x = arrays[front];
	if (++front == MaxSize)
		front = 0;
	--size;
	return x;
}

std::istream& operator>>(std::istream& is, Queue_array& que)
{
	int x;
	while (is >> x)
	{
		que.Enqueue(x);
	}
	return is;
}
std::ostream& operator<<(std::ostream& os, Queue_array& que)
{
	if (que.rear > que.front)
	{
		for(int i = que.front;i<= que.rear;++i)
			os << que.arrays[i] << " ";
		return os;
	}

	if (que.rear == que.front)
	{
		os << que.arrays[0] << " ";
		return os;
	}

	for (int i = que.front; i != MaxSize; ++i)
		os << que.arrays[i] << " ";
	for (int i = 0; i != que.rear+1; ++i)
		os << que.arrays[i] << " ";
	return os;
}
