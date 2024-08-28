/*Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
 La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.*/

#include <stdio.h>
#define N 10

void IngresaCodigos(int[],int,int,int);
int BuscarRepetido(int[],int,int);
void CargaVectores(int[],int[],int[]);
void MostrarVectores(int[],int[],int);
int MayorCantUnidades(int[],int[],int);
int MenorCantUnidades(int[],int[],int);
void MostrarMayoresYMenores(int[],int[],int,int,int);
int main(){
    int vCodigosInicio[N],vCod[N]={0},vCantUni[N]={0},mayor,menor;

    IngresaCodigos(vCodigosInicio,N,1000,10000);
    printf("\n");
    CargaVectores(vCod,vCantUni,vCodigosInicio);
    MostrarVectores(vCod,vCantUni,N);
    mayor=MayorCantUnidades(vCod,vCantUni,N);
    menor=MenorCantUnidades(vCod,vCantUni,N);
    MostrarMayoresYMenores(vCod,vCantUni,mayor,menor,N);

    return 0;
}

void IngresaCodigos(int v[],int ce,int valorMin,int valorMax){
    int i,repetir;

    for(i=0;i<ce;i++){
        printf("Ingrese el codigo: ");
        scanf("%d",&v[i]);
        repetir=BuscarRepetido(v,v[i],i);
        while(v[i]<valorMin || v[i]>valorMax || repetir!=-1){
            printf("CODIGO INVALIDO.");
            printf("\nIngrese nuevamente el codigo: ");
            scanf("%d",&v[i]);
            repetir=BuscarRepetido(v,v[i],i);
        }
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

void CargaVectores(int vCod[],int vCantUni[],int v[]){
    int repetir,cant,cod;

    printf("Ingrese codigo del producto: ");
    scanf("%d",&cod);
    if(cod!=0){
        repetir=BuscarRepetido(v,cod,N);
        if(repetir!=-1)
        vCod[repetir]=cod;
    }
    while(repetir==-1 && cod!=0){
        printf("CODIGO INVALIDO.");
        printf("\nIngrese nuevamente el codigo del producto: ");
        scanf("%d",&cod);
        if(cod!=0){
            repetir=BuscarRepetido(v,cod,N);
            if(repetir!=-1)
            vCod[repetir]=cod;
        }
    }

    while(cod!=0){
        printf("Ingrese cantidad de unidades: ");
        scanf("%d",&cant);
        while(cant<=0){
            printf("CANTIDAD INVALIDA.");
            printf("\nIngrese nuevamente la cantidad de unidades: ");
            scanf("%d",&cant);
        }
        vCantUni[repetir]+=cant;

       printf("Ingrese codigo del producto: ");
        scanf("%d",&cod);
        if(cod!=0){
            repetir=BuscarRepetido(v,cod,N);
            if(repetir!=-1)
            vCod[repetir]=cod;
        }
        while(repetir==-1 && cod!=0){
            printf("CODIGO INVALIDO.");
            printf("\nIngrese nuevamente el codigo del producto: ");
            scanf("%d",&cod);
            if(cod!=0){
                repetir=BuscarRepetido(v,cod,N);
                if(repetir!=-1)
                vCod[repetir]=cod;
            }
        }
    }
}

void MostrarVectores(int vCod[],int vCantUni[],int ce){
    int i;

    for(i=0;i<ce;i++){
        if(vCod[i]>0)
        printf("\nUnidades solicitadas del producto %d: %d unidades.",vCod[i],vCantUni[i]);
    }
}

int MayorCantUnidades(int vCod[],int vCantUni[],int ce){
    int i,mayor;
    mayor=vCantUni[0];

    for(i=0;i<ce;i++){
        if(vCantUni[i]>mayor)
        mayor=vCantUni[i];
    }

    return mayor;
}

int MenorCantUnidades(int vCod[],int vCantUni[],int ce){
    int i,menor;
    menor=vCantUni[0];

    for(i=0;i<ce;i++){
        if(vCantUni[i]<menor && vCantUni[i]!=0)
        menor=vCantUni[i];
    }

    return menor;
}

void MostrarMayoresYMenores(int vCod[],int vCantUni[],int mayor,int menor,int ce){
    int i;

    printf("\nLos productos con mayor cantidad de unidades solicitadas son: ");
    for(i=0;i<ce;i++){
        if(vCantUni[i]==mayor)
        printf("Prod. %d   ",vCod[i]);
    }

    printf("\nLos productos con menor cantidad de unidades solicitadas son: ");
    for(i=0;i<ce;i++){
        if(vCantUni[i]==menor)
        printf("Prod. %d   ",vCod[i]);
    }
}