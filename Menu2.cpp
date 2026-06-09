#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función auxiliar para imprimir el arreglo
void imprimir(vector<int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// --- ALGORITMOS DE ORDENAMIENTO ---

void burbuja(vector<int>& a) {
    cout << "\n--- Burbuja ---\n";
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
    imprimir(a);
}

void seleccionDirecta(vector<int>& a) {
    cout << "\n--- Seleccion Directa ---\n";
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
    }
    imprimir(a);
}

void insercionDirecta(vector<int>& a) {
    cout << "\n--- Insercion Directa ---\n";
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int aux = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > aux) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = aux;
    }
    imprimir(a);
}

void shellSort(vector<int>& a) {
    cout << "\n--- Shell Sort ---\n";
    int n = a.size();
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = a[i], j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
        gap /= 2;
    }
    imprimir(a);
}

void quick(vector<int>& a, int ini, int fin) {
    int i = ini, j = fin;
    int piv = a[(ini + fin) / 2];
    while (i <= j) {
        while (a[i] < piv) i++;
        while (a[j] > piv) j--;
        if (i <= j) { swap(a[i], a[j]); i++; j--; }
    }
    if (ini < j) quick(a, ini, j);
    if (i < fin) quick(a, i, fin);
}

// --- ALGORITMOS DE BÚSQUEDA ---

void busquedaSecuencial(const vector<int>& a, int valor) {
    cout << "\n--- Busqueda Secuencial ---\n";
    bool encontrado = false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == valor) {
            cout << "Elemento " << valor << " encontrado en la posicion: " << i << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "Elemento no encontrado." << endl;
}

void busquedaBinaria(vector<int> a, int valor) {
    cout << "\n--- Busqueda Binaria (Requiere ordenamiento previo) ---\n";
    // Forzamos un ordenamiento rápido por si el usuario no ha ordenado el vector original
    sort(a.begin(), a.end()); 
    cout << "Arreglo ordenado para busqueda: ";
    imprimir(a);

    int bajo = 0, alto = a.size() - 1;
    bool encontrado = false;

    while (bajo <= alto) {
        int centro = (bajo + alto) / 2;
        if (a[centro] == valor) {
            cout << "Elemento " << valor << " encontrado en la posicion: " << centro << endl;
            encontrado = true;
            break;
        } else if (valor < a[centro]) {
            alto = centro - 1;
        } else {
            bajo = centro + 1;
        }
    }
    if (!encontrado) cout << "Elemento no encontrado." << endl;
}

int main() {
    int datos[] = {10, 21, 17, 34, 11, 16, 44, 654, 123};
    vector<int> original(datos, datos + sizeof(datos) / sizeof(int));
    int opcion, buscar;

    do {
        cout << "\n--- MENU DE ALGORITMOS (UPIICSA) ---";
        cout << "\n1) Burbuja\n2) Seleccion Directa\n3) Insercion Directa";
        cout << "\n4) Shell Sort\n5) QuickSort\n6) Busqueda Secuencial";
        cout << "\n7) Busqueda Binaria\n0) Salir";
        cout << "\nOpcion: "; cin >> opcion;

        switch (opcion) {
            case 1: burbuja(original); break;
            case 2: seleccionDirecta(original); break;
            case 3: insercionDirecta(original); break;
            case 4: shellSort(original); break;
            case 5: 
                cout << "\n--- QuickSort ---\n";
                quick(original, 0, original.size() - 1); 
                imprimir(original);
                break;
            case 6:
                cout << "Valor a buscar: "; cin >> buscar;
                busquedaSecuencial(original, buscar);
                break;
            case 7:
                cout << "Valor a buscar: "; cin >> buscar;
                busquedaBinaria(original, buscar);
                break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Invalido.\n";
        }
    } while (opcion != 0);

    return 0;
}
