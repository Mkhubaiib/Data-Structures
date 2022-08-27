//Make Double Ended Linked 
#include<iostream>
#include"Node.h"
using namespace std;
class DoubleEndedLinkedList
{
    private:
        Node *head;
        Node *tail;

		/*we cannot want that user use this function
		Thatsway, it is in private*/
		void displayReverse(Node *x)
		{
			/*When completely itrate then start returning to previous call*/
			if (x->next==head)
			{
				cout << x->value << ", ";
				return;
			}	
			
			else
				{
				/*Iterate, first go to last element then 
				start shifting controll to previous call*/
				displayReverse(x->next);
				cout << x->value << ", ";
				}
		}

    public:
        DoubleEndedLinkedList()
        {
            tail = head = NULL;
        }

		/*Method to insert element at last of List*/
        void insert(int v)
            {
                Node *n = new Node();
                n->value = v;
                n->next = NULL;

				/*If list is empty*/
                if (head==NULL)
				{
                    head = tail = n;
					tail->next=head;
				}
				/*If list is not empty*/
                else
                    {
                    /*Node *p=head;
					//Loop for to go at the end of list
                    while (p->next!=head)
                        p = p->next;*/

                    tail->next = n;
                    tail = n;
					tail->next=head;					
                    }
            } 

        /*Method to insert element at start*/  
        void insertAtStart(int v)
		{
			Node *n = new Node();
			n->value = v;
			n->next = head;
			/*If list is empty*/
			if(head==NULL)
			{
				head = tail = n; tail->next=head;
			}			
					
			/*If list have elements*/
			
			/*Loop for to go at the end of list*/
			else
			{  /*Node *p=head;
					//Loop for to go at the end of list
                    while (p->next!=head)
                        	p = p->next;*/
					head=n;
					tail->next=head;
						
			} 
			
		}

		/*Method to dispaly elements of list*/
        void display()
		{
			/*If list is empty a bracket will show so*/
			if(head==NULL) return;

			Node *c=head;
			cout << "{";
			/*Loop to print elements untill tail occur*/
			while (c->next!=head) //simply also can be write as c!=NULL
				{
					cout << c->value << ", ";
					c=c->next;
				}   
			cout << c->value; 
			cout << "}" << endl;
		}   

		/*Method to remove element from list*/
        void remove(int v)
		{
			Node *p,*d;
			p=d=head;

			/*If list is empty*/
			if (head==NULL) return;
            /*If list have 1 elemnt*/
			if (head->value==v && head->next==head) {head = tail = NULL; return;}
			/*If element is first*/
			if (d->value==v)
				{
				Node *r = head;
				while (r->next!=head) r = r->next;
				head = head->next;
				r->next = head; 
				delete d; return;
				}
			/*Searching the element in linked list*/
			while (d->next!=head)
			{
				if (d->value==v)
					break;
				p=d;
				d=d->next;
			}

			/*If element is present between the list*/				
			if(d->next!=head)
				{
					p->next = d->next;
				}

			/*If element is last*/
			else if(d->value==v)
			{ 
				p->next = head; 
				tail = p;
			}
			else  return;

			delete d;
		}

		/*Function overloadind
		It will used to print elements in reverse oder*/
		void displayReverse()
		{
			/*If list is empty a bracket will show so just following do for that*/
			if(head==NULL) return;

			cout << "{";
			displayReverse(head);
			cout << "\b\b}" << endl;
		}
};
