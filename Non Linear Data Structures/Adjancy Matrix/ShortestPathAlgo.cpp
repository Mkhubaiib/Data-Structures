#include <iostream>

const int N = 5;

using namespace std;

void display(int[N][N]);
void changingEntries(int[N][N],int[N][N]);
void pathMatrix(int [N][N]);

int main(int argc, char** argv) {
    int A[N][N]={{0,2,0,0,5},{0,0,1,3,0},{0,0,0,0,4},{0,0,0,0,2},{5,0,4,0,0}};
    int Q[N][N];
    changingEntries(A,Q);
    pathMatrix(Q);
    display(Q);
	return 0;
}


void display(int M[N][N])
{
	cout << "----------------------------------" << endl;
	for (int i=0;i<N;i++)
	{
	
		for (int j=0; j<N;j++)
			cout << M[i][j] <<"\t";
		
		cout << endl;
				
	}
	cout << "----------------------------------" << endl;
}

void changingEntries(int B[N][N], int P[N][N])
{
	 int i,j;
	 for(i = 0; i < N; ++i)
      	for(j = 0; j < N; ++j)
            if (B[i][j]==0)
				P[i][j]=90000;
			else
				P[i][j]=B[i][j];
	
}

void pathMatrix(int P[N][N])
{
  int i,j,k;
  
	for(k = 0; k < N; ++k)
      for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            P[i][j] = min(P[i][j],P[i][k]+P[k][j]);
    	  
}