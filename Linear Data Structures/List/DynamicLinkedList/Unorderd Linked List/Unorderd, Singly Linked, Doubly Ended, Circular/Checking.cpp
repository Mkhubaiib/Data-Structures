#include<iostream>
#include"DoubleEndedLinkedList.h"
using namespace std;
int main()
{
    DoubleEndedLinkedList list;
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.remove(5);
    list.remove(44);

    list.remove(63);
    list.remove(6);
    list.remove(66);


    list.display();
    



    
    return 0;
}