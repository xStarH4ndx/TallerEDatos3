#pragma once
#include <iostream>
#include <vector>
#include "Arista.hpp"
using namespace std;

class Nodo
{
private:
    int id;// id del usuario
    string nombre,tipo;// nombre del servidor + tipo (cliente o router)
    vector<Arista*>aristas;// si es cliente, tendrá 1 arista bidireccional, si es router, tendrá más de 1
public:
    Nodo(int id, string nombre,string tipo)
    {
        this->id=id;
        this->nombre=nombre;
        this->tipo=tipo;
    }
    int getId(){return id;}
    string getNombre(){return nombre;}
    string getTipo(){return tipo;}
    const vector<Arista*>& getAristas() const{return aristas;}
    void agregarArista(Nodo* destino, int velocidad, int distancia);
    void HacerConexion(Nodo*,int, int);
    ~Nodo();
};

Nodo::~Nodo(){};

void Nodo::agregarArista(Nodo* destino, int velocidad, int distancia){
    Arista* nuevaArista = new Arista(destino, velocidad, distancia);
    aristas.push_back(nuevaArista);
}

/* EXPLICACIÓN:
Si el nodo es un "cliente", verifica y establece una nueva conexión con el nodo destino, asegurando 
la bidireccionalidad. Para nodos "router", el proceso es similar, permitiendo conexiones bidireccionales 
con otros nodos.
*/
void Nodo::HacerConexion(Nodo* destino,int velocidad, int distancia){
    if (this->tipo=="cliente"){
        //En el caso de que ya esté hecha la conexión, se retorna y termina la recursividad
        for(Arista* arista : aristas){
            if(arista->getDestino()==destino){
                return;
            }
        }
        
        //Se establece la conexión con el router
        this->agregarArista(destino, velocidad, distancia);

        //En el caso de que router ya tenga conexión con el cliente, se retorna
        for(Arista* referencia : destino->getAristas()){
            if(referencia->getDestino()==this){
                return;
            }
        }
        //Si router no tiene conexion, se le agrega
        destino->HacerConexion(this,velocidad,distancia);

    }else if (this->tipo=="router") {
        //Se revisa las conexiones que tiene el router hasta encontrar la que se busca
        for(Arista* arista : aristas){
            if(arista->getDestino()==destino){
                return;
            }
        }
        //En el caso de que la encuentre, se retorna, de lo contrario, se le añade
        this->agregarArista(destino,velocidad,distancia);

        //En el caso de que el nodo "destino" tenga una conexión ya hecha con el router, se retorna
        for(Arista* referencia: destino->getAristas()){
            if(referencia->getDestino()==this){
                return;
            }
        }
        //En el caso de que no tenga conexión, se vuelve a llamar 
        destino->HacerConexion(this,velocidad,distancia);
    }
}