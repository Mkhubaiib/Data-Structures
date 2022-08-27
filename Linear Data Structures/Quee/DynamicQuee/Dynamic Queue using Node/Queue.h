#include<iostream>
#include"Node.h"

using namespace std;
class Queue
{
    private:
        Node *top;
    public:
        Queue() {top = NULL;}
        void push(int v)
        {
            Node *n = new Node();
            n->value = v;
            n->next= NULL;

            if(top==NULL) {top=n; return;}
            Node *c = top;
            while (c->next!=NULL)
            {
                c=c->next;
            }
            c->next=n;
           
        }
        int gettop()
        {
            if (top!=NULL)
                return top->value;
            else
                return -1;
        }
        void pop()
        {
            if (gettop() == -1) return;
            Node *d = top;
            top=top->next;
            delete d;
        }

};