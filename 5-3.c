/*Realizar una función que permita ingresar por teclado un valor entero, un flotante y un carácter. La función
no debe retornar ningún valor. Las variables se declaran y se muestran en el programa principal.*/

#include <stdio.h>

void Carga(int*,float*,char*);
int main(){
    int a;
    float b;
    char c;

    Carga(&a,&b,&c);
    printf("\n%d - %.2f - %c",a,b,c);

    return 0;
}

void Carga(int *a,float *b,char *c){
    int ent;
    float flo;
    char car;

    printf("Ingrese entero: ");
    scanf("%d",a);
    printf("Ingrese flotante: ");
    scanf("%f",b);
    printf("Ingrese caracter: ");
    fflush(stdin);
    scanf("%c",c);
}