#include <iostream>

#define MAX_NODES 10
using namespace std;

class Graph
{
	private:
		int n;
		char V[MAX_NODES];
		int A[MAX_NODES][MAX_NODES];
	public:
		Graph()
		{
			n=0;
			for (int i=0;i<MAX_NODES;i++)
				for (int j=0;j<MAX_NODES;j++)
				    A[i][j] = 0;
		}
		void addVertex(char vertex)
		{
			if (search(vertex)<0)
			{
				V[n] = vertex;
				n++;
			}
			else
				cout <<"vertex already added" << endl;
		}
		void addEdge(char from, char to)
		{
			int f=search(from);
			int t=search(to);
			if (f<0 || t<0)
				{	cout << from <<" vertex " << to <<" not found " << endl;
					return;
				}
			A[f][t] = 1;
			A[t][f] = 1;    
		}
		
		void showMatrix()
		{
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<n;j++)
					cout << A[i][j] << " ";					
				cout << endl;
			}
		}
		int search(char vertex)
		{
			for (int i=0;i<n;i++)
				if (V[i] == vertex)
					return i;
			return -1;
		}
};


int main(int argc, char** argv) {
	Graph g;
	g.addVertex('a');
	g.addVertex('b');
	g.addVertex('c');
	g.addVertex('d');
	g.addVertex('e');
	g.addVertex('f');
	g.addVertex('g');
	//g.addVertex('a');
	
	g.addEdge('a','b');
	g.addEdge('a','c');
 	g.addEdge('a','d');
 	g.addEdge('b','d');
 	g.addEdge('c','e');
 	g.addEdge('c','f');
 	g.addEdge('e','f');
 	g.addEdge('f','a');
 	//g.addEdge('a','x');
 	g.showMatrix();
 	
	return 0;
}
