#include<iostream>
#include"TNode.h"
#include<queue>
#include<stack>
using namespace std;

class BST
{
    private:
        TNode *root;
        stack <TNode*> S,T;
        queue <TNode*> Q;

        //method to calculate the numbers of leaves
        int getLeafCount(TNode *root)
        {
        if(root == NULL)                            
            return 0;
        if(root->lc == NULL && root->rc == NULL)    
            return 1;        
        else    
            return getLeafCount(root->lc) + getLeafCount(root->rc);
        }

        //method to calculate the sum of leaves
        int getLeafSum(TNode *root)
        {
        if(root == NULL)    
            return 0;
        if(root->lc == NULL && root->rc == NULL)    
            return root->value;        
        else
            return getLeafSum(root->lc)+getLeafSum(root->rc);
        }

        //minimum value of tree
        int minValue(TNode *p)
        {
            while(p->lc!=NULL) p=p->lc;
            return p->value;
        }

        //maximum value of tree
        int maxValue(TNode *p)
        {
            while(p->rc!=NULL) p=p->rc;
            return p->value;
        }
     

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


        TNode* deleteNode(TNode *p, int v)
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

   
      
            void printLeaves(TNode *r)
            {
                if(r==NULL) return;
                printLeaves(r->lc);
                printLeaves(r->rc);
                if(r->lc==NULL && r->rc==NULL)
                        cout << r->value << ", ";
                
            }
        void Enigma(TNode *root, int k, int &c){
            if(root ==NULL || c>=k)
                return;
            cout<<"root: " << root->value << " c: " << c << "\n";
            Enigma(root->rc, k, c);
            c++;
            if(c==k){
                cout<<root->value << endl;
                return;
            }
            cout<<"root: " << root->value << " c: " << c << "\n";
            Enigma(root->lc, k, c);
        }
       
        void Mystery(TNode *root, int k){
            int c=0;
            Enigma(root, k , c);
        }

            
    public:
    
        BST()
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
            
        }

        //Iterative
        void levelwise()
        {
            
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

        void postorderi()
        {
            TNode *p = root;
            if (root == NULL) return;
            S.push(root);
            while(!S.empty())
            {
                p=S.top(); S.pop();
                T.push(p);
                if(p->lc!=NULL)
                    S.push(p->lc);
                if(p->rc!=NULL)
                    S.push(p->rc);
            }
            while(!T.empty())
            {
                p=T.top();
                T.pop();
                cout<<p->value<<", ";
            }
        }

        void inorderi()
        {
            TNode *p=root;
            cout << "{ ";
            while(!S.empty()||p!=NULL)
            {
                if(p!=NULL)
                {
                    S.push(p);
                    p=p->lc;
                }
                else
                {
                    p=S.top();
                    S.pop();
                    cout << p->value << ", ";
                    p=p->rc;
                }
            }
            cout << "\b\b}";
        }

        void preorderi()
        {
            TNode *p;
            S.push(root);
            while(!S.empty())
            {
                p=S.top(); S.pop();
                cout << p->value << ", ";
                if(p->rc!=NULL)
                    S.push(p->rc);
                if(p->lc!=NULL)
                    S.push(p->lc);                   
            }
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

        void remove(int v)
        {
            root = deleteNode(root, v);
        }

     void removei(int v)
            {
            if(root->lc==NULL && root->rc==NULL && root->value==v)
                {
                    root = NULL;
                    return;
                }

            //search
            TNode *p, *d;
            d=root;
            while(d->value!=v)
            {
                p=d;
                if(v<d->value)
                    d=d->lc;
                else
                    d=d->rc;
            }

            //check leaf Node
            if(d->lc==NULL && d->rc==NULL)
            {
                if(p->lc==d) p->lc=NULL;
                else p->rc=NULL;
            }

            //one child Node
            else if( (d->lc==NULL && d->rc!=NULL) || (d->lc!=NULL && d->rc == NULL))
            {
                if(p->lc==d)
                {
                    if(d->lc!=NULL) 
                        p->lc=d->lc;
                    else p->lc=d->rc;
                }
                else
                    if(d->lc!=NULL) p->rc = d->lc;
                    else p->rc=d->rc;        
            }
            //with two childs
            else
            {
                int temp = minValue(d->rc);
                d->value = temp ;
               
            }

            delete d;
            }

        

            int maxValue()
            {
                maxValue(root);
            }
            int minValue()
            {
                minValue(root);
            }

            int getLeafCount()
            {
                getLeafCount(root);
            }

            int getLeafSum()
            {
                
                getLeafSum(root);
            }

        void printLeaves()
        {
            printLeaves(root);
        }


        void Mystery(int k){
            Mystery(root, k);
        }

    };



