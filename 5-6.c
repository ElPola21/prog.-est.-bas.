/*Cargar un vector de enteros con números aleatorios de 3 cifras máximo.
Realizar una función que retorne un puntero al mayor valor del vector
Mostrar el máximo valor mediante el puntero y la posición en la cual se encuentra*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

int* Mayor(int[],int);
int main(){
    int i,v[MAX],*p;

    srand(time(NULL));
    p=Mayor(v,MAX);

    for(i=0;i<MAX;i++){
        printf("\n%d",v[i]);
    }
    printf("\nEl mayor es %d. Posicion %d.",*p,(p-v)+1);

    return 0;
}

int* Mayor(int v[],int ce){
    int i,*p;

    for(i=0;i<ce;i++){
        v[i]=rand()%1000;
    }
    p=v;
    for(i=0;i<ce;i++){
        if(v[i]>*p)
        p=v+i;
    }

    return p;
}