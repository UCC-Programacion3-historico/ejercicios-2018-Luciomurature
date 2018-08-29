#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

/**
 * Clase que implementa una Lista Enlazada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    Nodo<T> *inicio;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista(); //necesito destructor porque la lista usa memoria dinamica

    bool esVacia();

    int getTamanio();

    void insertar(unsigned int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(unsigned int pos);

    T getDato(unsigned int pos);

    void reemplazar(int pos, T dato); // "editar" dato

    void vaciar();
};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio = nullptr;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() {
    return inicio == nullptr; // si o no xd
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    //recorrer hasta llegar a null
    int cant = 0;
    Nodo<T> aux = inicio; //creo nodo auxiliar igual al inicio.
    //recorro mientras aux no sea el puntero nulo, cambiando aux al siguiente cada vuelta.
    while(aux != nullptr){
        cant++;
        aux = aux->getNext(); //auxiliar va a ser el siguiente usando la funcion getNext
    }
    return cant;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(unsigned int pos, T dato) {
    auto *nuevo = new Nodo<T>(); //auto es equivalente a Nodo<T> (nuevo va a ser del tipo Nodo T)
    Nodo<T> *aux = inicio; //puntero auxiliar que apunta a inicio
    if(pos == 0){ //caso especial
        nuevo->setNext(inicio);
        inicio = nuevo;
        return;
    }

    nuevo->setDato(dato); // le meto el dato parametro

    int pos_actual = 0; //voy pasando la lista cambiando el auxiliar
    while(pos_actual < pos-1 && aux != nullptr){
        pos_actual++;
        aux = aux->getNext(); //auxiliar va a ser el siguiente usando la funcion getNext
    }
    if(aux == nullptr){
        throw 1;
    }else{
        nuevo->setNext(aux->getNext()); // nuevo apunta a donde apunta aux
        aux->setNext(nuevo); //y aux apunta al nuevo nodo creado
    }

}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    auto *nuevo = new Nodo<T>();
    nuevo->setDato(dato);
    nuevo->setNext(inicio);
    inicio = nuevo;

}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    auto *nuevo = new Nodo<T>();
    Nodo<T> *aux = inicio;

    nuevo->setDato(dato);
    nuevo->setNext(nullptr);

    if(aux == nullptr){ //si la lista es vacia
        inicio = nuevo;
        return;
    }


    while(aux->getNext() != nullptr){ //Si el siguiente del auxiliar es nulo, sino me voy de la lista.
        aux = aux->getNext();
    }

    aux->setNext(nuevo);
}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(unsigned int pos) {
    Nodo<T> *aux = inicio;

    while(pos > 1 && aux != nullptr){
        pos--;
        aux = aux->getNext();
    }
    //una vez llegado al nodo que me interesa
    //la forma mas larga seria
    /*
     Nodo<T> *siguiente = aux->getNext();
     siguiente = siguiente->getNext();
     aux->setNext(siguiente);
    */
    if(aux == nullptr){ //no existe el nodo
        throw 1;
    }
    if(pos == 0){ //si elimino el primer nodo
        inicio = nullptr;
        delete aux;
    }else{
        /*aux->setNext(aux->getNext()->getNext()) //aux get next es siguiente, entonces necesito el siguiente. seria el siguiente del siguiente
        delete aux->getNext();
        aux->setNext(nullptr);*/
        Nodo<T> *siguiente = aux->getNext();
        if(siguiente != nullptr){
            aux->setNext(siguiente->getNext());
            delete siguiente;
        }
    }


}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(unsigned int pos) {
    Nodo<T> *aux = inicio;

    while(pos > 1 && aux != nullptr){
        pos--;
        aux = aux->getNext();
    }
    //una vez llegado al nodo que me interesa
    if(aux == nullptr){
        throw 1;
    }
    return aux->getDato();
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    Nodo<T> *aux = inicio;

    while(pos > 1 && aux != nullptr){
        pos--;
        aux = aux->getNext();
    }
    //una vez llegado al nodo que me interesa
    if(aux == nullptr){
        throw 1;
    }
    aux->setDato(dato);
}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {}


#endif //LISTA_H