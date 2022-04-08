
#ifndef TAD_KD_TREE_NODOKD_H
#define TAD_KD_TREE_NODOKD_H

#include <iostream>
#include "Punto.h"

class NodoKD {
protected:
    punto dato;
    std::string tipoFruta;
    NodoKD* hijoIzq;
    NodoKD* hijoDer;
public:
    NodoKD();
    NodoKD(punto val);
    NodoKD(punto val, std::string fruta);
    ~NodoKD();
    bool esHoja();
    punto obtenerDato();
    void fijarDato(punto val);
    std::string obtenerFruta();
    void fijarFruta(std::string val);
    NodoKD* obtenerHijoIzq();
    NodoKD* obtenerHijoDer();
    void fijarHijoIzq(NodoKD* izq);
    void fijarHijoDer(NodoKD* der);

};


#include "NodoKD.hxx"

#endif //TAD_KD_TREE_NODOKD_H
