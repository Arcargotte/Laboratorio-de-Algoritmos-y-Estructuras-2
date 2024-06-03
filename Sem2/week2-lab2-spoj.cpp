#include <iostream>
#include <vector>

using namespace std;

int firstOcc (vector<int> A, int k)
{

  for (int j = 0; j < A.size(); j++)
  {
    if (A[j] == k) return j;
  }
  
  return -1;
}

int countOcc (vector<int> A, int k)
{
    int cnt = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == k)
        {
            cnt++;
        }
    }

    return cnt;
}

vector<vector<int>> bubbleSortPairs (vector<vector<int>> A){
    /*
    Dado un vector de enteros, usa el algoritmo bubblesort para acomodarlos en orden descendente.
    */

    vector<int> temp (3);
    int j = 0;
    int n = A.size();
    while (n - j > 0){
        for (int i = 0; i < n - 1; i++){
            if (A[i][1] == A[i + 1][1] && A[i][2] > A[i + 1][2]){
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;            
                }
            else if (A[i][1] < A[i + 1][1])
            {
              temp = A[i];
              A[i] = A[i + 1];
              A[i + 1] = temp;            
                
            }

        j += 1;
    }
  }
    return A;
}

vector<vector<int>> pairCounter (vector<int> A, int c){
    /*
    Dado un vector de enteros positivos, retorna una lista de pares ordenados cuyo primer elemento es
    el entero en la lista y el segundo elemento es su número de ocurrencias en ella.
    */
    vector<vector<int>> pairs (c, vector<int> (3));

    for (int i = 0; i < c; i++)
    {
        pairs[i][0] = i + 1;
        pairs[i][1] = countOcc(A, i + 1);
        pairs[i][2] = firstOcc(A, i + 1);
    }

    return pairs;
}

vector<int> rksSorting (vector<int> A, long int c){
    /*
    Ordena un vector de enteros A tal que sus elementos aparezcan en función de su número de ocurrencias y si es un elemento  menor o 
    igual que una constante c.
    */
  vector<vector<int>> pairs = pairCounter(A, c);
  pairs = bubbleSortPairs(pairs);
  vector<int> rksA;

   for (int i = 0; i < c; i++){
    for (int j = 0; j < pairs[i][1]; j++){
        rksA.push_back(pairs[i][0]);
    }
   }

   rksA.resize(A.size());
   
   return rksA;
}

int main(){
  
  int n;
  int c;
  
  scanf("%d %d", &n, &c);

  vector <int> A (n);
  
  for (int i = 0; i < n; i++){
      scanf("%d", &A[i]);
  }
      
  A = rksSorting(A, c);

  for (int i; i < n - 1; i++){
    printf("%d ", A[i]);
  }
  printf("%d", A[n - 1]);

  return 0;
}