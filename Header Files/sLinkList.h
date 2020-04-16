//original code
#ifndef SLINKLIST
#define SLINKLIST

#include <iostream>
using namespace std;

//abstract class
template <class elemType>
class list
{
    public:
         virtual void clear() = 0;
         virtual int length() const = 0;
         virtual void insert(int i,const elemType &x) = 0;
         virtual void remove(int i) = 0;
         virtual int search(const elemType &x) const = 0;
         virtual elemType visit(int i) = 0;
         virtual void traverse() const = 0;
         virtual ~list(){};
};



//definition of sLinkList
template <class elemType>
class sLinkList
{
    private:
          struct node{
              elemType data;
              node *next;

              node(const elemType &x,node *n = NULL)
                  {data = x;next = n;}
              node():next(NULL){}
              ~node(){}
          };
          node *head;
          int currentLength;

          node *move(int i) const;

    public:
         sLinkList();
         ~sLinkList(){clear();delete head;}

         void clear();
         int length() const {return currentLength;}
         void insert(int i,const elemType &x);
         void remove(int i);
         int search(const elemType &x) const;
         elemType visit(int i) const;
         void traverse() const;
};



//implementation of move
template <class elemType>
typename sLinkList<elemType>::node *sLinkList<elemType>::move(int i) const
{
    node *p = head;
    while(i-->=0)  p=p->next;
    return p;
}



//implementation of constructor
template <class elemType>
sLinkList<elemType>::sLinkList()
{
    head = new node;
    currentLength = 0;
}



//implementation of clear
template <class elemType>
void sLinkList<elemType>::clear()
{
    node *p = head->next,*q;
    head->next = NULL;
    while(p!=NULL){
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}



//implementation of insert
template <class elemType>
void sLinkList<elemType>::insert(int i,const elemType &x)
{
    node *pos;

    pos = move(i-1);
    pos->next = new node(x,pos->next);
    ++currentLength;
}



//implementation of remove
template <class elemType>
void sLinkList<elemType>::remove(int i)
{
    node *pos,*delp;
                                                  
    pos = move(i-1);
    delp = pos->next;
    pos->next = delp->next;
    delete delp;
    --currentLength;
}



//implementation of search
template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const    
{                                                              
    node *p = head->next;                         //to find a specific element, if any, output its sequence number; if not, output -1                 
    int i = 0;

    while(p!=NULL&&p->data!=x) {p = p->next;++i;}
    if(p == NULL) return -1; else return i;
}



//implementation of visit
template <class elemType>
elemType sLinkList<elemType>::visit(int i) const
{
    return move(i)->data;
}



//implementation of traverse
template <class elemType>
void sLinkList<elemType>::traverse() const
{
    node *p = head->next;
    cout << endl;
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

#endif