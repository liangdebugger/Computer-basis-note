#ifndef STACK_H
#define STACK_H

#define MaxSize 100
#include <iostream>

class Stack_array
{
    friend std::istream& operator<<(std::istream&, Stack_array&);
    friend std::ostream& operator>>(std::istream&, Stack_array&);
public:
    Stack_array();
    ~Stack_array();
public:
    void Push(int data);
    int Pop();
    int Top();
    bool IsEmpty();
    void MakeEmpty();
private:
    size_t TopOfStack;
    int* arrays;
    size_t maxSize = MaxSize;
};
 
#endif
