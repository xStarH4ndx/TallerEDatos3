#pragma once
#include <iostream>
#include <vector>
#include <cmath>
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
    bool mostrarRuta(Nodo*partida,Nodo* destino,Nodo*aux,int,int,int);
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

int calcularVelocidadConexion(int pesoMensaje,int velocidad, int distancia)
{
    if(pesoMensaje <= velocidad) return pesoMensaje*distancia;
    else
    {
        int partes = static_cast<int>(floor(velocidad/pesoMensaje))+1;
        int cant;
        for (int i = 0; i < partes; i++)
        {
            cant+= pesoMensaje*distancia;
        }
        return cant;
        
    }
}

bool BellmanFord::mostrarRuta(Nodo* partida, Nodo* destino, Nodo* aux,int caminos,int megas,int velocidadConexion) 
{
    for(Arista* arista : partida->getAristas()) {
        //camino recorrido
        //cout<<partida->getTipo()<<partida->getId()<<" a "<<arista->getDestino()->getTipo()<<arista->getDestino()->getId()<<endl;
       
        if(arista->getDestino()->getTipo()=="router" && arista->getDestino()!=aux || arista->getDestino()==destino)
        {
            cout<<partida->getTipo()<<partida->getId()<<" a "<<arista->getDestino()->getTipo()<<arista->getDestino()->getId()<<endl;
            caminos++;
            cout<<caminos<<endl;
            velocidadConexion += calcularVelocidadConexion(megas,arista->getVelocidad(),arista->getDistancia());
        }
        
        //Muy importante no considerar el cliente de donde venimos
        if(arista->getDestino()->getTipo()=="cliente" && arista->getDestino()==destino) {
            cout<<"Se ha encontrado el cliente: "<<arista->getDestino()->getId()<< endl;
            cout<<"El peso total que ha generado este archivo es de: "<<velocidadConexion<<" megas"<<endl;
            //Se encontró el cliente, se retorna
            return true;
        }else if(arista->getDestino()->getTipo()=="router" && arista->getDestino()!=aux) {
            //Muy importante no considerar el router de donde vinimos
            if(mostrarRuta(arista->getDestino(),destino,partida,caminos,megas,velocidadConexion)) {
                //Cliente encontrado, dejamos de recorrer
                return true;
            }
            else
            {
                velocidadConexion -= calcularVelocidadConexion(megas,arista->getVelocidad(),arista->getDistancia());
                caminos--;
            }
            
        }
    }
    //No se encontró el cliente en el router
    cout<<"No se ha encontrado"<<endl;
    return false;
}

