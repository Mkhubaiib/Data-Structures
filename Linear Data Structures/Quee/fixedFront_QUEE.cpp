#include<iostream>
using namespace std;
#define N 10

class Quee
    {   
    private:
        int A[N];
        int rear;
    public:
        Quee()
        {
            rear = 0;
        }
    
        void enquee(int e)
        {
            A[rear++]=e;
        }
        int dequee()
        {   
            int a = getFirst();
            for(int i=0; i<rear-1; i++)
            {
                A[i]=A[i+1];
            }
            rear--;
            return a;
        }

        int getFirst()
        {
            return A[0];
        }

        bool isEmpty()
        {
            return rear == 0;
        }

        bool isFull()
        {
            return rear==N;
        }

        void display()
        {
            if (rear==0)cout << -1 << endl;
            for(int j =0; j<rear; j++)
            {
                cout << A[j] << endl;
            }
        }

};

int main()
{
    Quee Q;
    Q.enquee(10);
    Q.enquee(20);
    Q.enquee(30);
    Q.enquee(40);
    Q.enquee(50);
    Q.enquee(60);
    Q.enquee(70);
    Q.enquee(80);
    Q.enquee(90);
    Q.enquee(0);
    cout << Q.dequee() << endl;
    cout << Q.dequee() << endl;
    cout << Q.dequee() << endl;
    cout << "Elements:" << endl;
    Q.display();
    cout << Q.isEmpty() << endl;
    cout << Q.isFull();
   
 

    return 0;
}
