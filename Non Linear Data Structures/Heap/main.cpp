#include<iostream>
#include"MAXheap.h"
using namespace std;

int main(){
    int A[15]={45,23,43,27,22,19,21,56,12,14,56,34,64,24,21};
    int i;

    MAXheap heap;
    

    //Heap sort
    for(i=0; i<15;i++){
        heap.insert(A[i]);
    
    }
    heap.display();
    cout<< endl;


    for(i=9; i>=0; i--){
        A[i]=heap.getFirst();
        heap.remove();
    }
    
    for(i=0; i<10;i++){
       cout << A[i] << ", ";
    }
    return 0;
}