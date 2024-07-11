#include <iostream>
#include <string>
#include <vector>
    
using namespace std;
// Determina si un caracter k es el minimo lexicografico en el string s. Logra esto verificando si las ocurrencias de los elementos anteriores,
// que son menores lexicograficamente, son 0.
bool ismin(string &s, vector <int> & list, char k){

    for (int i = 0; i < k - 'a'; i++){
        if (list[i] != 0){
            return false;
        }
    }
    return true;
}
/*
Itera sobre los caracteres de s y los pushea en el string t hasta encontrar el minimo 
lexicografico. Una vez conseguido el minimo, es insertado directamente en el string u
y se busca el minimo lexicografico en los caracteres de t
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    vector<int> ocurrences (26, 0);

    // cuenta el numero de ocurrencias de cada caracter en s y guarda la informacion en el vector ocurrences
    cin >> s;
    for (char e: s){
        ocurrences[e - 'a'] += 1;
    }

    string t = "";
    string u = "";

    while (s.size() > 0){
        t.push_back(s[0]);
        s.erase(0,1);
        ocurrences[t.back() - 'a'] -= 1;

        while (t.size() != 0){
            
            if (ismin(s, ocurrences, t.back())){
                u.push_back(t.back());
                t.pop_back();
            } else {
                break;
            }
        }
    }
    cout << u << endl;
    return 0;
}