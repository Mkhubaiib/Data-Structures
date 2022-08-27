#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
    Stack S;
    S.push(30); 
    S.push(20); 
    S.push(10); 
    cout << S.pop();
    cout << S.pop();
    cout << S.pop();
    cout << S.pop();
    return 0;
}