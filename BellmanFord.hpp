#pragma once
#include <iostream>
#include <vector>
#include "Nodo.hpp"
#include "Edge.hpp"
using namespace std;

class BellmanFord
{
private:
    vector<Nodo*> servidores;
    vector<Edge*> conexiones;
public:
    BellmanFord(vector<Nodo*> servidores, vector<Edge*> conexiones)
    {
        this->servidores = servidores;
        this->conexiones = conexiones;
        this->crearGrafo(); // Llama a la función crearGrafo en el constructor
    };

    void crearGrafo(){
        //Creación del grafo (uniendo las conexiones)
        for (Edge* elemento : conexiones)
        {
            //Obtenemos el nodo de partida y llegada, conectamos a través de aristas
            Nodo* partida= elemento->getNodoPartida();
            Nodo* destino= elemento->getDestino();
            int velocidad= elemento->getVelocidad();
            int distancia= elemento->getDistancia();
            partida->HacerConexion(destino, velocidad, distancia);
        }
    }
    void rutaMasCorta(Nodo*partida,Nodo* destino);
    void testerRuta(Nodo*partida,Nodo* destino);
    ~BellmanFord();
};

//Esto es para liberar memoria
BellmanFord::~BellmanFord(){
    for(Nodo* nodo: servidores){
        delete nodo;
    }
    for(Edge* edge:conexiones){
        delete edge;
    }
}

void BellmanFord::testerRuta(Nodo*partida,Nodo*destino){
    if (partida == nullptr) {
        cout << "Error: Nodo de partida nulo." << endl;
        return;
    }
    for(Arista* arista : partida->getAristas()) {
        if(arista!=nullptr && arista->getDestino()!=nullptr) {
            if(arista->getDestino()->getTipo()=="cliente") {
                if(arista->getDestino()==destino) {
                    cout<<"Se ha encontrado el cliente: "<<arista->getDestino()->getId()<<endl;
                    return;
                }
            }
            testerRuta(arista->getDestino(),destino);
        }
    }
    cout<<"No se ha encontrado"<<endl;
}