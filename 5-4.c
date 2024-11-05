/* Hacer un programa que cargue un vector de 10 enteros y lo muestre usando una función para cargar y otra
mostrar sin utilizar subíndices.*/

#include <stdio.h>

void Carga(int[],int);
void Mostrar(int[],int);
int main(){
    int v[10];

    Carga(v,10);
    Mostrar(v,10);

    return 0;
}

void Carga(int v[],int ce){
    int i;

    for(i=0;i<ce;i++){
        printf("Ingrese entero: ");
        scanf("%d",v+i);
    }
}

void Mostrar(int v[],int ce){
    int i;

    for(i=0;i<ce;i++){
        printf("%6d",*(v+i));
    }
}