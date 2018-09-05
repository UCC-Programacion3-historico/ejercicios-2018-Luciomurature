#include <iostream>
#include "../Pila/Pila.h"
#include <string.h>
using namespace std;

char inverso(char p){
    if(p == '}')
        return '{';
    if(p == ')')
        return '(';
    if(p == ']')
        return '[';
    else
        return 'a';
}

int main() {
    string ecuacion = "{(4*8+(3+5))*[4+5]}";
    Pila<char> lucio;
    for(int i = 0 ; i < ecuacion.length() ; i++){
        if(ecuacion[i] == '{' || ecuacion[i] == '(' || ecuacion[i] == '['){
            lucio.push(ecuacion[i]);
        }
        if(ecuacion[i] == '}' || ecuacion[i] == ')' || ecuacion[i] == ']'){
            if(lucio.peek() == inverso(ecuacion[i])){
                lucio.pop();
            }
        }
    }
    cout << "la ecuacion esta bien escrita: "<< lucio.esVacia() << endl;

    return 0;
}