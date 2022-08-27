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
    list.insertAtStart(1);
    list.remove(12);
    list.remove(1);
    list.remove(2);
    list.remove(3);
    list.remove(5);
    list.remove(4);
    list.display();
    

    return 0;
}
