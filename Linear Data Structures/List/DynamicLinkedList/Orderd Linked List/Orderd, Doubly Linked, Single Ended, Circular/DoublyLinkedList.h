#include<iostream>
#include"DNode.h"

using namespace std;
class DoublyLinkedList
{
    private:
        DNode *head;
        
        void displayReverse(DNode *x)
        {
            if (x->next==head) {cout << x->value << ", "; return;}
            else 
            {
                displayReverse(x->next);
                cout << x->value << ", "; return;
            }
        
            
        }
    public:
        DoublyLinkedList()
        {
            head = NULL;
        }
            
        
        void insert(int v)
        {
            DNode *n = new DNode(v);

            //if empty list
            if (head==NULL)
            { 
                head = n;
                head->next = head->prev = head;
            }
            //if value is smallest all over in the list 
            else if (head->value>=v)
            {
                n->prev = head->prev;
                head->prev->next = n;
                head->prev = n;
                n->next = head;
                head = n;
            }
            else
            {
                DNode *c = head;
                while (c->next!=head) 
                {
                    if(c->value>v) break;
                    c = c->next;
                } 
                     
                if (c->next!=head) c=c->prev;   //According to our requirment to minimize code
                // Basically We want same following four lines for both the cases
                // case 1: to insert between list
                // case 2: to insert at last
                n->prev = c;
                n->next = c->next;
                c->next->prev = n;
                c->next = n;
            }
        }
        void display()
        {
            if (head == NULL)
            {
                cout << "{}" << endl;
                return;
            }
            cout << "{";
            DNode *c = head;
            while(c->next!=head)
            {
                cout << c->value << ", ";
                c = c->next;
            }
            cout << c->value;

            cout << "}" << endl;
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
   
        void displayReverse()
        {
            if (head == NULL)
            {
                cout << "{}" << endl;
                return;
            }
            cout << "{";
            displayReverse(head);
            cout << "\b\b}" << endl;
        }
    };
