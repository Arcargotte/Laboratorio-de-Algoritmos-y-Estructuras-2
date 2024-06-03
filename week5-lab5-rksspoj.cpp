#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <vector<int>> MAX_HEAPIFY (vector <vector<int>> A, int i, int n)
{
    int left, right, largest;
    vector <int> temp (3);

    left = i * 2 + 1;
    right = i * 2 + 2;

    if (left < n && A[left][1] < A[i][1])
    {
        largest = left;
    }
    else if (left < n && A[left][1] == A[i][1] && A[left][2] > A[i][2])
    {
      largest = left;
    }
    else
    {
        largest = i;
    }

    if (right < n && A[right][1] < A[largest][1])
    {
        largest = right;
    } 
    else if (right < n && A[right][1] == A[largest][1] && A[right][2] > A[largest][2])
    {
      largest = right;
    }
    if (largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        A = MAX_HEAPIFY(A, largest, n);

        return A;
    }

    return A;
}

vector <vector<int>> BUILD_MAX_HEAP (vector <vector<int>> A)
{
    float n = A.size();

    for (int i = floor(n/2) - 1; i >= 0; i--)
    {
        A = MAX_HEAPIFY(A, i, n);
    }

    return A;
}

vector <vector<int>> heapsortPairs (vector <vector<int>> A)
{
    float n = A.size();
    A = BUILD_MAX_HEAP(A);

    for (int i = n - 1; i >= 1; i--)
    {
        vector<int> temp (3);
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        A = MAX_HEAPIFY(A, 0, i);
    }

    return A;
}

int occurs (vector <int> A, int k)
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

vector<vector<int>> pairCounter (vector<int> A, int n, int c)
{
    /*
    Dado un vector de enteros positivos, retorna una lista de pares ordenados cuyo primer elemento es
    el entero en la lista y el segundo elemento es su número de ocurrencias en ella.
    */
    vector<vector<int>> pairs (c, vector <int> (3));
    vector<int> numbers(c);
    vector<int> indexes (c);

    int index = 0;

    for (int i = 0; i < n; i++){
        if (occurs(numbers, A[i]) == 0)
        {
            numbers[index] = A[i];
            indexes[index] = i;
            index++;
        }
    }

   for (int i = 0; i < c; i++){
        pairs[i][0] = numbers[i];
        pairs[i][1] = occurs(A, numbers[i]);
        pairs[i][2] = indexes[i];
    }

    
    return pairs;
}

vector<int> rksSorting (vector<int> A, int n, int c){
    
    //Ordena un vector de enteros A tal que sus elementos aparezcan en función de su número de ocurrencias y si es un elemento  menor o 
    //igual que una constante c.
    
  vector<vector<int>> pairs = pairCounter(A, n, c);
  pairs = heapsortPairs(pairs);

  vector<int> rksA;
  int i = 0;
  int j = 0;
  int cnt = 0;

   for (int i = 0; i < c; i++)
   {
    for (int j = 0; j < pairs[i][1]; j++)
        rksA.push_back(pairs[i][0]);
   }

   rksA.resize(n);
   
   return rksA;
}


int main () {
  
    int n, c;

    scanf("%d %d", &n, &c);
    
    vector <int> A (n);
    
    for (int i = 0; i < n; i++){
      cin >> A[i];
    }
    A = rksSorting(A, n, c);
            
    for (int i = 0; i < n; i++){
      printf("%d ", A[i]);
    }
    
    return 0;
}