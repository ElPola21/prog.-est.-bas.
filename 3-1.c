/*Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
Considerar que las palabras pueden estar separadas por más de un espacio consecutivo.*/

#include <stdio.h>
#include <string.h>
#define TAM 501

int main(){
    int i=0,cont=0;
    char cadena[TAM];

    printf("Ingrese frase: ");
    fflush(stdin);
    fgets(cadena,TAM,stdin);
    cadena[strlen(cadena)-1]='\0';
    
    while(cadena[i]!='\0'){
        if((cadena[i+1]==' ' ||  cadena[i+1]=='\0') && cadena[i]!=' ')
        cont++;
        i++;
    }
    printf("La frase tiene %d palabras.",cont);

    return 0;
}