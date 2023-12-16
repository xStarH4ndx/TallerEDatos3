#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Nodo.hpp"
#include "BellmanFord.hpp"
using namespace std;



int main(){

    vector<Nodo*> servidores;
    ifstream archivo;
    archivo.open("servidores.csv");

    if (!archivo.is_open()) cout << "Error al abrir el archivo." << endl;
    else 
    {
        string linea;
        while (getline(archivo, linea)) 
        {
            istringstream ss(linea);
            string id,servidor,tipo;

            getline(ss, id, ',');
            getline(ss, servidor, ',');
            getline(ss, tipo, ',');
            Nodo* nodo = new Nodo(stoi(id),servidor,tipo);
            servidores.push_back(nodo);
        }

        archivo.close();
    }

    ifstream archivo2;
    archivo.open("conexiones.csv");

    if (!archivo.is_open()) cout << "Error al abrir el archivo." << endl;
    else 
    {
        string linea;
        while (getline(archivo, linea)) 
        {
            istringstream ss(linea);
            string idCliente,idServidor,velocidad,distancia;

            getline(ss, idCliente, ',');
            getline(ss, idServidor, ',');
            getline(ss, velocidad, ',');
            getline(ss, distancia, ',');
            Nodo* cliente,* servidor;
            for(Nodo* nodo:servidores)
            {
                if(nodo->getId()==stoi(idCliente))cliente=nodo;
                if(nodo->getId()==stoi(idServidor))servidor=nodo;
            }
            cliente->setArista(servidor,stoi(velocidad),stoi(distancia));
        }

        archivo.close();
    }
    BellmanFord* grafo = new BellmanFord(servidores);
    return 0;
}