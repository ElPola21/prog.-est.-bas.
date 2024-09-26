/*Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION     CANTIDAD UNIDADES VENDIDAS      IMPORTE TOTAL VENDIDO
  XXXXXXX                 XXXX                       $XXXXX,XX
*/

#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct{
    char codigo[6];
    float precio;
    char descripcion[31];
    int uVendidas;
    float impTotal;
}producto;

int Carga(producto[],int);
int BuscarRep(producto[],char[],int);
void VentasMes(producto[],producto[],int);
void PuntoA(producto[],producto[],int);
void PuntoB(producto[],int);
int main(){
    producto prod[MAX],nuevoMes[MAX];
    int cantP,i;

    cantP=Carga(prod,MAX);

    for(i=0;i<cantP;i++){
        nuevoMes[i]=prod[i];
    }

    for(i=0;i<cantP;i++){
        strcpy(nuevoMes[i].codigo,"0");
        nuevoMes[i].uVendidas=0;
    }

    VentasMes(prod,nuevoMes,cantP);
    PuntoA(prod,nuevoMes,cantP);
    PuntoB(nuevoMes,cantP);

    return 0;
}

int Carga(producto p[],int max){
    int i=0,rep;

    printf("CARGA PRODUCTOS:\n\n");

    printf("Ingrese el codigo del producto: ");
    fflush(stdin);
    gets(p[i].codigo);
    while(strlen(p[i].codigo)<5 || strlen(p[i].codigo)>5){
        printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo del producto: ");
        gets(p[i].codigo);
    }
    printf("Ingrese el precio del producto: ");
    scanf("%f",&p[i].precio);
    while(p[i].precio<=0){
        printf("PRECIO INVALIDO.\nIngrese nuevamente el precio del producto: ");
        scanf("%f",&p[i].precio);
    }
    printf("Ingrese descripcion del producto: ");
    fflush(stdin);
    gets(p[i].descripcion);
    while(strlen(p[i].descripcion)>30 && strcmpi(p[i].descripcion,"FIN")!=0){
        printf("DESCRIPCION INVALIDA.\nIngrese nuevamente la descripcion del producto: ");
        gets(p[i].descripcion);
    }

    while(strcmpi(p[i].descripcion,"FIN")!=0){
        printf("Ingrese cantidad de unidades vendidas: ");
        scanf("%d",&p[i].uVendidas);
        while(p[i].uVendidas<=0){
            printf("CANTIDAD INVALIDA.\nIngrese nuevamente la cantidad de unidades vendidas: ");
            scanf("%d",&p[i].uVendidas);
        }
        printf("Ingrese el importe total vendido: ");
        scanf("%f",&p[i].impTotal);
        while(p[i].impTotal!=(p[i].precio*p[i].uVendidas)){
            printf("IMPORTE TOTAL INVALIDO.\nIngrese nuevamente el importe total vendido: ");
            scanf("%f",&p[i].impTotal);
        }

        i++;

        if(i<max){
            printf("\nIngrese el codigo del producto: ");
            fflush(stdin);
            gets(p[i].codigo);
            rep=BuscarRep(p,p[i].codigo,i);
            while(strlen(p[i].codigo)<5 || strlen(p[i].codigo)>5 || rep!=-1){
                printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo del producto: ");
                gets(p[i].codigo);
                rep=BuscarRep(p,p[i].codigo,i);
            }
            printf("Ingrese el precio del producto: ");
            scanf("%f",&p[i].precio);
            while(p[i].precio<=0){
                printf("PRECIO INVALIDO.\nIngrese nuevamente el precio del producto: ");
                scanf("%f",&p[i].precio);
            }
            printf("Ingrese descripcion del producto: ");
            fflush(stdin);
            gets(p[i].descripcion);
            while(strlen(p[i].descripcion)>30 && strcmpi(p[i].descripcion,"FIN")!=0){
                printf("DESCRIPCION INVALIDA.\nIngrese nuevamente la descripcion del producto: ");
                gets(p[i].descripcion);
            }
        }
    }

    return i;
}

int BuscarRep(producto p[],char datoBuscado[],int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(strcmp(p[i].codigo,datoBuscado)==0)
        pos=i;
    }

    return pos;
}

void VentasMes(producto pOg[],producto pNuevo[],int ce){
    int i,pos,cant=1;
    char cod[6];

    printf("\n\nVENTAS DEL NUEVO MES:\n\n");

    while(cant!=0){
        printf("Ingrese codigo del producto: ");
        fflush(stdin);
        gets(cod);
        pos=BuscarRep(pOg,cod,ce);
        while(pos==-1){
            printf("CODIGO NO ENCONTRADO.\nIngrese nuevamente el codigo del producto: ");
            fflush(stdin);
            gets(cod);
            pos=BuscarRep(pOg,cod,ce);
        }
        strcpy(pNuevo[pos].codigo,cod);
        printf("Ingrese la cantidad pedida: ");
        scanf("%d",&cant);
        while(cant<0 && cant!=0){
            printf("CANTIDAD INVALIDA.\nIngrese nuevamente la cantidad pedida: ");
            scanf("%d",&cant);
        }
        if(cant!=0)
        pNuevo[pos].uVendidas=cant;
    }
}

void PuntoA(producto pOg[],producto pNuevo[],int ce){
    int i;

    for(i=0;i<ce;i++){
        if(strcmpi(pNuevo[i].codigo,"0")==0)
        pNuevo[i].impTotal=0;
        else
        pNuevo[i].impTotal=(float)((pNuevo[i].precio)*(pNuevo[i].uVendidas));
    }
}

void PuntoB(producto pNuevo[],int ce){
    int i;

    printf("%15s %35s %35s","DESCRIPCION","CANTIDAD DE UNIDADES VENDIDAS","IMPORTE TOTAL VENDIDO");
    for(i=0;i<ce;i++){
        printf("\n%11s %24d %45f",pNuevo[i].descripcion,pNuevo[i].uVendidas,pNuevo[i].impTotal);
    }
}