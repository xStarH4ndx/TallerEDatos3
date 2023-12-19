#pragma once
#include <iostream>
#include <vector>
#include "Nodo.hpp"
using namespace std;

class Edge : public Arista//Edge hereda metodos de la clase Arista, para poder obtener destino, velocidad y distancia, junto con sus respectivos metodos
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
