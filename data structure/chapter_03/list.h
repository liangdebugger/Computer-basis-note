#ifndef LIST_H
#define LIST_H

#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

class LinkList 
{
	friend std::istream& operator>>(std::istream&, LinkList&);
	friend std::ostream& operator<<(std::ostream&, const LinkList&);
public:
	LinkList();																	
	LinkList(const LinkList&) = delete;    
	LinkList& operator=(LinkList) = delete;
	~LinkList();

	bool IsEmpty() const { return head->next == nullptr; }						//判断是否为空链表
	bool IsLast(Node* p) const { return p->next == nullptr; }					//判断是否是最后一个元素
	
	size_t Size() const;														//返回元素数量
	Node* Header() { return head; }												//返回表头
	Node* First() const { return head->next; }									//返回第一个元素
	void MakeEmpty();

	void Insert(int d,int n=-1);												//默认在尾部插入元素
	void Insert(int d, Node* p);
	void Delete(int n = -1);

	Node* Find(int);   															//查找
	Node* FindPrevious(int);													//返回前一个元素
	

private:
	Node* head = new Node;
};

#endif
