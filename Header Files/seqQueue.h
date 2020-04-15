#ifndef SEQQUEUE
#define SEQQUEUE

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



//definition of seqQueue
template <class elemType>
class seqQueue: public queue<elemType>
{
    private:
          elemType *elem;
          int maxSize;
          int front,rear;
          void doubleSpace();
    public:
         seqQueue(int size = 10);
         ~seqQueue();
         bool isEmpty() const;
         void enQueue(const elemType &x);
         elemType deQueue();
         elemType getHead() const;      
};



//implementation of constructor
template <class elemType>
seqQueue<elemType>::seqQueue(int size)
{
    elem = new elemType[size];
    maxSize = size;
    front = rear = 0;
}



//implementation of destructor
template <class elemType>
seqQueue<elemType>::~seqQueue()
{
    delete [] elem;
}



//implementation of isEmpty
template <class elemType>
bool seqQueue<elemType>::isEmpty() const
{
    return front == rear;
}



//implementation of deQueue
template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front+1) % maxSize;
    return elem[front];
}



//implementation of getHead
template <class elemType>
elemType seqQueue<elemType>::getHead() const
{
    return elem[(front+1) % maxSize];

}



//implementation of enQueue
template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if((rear=1) % maxSize == front) doubleSpace();
    rear = (rear+1) % maxSize;
    elem[rear] = x;
}



//implementation of doubleSpace
template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[2*maxSize];
    for(int i=0;i<maxSize;++i)
        elem[i] = tmp[(front+i) % maxSize];
    front = 0; rear = maxSize-1;
    maxSize *= 2;
    delete tmp;    
}



#endif