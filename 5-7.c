/*Dada la siguiente estructura:
typedef struct{
    int codigo;
    char descripcion[31];
    float precio;
}sProductos;
a. Crear una variable del tipo sProductos
b. Ingresar por teclado los campos
c. Crear un puntero a dicha estructura
d. Mostrar los datos ingresados mediante el puntero utilizando las dos nomenclaturas posibles*/

#include <stdio.h>
#include <string.h>

typedef struct{
    int codigo;
    char descripcion[31];
    float precio;
}sProductos;

void LeerTexto(char[],int);
int main(){
    sProductos prod,*pProd;

    printf("Ingrese codigo: ");
    scanf("%d",&prod.codigo);
    printf("Ingrese descripcion: ");
    fflush(stdin);
    LeerTexto(prod.descripcion,31);
    printf("Ingrese precio: ");
    scanf("%f",&prod.precio);

    pProd=&prod;

    printf("El codigo es %d.\nLa descripcion es %s.\nEl precio es %.2f.",(*pProd).codigo,pProd->descripcion,pProd->precio);

    return 0;
}

void LeerTexto (char texto[], int largo){
    int i=0;

    fgets(texto, largo, stdin);
    while (texto[i]!='\0'){
        if (texto[i]=='\n')
        texto[i]='\0';
        else
        i++;
    }
}