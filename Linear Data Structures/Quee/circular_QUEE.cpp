#include<iostream>
using namespace std;
#define N 10
class Queue
{
	private:
		int A[N];
		int front, rear, c;
	public:
		Queue() {front = 0;  rear = 0; c=0;}

		void enquee(int value){
			if(!isFull()){
            A[rear++ % 10] = value;
			c++;
			}
        }
		void dequee(){
			if(!isEmpty())
			{
            front++;
			c--;
			front%=N;
			}
        }
		bool isFull()
		{
			return (c==N);
		}
		bool isEmpty()
		{
			return (c==0);
		}

};

int main()
{
	Queue q;
	q.enquee(33);
	q.enquee(33);
	q.enquee(33);
	q.enquee(33);
	q.enquee(33);
	q.enquee(33);
	q.enquee(33);
	q.enquee(33);
	q.enquee(33);
	q.enquee(33);

	cout << q.isEmpty();
	cout << q.isFull();
	return 0;
}