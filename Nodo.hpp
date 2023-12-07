#pragma once
#include <iostream>
using namespace std;
class Arista;

class Nodo
{
private:
    int id;
    string nombre,tipo;
    Arista* destino;
public:
    Nodo(int id, string nombre,string tipo)
    {
        this->id=id;
        this->nombre=nombre;
        this->tipo=tipo;
        destino=nullptr;
    }
    int getId(){return id;}
    string getNombre(){return nombre;}
    string getTipo(){return tipo;}
    Arista* getArista(){return destino;}
    void setArista(Arista* arista){this->destino=destino;}
    ~Nodo();
};

Nodo::~Nodo()
{
}
