/*Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra*/

#include <stdio.h>
#include <time.h>
#define N 20

void CargarVector(int[],int);
void MostrarVector(int[],int);
int Menor(int[],int);
int ContMenor(int[],int,int);
int Mayor(int[],int);
void PosMayor(int[],int,int);
int main(){
    int v[N],menor,contMenor,mayor;

    srand(time(NULL));
    CargarVector(v,N);
    MostrarVector(v,N);
    menor=Menor(v,N);
    contMenor=ContMenor(v,menor,N);
    mayor=Mayor(v,N);
    printf("El menor valor es %d. Se repite %d veces.",menor,contMenor);
    printf("\nEl mayor valor es %d. ",mayor);
    PosMayor(v,mayor,N);

    return 0;
}

void CargarVector(int v[],int ce){
    int i;

    for(i=0;i<ce;i++){
        v[i]=rand()%1000;
        if(v[i]<100)
        i--;
    }
}

void MostrarVector(int v[],int ce){
    int i;

    for(i=0;i<ce;i++){
        printf("%d\n",v[i]);
    }
}

int Menor(int v[],int ce){
    int i,menor;
    menor=v[0];
    for(i=0;i<ce;i++){
        if(v[i]<menor)
        menor=v[i];
    }

    return menor;
}

int ContMenor(int v[],int menor,int ce){
    int i,cont=0;

    for(i=0;i<ce;i++){
        if(v[i]==menor)
        cont++;
    }

    return cont;
}

int Mayor(int v[],int ce){
    int i,mayor;
    mayor=v[0];
    for(i=0;i<ce;i++){
        if(v[i]>mayor)
        mayor=v[i];
    }

    return mayor;
}

void PosMayor(int v[],int mayor,int ce){
    int i;

    printf("El mayor se encuentra en la/s posicion/es: ");
    for(i=0;i<ce;i++){
        if(v[i]==mayor)
        printf("%d  ",i+1);
    }
}