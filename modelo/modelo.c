/*Se dispone del archivo llamadas.dat con las llamadas telefónicas del día realizadas por una
empresa. Dicho archivo se encuentra ordenado por Sector. Cada registro contiene: Sector
de la empresa (texto de 15 caracteres máximo), duración de la llamada en segundos (entero),
tipo de llamada (char: L local, I internacional, E dentro de la empresa).
Las llamadas realizadas dentro de la empresa no tienen costo.
Para valorizar las llamadas locales e internacionales se debe recuperar el costo por segundo
del archivo costos.dat que tiene; tipo de llamada (char), mes (entero), año (entero) y costo
por segundo (float). Se deben tomar en cuenta los costos del mes 6 del año 2024. Los costos
se deben recuperar mediante una función que reciba por referencia las dos variables donde
guardar los costos requeridos.
Por otro lado, se dispone del archivo gastosXSector.dat que contiene: Sector, importe total
gastado en el mes.
Se desea:
a) Usando corte de control generar un archivo de texto csv que indique: nombre del sector
y cantidad de llamadas de cada tipo
b) Actualizar el archivo de gastosXSector acumulando el gasto de las llamadas del día en
cada sector.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    char sector[16];
    int duracion;
    char tipo;
}llamadas;

typedef struct{
    char tipo;
    int mes;
    int anio;
    float costoXseg;
}costos;

typedef struct{
    char sector[16];
    float importeT;
}gastosXsect;

FILE *AbrirArchivo(char[],char[]);
int RecuperarCostos(float*,float*,int,int);
void LlamadasSector(FILE*,float,float);
void ActualizarArchivo(char[],float,FILE*);
int main(){
    llamadas l;
    costos c;
    gastosXsect g;
    FILE *pL,*pC,*pG,*pLxS;
    float costoL,costoI;
    int cant;
    
    cant=RecuperarCostos(&costoL,&costoI,6,2024);
    if(!cant)
    printf("No hubieron costos por llamada en 06/24.");
    else
    LlamadasSector(pLxS,costoL,costoI);

    return 0;
}

void LlamadasSector(FILE *pLxS,float costoL,float costoI){
    llamadas l;
    FILE *pL,*pG;
    int contL,contI,contE;
    float gastSector;
    char sectAnt[16],tipoAnt;
    pL=AbrirArchivo("llamadas.dat","rb");
    pLxS=AbrirArchivo("llamadasXsector.csv","wt");
    pG=AbrirArchivo("gastosXsector.dat","r+b");
    fprintf(pLxS,"\nSECTOR;LOCAL;INTER.;EMPRESA\n");
    fread(&l,sizeof(llamadas),1,pL);
    strcpy(sectAnt,l.sector);
    while(!feof(pL)){  
        contL=0;
        contI=0;
        contE=0;
        gastSector=0;
        while(!feof(pL) && !strcmpi(sectAnt,l.sector)){
            if(l.tipo=='L'){
                contL++;
                gastSector+=l.duracion*costoL;
            }
            else if(l.tipo=='I'){
                contI++;
                gastSector+=l.duracion*costoI;
            }
            else if(l.tipo=='E'){
                contE++;
            }
            fread(&l,sizeof(llamadas),1,pL);
        }
        fprintf(pLxS,"%s;%d;%d;%d\n",sectAnt,contL,contI,contE);
        ActualizarArchivo(sectAnt,gastSector,pG);
        strcpy(sectAnt,l.sector);
    }
    fclose(pL);
    fclose(pLxS);
    fclose(pG);
}

void ActualizarArchivo(char sector[],float gasto,FILE *pG){
    gastosXsect g;
    int encontrado=0;

    rewind(pG);
    fread(&g,sizeof(gastosXsect),1,pG);
    while(!feof(pG) && !encontrado){
        if(!strcmpi(sector,g.sector)){
            g.importeT+=gasto;
            fseek(pG,sizeof(gastosXsect)*-1,SEEK_CUR);
            fwrite(&g,sizeof(gastosXsect),1,pG);
            fflush(pG);
            encontrado=1;
        }
        fread(&g,sizeof(gastosXsect),1,pG);
    }
}

int RecuperarCostos(float *costL,float *costI,int mes,int anio){
    costos c;
    FILE *pC;
    int cont=0;

    *costL=0;
    *costI=0;

    pC=AbrirArchivo("costos.dat","rb");   
    fread(&c,sizeof(costos),1,pC);
    while(!feof(pC)){
        if(c.tipo=='L' && c.mes==mes && c.anio==anio){
            *costL=c.costoXseg;
            cont++;
        }
        else if(c.tipo=='I' && c.mes==mes && c.anio==anio){
            *costI=c.costoXseg;
            cont++;
        }
        fread(&c,sizeof(costos),1,pC);
    }
    fclose(pC);

    return cont;
}

FILE *AbrirArchivo(char archivo[],char modo[]){
    FILE *arch;
    
    arch=fopen(archivo,modo);
    if(arch==NULL){
        printf("Error.\n");
        getch();
        exit(1);
    }

    return arch;
}
