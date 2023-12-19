#pragma once
#include <iostream>
#include <vector>
#include "Nodo.hpp"
using namespace std;

class BellmanFord
{
private:
    vector<Nodo*> servidores;
    vector<Edge*> conexiones;
public:
    BellmanFord(vector<Nodo*> servidores,vector<Edge*>conexiones)
    {
        this->servidores=servidores;
        this->conexiones=conexiones;
    }
    void rutaMasCorta(Nodo*partida,Nodo* llegada);
    
    ~BellmanFord();
};

