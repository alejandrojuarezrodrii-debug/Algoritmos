#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>

// Usamos la directiva standard para evitar escribir std:: en todo el código
using namespace std;

// ==================================================
// ESTADO ORIGINAL DEL CÓDIGO (Estructura del Nodo)
// ==================================================
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
    // Constructor adaptado para máxima compatibilidad (usando NULL en vez de nullptr si fuera necesario)
    Nodo(int val) {
        dato = val;
        izquierdo = NULL;
        derecho = NULL;
    }
};

// Función para insertar nodos en el árbol binario de búsqueda
Nodo* insertar(Nodo* raiz, int dato) {
    if (raiz == NULL) {
        return new Nodo(dato);
    }
    if (dato < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, dato);
    } else {
        raiz->derecho = insertar(raiz->derecho, dato);
    }
    return raiz;
}

// Función para calcular las distancias de las hojas (Experimento)
void encontrarNivelesHojas(Nodo* raiz, int nivelActual, int& nivelMin, int& nivelMax) {
    if (raiz == NULL) return;

    if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
        if (nivelActual < nivelMin) nivelMin = nivelActual;
        if (nivelActual > nivelMax) nivelMax = nivelActual;
        return;
    }

    encontrarNivelesHojas(raiz->izquierdo, nivelActual + 1, nivelMin, nivelMax);
    encontrarNivelesHojas(raiz->derecho, nivelActual + 1, nivelMin, nivelMax);
}

// Destructor recursivo para liberar memoria RAM
void liberarArbol(Nodo* raiz) {
    if (raiz == NULL) return;
    liberarArbol(raiz->izquierdo);
    liberarArbol(raiz->derecho);
    delete raiz;
}

// ==================================================
// FUNCIONES DE RECORRIDO (Preorden, Entreorden y Postorden)
// ==================================================

void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izquierdo);
    cout << raiz->dato << " ";
    inorden(raiz->derecho);
}

void preorden(Nodo* raiz) {
    if (raiz == NULL) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierdo);
    preorden(raiz->derecho);
}

void postorden(Nodo* raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izquierdo);
    postorden(raiz->derecho);
    cout << raiz->dato << " ";
}

// ==================================================
// PROGRAMA PRINCIPAL
// ==================================================
int main() {
    // Inicializar semilla de números aleatorios
    srand(time(NULL));

    // --------------------------------------------------
    // DEMOSTRACIÓN DE RECORRIDOS (Árbol temporal de prueba)
    // --------------------------------------------------
    cout << "==================================================\n";
    cout << " DEMOSTRACION DE RECORRIDOS (Arbol de ejemplo)\n";
    cout << "==================================================\n";
    
    Nodo* arbolPrueba = NULL;
    
    // Arreglo e inserción tradicional para asegurar compatibilidad en Dev-C++
    int valoresPrueba[] = {50, 30, 70, 20, 40, 60, 80};
    for(int i = 0; i < 7; i++) {
        arbolPrueba = insertar(arbolPrueba, valoresPrueba[i]);
    }

    cout << "Nodos insertados en orden: 50, 30, 70, 20, 40, 60, 80\n\n";

    cout << "-> Recorrido Inorden:   "; inorden(arbolPrueba);   cout << "\n";
    cout << "-> Recorrido Preorden:  "; preorden(arbolPrueba);  cout << "\n";
    cout << "-> Recorrido Postorden: "; postorden(arbolPrueba); cout << "\n";
    
    liberarArbol(arbolPrueba);
    cout << "==================================================\n\n";


    // --------------------------------------------------
    // EXPERIMENTO ORIGINAL (50 repeticiones con 100 números)
    // --------------------------------------------------
    const int TOTAL_NUMEROS = 100;
    const int EXPERIMENTOS = 50;
    map<int, int> frecuenciasDiferencias;

    cout << "Ejecutando el experimento 50 veces...\n";
    cout << "--------------------------------------------------\n";
    cout << "Exp.\tNivel Min\tNivel Max\tDiferencia\n";
    cout << "--------------------------------------------------\n";

    for (int i = 1; i <= EXPERIMENTOS; ++i) {
        Nodo* raiz = NULL;

        for (int j = 0; j < TOTAL_NUMEROS; ++j) {
            int numAleatorio = rand() % 1000; 
            raiz = insertar(raiz, numAleatorio);
        }

        int nivelMinimo = 999999; // Cambiado por un entero alto compatible
        int nivelMaximo = -1;  

        encontrarNivelesHojas(raiz, 0, nivelMinimo, nivelMaximo);

        int diferencia = nivelMaximo - nivelMinimo;
        frecuenciasDiferencias[diferencia]++;

        cout << i << "\t" << nivelMinimo << "\t\t" << nivelMaximo << "\t\t" << diferencia << "\n";

        liberarArbol(raiz);
    }

    // --------------------------------------------------
    // TABLA DE FRECUENCIAS (Modificada para Dev-C++)
    // --------------------------------------------------
    cout << "\n==================================================\n";
    cout << " TABLA DE FRECUENCIAS (Diferencias de Menor a Mayor)\n";
    cout << "==================================================\n";
    cout << "Diferencia (Max - Min)\tFrecuencia (Veces obtenida)\n";
    cout << "--------------------------------------------------\n";

    // Modificación Crítica: Usamos un iterador tradicional de map compatible con cualquier versión de C++
    map<int, int>::iterator it;
    for (it = frecuenciasDiferencias.begin(); it != frecuenciasDiferencias.end(); ++it) {
        // it->first es la diferencia, it->second son las repeticiones
        cout << "\t" << it->first << "\t\t\t" << it->second << "\n";
    }
    cout << "--------------------------------------------------\n";

    return 0;
}
