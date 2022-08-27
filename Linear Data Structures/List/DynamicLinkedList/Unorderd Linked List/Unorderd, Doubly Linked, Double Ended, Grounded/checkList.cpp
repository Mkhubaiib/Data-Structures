#include<iostream>
#include"DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList list;

    list.insert(3);
    list.insert(33);
    list.insert(333);
    list.display();
    
    list.remove(3);
    list.remove(33);
    list.remove(33);
    list.display();

    return 0;
}
