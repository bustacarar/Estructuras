#include "ArbolQuad.h"

ArbolQuad::ArbolQuad(){
    this->raiz= NULL;
}

ArbolQuad::ArbolQuad(punto val){
    this->raiz = new NodoQuad(val);
}

punto ArbolQuad::datoRaiz(){
    return (this->raiz)->obtenerDato();
}

NodoQuad* ArbolQuad::obtenerRaiz(){
    return this->raiz;
}

void ArbolQuad::fijarRaiz(NodoQuad* n_raiz){
    this->raiz=n_raiz;
}

bool ArbolQuad::esVacio(){
    if(this->raiz==NULL)
        return true;
    else
        return false;
}

NodoQuad* ArbolQuad::insertarNodo(punto val,NodoQuad* padre){
    NodoQuad *nodo=NULL,*aux=NULL;
    if(esVacio()){
        raiz = new NodoQuad(val);
        aux=NULL;
    }
    else if(padre==NULL){
        nodo= new NodoQuad(val);
        aux=nodo;
    }
    else if(val.x < padre->obtenerDato().x && val.y < padre->obtenerDato().y){
        nodo=insertarNodo(val,padre->obtenerHijoInfIzq());
        if(nodo==NULL){
            aux=NULL;
        }
        else{
            padre->fijarHijoInfIzq(nodo);
            aux=padre;
        }
    }
    else if(val.x < padre->obtenerDato().x && val.y > padre->obtenerDato().y){
        nodo=insertarNodo(val,padre->obtenerHijoSupIzq());
        if(nodo==NULL){
            aux=NULL;
        }
        else{
            padre->fijarHijoSupIzq(nodo);
            aux=padre;
        }
    }
    else if(val.x > padre->obtenerDato().x && val.y < padre->obtenerDato().y){
        nodo=insertarNodo(val,padre->obtenerHijoInfDer());
        if(nodo==NULL){
            aux=NULL;
        }
        else{
            padre->fijarHijoInfDer(nodo);
            aux=padre;
        }
    }
    else if(val.x > padre->obtenerDato().x && val.y > padre->obtenerDato().y){
        nodo=insertarNodo(val,padre->obtenerHijoSupDer());
        if(nodo==NULL){
            aux=NULL;
        }
        else{
            padre->fijarHijoSupDer(nodo);
            aux=padre;
        }
    }
    return aux;
}

bool ArbolQuad::insertar(punto val){
    if(insertarNodo(val,raiz))
        return true;
    else
        return false;
}

NodoQuad* ArbolQuad::buscarNodo(punto val,NodoQuad* padre){
    if(padre->obtenerDato()==val){
        return padre;
    }
    else{
        if(val.x < padre->obtenerDato().x && val.y < padre->obtenerDato().y){
            buscarNodo(val,padre->obtenerHijoInfIzq());
        }
        else if(val.x < padre->obtenerDato().x && val.y > padre->obtenerDato().y){
            buscarNodo(val,padre->obtenerHijoSupIzq());
        }
        else if(val.x > padre->obtenerDato().x && val.y < padre->obtenerDato().y){
            buscarNodo(val,padre->obtenerHijoInfDer());
        }
        else{
            buscarNodo(val,padre->obtenerHijoSupDer());
        }
    }
}

NodoQuad* ArbolQuad::Buscar(punto val){
    return buscarNodo(val,raiz);
}

void ArbolQuad::preOrden(NodoQuad *currnodo){
    if(currnodo){
        std::cout<<currnodo->obtenerDato()<<" ";
        preOrden(currnodo->obtenerHijoSupIzq());
        preOrden(currnodo->obtenerHijoSupDer());
        preOrden(currnodo->obtenerHijoInfIzq());
        preOrden(currnodo->obtenerHijoInfDer());
    }
}

void ArbolQuad::inOrden(NodoQuad *currnodo){
    if(currnodo){
        inOrden(currnodo->obtenerHijoSupIzq());
        inOrden(currnodo->obtenerHijoSupDer());
        std::cout<<currnodo->obtenerDato()<<" ";
        inOrden(currnodo->obtenerHijoInfIzq());
        inOrden(currnodo->obtenerHijoInfDer());
    }
}

void ArbolQuad::posOrden(NodoQuad *currnodo){
    if(currnodo){
        posOrden(currnodo->obtenerHijoSupIzq());
        posOrden(currnodo->obtenerHijoSupDer());
        posOrden(currnodo->obtenerHijoInfIzq());
        posOrden(currnodo->obtenerHijoInfDer());
        std::cout<<currnodo->obtenerDato()<<" ";
    }
}

void ArbolQuad::preOrden(){
    preOrden(raiz);
}
void ArbolQuad::inOrden(){
    inOrden(raiz);
}
void ArbolQuad::posOrden(){
    posOrden(raiz);
}

