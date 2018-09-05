#include <iostream>Pila<char>
#include "../Pila/Pila.h"
using namespace std;

int main() {
    Pila<int> hola;
    Pila<int> chau;
    bool iguales = false;
    while(!hola.esVacia() && !chau.esVacia()){
        if(hola.pop() != chau.pop()){
            iguales = false;
            break;
        }
        else{
            iguales = true;
        }
    }
    cout << iguales << endl;
    return 0;
}