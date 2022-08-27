#include <iostream>
#include "mylist.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	List list;
	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	// list.insert(50);
	// list.insert(60);
	// list.insert(70);
	// list.insert(80);
	//list.insert(90);
	//list.insert(100);
	list.display();
	
	
	list.removeFirst();
	list.display();
	
	list.insert(200);
	list.display();
	
	list.removeLast();
	list.display();

	list.removeLast();
	list.removeLast();

	list.display();
	list.insert(25);
	list.insert(21);
	list.insert(23);
	list.insert(237);
	list.insert(235);
	;
	list.display();
	
	for(int i=0;i<list.getSize();i++){
		cout << list.getInteger(i) << endl;
	}
	return 0;
}

	