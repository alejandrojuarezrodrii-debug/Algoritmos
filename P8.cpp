#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

using namespace std;

class ArbolBinario {
private:
    class Nodo {
    public:
        int info;
        Nodo *izq;
        Nodo *der;
    };
    Nodo *raiz;
    void borrar(Nodo *reco);
    void imprimirPre(Nodo *reco);
    void imprimirEntre(Nodo *reco);
    void imprimirPost(Nodo *reco);
    bool buscar(Nodo *reco, int valor);

public:
    ArbolBinario();
    ~ArbolBinario();
    void insertar(int x);
    void imprimirPre();
    void imprimirEntre();
    void imprimirPost();
    void buscarValor(int valor);
};

ArbolBinario::ArbolBinario() {
    raiz = NULL;
}

ArbolBinario::~ArbolBinario() {
    borrar(raiz);
}

void ArbolBinario::borrar(Nodo *reco) {
    if (reco != NULL) {
        borrar(reco->izq);
        borrar(reco->der);
        delete reco;
    }
}

// Inserción bajo la regla de Árbol de Búsqueda
void ArbolBinario::insertar(int x) {
    Nodo *nuevo = new Nodo{x, NULL, NULL};
    if (raiz == NULL) {
        raiz = nuevo;
    } else {
        Nodo *anterior = NULL;
        Nodo *reco = raiz;
        while (reco != NULL) {
            anterior = reco;
            if (x < reco->info)
                reco = reco->izq;
            else
                reco = reco->der;
        }
        if (x < anterior->info)
            anterior->izq = nuevo;
        else
            anterior->der = nuevo;
    }
}

// Lógica de Búsqueda Recursiva
bool ArbolBinario::buscar(Nodo *reco, int valor) {
    if (reco == NULL) return false;
    if (reco->info == valor) return true;
    
    if (valor < reco->info)
        return buscar(reco->izq, valor);
    else
        return buscar(reco->der, valor);
}

void ArbolBinario::buscarValor(int valor) {
    if (buscar(raiz, valor))
        cout << "El valor " << valor << " SI se encuentra en el arbol.\n";
    else
        cout << "El valor " << valor << " NO se encuentra en el arbol.\n";
}

// Métodos de Recorrido
void ArbolBinario::imprimirPre() { imprimirPre(raiz); cout << "\n"; }
void ArbolBinario::imprimirPre(Nodo *reco) {
    if (reco != NULL) {
        cout << reco->info << " ";
        imprimirPre(reco->izq);
        imprimirPre(reco->der);
    }
}

void ArbolBinario::imprimirEntre() { imprimirEntre(raiz); cout << "\n"; }
void ArbolBinario::imprimirEntre(Nodo *reco) {
    if (reco != NULL) {
        imprimirEntre(reco->izq);
        cout << reco->info << " ";
        imprimirEntre(reco->der);
    }
}

void ArbolBinario::imprimirPost() { imprimirPost(raiz); cout << "\n"; }
void ArbolBinario::imprimirPost(Nodo *reco) {
    if (reco != NULL) {
        imprimirPost(reco->izq);
        imprimirPost(reco->der);
        cout << reco->info << " ";
    }
}

int main() {
    // Inicializar semilla aleatoria basada en el tiempo actual
    srand(time(NULL));
    
    ArbolBinario *arbol = new ArbolBinario();
    
    cout << "--- Insertando 10 numeros aleatorios ---\nNodos generados: ";
    int numeroBuscar = 0;
    
    for (int i = 0; i < 10; i++) {
        int numRandom = rand() % 100 + 1; // Números entre 1 y 100
        cout << numRandom << " ";
        arbol->insertar(numRandom);
        if (i == 5) numeroBuscar = numRandom; // Guardamos uno para la prueba de búsqueda
    }
    cout << "\n\n";
    
    cout << "Recorrido Preorden:   "; arbol->imprimirPre();
    cout << "Recorrido Entreorden: "; arbol->imprimirEntre();
    cout << "Recorrido Postorden:  "; arbol->imprimirPost();
    cout << "\n";
    
    // Prueba de búsqueda
    cout << "--- Prueba de Busqueda ---\n";
    arbol->buscarValor(numeroBuscar); // Debe dar SI
    arbol->buscarValor(999);          // Debe dar NO
    
    delete arbol;
    return 0;
}
