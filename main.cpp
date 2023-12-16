#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Nodo.hpp"
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

    return 0;
}