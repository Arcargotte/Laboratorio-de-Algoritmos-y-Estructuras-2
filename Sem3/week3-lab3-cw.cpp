#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <long long int> merge (vector <long long int> T, vector <long long int> U,vector <long long int> V, int n, int m){
  
  int i = 0, j = 0;
  
  for (int k = 0; k < m + n; k++){
    if (i != n && j != m){
      if (U[i] < V[j]){
        T[k] = U[i];
        i++;
    } else{
      T[k] = V[j];
      j++;
    }
    } else {
      if (i == n){
        T[k] = V[j];
        j++;
      } else if (j == m){
        T[k] = U[i];
        i++;
      }
    }
  }
  return T;
}

vector <long long int> mergeSort (vector<long long int> T, float n){
  if (n == 1){
    return T;
  } else{
    vector <long long int> U(T.begin(), T.begin() + floor(n / 2));
    vector <long long int> V(T.begin() + floor(n / 2), T.end());
    
    U = mergeSort(U, floor(n / 2));
    V = mergeSort(V, ceil(n / 2));

    return merge(T, U, V, floor(n / 2), ceil(n / 2));
  }
}

long int sumTill(vector <long long int> A, int right)
{
  /*
  Dado un vector A de longitud n y dos indices right tal que 0<=right < n, retorna la suma de los elementos desde 0 hasta right.
  */
  long int k = 0;

  for (int j = 0; j <= right; j++)
  {
    k += A[j];
  }

  return k;
}

int findOcc(vector <long long int> A, long int k)
{
  /*
  Dado un vector A de longitud n y un entero k, retorna el índice de la primera ocurrencia de k en A.
  */
  int n = A.size();

  for (int j = 0; j < n; j++)
  {
    if (A[j] == k)
    {
      return j;
    }
  }
  return -1;
}

int collectingGame(vector <long long int> A, long long int ai)
{
  int i = findOcc(A, ai), n = A.size(), num;
  long long int bi = 0;
  bi += sumTill(A, i);

  num = i;
  i++;

  while (A[i] <= bi && i < n)
  {
    bi += A[i];
    num++;
    i++;
  }

  return num;

}

int main (){
  
  int cases, n;
  
  scanf("%d", &cases);
  
  while (cases > 0){
    scanf("%d", &n);
    vector <long long int> A (n);

    for (int i = 0; i < n; i++){
      scanf("%ld", &A[i]);
    }

    vector <long long int> B (n);
    B = mergeSort(A, n);

    for (int i = 0; i < n; i++)
    {
      printf("%ld ", collectingGame(B, A[i]));
    }
      printf("\n");

    cases--;
  }

  return 0;
}