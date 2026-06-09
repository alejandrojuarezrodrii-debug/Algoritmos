#include <stdio.h>
#include <string.h>

int main()
{
    // Declaración de variables
    char nombre[50];
    int boleta;
    float calificaciones[5];  // Arreglo para 5 calificaciones
    float suma = 0, promedio;
    int i;  // Variable para el ciclo for
    
    // Entrada de datos básicos
    printf("REGISTRO DE CALIFICACIONES DEL ALUMNO\n");
    printf("======================================\n\n");
    
    printf("Ingrese el nombre del alumno: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;  // Eliminar salto de línea
    
    printf("Ingrese el numero de boleta: ");
    scanf("%d", &boleta);
    
    // CICLO FOR para ingresar las 5 calificaciones
    printf("\n--- INGRESE LAS 5 CALIFICACIONES ---\n");
    for(i = 0; i < 5; i++) {
        printf("Calificacion %d: ", i+1);
        scanf("%f", &calificaciones[i]);
        suma = suma + calificaciones[i];  // Acumular suma
    }
    
    // Calcular promedio
    promedio = suma / 5;
    
    // Salida de resultados
    printf("\n\n======================================\n");
    printf("        DATOS DEL ALUMNO\n");
    printf("======================================\n");
    printf("Nombre: %s\n", nombre);
    printf("Boleta: %d\n", boleta);
    
    // Mostrar todas las calificaciones usando for
    printf("\nCALIFICACIONES:\n");
    for(i = 0; i < 5; i++) {
        printf("  - Calificacion %d: %.2f\n", i+1, calificaciones[i]);
    }
    
    printf("\nPROMEDIO: %.2f\n", promedio);
    
    // Evaluación con IF ANIDADO
    printf("RESULTADO: ");
    if(promedio == 10) {
        printf("¡FELICIDADES!\n");
    } else {
        if(promedio >= 6) {
            printf("PASASTE\n");
        } else {
            printf("REPROBASTE\n");
        }
    }
    
    printf("======================================\n");
    
    return 0;
}
