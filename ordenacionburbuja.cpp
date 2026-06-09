#include<iostream>
using namespace std;

int main ()
{
    int i, j, temp, n;

    // 1. Pedir el tamaño del arreglo
    cout << "Ingrese el numero de elementos que desea ordenar: ";
    cin >> n;

    // Creamos el arreglo con el tamaño proporcionado
    int a[n]; 

    // 2. Pedir los elementos al usuario
    cout << "Ingrese los " << n << " numeros uno por uno:" << endl;
    for(i = 0; i < n; i++) {
        cout << "Elemento [" << i + 1 << "]: ";
        cin >> a[i];
    }

    // Mostrar lista original
    cout << "\nLista de entrada ...\n";
    for(i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    // 3. Algoritmo de ordenación (adaptado al tamaño n)
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // 4. Mostrar lista ordenada
    cout << "\nLista de elementos ordenados ...\n";
    for(i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    return 0;
}
