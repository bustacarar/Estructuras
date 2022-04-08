#include "NodoKD.h"

NodoKD::NodoKD(punto val) {
    this->dato=val;
    this->hijoIzq=NULL;
    this->hijoDer = NULL;
}

NodoKD::NodoKD() {
    this->hijoIzq=NULL;
    this->hijoDer = NULL;
}


NodoKD::NodoKD(punto val,std::string fruta) {
    this->dato=val;
    this->hijoIzq=NULL;
    this->hijoDer = NULL;
    this->tipoFruta=fruta;
}

punto NodoKD::obtenerDato() {
    return this->dato;
};

bool NodoKD::esHoja() {
    if(obtenerHijoDer()==NULL&&obtenerHijoIzq()==NULL){
        return true;
    }else{
        return false;
    }
}

NodoKD* NodoKD::obtenerHijoDer() {
    return this->hijoDer;
}

NodoKD* NodoKD::obtenerHijoIzq() {
    return this->hijoIzq;
}

void NodoKD::fijarDato(punto val){
    this->dato=val;

}

void NodoKD::fijarHijoIzq(NodoKD* izq){
    this->hijoIzq=izq;
}
void NodoKD::fijarHijoDer(NodoKD *der) {
    this->hijoDer=der;
}

std::string NodoKD::obtenerFruta(){
    return this->tipoFruta;
}
void NodoKD::fijarFruta(std::string val){
    this->tipoFruta=val;
}