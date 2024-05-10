#include <iostream>

using namespace std;

int main() {

    int usrin; 

    while (usrin != 42){
        cin >> usrin;
        if (usrin == 42){
            return 0;
        } else{
            cout << usrin << endl;
        }
    }
}