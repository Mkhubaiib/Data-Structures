#include<iostream>
#include"DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList list;

   
   list.insert(1);
   list.insert(2);
   list.insert(3);
   list.insert(4);
   list.insert(5);
   list.insert(6);

   list.remove(1);

    list.display();
    

    return 0;
}
