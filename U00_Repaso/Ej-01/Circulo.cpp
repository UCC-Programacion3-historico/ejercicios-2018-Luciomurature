#include "Circulo.h"
#define PI 3.1415926

float Circulo::getRadio() const {
    return radio;
}

void Circulo::setRadio(float radio) {
    Circulo::radio = radio;
}

float Circulo::getPerimetro() {
    return PI * radio * radio;
}

float Circulo::getSuperficie()
    return PI * 2 * radio;
}
