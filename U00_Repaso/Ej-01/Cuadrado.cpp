#include "Cuadrado.h"
#include "Geometria.h"

float Cuadrado::getSuperficie() {
    return Geometria::getAlto() * Geometria::getAncho();
}

