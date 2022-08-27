// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to insert vertices to adjacency list
void insert(vector<int> adj[], int u, int v)
{
	// Insert a vertex v to vertex u
	adj[u].push_back(v);
	return;
}

// Function to display adjacency list
void printList(vector<int> adj[], int V)
{
	for (int i = 0; i < V; i++) {
		cout << i;
		for (auto j : adj[i])
			cout << " --> " << j;
		cout << endl;
	}
	cout << endl;
}

// Function to convert adjacency
// list to adjacency matrix
vector<vector<int> > convert(vector<int> adj[],
							int V)
{
	// Initialize a matrix
	vector<vector<int> > matrix(V,
								vector<int>(V, 0));

	for (int i = 0; i < V; i++) {
		for (auto j : adj[i])
			matrix[i][j] = 1;
	}
	return matrix;
}

// Function to display adjacency matrix
void printMatrix(vector<vector<int> > adj, int V)
{
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// Driver code
int main()
{
	int V = 5;

	vector<int> adjList[V];

	// Inserting edges
	insert(adjList, 0, 1);
	insert(adjList, 0, 4);
	insert(adjList, 1, 0);
	insert(adjList, 1, 2);
	insert(adjList, 1, 3);
	insert(adjList, 1, 4);
	insert(adjList, 2, 1);
	insert(adjList, 2, 3);
	insert(adjList, 3, 1);
	insert(adjList, 3, 2);
	insert(adjList, 3, 4);
	insert(adjList, 4, 0);
	insert(adjList, 4, 1);
	insert(adjList, 4, 3);

	// Display adjacency list
	cout << "Adjacency List: \n";
	printList(adjList, V);

	// Function call which returns
	// adjacency matrix after conversion
	vector<vector<int> > adjMatrix
		= convert(adjList, V);

	// Display adjacency matrix
	cout << "Adjacency Matrix: \n";
	printMatrix(adjMatrix, V);

	return 0;
}
