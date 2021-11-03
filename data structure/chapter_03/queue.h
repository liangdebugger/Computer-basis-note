#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
};

class Queue
{
    friend std::istream& operator>>(std::istream&, Queue&);
    friend std::ostream& operator<<(std::ostream&, Queue&);
public:
    Queue() :front(nullptr), rear(nullptr), size(0) {}
    ~Queue();

public:
    bool IsEmpty() const;
    void MakeEmpty(); 
    void Enqueue(int x);
    int Dequeue();

private:
    Node *head = new Node;
    Node* front;
    Node* rear;
    size_t size;
};

#endif
