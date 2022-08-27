#include<iostream>
using namespace std;
#define Size 20
class MAXheap{
    private:
        int H[Size];
        int n;
 
        void heapUp(int i){
            int p;
            if(i==0) return;
            if(i%2==1)
                p=(i-1)/2;
            else
                p=(i-2)/2;

            if(H[i]>H[p]){
                int temp = H[i];
                H[i]=H[p];
                H[p]=temp;

                heapUp(p);
            }
        }
        void heapDown(int p){
            int l,r,t,g;
            
            l=2*p+1;
            r=2*p+2;
            if (p>=n) return;

            if (l<n)

                if(r<n)  
                
                    if(H[l]>H[r])
                        g=l;
                    else 
                        g=r;
                
                else
                    g=l;
                
            else
                   return;

            if(H[g]>H[p]){
                    t=H[g];
                    H[g]=H[p];
                    H[p]=t;
                }

            heapDown(g);

            
            }
        
        
    public:
           MAXheap(){
            n=0;
        }
        void insert(int v){
            if(n>=Size) return;
            H[n++]=v;
            heapUp(n-1);
        }
        void remove(){
            if(n==0) return;
            int p;
            H[0]=H[n-1]; //replace o index with last
            n--; //decrement total size
            heapDown(0);
        }

        void display(){
            cout << "[";
            for(int i=0; i<n; i++)
            cout << H[i] << ", ";
        }

        bool isEmpty(){
            return(n==0);
        }

        int getFirst(){
            if (!isEmpty()) return H[0];
        }
};