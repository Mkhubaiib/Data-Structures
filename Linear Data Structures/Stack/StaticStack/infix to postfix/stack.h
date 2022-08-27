#include <iostream>
using namespace std;

class Stack
{
	private:
		char A[10];
		int top;
	public:
		Stack()
		{
			top =0;
		}
	void push(char x)
	{
		if (!isFull())
			A[top++]=x;
	}
	
	char pop()
	{
		if (!isEmpty())
				return A[--top];
		else
				return -1;
	}
	
	char getTop()
	{
		if (!isEmpty())
			return (A[top-1]);
		else
			return -1;
	}
	bool isEmpty()
	{
		return (top==0);
	}
	
	bool isFull()
	{
		return (top==10);
	}
};
