#include <iostream>
#include <vector>

using namespace std;


// Implementación de cola como lista enlazada
// struct element
// {
//     long long x;
//     element * nx;

//     element()
//     {
//         x = 0;
//         nx = nullptr;
//     }
// };

// struct queue
// {
//     element * head;

//     queue()
//     {
//         head = nullptr;
//     }

//     void enqueue (long long y)
//     {
//         element * toEnqueue = new element();
//         toEnqueue->x = y;

//         if (head == nullptr)
//         {
//             head = toEnqueue;
//             return;
//         }

//         element * nxt_element = head;

//         while (nxt_element -> nx != nullptr)
//         {
//             nxt_element = nxt_element -> nx;
//         }
        
//         nxt_element->nx = toEnqueue;
        
//     }

//     void dequeue ()
//     {
//         if (head == nullptr)
//         {
//             return;
//         }
//         head = head->nx;

//     }

//     void first_element()
//     {
//         if (head != nullptr)
//         {
//             printf("%lld\n", head->x);
//         }
//         else
//         {
//             printf("Empty!\n");
//         }
//     }
// };

// queue queries = queue();

// int main ()
// {
//     long num_queries;
//     int option;
//     long long usrinput;

//     scanf("%ld",&num_queries);

//     while (num_queries > 0)
//     {   
//         scanf("%d",&option);
//         if (option == 1)
//         {
//             scanf("%lld",&usrinput);
//             queries.enqueue(usrinput);
//         }
//         else if (option == 2)
//         {
//             queries.dequeue();
//         }
//         else
//         {
//             queries.first_element();
//         }

//         num_queries--;
//     }

//     return 0;
// }

// Implementación de cola como lista enlazada (version 2)

// struct element
// {
//     long long x;
//     element * nx;

//     element()
//     {
//         x = 0;
//         nx = nullptr;
//     }
// };

// struct queue
// {
//     int cnt;
//     element * head;

//     queue()
//     {
//         cnt = 0;
//         head = nullptr;
//     }

//     void enqueue (long long y)
//     {
//         if (cnt == 0)
//         {
//             element * toEnqueue = new element();
//             toEnqueue->x = y;
//             head = toEnqueue;
//             cnt++;
//             return;
//         }

//         element * toEnqueue = head + cnt; //dirección de memoria en el que se va a guardar el sig. elemento

//         *toEnqueue = element(); // se guarda el sig. elemento de la cola en una dirección de memoria continua a la de la cabeza.
//         toEnqueue->x = y;
//         // relaciona el siguiente elemento del anterior al nuevo que se está agregando a menos que se trate del primer elemento de la lista.

//         element * prevElem = toEnqueue - 1;
//         prevElem->nx = toEnqueue;

//         cnt++;

//     }

//     void dequeue ()
//     {
//         if (head == nullptr)
//         {
//             return;
//         }
//         head = head->nx;

//     }

//     void first_element()
//     {
//         if (head != nullptr)
//         {
//             printf("%lld\n", head->x);
//         }
//         else
//         {
//             printf("Empty!\n");
//         }
//     }
// };

// int main ()
// {
//     queue queries = queue();

//     long num_queries;
//     int option;
//     long long usrinput;

//     scanf("%ld",&num_queries);

//     while (num_queries > 0)
//     {   
//         scanf("%d",&option);

//         if (option == 1)
//         {
//             scanf("%lld",&usrinput);
            
//             queries.enqueue(usrinput);
//         }
//         else if (option == 2)
//         {
//             queries.dequeue();
//         }
//         else if (option == 3);
//         {
//             queries.first_element();
//         }

//         num_queries--;
//     }

//     return 0;
// }

// Implementación de cola como vector

// Existe una variable global int 'head' cuyo valor es exactamente 0. Se inicializa con el valor -1 para determinar su valor a 0
// mediante el operador '++' en el caso base de la función enqueue.
int head = -1;

// Inserta un elemento al final del vector e incrementa head tal que éste siempre esté apuntando al primer elemento del vector. O sea, a la cabeza de la cola.

void enqueue (vector <long long> &A, long long x)
{
    if (A.size() == 0)
    {
        A.push_back(x);
        head++;
        return;
    }

    A.push_back(x);
    return;
}

// Elimina el primer elemento del vector. O sea, al primer elemento insertado en la cola y aumenta por una unidad a head de manera que apunte a la nueva cabeza de la cola.

void dequeue (vector <long long> &A)
{
    if (A.size() ==  0 || head >= A.size())
    {
        return;
    }
    head++;

    return;
}

// 'Output' en stdout el primer elemento del vector. O sea, la cabeza de la cola. Retorna 'Empty!' cuando la cola no tiene elementos.
/*
Comentarios: la guardia del condicional 'if', similar al anterior, asegura que en el caso de que no se haya incluido ningún elemento en la cola o que, agregados n elementos
en ella y, a su vez, eliminados n elementos de la cola, se determine que la cola esté vacía, pues este programa no elimina o deslocaliza de la memoria los elementos
ya incluidos en el vector por asuntos de eficiencia, sino que solo deja de referenciarlos a través de la variable 'head'.
*/

void first_element (vector <long long> &A)
{
    if (head >= A.size() || A.size() == 0)
    {
        printf("Empty!\n");
        return;
    }

    printf("%lld\n", A[head]);

    return;
}
// Se crea en la pila de la función main() el vector 'queue' y las variables num_queries (número de tareas a procesar por el programa), option (opciones disponibles de tareas:
// agregar elemento a la cola [1], eliminar elemento de la cola [2], output la cabeza de la cola [3]) y usrinput (sea la opción [1], entonces tomará el elemento a incluir)
// en la cola. El programa iterará en función del número de tareas a procesar ingresado por el usuario.
/*
Comentarios finales: encontrará dos implementaciones adicionales de cola como listas enlazadas: una versión que contiene la función enqueue de orden O(n) y otra
que es de orden O(1). Sin embargo, ambas implementaciones incurren a errores graves de acceso a zonas prohibidas en la memoria. Ninguna de esas versiones fue
aceptada definitivamente por SPOJ; solo la implementación como vector.
*/
int main ()
{
    vector <long long> queue;

    long num_queries;
    int option;
    long long usrinput;

    scanf("%ld",&num_queries);

    while (num_queries > 0)
    {   
        scanf("%d",&option);
        if (option == 1)
        {
            scanf("%lld",&usrinput);
            
            enqueue(queue, usrinput);
        } 
        else if (option == 2) 
        {
            dequeue(queue);
        }
        else if (option == 3)
        {
            first_element(queue);
        }

        num_queries--;
    }

    return 0;
}