#include<iostream>
using namespace std;
class Stack
{
    private:
        int A[10];
        int top;
    public:
        Stack(){top=0;}

        void push(int v)
        {
            if(top<10) A[top++]=v;
        }

        int pop()
        {
            if (top >= 0) return A[--top];
            else return -1;
        }
        bool isEmpty(){return (top==0);}
        int gettop(){return A[--top];}
        bool isFull(){return (top==10);}
};