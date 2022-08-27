#include<iostream>
#include"Stack.h"
#include<cstring>
using namespace std;

int main()
{
    Stack S;
    char brackets[] = {"[{()}]"};

    for (int i=0; i<strlen(brackets); i++)
    {
        if(brackets[i]=='[' || brackets[i]=='{' || brackets[i]=='(')
            S.push(brackets[i]);
            
        else  if(brackets[i]==']'){
            if (S.pop()=='[') continue;
            else {cout << "Error"; break;}
        }
        else  if(brackets[i]=='}'){
            if (S.pop()=='{') continue;
            else  {cout << "Error"; break;}
        }
        else  if(brackets[i]==')'){
            if (S.pop()=='(') continue;
            else  {cout << "Error"; break;}
        }
    }
    if (!S.isEmpty()) cout << "Error"; 
  

    return 0;
}

