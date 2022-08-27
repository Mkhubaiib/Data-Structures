#include<iostream>
#include"TNode.h"
#include<queue>

using namespace std;

class Splaytree{
 	private:
        TNode *root;
 		 void preorder(TNode *r)
        {
            if(r==NULL) return;
            cout << r->value << ", ";
            preorder(r->lc);
            preorder(r->rc);
        }

        void postorder(TNode *r)
        {
            if(r==NULL) return;
            postorder(r->lc);
            postorder(r->rc);
            cout << r->value << ", ";
        }

        void inorder(TNode *r)
        {
            if(r==NULL) return;
            inorder(r->lc);
            cout << r->value << ", ";
            inorder(r->rc);
        }


 			
		TNode *rightRotate(TNode *x)
		{
    	TNode *y = x->lc;
    	x->lc = y->rc;
    	y->rc = x;
    	return y;
		}
 

		TNode *leftRotate(TNode *x)
		{
   			TNode *y = x->rc;
    		x->rc = y->lc;
   			y->lc = x;
    		return y;
		}


		TNode *splay(TNode *root, int n)
		{
		    // Base cases: root is NULL or
		    // key is present at root
		    if (root == NULL || root->value == n)
		        return root;
		 
		    // Key lies in left subtree
		    if (root->value > n)
		    {
		        // Key is not in tree, we are done
		        if (root->lc == NULL) return root;
		 
		        // Zig-Zig (Left Left)
		        if (root->lc->value > n)
		        {
		            // First recursively bring the
		            // key as root of left-left
		            root->lc->lc = splay(root->lc->lc, n);
		 
		            // Do first rotation for root,
		            // second rotation is done after else
		            root = rightRotate(root);
		        }
		        else if (root->lc->value < n ) // Zig-Zag (Left Right)
		        {
		            // First recursively bring
		            // the key as root of left-right
		            root->lc->rc = splay(root->lc->rc, n);
		 
		            // Do first rotation for root->left
		            if (root->lc->rc != NULL)
		                root->lc = leftRotate(root->lc);
		        }
		 
		        // Do second rotation for root
		        return (root->lc == NULL)? root: rightRotate(root);
		    }
		    else // Key lies in right subtree
		    {
		        // Key is not in tree, we are done
		        if (root->rc == NULL) return root;
		 
		        // Zag-Zig (Right Left)
		        if (root->rc->value > n)
		        {
		            // Bring the key as root of right-left
		            root->rc->lc = splay(root->rc->lc, n);
		 
		            // Do first rotation for root->right
		            if (root->rc->lc != NULL)
		                root->rc = rightRotate(root->rc);
		        }
		        else if (root->rc->value < n)// Zag-Zag (Right Right)
		        {
		            // Bring the key as root of
		            // right-right and do first rotation
		            root->rc->rc = splay(root->rc->rc, n);
		            root = leftRotate(root);
		        }
		 
		        // Do second rotation for root
		        return (root->rc == NULL)? root: leftRotate(root);
		    }
		    
		}
		


	
	
	public:
		Splaytree()
		{root = NULL;}
		
		void insert(int v)
        {
            TNode *n = new TNode(v);
            if(root == NULL)
            {
                root = n;
                return;
            }

            TNode *t = root;
            TNode *p = root;
            while (p!=NULL)
            {
                t=p;
                if (n->value < p->value)
                    p = p->lc;
                else p = p->rc;
            }
            if (n->value < t->value)
                t->lc=n;
            else t->rc = n;

        root =splay(root,v);;    
			
        }
	//Recursives
        void preorder()
        {
            cout << "{ ";
            preorder(root);
            cout << " \b\b}";

        }
        void inorder()
        {
            cout << "{ ";
            inorder(root);
            cout << "\b}";
        }
        void postorder()
        {
            cout << "{ ";
            postorder(root);
            cout << " \b\b}";
        }
		  //Iterative
        void levelwise()
        {
            queue<TNode*>Q;
            TNode *p;
            Q.push(root);
            while(!Q.empty())
            {
                p=Q.front();
                Q.pop();
                cout << p->value;
                if(p->lc!=NULL)
                    Q.push(p->lc);
                if(p->rc!=NULL)
                    Q.push(p->rc);
            }
        }
		
 };

