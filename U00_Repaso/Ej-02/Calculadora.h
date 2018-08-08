#ifndef REPASO_CALCULADORA_H
#define REPASO_CALCULADORA_H
#include <iostream>;
using namespace std;


template <class T>
class Calculadora {
public:
    T sumar(T a, T b){
        return a+b;
    }
    T restar(T a, T b){
        return a-b;
    }
    T multiplicar(T a, T b){
        return a*b;
    }
    T dividir(T a, T b){
        if(b == 0)
            throw 404;
        return a/b;
    }
};


#endif //REPASO_CALCULADORA_H
