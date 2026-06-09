#include <stdio.h>
int main() //menu, que es el inicio del programa//
{
    int dulce,total;
    printf("Tecléa el valor consumido de dulce: \n"); //stdo es printf
    scanf("%d", &dulce); //scanf es de la librería stdio., y el & para ingresar el num
    total = dulce * 13;

    printf("El consumo fue %d \n", total);
    // printf("La multiplicacion es %d \n", mul);
    // printf("La division es %.2f \n", media); //.2 es para dos decimales
}
