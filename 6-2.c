/*Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea desarrollar un
programa que, basado en la información del archivo, genere 3 archivos:
• Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
• Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no
promocionados).
• Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre del archivo
a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para mostrar todos los
archivos generados.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
    int dni;
    char nombreApellido[81];
    int nota1;
    int nota2;
    float prom;
}tAlumno;

FILE * AbrirArchivo(char[],char[]);
void ComprobarDatos(char[]);
int main(){
    FILE *archAlu,*archProm,*archCur,*archRep;
    tAlumno alumno;

    archAlu=AbrirArchivo("Alumnos.dat","rb");
    archProm=AbrirArchivo("Promocionados.dat","wb");
    archCur=AbrirArchivo("Cursada.dat","wb");
    archRep=AbrirArchivo("Reprobados.dat","wb");

    fread(&alumno,sizeof(tAlumno),1,archAlu);
    while(!feof(archAlu)){
        if(alumno.prom>=7)
        fwrite(&alumno,sizeof(tAlumno),1,archProm);
        else if(alumno.prom<7 && alumno.prom>=4)
        fwrite(&alumno,sizeof(tAlumno),1,archCur);
        else if(alumno.prom<4)
        fwrite(&alumno,sizeof(tAlumno),1,archRep);
        fread(&alumno,sizeof(tAlumno),1,archAlu);
    }

    fclose(archAlu);
    fclose(archProm);
    fclose(archCur);
    fclose(archRep);

    printf("\nContenido Promocionados:");
    ComprobarDatos("Promocionados.dat");
    printf("\nContenido Cursada:");
    ComprobarDatos("Cursada.dat");
    printf("\nContenido Reprobados:");
    ComprobarDatos("Reprobados.dat");

    fclose(archProm);
    fclose(archCur);
    fclose(archRep);

    return 0;
}

FILE * AbrirArchivo(char nombre[],char modo[]){
    FILE * arch;

    arch=fopen(nombre,modo);
    if(arch==NULL){
        printf("Error.\n");
        getch();
        exit(1);
    }

    return arch;
}

void ComprobarDatos(char nombre[]){
    FILE * arch;
    tAlumno alumno;

    arch=AbrirArchivo(nombre,"rb");

    while(fread(&alumno,sizeof(tAlumno),1,arch)){
        printf("\nDNI: %d\n", alumno.dni);
        printf("Promedio: %.2f\n", alumno.prom);
    }
}