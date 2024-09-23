/*Se desea desarrollar un sistema de reservas de entradas para un cine. La sala consta de 12 filas numeradas de
la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central, con las butacas impares a la
derecha y las pares a la izquierda, como en el siguiente esquema:
8 6 4 2 1 3 5 7 9
Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando
con la letra D las disponibles y con la letra R las reservadas.
Por cada reserva se debe solicitar la fila y número de butaca a reservar. Cada vez que se realice una
reserva se deberá actualizar el esquema que muestra las butacas. Si la butaca seleccionada ya estaba
ocupada se debe informar al usuario para que seleccione otra. El proceso de reserva finaliza con una fila
con un número negativo.
Al finalizar mostrar:
a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
b. los números de filas que quedaron vacías.
c. la o las filas con mayor cantidad de espectadores.
d. un listado con la cantidad de personas que se sentaron en los mismos números de butacas en
todo el cine ordenado de mayor a menor. Por ejemplo:
    Butaca Cantidad
       1     10
       4     6
       8     2
     ..............
EL D NO LO PUDE HACER*/

#include <stdio.h>
#define F 12
#define C 9

void CargarM(char[][C],int,int);
void CargarReservas(char[][C],int[],int,int);
int BuscarButaca(int[],int,int);
int BuscarAsiento(char[][C],int,int,char,int,int);
void MostrarA(int,int);
void MostrarB(char[][C],int,int);
void MostrarC(char[][C],int,int);
int main(){
    char mButacas[F][C];
    int vCol[C]={8,6,4,2,1,3,5,7,9};

    CargarM(mButacas,F,C);
    CargarReservas(mButacas,vCol,F,C);
    MostrarB(mButacas,F,C);
    MostrarC(mButacas,F,C);

    return 0;
}

void CargarM(char m[][C],int filas,int col){
    int i,j;

    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            m[i][j]='D';
        }
    }
}

void CargarReservas(char m[][C],int v[],int filas,int col){
    int i,j,fila,butaca,posBut,rep,contDisp=108,contRes=0;

    printf("     ");
    for(j=0;j<col;j++){
        printf("%5d",v[j]);
    }
    printf("\n");
    for(i=0;i<filas;i++){
        printf("%5d",i+1);
        for(j=0;j<col;j++){
            printf("%5c",m[i][j]);
        }
        printf("\n");
    }

    printf("\nIngrese fila a reservar: ");
    scanf("%d",&fila);
    while((fila<1 || fila>12) && fila>=0){
        printf("FILA INVALIDA.\nIngrese nuevamente la fila a reservar: ");
        scanf("%d",&fila);
    }
    while(fila>0){
        printf("\nIngrese numero de butaca a reservar: ");
        scanf("%d",&butaca);
        while(butaca<1 || butaca>9){
            printf("BUTACA INVALIDA.\nIngrese nuevamente el numero de butaca a reservar: ");
            scanf("%d",&butaca);
        }
        system("CLS");
        
        posBut=BuscarButaca(v,butaca,col);
        rep=BuscarAsiento(m,fila,posBut,'R',filas,col);
        if(!rep){
            m[fila-1][posBut]='R';
            contDisp--;
            contRes++;
        }
        else
        printf("ASIENTO OCUPADO.\n");

        printf("     ");
        for(j=0;j<col;j++){
            printf("%5d",v[j]);
        }
        printf("\n");
        for(i=0;i<filas;i++){
            printf("%5d",i+1);
            for(j=0;j<col;j++){
                printf("%5c",m[i][j]);
            }
            printf("\n");
        }

        printf("\nIngrese fila a reservar: ");
        scanf("%d",&fila);
        while((fila<1 || fila>12) && fila>=0){
            printf("FILA INVALIDA.\nIngrese nuevamente la fila a reservar: ");
            scanf("%d",&fila);
        }
    }

    MostrarA(contDisp,contRes);
}

int BuscarButaca(int v[],int datoBuscado,int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(v[i]==datoBuscado)
        pos=i;
    }

    return pos;
}

int BuscarAsiento(char m[][C],int fila,int butaca,char datoBuscado,int filas,int col){
    int pos=0;

    if(m[fila-1][butaca]==datoBuscado)
    pos=1;

    return pos;
}

void MostrarA(int disp,int res){
    printf("\nHay %d asientos libres.\nHay %d asientos ocupados.",disp,res);
}

void MostrarB(char m[][C],int filas,int col){
    int i,j,contD=0;

    printf("\n\nLas filas que quedaron vacias son:\n");
    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            if(m[i][j]=='D')
            contD++;
            if(contD==9)
            printf("Fila: %d. ",i+1);
        }
        contD=0;
    }
}

void MostrarC(char m[][C],int filas,int col){
    int i,j,mayor,contR=0;

    for(j=0;j<col;j++){
        if(m[0][j]=='R')
        contR++;
    }
    mayor=contR;
    contR=0;

    for(i=0;i<filas;i++){
        for(j=1;j<col;j++){
            if(m[i][j]=='R')
            contR++;
        }
        if(contR>mayor)
        mayor=contR;
        contR=0;
    }

    printf("\n\nLas filas con mayor cantidad de espectadores son: ");
    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            if(m[i][j]=='R')
            contR++;
        }
        if(contR==mayor)
        printf("Fila %d. ",i+1);
        contR=0;
    }
}