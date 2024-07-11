#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
Funcionamiento del algoritmo:

Dado un arreglo de n elementos a, se busca una n permutacion p, tal que la permutacion
suma a + p tenga un elemento m de la forma m = ai + pi cuyo numero de ocurrencias k sea 
el maximo entre todas las permutaciones.

Tenemos las siguientes consideraciones en el arreglo a: 
(1) Si existen l ocurrencias de ai en a, entonces m aparece cuanto mucho n - (l - 1), pues
    el elemento pi en m = ai + p es unico, por lo que ese m solo puede ocurrir una vez.
(2) El numero maximo de ocurrencias de m en a + p es indiferente del orden lineal de a,
    pues se han de seguir sumando los elementos de la n permutacion en el arreglo a. Por lo
    tanto, podemos ordenar a.
(3) Para todo m, existe una cota superior. Esta es, el elemento aj tal que m = aj. Luego,
    m aparece cuanto mucho pos(cota_superior) - ai. La cota superior resulta de tener un
    m = ai + n, para cualquier ai en a. Suponiendo que a esta ordenado y tomando en cuenta
    que n es el maximo de la n permutacion, no es posible obtener aj (pues, no se puede sumar
    con 0) ni ak, para j<k, pues no es posible encontrar un q>n tal que m = ak + q.

Con estas consideraciones, el algoritmo descarta y toma de forma organizada gracias a la
estructura 'set' los elementos del arreglo a y los coloca en un vector av. Luego, para cada
uno de los elementos x en el vector av, se determina la cota superior de x + n para descartar
aquellas ocurrencias imposibles de m en el arreglo para x + n. Como va a existir un pi unico
para los elementos de a desde el indice de x hasta la cota superior, se suman cada
numero de ocurrencias y, despues de iterar sobre cada uno de los elementos, se compara el
resultado con el anterior obtenido. Finalmente, se dara como respuesta el mayor
de todos los resultados que corresponden al numero de ocurrencias de x + n.
*/
int main() 
{
  int t, n, ai;
  set <int> a;
  vector <int> av;
    
  scanf("%d", &t);
  while (t > 0){
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
      scanf("%d", &ai);
      a.insert(ai);
    }
    av.assign(a.begin(), a.end());
    
    int x, ans = 0, prop = 0;
    for (int i = 0; i < av.size(); i++){
      x = av[i];
      /*
      lower_bound retorna un iterador al primer elemento que es menor o igual que x + n.
      prop (proposal) corresponde al numero de ocurrencias de x + n. Si se resta la cota
      inferior de un numero por el iterador que apunta al inicio de un contenedor, se
      retorna su indice. Luego, lo restamos por i para obtener el numero de elementos
      que van a sumar a m
      */
      auto lowb = lower_bound(av.begin(), av.end(), x + n);
      prop = (lowb - av.begin()) - i;
      ans = max(ans,prop);
      }
      
      printf("%d\n", ans);
      a.clear();
      av.clear();
      t--;
    }
    
    return 0;
}