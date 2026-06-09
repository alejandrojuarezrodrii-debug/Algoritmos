#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 10005 // Máximo número de vértices
#define Node pair< int , int > // first: vértice adyacente, second: peso (tiempo en minutos)
#define INF 1<<30 // Infinito

// Comparador para convertir la cola de prioridad en un min-Heap
struct cmp {
    bool operator() ( const Node &a , const Node &b ) {
        return a.second > b.second;
    }
};

vector< Node > ady[ MAX ];                     // Lista de adyacencia
int distancia[ MAX ];                          // Almacena d(v) o d(u)
bool visitado[ MAX ];                          // Para marcar nodos permanentes
priority_queue< Node , vector<Node> , cmp > Q; // Cola de prioridad
int V = 10;                                    // 10 Estaciones de Metrobús
int previo[ MAX ];                             // Para reconstruir el camino

// Inicialización del algoritmo (Paso 1)
void init(){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  // Asigna infinito a todos los nodos
        visitado[ i ] = false; // Ninguno ha sido visitado
        previo[ i ] = -1;      // Sin predecesor inicial
    }
}

// Paso de relajación: d(v) = min(d(v), d(u) + w(u,v))
void relajacion( int actual , int adyacente , int peso ){
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  // Actualiza con el menor valor
        previo[ adyacente ] = actual;                         // Guarda el predecesor
        Q.push( Node( adyacente , distancia[ adyacente ] ) ); // Añade a la cola
    }
}

// Impresión recursiva del camino óptimo
void print( int destino ){
    if( previo[ destino ] != -1 )
        print( previo[ destino ] );
    printf("%d " , destino );
}

// Algoritmo de Dijkstra
void dijkstra( int inicial ){
    init(); 
    Q.push( Node( inicial , 0 ) ); // Origen con distancia 0
    distancia[ inicial ] = 0;      
    
    int actual , adyacente , peso;
    while( !Q.empty() ){          
        actual = Q.top().first;    // Extrae el nodo u con el d(u) mínimo
        Q.pop();                  
        
        if( visitado[ actual ] ) continue; 
        visitado[ actual ] = true; // Nodo permanente
        
        // Explora los vecinos v del nodo u
        for( size_t i = 0 ; i < ady[ actual ].size() ; ++i ){ 
            adyacente = ady[ actual ][ i ].first;   // Nodo v
            peso = ady[ actual ][ i ].second;       // w(u,v)
            if( !visitado[ adyacente ] ){        
                relajacion( actual , adyacente , peso ); 
            }
        }
    }

    // Muestra los resultados en consola
    printf( "\n--- TIEMPOS MÍNIMOS DESDE LA ESTACIÓN %d ---\n" , inicial );
    for( int i = 1 ; i <= V ; ++i ){
        if(distancia[i] == INF)
            printf("Estacion %d -> Inalcanzable\n", i);
        else
            printf("Estacion %d -> Tiempo minimo: %d min\n" , i , distancia[ i ] );
    }

    puts("\n**************** Impresion de Ruta ****************");
    printf("Ingrese la estacion destino (1-10): ");
    int destino;
    scanf("%d" , &destino );
    
    if(distancia[destino] == INF){
        printf("No hay ruta disponible.\n");
    } else {
        printf("Ruta mas rapida (ID de estaciones): ");
        print( destino );
        printf("\n\nTiempo total de traslado: %d minutos.\n", distancia[destino]);
    }
}

// Carga automática del grafo diseñado (Matriz/Lista)
void cargarGrafoMetrobus() {
    // Par ordenado: ady[origen].push_back(Node(destino, peso_minutos))
    // Al ser no dirigido (bidireccional), se añade de A a B y de B a A
    
    // L6: El Rosario (1) - Dep. 18 de Marzo (3) = 25 min
    ady[1].push_back(Node(3, 25)); ady[3].push_back(Node(1, 25));
    
    // L3: Juárez (2) - Hidalgo (5) = 4 min
    ady[2].push_back(Node(5, 4));  ady[5].push_back(Node(2, 4));
    
    // L6: Dep. 18 de Marzo (3) - San Juan de Aragón (4) = 12 min
    ady[3].push_back(Node(4, 12)); ady[4].push_back(Node(3, 12));
    
    // L1: Dep. 18 de Marzo (3) - Hidalgo (5) = 15 min
    ady[3].push_back(Node(5, 15)); ady[5].push_back(Node(3, 15));
    
    // L5: San Juan de Aragón (4) - Coyuya (7) = 30 min
    ady[4].push_back(Node(7, 30)); ady[7].push_back(Node(4, 30));
    
    // L1: Hidalgo (5) - Nuevo León (6) = 18 min
    ady[5].push_back(Node(6, 18)); ady[6].push_back(Node(5, 18));
    
    // L2: Nuevo León (6) - Coyuya (7) = 22 min
    ady[6].push_back(Node(7, 22)); ady[7].push_back(Node(6, 22));
    
    // L1: Nuevo León (6) - Villa Olímpica (8) = 32 min
    ady[6].push_back(Node(8, 32)); ady[8].push_back(Node(6, 32));
    
    // L5: Coyuya (7) - Las Bombas (9) = 25 min
    ady[7].push_back(Node(9, 25)); ady[9].push_back(Node(7, 25));
    
    // L2: Coyuya (7) - UPIICSA (10) = 8 min
    ady[7].push_back(Node(10, 8)); ady[10].push_back(Node(7, 8));
}

int main(){
    // Cargamos los datos preestablecidos del ejercicio del Metrobús
    cargarGrafoMetrobus();
    
    printf("Estaciones cargadas: 10\n");
    printf("1. Rosario            2. Juarez         3. Dep. 18 de Marzo   4. S.J. de Aragon\n");
    printf("5. Hidalgo            6. Nuevo Leon     7. Coyuya             8. Villa Olimpica\n");
    printf("9. Las Bombas         10. UPIICSA\n\n");
    
    printf("Ingrese la estacion inicial (1-10): ");
    int inicial;
    scanf("%d" , &inicial );
    
    if(inicial >= 1 && inicial <= 10) {
        dijkstra( inicial );
    } else {
        printf("ID de estacion no valido.\n");
    }
    
    return 0;
}
