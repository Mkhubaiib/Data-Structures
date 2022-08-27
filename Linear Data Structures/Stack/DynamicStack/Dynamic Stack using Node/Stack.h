#include<iostream>
#include"Node.h"

using namespace std;
class Stack
{
    private:
        Node *top;
    public:
        Stack() {top = NULL;}
        void push(int v)
        {
            Node *n = new Node();
            n->value = v;
            n->next = top;
            top = n;
        }
        int gettop()
        {
            if (top!=NULL)
                return top->value;
            else
                return -1;
        }
        int pop()
        {
            Node *d = top;
            if (top == NULL) return;
            if (d->next==NULL)
                top = NULL;
            else top = top->next;
            delete d;
        }

};