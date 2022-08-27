#include<iostream>
#include"DoubleEndedLinkedList.h"
using namespace std;
int main()
{
    DoubleEndedLinkedList list;
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insertAtStart(3);
    list.insertAtStart(2);
    list.insertAtStart(1);
    list.display();
    list.deleteNodes(4,'G');
    list.display();


    
    return 0;
}