/*Dada la estructura alumno:
struct alumno{
    char nom[31];
    int dni;
};
Realizar un programa que permita cargar alumnos y mostrarlos. Como máximo permitir 50 alumnos. El ingreso
finaliza con un DNI igual a 0. Realizar una función para cargar y otra para mostrar usando notación de punteros.*/

#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct{
    int dni;
    char nom[31];
}alumno;

int Carga(alumno[],int);
void LeerTexto(char[],int);
void Mostrar(alumno[],int);
int main(){
    alumno alu[MAX],*pAlu;
    int cant;

    pAlu=alu;
    cant=Carga(pAlu,MAX);
    if(!cant)
    printf("No se cargaron alumnos.");
    else
    Mostrar(pAlu,cant);

    return 0;
}

void Mostrar(alumno a[],int ce){
    int i;

    for(i=0;i<ce;i++){
        printf("\nDNI: %d\nNombre: %s\n",(a+i)->dni,(a+i)->nom);
    }
}

int Carga(alumno a[],int ce){
    int i=0;

    printf("Ingrese DNI del alumno: ");
    scanf("%d",&(a+i)->dni);
    while(((a+i)->dni<1000000 || (a+i)->dni>9999999) && (a+i)->dni!=0){
        printf("DNI invalido.\nIngrese nuevamente el DNI del alumno: ");
        scanf("%d",&(a+i)->dni);
    }

    while((a+i)->dni!=0 && i<ce){
        printf("Ingrese nombre: ");
        fflush(stdin);
        LeerTexto((a+i)->nom,31);
        while(!strlen((a+i)->nom) || strlen((a+i)->nom)>30){
            printf("NOMBRE INVALIDO.\nIngrese nuevamente el nombre: ");
            fflush(stdin);
            LeerTexto((a+i)->nom,31);
        }

        i++;

        printf("\nIngrese DNI del alumno: ");
        scanf("%d",&(a+i)->dni);
        while(((a+i)->dni<1000000 || (a+i)->dni>9999999) && (a+i)->dni!=0){
            printf("DNI invalido.\nIngrese nuevamente el DNI del alumno: ");
            scanf("%d",&(a+i)->dni);
        }
    }

    return i;
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