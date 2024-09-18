/*Cargar de forma aleatoria una matriz de 5 x 8 con números de 2 cifras. Determinar el máximo valor
almacenado en la matriz indicando cuantas veces se repite y en que posiciones*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define F 5
#define C 8

void CargarYMostrarMat(int[][C],int,int);
int BuscarMayor(int[][C],int,int);
int ContMayor(int[][C],int,int,int);
void PosMayor(int[][C],int,int,int);
int main(){
    int m[F][C],mayor,contMayor;

    srand(time(NULL));
    CargarYMostrarMat(m,F,C);
    mayor=BuscarMayor(m,F,C);
    contMayor=ContMayor(m,mayor,F,C);
    printf("El mayor valor de la matriz es %d y aparece %d veces. ",mayor,contMayor);
    PosMayor(m,mayor,F,C);

    return 0;
}

void CargarYMostrarMat(int m[][C],int filas,int col){
    int i,j;

    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            do{
                m[i][j]=rand()%100;
            }while (m[i][j]<10);
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}

int BuscarMayor(int m[][C],int filas,int col){
    int i,j,mayor;

    mayor=m[0][0];
    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            if(m[i][j]>mayor)
            mayor=m[i][j];   
        }
    }

    return mayor;
}

int ContMayor(int m[][C],int datoBuscado,int filas,int col){
    int i,j,cont=0;

    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            if(m[i][j]==datoBuscado)
            cont++;   
        }
    }

    return cont;
}

void PosMayor(int m[][C],int mayor,int filas,int col){
    int i,j;

    printf("Se encuentra en las posiciones: ");
    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            if(m[i][j]==mayor)
            printf("%3dx%d",i,j);   
        }
    }
}