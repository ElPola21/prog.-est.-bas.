/*Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor*/

#include <stdio.h>
#include <string.h>
#define MAX 50

int CargarV(char[][31],int[],int);
int BuscarRepetido(int[],int,int);
void CargarAlumno(char[][31],int[],int);
int BuscarAlumno(char[][31],char[],int);
void OrdenarV(char[][31],int);
void MostrarB(char[][31],int);
int main(){
    int vDNI[MAX],cant;
    char vAlumnos[MAX][31];

    cant=CargarV(vAlumnos,vDNI,MAX);
    CargarAlumno(vAlumnos,vDNI,cant);
    OrdenarV(vAlumnos,cant);
    MostrarB(vAlumnos,cant);

    return 0;
}

int CargarV(char v[][31],int vDNI[],int max){
    int i=0,rep;

    printf("Ingrese nombre: ");
    fflush(stdin);
    fgets(v[i],31,stdin);
    v[i][strlen(v[i])-1]='\0';

    if(strcmp(v[i],"FIN")!=0){
        printf("Ingrese DNI del alumno: ");
        scanf("%d",&vDNI[i]);
        while(vDNI[i]<1000000 || vDNI[i]>99999999){
            printf("DNI INVALIDO.\nIngrese nuevamente el DNI del alumno: ");
            scanf("%d",&vDNI[i]);
        }
    }
    i++;
    while(i<max && strcmp(v[i-1],"FIN")!=0){
        printf("Ingrese nombre: ");
        fflush(stdin);
        fgets(v[i],31,stdin);
        v[i][strlen(v[i])-1]='\0';

        if(strcmp(v[i],"FIN")!=0){
            printf("Ingrese DNI del alumno: ");
            scanf("%d",&vDNI[i]);
            rep=BuscarRepetido(vDNI,vDNI[i],i);
            while(vDNI[i]<1000000 || vDNI[i]>99999999 || rep!=-1){
                printf("DNI INVALIDO.\nIngrese nuevamente el DNI del alumno: ");
                scanf("%d",&vDNI[i]);
                rep=BuscarRepetido(vDNI,vDNI[i],i);
            }
        }
        i++;
    }

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

int BuscarAlumno(char v[][31],char datoBuscado[],int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(strcmp(v[i],datoBuscado)==0)
        pos=i;
    }

    return pos;
}

void CargarAlumno(char vAl[][31],int vDNI[],int max){
    char alumno[31];
    int rep;

    while(strcmp(alumno,"NOBUSCARMAS")!=0){
        printf("\nIngrese alumno: ");
        fflush(stdin);
        fgets(alumno,31,stdin);
        alumno[strlen(alumno)-1]='\0';
        rep=BuscarAlumno(vAl,alumno,max);
        if(rep==-1 && strcmp(alumno,"NOBUSCARMAS")!=0)
        printf("NO SE REGISTRO ESE ALUMNO");
        else if(strcmp(alumno,"NOBUSCARMAS")!=0)
        printf("DNI: %d",vDNI[rep]);
    }
}

void OrdenarV(char v[][31],int ce){
    int i,j;
    char aux[31];

    for(i=0;i<ce-1;i++){
        for(j=0;j<ce-1-i;j++){
            if(strcmpi(v[j],v[j+1])>0){
                strcpy(aux,v[j]);
                strcpy(v[j],v[j+1]);
                strcpy(v[j+1],aux);
            }
        }
    }
}

void MostrarB(char v[][31],int ce){
    int i;

    for(i=0;i<ce;i++){
        if(strcmp(v[i],"FIN")!=0)
        printf("\n%d: %s",i+1,v[i]);
    }
}