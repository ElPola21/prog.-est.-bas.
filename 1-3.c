/*En un curso de la maestría en informática los estudiantes deben exponer en forma grupal sus investigaciones
de un tema dado. El curso está formado por 5 grupos. Se pide realizar un programa para sortear el orden de
exposición de dichos grupos. Cada vez que se ejecute el programa deberá mostrar un orden de exposición
distinto para cada uno de los 5 grupos.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void VectorOrdenGrupos(int[],int);
void MostrarOrdenGrupos(int[],int);
int BuscarRepetido(int[],int,int);
int main(){
    int vGrupos[N];

    srand(time(NULL));
    VectorOrdenGrupos(vGrupos,N);
    MostrarOrdenGrupos(vGrupos,N);

    return 0;
}

void VectorOrdenGrupos(int v[],int cantGrup){
    int i,repetirVal;

    for(i=0;i<cantGrup;i++){
        v[i]=rand()%5 +1;
        repetirVal=BuscarRepetido(v,v[i],i);
        if(repetirVal!=-1)
        i--;
    }
}

int BuscarRepetido(int v[],int datoBuscado,int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(v[i]==datoBuscado)
        pos=i;
    }

    return pos;
}

void MostrarOrdenGrupos(int v[],int cantGrup){
    int i;

    printf("El orden de los grupos es:\n");
    for(i=0;i<cantGrup;i++){
        printf("%d\n",v[i]);
    }
}