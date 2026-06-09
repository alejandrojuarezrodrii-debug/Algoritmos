#include <iostream>
#include <string.h>

using namespace std;

// Estructura para los datos del registro
struct Registro {
    char curp[19]; // 18 caracteres + fin de cadena '\0'
    bool activo;   // Para simular bajas lógicas
};

// Prototipos de funciones
void Alta(Registro*, int&, int);
void Baja(Registro*, int);
void Modificacion(Registro*, int);
int Buscar(Registro*, char*, int); // Basado en búsqueda secuencial
void MostrarTodo(Registro*, int);

int main() {
    const int MAX = 100; // Capacidad máxima del arreglo
    Registro lista[MAX];
    int total = 0; // Cuántos registros hay actualmente
    int opcion;
    char curpBusca[19];

    do {
        cout << "\n--- MENU GESTION CURP ---" << endl;
        cout << "1. Alta de registro" << endl;
        cout << "2. Baja (por CURP)" << endl;
        cout << "3. Modificacion" << endl;
        cout << "4. Mostrar todos" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: Alta(lista, total, MAX); break;
            case 2: Baja(lista, total); break;
            case 3: Modificacion(lista, total); break;
            case 4: MostrarTodo(lista, total); break;
        }
    } while(opcion != 5);

    return 0;
}

// Implementacion de Busqueda Secuencial
int Buscar(Registro* vec, char* valor, int n) {
    for(int k = 0; k < n; k++) {
        if(strcmp(vec[k].curp, valor) == 0 && vec[k].activo) {
            return k; // Retorna la posicion
        }
    }
    return -1; // No encontrado
}

void Alta(Registro* vec, int &n, int limite) {
    if(n < limite) {
        cout << "Ingrese la nueva CURP (18 caracteres): ";
        cin >> vec[n].curp;
        vec[n].activo = true;
        n++;
        cout << "Alta exitosa." << endl;
    } else {
        cout << "Error: Lista llena." << endl;
    }
}

void Baja(Registro* vec, int n) {
    char busca[19];
    cout << "Ingrese CURP a dar de baja: ";
    cin >> busca;
    int pos = Buscar(vec, busca, n);
    if(pos != -1) {
        vec[pos].activo = false; // Baja logica
        cout << "Registro desactivado correctamente." << endl;
    } else {
        cout << "CURP no encontrada." << endl;
    }
}

void Modificacion(Registro* vec, int n) {
    char busca[19];
    cout << "Ingrese CURP a modificar: ";
    cin >> busca;
    int pos = Buscar(vec, busca, n);
    if(pos != -1) {
        cout << "Ingrese la nueva CURP: ";
        cin >> vec[pos].curp;
        cout << "Modificacion exitosa." << endl;
    } else {
        cout << "No se puede modificar: CURP no existe." << endl;
    }
}

void MostrarTodo(Registro* vec, int n) {
    cout << "\nLISTADO DE REGISTROS ACTIVOS:" << endl;
    for(int i = 0; i < n; i++) {
        if(vec[i].activo) {
            cout << i << ". " << vec[i].curp << endl;
        }
    }
}
