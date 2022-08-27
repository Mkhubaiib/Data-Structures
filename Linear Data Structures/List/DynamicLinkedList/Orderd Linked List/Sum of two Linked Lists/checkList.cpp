#include<iostream>
#include"DoublyLinkedList.h"

using namespace std;


int main()
{
    DoublyLinkedList list1;
    DoublyLinkedList list2;
    DoublyLinkedList list3;

    //Elements in first list
    list1.insert(1);
    list1.insert(1);
    list1.insert(3);
    list1.insert(8);
    list1.insert(5);
    list1.insert(9);
    list1.insert(10);
    list1.insert(11);
    list1.display();
    //Elements in Second list
    list2.insert(3);
    list2.insert(4);
    list2.insert(2);
    list2.insert(7);
    list2.insert(5);
    list2.insert(7);
    list2.insert(6);
    list2.insert(8);
    list2.display();
    cout << "Combine";
    list3.combine(list1,list2).display();

    return 0;
}
