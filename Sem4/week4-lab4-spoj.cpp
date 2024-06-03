#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

void printVector (vector <vector <int>> A)
{
  int n = A.size();
  
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
       printf("%d ", A[i][j]); 
      }
      printf("\n");
    }
    
  return;
}

vector<vector<int>> subMatrix(vector<vector<int>> A, int n, int x0, int y0)
{
  /*
  Dada una matriz cuadrada A de dimension k, determina una submatriz cuadrada subA de dimensión n tal que n <= k a partir del elemento en la
  posicion (x0,y0) hasta el que está en la posición (x1,y1), para 0 <= x0,x1,y0,y1 < n. Para el caso
  de determinar una submatriz de dimension n = 1, retorna el elemento en la posición (x0,y0).
  */
  vector<vector<int>> subA (n, vector<int> (n));

  int i = 0;
  int j = 0;
  
  for (int k = x0; k < x0 + n; k++)
    {
      for (int w = y0; w < y0 + n; w++)
      {
        subA[i][j] = A[k][w];
        j++;
      }
      j = 0;
      i++;
    }
    return subA; 
}

vector<vector<int>> matrixAddition (vector<vector<int>> A, vector<vector<int>> B, int n)
{
  vector<vector<int>> C (n, vector<int> (n,0));
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  
  return C;
}

vector<vector<int>> matrixSubstraction (vector<vector<int>> A, vector<vector<int>> B, int n)
{
  vector<vector<int>> C (n, vector<int> (n,0));
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
  
  return C;
}

vector<vector<int>> matrixGrouping (vector<vector<int>> C11, vector<vector<int>> C12, vector<vector<int>> C21, vector<vector<int>> C22, int n)
{
  /*
  Dadas cuatro submatrices C11,C12,C21,C22 correspondientes a cuatro cuartos de una matriz cuadrada C de dimension n,
  cada una de dimension n / 2, respectivamente, retorna la matriz C.
  */
  vector <vector <int>> C(n, vector <int>(n));
  
    int i = 0;
    int q = 0;
    int j;
    int k;
    while(i < n/2){
        j = 0; 
        k = 0;
        while(j < n/2){
            C[i][j] = C11[q][k];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }

    i = 0;
    q = 0;
    while(i < n/2){
        j = n/2;
        k = 0; 
        while(j < n){
            C[i][j] = C12[q][k];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }

    i = n/2;
    q = 0;
    while(i < n){
        j = 0;
        k = 0; 
        while(j < n/2){
            C[i][j] = C21[q][k];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }

    i = n/2;
    q = 0;
    while(i < n){
        j = n/2;
        k = 0; 
        while(j < n){
            C[i][j] = C22[q][k];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }
    
    return C;
}

vector<vector<int>> strassen (vector<vector<int>> A, vector<vector<int>> B, int n)
{
  if (n == 1)
  {
    vector <vector<int>> C (n, vector <int> (n));
    C[0][0] = A[0][0] * B[0][0];

    return C;
  }
  else
  {

    vector<vector<int>> A11 = subMatrix(A, n / 2, 0, 0);

    vector<vector<int>> A12 = subMatrix(A, n / 2, 0, n / 2);

    vector<vector<int>> A21 = subMatrix(A, n / 2, n / 2, 0);

    vector<vector<int>> A22 = subMatrix(A, n / 2, n / 2, n / 2);

    vector<vector<int>> B11 = subMatrix(A, n / 2, 0, 0);

    vector<vector<int>> B12 = subMatrix(A, n / 2, 0, n / 2);

    vector<vector<int>> B21 = subMatrix(A, n / 2, n / 2, 0);

    vector<vector<int>> B22 = subMatrix(A, n / 2, n / 2, n / 2);
    
    vector<vector<int>> P1 = strassen(A11, matrixSubstraction(B12, B22, n / 2), n / 2);

    vector<vector<int>> P2 = strassen(matrixAddition(A11, A12, n / 2), B22, n / 2);

    vector<vector<int>> P3 = strassen(matrixAddition(A21, A22, n / 2), B11, n / 2);
    
    vector<vector<int>> P4 = strassen(A22, matrixSubstraction(B21, B11, n / 2), n / 2);

    vector<vector<int>> P5 = strassen(matrixAddition(A11, A22, n / 2), matrixAddition(B11, B22, n / 2), n / 2);

    vector<vector<int>> P6 = strassen(matrixSubstraction(A12, A22, n / 2), matrixAddition(B21, B22, n / 2), n / 2);

    vector<vector<int>> P7 = strassen(matrixSubstraction(A11, A21, n / 2), matrixAddition(B11, B12, n / 2), n / 2);
    
    vector<vector<int>> C11 = matrixSubstraction(matrixAddition(matrixAddition(P5, P4, n / 2), P6, n / 2), P2, n / 2);
    vector<vector<int>> C12 = matrixAddition(P1, P2, n / 2);
    vector<vector<int>> C21 = matrixAddition(P3, P4, n / 2);
    vector<vector<int>> C22 = matrixSubstraction(matrixAddition(P5, P1, n / 2), matrixAddition(P3, P7, n / 2), n / 2);

    vector <vector<int>> C = matrixGrouping(C11, C12, C21, C22, n);
    return C;
  }
}

int main()
{
    vector <vector <int>> A = {{1,2,3,4},{5,6,7,8}, {9,10,11,12},{13,14,15,16}}, B = {{1,2,3,4},{5,6,7,8}, {9,10,11,12},{13,14,15,16}};
    
    vector <vector <int>> C = strassen(A, B, 4);
    printVector(C);
    return 0;
}