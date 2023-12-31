#pragma once
#include <iostream>
class Nodo;
using namespace std;

class Arista
{
private:
    Nodo* destino;// corresponde a la conexion de cliente-router o router-router
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
    void setVelocidad(int velocidad){this->velocidad=velocidad;}
    void setDistancia(int distancia){this->distancia=distancia;}
    ~Arista();
};

Arista::~Arista(){}