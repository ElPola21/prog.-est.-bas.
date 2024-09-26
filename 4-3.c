/*Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
a. Declarar un tipo de dato que contenga la información del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.
d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.
e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.*/

#include <stdio.h>
#include <string.h>
#define MAX 80

typedef struct{
    int DNI,nota1,nota2;
    char NombreC[81];
    float promedio;
}alumno;

int INGRESO(alumno[],int);
void RESULTADO(alumno[],int);
void INFORME_PROMO(alumno[],int);
int BuscarDato(alumno[],int,int);
int main(){
    alumno al[MAX];
    int cant;

    cant=INGRESO(al,MAX);
    RESULTADO(al,cant);
    INFORME_PROMO(al,cant);

    return 0;
}

int BuscarDato(alumno a[],int datoBuscado,int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(a[i].DNI==datoBuscado)
        pos=i;
    }

    return pos;
}

int INGRESO(alumno a[],int ce){
    int i=0,rep;

    printf("CARGA:\n\nIngrese DNI del alumno: ");
    scanf("%d",&a[i].DNI);
    while((a[i].DNI<1000000 || a[i].DNI>99999999) && a[i].DNI!=0){
        printf("DNI INVALIDO.\nIngrese nuevamente el DNI del alumno: ");
        scanf("%d",&a[i].DNI);
    }

    while(a[i].DNI!=0 && i<ce){
        printf("Ingrese apellido y nombre del alumno: ");
        fflush(stdin);
        gets(a[i].NombreC);
        while(strlen(a[i].NombreC)>80){
            printf("NOMBRE INVALIDO.\nIngrese nuevamente el apellido y nombre del alumno: ");
            fflush(stdin);
            gets(a[i].NombreC);
        }

        printf("Ingrese nota 1 del alumno %s: ",a[i].NombreC);
        scanf("%d",&a[i].nota1);
        while(a[i].nota1<=0 || a[i].nota1>10){
            printf("NOTA INVALIDA.\nIngrese nuevamente la nota 1 del alumno %s: ",a[i].NombreC);
            scanf("%d",&a[i].nota1);
        }
        printf("Ingrese nota 2 del alumno %s: ",a[i].NombreC);
        scanf("%d",&a[i].nota2);
        while(a[i].nota2<=0 || a[i].nota2>10){
            printf("NOTA INVALIDA.\nIngrese nuevamente la nota 2 del alumno %s: ",a[i].NombreC);
            scanf("%d",&a[i].nota2);
        }
        a[i].promedio=(float)(a[i].nota1+a[i].nota2)/2;
        printf("El promedio del alumno %s es %.2f.\n",a[i].NombreC,a[i].promedio);
        
        i++;

        if(i<ce){
            printf("\nIngrese DNI del alumno: ");
            scanf("%d",&a[i].DNI);
            rep=BuscarDato(a,a[i].DNI,i);
            while((a[i].DNI<1000000 || a[i].DNI>99999999 || rep!=-1) && a[i].DNI!=0){
                printf("DNI INVALIDO.\nIngrese nuevamente el DNI del alumno: ");
                scanf("%d",&a[i].DNI);
                rep=BuscarDato(a,a[i].DNI,i);
            }
        }
    }

    return i;
}

void RESULTADO(alumno a[],int ce){
    int i;

    printf("\nLos alumnos que aprobaron son:");
    for(i=0;i<ce;i++){
        if(a[i].nota1>=4 && a[i].nota2>=4)
        printf("%10s",a[i].NombreC);
    }

    printf("\nLos alumnos que reprobaron son:");
    for(i=0;i<ce;i++){
        if(a[i].nota1<4 || a[i].nota2<4)
        printf("%10s",a[i].NombreC);
    }
}

void INFORME_PROMO(alumno a[],int ce){
    int i;

    printf("\nLos alumnos que promocionaron son: ");
    for(i=0;i<ce;i++){
        if(a[i].nota1>=7 && a[i].nota2>=7)
        printf("%d - %s - %.2f",a[i].DNI,a[i].NombreC,a[i].promedio);
    }
}