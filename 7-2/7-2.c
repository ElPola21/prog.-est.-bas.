/*Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa. El archivo se
encuentra ordenado por sucursal y contiene la siguiente estructura:
• Sucursal (15 caracteres máximo)
• Código de producto (entero)
• Cantidad (entero)
Por otro lado, se dispone de un archivo de los productos que vende la empresa y el estado del stock al mes
pasado con la siguiente estructura:
• Código de producto (entero)
• Descripción (20 caracteres máximo)
• Precio (float)
• Stock (entero)
• Punto de pedido (entero)
• Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos, pero sí se sabe que no hay más de 200. Se desea:
a. Mostrar el importe total vendido en cada sucursal.
b. Mostrar la recaudación total de la empresa en el mes.
c. Determinar la sucursal que vendió mayor cantidad de productos.
d. Actualizar el archivo de productos con el nuevo stock.
e. Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse
(código y cantidad) de aquellos productos que al finalizar de procesar las ventas del mes queden
con stock menor al punto de pedido. */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    char sucursal[16];
    int codP;
    int cant;
}ventas;

typedef struct{
    int codP;
    char desc[21];
    float precio;
    int stock;
    int puntoP;
    int cantP;
}productos;

typedef struct{
    int codP;
    int cant;
}pedidos;

FILE *AbrirArchivo(char[],char[]);
void LeerTexto(char[],int);
void PuntoAyB(FILE*,FILE*);
void PuntoC(FILE*);
void PuntoDyE(FILE*,FILE*);
int main(){
    ventas vent;
    productos prod;
    pedidos ped;
    FILE *pVent,*pProd,*pPedidos;

    pProd=AbrirArchivo("Productos.dat","rb");
    pVent=AbrirArchivo("Ventas.dat","rb");

    rewind(pProd);
    rewind(pVent);
    PuntoAyB(pVent,pProd);

    rewind(pVent);
    PuntoC(pVent);

    fclose(pProd);
    fclose(pVent);
    
    pProd=AbrirArchivo("Productos.dat","r+b");
    pVent=AbrirArchivo("Ventas.dat","rb");
    PuntoDyE(pVent,pProd);
    fclose(pProd);
    fclose(pVent);

    pPedidos=AbrirArchivo("Pedidos.dat","rb");
    fread(&ped,sizeof(pedidos),1,pPedidos);
    while(!feof(pPedidos)){
        printf("\n\nCodigo: %d",ped.codP);
        printf("\nCantidad: %d",ped.cant);
        fread(&ped,sizeof(pedidos),1,pPedidos);
    }
    fclose(pPedidos);

    return 0;
}

void PuntoDyE(FILE *pV,FILE *pP){
    productos p;
    ventas v;
    pedidos ped;
    int prodEncontrado;
    FILE * pPedidos;

    pPedidos=AbrirArchivo("Pedidos.dat","wb");
    printf("\n\n---PUNTO D---");
    fread(&v,sizeof(ventas),1,pV);
    while(!feof(pV)){
        prodEncontrado=0;
        rewind(pP);
        fread(&p,sizeof(productos),1,pP);
        while(!feof(pP) && !prodEncontrado){
            if(v.codP==p.codP){
                p.stock-=v.cant;
                if(p.stock<0)
                p.stock=0;
                fseek(pP,sizeof(productos)*-1,SEEK_CUR);
                fwrite(&p,sizeof(productos),1,pP);
                fflush(pP);
                prodEncontrado=1;

                if(p.stock<p.puntoP){
                    ped.codP=p.codP;
                    ped.cant=p.cantP;
                    fwrite(&ped,sizeof(pedidos),1,pPedidos);
                }
            }
            fread(&p,sizeof(productos),1,pP);
        }    
        fread(&v,sizeof(ventas),1,pV);
    }
    fclose(pPedidos);
    fclose(pP);
    
    pP=AbrirArchivo("Productos.dat","rb");
    fread(&p,sizeof(productos),1,pP);
    while(!feof(pP)){
        printf("\n\n%d\n%s\n%f\n%d\n%d\n%d",p.codP,p.desc,p.precio,p.stock,p.puntoP,p.cantP);
        fread(&p,sizeof(productos),1,pP);
    }
}

void PuntoC(FILE *pV){
    ventas v;
    char sucAnt[16],sucMay[16];
    int CantP=0,cantMay=0;

    printf("\n\n---PUNTO C---");
    fread(&v,sizeof(ventas),1,pV);
    strcpy(sucAnt,v.sucursal);
    while(!feof(pV)){
        if(strcmpi(sucAnt,v.sucursal)!=0){
            if(cantMay<CantP){
                strcpy(sucMay,v.sucursal);
                cantMay=CantP;
            }
            CantP=0;
            strcpy(sucAnt,v.sucursal);
        }
        CantP+=v.cant;
        fread(&v,sizeof(ventas),1,pV);
    }
    if(cantMay<CantP){
        strcpy(sucMay,v.sucursal);
        cantMay=CantP;
    }
    printf("\nLa sucursal que vendio mayor cantidad de productos:\nSucursal %s con %d productos vendidos.",sucMay,cantMay);
}

void PuntoAyB(FILE *pV,FILE*pP){
    ventas v;
    productos p;
    char sucAnt[16];
    int aux=0,productoEncontrado;
    float importeTSuc=0,recaudacionT=0;

    printf("---PUNTO A---");
    fread(&v,sizeof(ventas),1,pV);
    while(!feof(pV)){
        if(!aux){
            aux=1;
            strcpy(sucAnt,v.sucursal);
        }
        if(strcmpi(sucAnt,v.sucursal)!=0){
            printf("\nSucursal: %s\nImporte total: $%.2f\n",sucAnt,importeTSuc);
            importeTSuc=0;
            strcpy(sucAnt,v.sucursal);
        }
        productoEncontrado=0;
        rewind(pP);
        while(!feof(pP) && !productoEncontrado){
            if(p.codP==v.codP){
                recaudacionT+=(float)v.cant*p.precio;
                importeTSuc+=(float)v.cant*p.precio;
                productoEncontrado=1;
            }
            fread(&p,sizeof(productos),1,pP);
        }
        
        rewind(pP);
        fread(&v,sizeof(ventas),1,pV);
    }

    if(aux)
    printf("\nSucursal: %s\nImporte total: $%.2f\n",sucAnt,importeTSuc);
    printf("\n---PUNTO B---\nLa recaudacion total de la empresa es $%.2f.",recaudacionT);
}

FILE *AbrirArchivo(char archivo[],char modo[]){
    FILE *arch;

    arch=fopen(archivo,modo);
    if(arch==NULL){
        printf("Error.\n");
        getch();
        exit(1);
    }

    return arch;
}

void LeerTexto(char texto[],int largo){
    int i=0;
    
    fgets(texto,largo,stdin);
    while(texto[i]!='\0'){
        if(texto[i]=='\n')
        texto[i]='\0';
        else
        i++;
    }
}
