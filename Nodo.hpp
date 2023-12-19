#pragma once
#include <iostream>
#include "Arista.hpp"
using namespace std;

class Nodo
{
private:
    int id;// id del usuario
    string nombre,tipo;// nombre del servidor + tipo (cliente o router)
    Arista* referencia;// este es el "peso" de la arista, la arista contiene sus propios atributos
public:
    Nodo(int id, string nombre,string tipo)
    {
        this->id=id;
        this->nombre=nombre;
        this->tipo=tipo;
        referencia=nullptr;
    }
    int getId(){return id;}
    string getNombre(){return nombre;}
    string getTipo(){return tipo;}
    Arista* getArista(){return referencia;}
    void setArista(Nodo*,int, int);
    ~Nodo();
};

void Nodo::setArista(Nodo* destino,int velocidad, int distancia){
    //Verificamos si el tipo del nodo actual es "Cliente"
    if (this->tipo=="Cliente") {
        //En el caso de que ya esté hecha la conexión, se retorna y termina la reciprocidad
        if(referencia!=nullptr && referencia->getDestino()==destino){
            return;
        }
        //Si ya hay una arista, la eliminamos antes de establecer la nueva conexión, de esta forma el cliente tiene una sola conexión
        if (referencia!=nullptr) {
            delete referencia;
        }
        //Asignamos la conexión con el router
        this->referencia= new Arista(destino, velocidad, distancia);
        //Aseguramos que el router tenga conexión con el cliente actual
        destino->setArista(this, velocidad, distancia);

    } else if (this->tipo=="Router") {
        //Si el tipo es "Router", puede tener más de una conexión
        this->referencia = new Arista(destino, velocidad, distancia);
        //Aseguramos que el cliente o router tambíen tenga una conexión con el nodo actual
        destino->setArista(this, velocidad, distancia);
    }
}