#include<iostream>
using namespace std;
class Stack
{
    private:
        char A[10];
        int top;
    public:
        Stack(){top=0;}

        void push(char v)
        {
            if(top<10) A[top++]=v;
        }

        char pop()
        {
            if (top >= 0) return A[--top];
            else return '\0';
        }

        bool isEmpty(){return (top==0);}
        char gettop(){return A[--top];}
        bool isFull(){return (top==10);}
};