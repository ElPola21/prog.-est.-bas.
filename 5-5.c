/* Al programa anterior agregarle una función que reciba la dirección de inicio del vector y un número a buscar
y retorne un puntero al dato encontrado o NULL sino lo encuentra. En el main agregar un proceso de
búsqueda que se repita hasta ingresar un número negativo o cero a buscar. Si se lo encontró se debe
indicar en que posición del vector estaba (calcular dicha posición utilizando la dirección retornada)*/

#include <stdio.h>

void Carga(int[],int);
void Mostrar(int[],int);
int* Agregado(int[],int,int);
int main(){
    int v[10],num,*p;

    Carga(v,10);
    Mostrar(v,10);
    printf("\nIngrese numero a buscar: ");
    scanf("%d",&num);
    while(num>0){
        p=Agregado(v,num,10);
        if(p!=NULL)
        printf("Posicion %d.",p-v);
        else
        printf("No se encuentra en el vector.");

        printf("\nIngrese numero a buscar: ");
        scanf("%d",&num);
    }

    return 0;
}

int* Agregado(int v[],int dato,int ce){
    int i,*p=NULL;

    for(i=0;i<ce;i++){
        if(*(v+i)==dato){
            p=v+i;
        }
    }

    return p;
}

void Carga(int v[],int ce){
    int i;

    for(i=0;i<ce;i++){
        printf("Ingrese entero: ");
        scanf("%d",v+i);
    }
}

void Mostrar(int v[],int ce){
    int i;

    for(i=0;i<ce;i++){
        printf("%6d",*(v+i));
    }
}