#pragma once
#include <iostream>
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

void Nodo::agregarArista(Nodo* destino, int velocidad, int distancia){
    Arista* nuevaArista = new Arista(destino, velocidad, distancia);
    aristas.push_back(nuevaArista);
}

/* EXPLICACIÓN:
Si el nodo es un "CLiente", verifica si ya existe una conexión con el destino antes de 
agregar una nueva arista. Si ya hay una arista, la elimina antes de establecer la nueva 
conexión. Luego, agrega la nueva arista y asegura que el nodo destino 
también tenga una conexión de vuelta.

Si el nodo es un "Router", realiza una verificación similar y agrega la nueva arista.
Asegura que el nodo destino también tenga una conexión de vuelta.
*/
void Nodo::HacerConexion(Nodo* destino,int velocidad, int distancia){
    if (this->tipo=="Cliente"){
        //En el caso de que ya esté hecha la conexión, se retorna y termina la recursividad
        for(Arista* arista : aristas){
            if(arista->getDestino()==destino){
                return;
            }
        }
        
        // Asignamos la conexión con el router
        this->agregarArista(destino, velocidad, distancia);

        for(Arista* referencia : destino->getAristas()){
            if(referencia->getDestino()==this){
                return;
            }
        }
        // Aseguramos que el router tenga conexión con el cliente actual
        destino->HacerConexion(this,velocidad,distancia);

    }else if (this->tipo=="Router") {
        for(Arista* arista : aristas){
            if(arista->getDestino()==destino){
                return;
            }
        }
        this->agregarArista(destino,velocidad,distancia);

        for(Arista* referencia: destino->getAristas()){
            if(referencia->getDestino()==this){
                return;
            }
        }
        destino->HacerConexion(this,velocidad,distancia);
    }
}