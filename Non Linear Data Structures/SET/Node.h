#include<iostream>
using namespace std;
//class to implement a node of a BST
template <typename T>
class Node
{
public:
    T value;
    Node *lc;
    Node *rc;

    Node()
    {
        lc = NULL;
        rc = NULL;
    }
    
    Node(T v)
    {
        lc = NULL;
        rc = NULL;
        value = v;
    }
};