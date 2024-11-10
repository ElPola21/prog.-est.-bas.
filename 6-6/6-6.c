/*Dado el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Realizar un programa que permita eliminar productos dado su código*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    float precio;
    char desc[51];
}producto;

FILE * AbrirArchivo(char[],char[]);
void CargarCopia(FILE*,FILE*,int);
int main(){
    producto prod;
    FILE *pProd,*pCopia;
    int codEliminar;

    pProd=AbrirArchivo("productos.dat","rb");
    pCopia=AbrirArchivo("copia.dat","wb");

    printf("Ingrese codigo del producto a eliminar: ");
    scanf("%d",&codEliminar);
    CargarCopia(pProd,pCopia,codEliminar);
    
    fclose(pCopia);
    fclose(pProd);

    remove("productos.dat");
    rename("copia.dat","productos.dat");

    pProd=AbrirArchivo("productos.dat","rb");
    fread(&prod,sizeof(producto),1,pProd);
    while(!feof(pProd)){
        printf("%d-%.2f-%s\n",prod.cod,prod.precio,prod.desc);
        fread(&prod,sizeof(producto),1,pProd);
    }

    return 0;
}

void CargarCopia(FILE *pP,FILE *pC,int codElim){
    producto prod;

    fread(&prod,sizeof(producto),1,pP);
    while(!feof(pP)){
        if(codElim!=prod.cod)
        fwrite(&prod,sizeof(producto),1,pC);
        fread(&prod,sizeof(producto),1,pP);
    }
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
