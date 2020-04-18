//File.homework6-1
//judge a binary tree if it is complete

/* Given a binary tree, if it is complete, output 'Y', else output 'N'
   
   Sample Input: 4
                 0 0
				 0 0
				 1 0
				 3 2
   Sample Outout: Y

   Sample Input: 4
                 0 0
				 0 0
				 0 1
				 3 2
   Sample Output: N

*/

#include <iostream>
#include "isComplete.h"

using namespace std;

int main()
{
	binaryTree<int> tree;
	int n;
	cin >> n;
	tree.createTree(n, 0);
	
	if (tree.isComplete(n))
		cout << 'Y' << endl;
	else
		cout << 'N' << endl;
	return 0;
}
