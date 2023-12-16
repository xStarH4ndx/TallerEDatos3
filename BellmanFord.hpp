#pragma once
#include <iostream>
#include <vector>
#include "Nodo.hpp"
using namespace std;

class BellmanFord
{
private:
    vector<Nodo*> servidores;
public:
    BellmanFord(vector<Nodo*> servidores)
    {
        this->servidores=servidores;
    }
    void rutaMasCorta(Nodo*partida,Nodo* llegada);
    
    ~BellmanFord();
};
