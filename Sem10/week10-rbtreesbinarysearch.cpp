#include <iostream>

using namespace std;

struct node
{
    // atributos
    int key;
    int pos;
    node * p;
    node * left;
    node * right;
    int color;
    // inicializador
    node(int value, int i)
    {
        key = value;
        pos = i;
        left = nullptr;
        right = nullptr;
        p = nullptr;
        color = 1;
    }
};

struct RBtree
{
    // atributos:
    node * root;

    // inicializador:
    RBtree()
    {
        root = nullptr;
    }
    // Busca el nodo con clave num en el árbol
    int search(int num)
    {
        node * x = root;
    
        while (x != nullptr)
        {
            if (num == x->key)
            {
                return x->pos;
            }
            else if (num < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        
        return -1;
        
    }
    // Función auxiliar ROTACIÓN IZQUIERDA. Solamente se utiliza como función auxiliar en INSERT_FIXUP. Hace una rotación a la izquierda del nodo z
    void left_rotate (node *z)
    {

        if (z == nullptr || z->right == nullptr) return;

        node * y = z->right;
        z->right = y->left;
        if (y->left != nullptr)
        {
            y->left->p = z;
        }
        y->p = z->p;

        if (z->p == nullptr)
        {
            root = y;
        }
        else if (z == z->p->left)
        {
            z->p->left = y;
        }
        else
        {
            z->p->right = y;
        }
        y->left = z;
        z->p = y;
    }
    // Función auxiliar ROTACIÓN DERECHA. Solamente se utiliza como función auxiliar en INSERT_FIXUP. Hace una rotación a la derecha del nodo z
    void right_rotate (node * z)
    {

        if (z == nullptr || z->left == nullptr) return;

        node * x = z->left;
        z->left = x->right;
        if (x->right != nullptr)
        {
            x->right->p = z;
        }  
        x->p = z->p;
        if (z->p == nullptr)
        {
            root = x;
        }
        else if (z->p == z->p->left)
        {
            z->p->left = x;
        }
        else
        {
            z->p->right = x;
        }
        x->right = z;
        z->p = x;
        
    }
    // INSERT FIX-UP
    // Función auxiliar que se asegura que se mantengan las propiedades del árbol RB una vez insertado un nuevo elemento
    void insert_fixup (node *z)
    {
        while (z != root && z->p->color == 1)
        {
            if (z->p == z->p->p->left)
            {
                node * y = z->p->p->right;
                if (y != nullptr && y->color == 1)
                {
                    z->p->color = 0;
                    y->color = 0;
                    z->p->p->color = 1;
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->right)
                    {
                        z = z->p;
                        left_rotate(z);                    
                    }
                    z->p->color = 0;
                    z->p->p->color = 1;
                    right_rotate(z->p->p);
                }

            }
            else
            {
                node * y = z->p->p->left;
                if (y != nullptr && y->color == 1)
                {
                    z->p->color = 0;
                    y->color = 0;
                    z->p->p->color = 1;
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->left)
                    {
                        z = z->p;
                        right_rotate(z);
                    }
                    z->p->color = 0;
                    z->p->p->color = 1;
                    left_rotate(z->p->p);
                }       
            }
        }
        root->color = 0;
    }
    // Funcion INSERT-NODE. Agrega un nodo de clave k y pos i al arbol RB cumpliendo las propiedades de un arbol binario, pero no las de un arbol RB. Para arreglar el arbol,
    // llama a la funcion INSERT-FIXUP.
    void insert(int key, int i)
    {
        node * z = new node(key, i);
        node * y = nullptr;
        node * x = root;

        while (x != nullptr)
        {
            y = x;
            if (z->key <= x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        z->p = y;

        if (y == nullptr)
        {
            root = z;
        }
        else if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }

        insert_fixup(z);
    }
};

int main ()
{
    int size, nqueries, query_result, usrin, query;

    scanf("%d %d", &size, &nqueries);

    // inicializa el árbol RB
    RBtree list = RBtree();
    
    int pos = 0, key, posKey, occur = 0;
    /*
    Para solucionar la problematica de m ocurrencias de un nodo de clave k en el arbol RB, donde se debe retornar el indice i de la primera ocurrencia de k en la lista,
    guarda i en la variable 'posKey' y a todo nodo insertado en el arbol que coincida con k, se le asigna i. Cuando un nodo de clave l no coincida con k, suma m a posKey 
    tal que el resultado sea el indice que apunta al elemento l en la lista.

    Ilustración:
    Sea el arreglo {1 2 2 3 3 9}, el arbol RB tiene los nodos (1), (2), (3) y (9) con ocurrencias 1, 2, 2 y 1 y atributos 'pos' 0, 1, 3, 5, en el arbol respectivamente.
    */
    while (size > 0)
    {
        scanf("%d", &usrin);
        // Caso base. Esta insertando la raiz en el arbol RB.
        if (pos == 0)
        {
            posKey = pos;
            key = usrin;
            occur++;
            list.insert(key, 0);
        }
        else
        {
            if (key == usrin)
            {
                occur++;
                list.insert(key, posKey);
            }
            else
            {
                key = usrin;
                posKey = posKey + occur;
                list.insert(key, posKey);
                occur = 1;
            }
        }
        pos++;
        size--;
    }

    while (nqueries > 0)
    {
        scanf("%d", &query);
        query_result = list.search(query);
        printf("%d\n", query_result);
        nqueries--;
    }
    return 0;
}