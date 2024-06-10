#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
    /*
    La idea del algoritmo es recorrer solo una vez cada uno de los caracteres del string compuesto por paréntesis de apertura y cierre e identificar cuando encuentra cualquiera de los dos
    para sumar una unidad al número total de cambios necesarios para que el string sea un RBS o seguir recorriendo el string.
    */
    ios_base::sync_with_stdio(0);

    long long len;

    string s;

    long long ans = 0;
    vector<char> brackets;
    cin >> s;
    len = s.size();
    for (long long i = 0; i < len; i++)
    {
        /*
        Crea un vector de caracteres que contiene todos los paréntesis de apertura encontrados hasta el i-ésimo índice. Si resulta que no ha encontrado un paréntesis de apertura, pero sí uno 
        de cierre, retorna 'imposible, pues se habrá encontrado con casos donde solo se han entregado paréntesis de cierre y para el cual no se pueden hacer intercambios tales que
        el string se convierta en un RBS. Ejemplo: }}))>>]]...
        */
        if (s[i] == 40 || s[i] == 60 || s[i] == 91 || s[i] == 123) 
        {
            brackets.push_back(s[i]);
        }
        else
        {
            if (brackets.size() == 0)
            {
                printf("Impossible");
                
                return 0;
            }
            else
            {
                /*
                En este punto, el algoritmo habrá encontrado paréntesis de apertura y se habrá topado con el primero de cierre. Si el paréntesis de cierre es del mismo tipo que el último
                paréntesis de apertura encontrado, entonces lo eliminará del vector y verificará el siguiente paréntesis. Si no es el caso que el sig. paréntesis es del mismo tipo, suma una unidad
                al número de intercambios a realizar para que el paréntesis, hasta ahora, pueda ser considerado un RBS y elimina también el último paréntesis de entrada del vector. 
                */
                if((s[i] == 41 && brackets[brackets.size() - 1] == 40) || (s[i] == 62 && brackets[brackets.size() - 1] == 60) || (s[i] == 93 && brackets[brackets.size() - 1] == 91) || (s[i] == 125 && brackets[brackets.size() - 1] == 123))
                {
                    brackets.pop_back();
                }
                else
                {
                    ans++;
                    brackets.pop_back();
                }
            }                
        }

    }
    /*
    Si después de haber recorrido todos los elementos del string todavía quedan paréntesis de entrada por corresponder a paréntesis de salida, entonces el string no puede ser un RBS. 
    De no ser ese el caso, entonces el string es un RBS y se retornará el número de intercambios realizados para que pueda ser considerado así.
    */
    if (brackets.size() != 0)
    {
        printf("Impossible");
        return 0;
    }

    cout << ans << endl;
    brackets.clear();

}