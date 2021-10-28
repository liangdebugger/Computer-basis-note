#include "list.h"

LinkList::LinkList()
{
	head->data = 0;
	head->next = NULL;
}

LinkList::~LinkList()
{
	delete head; 
}


size_t LinkList::Size() const
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

void LinkList::MakeEmpty()
{
	head->next = NULL;
}
void LinkList::Insert(int d, int n)
{
	if (n == -1)
		n = (*this).Size();
	if (n>(*this).Size())
		std::cout << "下标越界" << std::endl;
	else
	{
		Node* p = head;
		while (n)
		{
			p = p->next;
			--n;
		}
		Node* ptemp = new Node;
		ptemp->data = d;
		ptemp->next = p->next;
		p->next = ptemp;
	}
}

void LinkList::Insert(int d, Node* p)
{
	Node* obj = new Node;
	obj->data = d;
	Node* next_p = p->next;
	p->next = obj;
	obj->next = next_p;
}

void LinkList::Delete(int n)
{
	if (n == -1)
		n = (*this).Size();
	if (n>(*this).Size())
		std::cout << "下标越界" << std::endl;
	else
	{
		Node* p = head;
		while (n-1)
		{
			p = p->next;
			--n;
		}
		Node* ptemp = new Node;
		ptemp->next = p->next->next;
		delete p->next;
		p->next = ptemp->next;
		delete ptemp;
	}
}

std::istream& operator>>(std::istream& is, LinkList& list)
{
	int x;
	Node* p = list.head;
	while (is >> x) 
	{
		list.Insert(x, p);
		p = p->next;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const LinkList& list)
{
	Node* p = list.head;
	while (p->next) {
		os << p->next->data << " ";
		p = p->next;
	}
	return os;
}
