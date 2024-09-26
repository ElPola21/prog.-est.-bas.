/*Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).
Se solicita:
a. Declarar un tipo de dato que contenga la información del medicamento.
b. Declarar un vector de estructura de tipo de datos creado en a.
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.*/

#include <stdio.h>
#define CANT 5

typedef struct{
    int codMed;
    float precio;
    int stock;
}medicamento;

void INGRESO(medicamento[],int);
void BUSQUEDA_MEDI(medicamento[],int);
int Busqueda(medicamento[],int,int);
void INFORME(medicamento[],int);
int main(){
    medicamento med[CANT];

    INGRESO(med,CANT); 
    BUSQUEDA_MEDI(med,CANT);
    INFORME(med,CANT);

    return 0;
}

void INGRESO(medicamento med[],int ce){
    int i,rep;

    printf("CARGA MEDICAMENTOS:\n");
    for(i=0;i<ce;i++){
        printf("\nIngrese el codigo del medicamento: ");
        scanf("%d",&med[i].codMed);
        rep=Busqueda(med,med[i].codMed,i);
        while(rep!=-1 || med[i].codMed<100 || med[i].codMed>999){
            printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo del medicamento: ");
            scanf("%d",&med[i].codMed);
            rep=Busqueda(med,med[i].codMed,i);
        }
        printf("Ingrese el precio del medicamento: ");
        scanf("%f",&med[i].precio);
        while(med[i].precio<=0){
            printf("PRECIO INVALIDO.\nIngrese nuevamente el precio del medicamento: ");
            scanf("%f",&med[i].precio);
        }
        printf("Ingrese stock del medicamento: ");
        scanf("%d",&med[i].stock);
        while(med[i].stock<0){
            printf("NUMERO INVALIDO.\nIngrese nuevamente el stock del medicamento: ");
            scanf("%d",&med[i].stock);
        }
    }
}

void BUSQUEDA_MEDI(medicamento med[],int ce){
    int cod,pos;

    printf("\nBUSQUEDA MEDICAMENTO:\n\nIngrese codigo del medicamento: ");
    scanf("%d",&cod);
    while(cod!=10){
        pos=Busqueda(med,cod,ce);
        while(pos==-1 && cod!=10){
            printf("CODIGO NO ENCONTRADO.\nIngrese nuevamente el codigo del medicamento: ");
            scanf("%d",&cod);
            pos=Busqueda(med,cod,ce);
        }
        printf("El precio del medicamento %d es %.2f.\n",med[pos].codMed,med[pos].precio);

        printf("\nIngrese codigo del medicamento: ");
        scanf("%d",&cod);
    }
    
}

int Busqueda(medicamento med[],int datoBuscado,int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(med[i].codMed==datoBuscado)
        pos=i;
    }

    return pos;
}

void INFORME(medicamento med[],int ce){
    int i;

    printf("\nLos medicamentos con un stock menor a 10 unidades son:");
    for(i=0;i<ce;i++){
        if(med[i].stock<10)
        printf("%5d",med[i].codMed);
    }
}