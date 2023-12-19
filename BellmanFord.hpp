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
    void rutaMasCorta(Nodo*partida,Nodo* llegada);
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
