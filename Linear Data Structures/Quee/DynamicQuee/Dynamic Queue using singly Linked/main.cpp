#include<iostream>
#include"Queue.h"
using namespace std;
int main()
{
    Queue Q;
    Q.enqueue(30); 
    Q.enqueue(20); 
    Q.enqueue(10); 
    cout << Q.getTop();
    Q.dequee();
    cout << Q.getTop();
    Q.dequee();
    cout << Q.getTop();
    Q.dequee();
    
    return 0;
}