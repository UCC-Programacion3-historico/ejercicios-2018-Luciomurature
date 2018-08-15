#include <iostream>
#include "digitos.h"

using namespace std;

unsigned int cociente(unsigned int a, unsigned int b) {
    if(b > a)
        return 0;
    else
        return cociente(a-b, b) + 1;
}


unsigned int resto(unsigned int a, unsigned int b) {
    if(a<b){
        return a;
    }
    else{
        return resto(a-b, b);
    }
}


void escribir_espaciado(unsigned int num) {
    int var;
    if(num < 10){
        std::cout << num << "  ";
        return;
    }
    else{
        var = resto(num, 10);
        num = cociente(num, 10);
        escribir_espaciado(num);
        std::cout << var << "  ";
    }
}
