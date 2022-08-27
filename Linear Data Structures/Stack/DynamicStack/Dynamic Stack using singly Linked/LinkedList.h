#include"Node.h"
#include<iostream>
using namespace std;

class LinkedList
    {
    private:
        Node *head;

    public:
        LinkedList()
        {head = NULL;}

        void insertAtStart(int v){
            Node *p = new Node();
            p->value = v;
            p->next=head;
            head=p;
        }

        void remove(int v){

            Node *d = head;
            Node *p = head;

            if(head==NULL)  return;

            while(d!=NULL){
                if(d->value==v) 
                   break;
                p=d;
                d=d->next;
            }   

            if(d==NULL)  return;
            if(d==head) head=d->next;
           
            else{
                  p->next=d->next;
            }
            delete  d;
        } 

        int getfirst()
        {
            if (head==NULL) return -1;
            return head->value;
        }   
    };   