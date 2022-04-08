
#ifndef TAD_KD_TREE_ARBOLKD_H
#define TAD_KD_TREE_ARBOLKD_H

#include "NodoKD.h"
#include "math.h"

class ArbolKD {
protected:
    NodoKD* raiz;
public:
    ArbolKD();
    ArbolKD(punto val);
    ArbolKD(punto val,std::string fruta);
    ~ArbolKD();
    punto datoRaiz();
    NodoKD* obtenerRaiz();
    void fijarRaiz(NodoKD* n_raiz);
    bool esVacio();
    bool insertar(punto val,std::string fruta);
    NodoKD* insertarNodo(punto val,std::string fruta, NodoKD* padre, bool dimension);
    void preOrden();
    void inOrden(NodoKD* nodo);
    void posOrden();
    void nivelOrden();
    bool buscar(punto val);
    NodoKD* buscarNodo(punto val, NodoKD* nodo,bool dimension);
    std::string busquedaEuclidiana(punto val);
    void buscarMasCercano(punto val, NodoKD* nodoKd, bool dimension,std::string &datoPotencial,float&distancia);

};

#include "ArbolKD.hxx"

#endif //TAD_KD_TREE_ARBOLKD_H
