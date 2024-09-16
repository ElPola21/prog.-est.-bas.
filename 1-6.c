/*Dado un conjunto de 10 números enteros ordenados de menor a mayor, ingresar por teclado 3 números más
no ordenados. Insertarlos donde correspondan. Mostrar en pantalla la serie inicial y la final.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void CargarV1(int[],int);
void OrdenarV(int[],int);
void UnirV1y2(int[],int[],int[],int);
int main(){
    int i,v1[N],v2[3],vUnido[N+3];

    srand(time(NULL));
    CargarV1(v1,N);
    OrdenarV(v1,N);
    printf("INICIAL:\n");
    for(i=0;i<N;i++){
        printf("%d\n",v1[i]);
    }
    UnirV1y2(v1,v2,vUnido,N+3);
    printf("FINAL:\n");
    for(i=0;i<N+3;i++){
        printf("%d\n",vUnido[i]);
    }

    return 0;
}

void CargarV1(int v1[],int ce){
    int i;
    for(i=0;i<ce;i++){
        v1[i]=rand()%100;
    }
}

void OrdenarV(int v1[],int ce){
    int aux,i,cota=ce-1,desordenado=1;

    while(desordenado){
        desordenado=0;
        for(i=0;i<cota;i++){
            if(v1[i]>v1[i+1]){
                aux=v1[i];
                v1[i]=v1[i+1];
                v1[i+1]=aux;
                desordenado=i;
            }
        }
        cota=desordenado;
    }
}

void UnirV1y2(int v1[],int v2[],int vUnido[],int ce){
    int i;

    for(i=0;i<3;i++){
        printf("Ingrese un numero: ");
        scanf("%d",&v2[i]);
    }

    for(i=0;i<ce;i++){
        if(i<10)
        vUnido[i]=v1[i];
        else
        vUnido[i]=v2[i-10];
    }

    OrdenarV(vUnido,ce);
}