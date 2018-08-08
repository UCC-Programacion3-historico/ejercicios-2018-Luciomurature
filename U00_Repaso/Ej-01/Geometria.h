#ifndef REPASO_GEOMETRIA_H
#define REPASO_GEOMETRIA_H

#include "Color.h"

class Geometria {
    protected:
        float ancho;
public:
    float getAncho() const;

    void setAncho(float ancho);

    float getAlto() const;

    void setAlto(float alto);

protected:
    float alto;
    public:
        Color col;
        virtual float getPerimetro() = 0;
        virtual float getSuperficie() = 0;
};


#endif //REPASO_GEOMETRIA_H
