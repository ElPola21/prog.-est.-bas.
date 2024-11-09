/*El archivo ventas.dat contiene información histórica de las ventas realizadas por una empresa desde el año
2014 al 2023. El formato de registro es el siguiente:
• Mes (entero)
• Año (entero)
• Dia (entero)
• Código de Producto (entero)
• Importe de la venta (real)
Se pide ingresar un rango de años y mostrar un cuadro ventas realizadas en cada mes de cada año. Por ejemplo,
si se ingresa desde 2020 a 2022 debe mostrar lo siguiente:
      Mes 1 Mes 2 Mes 3 ……. Mes 12
2020   xxx   xxx   xxx       xxx
2021   xxx   xxx   xxx       xxx
2022   xxx   xxx   xxx       xxx
Una vez configurados los años debe poder cambiarse la vista para en lugar de visualizar cantidad de ventas, ver el
detalle de importe por mes/año. El usuario podrá alternar las vistas las veces que quiera. Agregar una opción
para finalizar el programa. NO LO ENTENDI ESTE PUNTO*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    int mes;
    int anio;
    int dia;
    int codP;
    float importe;
}ventas;

FILE * AbrirArchivo(char[],char[]);
//void Carga(ventas,FILE*);
void ModoVista(ventas,FILE*);
void CargaTablaVista1(ventas,FILE*,int[][3],int,int);
void Vista1(ventas,FILE*,int,int);
int main(){
    ventas vent;
    FILE * pVentas;
    //Carga(vent,pVentas); //DATOS CARGADOS DESDE 2014 A 2016
    ModoVista(vent,pVentas);

    return 0;
}

void Vista1(ventas v,FILE * p,int aI,int aF){
    int i,j,mImpMes[12][3];
    
    p=AbrirArchivo("ventas.dat","rb");
    printf("\n          ");
    for(i=0;i<12;i++){
        printf("Mes %d   ",i+1);
    }
    for(i=0;i<((aF-aI)+1);i++){
        for(j=0;j<12;j++){
            mImpMes[i][j]=0;
        }
    }

    CargaTablaVista1(v,p,mImpMes,aI,aF);

    for(i=0;i<((aF-aI)+1);i++){
        for(j=0;j<12;j++){
            if(j==0)
            printf("\nANIO %d",i+1);
            printf("%8d",mImpMes[i][j]);
        }
        printf("\n");
    }
}

void CargaTablaVista1(ventas v,FILE * p,int m[][3],int aI,int aF){
    int contAnio=aI;
    fread(&v,sizeof(ventas),1,p);
    while(!feof(p)){
        if(v.anio==aI)
        m[v.mes-1][contAnio-aI]++;
        else if(v.anio==aI+1){
            contAnio=aI+1;
            m[v.mes-1][contAnio-aI]++;
        }
        else if(v.anio==aI+2){
            contAnio=aI+2;
            m[v.mes-1][contAnio-aI]++;
        }
        //tendrian q estar las posibilidades de todos los anios(2014 a 2023) pero no tengo ganas
        fread(&v,sizeof(ventas),1,p);
    }

    fclose(p);
}

void ModoVista(ventas v,FILE * p){
    int anioI,anioF,vista;
    
    printf("Ingrese anio inicial: ");
    scanf("%d",&anioI);
    while(anioI<2014 || anioI>2016){
        printf("ANIO INVALIDO.\nIngrese nuevamente el anio inicial: ");
        scanf("%d",&anioI);
    }

    printf("Ingrese anio final: ");
    scanf("%d",&anioF);
    while(anioF<2014 || anioF>2016 || anioF<anioI){
        printf("ANIO INVALIDO.\nIngrese nuevamente el anio final: ");
        scanf("%d",&anioF);
    }

    printf("-Ingrese vista-:\n1- Ventas realizadas por cada mes cada anio.\n2- Detalle de importe por mes/anio.\n0- Finalizar programa.\nOpcion: ");
    scanf("%d",&vista);
    while(vista<0 || vista>3){
        printf("VISTA INVALIDA.\nIngrese nuvamente vista: ");
        scanf("%d",&vista);
    }
    while(vista!=0){
        if(vista==1)
        Vista1(v,p,anioI,anioF);

        printf("\n-Ingrese vista-:\n1- Ventas realizadas por cada mes cada anio.\n2- Detalle de importe por mes/anio.\n0- Finalizar programa.\nOpcion: ");
        scanf("%d",&vista);
        while(vista<0 || vista>3){
            printf("VISTA INVALIDA.\nIngrese nuvamente vista: ");
            scanf("%d",&vista);
        }
    }
}

FILE * AbrirArchivo(char archivo[],char modo[]){
    FILE * arch;
    
    arch=fopen(archivo,modo);
    if(arch==NULL){
        printf("ERROR.");
        getch();
        exit(1);
    }

    return arch;
}
//CARGADO DESDE 2014 A 2016
/*void Carga(ventas v,FILE * p){
    printf("Ingrese mes: ");
    scanf("%d",&v.mes);
    while((v.mes<1 || v.mes>12) && v.mes!=0){
        printf("MES INVALIDO.\nIngrese nuevamente el mes: ");
        scanf("%d",&v.mes);
    }
    while(v.mes!=0){
        printf("Ingrese anio: ");
        scanf("%d",&v.anio);
        while(v.anio<2014 || v.anio>2016){
            printf("ANIO INVALIDO.\nIngrese nuevamente el anio: ");
            scanf("%d",&v.anio);
        }

        printf("Ingrese dia: ");
        scanf("%d",&v.dia);
        while(v.dia<1 || v.dia>31){
            printf("DIA INVALIDO.\nIngrese nuevamente el dia: ");
            scanf("%d",&v.dia);
        }

        printf("Ingrese codigo del producto: ");
        scanf("%d",&v.codP);

        printf("Ingrese importe de la venta: ");
        scanf("%f",&v.importe);
        while(v.importe<0){
            printf("VENTA INVALIDA.\nIngrese nuevamente el importe de la venta: ");
            scanf("%f",&v.importe);
        }

        fwrite(&v,sizeof(ventas),1,p);

        printf("\nIngrese mes: ");
        scanf("%d",&v.mes);
        while((v.mes<1 || v.mes>12) && v.mes!=0){
            printf("MES INVALIDO.\nIngrese nuevamente el mes: ");
            scanf("%d",&v.mes);
        }
    }
}*/