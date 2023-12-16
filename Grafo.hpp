#pragma once
#include <iostream>
#include <vector>
#include "Nodo.hpp"
using namespace std;

class Grafo
{
private:
    vector<Nodo*> servidores;
public:
    Grafo(vector<Nodo*> servidores)
    {
        this->servidores=servidores;
    }
    
    ~Grafo();
};
