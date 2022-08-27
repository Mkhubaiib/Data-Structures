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
			if (x==NULL)	return;
			
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
                    head = tail = n;
				/*If list is not empty*/
                else
                    {
                    Node *p=head;
					/*Loop for to go at the end of list*/
                    while (p->next!=NULL)
                        p = p->next;

                    //p->next = n;
					tail->next=n;
                    tail = n;					
                    }
            } 

        /*Method to insert element at start*/  
        void insertAtStart(int v)
		{
			Node *n = new Node();
			n->value = v;
			n->next = head;
			head=n;
			if(head==NULL) tail = n;	/*If list is empty*/					
		}

		/*Method to dispaly elements of list*/
        void display()
		{
			/*If list is empty a bracket will show so*/
			if(head==NULL) return;

			Node *c=head;
			cout << "{";
			/*Loop to print elements untill tail occur*/
			while (c!=NULL) //simply also can be write as c!=NULL
				{
					cout << c->value << ", ";
					c=c->next;
				}   
			cout << "\b\b}" << endl;
		}   

		/*Method to remove element from list*/
        void remove(int v)
		{
			Node *p,*d;
			p=d=head;

			/*If list is empty*/
			if (head==NULL) return;
            
			/*Searching the element in linked list*/
			while (d!=NULL)
			{
				if (d->value==v)
					break;
				p=d;
				d=d->next;
			}

			/*If element is not present*/
			if (d==NULL) return;
            
			/*If element is first*/
			if (d==head)
				head = head->next;

			/*If element is last*/
			else if(d==tail){ p->next = NULL; tail=p;}
			/*If element is present between the list*/
			else
				{
					p->next = d->next;
				}
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

		void deleteNodes(int val, char criteria)
		{	
			//if empty
			if (head==NULL) return;
			//search
			Node *f = head;
			Node *p = head;
			while(f!=NULL)
			{	
				if(f->value==val) break;
				p=f;
				f=f->next;
			}

		if(criteria=='G')
		{
			p->next=NULL; tail=p;
			Node *temp = f; 
			int condition;
			if(f==head) condition=1;
			Node *tempnext; 
			while (f->next!=NULL)
			{
				tempnext = f->next;
				delete f;
				f=tempnext;

			}
			
			
			if(condition==1) {head=tail=NULL; return;}
				
			
		}
		else if(criteria=='L')
		{
			int condition;
			if(f==tail) condition=1;

			Node *temp =head; 
			Node *tempnext; 
			
			while (temp!=f)
			{
				tempnext = temp->next;
				delete temp;
				temp=tempnext;

			}

			head=f->next;
			delete f;
			if(condition==1) {head=tail=NULL; return;}
		}

		}
};
