#include<iostream>
#include"LinkedList.h"

using namespace std;
class Stack
{
    private:
        LinkedList list;
    public:
        void push(int v)
        {
            list.insertAtStart(v);
        }
        int pop()
        {
            int x = list.getfirst();
            if (x==-1) 
                return -1;
            else
            {
                list.remove(x);
                return x;   
            }

            
        }

};