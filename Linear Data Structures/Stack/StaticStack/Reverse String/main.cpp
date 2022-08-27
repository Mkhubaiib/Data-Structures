#include<iostream>
#include"Stack.h"
#include<cstring>
using namespace std;
int main()
{
    Stack S;
    char a[] = {"KHUBAIB"};
    char b[strlen(a)];
    for (int i=0; i<strlen(a); i++){
        S.push(a[i]);
    }

    for(int i =0; i<strlen(a); i++)
    {
    b[i] = S.pop();
    }

    cout << b;

    return 0;
}