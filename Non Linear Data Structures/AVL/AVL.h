#include "AVLTNode.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class AVLTree
{
    private:
    	AVLTNode* root;
    
	public:
    	AVLTree()
        {
         root = NULL;
        }
  	
	  	void Insert(int value)
  		{
  			AVLTNode *N = new AVLTNode(value);
			root  = Insert(root,N);
		}
		
        void InOrder()
        {
            InOrderTraversal(root);
        }	
	private:	
		AVLTNode* Insert(AVLTNode *P, AVLTNode* N)
  		{
        	int bf;
			if (P==NULL) 
				return N;
            else if (N->value < P->value)
        		P->lc = Insert(P->lc, N);     		
    		else if (N->value > P->value)
        		P->rc = Insert(P->rc, N);
    		else // Equal keys are not allowed in BST
        		return P;
        	
			P->height = 1 + max(height(P->lc), height(P->rc));
			bf = getBalance(P);
			
			if (bf > 1)
				{					
				if (N->value < P->lc->value)
       				 return rightRotate(P);
       			else if (N->value > P->lc->value)
       			   		{
       			   			P->lc = leftRotate(P);
       			   			return rightRotate(P);
						}
 				}
 			else
 			if (bf < -1)
			 	{
			 	if (N->value > P->rc->value)
			 		return leftRotate(P);
			 	else if (N->value < P->rc->value)
			 		{
				 
			 		P->rc = rightRotate(P->rc);
			 		return leftRotate(P);
			 		}
			    }
			else	
    		 	return P;
		}
		
		
        int height(AVLTNode* r)
        {
             	if (r==NULL) 
				 	return 0;
             	else
                	return r->height;
		}
		 
		int max(int a, int b) 
		{
    		return (a > b) ? a : b;
    	}
    		  
    	int getBalance(AVLTNode *N)
		{
			if (N == NULL)
				return 0;
			else
  				return height(N->lc) - height(N->rc);
		}		

        void InOrderTraversal(AVLTNode* R) 
		{
        	if (R==NULL) return;
            InOrderTraversal(R->lc);
            cout << "(" << R->value << ", " <<R->height <<"), " << endl;
		    InOrderTraversal(R->rc);
        }
              
           
           
       AVLTNode *rightRotate(AVLTNode *y)
		{
    	AVLTNode *x = y->lc;
    	AVLTNode *z = x->rc;
 
    	// Perform rotation
    	x->rc = y;
    	y->lc = z;
 
    	// Update heights
    	y->height = max(height(y->lc), height(y->rc)) + 1;
    	x->height = max(height(x->lc), height(x->rc)) + 1;
 
    	// Return new root
    	return x;
		}	
		
		AVLTNode *leftRotate(AVLTNode *x)
		{
   		 AVLTNode *y = x->rc;
   		 AVLTNode *z = y->lc;
 
   		 // Perform rotation
   		 x->rc = z;
		 y->lc = x;
   		 
 
    	// Update heights
    	x->height = max(height(x->lc), height(x->rc)) + 1;
    	y->height = max(height(y->lc), height(y->rc)) + 1;
 	    // Return new root
    	return y;
		}        
};
