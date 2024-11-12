/*Se dispone de un archivo llamado Rating.dat que guarda la información de los puntos obtenidos de rating en
los distintos programas de canales de cable a lo largo del día. Cada registro contiene:
• Número de canal (entero)
• Programa (texto de 35 caracteres máximo)
• Rating (float)
El archivo se encuentra ordenado por canal.
Se solicita informar:
a. Aquellos canales que obtengan menos de 15 puntos en total.
b. El canal más visto.
c. Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
• Número de canal.
• Promedio.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    int numCanal;
    char programa[36];
    float rating;
}canales;

typedef struct{
    int numCan;
    float promedio;
}promedio;

FILE * AbrirArchivo(char[],char[]);
void LeerTexto(char[],int);
void AyB(FILE*);
void Promedio(FILE*,FILE*);
int main(){
    canales canal;
    promedio prom;
    FILE *pRat,*pPromedio;

    pRat=AbrirArchivo("Rating.dat","rb");
    pPromedio=AbrirArchivo("Promedio.dat","wb");
    AyB(pRat);
    rewind(pRat);
    Promedio(pRat,pPromedio);
    fclose(pPromedio);

    return 0;
}

void Promedio(FILE *pRat,FILE* pProm){
    canales canal;
    promedio prom;
    int contRat,canalAnt,contMismoCanal;

    printf("\nPromedios:");
    fread(&canal,sizeof(canales),1,pRat);
    while(!feof(pRat)){
        canalAnt=canal.numCanal;
        contRat=0;
        contMismoCanal=0;
        while(!feof(pRat) && canalAnt==canal.numCanal){
            canalAnt=canal.numCanal;
            contRat+=canal.rating;
            contMismoCanal++;
            fread(&canal,sizeof(canales),1,pRat);
        }
        prom.numCan=canalAnt;
        prom.promedio=(float)contRat/contMismoCanal;
        fwrite(&prom,sizeof(promedio),1,pProm);
        printf("\nCanal: %d - Promedio: %.2f",canalAnt,prom.promedio);
    }
}

void AyB(FILE *p){
    canales canal;
    int contRat=0,mayorRat,canalAnt,mayorCan,aux=0;

    printf("Canales con menos de 15 puntos en total:");
    fread(&canal,sizeof(canales),1,p);
    while(!feof(p)){
        canalAnt=canal.numCanal;
        contRat=0;
        while(!feof(p) && canalAnt==canal.numCanal){
            canalAnt=canal.numCanal;
            contRat+=canal.rating;
            fread(&canal,sizeof(canales),1,p);
        }
        if(!aux){
            mayorCan=canalAnt;
            mayorRat=contRat;
            aux=1;
        }
        if(contRat<15)
        printf("\n- Canal %d",canalAnt);
        if(mayorRat<contRat){
            mayorCan=canalAnt;
            mayorRat=contRat;
        }
    }

    printf("\nEl canal mas visto es el canal %d con %d de rating.\n",mayorCan,mayorRat);
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
    FILE *arch;

    arch=fopen(archivo,modo);
    if(arch==NULL){
        printf("Error.\n");
        getch();
        exit(1);
    }
}
