#include<iostream>
#include"LinkedList.h"

using namespace std;
class Queue
{
    private:
        LinkedList list;
    public:
        void enqueue(int v)
        {
            list.insert(v);
        }

        void dequee()
        {
            if (list.head==NULL) return;
            int x = list.getfirst();
            list.remove(x);
                     
        }

        int getTop(){
            return list.getfirst();
        }

};