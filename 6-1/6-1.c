/*Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char nombreApellido[81];
    int nota1;
    int nota2;
    float prom;
}tAlumno;

int main()
{
    tAlumno alumnos;
    FILE * ap;

    ap = fopen("Alumnos.dat", "wb");
    if(ap == NULL)
    {
        printf("Error.\n");
        getch();
        exit(1);
    }

    printf("Ingrese el DNI del alumno (0 para cerrar): ");
    scanf("%d", &alumnos.dni);

    while(alumnos.dni != 0)
    {
        printf("Ingrese su nombre y apellido: ");
        fflush(stdin);
        fgets(alumnos.nombreApellido, 81, stdin);
        printf("Ingrese la primera nota: ");
        scanf("%d", &alumnos.nota1);
        printf("Ingrese la segunda nota: ");
        scanf("%d", &alumnos.nota2);
        alumnos.prom = (float)(alumnos.nota1 + alumnos.nota2)/2;

        fwrite(&alumnos, sizeof(tAlumno), 1, ap);
        
        printf("Ingrese el DNI del alumno (0 para cerrar): ");
        scanf("%d", &alumnos.dni);
    }

    fclose(ap);

    ap = fopen("Alumnos.dat", "rb");
    if(ap == NULL)
    {
        printf("Error.\n");
        getch();
        exit(1);
    }

    while(fread(&alumnos, sizeof(tAlumno), 1, ap)){
        printf("\nDNI: %d\n", alumnos.dni);
        printf("Nombre y Apellido: %s", alumnos.nombreApellido);
        printf("Nota 1: %d\n", alumnos.nota1);
        printf("Nota 2: %d\n", alumnos.nota2);
        printf("Promedio: %.2f\n", alumnos.prom);
        printf("------------------------\n");
    }

    fclose(ap);

    return 0;
}
