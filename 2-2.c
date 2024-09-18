/*Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por fila de
dicha matriz y otra función que calcule la suma por columna en otro vector.*/

#include <stdio.h>
#define F 5
#define C 4

void CargarMatriz(int[][C],int,int);
void SumaFila(int[][C],int[],int,int);
void SumaCol(int[][C],int[],int,int);
void MostrarMat(int[][C],int,int);
void MostrarVec(int[],int[],int,int);
int main(){
    int m[F][C],vSumFilas[F],vSumCol[C];

    CargarMatriz(m,F,C);
    SumaFila(m,vSumFilas,F,C);
    SumaCol(m,vSumCol,F,C);
    MostrarMat(m,F,C);
    printf("\n\n");
    MostrarVec(vSumFilas,vSumCol,F,C);    

    return 0;
}

void CargarMatriz(int m[][C],int filas,int col){
    int i,j;

    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            printf("Ingrese el valor %dx%d: ",i,j);
            scanf("%d",&m[i][j]);
        }
        printf("\n");
    }
}

void SumaFila(int m[][C],int v[],int filas,int col){
    int i,j,sum=0;

    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            sum+=m[i][j];
        }
        v[i]=sum;
        sum=0;
    }
}

void SumaCol(int m[][C],int v[],int filas,int col){
    int i,j,sum=0;

    for(j=0;j<col;j++){
        for(i=0;i<filas;i++){
            sum+=m[i][j];
        }
        v[j]=sum;
        sum=0;
    }
}

void MostrarMat(int m[][C],int filas,int col){
    int i,j;

    printf("MATRIZ:\n");
    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}

void MostrarVec(int vF[],int vC[],int filas,int col){
    int i;

    printf("VECTOR SUMA FILAS: ");
    for(i=0;i<filas;i++){
        printf("%3d",vF[i]);
    }
    printf("\nVECTOR SUMA COLUMNAS: ");
    for(i=0;i<col;i++){
        printf("%3d",vC[i]);
    }
}