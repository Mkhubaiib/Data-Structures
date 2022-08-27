#include<iostream>
#include"DoublyLinkedList.h"


using namespace std;

int main()
{
    DoublyLinkedList list;

   
   list.insert(3);
   list.insert(2);
    list.display();
    list.remove(2);
 
    
    return 0;
}
