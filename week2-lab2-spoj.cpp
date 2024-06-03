#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> bubbleSortVectorPairs (vector<pair<int, int>> APairs){
    /*
    Dado un vector de enteros, usa el algoritmo bubblesort para acomodarlos en orden descendente.
    */

    pair<int, int> temp;
    int j = 0;
    int n = APairs.size();
    while (n - j > 0){
        for (int i = 0; i < n - 1; i++){
            if (APairs[i].second < APairs[i + 1].second){
                temp = APairs[i];
                APairs[i] = APairs[i + 1];
                APairs[i + 1] = temp;            
                }
        }
        j += 1;
    }

    return APairs;
}

vector<pair<int,int>> pairCounter (vector<int> A, int c){
    /*
    Dado un vector de enteros positivos, retorna una lista de pares ordenados cuyo primer elemento es
    el entero en la lista y el segundo elemento es su número de ocurrencias en ella.
    */
    vector<pair<int,int>> pairs;
    vector<int> numbers;

    int index = 0;

    for (int i = 0; i < A.size(); i++){
        if (count(numbers.begin(), numbers.end(), A[i]) <= 0){
            numbers.push_back(A[i]);
        }
    }

   for (int i = 0; i < c; i++){
        pairs.push_back({numbers[i], count(A.begin(), A.end(), numbers[i])});  
    }

    return pairs;
}

vector<int> rksSorting (vector<int> A, int c){
    /*
    Ordena un vector de enteros A tal que sus elementos aparezcan en función de su número de ocurrencias y si es un elemento  menor o 
    igual que una constante c.
    */
  vector<pair<int,int>> pairs = pairCounter(A, c);
  pairs = bubbleSortVectorPairs(pairs);
  vector<int> rksA;

   for (int i = 0; i < c; i++){
    for (int j = 0; j < pairs[i].second; j++){
        rksA.push_back(pairs[i].first);
    }
   }
   
   return rksA;
}

int main(){
  vector <int> A;
  
  int n, c, input;

  scanf("%d %d", &n, &c);

  for (int i = 0; i < n; i++){
      scanf("%d", &input);
      A.push_back(input);
  }
      
  A = rksSorting(A, c);
  
  for (int i; i < n; i++){
    printf("%d ", A[i]);
  }

  return 0;
}