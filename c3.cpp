#include <stdio.h>
#include <string.h>
#include <ctype.h>  // para tolower()

int main() {
    // Declaración de variables
    char nombre[50];
    int boleta;
    int i, n;
    float suma, promedio, dato;
    char opcion;
    
    // DO-WHILE principal (para repetir todo el proceso)
    do {
        printf("========================================\n");
        printf("    REGISTRO DE CALIFICACIONES\n");
        printf("========================================\n\n");
        
        // Entrada de datos básicos
        printf("Ingrese el nombre del alumno: ");
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strcspn(nombre, "\n")] = 0;  // Eliminar salto de línea
        
        printf("Ingrese el numero de boleta: ");
        scanf("%d", &boleta);
        
        // Preguntar cuántas calificaciones
        printf("\n¿Cuantas calificaciones se van a introducir? ");
        scanf("%d", &n);
        
        // IF para validar que n sea positivo
        if (n > 0) {
            printf("\n--- PRUEBA DE ESCRITORIO ---\n");
            printf("Corrida | n | dato | suma | promedio\n");
            printf("--------------------------------------\n");
            
            i = 1;
            suma = 0;
            
            // WHILE para ingresar las n calificaciones
            while (i <= n) {
                printf("Calificacion %d: ", i);
                scanf("%f", &dato);
                suma = suma + dato;
                
                // Mostrar cada paso de la prueba de escritorio
                printf("   %d    | %d | %.2f | %.2f |\n", i, n, dato, suma);
                
                i++;
            }
            
            // Calcular promedio
            promedio = suma / n;
            printf("--------------------------------------\n");
            printf("Promedio final: %.2f\n", promedio);
            
            // IF ANIDADO para evaluar el resultado
            printf("RESULTADO: ");
            if (promedio == 10) {
                printf("¡FELICIDADES!\n");
            } else {
                if (promedio >= 6) {
                    printf("PASASTE\n");
                } else {
                    printf("REPROBASTE\n");
                }
            }
            
            // Mostrar datos del alumno
            printf("\n--- DATOS DEL ALUMNO ---\n");
            printf("Nombre: %s\n", nombre);
            printf("Boleta: %d\n", boleta);
            printf("Calificaciones ingresadas: %d\n", n);
            printf("Suma total: %.2f\n", suma);
            printf("Promedio: %.2f\n", promedio);
            printf("========================================\n");
            
        } else {
            printf("\nError: Debe ingresar un numero positivo de calificaciones.\n");
        }
        
        // Preguntar si desea continuar
        printf("\n¿Desea continuar con otro alumno? (s/n): ");
        scanf(" %c", &opcion);  // Espacio antes de %c para ignorar whitespace
        getchar();  // Limpiar el buffer de entrada
        
    } while (opcion == 's' || opcion == 'S');
    
    printf("\nPrograma terminado. ¡Hasta luego!\n");
    
    return 0;
}
