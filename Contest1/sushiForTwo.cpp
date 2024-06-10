#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void MAX_HEAPIFY (vector <int> &A, int i, int n)
{
    int left, right, largest, temp;

    left = i * 2 + 1;
    right = i * 2 + 2;

    if (left < n && A[left] < A[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if (right < n && A[right] < A[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MAX_HEAPIFY(A, largest, n);
    }
}

void BUILD_MAX_HEAP (vector <int> &A)
{
    float n = A.size();

    for (int i = floor(n/2) - 1; i >= 0; i--)
    {
        MAX_HEAPIFY(A, i, n);
    }
}

void heapsort (vector <int> &A)
{
    float n = A.size();
    BUILD_MAX_HEAP(A);

    for (int i = n - 1; i >= 1; i--)
    {
        int temp;
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        MAX_HEAPIFY(A, 0, i);
    }
}

int main ()
{
  /*
  Este programa recibe los n elementos del arreglo de 1s y 0s individualmente para determinar las longitudes
  de los subarreglos posibles tales que, para 0<=p<q<n, [p..l/2] y [l/2+1..q], con l/2 siendo la longitud
  más grande de la mitad del subarreglo tal que todos sus elementos sean 1s o 2s.
  */
    int n;
    int id_count = 1, count = 0, it = 0, id = 0, input;
    vector<int> maxlens;

    scanf("%d", &n);
    
    /*
    Inicializa el contador del primer valor ingresado por el usuario (id_count) a 1 porque siempre existe
    una ocurrencia del valor que uno lee en un arreglo.
    */
    while (it < n)
    {
      scanf("%d", &input);
      /*
      Determina como identificador (id) el elemento ingresado por el usuario y va sumando en el contador
      `id_count` tantos elementos que sean iguales a id. Como no existe un id en la primera iteración (razón
      por lo que se inicializa en 0), se asigna como id el input.

      Cuando el usuario ingresa un elemento distinto, compara el número de ocurrencias del id con el número
      de ocurrencias continuas del elemento distinto y determina el menor entre los dos para definirlo
      como la mitad de la longitud máxima alcanzable del subarreglo deseado. Para realizar esto, guarda el número
      de ocurrencias del id en la variable `count` y, actualizando el elemento distinto como el nuevo id, 
      actualiza el número de ocurrencias del id como 1 y reinicia el proceso de conteo. 

      Se obtendrán todas las mitades de las máximas longitudes posibles del subarreglo en el arreglo original y se irán guardando
      en el vector `maxlens`. Luego, este vector se ordenará de mayor a menor a través de heapsort y retonará
      el primer elemento, que será el mayor, y se multiplicará por dos en su retorno para devolver así
      la longitud total del arreglo cuyos elementos en sus mitades sean únicamente 1s y 2s.
      */
      if (id == input)
      {
        id_count++;
      }
      else if ((id != input && id != 0))
      {
        if (count != 0 && count >= id_count)
        {
          maxlens.push_back(id_count);
        } 
        else if (count != 0 && count < id_count)
        {
          maxlens.push_back(count);
        }

        count = id_count;
        id_count = 1;
      }

      id = input;
      it++;
    }

    if (count >= id_count)
    {
      maxlens.push_back(id_count);
    } 
    else if (count < id_count)
    {
      maxlens.push_back(count);
    }
    /*
    El bucle `while` ignora la última mitad de la distancia máxima posible alcanzable en la secuencia
    de elementos ingresados por el usuario. Por ese motivo, se hace una comparación después del bucle
    para ingresarlo en el vector.

    Finalmente, realiza un heapsort de susodicho vector que lo arregla a través de una referencia a él mismo
    */
    heapsort(maxlens);

    printf("%d", 2 * maxlens[0]);

    return 0;
}