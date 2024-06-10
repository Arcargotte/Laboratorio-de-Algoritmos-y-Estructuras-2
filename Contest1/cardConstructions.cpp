#include <stdio.h>
#include <vector>

using namespace std;

long int num_cards (long int h)
{
    /*
  Determina el número de cartas necesarias para construir una pirámide de altura h mediante el n-ésimo término de la recursión de la forma num_cards(h) = num_cards(h - 1) + 3 * h - 1
  */
    int x = h, r = 0;

    while (x != 1)
    {
        r = r + 3 * x - 1;
        x = x - 1;
    }

    r += 2;

    return r;
}

bool isPossible(long int n, int h)
{
    /*
    Determina si es posible construir una pirámide de altura h con n cartas.
    */

   long int compare = num_cards(h);

   if (compare > n)
   {
    return false;
   }
   else
   {
    return true;
   }
}

int main ()
{   
    int cases, cnt;
    long int numCards;

    scanf("%d", &cases);

    while (cases > 0)
    {
        cnt = 0;
        scanf("%ld", &numCards);
        // Verifica la altura más grande de la pirámide que es posible construir con numCards y resta las cartas utilizadas para hacerla. 
        // Luego, suma uno al total de pirámides construidas y repite el proceso ssi es posible construir al menos una pirámide de altura 1.
        /*
        El algoritmo busca construir una pirámide de cartas con la altura máxima posible para numCards actual. Una vez construida, resta
        del total las cartas utilizadas y suma uno a la variable cnt que determina al final del programa el número de pirámides construidas
        para la altura h - 1 (no la altura h, pues esa es la primera altura no alcanzable para el número de cartas total)
        */

        while (isPossible(numCards, 1))
        {
            long int h = 1;

            while (isPossible(numCards, h))
            {
                h++;
            }

            numCards = numCards - num_cards(h - 1);
            cnt++;        
        }

        printf("%d \n", cnt);
        cases--;
    }
    
    return 0;
}