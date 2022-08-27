#include <iostream>

const int N = 5;

using namespace std;

void display(int[N][N]);
void changingEntriesTo_1(int[N][N],int[N][N]);
void pathMatrix(int [N][N]);

int main(int argc, char** argv) {
    int A[N][N]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,0,1},{0,1,0,0,1},{0,0,1,1,0}};
    int P[N][N];
    changingEntriesTo_1(A,P);
    pathMatrix(P);
    display(P);
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

void changingEntriesTo_1(int B[N][N], int P[N][N])
{
	 int i,j;
	 for(i = 0; i < N; ++i)
      	for(j = 0; j < N; ++j)
            if (B[i][j]>0)
				P[i][j]=1;
			else
				P[i][j]=0;
	
}

void pathMatrix(int P[N][N])
{
  int i,j,k;
  
	for(k = 0; k < N; ++k)
      for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            P[i][j] = P[i][j]  || (P[i][k] && P[k][j]);
    	  
}