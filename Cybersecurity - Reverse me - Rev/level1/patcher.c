#include <stdio.h>

int main() {
    FILE *archivo;
    char nombreArchivo[] = "level1";
    long posicion = 0x1244; // offset position of if statment to be patched

    // Abrir el archivo en modo lectura y escritura binaria
    archivo = fopen(nombreArchivo, "r+b");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Mover el puntero de lectura/escritura a la posición especificada
    if (fseek(archivo, posicion, SEEK_SET) != 0) {
        perror("Error al mover el puntero de archivo");
        fclose(archivo);
        return 1;
    }

    // Reemplazar los 6 bytes en la posición especificada con 0x90
    for (int i = 0; i < 6; i++) {
        if (fputc(0x90, archivo) == EOF) { //Replace with 0x90 (NOP)
            perror("Error al escribir en el archivo");
            fclose(archivo);
            return 1;
        }
    }

    // Cerrar el archivo
    fclose(archivo);

    printf("Bytes reemplazados con éxito en la posición 0x11244.\n");

    return 0;
}