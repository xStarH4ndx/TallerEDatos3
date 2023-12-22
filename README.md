-----------------------------------------
#               TallerEDatos3
-----------------------------------------
Integrantes:
- Javier Saldaño
- Bruno Toro
-----------------------------------------
#           ESTRUCTURA DEL CODIGO
-----------------------------------------

1)Clase Arista:
- Esta clase modela una conexión entre nodos dentro del grafo. Cada arista está definida
por su nodo de destino, velocidad y distancia. Estos atributos pueden ser modificados
u obtenidos a través de sus metodos geters y seters.

2)Clase Nodo:
- Representa un vértice del grafo, que puede ser de tipo Cliente o Router. Cada nodo tiene un 
identificador único, un nombre y un tipo. Cliente puede tener una sola conexión con un router, 
la cual es bidireccional. Por otro lado, Router puede tener más de una conexión, entre clientes 
y más routers, todas bidireccionales.

- El metodo HacerConexion(Nodo* destino,int velocidad,int distancia) establece
una conexión bidireccional con otro nodo

3)Clase BellmanFord:
- Esta clase implementa el algoritmo de Bellman-Ford para encontrar la ruta más corta en el grafo.
Almacena una lista de Edges, la cual corresponde al conjunto de Nodos y la arista que los une.
Con el metodo de crearGrafo(), se construye el grafo, uniendo los nodos a través de aristas, con
su respectivo "peso" (velocidad y tiempo).

-----------------------------------------
#    IMPLEMENTACIÓN EN BELLMANFORD
-----------------------------------------
1)Funcion mostrarRuta(Nodo,Nodo,Nodo,int): Implementa la búsqueda de una ruta en el grafo utilizando recursividad.
Toma como parámetros un nodo de partida, un nodo destinom, y un nodo auxiliar, junto con un contador que se encarga de acumular los movimientos que se van realizando. La función recorre la lista de aristas salientes del nodo de partida, imprimiendo la información de la ruta recorrida. Además actualiza el contador para llevar un seguimiento de la cantidad de nodos tipo router visitados, excluyendo el nodo auxiliar. La función busca un nodo tipo "Cliente", cuando se encuentra, la función retorna true, en el caso contrario, la función continúa la exploración recursiva hacia nodos tipo "router". La función retorna false si no se encuentra la ruta hacia el cliente en el nodo destino o cualquier router intermedio. Este método proporciona información detallada sobre el camino recorrido, destacando la presencia de clientes y routers a lo largo de la ruta.