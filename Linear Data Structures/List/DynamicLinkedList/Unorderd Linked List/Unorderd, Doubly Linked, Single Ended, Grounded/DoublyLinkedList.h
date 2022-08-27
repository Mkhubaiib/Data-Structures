#include<iostream>
#include"DNode.h"

using namespace std;
class DoublyLinkedList
{
    private:
        DNode *head;
        DNode* max()
        {
            DNode *m = head;
            int maxValue = head->value;
            while (m->next!=NULL)
            {
                if(maxValue<m->value) maxValue=m->value;
                m=m->next;
            }
             DNode *d = head;
            
            // searching
            while(d!=NULL)
            {
                if(d->value==maxValue) break;
                d=d->next;
            }
            return d;
        }
        DNode* min()
        {
            DNode *m = head;
            int minValue = head->value;
            while (m->next!=NULL)
            {
                if(minValue>m->value) minValue=m->value;
                m=m->next;
            }
             DNode *d = head;
            
            // searching
            while(d!=NULL)
            {
                if(d->value==minValue) break;
                d=d->next;
            }
            return d;
        }
        
    public:
        DoublyLinkedList()
        {
            head = NULL;
        }
            
        //Method for insert element at last 
        void insert(int v)
        {
            DNode *n = new DNode(v);
            if (head==NULL) head = n;
            else
            {
                DNode *c = head;

                while (c->next!=NULL)   c=c->next;
                    c->next = n;
                    n->prev = c;
                                
            }
            

        }  
        //Method for insert element at start
        void insertAtStart(int v)
        {
            DNode *n = new DNode(v);
            if(head!=NULL)  head->prev = n;

            n->next = head;
            head = n;
            
        }

        void display()
        {
            DNode *c = head;
            while(c!=NULL)
            {
                cout << c->value << ", ";
                c = c->next;
            }
        
        cout << endl;
        }

        void remove(int r)
        {
            //empty list
            if (head==NULL) return;

            DNode *d = head;
            
            // searching
            while(d!=NULL)
            {
                if(d->value==r) break;
                d=d->next;
            }

            //if element not find
            if (d==NULL) return;

            //if first element
            if(d->prev==NULL)
            {
                d->next->prev = d->prev;
                head = d->next;
            }
            //if last element
            else if(d->next==NULL)
            {
                d->prev->next=d->next;
            }
            //if midle
            else 
            {
                d->prev->next = d->next;
                d->next->prev = d->prev;
            }

            delete d;
        }

        void swap()
        {
            DNode *currX = max();
            DNode *currY = min();
            
            DNode *prevX = currX->prev;
            DNode *prevY = currY->prev;
          
            prevX->next = currY;
            prevY->next = currX;
            // Swap next pointers  
            DNode *temp = currY->next;
            currY->next=currX->next;
            currX->next=temp;

        }
        

};