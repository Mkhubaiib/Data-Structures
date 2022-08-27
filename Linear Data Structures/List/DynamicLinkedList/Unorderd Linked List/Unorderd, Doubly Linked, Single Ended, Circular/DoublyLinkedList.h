#include<iostream>
#include"DNode.h"

using namespace std;
class DoublyLinkedList
{
    private:
        DNode *head;
    public:
        DoublyLinkedList()
        {
            head = NULL;
        }
            
        //Method for insert element at last 
        void insert(int v)
        {
            DNode *n = new DNode(v);

            if (head==NULL)
            { 
                head = n;
                head->next = head->prev = head;
            }
            else
            {
                DNode *c = head;

                while (c->next!=head)   c=c->next;
                    c->next = n;
                    n->prev = c;
                    n->next=head;
                    head->prev=n;                   
            }
        }  

        //Method for insert element at start
        void insertAtStart(int v)
        {
            DNode *n = new DNode(v);
            if(head!=NULL)
            {
                n->prev = head->prev;
                head->prev->next = n;
                head->prev = n;
                n->next = head;
                head = n;
            } 
            else
            {
                head = n;
                head->next = head->prev = head;
            }           
        }

        void display()
        {
            DNode *c = head;
            while(c->next!=head)
            {
                cout << c->value << ", ";
                c = c->next;
            }
            cout << c->value << endl;
            }

        void remove(int r)
        {
            //empty list
            if (head==NULL) return;
     
            DNode *d = head;
            
            //search
            while(d->next!=head)
            {
                if(d->value==r) break;
                d=d->next;
            }
              //If there is only one element present in list          
            if(d->next== head && d->prev == head && d->value == head->value)
            {
                head = NULL;
                return;
            }

            if(d->value==r)
            {
                d->prev->next=d->next;
                d->next->prev = d->prev;  

                if(head->value==r) head = d->next; //For first element

                delete d;
                return;
            }
            //if element not present
            else    return;
        }
};
