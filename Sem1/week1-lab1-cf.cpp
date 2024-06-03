#include <iostream>
#include <vector>

using namespace std;

vector <int> rmnResize (vector <int> A, int k, int num){
  /*
  Dado un vector A, elimina num instancias del elemento k.
  */
  vector <int> B = A;
  int index = 0;
  
  while (num > 0){
    if (B[index] == k){
      B.erase(B.begin() + index);
      num--;
    } else{
      index++;
      }
  }
  
  return B;
}

vector <int> addnResize (vector <int> A, int k, int num){
  /*
  Dado un vector A, empuja al final de un vector num instancias del elemento k.
  */
  vector <int> B = A;
  
  while (num > 0){
    B.push_back(k);
    num = num - 1;
  }
  
  return B;
}

int countOccur (vector <int> A, int k){
  /*
  Dado un vector A, retorna el número de ocurrencias del elemento k.
  */
    int cnt = 0;
    for (int i = 0; i < A.size(); i++){
        if (A[i] == k){
            cnt++;
        }
    }

    return cnt;
}

int cardExchange (vector <int> A, int k){
  /*
  Dado un vector A y un entero k, verifica si un elemento A[i] ocurre k veces. Cuando ocurre k veces, 
  elimina las k ocurrencias de A[i]; si no ocurre k veces, verifica si puede sumarse k - 1 a las ocurrencias
  de A[i] tal que A[i] ocurra k veces. Si no puede sumarse k - 1 y no existe un A[j] tal que i != j que
  ocurra k veces, retorna la longitud del vector; si el vector termina siendo vacío, retorna k - 1.
  */
    int toAdd = 0, cnt = 0;

    while (!(A.empty())){
      for (int i = 0; i < A.size(); i++){
        cnt = countOccur(A, A[i]);
        if (cnt >= k){
          A = rmnResize(A, A[i], k);
          toAdd += (k - 1);
          break;
        } else if (cnt + toAdd >= k){
          A = addnResize(A, A[i], toAdd);
          toAdd -= (k - 1);
          break;
        } else if (i == A.size() - 1){
          return A.size();
      }
    }
  return toAdd;
  }
}

int main (){

    vector <int> A;
    
    int n, k, input, cases, result;
    
    scanf("%d", &cases);

    while (cases > 0){
      scanf("%d %d", &n, &k);

      for (int i = 0; i < n; i++){
          scanf("%d", &input);
          A.push_back(input);
      }
      result = cardExchange(A, k);
      A.clear();

      cout << result << endl;
    
      cases--;
    }
    
  return 0;
}