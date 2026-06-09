#include <iostream>
#include <vector>

using namespace std;

// --- Prototipos de Funciones (Modularidad) ---
void pedirDatos(vector<int>& a, int n);
void mostrarArreglo(const vector<int>& a);
void intercambiar(int &x, int &y);

// Algoritmos de Ordenación
void burbuja(vector<int>& a);
void seleccion(vector<int>& a);
void insercion(vector<int>& a);
void shell(vector<int>& a);
void quickSort(vector<int>& a, int inicio, int fin); // Recursivo
void heapSort(vector<int>& a); // Basado en Montículo
void amontonar(vector<int>& a, int n, int i); // Auxiliar recursivo para Heap

int main() {
    int n, opcion;

    cout << "Ingrese el numero de elementos: ";
    cin >> n;

    vector<int> a(n);
    pedirDatos(a, n);

    do {
        cout << "\n--- MENU DE ORDENACION ---" << endl;
        cout << "1. Burbuja\n2. Seleccion\n3. Insercion\n4. QuickSort (Recursivo)\n5. Shell\n6. HeapSort (Recursivo)\n7. Salir" << endl;
        cout << "Escoja una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 6) {
            vector<int> copia = a; // Trabajamos sobre una copia para no alterar el original
            
            switch(opcion) {
                case 1: burbuja(copia); break;
                case 2: seleccion(copia); break;
                case 3: insercion(copia); break;
                case 4: quickSort(copia, 0, n - 1); break;
                case 5: shell(copia); break;
                case 6: heapSort(copia); break;
            }

            cout << "\nLista ordenada: ";
            mostrarArreglo(copia);
        }
    } while (opcion != 7);

    return 0;
}

// --- Implementaciones Modulares ---

void pedirDatos(vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Elemento [" << i + 1 << "]: ";
        cin >> a[i];
    }
}

void mostrarArreglo(const vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void intercambiar(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// 1. Burbuja
void burbuja(vector<int> a) {
    cout << "\n--- Burbuja ---\n";
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        cout << "Pasada " << i + 1 << ": ";
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
        for (int x : a) cout << x << " ";
        cout << "\n";
    }
}

// 2. Selección
void seleccion(vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++)
            if(a[j] < a[min]) min = j;
        intercambiar(a[i], a[min]);
    }
}

// 3. Inserción
void insercion(vector<int>& a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        int aux = a[i], j = i - 1;
        while(j >= 0 && a[j] > aux) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = aux;
    }
}

// 4. QuickSort (RECURSIVO)
void quickSort(vector<int>& a, int inicio, int fin) {
    int i = inicio, j = fin;
    int pivote = a[(inicio + fin) / 2];
    while (i <= j) {
        while (a[i] < pivote) i++;
        while (a[j] > pivote) j--;
        if (i <= j) {
            intercambiar(a[i], a[j]);
            i++; 
            j--;
        }
    }

    // Aseguramos que solo llame a la recursión si hay elementos pendientes
    if (inicio < j) quickSort(a, inicio, j); // Sub-arreglo izquierdo
    if (i < fin) quickSort(a, i, fin);       // Sub-arreglo derecho
}

// 5. Shell
void shell(vector<int>& a) {
    int n = a.size();
    for (int salto = n / 2; salto > 0; salto /= 2) {
        for (int i = salto; i < n; i++) {
            int temp = a[i], j;
            for (j = i; j >= salto && a[j - salto] > temp; j -= salto)
                a[j] = a[j - salto];
            a[j] = temp;
        }
    }
}

// 6. HeapSort (RECURSIVO)
void amontonar(vector<int>& a, int n, int i) {
    int largo = i, izq = 2 * i + 1, der = 2 * i + 2;
    if (izq < n && a[izq] > a[largo]) largo = izq;
    if (der < n && a[der] > a[largo]) largo = der;
    if (largo != i) {
        intercambiar(a[i], a[largo]);
        amontonar(a, n, largo); // Llamada recursiva
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) amontonar(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        intercambiar(a[0], a[i]);
        amontonar(a, i, 0);
    }
}
