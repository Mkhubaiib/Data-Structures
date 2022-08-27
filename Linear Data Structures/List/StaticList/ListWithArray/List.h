#include <iostream>
#define SIZE  10
using namespace std;

class List{

	private:
		int A[SIZE];
		int c;
		
	public:
		List() 
		{
			c=0;
		}
		
		
	void insert(int e){
		if(c<SIZE){
			A[c] = e;
			c++;
		}
	}
	
	void display(){
		cout<<"{";
		for(int i=0; i<c; i++){
			cout << A[i]  <<", ";
		}
		cout << "}" << endl;
	}
	
	void removeLast(){
		if(c>0){
			c--;
		}
	}
	
	void removeFirst(){
		if(c>0){
			for(int i=1; i<c; i++){
				A[i-1]=A[i];
				c--;
			}
		}
	}
	
};
