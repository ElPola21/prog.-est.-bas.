/*Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las funciones de
la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre coma espacio y
apellido) y mostrarlo*/

#include <stdio.h>
#include <string.h>
#define TAM 40

int main(){
    char nombre[TAM],apellido[TAM],completo[TAM*2];

    printf("Ingrese nombre: ");
    fgets(nombre,TAM,stdin);
    fflush(stdin);
    nombre[strlen(nombre)-1]='\0';

    printf("Ingrese apellido: ");
    fgets(apellido,TAM,stdin);
    fflush(stdin);
    apellido[strlen(apellido)-1]='\0';

    strcat(nombre,", ");
    strcpy(completo,strcat(nombre,apellido));
    printf("%s",completo);

    return 0;
}