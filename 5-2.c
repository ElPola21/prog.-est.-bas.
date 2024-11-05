/*Definir dos números enteros y dos punteros a dichos números. Accediendo mediante los punteros sumar
ambos números y mostrar el resultado por pantalla.*/

#include <stdio.h>

int main(){
    int a,b,*puntero1,*puntero2;

    printf("Ingrese numero a: ");
    scanf("%d",&a);
    printf("Ingrese numero b: ");
    scanf("%d",&b);

    puntero1=&a;
    puntero2=&b;

    printf("\nLa suma es %d.",*puntero1+*puntero2);

    return 0;
}