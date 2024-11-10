/*Se dispone de un archivo llamado Stock.dat que contiene la información de los productos que vende una
fábrica. En el archivo se guarda:
• Código de artículo (entero)
• Descripción (50 caracteres máximo)
• Stock (entero)
Luego se ingresan por teclado las ventas a realizar indicando:
• Código de artículo
• Cantidad
 La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
• Código de artículo
• Cantidad faltante
Si ya hay un registro previo en dicho archivo de faltantes con el mismo producto debe incrementarse la
cantidad.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 50

// Estructuras de datos
typedef struct {
    int codigo;
    char descripcion[MAX_DESC];
    int stock;
} Producto;

typedef struct {
    int codigo;
    int cantidadFaltante;
} Faltante;

// Prototipos de funciones
void registrarFaltante(int codigo, int cantidad);
void mostrarStock();
void mostrarFaltantes();

// Función principal
int main() {
    FILE *archivoStock, *archivoFaltantes;
    Producto producto;
    int codigoVenta, cantidadVenta;

    // Abrimos el archivo Stock.dat en modo lectura y escritura
    archivoStock = fopen("Stock.dat", "r+b");
    if (archivoStock == NULL) {
        printf("Error al abrir el archivo Stock.dat\n");
        return 1;
    }

    // Abrimos el archivo Faltantes.dat en modo de escritura para agregar registros
    archivoFaltantes = fopen("Faltantes.dat", "a+b");
    if (archivoFaltantes == NULL) {
        printf("Error al abrir el archivo Faltantes.dat\n");
        fclose(archivoStock);
        return 1;
    }
    fclose(archivoFaltantes); // Cerramos, lo abriremos solo cuando haya faltante

    // Ingresar ventas por teclado
    printf("Ingrese el codigo de articulo (0 para terminar): ");
    scanf("%d", &codigoVenta);

    while (codigoVenta != 0) {
        printf("Ingrese la cantidad a vender: ");
        scanf("%d", &cantidadVenta);

        // Buscamos el producto en Stock.dat
        rewind(archivoStock); // Volvemos al inicio del archivo
        int encontrado = 0;
        
        while (fread(&producto, sizeof(Producto), 1, archivoStock)) {
            if (producto.codigo == codigoVenta) {
                encontrado = 1;
                if (producto.stock >= cantidadVenta) {
                    // Hay stock suficiente
                    producto.stock -= cantidadVenta;
                    fseek(archivoStock, -sizeof(Producto), SEEK_CUR);
                    fwrite(&producto, sizeof(Producto), 1, archivoStock);
                    printf("Venta realizada con exito.\n");
                } else {
                    // No hay stock suficiente
                    printf("Stock insuficiente. Se venden %d unidades de %d solicitadas.\n", producto.stock, cantidadVenta);
                    int faltante = cantidadVenta - producto.stock;
                    registrarFaltante(codigoVenta, faltante);

                    // Vendemos lo que queda en stock
                    producto.stock = 0;
                    fseek(archivoStock, -sizeof(Producto), SEEK_CUR);
                    fwrite(&producto, sizeof(Producto), 1, archivoStock);
                }
                break;
            }
        }

        if (!encontrado) {
            printf("Producto con codigo %d no encontrado.\n", codigoVenta);
        }

        // Solicitar siguiente venta
        printf("Ingrese el codigo de articulo (0 para terminar): ");
        scanf("%d", &codigoVenta);
    }

    // Cerrar archivos
    fclose(archivoStock);

    // Mostrar los contenidos de Stock.dat y Faltantes.dat después de finalizar
    printf("\nContenido final de Stock.dat:\n");
    mostrarStock();

    printf("\nContenido final de Faltantes.dat:\n");
    mostrarFaltantes();

    return 0;
}

// Función para registrar faltantes
void registrarFaltante(int codigo, int cantidad) {
    FILE *archivoFaltantes = fopen("Faltantes.dat", "r+b");
    Faltante faltante;
    int encontrado = 0;

    // Buscamos si el código de artículo ya tiene un registro de faltante
    while (fread(&faltante, sizeof(Faltante), 1, archivoFaltantes)) {
        if (faltante.codigo == codigo) {
            // Si el artículo ya está en el archivo, acumulamos la cantidad faltante
            faltante.cantidadFaltante += cantidad;
            fseek(archivoFaltantes, -sizeof(Faltante), SEEK_CUR);
            fwrite(&faltante, sizeof(Faltante), 1, archivoFaltantes);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        // Si no estaba, agregamos un nuevo registro de faltante
        faltante.codigo = codigo;
        faltante.cantidadFaltante = cantidad;
        fwrite(&faltante, sizeof(Faltante), 1, archivoFaltantes);
    }

    fclose(archivoFaltantes);
}

// Función para mostrar el contenido de Stock.dat
void mostrarStock() {
    FILE *archivoStock = fopen("Stock.dat", "rb");
    Producto producto;

    if (archivoStock == NULL) {
        printf("Error al abrir el archivo Stock.dat\n");
        return;
    }

    printf("Codigo\tDescripcion\t\tStock\n");
    printf("------\t-----------\t\t-----\n");
    while (fread(&producto, sizeof(Producto), 1, archivoStock)) {
        printf("%d\t%-20s\t%d\n", producto.codigo, producto.descripcion, producto.stock);
    }

    fclose(archivoStock);
}

// Función para mostrar el contenido de Faltantes.dat
void mostrarFaltantes() {
    FILE *archivoFaltantes = fopen("Faltantes.dat", "rb");
    Faltante faltante;

    if (archivoFaltantes == NULL) {
        printf("Error al abrir el archivo Faltantes.dat\n");
        return;
    }

    printf("Codigo\tCantidad Faltante\n");
    printf("------\t------------------\n");
    while (fread(&faltante, sizeof(Faltante), 1, archivoFaltantes)) {
        printf("%d\t%d\n", faltante.codigo, faltante.cantidadFaltante);
    }

    fclose(archivoFaltantes);
}
