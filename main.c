#include <stdio.h>
#include <string.h>


void leerData();
int main() {
    leerData();
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