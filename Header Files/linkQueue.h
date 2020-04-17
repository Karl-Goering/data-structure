//original code
#ifndef LINKQUEUE
#define LINKQUEUE

#include <iostream>
using namespace std;

//abstract class of queue
template <class elemType>
class queue
{
    public:
         virtual bool isEmpty() const = 0;              
         virtual void enQueue(const elemType &x) = 0;
         virtual elemType deQueue() = 0;
         virtual elemType getHead() const = 0;
         virtual ~queue() {}

};



//definition of linkQueue
template <class elemType>
class linkQueue: public queue<elemType>
{
    private:
          struct node{
              elemType data;
              node *next;
              node(const elemType &x,node *N = NULL)
              {data=x;next=N;}
              node():next(NULL){}
              ~node(){}
          };
    node *front,*rear;

    public:
         linkQueue();
         ~linkQueue();
         bool isEmpty() const;
         void enQueue(const elemType &x);
         elemType deQueue();
         elemType getHead() const;
};



//implementation of constructor
template <class elemType>
linkQueue<elemType>::linkQueue()
{
    front=rear=NULL;
}



//implementation of destructor
template <class elemType>
linkQueue<elemType>::~linkQueue()
{
    node *tmp;
    while(front!=NULL){
        tmp = front;
        front = front->next;
        delete tmp;
    }
}



//implementation of isEmpty
template <class elemType>
bool linkQueue<elemType>::isEmpty() const
{
    return front == NULL;
}



//implementation of getHead
template <class elemType>
elemType linkQueue<elemType>::getHead() const
{
    return front->data;
}



//implementation of enQueue
template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
    if(rear == NULL)
          front = rear = new node(x);
    else
    
          rear = rear->next = new node(x);    
}



//implementation of deQueue
template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *tmp = front;
    elemType value = front->data;
    front = front->next;
    if(front == NULL) rear = NULL;
    delete tmp;
    return value;
}

#endif