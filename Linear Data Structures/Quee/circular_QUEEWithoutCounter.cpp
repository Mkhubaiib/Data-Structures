#include<iostream>
using namespace std;
#define N 10
class Queue
{
	private:
		int A[N];
		int front, rear;
        int next(int index)
        {
            return (++index%N);
        }
	public:
		Queue() {front = -1;  rear = -1;}

		void enquee(int value){
			A[++rear%N] = value;
			
        }
		void dequee(){
		
            front++;
			front%=N;
			
        }

		
		void display()
		{
			for(int z = ++front; z<=rear; z++)
			{
				cout << A[z] << ", ";
			}
		}

	

};

int main()
{
	Queue q;
	q.enquee(0);	
	q.enquee(1);
	q.enquee(2);
	q.enquee(3);

	q.display();

	
	return 0;
}
