/*La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours a través de 15 agencias en todo
el país. Diariamente cada agencia envía la cantidad de ventas efectuadas de cada tour, indicando agencia,
tours y la cantidad de pasajes. Algunas agencias envían 0 en la cantidad cuando no existen pasajes para un
tour determinado, pero no en todas.
La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
• Código de agencia (de 1 a 15)
• Código de tour (1 a 10)
• Cantidad de pasajes (0 a 20)
Informar:
a. El total de pasajes vendidos por tour en cada agencia.
b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos. (puede repetirse)*/

#include <stdio.h>
#define F 15
#define C 10

void CargarMat(int[][C],int[][C],int,int);
int BuscarDato(int[][C],int,int,int);
void MostrarA(int[][C],int,int);
void MostrarB(int [][C],int,int);
int main(){
    int i,j,m[F][C],m2[F][C];

    for(i=0;i<F;i++){
        for(j=0;j<C;j++){
            m[i][j]=0;
            m2[i][j]=-1;
        }
    }

    CargarMat(m,m2,F,C);
    printf("\n\n");
    MostrarA(m,F,C);
    printf("\n\n");
    MostrarB(m,F,C);

    return 0;
}

void CargarMat(int m[][C],int m2[][C],int filas,int col){
    int i,j,agencia,tour,pasajes,cont=0,ret;
    
    printf("\nIngrese el codigo de agencia: ");
    scanf("%d",&agencia);
    while(agencia<1 || agencia>15){
        printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo de agencia: ");
        scanf("%d",&agencia);
    }
    ret=BuscarDato(m2,-1,filas,col);
    
    while(ret!=-1){
        printf("Ingrese el codigo de tour: ");
        scanf("%d",&tour);
        while(tour<1 || tour>10){
            printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo de tour: ");
            scanf("%d",&tour);
        }
    
        printf("Ingrese la cantidad de pasajes: ");
        scanf("%d",&pasajes);
        while(pasajes<0 || pasajes>20){
            printf("NUMERO INVALIDO.\nIngrese nuevamente la cantidad de pasajes: ");
            scanf("%d",&pasajes);
        }
        m[agencia-1][tour-1]+=pasajes;
        m2[agencia-1][tour-1]=pasajes;

        ret=BuscarDato(m2,-1,filas,col);

        if(ret!=-1){
            printf("\nIngrese el codigo de agencia: ");
            scanf("%d",&agencia);
            while(agencia<1 || agencia>15){
                printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo de agencia: ");
                scanf("%d",&agencia);
            }
        }
    }

    printf("\n");
    printf("\n");
    for(j=0;j<col;j++){
        printf("%6d",j+1);
    }
    printf("\n");
    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            if(j==0)
            printf("%d",i+1);
            printf("%5d",m[i][j]);
        }
        printf("\n");
    }
}

int BuscarDato(int m[][C],int datoBuscado,int filas,int col){
    int i,j,ret=-1;

    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            if(m[i][j]==datoBuscado){
                ret=1;
            }
        } 
    }

    return ret;
}

void MostrarA(int m[][C],int filas,int col){
    int i,j;
    for(i=0;i<filas;i++){
        printf("\nAGENCIA %d:\n",i+1);
        for(j=0;j<col;j++){
            printf("Tour %d: %d  ",j+1,m[i][j]);
        }
    }
}

void MostrarB(int m[][C],int filas,int col){
    int i,j,mayor,sum=0;

    printf("Las agencias que mas pasajes vendieron fueron:");
    for(j=0;j<col;j++){
        sum+=m[0][j];
    }
    mayor=sum;
    sum=0;
    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            sum+=m[i][j];
        }
        if(sum>mayor){
            mayor=sum;
        }
        sum=0;
    }

    for(i=0;i<filas;i++){
        for(j=0;j<col;j++){
            sum+=m[i][j];
        }
        if(sum==mayor)
        printf("%3d",i+1); 
        sum=0;
    }
    printf("   con %d pasajes vendidos.",mayor);
}