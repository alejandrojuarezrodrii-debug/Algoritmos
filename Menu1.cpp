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

void burbuja(vector<int> a) {
    cout << "\n--- Burbuja ---\n";
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
        cout << "Pasada " << i + 1 << ": ";
        imprimir(a);
    }
}

void seleccionDirecta(vector<int> a) {
    cout << "\n--- Seleccion Directa ---\n";
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]);
        cout << "Pasada " << i + 1 << ": ";
        imprimir(a);
    }
}

void insercionDirecta(vector<int> a) {
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
        cout << "Pasada " << i << ": ";
        imprimir(a);
    }
}

void shellSort(vector<int> a) {
    cout << "\n--- Shell Sort ---\n";
    int n = a.size();
    int gap = n / 2, pasada = 1;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = a[i], j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
        cout << "Gap " << gap << " (Pasada " << pasada << "): ";
        imprimir(a);
        gap /= 2;
        pasada++;
    }
}

void quick(vector<int>& a, int ini, int fin, int& p) {
    int i = ini, j = fin;
    int piv = a[(ini + fin) / 2];
    while (i <= j) {
        while (a[i] < piv) i++;
        while (a[j] > piv) j--;
        if (i <= j) { swap(a[i], a[j]); i++; j--; }
    }
    cout << "Pasada " << ++p << ": ";
    imprimir(a);
    if (ini < j) quick(a, ini, j, p);
    if (i < fin) quick(a, i, fin, p);
}

int main() {
    // Arreglo de la imagen
    int datos[] = {10, 21, 17, 34, 11, 16, 44, 654, 123};
    vector<int> original(datos, datos + sizeof(datos) / sizeof(int));
    int opcion;

    do {
        cout << "\n--- MENU DE ORDENAMIENTO ---";
        cout << "\n1) Burbuja\n2) Seleccion Directa\n3) Insercion Directa";
        cout << "\n4) Shell Sort\n5) QuickSort\n0) Salir";
        cout << "\nOpcion: "; cin >> opcion;

        switch (opcion) {
            case 1: burbuja(original); break;
            case 2: seleccionDirecta(original); break;
            case 3: insercionDirecta(original); break;
            case 4: shellSort(original); break;
            case 5: {
                vector<int> copia = original;
                int p = 0;
                cout << "\n--- QuickSort ---\n";
                quick(copia, 0, copia.size() - 1, p);
                break;
            }
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Invalido.\n";
        }
    } while (opcion != 0);

    return 0;
}
