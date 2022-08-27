#include <iostream>
#include <bits/stdc++.h>
#include "Vertex.h"
#include <list>


using namespace std;
class Graph
{
	private:
		list <Vertex> A;


	public:

		void addVertex(char vertex)
		{
			if (search(vertex).value=='N')
			{
				Vertex V;
				V.value = vertex;
				A.push_back(V);
			}
			else
				cout <<"vertex already added" << endl;
		}


		void addEdge(char from, char to)
		{
			Vertex f = search(from);
			Vertex t = search(to);
		  			
			if (f.value=='N' || t.value=='N')
				{	cout << from <<" vertex " << to <<" not found " << endl;
				
				}

			list<Vertex>::iterator it;
			for (it = A.begin(); it != A.end(); ++it){	
				if(it->value==f.value)	it->edge.push_back(to);
				if(it->value==t.value)	it->edge.push_back(from);
			}	
		

		}
		
		void showAdjancyList()
		{
			list<Vertex>::iterator it;
			for (it = A.begin(); it != A.end(); ++it){	
				cout << "Vertex " << it->value << ": ";	
				for (list<char>::iterator i=it->edge.begin(); i!=it->edge.end(); i++)
       				cout << *i << " ";		
				cout << endl;
			}	
		}

		void print(list<char> A){
				list<char>::iterator it;
			for (it = A.begin(); it != A.end(); ++it){	
				cout << *it << ","	;
				
			}	
		}
		Vertex search(char vertex)
		{
			list<Vertex>::iterator it;
			for (it = A.begin(); it != A.end(); ++it){
				if(it->value==vertex)
					return *it;		
			}	
			Vertex temp;
			temp.value = 'N';
			return temp;
			
		}

		int getSize(){
			return A.size();
		}
	
};

void printMatrix(vector<vector<int> > adj, int V)
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adj[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char** argv) {
	Graph g;
	g.addVertex('a');
	g.addVertex('b');
	g.addVertex('c');
	g.addVertex('d');
	g.addVertex('e');
	g.addVertex('f');
	g.addVertex('g');
	
	
	g.addEdge('a','b');
	g.addEdge('a','c');
 	g.addEdge('a','d');
 	g.addEdge('b','d');
 	g.addEdge('c','e');
 	g.addEdge('c','f');
 	g.addEdge('e','f');
 	g.addEdge('f','a');
 
 	g.showAdjancyList();
 	cout << g.getSize() << endl;

	return 0;
}

