#ifndef HASHMAP_H
#define HASHMAP_H

#include "NodoArbol.h"
#include "Nodo.h"

template<class T>
class ArbolBinario {
private:
    Nodo *raiz;
public:
    ArbolBinario();

    void put(T dato);

    T search(T dato);

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();

private:

    void put(T dato, NodoArbol<T> *r);

    T search(T dato, NodoArbol<T> *r);

    NodoArbol<T> *remove(T dato, NodoArbol<T> *r);

    void preorder(NodoArbol<T> *r);

    void inorder(NodoArbol<T> *r);

    void postorder(NodoArbol<T> *r);

    ~ArbolBinario();

    bool esVacio(NodoArbol<T> *r);

    void print(NodoArbol<T> *r);

};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
ArbolBinario<T>::ArbolBinario() {

}


/**
 * Destructor del Arbol
 */
template<class T>
ArbolBinario<T>::~ArbolBinario() {

}


/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template<class T>
T ArbolBinario<T>::search(T dato) {
    return search(dato, raiz); // llamada recursiva
}

template<class T>
T ArbolBinario<T>::search(T dato, NodoArbol<T> *r) {

    if(r == nullptr)
        throw 404;

    if(dato == r->getDato()){
        return r->getDato();
    }
    if(dato > r->getDato()){
        return search(dato, r->getDer());
    } else
        return search(dato, r->getIzq());
}


/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template<class T>
void ArbolBinario<T>::put(T dato) {
    if(raiz != nullptr)
        put(dato, raiz); // llamada recursiva
    else{
        raiz = NodoArbol<T>(dato);
    }

}


template<class T>
void ArbolBinario<T>::put(T dato, NodoArbol<T> *r) {


    T miDato = r->getDato();
    if(dato == miDato)
        throw 200;


    if(dato > miDato){
        if(r->getDer() != nullptr)
            put(dato, r->getDer());
        else{
            auto nuevo = new Nodo<T>(dato);
            r->setDer(nuevo);
        }
    } else{
        if(r->getIzq() != nullptr)
            put(dato, r->getIzq());
        else{
            auto nuevo = new Nodo<T>(dato);
            r->setIzq(nuevo);
        }
    }
}


/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T>
void ArbolBinario<T>::remove(T dato) {
    return remove(dato, raiz); // llamada recursiva
}


template<class T>
NodoArbol<T> *ArbolBinario<T>::remove(T dato, NodoArbol<T> *r) {
    if(r == nullptr)
        throw 404;

    if(dato == r->getDato()){
        r->setDer(remove(dato, r->getDato()));
    }
    if(dato > r->getDato()){
        r->setIzq(remove(dato, r->getDer()));
    } else
        remove(dato, r->getIzq());
    if(r->getIzq() != nullptr)
        put(r->getIzq(), r->getDer());

    NodoArbol<T> *aux = r->getDer();
    delete r;


    return aux;
}


/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool ArbolBinario<T>::esVacio() {
    return raiz == nullptr;
}


/**
 * Recorre un árbol en preorden
 */
template<class T>
void ArbolBinario<T>::preorder() {
    return preorder(raiz); // llamada recursiva
}


/**
 * Recorre un árbol en orden
 */
template<class T>
void ArbolBinario<T>::inorder() {
    return inorder(raiz); // llamada recursiva
}


/**
 * Recorre un árbol en postorden
 */
template<class T>
void ArbolBinario<T>::postorder() {
    return postorder(raiz); // llamada recursiva
}


/**
 * Muestra un árbol por consola
 */
template<class T>
void ArbolBinario<T>::print() {

}


#endif //HASHMAP_H