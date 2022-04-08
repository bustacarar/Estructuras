#include "ArbolKD.h"


ArbolKD::ArbolKD() {
    this->raiz= NULL;
}

ArbolKD::ArbolKD(punto val,std::string fruta){
    this->raiz = new NodoKD(val,fruta);
}

ArbolKD::ArbolKD(punto val){
    this->raiz = new NodoKD(val);
}

NodoKD *ArbolKD::obtenerRaiz() {
    return this->raiz;
}

bool ArbolKD::esVacio() {
    if(this->raiz==NULL)
        return true;
    else
        return false;
}


NodoKD* ArbolKD::insertarNodo(punto val,std::string fruta,NodoKD* padre,bool dimension){ //Si dimension==t, x; si dimension==f, y
    NodoKD *nodo=NULL,*aux=NULL;
    if(this->esVacio()){

        this->raiz = new NodoKD(val,fruta);//std::cout<<"SII"<<std::endl;
        aux=NULL;
    }
    else if(padre==NULL){
        nodo= new NodoKD(val);
        aux=nodo;
    }else if(dimension){
        //comparación en x
        if(val.x<=padre->obtenerDato().x){
            if(padre->obtenerHijoIzq()==NULL){
                nodo=new NodoKD(val);
                nodo->fijarFruta(fruta);
                padre->fijarHijoIzq(nodo);
                return nodo;
            }else{
                insertarNodo(val, fruta,padre->obtenerHijoIzq(),!dimension);
            }
        }else{
            if(padre->obtenerHijoDer()==NULL){

                nodo=new NodoKD(val);
                nodo->fijarFruta(fruta);
                padre->fijarHijoDer(nodo);
                return nodo;
            }else{
                insertarNodo(val, fruta,padre->obtenerHijoDer(),!dimension);
            }
        }
    }else{
        //comparación en y
        if(val.y<=padre->obtenerDato().y){
            if(padre->obtenerHijoIzq()==NULL){
                nodo=new NodoKD(val);
                nodo->fijarFruta(fruta);
                padre->fijarHijoIzq(nodo);
            }else{
                insertarNodo(val, fruta,padre->obtenerHijoIzq(),!dimension);
            }
        }else{
            if(padre->obtenerHijoDer()==NULL){
                nodo=new NodoKD(val);
                nodo->fijarFruta(fruta);
                padre->fijarHijoDer(nodo);
            }else{
                insertarNodo(val, fruta,padre->obtenerHijoDer(),!dimension);
            }
        }

    }

    return nodo;
}

bool ArbolKD::insertar(punto val,std::string fruta){
    if(insertarNodo(val,fruta,this->raiz,true))
        return true;
    else
        return false;
}

void ArbolKD::inOrden(NodoKD* nodo) {
    if (nodo)
    {
        inOrden(nodo->obtenerHijoIzq());
        std::cout <<"("<< nodo->obtenerDato().x <<","<<nodo->obtenerDato().y<<") ";
        inOrden(nodo->obtenerHijoDer());
    }
}

bool ArbolKD::buscar(punto val){
    if(buscarNodo(val,this->raiz,true)){
        return true;
    }else{
        return false;
    }
}

NodoKD* ArbolKD::buscarNodo(punto val,NodoKD* nodokd,bool dimension){ //Si dimension==t, x; si dimension==f, y
    //NodoKD *nodo=NULL;
    if(nodokd==NULL){
        return NULL;
    }
    if(this->esVacio()){
        return NULL;
    }
    else if(nodokd->obtenerDato().x==val.x&&nodokd->obtenerDato().y==val.y){
        return nodokd;
    }
    if(nodokd->obtenerHijoIzq()==NULL&&nodokd->obtenerHijoDer()==NULL){
        return NULL;
    }
    if(dimension){
        //comparación en x
        if(val.x<=nodokd->obtenerDato().x){
            buscarNodo(val,nodokd->obtenerHijoIzq(),!dimension);
        }else{
            buscarNodo(val,nodokd->obtenerHijoDer(),!dimension);
        }
    }else{
        //comparación en y
        if(val.y<=nodokd->obtenerDato().y){
            buscarNodo(val,nodokd->obtenerHijoIzq(),!dimension);
        }else{
            buscarNodo(val,nodokd->obtenerHijoDer(),!dimension);
        }

    }

}

std::string ArbolKD::busquedaEuclidiana(punto val){
    NodoKD* masCercano=new NodoKD();
    float distancia=1000000000000000000;
    std::string dato;
    buscarMasCercano(val,this->raiz,true,dato,distancia);
    return dato;
}

void ArbolKD::buscarMasCercano(punto val, NodoKD* nodokd, bool dimension, std::string &datoPotencial,float& distanciaMin){
    if(this->esVacio()){
        return;
    }
    float distancia= sqrt(pow(val.x-nodokd->obtenerDato().x,2)+pow(val.y-nodokd->obtenerDato().y,2));
    //std::cout<<distancia<<" "<<distanciaMin<<std::endl;
    if(distancia<distanciaMin){
        distanciaMin=distancia;
        datoPotencial=nodokd->obtenerFruta();
       //std::cout<<datoPotencial<< std::endl;
    }
    if(nodokd->obtenerHijoIzq()==NULL&&nodokd->obtenerHijoDer()==NULL){
        //std::cout<<"MIN: "<<distanciaMin<<" "<<datoPotencial<<std::endl;
        return;
    }
    if(dimension){
        //comparación en x
        if(val.x<=nodokd->obtenerDato().x){
            buscarMasCercano(val,nodokd->obtenerHijoIzq(),!dimension,datoPotencial,distanciaMin);
        }else{
            buscarMasCercano(val,nodokd->obtenerHijoDer(),!dimension,datoPotencial,distanciaMin);
        }
    }else{
        //comparación en y
        if(val.y<=nodokd->obtenerDato().y){
            buscarMasCercano(val,nodokd->obtenerHijoIzq(),!dimension,datoPotencial,distanciaMin);
        }else{
            buscarMasCercano(val,nodokd->obtenerHijoDer(),!dimension,datoPotencial,distanciaMin);
        }

    }

}