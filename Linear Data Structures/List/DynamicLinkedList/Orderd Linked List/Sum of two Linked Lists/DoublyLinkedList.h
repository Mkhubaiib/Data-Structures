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
            else if (head->value>v)
            {
                n->prev = head->prev;
                head->prev->next = n;
                head->prev = n;
                n->next = head;
                head = n;
            }
            else
            {
            DNode *c = head->next;
            while(c!=head)
            {
                if(c->value>v)   break;
                 
                c=c->next;
            }

                c->prev->next = n;
                n->prev = c->prev;
                c->prev = n;
                n->next = c;  

                //delete if repeted
                if(n->value==n->prev->value )
                    {
                        n->prev->next=n->next;
                        n->next->prev=n->prev; 
                        delete n;
                    }      
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
            
       
            
       

        //Function sum
        DoublyLinkedList combine operator + (DoublyLinkedList list1)
        {
                DoublyLinkedList list3;
        
                    DNode *c1 = list1.head;
                    DNode *c2 = list2.head;

                    while(c1->next!=list1.head)
                    {
                        list3.insert( c1->value);
                        c1 = c1->next;
                    }
                        list3.insert( c1->value);

                    
                    while(c2->next!=list2.head)
                    {
                        list3.insert(c2->value);
                        c2 = c2->next;
                    }
                        list3.insert(c2->value);

               return list3;
        }

    };
