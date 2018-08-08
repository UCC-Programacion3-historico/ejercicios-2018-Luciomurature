#ifndef REPASO_GEOMETRIA_H
#define REPASO_GEOMETRIA_H


class Geometria {
    protected:
        float ancho;
        float alto;
        char *color;
    public:
        virtual float getPerimetro() const  = 0;
        virtual float getSuperficie() const  = 0;
};


#endif //REPASO_GEOMETRIA_H
