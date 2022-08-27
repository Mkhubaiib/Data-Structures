#include <cstdlib>
#include <iostream>
#include <stack>
#include "AVL.h"

using namespace std;

int main()
{
    int A[]={45,23,43}; //50,40,80,20,45,90,100,85,75,110,300,200//45,23,43,27,22,19,21,56,12,14,34,64,24
    const int n=3;
    int i;
    AVLTree Tree;
    for (i=0;i<n;i++)
    {
        Tree.Insert(A[i]);
    }
    cout << "InOrder  (R):"; Tree.InOrder();   cout << endl;
    return 0;
}
