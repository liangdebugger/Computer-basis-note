#ifndef QUEUE_H
#define QUEUE_H
#define MaxSize 10
#include <iostream>


class Queue_array
{
    friend std::istream& operator>>(std::istream&, Queue_array&);
    friend std::ostream& operator<<(std::ostream&, Queue_array&);
public:
    Queue_array();
    ~Queue_array();

public:
    bool IsEmpty() const;
    bool IsFull() const;
    void MakeEmpty(); 
    void Enqueue(int x);
    int Dequeue();

private:
    size_t front;
    size_t rear;
    size_t size;
    size_t maxsize = MaxSize;
    int* arrays;
};

#endif
