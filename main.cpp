#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Nodo.hpp"
#include "BellmanFord.hpp"
#include "Edge.hpp"
using namespace std;



int main(){

    vector<Nodo*> servidoresConConexion;
    vector<Nodo*> servidores;
    vector<Edge*> conexiones;

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
            
            servidores.push_back(nodo);//Lista con los nodos sin conectar
            
            servidoresConConexion.push_back(nodo);//Lista con los nodos antes de conectar
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
            for(Nodo* nodo:servidoresConConexion)
            {
                if(nodo->getId()==stoi(idCliente))cliente=nodo;
                if(nodo->getId()==stoi(idServidor))servidor=nodo;
            }
            Edge* conexion = new Edge(cliente,servidor,stoi(velocidad),stoi(distancia));
            conexiones.push_back(conexion);//Lista de las conexiones utilizando la clase edge

            cliente->setArista(servidor,stoi(velocidad),stoi(distancia));//Estan los nodos con las conexiones listas por medio de la clase arista
        }

        archivo.close();
    }
    BellmanFord* grafo = new BellmanFord(servidores,conexiones);
    return 0;
}