#pragma once
#include <iostream>
class Nodo;
using namespace std;

class Arista
{
private:
    Nodo* destino;// corresponde al clinete (id usuario + nombre servidor + tipo)
    int velocidad,distancia;// corresponde al "peso" de la arista y los segundos que tarda
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

