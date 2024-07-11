#include <iostream>
#include <vector>
    
using namespace std;
// Funcion auxiliar para imprimir en el stdout una matriz B de dimension m x n
void printMatrix (vector<vector<int>> &B, int m, int n)
{
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                printf("%d ", B[i][j]);
            }
            printf("%d", B[i][n - 1]);
            printf("\n");
        }
}
/*
Pasa por cada uno de los elementos de la matriz. Si encuentra un 0 en la posicion ij,
entonces convierte en 0 a cada uno de los elementos de la fila i y la columna j. A su vez,
guarda la coordenada ij donde encontró un 1 y los inserta en una lista. Despues de haber
leido toda la matriz, verifica las coordenadas de los 1s y verifica si es posible colocar
un 1 en la fila i o en la columna j de la matriz respuesta B buscando una casilla en el
que no haya un 0. Hace esta verificacion para cada uno de los pares de coordenadas
encontrados. Si no es posible colocar un 1, entonces la matriz B es imposible de determinar.
*/ 
bool orMatrix (int m, int n, vector <vector <int>> &A, vector <vector <int>> &B)
{
    vector <int> posOf1;
    bool isPossible;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 0){
                // Coloca 0s en la fila i y en la columna j en la matriz resultado
                for (int col = 0; col < n; col++){
                    B[i][col] = 0;
                }
                for (int row = 0; row < m; row++){
                    B[row][j] = 0;
                }
            } else{
                posOf1.push_back(i);
                posOf1.push_back(j);
            }
        }
    }
    // Verificamos la columna y el renglon del elemento en la posicion ij. Si es posible colocar un 1 en el renglon o en la fila para
    // todos los 1s que hay en A, entonces la matriz resultado B existe.
    for (int k = 0; k < posOf1.size(); k += 2)
    {
        isPossible = false;
        int i = posOf1[k], j = posOf1[k + 1];
        if (B[i][j] == 0){
            for (int col = 0; col < n; col++){
                if (B[i][col] != 0){
                    isPossible = true;
                    B[i][col] = 1;
                }
            }
            for (int row = 0; row < m; row++){
                if (B[row][j] != 0){
                    isPossible = true;
                    B[row][j] = 1;
                }
            }
            if (!(isPossible)) {
                return false;
            }
        } else{
            B[i][j] = 1;
        }            
    }
    return true;
}


int main ()
{
    int m, n, e;

    scanf("%d %d", &m, &n);

    vector <vector <int>> A (m, vector<int>(n));
    vector <vector <int>> B (m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &e);
            A[i][j] = e;
        }
    }
    bool ans = orMatrix(m, n, A, B);

    if (ans)
    {
        printf("YES\n");
        printMatrix(B, m, n);
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}