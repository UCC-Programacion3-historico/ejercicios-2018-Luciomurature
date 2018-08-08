#ifndef REPASO_CIRCULO_H
#define REPASO_CIRCULO_H
#include "Geometria.h"



class Circulo: public Geometria {
protected:
    float radio;
public:
    float getRadio();
    void setRadio(float radio);
    float getPerimetro();
    float getSuperficie();

};


#endif //REPASO_CIRCULO_H
