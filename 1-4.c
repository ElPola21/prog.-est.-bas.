/*Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado
de mayor a menor por nota.*/

#include <stdio.h>
#define N 6

int CargarVectores(int[],int[],int);
int BuscarRepetido(int[],int,int);
void OrdenarVectorNota(int[],int[],int);
void MostrarListado(int[],int[],int);
int main(){
    int vDNI[N],vNota[N],tamanio;

    tamanio=CargarVectores(vDNI,vNota,N);
    OrdenarVectorNota(vDNI,vNota,tamanio);
    MostrarListado(vDNI,vNota,tamanio);

    return 0;
}

int CargarVectores(int vDNI[],int vNota[],int maxAlu){
    int i=0,repetir;

    printf("Ingrese DNI del alumno: ");
    scanf("%d",&vDNI[i]);
    while((vDNI[i]<1000000 || vDNI[i]>99999999) && vDNI[i]>=0){
        printf("DNI INVALIDO.");
        printf("\nIngrese nuevamente el DNI del alumno: ");
        scanf("%d",&vDNI[i]);
    }

    while(vDNI[i]>0 && i<6){
        printf("Ingrese nota del alumno: ");
        scanf("%d",&vNota[i]);
        while(vNota[i]<1 || vNota[i]>10){
            printf("NOTA INVALIDA.");
            printf("\nIngrese nuevamente la nota del alumno: ");
            scanf("%d",&vNota[i]);
        }
        i++;
        if(i<6){
            printf("Ingrese DNI del alumno: ");
            scanf("%d",&vDNI[i]);
            repetir=BuscarRepetido(vDNI,vDNI[i],i);
            while((vDNI[i]<1000000 || vDNI[i]>99999999) && vDNI[i]>=0 || repetir>-1){
                printf("DNI INVALIDO.");
                printf("\nIngrese nuevamente el DNI del alumno: ");
                scanf("%d",&vDNI[i]);
                repetir=BuscarRepetido(vDNI,vDNI[i],i);
            }
        }
    }
    printf("\n");

    return i;
}

int BuscarRepetido(int v[],int datoBuscado,int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(v[i]==datoBuscado)
        pos=i;
    }

    return pos;
}

void OrdenarVectorNota(int vDNI[],int vNota[],int ce){
    int auxDNI,auxNota,i,cota=ce-1,desordenado=1;

    while(desordenado){
        desordenado=0;
        for(i=0;i<cota;i++){
            if(vNota[i]<vNota[i+1]){
                auxNota=vNota[i];
                vNota[i]=vNota[i+1];
                vNota[i+1]=auxNota;
                auxDNI=vDNI[i];
                vDNI[i]=vDNI[i+1];
                vDNI[i+1]=auxDNI;
                desordenado=i;
            }
        }
        cota=desordenado;
    }
}

void MostrarListado(int vDNI[],int vNota[],int ce){
    int i;

    for(i=0;i<ce;i++){
        printf("\nDNI: %d  -  Nota: %d",vDNI[i],vNota[i]);
    }
}