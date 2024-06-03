#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort (vector <int> A){
    /*
    Dado un vector de enteros, usa el algoritmo bubblesort para acomodarlos en orden descendente.
    */

    int temp;
    int j = 0;
    int n = A.size();
    while (n - j > 0){
        for (int i = 0; i < n - 1; i++){
            if (A[i] > A[i + 1]){
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;            
                }
        }
        j += 1;
    }

    return A;
}

int beautyOfArray (vector <int> A){
  
    int n = A.size();
    A = bubbleSort(A);

    int beauty = A[n - 1] - A[0];

    return beauty;
}


int main(){

    vector <int> A;
    
    int n, input, cases, result;
    
    scanf("%d", &cases);

    while (cases > 0){
      scanf("%d", &n);

      for (int i = 0; i < n; i++){
          scanf("%d", &input);
          A.push_back(input);
      }
      
      result = beautyOfArray(A);
      A.clear();
    
      cout << result << endl;
    
      cases--;
    }

    return 0;
}