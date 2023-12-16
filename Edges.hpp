#pragma once
#include <iostream>
#include <vector>
#include "Nodo.hpp"
using namespace std;
class Edges
{
private:
    Nodo* partida, *llegada;
    int velocidad,distancia;

public:
    Edges(Nodo* partida,Nodo* llegada,int velocidad,int distancia)
    {
        this->partida=partida;
        this->llegada=llegada;
        this->velocidad=velocidad;
        this->distancia=distancia;
    }
    ~Edges();
};


Edges::~Edges()
{
}
