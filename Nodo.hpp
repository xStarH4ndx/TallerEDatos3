#pragma once
#include <iostream>
#include "Arista.hpp"
using namespace std;

class Nodo
{
private:
    int id;// id del usuario
    string nombre,tipo;// nombre del servidor + tipo (cliente o router)
    Arista* referencia;// este es el "peso" de la arista, la arista contiene sus propios atributos
public:
    Nodo(int id, string nombre,string tipo)
    {
        this->id=id;
        this->nombre=nombre;
        this->tipo=tipo;
        referencia=nullptr;
    }
    int getId(){return id;}
    string getNombre(){return nombre;}
    string getTipo(){return tipo;}
    Arista* getArista(){return referencia;}
    void setArista(Nodo*,int, int);
    ~Nodo();
};

void Nodo::setArista(Nodo* destino,int velocidad, int distancia)
{
    {
        this->referencia= new Arista(destino,velocidad,distancia);
    }
}