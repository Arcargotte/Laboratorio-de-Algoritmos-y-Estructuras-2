#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <long int> merge (vector <long int> T, vector <long int> U, vector <long int> V, int n, int m){
  
  int i = 0, j = 0;
  
  for (int k = 0; k < m + n; k++){
    if (i != n and j != m){
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

vector <long int> mergeSort (vector<long int> T, float n){
  if (n == 1){
    return T;
  } else{
    vector<long int> U(T.begin(), T.begin() + floor(n / 2));
    vector <long int> V(T.begin() + floor(n / 2), T.end());
    
    U = mergeSort(U, floor(n / 2));
    V = mergeSort(V, ceil(n / 2));

    return merge(T, U, V, floor(n / 2), ceil(n / 2));
  }
}

vector <int> insertionSort (const vector <int> A){
  int n = A.size();
  vector <int> B;
  B.resize(n);
  copy(A.begin(), A.end(), &B[0]);
    for (int j = 1; j < n; j++){
        int key = B[j];
        int i = j - 1;
        while (B[i] > key && i >= 0){
            B[i + 1] = B[i];
            i = i - 1;
        }
        B[i + 1] = key;
    }

  return B;
}

int binarySearchRec (vector <long int> A, long int ai, int l, int r){

  if (l == r){
    return l;
  }

  int mid = ceil(float(l + r) / 2);

  if (ai >= A[mid]){
    return binarySearchRec(A, ai, l, mid - 1);
  } else{
    return r;
  }

}

int binarySearch(vector <long int> A, long int ai){
  int n = A.size();

  if(n == 0 || ai > A[n - 1]){
    return n - 1;
  } else{
    binarySearchRec(A, ai, 0, n - 1);
  }
}

int main (){
  vector <long int> A = {1,2,3,3,3,5,7,9};

  int r = binarySearch(A, 3);

  printf("%d", r);

  return 0;
}

vector <int> MAX_HEAPIFY (vector <int> A, int i, int n)
{
    int left, right, largest, temp;

    left = i * 2 + 1;
    right = i * 2 + 2;

    if (left < n && A[left] > A[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if (right < n && A[right] > A[largest])
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

vector <int> BUILD_MAX_HEAP (vector <int> A)
{
    float n = A.size();

    for (int i = floor(n/2) - 1; i >= 0; i--)
    {
        A = MAX_HEAPIFY(A, i, n);
    }

    return A;
}

vector <int> heapsort (vector <int> A)
{
    float n = A.size();
    A = BUILD_MAX_HEAP(A);

    for (int i = n - 1; i >= 1; i--)
    {
        int temp;
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        A = MAX_HEAPIFY(A, 0, i);
    }

    return A;
}