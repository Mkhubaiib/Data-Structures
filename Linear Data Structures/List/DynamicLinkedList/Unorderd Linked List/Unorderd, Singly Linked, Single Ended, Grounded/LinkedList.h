#include"Node.h"
#include<iostream>
using namespace std;

class LinkedList
    {
    private:
        Node *head;
        void displayReverse(Node *x)
            {
                if (x==NULL)
                    return ;
                else
                    displayReverse(x->next);
                cout << x->value<<",";
            }
    public:
        LinkedList()
        {head = NULL;}

        void insertAtStart(int v){
            Node *p = new Node();
            p->value = v;
            p->next=head;
            head=p;
        }

        void insert(int v)
        {  
            
            Node *n = new Node();
            n->value = v;
            n->next = NULL;

            if(head==NULL)
                head = n;
            else{
                Node *c = head;
                while(c->next)
                    c=c->next;
                
                c->next=n;
            }
        }

        void display()
        {
            Node *c = head;
            cout << "{";
            while(c!=NULL) 
            {
                cout << c->value << ", ";
                c=c->next;
            }
            cout << "\b\b" << endl;
        }
       
        void displayReverse()
        {
            cout << "{";
            displayReverse(head);
            cout << "\b\b}" << endl;
        }

        Node* search(int v){
            Node *p = head;
            while(p!=NULL){
                if(p->value==v){
                    return p;
                }
                p=p->next;
            }
            return NULL;
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

    int count(){
        int counter = 0;
        Node *p = head;
        while(p!=NULL){
            counter++;
            p = p->next;
        }
        return counter;
    }
    

      
    };   