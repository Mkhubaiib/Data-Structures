#include <iostream>

const int N = 5;

using namespace std;

void display(int[N][N]);

void multiply(int [N][N], int [N][N], int [N][N]);
void add(int [N][N], int [N][N], int [N][N]);
void pathMatrix(int[N][N],int[N][N]);

int main(int argc, char** argv) {

	int A[N][N]={{0,1,1,0,0},{1,0,0,1,0},{1,0,0,0,1},{0,1,0,0,1},{0,0,1,1,0}};
    int A2[N][N];
    int A3[N][N];
    int A4[N][N];
    int A5[N][N];
    int B[N][N];
    int P[N][N];
    
   
    
    display(A);
    multiply(A,A,A2);
    display(A2);
 	multiply(A,A2,A3);
 	display(A3);
 	multiply(A,A3,A4);
 	display(A4);
 	multiply(A,A4,A5);
 	display(A5);
 	add(A,A2,B);
    add(A3,B,B);
    add(A4,B,B);
    add(A5,B,B);
    display(B);
    pathMatrix(B,P);
    
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

void multiply(int A[N][N], int B[N][N], int M[N][N])
{
  int i,j,k;
  
	for(i = 0; i < N; ++i)
      for(j = 0; j < N; ++j)
      {
	  	M[i][j] = 0;
            for(k = 0; k < N; ++k)
            {
                M[i][j] += A[i][k] *B[k][j];
            }    	
	  }
}

void add(int A[N][N], int B[N][N], int C[N][N])
{
	 int i,j;
	 for(i = 0; i < N; ++i)
      	for(j = 0; j < N; ++j)
            C[i][j] = A[i][j] + B[i][j];
          	
}

void pathMatrix(int B[N][N], int P[N][N])
{
	 int i,j;
	 for(i = 0; i < N; ++i)
      	for(j = 0; j < N; ++j)
            if (B[i][j]>0)
				P[i][j]=1;
			else
				P[i][j]=0;
	
}


