#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> merge (vector <int> T, vector <int> U, vector <int> V, int n, int m){
  
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

vector <int> mergeSort (vector<int> T, float n){
  if (n == 1){
    return T;
  } else{
    vector<int> U(T.begin(), T.begin() + floor(n / 2));
    vector <int> V(T.begin() + floor(n / 2), T.end());
    
    U = mergeSort(U, floor(n / 2));
    V = mergeSort(V, ceil(n / 2));

    return merge(T, U, V, floor(n / 2), ceil(n / 2));
  }
}

bool isPossible(vector <int> A, int cows, int dist)
{
  int n = A.size();
  int currPos = A[0];
  int cowCount = 1;

  for (int i = 1; i < n; i++)
  {
    if (A[i] - currPos >= dist)
    {
      currPos = A[i];
      cowCount++;
    }

    if (cowCount >= cows){
      return true;
    }
  }
  return false;
}

int aggCowSorter (vector <int> A, int cows)
{
  
  int l = 1, n = A.size(), r = A[n - 1] - A[0];
  
  while (l <= r)
  {
    int mid = floor(float(l + r) / 2);
    
    if (isPossible(A, cows, mid))
    {
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  
  return r;
}

int main() 
{
    int n, k, cases, result;
    scanf("%d", &cases);

    while (cases > 0){
      scanf("%d %d", &n, &k);
      vector <int> A (n);
      for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
      }
      
      A = mergeSort(A, n);
      
      printf("%d\n", aggCowSorter(A, k));
      cases--;
    }
        
    return 0;
}