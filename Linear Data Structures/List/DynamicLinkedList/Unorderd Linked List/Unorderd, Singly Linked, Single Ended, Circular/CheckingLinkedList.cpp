#include<iostream>
#include"CircularLinkedList.h"

using namespace std;
int main()
{
    CircularLinkedList list;
    list.display();

    list.insert(10);
    list.display();

    list.remove(10);
    list.display();

    list.insert(23);
    list.insert(21);
    list.display();

    list.remove(23);
    list.display();
    list.displayReverse();
    list.insert(2);
    list.insertAtStart(4);
    list.display();
    return 0;
}
