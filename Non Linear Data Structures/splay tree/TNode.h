#include<iostream>
using namespace std;

class TNode
{
public:
    int value;
    TNode *lc;
    TNode *rc;

    TNode()
    {
        lc = NULL;
        rc = NULL;
    }
    TNode(int v)
    {
        lc = NULL;
        rc = NULL;
        value = v;
    }
};