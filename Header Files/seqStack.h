//original header file from book
#ifndef SEQSTACK
#define SEQSTACK

#include <iostream>

using namespace std;

template <class elemType>
class stack {
   public:
    virtual ~stack() {}
    virtual elemType pop() = 0;
    virtual elemType top() const = 0;
    virtual void push(const elemType& x) = 0;
    virtual bool isEmpty() const = 0;
};

template <class elemType>
class seqStack : public stack<elemType> {
   private:
    elemType* elem;
    int top_p; 
    int maxSize;
    void doubleSpace();

   public:
    seqStack(const seqStack<elemType>& s);
    seqStack(int initSize = 10);
    ~seqStack();
    elemType top() const;
    elemType pop();
    void push(const elemType& x);
    bool isEmpty() const;
};

template <class elemType>
void seqStack<elemType>::doubleSpace() {
    elemType* tmp;
    tmp = elem;
    elem = new elemType[maxSize * 2];
    for (int i = 0; i < maxSize; i++) {
        elem[i] = tmp[i];
    }
    maxSize = maxSize * 2;
    delete tmp;
}

template <class elemType>
seqStack<elemType>::seqStack(int initSize) {
    maxSize = initSize;
    elem = new elemType[maxSize];
    top_p = -1;
}

template <class elemType>
seqStack<elemType>::seqStack(const seqStack<elemType>& s) {
    maxSize = s.maxSize;
    elem = new elemType[maxSize];
    top_p = s.top_p;
    if (s.top_p != -1) {
        for (int i = 0; i <= s.top_p; i++) {
            elem[i] = s.elem[i];
        }
    }
}

template <class elemType>
seqStack<elemType>::~seqStack() {
    delete[] elem;
}

template <class elemType>
void seqStack<elemType>::push(const elemType& x) {
    if (top_p == maxSize - 1) {
        doubleSpace();
    }
    top_p++;
    elem[top_p] = x;
}

template <class elemType>
elemType seqStack<elemType>::pop() {
    elemType tmp = elem[top_p];
    top_p--;
    return tmp;
}

template <class elemType>
elemType seqStack<elemType>::top() const {
    return elem[top_p];
}

template <class elemType>
bool seqStack<elemType>::isEmpty() const {
    return (top_p == -1);
}
#endif