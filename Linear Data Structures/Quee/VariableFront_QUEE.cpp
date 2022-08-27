#include<iostream>
using namespace std;
#define N 10

class Quee
    {   
    private:
        int A[N];
        int rear, front;
    public:
        Quee()
        {
            front = rear = 0;
        }
    
        void enquee(int e)
        {
            A[rear++]=e;
        }
        int dequee()
        {   
            int a = getFirst();
            front++;
            return a;
        }
  
        int getFirst()
        {
            return A[front];
        }

        /*bool isEmpty()
        {
            return 
        }

        bool isFull()
        {
            return 
        }*/

};

int main()
{
    Quee Q;
    Q.enquee(10);
    Q.enquee(20);
    Q.enquee(30);
    Q.enquee(40);

    cout << Q.dequee() << endl;

    cout << Q.getFirst();
    return 0;
}
