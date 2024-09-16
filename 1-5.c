/*Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe
ordenar de forma ascendente la colección con dichos códigos para permitir realizar búsquedas binarias.
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código
de artículo y cantidad. (EN LOS 3 UN VECTOR)
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una
venta de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
CANT UNIDADES        CÓDIGO
     XXX              XXX
     XXX              XXX
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/

#include <stdio.h>
#define N 9

int BuscarRepetido(int[],int,int);
int BusquedaBinaria(int[],int,int);
void CargarVCodProd(int[],int);
void CargarVCodVendedor(int[],int);
void OrdenarVCodProd(int[],int);
void CargarVCant(int[],int[],int[],int[],int);
void OrdenarVMayorAMenor(int[],int[],int);
void MostrarPuntoA(int[],int[],int);
void MostrarPuntoB(int[],int[],int[],int);
int main(){
    int vCodProd[N],vCodVendedor[5],vVendCant[5]={0},vCant[N]={0};

    CargarVCodProd(vCodProd,N);
    OrdenarVCodProd(vCodProd,N);
    CargarVCodVendedor(vCodVendedor,5);
    CargarVCant(vCodProd,vCodVendedor,vVendCant,vCant,N);
    OrdenarVMayorAMenor(vCant,vCodProd,N);
    MostrarPuntoA(vCant,vCodProd,N);
    printf("\n\n");
    MostrarPuntoB(vCant,vCodVendedor,vVendCant,N);

    return 0;
}

void CargarVCodVendedor(int v[],int ce){
    int i;

    for(i=0;i<ce;i++){
        v[i]=1001+i;
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

void CargarVCodProd(int v[],int ce){
    int i,repetir;

    for(i=0;i<ce;i++){
        printf("Ingrese codigo de producto: ");
        scanf("%d",&v[i]);
        repetir=BuscarRepetido(v,v[i],i);
        while(v[i]<100 || v[i]>999 || repetir!=-1){
            printf("CODIGO INVALIDO");
            printf("\nIngrese nuevamente el codigo de producto: ");
            scanf("%d",&v[i]);
            repetir=BuscarRepetido(v,v[i],i);
        }
    }
}

void OrdenarVCodProd(int v[],int ce){
    int aux,i,cota=ce-1,desordenado=1;

    while(desordenado){
        desordenado=0;
        for(i=0;i<cota;i++){
            if(v[i]>v[i+1]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                desordenado=i;
            }
        }
        cota=desordenado;
    }
}

int BusquedaBinaria(int v[],int buscado,int ce){
    int pos=-1,li=0,ls=ce-1,med;

    while(pos==-1 && li<=ls){
        med=(li+ls)/2;
        if(v[med]==buscado)
        pos=med;
        else if(buscado>v[med])
        li=med+1;
        else
        ls=med-1;
    }
    return pos;
}

void CargarVCant(int vProd[],int vVend[],int vVendCant[],int vCant[],int ce){
    int vendedor,art,cant,repetir1,repetir2;

    printf("Ingrese codigo de vendedor: ");
    scanf("%d",&vendedor);
    repetir1=BusquedaBinaria(vVend,vendedor,5);
    while(repetir1==-1 && vendedor!=0){
        printf("CODIGO INVALIDO.");
        printf("\nIngrese nuevamente el codigo de vendedor: ");
        scanf("%d",&vendedor);
        repetir1=BusquedaBinaria(vVend,vendedor,5);
    }

    while(vendedor!=0){
        printf("Ingrese codigo de articulo: ");
        scanf("%d",&art);
        repetir2=BusquedaBinaria(vProd,art,ce);
        while(repetir2==-1){
            printf("CODIGO INVALIDO.");
            printf("\nIngrese nuevamente el codigo de articulo: ");
            scanf("%d",&art);
            repetir2=BusquedaBinaria(vProd,art,ce);
        }

        printf("Ingrese cantidad de ventas del articulo %d: ",vProd[repetir2]);
        scanf("%d",&cant);
        while(cant<0){
            printf("CANTIDAD INVALIDA.");
            printf("\nIngrese nuevamente la cantidad de ventas del articulo %d: ",vProd[repetir2]);
            scanf("%d",&cant);
        }
        vCant[repetir2]+=cant;
        vVendCant[repetir1]+=cant;

        printf("Ingrese codigo de vendedor: ");
        scanf("%d",&vendedor);
        repetir1=BusquedaBinaria(vVend,vendedor,5);
        while(repetir1==-1 && vendedor!=0){
            printf("CODIGO INVALIDO.");
            printf("\nIngrese nuevamente el codigo de vendedor: ");
            scanf("%d",&vendedor);
            repetir1=BusquedaBinaria(vVend,vendedor,5);
        }
    }
}

void OrdenarVMayorAMenor(int vCant[],int vCodProd[],int ce){
    int aux1,aux2,i,cota=ce-1,desordenado=1;

    while(desordenado){
        desordenado=0;
        for(i=0;i<cota;i++){
            if(vCant[i]<vCant[i+1]){
                aux1=vCant[i];
                vCant[i]=vCant[i+1];
                vCant[i+1]=aux1;
                aux2=vCodProd[i];
                vCodProd[i]=vCodProd[i+1];
                vCodProd[i+1]=aux2;
                desordenado=i;
            }
        }
        cota=desordenado;
    }
}

void MostrarPuntoA(int vCant[],int vArt[],int ce){
    int i;

    printf("CANT UNIDADES       CODIGO");
    for(i=0;i<ce;i++){
        printf("\n    %d                %d",vCant[i],vArt[i]);
    }
}

void MostrarPuntoB(int vCant[],int vVend[],int vVendCant[],int ce){
    int i,menor;

    menor=vVendCant[0];
    for(i=0;i<ce;i++){
        if(vVendCant[i]<menor)
        menor=vVendCant[i];
    }

    printf("Los vendedores que realizaron menor cantidad de ventas fueron con %d ventas: ",menor);
    for(i=0;i<ce;i++){
        if(vVendCant[i]==menor)
        printf("%6d",vVend[i]);
    }
}