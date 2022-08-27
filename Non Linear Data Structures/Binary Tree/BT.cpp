#include <iostream>
#define N 7
using namespace std;
class BT
{
    private:
        char A[N];

        void inorder(int p)
        {
            int l;
            int r;
            l = 2*p+1;
            r = 2*p+2;

            if(p>N) return;
            if(l<N) inorder(l);
            cout << A[p] << ", ";
            if(r<N) inorder(r);
            
        }
        void preorder(int p)
        {
            int l;
            int r;
            l = 2*p+1;
            r = 2*p+2;

            if(p>N) return;
            cout    << A[p];

            if(l<N) preorder(l);
            if(r<N) preorder(r);
        }
        void postorder(int p)
        {
            int l;
            int r;
            l = 2*p+1;
            r = 2*p+2;

            if(p>N) return;
            if(l<N) postorder(l);
            if(r<N) postorder(r);
            cout    << A[p];
        }
    public:
        void insert()
        {
            for(int i = 0; i<N; i++)
            {
                cout << "Enter element " << i << ": ";
                cin >> A[i];
            }
        }
        void LevelWise()
        {   cout << "{";
            for(int j=0; j<N; j++)
            {
                /*if(A[j]>0)*/ cout << A[j] << ", ";
            }
            cout << "\b\b}";
        }

    void inorder()
    {
        cout << "{";
        inorder(0);
        cout << "\b\b}";
    }
    void preorder()
    {
        cout << "{";
        preorder(0);
        cout << "\b\b}";
    }
    void postorder()
    {
        cout << "{";
        postorder(0);
        cout << "\b\b}";
    }   
};

int main()
{
    BT T1;
    T1.insert();
    T1.LevelWise(); cout << endl;
    T1.preorder();  cout << endl;
    T1.postorder(); cout << endl;
    T1.inorder();   cout << endl;
    return 0;
}