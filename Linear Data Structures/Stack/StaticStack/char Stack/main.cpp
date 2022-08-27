#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
    Stack S;
    S.push('a');
    S.push('b');
    S.push('c');
    S.push('d');
    S.push('e');
    S.push('f');
    S.push('g');
    S.push('h');
    S.push('i');
    S.push('j');
    cout << S.pop();
    cout << S.gettop();
    cout << S.isEmpty();
    cout << S.isFull();
    return 0;
}