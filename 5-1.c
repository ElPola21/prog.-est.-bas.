/*Crear una variable entera y un puntero a dicha variable
Asignar el valor 10 a la variable mediante el puntero
Mostrar:
a) la dirección de la variable
b) la dirección del puntero
c) el contenido de la variable
d) el contenido de la variable accediendo mediante el puntero
e) el contenido del puntero*/

#include <stdio.h>

int main(){
    int var=10,*puntero;

    puntero=&var;

    printf("Direccion de variable: %p",&var);
    printf("\nDireccion del puntero: %p",&puntero);
    printf("\nContenido de la variable: %d",var);
    printf("\nContenido de la variable accediendo mediante el puntero(contenido apuntado): %d",*puntero);
    printf("\nContenido del puntero: %p",puntero);

    return 0;
}