#include<iostream>
#include"Set.h"
using namespace std;
int main()
{
	
	// Create Set A
	Set<int> A;

	// Add elements to Set A
 	A.add(1);
    A.add(2);
    A.add(3);
    A.add(2);
    A.add(323);

	// Display the contents of Set A
	cout << "A = ";
	A.displaySet();
 
	// Checkink Size of Set
	cout << "The size of set is " <<  A.getSize();
	cout << "\n";
	
	 // Check if Set A contains some elements
    cout << "A " << (A.contains(3) ? "contains"  : "does not contain")  << " 3" << endl;
    cout << "A " << (A.contains(4) ? "contains"  : "does not contain")  << " 4" << endl;
    cout << endl;

	//Getting elements of set in array
	int* arr = A.toArray();
    
	cout << "[";
	for(int i=0; i<A.getSize(); i++)
		cout << arr[i] << ",";
	cout << "\b]" << "\n\n";
    
	//To remove 323
	A.remove(323);
	cout << "After removing 323\n";
	A.displaySet();

	cout<<"\n";
	//Create Set B
	Set <int> B;
	// Add elements to Set A
    B.add(1);
    B.add(2);
    B.add(4);
	// Set D contains the union
	// of the Sets A and B
	Set<int> D = A.unionSet(B);
	cout << "A union B = ";
	D.displaySet();
	cout << endl;

	
	// Set E contains the intersection
	// of the Sets A and B
	Set<int> E = A.intersectionSet(B);
	cout << "A intersection B = ";
	E.displaySet();
	cout << endl;

    // Display the contents of Set B
    cout << "B = ";
    B.displaySet();
    
    cout << "P(B) = " << endl;
    B.displayPowerSet();
    cout << endl;
 
    // Create Set C
    Set<int> C;
    C.add(1);
    C.add(2);
    C.add(4);
 
    // Display the contents of Set C
    cout << "C = ";
    C.displaySet();
    cout << endl;
 
    // Set F contains the difference
    // of the Sets A and B
    Set<int> F = A - B;
    cout << "A - B = ";
    F.displaySet();
    cout << endl;

   // Equality tests
    cout << "Equality of Sets:" << endl;
 
    cout << "A "
         << ((A == B) ? "" : "!") << "= B"
         << endl;
    cout << "B "
         << ((B == C) ? "" : "!") << "= C"
         << endl;
    cout << "A "
         << ((A == C) ? "" : "!") << "= C"
         << endl;
    cout << endl;
 
   // Display the product
    cout << "A x B = ";
    A.displayProduct(B);
    cout << endl;
    Set<int> U;
    U.add(1);
    U.add(2);
    U.add(3);
    U.add(4);
    U.add(5);
    U.add(6);
    U.add(7);
 
    // Complements of the respective Sets
    Set<int> A1 = A.complementSet(U);
    Set<int> B1 = B.complementSet(U);
    Set<int> C1 = C.complementSet(U);
 
    cout << "A' = ";
    A1.displaySet();
    cout << "B' = ";
    B1.displaySet();
    cout << "C' = ";
    C1.displaySet();
    return 0;


}