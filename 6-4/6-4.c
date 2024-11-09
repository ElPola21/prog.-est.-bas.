/*Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo se llama precios.dat y fue generado utilizando la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    float precio;
    char desc[51];
}listaPrecios;

FILE * AbrirArchivo(char[],char[]);
void CargarArchivo(listaPrecios,FILE*);
void ActualizarPrecios(FILE*,float);
void LeerTexto(char[],int);
int main(){
    listaPrecios lista;
    FILE * pPrecios;
    float porcentaje;

    printf("Ingrese porcentaje de incremento: ");
    scanf("%f",&porcentaje);

    pPrecios=AbrirArchivo("precios.dat","r+b");
    //CargarArchivo(lista,pPrecios);
    ActualizarPrecios(pPrecios,porcentaje);
    fclose(pPrecios);
    
    return 0;
}

void ActualizarPrecios(FILE * p,float incremento){
    listaPrecios lis;

    rewind(p);
    fread(&lis,sizeof(listaPrecios),1,p);
    while(!feof(p)){
        lis.precio+=(lis.precio*incremento)/100;
        fseek(p,sizeof(listaPrecios)*-1,SEEK_CUR);
        fwrite(&lis,sizeof(listaPrecios),1,p);
        fflush(p);
        fread(&lis,sizeof(listaPrecios),1,p);
    }
}

void CargarArchivo(listaPrecios lis,FILE * p){
    printf("Ingrese codigo: ");
    scanf("%d",&lis.cod);
    while(lis.cod!=0){
        printf("Ingrese precio: ");
        scanf("%f",&lis.precio);

        printf("Ingrese descripcion: ");
        fflush(stdin);
        LeerTexto(lis.desc,51);

        fwrite(&lis,sizeof(listaPrecios),1,p);

        printf("\nIngrese codigo: ");
        scanf("%d",&lis.cod);
    }
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

FILE * AbrirArchivo(char archivo[],char modo[]){
    FILE * arch;

    arch=fopen(archivo,modo);
    if(arch==NULL){
        printf("ERROR.\n");
        getch();
        exit(1);
    }

    return arch;
}
