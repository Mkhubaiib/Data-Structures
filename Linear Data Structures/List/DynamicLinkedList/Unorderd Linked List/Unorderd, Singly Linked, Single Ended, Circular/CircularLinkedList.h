//Circular Linked List
#include <iostream>
#include "Node.h"

using namespace std;

class CircularLinkedList
 {
 	private:
 		Node *head;
		 /*This is private function because we donot want in main.
		  This method is used to dispaly elements of LinkedLised in 
		  reverse oder*/
		void displayReverse(Node *x)
		{
			/*If list is empty*/
			if (x==NULL)
				return;

			/*If Linked List have only one element or
			used to print Last element of Linked List */
			else if(x->next==head) 
			{
				cout << x->value << ", ";
				return;
				}

			else
				{
				/*This is recursive function when its reached at last element
				then the above statement in (else if) print last element
				and then satrt printing elements in reverse oder*/
				displayReverse(x->next);
				cout << x->value << ", ";
				}
		}
 	public:
	 	/*Constructor*/
 		CircularLinkedList()
 		{
 			head=NULL;
		}
	
		/*Method to insert element at end of the Linked List*/
		void insert(int v)
		{
			Node *n = new Node();
			n->value = v;
			n->next = NULL;

			/*If LinkedList is empty*/
			if (head==NULL){

				/*list is empty so n become our head;*/
				head = n;
				
				/*updating the next of head with Address of head 
				because there now only one element in LinkedList*/
				head->next = head;
				
				}

			/*If LinkedList have one or more than one elements*/
			else
				{
				/*Loop for go to at the end of  LinkedList*/ 
				Node *p = head;

				while (p->next!=head)
					p = p->next;

				/*As we know, when the element occur having its next is 
				pointing towards head its mean it is last element of
				LinkedList, so we update its next with current addrees 
				of element which is n in this case and update the next of 
				n to head to make circular*/

				p->next = n;
				n->next = head;					
				}
		}
		
		/*Method to display the elements of Linked List*/
		void display()
		{
			if(head==NULL) return;
			/*Loop to iterate all elements*/
			Node *c = head;
			cout << "{";

			/*Condition is when the element occur having its next 
			pointing towards head, means it is the last element of 
			LinkedList*/
			while (c->next!=head)
				{
					cout << c->value << ", ";
					c=c->next;
				}
				/*The last element will not print in above loop
				because loop end when the next of element is head,
				but we cannot ignore last element so, the following
				line print last element*/ 
				cout << c->value;
			
			cout << "}" << endl;
		}	

		/*Method to insert element at start of the Linked List*/
		void insertAtStart(int v)
		{	
			Node *n = new Node();	
			n->value = v;
			
			/*If Linked List is empty*/
			if(head==NULL)
			{
				head=n;
				n->next=head;
			}

			else
			{
				/*loop for to go at the end of the Linked List
				because by inserting element at satrt now we
				need to update the next of last element*/
				Node *c = head;
				while (c->next!=head)
					c=c->next;
				
				n->next = head;		
				head = n;
				c->next = head;
			}
		}

		/*Function overloading*/
		 void displayReverse()
		{
			cout << "{";
			displayReverse(head);
			cout << "\b\b}" << endl;
		}	


		/*Method to remove element*/
		void remove(int v)
		{
			Node *p,*d,*c;
			c=p=d=head;
			
			//If list is empty
			if (head==NULL) return;

		
			//Searching element in list
			while (d->next!=head)
			{
				if (d->value==v)
					break;
				p=d;
				d=d->next;
			}

			/*If element not present in list, Point: at this stage all
			elements(Nodes) had checked so,*/
			if (d->value!=v) return;

			/*Diffrent conditions with respect to head
			1:  Maybe there is only one element in linked list and 
			  we want to delete that.
			2:  Maybe there are more than one but we want to remove first*/
			if (d==head){	

				//If there is only one element
				if(head->next==head)
				{
					head = NULL;
					return;
				}
				
				//If element is head
				/*Loop to iterate all element for update the the next of last element*/
				while (c->next!=head)
					c=c->next;
				
				head = head->next;
				c->next = head;
				}
			

			//If element is present between two elements or last
			else
				{
					p->next = d->next;
				}

			/*deleting the node*/
			delete d;
		}
    	
 };
