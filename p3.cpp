#include <iostream>
using namespace std;

// Función recursiva para calcular el factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base
    } else {
        return n * factorial(n - 1); // Llamada recursiva
    }
}

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;
    
    cout << "El factorial de " << numero << " es: " << factorial(numero) << endl;
    
    return 0;
}
