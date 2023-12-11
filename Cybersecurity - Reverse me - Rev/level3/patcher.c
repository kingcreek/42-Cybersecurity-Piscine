#include <stdio.h>

int patch_position(long position, char patch, int size)
{
	FILE *archivo;
    char nombreArchivo[] = "level3";
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
    
	//patch 2 instructions

	//first i never enter in while condition
	long patch1 = 0x0000135c; //patch with 0x00
	if (!patch_position(patch1, 0xFE, 1)) //only 1 byte
		return 0;

	long patch2 = 0x0000135d; //patch with 0x00
	if (!patch_position(patch2, 0x01, 1)) //only 1 byte
		return 0;

    printf("Program patched!\n");

    return 0;
}