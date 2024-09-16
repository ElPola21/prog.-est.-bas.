/*Dado un vector de 10 enteros, ingresar un entero por teclado, buscarlo y, si se lo encuentra, generar un nuevo
vector con los índices correspondientes a las ubicaciones en el primer vector del entero ingresado.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void CargarYMostrarV(int[],int);
void CargarVInd(int[],int[],int);
int BuscarDato(int[],int[],int,int);
int main() {
    int v[N],vIndices[N];

    srand(time(NULL));
    CargarYMostrarV(v,N);
    CargarVInd(v,vIndices,N);

    return 0;
}

void CargarYMostrarV(int v[],int ce){
    int i;

    for(i=0;i<ce;i++){
        v[i]=rand()%10;
    }

    for(i=0;i<ce;i++){
        printf("\n%d",v[i]);
    }
}

int BuscarDato(int v[],int vInd[],int datoBuscado,int ce){
    int i,cont=0;

    for(i=0;i<ce;i++){
        if(v[i]==datoBuscado){
            vInd[cont]=i;
            cont++;
        }
    }

    return cont;
}

void CargarVInd(int v[],int vInd[],int ce){
    int i,num,cont;

    printf("\n\nIngrese un numero: ");
    scanf("%d",&num);
    cont=BuscarDato(v,vInd,num,ce);
    if(!cont)
    printf("No se encontro el numero.");
    else
    printf("El numero se encuentra en las posiciones:");
    for(i=0;i<cont;i++){
        printf("%3d",vInd[i]);
    }
}