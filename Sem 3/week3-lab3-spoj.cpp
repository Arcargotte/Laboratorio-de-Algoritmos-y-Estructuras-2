#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> merge (vector <int> T, vector <int> U, vector <int> V, int n, int m){
  
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

int aggrcowSorter (vector <int> A, int k){
  int n = A.size(), minD = 0, allDis, currPos, nxtPos, cowCount;

  A = mergeSort(A, n);

  allDis = A[n - 1] - A[0];
  
  for (int dis = 1; dis <= allDis; dis++){
    currPos = 0;
    nxtPos = currPos + 1;
    cowCount = k - 1;

    while (cowCount != 0){
      //printf("(%d, %d, %d, %d, %d)\n", dis, currPos, nxtPos, minD, cowCount);

      if (A[nxtPos] - A[currPos] >= dis){
        cowCount--;
        currPos = nxtPos;
        nxtPos++;
      } else if (A[nxtPos] - A[currPos] < dis && nxtPos + 1 >= n){
        return minD;
      } else if (A[nxtPos] - A[currPos] < dis && !(nxtPos + 1 >= n)){
        nxtPos++;
      }
      
    }
    
  minD = dis;

  }
}

int main() 
{
    int n, k, cases, usrin, result;
    vector <int> A;
    scanf("%d", &cases);

    while (cases > 0){
      scanf("%d %d", &n, &k);
      for (int i = 0; i < n; i++){
        scanf("%d", &usrin);
        A.push_back(usrin);
      }
      result = aggrcowSorter(A, k);
      printf("%d\n", result);
      A.clear();
      cases--;
    }
        
    return 0;
}