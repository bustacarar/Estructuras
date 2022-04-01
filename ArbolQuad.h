#ifndef ARBOLQUAD_H_INCLUDED
#define ARBOLQUAD_H_INCLUDED

#include <iostream>
#include "NodoQuad.hxx"

class ArbolQuad {
protected:
    NodoQuad* raiz;
public:
    ArbolQuad();
    ArbolQuad(punto val);
    ~ArbolQuad();
    punto datoRaiz();
    NodoQuad* obtenerRaiz();
    void fijarRaiz(NodoQuad* n_raiz);
    bool esVacio();
    NodoQuad* insertarNodo(punto val,NodoQuad* padre);
    bool insertar(punto val);
    NodoQuad* Buscar(punto val);
    NodoQuad* buscarNodo(punto val,NodoQuad* padre);
    void preOrden();
    void preOrden(NodoQuad *currnodo);
    void inOrden();
    void inOrden(NodoQuad *currnodo);
    void posOrden();
    void posOrden(NodoQuad *currnodo);
    void nivelOrden();
};


#endif // ARBOLQUAD_H_INCLUDED
