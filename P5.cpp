#include <iostream>
using namespace std;

int main() {
    int boletos;
    char respuesta;

    cout << "Central de Autobuses\n";
    cout << "¿Cuántos boletos quieres? ";
    cin >> boletos;

    cout << "¿Deseas hacer la compra? (s/n): ";
    cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        cout << "Total de boletos comprados: " << boletos << endl;
    } else {
        cout << "Compra cancelada.\n";
    }

    return 0;
}
