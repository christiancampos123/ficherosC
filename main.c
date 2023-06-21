#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void leerData();
void meterData();
int main() {
    leerData();
    meterData();
    return 0;
}

void leerData() {
    FILE *archivo;
    char nombreArchivo[] = "C:/Users/christian.campos/Desktop/scriptsDeC/ficherosC/datos.txt";
    char linea[100];
    int numeroPalabra = 1; // Número de la palabra que deseas obtener
    char delimitadores[] = " \t"; // Delimitadores de palabras (espacios y tabulaciones)
    char *palabra;

    // Abrir archivo en modo de lectura
    archivo = fopen(nombreArchivo, "r");

    // Verificar si el archivo se ha abierto correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
    }

    // Leer línea por línea del archivo y obtener la segunda palabra
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        int contador = 0;
        palabra = strtok(linea, delimitadores);

        while (palabra != NULL && contador < numeroPalabra) {
            palabra = strtok(NULL, delimitadores);
            contador++;
        }

        if (palabra != NULL) {
            printf("palabra: %s\n", palabra);
        }
    }
    // Cerrar el archivo
    fclose(archivo);
}

void meterData() {
    FILE *archivoOriginal;
    FILE *archivoNuevo;
    char nombreArchivoOriginal[] = "C:/Users/christian.campos/Desktop/scriptsDeC/ficherosC/datos.txt";
    char nombreArchivoNuevo[] = "C:/Users/christian.campos/Desktop/scriptsDeC/ficherosC/datos2.txt";
    char linea[100];
    int numLin = 0;
    char numLins[50];

    // Abrir archivo original en modo de lectura
    archivoOriginal = fopen(nombreArchivoOriginal, "r");

    // Verificar si el archivo original se ha abierto correctamente
    if (archivoOriginal == NULL) {
        printf("Error al abrir el archivo original.\n");
    }

    // Abrir archivo nuevo en modo de escritura
    archivoNuevo = fopen(nombreArchivoNuevo, "w");

    // Verificar si el archivo nuevo se ha abierto correctamente
    if (archivoNuevo == NULL) {
        printf("Error al abrir el archivo nuevo.\n");

    }
    // Leer línea por línea del archivo original, agregar la cadena nueva y escribir en el archivo nuevo
    while (fgets(linea, sizeof(linea), archivoOriginal) != NULL) {
        char lineaModificada[150]; // Espacio para almacenar la línea modificada
        numLin++;

        sprintf(numLins, "%d", numLin);
        strcpy(lineaModificada, numLins); // Copiar la cadena nueva al principio de la línea
        strcat(lineaModificada, linea); // Concatenar la línea original después de la cadena nueva

        fputs(lineaModificada, archivoNuevo); // Escribir la línea modificada en el archivo nuevo
    }

    // Cerrar archivos
    fclose(archivoOriginal);
    fclose(archivoNuevo);

    printf("Archivo creado con las modificaciones.\n");
}