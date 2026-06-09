#include <iostream>
using namespace std;
int Binaria(int*, int, int, int);
int tabla[] = {
    1, 3, 12, 33, 42, 43, 44, 45, 54, 55,
    61, 63, 72, 73, 82, 83, 84, 85, 94, 95,
    101, 103, 112, 133, 142, 143, 144, 145, 154, 155,
    161, 163, 172, 173, 182, 183, 184, 185, 194, 195
};

int main() {
    int pos;
    int valor = 141;

    pos = Binaria(tabla, valor, 0, sizeof(tabla)/sizeof(tabla[0])-1);
    if(pos >= 0) 
        cout << "Valor " << valor << " encontrado en posicion: " << pos << endl;
    else 
        cout << "Valor " << valor << " no encontrado" << endl;
    
    return 0;
}

/* Función de búsqueda binaria:
Busca el "valor" dentro del vector "vec" entre los márgenes
inferior "i" y superior "s" */
int Binaria(int* vec, int valor, int i, int s) {
    int inferior = i;
    int superior = s;
    int central;
    central = inferior + (superior - inferior) / 2;
    if(vec[central] == valor) return central;
    if(superior <= inferior) return -1;
    else if(vec[central] < valor) 
        return Binaria(vec, valor, central + 1, superior);
    return Binaria(vec, valor, inferior, central - 1);
}
