#include<iostream>
#include"Node.h"
#include <math.h>
#include"stack"
using namespace std;



// Class to implement a Set using BST
template <typename T>
class Set
{
    private:

        // Pointer to the root of theBST storing the set data
        Node<T>* root;

        //method to calculate the number of elements in the set
        int getSize(Node<T> *root)
        {
        if(root == NULL) return 0;     
        return 1 + getSize(root->lc) + getSize(root->rc);
        }

        /*
            Function to insert a node with
            given data into the BST
            
            @param r pointer to the root node
            @param d the data to insert
            @return pointer to the root of the resultant BST
        */
        Node<T>* insert(Node<T>* P, Node<T>* N)
            {
        
                // Add the node when NULL node is encountered
                if (P==NULL) 
				    return N;
        
                // Traverse the left subtree if data
                // is less than the current node
                else if (N->value < P->value)
        		    P->lc = insert(P->lc, N); 
        
                // Traverse the right subtree if data
                // is greater than the current node
    		    else if (N->value > P->value)
        		    P->rc = insert(P->rc, N);
            
                else // Equal keys are not allowed in SET
                    return P;
            }



        // Function to print the inorder traversal of the BST
        void inorder( Node<T>*r)
        {
            if(r==NULL) return;
            inorder(r->lc);
            cout << r->value << ", ";
            inorder(r->rc);
        }

        /*
            Function to check if BST contains a node
            with the given data
            
            @param r pointer to the root node
            @param d the data to search
            @return 1 if the node is present else 0
        */

        int containsNode(Node<T>* r, T d)
        {
            if (r == NULL) {
                return 0;
            }
            int x = r->value == d ? 1 : 0;
            return x | containsNode(r->lc, d) | containsNode(r->rc, d);
        }
               
        /*minimum value of tree
            Function to minimum element of set
            @param p the root node
        */
        T minValue(Node<T> *p)
        {
            while(p->lc!=NULL) p=p->lc;
            return p->value;
        }
        /*
            Function to remove the element of set
            @param p the root node
            @param v the element to remove
        */
        Node<T>* deleteNode(Node<T> *p, int v)
        {
            if(p==NULL) return p;
            if(v<p->value) p->lc = deleteNode(p->lc,v);
            else if(v>p->value) p->rc=deleteNode(p->rc,v);
            else{
                if(p->lc==NULL) return p->rc;
                else if (p->rc==NULL) return p->lc;
                p->value=minValue(p->rc);
                p->rc = deleteNode(p->rc,p->value);
            }
            return p;
        }
    public:
    
        // Default constructor
        Set()
        {
            root = NULL;           
        }

        // Copy constructor
        Set(const Set& s)
        {
            root = s.root;
        }

        /*
            Function to Add an element to the set
    
            @param v the element to add to the set
        */
        void add(const T v)
        {
            Node<T>* N = new Node<T>(v);
			root  = insert(root,N);
        }


        /*
            Function to return the current size of the Set
            
            @return size of set
        */
        int getSize()
        {
            return getSize(root);
        }
        


        // Function to print the contents of the set
        void displaySet()
        {
            cout << "{ ";
            inorder(root);
            cout << "\b\b}" << endl;
        }

        /*
		Function to convert the set into an array
		
		@return array of set elements
	    */

        T* toArray()
        {
            T* A = new T[getSize()];
            int i = 0;
            stack<Node<T>*> nodeStack;
            nodeStack.push(this->root);

            while (!nodeStack.empty()) {
                Node<T>* node;
                node = nodeStack.top();
                nodeStack.pop();

                A[i++] = node->value;

                if (node->rc)
                    nodeStack.push(node->rc);
                if (node->lc)
                    nodeStack.push(node->lc);
            }
            return A;
        }

        /*
            Function to check whether the set contains an element
            
            @param data the element to search
            @return relut of check
        */
        bool contains(T data)
        {
            return containsNode(root, data) ? true : false;
        }
 
        /*
            Function to remove the element of set
            @param v the element to remove
        */
        void remove(T v)
        {
            root = deleteNode(root, v);
        }

        	/*
		Function to compute the union of two sets
		
		@param s set to find union with
		@return the union set
        */
        Set unionSet(Set& s)
        {
            Set<T> resultant;

            // Second set is returned
            // if first set is empty
            if (root == NULL)
                return resultant;

            // First set is returned
            // if second set is empty
            if (s.root == NULL)
                return *this;

            // The elements of the first set
            // are added to the resultant set
            stack<Node<T>*> nodeStack;
            nodeStack.push(root);

            // Preorder traversal of the BST
            while (!nodeStack.empty()) {
                Node<T>* node;
                node = nodeStack.top();
                nodeStack.pop();

                // The data is added to the resultant set
                resultant.add(node->value);

                if (node->rc)
                    nodeStack.push(node->rc);
                if (node->lc)
                    nodeStack.push(node->lc);
            }

            // The elements of the second set
            // are added to the resultant set
            stack<Node<T>*> nodeStack1;
            nodeStack1.push(s.root);

            while (!nodeStack1.empty()) {
                Node<T>* node;
                node = nodeStack1.top();
                nodeStack1.pop();

                resultant.add(node->value);

                if (node->rc)
                    nodeStack1.push(node->rc);
                if (node->lc)
                    nodeStack1.push(node->lc);
            }

            return resultant;
        }

        /**
            Computes the intersection of two sets
            
            @param s the set to find intersection with
            @return the intersection set
        */
        Set intersectionSet(Set& s)
        {
            Set<T> resultant;
            stack<Node<T>*> nodeStack;
            nodeStack.push(root);

            while (!nodeStack.empty()) {
                Node<T>* node;
                node = nodeStack.top();
                nodeStack.pop();
                if (s.contains(node->value)) {
                    resultant.add(node->value);
                }
                if (node->rc)
                    nodeStack.push(node->rc);
                if (node->lc)
                    nodeStack.push(node->lc);
            }
            return resultant;
        }

    /*
		Function to compute the complement of the set
		
		@param U the universal set
		@return the complement set
	*/
	Set complementSet(Set& U)
	{
		return (U - *this);
	}


	/*
		Function that checks equality of two sets
		
		@param s set to check equality with
		@return boolean value denoting result of check
	*/
	bool operator==(Set& s)
	{
		if (s.getSize() != getSize()) {
			return false;
		}
		stack<Node<T>*> nodeStack;
		nodeStack.push(this->root);

		while (!nodeStack.empty()) {
			Node<T>* node;
			node = nodeStack.top();
			nodeStack.pop();
			if (!s.contains(node->value)) {
				return false;
			}
			if (node->rc)
				nodeStack.push(node->rc);
			if (node->lc)
				nodeStack.push(node->lc);
		}
		return true;
	}

	/*
		Function to compute the difference of two sets
		
		@param s the set to be subtracted
		@return the difference set
	*/
	Set operator-(Set& s)
	{
		Set<T> resultant;
		stack<Node<T>*> nodeStack;
		nodeStack.push(this->root);

		while (!nodeStack.empty()) {
			Node<T>* node;
			node = nodeStack.top();
			nodeStack.pop();
			if (!s.contains(node->value)) {
				resultant.add(node->value);
			}
			if (node->rc)
				nodeStack.push(node->rc);
			if (node->lc)
				nodeStack.push(node->lc);
		}
		return resultant;
	}

    /*
		Function to print the cartesian product of two sets
		
		@param s the set to find product with
	*/
	void displayProduct(Set& s)
	{
		int i, j, n2 = s.getSize();
		T* A = toArray();
		T* B = s.toArray();

		i = 0;

		cout << "{ ";
		for (i = 0; i < getSize(); i++) {
			for (j = 0; j < n2; j++) {
				cout << "{ " << A[i] << " " << B[j] << " } ";
			}
		}
		cout << "}" << endl;
	}

	// Function to print power set of the set
	void displayPowerSet()
	{
		int n = pow(2, getSize());
		T* A = toArray();
		int i;
		while (n-- > 0) {
			cout << "{ ";
			for (int i = 0; i < getSize(); i++) {
				if ((n & (1 << i)) == 0) {
					cout << A[i] << " ";
				}
			}
			cout << "}" << endl;
		}
	}


    };




