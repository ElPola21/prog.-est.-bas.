/*Se desea realizar un programa que permita actualizar la lista de precios de una empresa en forma individual
a cada uno de sus productos.
Los productos que están guardados en el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación
de precios finaliza con un código de producto igual a 0.
Al finalizar exportar a un archivo con formato de texto (.csv) para que la lista de precios pueda ser
visualizada directamente utilizando un programa de planillas de cálculo como por ejemplo el Excel.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    float precio;
    char descripcion[51];
}producto;

FILE * AbrirArchivo(char[],char[]);
void LeerTexto(char[],int);
void ActualizarPrecios(FILE*);
int BuscarDato(int,FILE*);
int main(){
    producto prod;
    FILE *pProd,*exportar;

    pProd=AbrirArchivo("precios.dat","r+b");
    ActualizarPrecios(pProd);
    fclose(pProd);

    pProd=AbrirArchivo("precios.dat","r+b");
    exportar=AbrirArchivo("precios.csv","wt");
    fprintf(exportar,"CODIGO;PRECIO;DESC\n");
    fread(&prod,sizeof(producto),1,pProd);
    while(!feof(pProd)){
        fprintf(exportar,"%d;%.2f;%s\n",prod.cod,prod.precio,prod.descripcion);
        fread(&prod,sizeof(producto),1,pProd);
    }
    fclose(exportar);
    fclose(pProd);

    return 0;
}

void ActualizarPrecios(FILE *p){
    producto prod;
    int cod,pos,i;
    float nPrecio;

    printf("Ingrese codigo: ");
    scanf("%d",&cod);
    while(cod!=0){
        pos=BuscarDato(cod,p);
        if(pos!=-1){
            printf("Ingrese nuevo precio: ");
            scanf("%f",&nPrecio);
            
            fseek(p,sizeof(producto)*pos,SEEK_SET);
            fread(&prod,sizeof(producto),1,p);
            prod.precio=nPrecio;
            fseek(p,sizeof(producto)*pos,SEEK_SET);
            fwrite(&prod,sizeof(producto),1,p);
            fflush(p);
            printf("Precio actualizado.");
        }
        else
        printf("No se encontro el codigo.");

        printf("\nIngrese codigo: ");
        scanf("%d",&cod);
    }
}

int BuscarDato(int dato,FILE *p){
    producto regProd;
    int pos=-1,i=0;
    
    rewind(p);
    fread(&regProd,sizeof(producto),1,p);
    while(!feof(p) && pos==-1){
        if(dato==regProd.cod)
        pos=i;
        else{
            fread(&regProd,sizeof(producto),1,p);
            i++;
        }
    }

    return pos;
}

FILE * AbrirArchivo(char archivo[],char modo[]){
    FILE *arch;

    arch=fopen(archivo,modo);
    if(arch==NULL){
        printf("Error.\n");
        getch();
        exit(1);
    }

    return arch;
}
