#include <iostream>
#define SIZE 10
using namespace std;

class List
{
	private:
	  //const int SIZE = 10;
	  int f;
	  int l;
	  int c;
	  int A[SIZE];
	
	public:
		List()
	{
		f=-1;
		l=0;
		c=0;

	}
	
	void insert(int e)
	{
		if(c<SIZE)
		{
		A[l] = e; 
		if (f==-1) f=0;
		l++; 
		if (l==SIZE)
			l=0;
		c++;
		}
	}

	void display()
	{
	 cout << "{";
	 int i=f;
	 int j=0;
	 while (j<c)
	 {
	 	cout << A[i] <<", ";
	 	i++; if (i==SIZE) i=0;
		j++;
	 }	
	cout <<"}" << endl;
	
	}

	void removeLast()
	{
		if(c>0) 
		{
		c--;
		l--;
		
		if (l<0){ l=SIZE-1;};
		}
	}

	void removeFirst()
	{
	if(c>0)
		{
		c--;
		f++;
		if (f==SIZE) f=0;
		}
	}

	int getInteger(int index)
	{	

		int currentIndex = index+f;

		
		if (currentIndex<SIZE && currentIndex<l){

		return A[currentIndex];}
		else if(currentIndex<l)

		{return A[index-(c-f)];}

		else
		{return -1;}
	}

	int getSize(){
		return c;
	}
};
