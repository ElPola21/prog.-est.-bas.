/*La fórmula 1 está compuesta por 20 pilotos y en el año se corrieron 23 carreras.
a) Se desea ingresar la información de cada piloto (nombre, escudería) y la posición en la que llegó dicho
piloto en cada una de las 23 carreras (1 a 20).
b) Luego se debe poder elegir el número de carrera del año y mostrar el listado de los 10 primeros puestos
de dicha carrera. Repetir el proceso con distintos números de carreras hasta ingresar un 0 como número
de carrera.*/

#include <stdio.h>
#include <string.h>
#define CAR 3
#define PIL 3

typedef struct{
    char nombre[43];
    char escuderia[33];
    int posicion;
}piloto;

void CargaPilotos(piloto[][CAR],int,int);
int BuscarDato(piloto[][CAR],int,int,int);
void Ordenar(piloto[][CAR],int,int);
void ElegirCarrera(piloto[][CAR]);
int main(){
    piloto p[PIL][CAR];
    int i,j;

    CargaPilotos(p,PIL,CAR);
    Ordenar(p,PIL,CAR);
    ElegirCarrera(p);

    return 0;
}

int BuscarDato(piloto p[][CAR],int datoBuscado,int filas,int col){
    int i,pos=-1;

    for(i=0;i<filas;i++){
        if(p[i][col].posicion==datoBuscado)
        pos=i;
    }

    return pos;
}

void Ordenar(piloto p[][CAR],int filas,int col){
    int i,j,auxPos,cota=filas-1,desordenado=1;
    char auxNom[43],auxEsc[33];

    while(desordenado){
        desordenado=0;
        for(j=0;j<col;j++){
            for(i=0;i<cota;i++){
                if(p[i][j].posicion>p[i+1][j].posicion){
                    auxPos=p[i][j].posicion;
                    p[i][j].posicion=p[i+1][j].posicion;
                    p[i+1][j].posicion=auxPos;
                    strcpy(auxNom,p[i][j].nombre);
                    strcpy(p[i][j].nombre,p[i+1][j].nombre);
                    strcpy(p[i+1][j].nombre,auxNom);
                    strcpy(auxEsc,p[i][j].escuderia);
                    strcpy(p[i][j].escuderia,p[i+1][j].escuderia);
                    strcpy(p[i+1][j].escuderia,auxEsc);
                    desordenado=i;
                }
            }
        }
        cota=desordenado;
    }
}
                                  //  piloto, numCarrera
void CargaPilotos(piloto p[][CAR],int filas,int col){
    int i=0,j=0,rep;
    char nombre[43],esc[33];

    printf("\nIngrese nombre del piloto: ");
    fflush(stdin);
    fgets(nombre,43,stdin);
    nombre[strlen(nombre)-1]='\0';
    while(strlen(nombre)>40 || strlen(nombre)==0){
        printf("NOMBRE INVALIDO.\nIngrese nuevamente el nombre del piloto: ");
        fflush(stdin);
        fgets(nombre,43,stdin);
        nombre[strlen(nombre)-1]='\0';   
    }

    printf("Ingrese escuderia de %s: ",nombre);
    fflush(stdin);
    fgets(esc,33,stdin);
    esc[strlen(esc)-1]='\0';
    while(strlen(esc)>30 || strlen(esc)==0){
        printf("ESCUDERIA INVALIDA.\nIngrese nuevamente la escuderia de %s: ",nombre);
        fflush(stdin);
        fgets(esc,33,stdin);
        esc[strlen(esc)-1]='\0';
    }
    
    for(j=0;j<col;j++){
        strcpy(p[i][j].nombre,nombre);
        strcpy(p[i][j].escuderia,esc);
        printf("Ingrese posicion de %s en la carrera %d: ",nombre,j+1);
        scanf("%d",&p[i][j].posicion);
        while(p[i][j].posicion<0 || p[i][j].posicion>20){
            printf("POSICION INVALIDA.\nIngrese nuevamente la posicion de %s en la carrera %d: ",nombre,j+1);
            scanf("%d",&p[i][j].posicion);
        }
    }

    for(i=1;i<filas;i++){
        printf("\nIngrese nombre del piloto: ");
        fflush(stdin);
        fgets(nombre,43,stdin);
        nombre[strlen(nombre)-1]='\0';
        while(strlen(nombre)>40 || strlen(nombre)==0){
            printf("NOMBRE INVALIDO.\nIngrese nuevamente el nombre del piloto: ");
            fflush(stdin);
            fgets(nombre,43,stdin);
            nombre[strlen(nombre)-1]='\0';
        }

        printf("Ingrese escuderia de %s: ",nombre);
        fflush(stdin);
        fgets(esc,33,stdin);
        esc[strlen(esc)-1]='\0';
        while(strlen(esc)>30 || strlen(esc)==0){
            printf("ESCUDERIA INVALIDA.\nIngrese nuevamente la escuderia de %s: ",nombre);
            fflush(stdin);
            fgets(esc,33,stdin);
            esc[strlen(esc)-1]='\0';
        }
        
        for(j=0;j<col;j++){
            strcpy(p[i][j].nombre,nombre);
            strcpy(p[i][j].escuderia,esc);
            printf("Ingrese posicion de %s en la carrera %d: ",nombre,j+1);
            scanf("%d",&p[i][j].posicion);
            rep=BuscarDato(p,p[i][j].posicion,i,j);
            while(p[i][j].posicion<0 || p[i][j].posicion>20 || rep!=-1){
                printf("POSICION INVALIDA.\nIngrese nuevamente la posicion de %s en la carrera %d: ",nombre,j+1);
                scanf("%d",&p[i][j].posicion);
                rep=BuscarDato(p,p[i][j].posicion,i,j);
            }
        }
    }
}

void ElegirCarrera(piloto p[][CAR]){
    int i,carrera;

    printf("\n\nIngrese numero de carrera: ");
    scanf("%d",&carrera);
    while((carrera<1 || carrera>23) && carrera!=0){
        printf("NUMERO INVALIDO.\nIngrese nuevamente el numero de carrera: ");
        scanf("%d",&carrera);
    }

    while(carrera!=0){
        printf("\nLos primeros 10 puestos son:\n%8s %14s","NOMBRE","ESCUDERIA");
        for(i=0;i<3;i++){
            printf("\n%8s %14s",p[i][carrera-1].nombre,p[i][carrera-1].escuderia);
        }

        printf("\nIngrese numero de carrera: ");
        scanf("%d",&carrera);
        while((carrera<1 || carrera>23) && carrera!=0){
            printf("NUMERO INVALIDO.\nIngrese nuevamente el numero de carrera: ");
            scanf("%d",&carrera);
        }
    }
}