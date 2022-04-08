#include <iostream>
#include "ArbolKD.h"
#include "Punto.h"
#include "ArbolQuad.h"
#include <fstream>
#include <chrono>

int main(int argc, char* argv[]) {
    ArbolQuad* quad = new ArbolQuad();
    ArbolKD* kd=new ArbolKD();
    punto insercion;
    NodoQuad* resbus;
    std::string archivo="C:\\Users\\willi\\OneDrive- Universidad\\OneDrive - Pontificia Universidad Javeriana\\UNIVERSIDAD\\ESTRUCTIRAS DE DATOS\\KDTREE TAD\\ejemplo1.txt";// argv[1];
    std::fstream entrada;
    std::ofstream salidaInsertar;
    salidaInsertar.open("Insertar1.txt");
    std::ofstream salidaBuscar;
    salidaBuscar.open("Busca1.txt");
    entrada.open(archivo,std::ios::in);
    int cont=0;
    if(entrada.is_open()){
        while(!entrada.eof()){
            cont++;
            std::string tipo="";
            int color=0;
            std::string pesosS;
            std::string colorS;
            float pesos=0;
            //std::getline(entrada,tipo,' ');
            //std::getline(entrada,pesosS,' ');
            //std::getline(entrada,colorS,' ');
            entrada>>tipo;
            entrada>>pesosS;
            entrada>>colorS;
            //std::cout<<tipo<<" "<<pesos<<" "<<color<<std::endl;


            //cambio a punto para interpretar como float
            for(int i=0; i<pesosS.size();i++){
                if(pesosS[i]==','){
                    pesosS[i]='.';
                    break;
                }
            }
            insercion.x= stof(pesosS);
            insercion.y=stoi(colorS);
            tipo=tipo;



            //inserción Quad
            long start_insert_Quad =
                    std::chrono::duration_cast< std::chrono::nanoseconds >(
                            std::chrono::system_clock::now( ).time_since_epoch( )
                    ).count( );
            quad->insertar(insercion,tipo);
            long end_insert_Quad =
                    std::chrono::duration_cast< std::chrono::nanoseconds >(
                            std::chrono::system_clock::now( ).time_since_epoch( )
                    ).count( );
            salidaInsertar<<end_insert_Quad - start_insert_Quad<<" ";
            //insercion kd
            long start_insert_KD =
                    std::chrono::duration_cast< std::chrono::nanoseconds >(
                            std::chrono::system_clock::now( ).time_since_epoch( )
                    ).count( );
            kd->insertar(insercion,tipo);//std::cout<<"SALE"<<std::endl;
            long end_insert_KD =
                    std::chrono::duration_cast< std::chrono::nanoseconds >(
                            std::chrono::system_clock::now( ).time_since_epoch( )
                    ).count( );
            salidaInsertar<<end_insert_KD - start_insert_KD<<std::endl;

            /*
             * Las fucniones de busqueda reciben los datos del archivo, pero pueden recibir cualquier dupla (x,y) y retornar la fruta de mayor similitud
             */

            //búsqueda quad
            std::string frutaEncontradaQuad;
            long start_search_Quad =
                    std::chrono::duration_cast< std::chrono::nanoseconds >(
                            std::chrono::system_clock::now( ).time_since_epoch( )
                    ).count( );
            frutaEncontradaQuad=quad->busquedaEuclidiana(insercion);
            std::cout<<frutaEncontradaQuad<<std::endl;
            long end_search_Quad =
                    std::chrono::duration_cast< std::chrono::nanoseconds >(
                            std::chrono::system_clock::now( ).time_since_epoch( )
                    ).count( );
            salidaBuscar<<end_search_Quad - start_search_Quad<<" ";

            std::string frutaEncontrada;
            //búsqueda kd
            long start_search_KD =
                    std::chrono::duration_cast< std::chrono::nanoseconds >(
                            std::chrono::system_clock::now( ).time_since_epoch( )
                    ).count( );
            frutaEncontrada=kd->busquedaEuclidiana(insercion);
            std::cout<<frutaEncontrada<<std::endl;
            long end_search_KD =
                    std::chrono::duration_cast< std::chrono::nanoseconds >(
                            std::chrono::system_clock::now( ).time_since_epoch( )
                    ).count( );
            salidaBuscar<<end_search_KD - start_search_KD<<std::endl;
            std::cout<<cont<<" "<<insercion.x<<" "<<insercion.y<<std::endl;
        }
        entrada.close();
    }else{
        std::cout<<"Error al abrir el archivo"<<std::endl;
    }
    salidaInsertar.close();
    salidaBuscar.close();
    std::cout<<"\nINORDER quad: "<<std::endl;
    quad->inOrden();
    std::cout<<"\nINORDER KD: "<<std::endl;
    kd->inOrden(kd->obtenerRaiz());




/*
    punto pt1;
    pt1.x=95.2;
    pt1.y=15;

    pt1.x=22.33;
    pt1.y=11;
    arbol->insertar(pt1,"criolla");
    pt1.x=123.45;
    pt1.y=16;
    arbol->insertar(pt1,"tomate");
    pt1.x=342.2;
    pt1.y=9;
    arbol->insertar(pt1,"pepino");
    pt1.x=285;
    pt1.y=8;
    arbol->insertar(pt1,"pepino");

    pt1.x=123.45;
    pt1.y=16;
    /*if(arbol->buscar(pt2)){
        std::cout<<"Encontrado"<<std::endl;
    }else{
        std::cout<<"No encontrado"<<std::endl;
    }
    arbol->inOrden(arbol->obtenerRaiz());
    std::cout<<"\nBusqueda: "<<arbol->busquedaEuclidiana(pt1)<<std::endl;*/

    return 0;
}
