/*Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
• Número de cliente (entero de 4 dígitos no correlativos).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).
El ingreso de datos finaliza con un número de cliente 999.
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:
• Código de cliente (entero de 4 dígitos no correlativos).
• Nombre y Apellido (50 caracteres máximo).
Se solicita:
a. Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada
cliente, informando:
CODIGO DE CLIENTE   NOMBRE Y APELLIDO   TOTAL FACTURADO
       X             XXXXX XXXXXXXX     $ XXXXXXXXX,XX
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
    int codigoCliente;
    char nombreC[50];
}cliente;

typedef struct{
    cliente;
    float importe;
    int numVend;
}venta;

int CARGA_CLIENTE(cliente[],int[][MAX],int);
void IngresoVentas(venta[],cliente[],int[][MAX],int[][10],int,float[]);
int Correlativo(int);
int BuscarDatoC(cliente[],int,int);
int BuscarDatoV(int[][10],int,int);
void PuntoAyB(int[][MAX],int[][10],int);
void PuntoC(cliente[],float[],int);
void OrdenarV(cliente[],float[],int);
int main(){
    cliente c[MAX];
    venta v[MAX];
    int i,j,cant,mC[2][MAX],mV[2][10]={{1,2,3,4,5,6,7,8,9,10},{0,0,0,0,0,0,0,0,0,0}};
    float vImpPorCliente[MAX];

    cant=CARGA_CLIENTE(c,mC,MAX);
    for(i=0;i<cant;i++){
        v[i].importe=0;
        v[i].numVend=0;
        vImpPorCliente[i]=0;
    }
    for(j=0;j<cant;j++){
        mC[1][j]=0;
    }
    IngresoVentas(v,c,mC,mV,cant,vImpPorCliente);
    PuntoAyB(mC,mV,cant);
    OrdenarV(c,vImpPorCliente,cant);
    PuntoC(c,vImpPorCliente,cant);

    return 0;
}

int CARGA_CLIENTE(cliente c[],int mC[][MAX],int ce){
    int i=0,rep,codC;

    printf("CARGA CLIENTE:\n\nIngrese codigo de cliente: ");
    scanf("%d",&codC);
    rep=Correlativo(codC);
    while((codC<1000 || codC>9999 || rep) && codC!=999){
        printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo de cliente: ");
        scanf("%d",&codC);
        rep=Correlativo(codC);
    }
    if(!rep && codC!=999){
        c[i].codigoCliente=codC;
        mC[0][i]=c[i].codigoCliente;
    }

    while(codC!=999 && i<ce){
        printf("Ingrese nombre y apellido del cliente: ");
        fflush(stdin);
        gets(c[i].nombreC);
        while(strlen(c[i].nombreC)>50){
            printf("NOMBRE INVALIDO.\nIngrese nuevamente el nombre y apellido del cliente: ");
            fflush(stdin);
            gets(c[i].nombreC);
        }

        i++;

        if(i<ce){
            printf("\nIngrese codigo de cliente: ");
            scanf("%d",&codC);
            rep=Correlativo(codC);
            while((codC<1000 || codC>9999 || rep) && codC!=999){
                printf("CODIGO INVALIDO.\nIngrese nuevamente el codigo de cliente: ");
                scanf("%d",&codC);
                rep=Correlativo(codC);
            }
            if(!rep && codC!=999){
                c[i].codigoCliente=codC;
                mC[0][i]=c[i].codigoCliente;
            }
        }
    }

    return i;
}

int Correlativo(int cod){
    int resto1,resto2,resto3,resto4,ret=0;

    resto1=cod%10;
    resto2=cod%100/10;
    resto3=cod%1000/100;
    resto4=cod%10000/1000;
    if((resto1==resto2+1) && (resto2==resto3+1) && (resto3==resto4+1))
    ret=1;
    else if((resto1==resto2-1) && (resto2==resto3-1) && (resto3==resto4-1))
    ret=1;

    return ret;
}

int BuscarDatoC(cliente c[],int datoBuscado,int ce){
    int i,pos=-1;

    for(i=0;i<ce;i++){
        if(c[i].codigoCliente==datoBuscado)
        pos=i;
    }

    return pos;
}

int BuscarDatoV(int mV[][10],int datoBuscado,int ce){
    int j,pos=-1;

    for(j=0;j<ce;j++){
        if(mV[0][j]==datoBuscado)
        pos=j;
    }

    return pos;
}

void IngresoVentas(venta v[],cliente c[],int mC[][MAX],int mV[][10],int ce,float vImpCliente[]){
    int numC,pos,pos2,vend;
    
    printf("INGRESO VENTAS:\n\nIngrese numero de cliente: ");
    scanf("%d",&numC);
    pos=BuscarDatoC(c,numC,ce);
    while(pos==-1 && numC!=999){
        printf("NUMERO INVALIDO.\nIngrese nuevamente el numero de cliente: ");
        scanf("%d",&numC);
        pos=BuscarDatoC(c,numC,ce);
    }
    while(numC!=999){
        printf("Ingrese importe del cliente %d: ",c[pos].codigoCliente);
        scanf("%f",&v[pos].importe);
        while(v[pos].importe<=0){
            printf("IMPORTE INVALIDO.\nIngrese nuevamente el importe del cliente %d: ",c[pos].codigoCliente);
            scanf("%f",&v[pos].importe);
        }
        vImpCliente[pos]+=v[pos].importe;

        printf("Ingrese numero del vendedor: ");
        scanf("%d",&vend);
        pos2=BuscarDatoV(mV,vend,10);
        while(vend<1 || vend>10){
            printf("NUMERO INVALIDO.\nIngrese nuevamente el numero del vendedor: ");
            scanf("%d",&vend);
            pos2=BuscarDatoV(mV,vend,10);
        }
        v[pos2].numVend=vend;
        mC[1][pos]++;
        mV[1][pos2]++;

        printf("\nIngrese numero de cliente: ");
        scanf("%d",&numC);
        pos=BuscarDatoC(c,numC,ce);
        while(pos==-1 && numC!=999){
            printf("NUMERO INVALIDO.\nIngrese nuevamente el numero de cliente: ");
            scanf("%d",&numC);
            pos=BuscarDatoC(c,numC,ce);
        }
    }
}

void PuntoAyB(int mC[][MAX],int mV[][10],int ce){
    int i,j;

    printf("\n\nVENTAS POR CLIENTE:\n");
    for(i=0;i<2;i++){
        for(j=0;j<ce;j++){
            printf("%7d",mC[i][j]);
        }
        printf("\n");
    }

    printf("\n\nVENTAS POR VENDEDOR:\n");
    for(i=0;i<2;i++){
        for(j=0;j<10;j++){
            printf("%7d",mV[i][j]);
        }
        printf("\n");
    }
}

void PuntoC(cliente c[],float vImp[],int ce){
    int i;

    printf("\n\nTOTAL FACTURADO POR CLIENTE:\n");
    printf("%23s %23s %23s","CODIGO DE CLIENTE","NOMBRE Y APELLIDO","TOTAL FACTURADO");
    for(i=0;i<ce;i++){
        printf("\n%16d %23s %25.2f",c[i].codigoCliente,c[i].nombreC,vImp[i]);
    }
}

void OrdenarV(cliente c[],float vImp[],int ce){
    int i,j,auxC,auxImp;
    char auxNombre[50];

    for(i=0;i<ce-1;i++){
        for(j=0;j<ce-1-i;j++){
            if(vImp[j]<vImp[j+1]){
                auxImp=vImp[j];
                vImp[j]=vImp[j+1];
                vImp[j+1]=auxImp;
                auxC=c[j].codigoCliente;
                c[j].codigoCliente=c[j+1].codigoCliente;
                c[j+1].codigoCliente=auxC;
                strcpy(auxNombre,c[j].nombreC);
                strcpy(c[j].nombreC,c[j+1].nombreC);
                strcpy(c[j+1].nombreC,auxNombre);
            }
        }
    }
}