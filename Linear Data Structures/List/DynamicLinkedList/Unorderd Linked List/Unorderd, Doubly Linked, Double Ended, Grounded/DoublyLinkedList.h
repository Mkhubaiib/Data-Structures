#include<iostream>
#include"DNode.h"

using namespace std;
class DoublyLinkedList
{
    private:
        DNode *head, *tail;
    public:
        DoublyLinkedList()
        {
            head = tail = NULL;
        }
            
        //Method for insert element at last 
        void insert(int v)
        {
            DNode *n = new DNode(v);
            if (head==NULL) head = tail = n;
            else
            {
                DNode *c = head;

                //while (c->next!=NULL)   c=c->next;
                    tail->next = n;
                    n->prev = tail;
                    tail = n;                               
            }
            

        }  
        //Method for insert element at start
        void insertAtStart(int v)
        {
            DNode *n = new DNode(v);
            if(head!=NULL)  head->prev = n;

            n->next = head;
            head = n;
            if(head==NULL) tail = n;	/*If list is empty*/   
        }

        void display()
        {

            
			if(head==NULL) return;
            cout << "{";
            DNode *c = head;
            while(c!=NULL)
            {
                cout << c->value << ", ";
                c = c->next;
            }
        
        cout << "\b\b}" << endl;
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
            else if(d->next==NULL) /*Also write as d==tail*/
            {
                d->prev->next=d->next;
                tail = d->prev;
            }

            else if(d->next != NULL && d->prev != NULL)
            {
                d->prev->next = d->next;
                d->next->prev = d->prev;
            }

            delete d;
        }
};