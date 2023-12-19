#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Nodo.hpp"
#include "BellmanFord.hpp"
#include "Edge.hpp"
using namespace std;


//Función para leer archivo de servidores y crear una lista de nodos (cliente y router)
vector<Nodo*> leerArchivoServidores(const string& nombreArchivo) {
    vector<Nodo*> nodos;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
    } else {
        string linea;
        while (getline(archivo, linea)) {
            istringstream ss(linea);
            string id, servidor, tipo;

            getline(ss, id, ',');
            getline(ss, servidor, ',');
            getline(ss, tipo, ',');
            Nodo* nodo = new Nodo(stoi(id), servidor, tipo);
            nodos.push_back(nodo); //Lista con los nodos
        }
        archivo.close();
    }
    return nodos;
}

//Funcion para crear una lista de Edges, para fabricar el grafo despues
vector<Edge*> leerArchivoConexiones(const string& nombreArchivo, const vector<Nodo*>& nodos) {
    vector<Edge*> conexiones;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
    } else {
        string linea;
        while (getline(archivo, linea)) {
            istringstream ss(linea);
            string idCliente, idServidor, velocidad, distancia;

            getline(ss, idCliente, ',');
            getline(ss, idServidor, ',');
            getline(ss, velocidad, ',');
            getline(ss, distancia, ',');

            Nodo* cliente = nullptr;
            Nodo* servidor = nullptr;
            for (Nodo* nodo : nodos) {
                if (nodo->getId() == stoi(idCliente)) cliente = nodo;
                if (nodo->getId() == stoi(idServidor)) servidor = nodo;
            }

            Edge* conexion = new Edge(cliente, servidor, stoi(velocidad), stoi(distancia));
            conexiones.push_back(conexion);
            cliente->setArista(servidor, stoi(velocidad), stoi(distancia));
        }
        archivo.close();
    }
    return conexiones;
}

int main(){
    vector<Nodo*> servidores = leerArchivoServidores("servidores.csv");
    vector<Nodo*> servidoresConConexion = servidores; //Haciendo una copia para tener los nodos antes de conectar
    vector<Edge*> conexiones = leerArchivoConexiones("conexiones.csv", servidoresConConexion);


    //esto se puede implementar en el grafo para crearlo
    for(Edge* elemento: conexiones){
        //obtenemos el nodo de partida y llegada
        Nodo* partida= elemento->getNodoPartida();
        Nodo* destino= elemento->getDestino();
        

       // partida->setArista(destino,)



    }

    BellmanFord* grafo = new BellmanFord(servidores,conexiones);
    return 0;

}