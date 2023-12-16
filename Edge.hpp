#pragma once
#include <iostream>
#include <vector>
#include "Nodo.hpp"
using namespace std;
class Edge
{
private:
    Nodo* partida, *llegada;
    int velocidad,distancia;

public:
    Edge(Nodo* partida,Nodo* llegada,int velocidad,int distancia)
    {
        this->partida=partida;
        this->llegada=llegada;
        this->velocidad=velocidad;
        this->distancia=distancia;
    }
    ~Edge();
};


Edge::~Edge()
{
}
