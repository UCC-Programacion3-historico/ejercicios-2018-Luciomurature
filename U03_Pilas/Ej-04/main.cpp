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
    else throw 1;
}

int main() {
    string ecuacion = "{(4*8+(3+5))*[4+5]}";
    long n = ecuacion.length();
    Pila<char> lucio;
    for(int i = 0 ; i < n ; i++){
        if(ecuacion[i] == '{' || ecuacion[i] == '(' || ecuacion[i] == '['){
            lucio.push(ecuacion[i]);
        }
        if(ecuacion[i] == '}' || ecuacion[i] == ')' || ecuacion[i] == ']'){
            if(lucio.peek() == inverso(ecuacion[i])){
                lucio.pop();
            }
        }
    }
    cout << "la ecuacion esta bien escrita ? "<< lucio.esVacia() << endl;

    return 0;
}