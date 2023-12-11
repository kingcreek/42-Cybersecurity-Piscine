#include <stdio.h>

int main() {
    FILE *archivo;
    char nombreArchivo[] = "level1";
    long posicion = 0x1244; // offset position of if statment to be patched

    // Open fuile in read and binary write
    archivo = fopen(nombreArchivo, "r+b");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Seek read pointer to location {posicion}
    if (fseek(archivo, posicion, SEEK_SET) != 0) {
        perror("Error al mover el puntero de archivo");
        fclose(archivo);
        return 1;
    }

    // //Replace 6 first bytes with 0x90 (NOP)
    for (int i = 0; i < 6; i++) {
        if (fputc(0x90, archivo) == EOF) {
            perror("Error al escribir en el archivo");
            fclose(archivo);
            return 1;
        }
    }

    // close file
    fclose(archivo);

    printf("Bytes reemplazados con éxito en la posición 0x11244.\n");

    return 0;
}