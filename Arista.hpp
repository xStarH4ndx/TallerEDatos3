#pragma once
#include <iostream>
#include "Nodo.hpp"
using namespace std;

class Arista
{
private:
    Nodo* destino;
    int velocidad,distancia;
public:
    Arista(Nodo* destino, int velocidad, int distancia)
    {
        this->destino=destino;
        this->velocidad=velocidad;
        this->distancia=distancia;
    }
    Nodo* getDestino(){return destino;}
    int getVelocidad(){return velocidad;}
    int getDistancia(){return distancia;}
    void setDestino(Nodo* destino){this->destino=destino;}
    ~Arista();
};


Arista::~Arista()
{
}
