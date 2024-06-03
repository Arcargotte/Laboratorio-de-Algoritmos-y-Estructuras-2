#include <iostream>
#include <vector>
#include <algorithm>
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

vector <long  int> mergeSort (vector<long int> T, float n){
  if (n == 1){
    return T;
  } else{
    vector <long int> U(T.begin(), T.begin() + floor(n / 2));
    vector <long int> V(T.begin() + floor(n / 2), T.end());
    
    U = mergeSort(U, floor(n / 2));
    V = mergeSort(V, ceil(n / 2));

    return merge(T, U, V, floor(n / 2), ceil(n / 2));
  }
}

int scoreMaker (vector <long int> B, long long int bi){
  int n = B.size(), i;
  long long int score = 0;

  B = mergeSort(B, n);

  //find first occurrence of bi in sorted vector B
  for (int j = 0; j < n; j++){
    if (B[j] == bi){
      i = j;
      break;
    }
  }
  
  vector <long int> B_pi;
  vector <long int> B_iq;

  for (int j = 0; j < i; j++){
    bi += B[j];
    score++;
  }
  
  for (int j = i + 1; j < n; j++){
    if (bi >= B[j]){
      bi +=B[j];
      score++;
    } else{
      break;
    }
  }

  return score;
}

void collectingGame (vector <long int> B){
  for (int i = 0; i < B.size(); i++){
    printf("%d ", scoreMaker(B, B[i]));
  }
  printf("\n");

  return;
}

int main (){
  
  vector <long int> A;
  int cases, n, result;
  long int usrin;
  
  scanf("%d", &cases);
  
  while (cases > 0){

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
      scanf("%ld", &usrin);
      A.push_back(usrin);
    }

    collectingGame(A);
    A.clear();
    cases--;
  }

  return 0;
}