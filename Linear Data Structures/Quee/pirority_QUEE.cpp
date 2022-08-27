#include<iostream>
using namespace std;
#define N 25

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
            if(!isFull())
            {
                A[rear++]=e;
            }
            else return;
            
        }
        void dequee()
        {   

            for(int i=0; i<rear-1; i++)
            {
                A[i]=A[i+1];
            }
            rear--;
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
            cout << "{ ";
            for(int j =0; j<rear; j++)
            {
                cout << A[j] << ", ";
            }
            cout << "\b\b}";
        }

        
};
class pirority_QUEE
{
    private:
        Quee Q[N];
    public:
        void enquee(int e, int p)
        {
            Q[p].enquee(e);
        }
        //highest pirority dequee
        void dequee()
        {
            for(int i =0; i<=N; i++)
            {
                if (!Q[i].isEmpty()) 
                {
                    Q[i].dequee(); return;
                }
                
            }   
        }

        void display()
        {
            Q[25].display();
        }


        
};

int main()
{

    pirority_QUEE PQ;
   PQ.enquee(10,5);
   PQ.enquee(20,15);
   PQ.enquee(30,5);
   PQ.enquee(40,15);
   PQ.enquee(50,10);
   PQ.enquee(60,11);
   PQ.enquee(70,25);
   PQ.enquee(80,10);
   PQ.enquee(90,6);
   PQ.enquee(35,8);
   PQ.enquee(45,16);
   PQ.enquee(25,15);
   PQ.enquee(15,25);
   PQ.enquee(65,15);


    PQ.display();
    return 0;
}