#pragma once
#include <iostream>
#include <vector>
#include "Nodo.hpp"
using namespace std;

class Edge : public Arista
{
private:
    Nodo* partida;
public:
    Edge(Nodo* partida,Nodo* destino,int velocidad,int distancia): Arista(destino, velocidad, distancia)
    {
        this->partida=partida;
    }
    
    Nodo* getNodoPartida(){return this->partida;}
    ~Edge();
};


Edge::~Edge()
{
}
