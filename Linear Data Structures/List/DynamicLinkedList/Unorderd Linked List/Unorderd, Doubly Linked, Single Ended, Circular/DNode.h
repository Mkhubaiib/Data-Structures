#include<iostream>
using namespace std;

class DNode
{
    public:
        int value;
        DNode *next;
        DNode *prev;
        DNode()
        {
            value = 0;
            next = prev = NULL;
        }
        DNode(int v)
        {
            value = v;
            next = prev = NULL;
        }
    
};