//File.homework1-1
//Find the kth largest element in an unsorted array

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    for (int i = 0; i < size; ++i) {
        bool flag = true;
        for (int j = 0; j < size-i-1; ++j)
           if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]), flag = false;
        if (flag) break;
    }
}

int main()
{
int n,k,i;
cin >> n >> k;
int *p = new int[n];

for (i = 0;i < n;++ i)
cin >> p[i];
bubbleSort(p,n);
cout << p[n-k];

delete [] p;

return 0;
}	
