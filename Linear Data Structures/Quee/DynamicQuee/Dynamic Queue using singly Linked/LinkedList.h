#include"Node.h"
#include<iostream>
using namespace std;

class LinkedList
    {
        
    public:
        Node *head;
        LinkedList()
        {head = NULL;}

        void insert(int v){
            Node *p = new Node();
            p->value=v;
            p->next=NULL;
            if (head==NULL) head = p;
            else
                {
                    Node *temp = head;
                    while(temp->next!=NULL) temp=temp->next;
                    temp->next=p;
                }
                
           
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