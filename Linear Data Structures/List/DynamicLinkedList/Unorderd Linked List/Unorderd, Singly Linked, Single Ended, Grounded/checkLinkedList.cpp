#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
    LinkedList linkedList;

    linkedList.displayReverse();
    linkedList.remove(10);
    linkedList.display();
    linkedList.insert(12);
    linkedList.insert(122);
    linkedList.display();
    
    

    return 0;
} 