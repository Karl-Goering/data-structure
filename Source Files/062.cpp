//File.homework6-2
//the traversal of binary tree

/* Given a binary tree of n nodes, you are supposed to print
   the preorder, midorder, postorder, and levelorder of it.

   Sample Input: 10
                 8 0
				 4 1
				 0 0
				 6 9
				 0 0
				 3 7
				 0 0
				 0 0
				 5 10
				 0 0

   Sample Output: 2 4 6 3 7 9 5 10 1 8
	              3 6 7 4 5 9 10 2 8 1
				  3 7 6 5 10 9 4 8 1 2
				  2 4 1 6 9 8 3 7 5 10
*/

#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
	binaryTree<int> tree;
	int n;
	cin >> n;
	tree.createTree(n,0);
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	tree.levelOrder();
	return 0;
}
