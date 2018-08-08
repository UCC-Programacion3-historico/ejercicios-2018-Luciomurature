#include <iostream>
#include "Calculadora.h"

using namespace std;

int main() {
    Calculadora<int> micalc;
    Calculadora<double> micalcDouble;
    cout << micalc.sumar(2,2)<< endl;
    cout << micalc.restar(2,3) << endl;
    cout << micalc.dividir(15,3) << endl;
    cout << micalc.multiplicar(3,8) << endl;
    cout << micalcDouble.sumar(0.258963,2.528)<< endl;
    cout << micalcDouble.restar(2.5,3.89665874) << endl;
    cout << micalcDouble.dividir(15,3) << endl;
    cout << micalcDouble.multiplicar(5.36,8.98) << endl;


    return 0;
}