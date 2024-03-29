#include <stdio.h>

int patch_position(long position, char patch, int size)
{
	FILE *archivo;
    char nombreArchivo[] = "level2";
	// Open fuile in read and binary write
    archivo = fopen(nombreArchivo, "r+b");
	if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 0;
    }
	// Seek read pointer to location {posicion}
    if (fseek(archivo, position, SEEK_SET) != 0) {
        perror("Error al mover el puntero de archivo");
        fclose(archivo);
        return 0;
    }
	// //Replace 6 first bytes with 0x90 (NOP)
    for (int i = 0; i < size; i++) {
        if (fputc(patch, archivo) == EOF) {
            perror("Error al escribir en el archivo");
            fclose(archivo);
            return 0;
        }
    }
	// close file
    fclose(archivo);
	return 1;
}

int main() {

	long patch = 0x1244; // offset position of if statment to be patched
	if (!patch_position(patch, 0x90, 6)) //Replace 6 first bytes with 0x90 (NOP)
		return 0;

    printf("Program patched!\n");
    return 0;
}