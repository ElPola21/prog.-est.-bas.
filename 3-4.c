/*Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad exacta
de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y la carga de
los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del día y por cada
venta se ingresa el código de producto y cantidad de unidades vendidas terminando con una cantidad igual
a 0. Se solicita:
a. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
b. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.*/

#include <stdio.h>
#include <string.h>
#define MAX 49
#define tam 4

int CargarPro(char[][tam],int[],int);
int BuscarRep(char[][tam],char[],int);
void RegVentas(char[][tam],int[],int);
void MostrarA(char[][tam],int[],int[],int);
void MostrarB(char[][tam],int[],int);
void OrdenarV(char[][tam],int [],int);
int main(){
    int vPrecio[MAX],cant,vVent[MAX];
    char cod[MAX][tam];

    cant=CargarPro(cod,vPrecio,MAX);
    RegVentas(cod,vVent,cant);
    MostrarA(cod,vPrecio,vVent,cant);
    MostrarB(cod,vPrecio,cant);

    return 0;
}

int CargarPro(char cod[][tam],int vP[],int max){
    int i=0,rep;

    printf("CARGA DE PRODUCTOS:\n");
    printf("\nIngrese codigo del producto: ");
    fflush(stdin);
    gets(cod[i]);
    while((strlen(cod[i])<3 || strlen(cod[i])>3)){
        printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo del producto: ");
        fflush(stdin);
        gets(cod[i]);
    }

    while(i<max && strcmpi(cod[i],"FIN")!=0){
        printf("Ingrese precio del producto: ");
        scanf("%d",&vP[i]);
        while(vP[i]<=0){
            printf("PRECIO INVALIDO.\nIngrese nuevamente el precio del producto: ");
            scanf("%d",&vP[i]);
        }
        i++;
        if(i<max){
            printf("Ingrese codigo del producto: ");
            fflush(stdin);
            gets(cod[i]);
            rep=BuscarRep(cod,cod[i],i);
            while(rep!=-1 || (strlen(cod[i])<3 || strlen(cod[i])>3)){
                printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo del producto: ");
                fflush(stdin);
                gets(cod[i]);
                rep=BuscarRep(cod,cod[i],i);
            }
        }
    }

    return i;
}

int BuscarRep(char c[][tam],char datoBuscado[],int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(strcmp(c[i],datoBuscado)==0)
        pos=i;
    }

    return pos;
}

void RegVentas(char cod[][tam],int vVent[],int ce){
    char codigo[tam];
    int i=0,ventas,rep;

    for(i=0;i<ce;i++){
        vVent[i]=0;
    }

    printf("REGISTRO VENTAS:\n");
    printf("\nIngrese numero del producto: ");
    fflush(stdin);
    gets(codigo);
    rep=BuscarRep(cod,codigo,ce);
    while(rep==-1){
        printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo del producto: ");
        fflush(stdin);
        gets(codigo);
        rep=BuscarRep(cod,codigo,ce);
    }

    printf("Ingrese cantidad de ventas: ");
    scanf("%d",&ventas);
    while(ventas<0 && ventas!=0){
        printf("CANTIDAD INVALIDA\nIngrese nuevamente la cantidad de ventas: ");
        scanf("%d",&ventas);
    }
    vVent[rep]+=ventas;

    while(ventas!=0){
        printf("\nIngrese numero del producto: ");
        fflush(stdin);
        gets(codigo);
        rep=BuscarRep(cod,codigo,ce);
        while(rep==-1){
            printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo del producto: ");
            fflush(stdin);
            gets(codigo);
            rep=BuscarRep(cod,codigo,ce);
        }

        printf("Ingrese cantidad de ventas: ");
        scanf("%d",&ventas);
        while(ventas<0 && ventas!=0){
            printf("CANTIDAD INVALIDA\nIngrese nuevamente la cantidad de ventas: ");
            scanf("%d",&ventas);
        }
        vVent[rep]+=ventas;
    }
}

void MostrarA(char c[][tam],int vP[],int vV[],int ce){
    int i,sumP=0,menorVen;
    char menor[tam];

    strcpy(menor,c[0]);
    menorVen=vV[0];

    for(i=0;i<ce;i++){
        sumP+=vP[i];
    }
    printf("\nLa recaudacion total del dia fue de: $%d",sumP);
    printf("\nLos productos que vendieron menor cantidad de unidades fueron:");
    for(i=0;i<ce;i++){
        if(menorVen>vV[i])
        menorVen=vV[i];
    }
    for(i=0;i<ce;i++){
        if(menorVen==vV[i])
        printf("%5s",c[i]);
    }
}

void MostrarB(char c[][tam],int vP[],int ce){
    int i;
    
    OrdenarV(c,vP,ce);
    printf("\n\n%5s %5s","PRODUCTO","PRECIO");
    for(i=0;i<ce;i++){
        printf("\n%5s %5d",c[i],vP[i]);
    }
}

void OrdenarV(char v[][tam],int vP[],int ce){
    int i,j,auxP;
    char aux[tam];

    for(i=0;i<ce-1;i++){
        for(j=0;j<ce-1-i;j++){
            if(strcmpi(v[j],v[j+1])>0){
                strcpy(aux,v[j]);
                strcpy(v[j],v[j+1]);
                strcpy(v[j+1],aux);
                auxP=vP[j];
                vP[j]=vP[j+1];
                vP[j+1]=auxP;
            }
        }
    }
}