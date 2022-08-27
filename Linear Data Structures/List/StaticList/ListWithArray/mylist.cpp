#include<iostream>
#include"List.h"
using namespace std;

int main(){
	List list;
	int T[10]={20,30,40,50,60,90,80,50,20,12};
	for(int i=0;i<10;i++){
		list.insert(T[i]);
	}
	list.removeFirst();
	list.removeLast();
	list.removeFirst();
	list.removeLast();
	list.display();
	return 0;
}
