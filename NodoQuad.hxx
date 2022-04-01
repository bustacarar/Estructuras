#include "NodoQuad.h"

NodoQuad::NodoQuad(){
    this->dato.x=0;
    this->dato.y=0;
    this->hijoSupIzq=NULL;
    this->hijoSupDer=NULL;
    this->hijoInfIzq=NULL;
    this->hijoInfDer=NULL;
}

NodoQuad::NodoQuad(punto val){
    this->dato=val;
    this->hijoSupIzq=NULL;
    this->hijoSupDer=NULL;
    this->hijoInfIzq=NULL;
    this->hijoInfDer=NULL;
}

punto NodoQuad::obtenerDato(){
    return this->dato;
}

void NodoQuad::fijarDato(punto val){
    this->dato=val;
}

NodoQuad* NodoQuad::obtenerHijoSupIzq(){
    return (this->hijoSupIzq);
}

NodoQuad* NodoQuad::obtenerHijoInfIzq(){
    return (this->hijoInfIzq);
}

NodoQuad* NodoQuad::obtenerHijoSupDer(){
    return (this->hijoSupDer);
}

NodoQuad* NodoQuad::obtenerHijoInfDer(){
    return (this->hijoInfDer);
}

void NodoQuad::fijarHijoSupIzq(NodoQuad* sizq){
    this->hijoSupIzq= sizq;
}

void NodoQuad::fijarHijoInfIzq(NodoQuad* iizq){
    this->hijoInfIzq= iizq;
}

void NodoQuad::fijarHijoSupDer(NodoQuad* sder){
    this->hijoSupDer= sder;
}

void NodoQuad::fijarHijoInfDer(NodoQuad* ider){
    this->hijoInfDer= ider;
}

bool NodoQuad::esHoja(){
    if(this->hijoSupIzq==NULL && this->hijoSupDer==NULL && this->hijoInfIzq==NULL && this->hijoInfDer==NULL)
        return true;
    else
        return false;
}
