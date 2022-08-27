#include<iostream>
#include"DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList list;

    list.insert(9);
    list.insert(10);
    list.insert(3);
    list.insert(4);
    list.insert(1);
    list.insert(5);
    list.insert(6);
    list.insert(7);

    list.display();
    list.swap();
    list.display();
    return 0;
}
