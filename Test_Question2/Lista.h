
#include "Nodo.h"
#include <functional>
typedef unsigned int uint;
template <class T>
class Lista {
private:
    Nodo<T>* nodo;
    typedef function<int(T, T)> Comp;
    Nodo<T>* ini;
    uint lon; // n�mero de elementos en la lista

public:
    Lista() : ini(nullptr), lon(0) { nodo = new Nodo<T>(); }
    Lista(Nodo<T>* pNodo) {
        nodo = pNodo;
    };
    uint longitud();
    bool esVacia();
    void agregaInicial(T elem);
    void agregaPos(T elem, uint pos);
    void agregaFinal(T elem);
    void modificarInicial(T elem);
    void modificarPos(T elem, uint pos);
    void modificarFinal(T elem);
    void eliminaInicial();
    void eliminaPos(uint pos);
    void eliminaFinal();
    T obtenerInicial();
    T obtenerPos(uint pos);
    T obtenerFinal();
    T buscar(T elem);


    //~Lista(void);
    void agregar(T pNodo); //sumar nodos a la lista
    int size();
};
template <class T>
uint Lista<T>::longitud() {
    return lon;
}
template <class T>
bool Lista<T>::esVacia() {
    return lon == 0;
}
template <class T>
void Lista<T>::agregaInicial(T elem) {
    Nodo<T>* nuevo = new Nodo<T>(elem);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
}
template <class T>
T Lista<T>::buscar(T elem) {
    Nodo<T>* aux = ini;
    while (aux != nullptr) {
        if (comparar(aux->elem, elem) == 0) {
            return aux->elem;
        }
        aux = aux->sgte;
    }
    return 0;
}

template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        Nodo<T>* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        Nodo<T>* nuevo = new Nodo<T>(elem);
        nuevo->set_Sgte(aux->get_Sgte());
        if (nuevo != nullptr) {

            aux->set_Sgte(nuevo);
            lon++;
        }
    }
}
template <class T>
void Lista<T>::agregaFinal(T elem) {
    agregarPos(elem, lon); // ;)
}

template <class T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        Nodo<T>* aux = ini;
        ini = ini->sgte;
        delete aux;
        lon--;
    }
}

template <class T>
void Lista<T>::eliminaPos(uint pos) {
}
template <class T>
void Lista<T>::eliminaFinal() {
}

template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->elem = elem;
    }
}

template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sgte;
        }
        aux->elem = elem;
    }
}
template <class T>
void Lista<T>::modificarFinal(T elem) {
    modificar(elem, lon - 1);
}

template <class T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}


template <class T>
T Lista<T>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        return aux->get_Elem();
    }
    else {
        return NULL;
    }
}
template <class T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}

template <class T>
void Lista<T>::agregar(T d) //100
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_Sgte(nodo);
    nodo = nuevo;
}



