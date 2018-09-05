#include <iostream>
#include "../Pila/Pila.h"
#include <string.h>
using namespace std;

int main() {
    char *palabra = "lechuga de satan";
    Pila<char> caca;
    for(int i = 0; i<strlen(palabra) ; i++){
        caca.push(palabra[i]);
    }
    for(int i = 0; i<strlen(palabra) ; i++){
        cout << caca.pop();
    }
    return 0;
}