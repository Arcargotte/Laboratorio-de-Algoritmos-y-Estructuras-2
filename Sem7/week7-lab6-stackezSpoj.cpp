#include <iostream>
#include <vector>

using namespace std;


// Implementación de pila como vector

// Existe una variable global int 'top' cuyo valor varía entre 0 y n excluyente, siendo n la longitud del vector. Se inicializa con el valor -1 para aumentar progresivamente
// mediante el operador '++' el valor de top tal que apunte al i-ésimo índice del vector.
int top = -1;

// Inserta un elemento al final del vector e incrementa top tal que éste siempre esté apuntando al último elemento del vector. O sea, al tope de la pila.
void push (vector <long long> &A, long long x)
{
    if (A.size() == 0)
    {
        A.push_back(x);
        top++;
        return;
    }

    A.push_back(x);
    top++;
    return;
}
// Elimina el último elemento del vector. O sea, al último elemento insertado en la pila y reduce por una unidad a top de manera que apunte al nuevo tope de la pila.
void pop (vector <long long> &A)
{
    if (A.size() ==  0 || top >= A.size())
    {
        return;
    }
    A.pop_back();
    top--;

    return;
}
// 'Output' en stdout el último elemento del vector. O sea, el tope de la pila. Retorna 'Empty!' cuando la pila no tiene elementos.
/*
Comentarios: la condición top >= A.size() fortalece la guardia del condicional en la función, pero no existe algún caso en el que se cumpla la condición de top >= A.size(), pues
se tiene como invariante que top < A.size(). Sin embargo, SPOJ aceptó esta solución y por ese motivo se dejó la condición para que respalde la versión entregada en la página.
*/
void top_element (vector <long long> &A)
{
    if (top >= A.size() || A.size() == 0)
    {
        printf("Empty!\n");
        return;
    }

    printf("%lld\n", A[top]);

    return;
}
// Se crea en la pila de la función main() el vector 'stack' y las variables num_queries (número de tareas a procesar por el programa), option (opciones disponibles de tareas:
// agregar elemento a la pila [1], eliminar elemento de la pila [2], output el tope de la pila [3]) y usrinput (sea la opción [1], entonces tomará el elemento a incluir)
// en la pila. El programa iterará en función del número de tareas a procesar ingresado por el usuario.

int main ()
{
    vector <long long> stack;

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
            
            push(stack, usrinput);

        } 
        else if (option == 2) 
        {
            pop(stack);
        }
        else if (option == 3)
        {
            top_element(stack);
        }

        num_queries--;
    }

    return 0;
}