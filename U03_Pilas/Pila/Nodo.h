//
// Created by alumno on 29/08/18.
//

#ifndef PROGRAMACION3_NODO_H
#define PROGRAMACION3_NODO_H

template <class T>
class Nodo {
private:
    T dato;
    Nodo *next;
public:
    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        Nodo::dato = dato;
    }

    Nodo *getNext() const {
        return next;
    }

    void setNext(Nodo *next) {
        Nodo::next = next;
    }

};


#endif //PROGRAMACION3_NODO_H
