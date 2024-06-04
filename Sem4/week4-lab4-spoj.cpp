#include <iostream>
#include <cstdint>
#include <vector>
#include <inttypes.h>

using namespace std;

void printVector (vector <long long> A)
{
  long long  n = A.size();
  
  for (int i = 0; i < n; i++)
    {
      printf("%lld ", A[i]); 
      printf(" ");
    }
    
  return;
}

vector<vector<long long>> subMatrix(vector<vector<long long>> A, long n, long x0, long y0)
{
  /*
  Dada una matriz cuadrada A de dimension k, determina una submatriz cuadrada subA de dimensión n tal que n <= k a partir del elemento en la
  posicion (x0,y0) hasta el que está en la posición (x1,y1), para 0 <= x0,x1,y0,y1 < n. Para el caso
  de determinar una submatriz de dimension n = 1, retorna el elemento en la posición (x0,y0).
  */
  vector<vector<long long int>> subA (n, vector<long long int> (n));

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

vector<vector<long long>> matrixAddition (vector<vector<long long>> A, vector<vector<long long>> B, long n)
{
  vector<vector<long long>> C (n, vector<long long> (n,0));
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  
  return C;
}

vector<vector<long long>> matrixSubstraction (vector<vector<long long>> A, vector<vector<long long>> B, long n)
{
  vector<vector<long long>> C (n, vector<long long> (n,0));
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
  
  return C;
}

vector<vector<long long>> matrixGrouping (vector<vector<long long>> C11, vector<vector<long long>> C12, vector<vector<long long>> C21, vector<vector<long long>> C22, long n)
{
  /*
  Dadas cuatro submatrices C11,C12,C21,C22 correspondientes a cuatro cuartos de una matriz cuadrada C de dimension n,
  cada una de dimension n / 2, respectivamente, retorna la matriz C.
  */
  vector <vector <long long int>> C(n, vector <long long int>(n));
  
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

vector<vector<long long>> strassen (vector<vector<long long>> A, vector<vector<long long>> B, long n)
{
  if (n == 1)
  {
    vector <vector<long long >> C (n, vector <long long> (n));
    C[0][0] = A[0][0] * B[0][0];

    return C;
  }
  else
  {
    vector<vector<long long>> A11, A12, A21, A22, B11, B12, B21, B22;

    A11 = subMatrix(A, n / 2, 0, 0);

    A12 = subMatrix(A, n / 2, 0, n / 2);

    A21 = subMatrix(A, n / 2, n / 2, 0);

    A22 = subMatrix(A, n / 2, n / 2, n / 2);

    B11 = subMatrix(B, n / 2, 0, 0);

    B12 = subMatrix(B, n / 2, 0, n / 2);

    B21 = subMatrix(B, n / 2, n / 2, 0);

    B22 = subMatrix(B, n / 2, n / 2, n / 2);

    vector<vector<long long>> P1, P2, P3, P4, P5, P6, P7;

    P1 = strassen(A11, matrixSubstraction(B12, B22, n / 2), n / 2);

    P2 = strassen(matrixAddition(A11, A12, n / 2), B22, n / 2);

    P3 = strassen(matrixAddition(A21, A22, n / 2), B11, n / 2);
    
    P4 = strassen(A22, matrixSubstraction(B21, B11, n / 2), n / 2);

    P5 = strassen(matrixAddition(A11, A22, n / 2), matrixAddition(B11, B22, n / 2), n / 2);

    P6 = strassen(matrixSubstraction(A12, A22, n / 2), matrixAddition(B21, B22, n / 2), n / 2);

    P7 = strassen(matrixSubstraction(A11, A21, n / 2), matrixAddition(B11, B12, n / 2), n / 2);
        
    vector<vector<long long>> C, C11,C12,C21,C22;

    C11 = matrixSubstraction(matrixAddition(matrixAddition(P5, P4, n / 2), P6, n / 2), P2, n / 2);
    C12 = matrixAddition(P1, P2, n / 2);
    C21 = matrixAddition(P3, P4, n / 2);
    C22 = matrixSubstraction(matrixAddition(P5, P1, n / 2), matrixAddition(P3, P7, n / 2), n / 2);

    C = matrixGrouping(C11, C12, C21, C22, n);
    
    return C;
  }
}

int main()
{
  long  n, i, j, d1, p1, r1, r2, m1, d2, p2, m2;
  //here you need to read n, p1, d1, r1, m1, p2, d2, r2, m2 from input.
  scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld", &n, &p1, &d1, &r1, &m1, &p2, &d2, &r2, &m2);
  vector <vector<long long>> A (n, vector<long long >(n));
  vector <vector<long long >> B (n, vector<long long >(n));
  vector <vector<long long >> C (n, vector<long long >(n));

  vector <long long> V (n);
  for (i=0; i<n; ++i)
      for (j=0; j<n; ++j) {
          d1 = d1 * p1 + r1;
          d2 = d2 * p2 + r2;
          A[i][j] = d1 >> (32 - m1);
          B[i][j] = d2 >> (32 - m2);
      }

  C = strassen(A, B, n);
  
  for (i=0; i<n; ++i) {
    V[i] = 0;
    for (j=0; j<n; ++j)
        V[i] ^= C[i][j];
    printf("%lld ", V[i]);
  }

  return 0;
}