#include<iostream>
#include"Queue.h"
using namespace std;
int main()
{
    Queue Q;
    Q.push(30); 
    Q.push(20); 
    Q.push(10); 

    cout << Q.gettop();
    Q.pop();
    cout << Q.gettop();
    Q.pop();
    cout << Q.gettop();
    Q.pop();
   
    return 0;
}