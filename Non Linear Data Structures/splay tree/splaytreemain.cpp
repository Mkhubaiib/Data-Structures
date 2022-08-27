#include<iostream>
#include"Splaytree.h"

using namespace std;

int main(){
	Splaytree sp;
	sp.insert(100);
	sp.insert(50);
	sp.insert(200);
	sp.insert(40);
	sp.insert(30);
	sp.insert(20);
	sp.preorder();
	
	return 0;
}
