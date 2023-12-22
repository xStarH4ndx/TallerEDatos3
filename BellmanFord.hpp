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
    bool testerRuta(Nodo*partida,Nodo* destino,Nodo*aux,int);
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

bool BellmanFord::testerRuta(Nodo* partida, Nodo* destino, Nodo* aux,int total) {
    for(Arista* arista : partida->getAristas()) {
        //camino recorrido
        cout<<partida->getTipo()<<partida->getId()<<" a "<<arista->getDestino()->getTipo()<<arista->getDestino()->getId()<<endl;
       
        //if(arista->getDestino()!=aux){total++;}
        cout<<total<<endl;
        //Muy importante no considerar el cliente de donde venimos
        if(arista->getDestino()->getTipo()=="cliente" && arista->getDestino()==destino) {
            cout<<"Se ha encontrado el cliente: "<<arista->getDestino()->getId()<< endl;
            //Se encontró el cliente, se retorna
            return true;
        }else if(arista->getDestino()->getTipo()=="router" && arista->getDestino()!=aux) {
            //Muy importante no considerar el router de donde vinimos
            if(testerRuta(arista->getDestino(),destino,partida,total++)) {
                //Cliente encontrado, dejamos de recorrer
                return true;
            }
        }
    }
    //No se encontró el cliente en el router
    cout<<"No se ha encontrado"<<endl;
    return false;
}

