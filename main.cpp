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
        }
        archivo.close();
    }
    return conexiones;
}


Nodo* menu(const vector<Nodo*>&nodos){
    int id;bool encontrado=false;
    cout<<"Ingrese ID: ";
    cin>>id;
    Nodo*cliente=nullptr;//Cliente
    while(!encontrado){
        for(Nodo*nodo:nodos){
            if(nodo->getTipo()=="cliente" && nodo->getId()==id){
                cout<<"ID verificado"<<endl;
                cliente=nodo;
                encontrado=true;
                break;
            }
        }
        if(!encontrado){
            cout<<"Ingrese ID valido: ";
            cin>>id;
        }
    }
    return cliente;
}

int cantMegas()
{
    int opcion;
    do
    {
        cout<<"Ingrese el tipo de archivo:"<<endl;
        cout<<" "<<endl;
        cout<<"1) Imagen"<<endl;
        cout<<"2) Video"<<endl;
        cout<<"3) PDF "<<endl;cin>>opcion;
        switch (opcion)
        {
        case 1:
            return 300;
            break;
        case 2:
            return 900;
            break;
        case 3:
            return 600;
            break;        
        default:
            cout<<"Ingrese una opción válida valido";
            break;
        }
    } while (opcion==0);
    return 0;
}

int main(){
    //PROBANDO CON TXT EDITADO
    vector<Nodo*> servidores = leerArchivoServidores("servidores.csv");
    vector<Nodo*> servidoresConConexion = servidores; //Haciendo una copia para tener los nodos antes de conectar (no se si es necesario, lo tenemos como idea por si las moscas)
    vector<Edge*> conexiones = leerArchivoConexiones("conexiones.csv", servidoresConConexion);

    //Creación del grafo (uniendo las conexiones)
    BellmanFord grafo(servidores, conexiones);

    cout<<"----Emisor----"<<endl;
    Nodo*partida=menu(servidores);
    cout<<"----RECEPTOR----"<<endl;
    Nodo*destino=menu(servidores);
    Nodo* aux=partida;
    cout<<"---RECORRIDO---"<<endl;
    int megas = cantMegas();
    grafo.mostrarRuta(partida,destino,aux,0,megas,0);//1 corresponde al movimiento inicial, del cliente al router inicial
    return 0;
}