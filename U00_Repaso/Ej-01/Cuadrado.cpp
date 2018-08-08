#include "Cuadrado.h"
#include "Geometria.h"
#include <math.h>

float Cuadrado::getSuperficie() {
    return Geometria::getAlto() * Geometria::getAncho();
}

float Cuadrado::getDiagonal() {
    return sqrt(2*(Geometria::getAlto() * Geometria::getAncho())
}

float Cuadrado::getPerimetro() {
    return 4*Geometria::getAlto();
}