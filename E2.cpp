#include <stdio.h>

int main()
{
    // Declaración de variables
    int num1, num2, num3, num4;
    int suma, multiplicacion;
    float media;
    
    // Entrada de datos
    printf("CALCULADORA DE SUMA, MULTIPLICACION Y MEDIA\n");
    printf("============================================\n\n");
    
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);
    
    printf("Ingrese el cuarto numero: ");
    scanf("%d", &num4);
    
    // Procesamiento
    suma = num1 + num2 + num3 + num4;
    multiplicacion = num1 * num2 * num3 * num4;
    media = suma / 4.0;  // Se usa 4.0 para obtener resultado decimal
    
    // Salida de resultados
    printf("\nRESULTADOS:\n");
    printf("-----------\n");
    printf("La suma de %d + %d + %d + %d = %d\n", num1, num2, num3, num4, suma);
    printf("La multiplicacion de %d * %d * %d * %d = %d\n", num1, num2, num3, num4, multiplicacion);
    printf("La media aritmetica de los 4 numeros es: %.2f\n", media);
    
    return 0;
}
