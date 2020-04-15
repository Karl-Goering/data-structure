//To complete the task of "jump the queue", I modify the enQueue function
//When the newcomer is equal to the FORMER but different from the LATTER, just insert it between them

#ifndef JUMPQUEUE_H
#define JUMPQUEUE_H

#include <iostream>
using namespace std;

template <class elemType>
class queue
{
public:
	virtual bool isEmpty()const = 0;
	virtual void enQueue(const elemType& x, const elemType& n) = 0;
	virtual elemType deQueue() = 0;
	virtual elemType getHead() const = 0;
	virtual ~queue() {}

};

template <class elemType>
class linkQueue : public queue<elemType>
{
private:
	struct node {
		elemType data, num;
		node* next;
		node(const elemType& x, const elemType &n, node* N = NULL)
		{
			data = x; num = n; next = N;
		}
		node() :next(NULL) {}
		~node() {}
	};

	node* front, * rear;

public:
	linkQueue();
	~linkQueue();
	bool isEmpty()const;
	void enQueue(const elemType& x, const elemType& n);
	elemType deQueue();
	elemType getHead()const;
};

template <class elemType>
linkQueue<elemType>::linkQueue()
{
	front = rear = NULL;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
	node* tmp;
	while (front != NULL) {
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

template <class elemType>
bool linkQueue<elemType>::isEmpty()const
{
	return front == NULL;
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType& x, const elemType& n)    //pay attention to the argument list
{
	if (rear == NULL)
		front = rear = new node(x,n);
	else {
		bool flag = true;
		node* p = front, * q;
		while (p->next) {
			if (x == p->data && p->next->data != x)            //meanwhile satisfy two conditions
			{
				flag = false;
				q = new node(x, n, p->next);
				p->next = q;
				break;                                     //break out of the loop
			}
			else
			{
				p = p->next;
			}
		}
		if (flag) rear = rear->next = new node(x, n);              //traverse the whole queue but find nothing, then to the rear
	}
}

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
	if (front == NULL)
	{
		rear = NULL;
		cout << -1 << endl;
		return -1;
	}
	node* tmp = front;
	elemType value = front->num;
	front = front->next;
	if (front == NULL) rear = NULL;
	delete tmp;
	cout << value << endl;
	return value;
}

template <class elemType>
elemType linkQueue<elemType>::getHead()const
{
	return front->data;
}


#endif
