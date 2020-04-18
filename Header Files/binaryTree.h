//modified code
//must use "linkQueue.h"
#ifndef BINARYTREE
#define BINARYTREE

#include <iostream>
#include "linkQueue.h"

using namespace std;

//abstract class of bTree
template <class T>
class bTree
{
    public:
         virtual bool isEmpty() const = 0;
         virtual T Root (T flag) const = 0;
         virtual T parent (T x,T flag) const = 0;
         virtual T lchild (T x,T flag) const = 0;
         virtual T rchild (T x,T flag) const = 0;
         virtual void delLeft(T x) = 0;
         virtual void delRight(T x) = 0;
         virtual void preOrder() const = 0;
         virtual void midOrder() const = 0;
         virtual void postOrder() const = 0;
         virtual void levelOrder() const = 0;
};



//definition of binaryTree
template <class T>
class binaryTree: public bTree<T>{
    
private:
      struct Node{
          
          T data;
          Node *left,*right,*parent;
          Node(): left(NULL),right(NULL),parent(NULL) {}
          Node(T item,Node *L = NULL,Node *R = NULL,Node *P = NULL): data(item),left(L),right(R),parent(P){}
          ~Node(){}
      };

      Node *root; //the root node of binaryTree
public:
     binaryTree():root(NULL){}
     binaryTree(T x){root = new Node(x);}
     ~binaryTree();
     bool isEmpty() const;
     T Root(T flag) const;
     T lchild(T x,T flag) const;
     T rchild(T x,T flag) const;
     void delLeft(T x);
     void delRight(T x);
     void preOrder() const;
     void midOrder() const;
     void postOrder() const;
     void levelOrder() const;
     void createTree(int x,T flag);
     T parent(T x,T flag) const {return flag;}
private:
      Node *find(T x,Node *t) const;
      void clear(Node *&t);
      void preOrder(Node *t) const;
      void midOrder(Node *t) const;
      void postOrder(Node *t) const;
};



/* implemrntation of some functions */
//fuction isEmpty
//function Root(if the binary tree is empty, return flag, else return the value of root)
//fuction clear(recursion)
//destructor(use function clear)
template <class T>
bool binaryTree<T>::isEmpty() const
{
    return root == NULL;
}

template <class T>
T binaryTree<T>::Root(T flag) const    
{
    if(root == NULL) return flag;
    else return root->data;
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t)
{
    if(t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}

template <class T>
binaryTree<T>::~binaryTree()
{
    clear(root);
}



/* 
implementation of traversal
overload and recurse 
*/
template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const
{
    if(t == NULL) return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}

template <class T>
void binaryTree<T>::preOrder() const
{
    cout << endl;
    preOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const
{
    if(t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}

template <class T>
void binaryTree<T>::postOrder() const
{
    cout << endl;
    postOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const
{
    if(t == NULL) return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}

template <class T>
void binaryTree<T>::midOrder() const
{
    cout << endl;
    midOrder(root);
}

template <class T>
void binaryTree<T>::levelOrder() const
{
    linkQueue<Node *> que;
    Node *tmp;

    cout << endl;
    que.enQueue(root);

    while(!que.isEmpty()){
        tmp = que.deQueue();
        cout << tmp->data << " ";
        if(tmp->left) que.enQueue(tmp->left);
        if(tmp->right) que.enQueue(tmp->right);
    }
}



/* other fuctions */
//function find
//function lchild
//function rchild
//function delLeft
//function delRight
template <class T>
typename binaryTree<T>::Node *binaryTree<T>::find(T x,binaryTree<T>::Node *t) const
{
    Node *tmp;
    if(t == NULL) return NULL;
    if(t->data == x) return t;
    if(tmp = find(x,t->left)) return tmp;
    else return find(x,t->right);
}

template <class T>
void binaryTree<T>::delLeft(T x)
{
    Node *tmp = find(x,root);
    if(tmp == NULL) return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(T x)
{
    Node *tmp = find(x,root);
    if(tmp == NULL) return;
    clear(tmp->right);
}

template <class T>
T binaryTree<T>::lchild(T x,T flag) const
{
    Node *tmp = find(x,root);
    if(tmp == NULL||tmp->left == NULL) return flag;

    return tmp->left->data;
}

template <class T>
T binaryTree<T>::rchild(T x,T flag) const
{
    Node *tmp = find(x,root);
    if(tmp == NULL||tmp->right == NULL) return flag;

    return tmp->right->data;
}



//createTree
template<class T>
void binaryTree<T>::createTree(int n, T flag)
{
	Node** p = NULL;
	T ldata, rdata;
	p = new Node * [n + 1];
	for (int i = 1; i <= n; ++i) {
		p[i] = new Node(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> ldata >> rdata;
		if (ldata != flag) {
			p[i]->left = p[ldata];
			p[i]->left->parent = p[i];
		}
		if (rdata != flag) {
			p[i]->right = p[rdata];
			p[i]->right->parent = p[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i]->parent == NULL) root = p[i];
	}
}

#endif