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
    
	//patch 2 instructions

	//first i never enter in while condition
	long patch1 = 0x13f2; //patch with 0x00
	if (!patch_position(patch1, 0x00, 1)) //only 1 byte
		return 0;

	
    long patch2 = 0x146e; // patch if condition 0f 85 0d 00 00 00 {JNZ to JZ}
	if (!patch_position(patch2, 0x84, 1)) //only 1 byte
		return 0;

	
	//change flow in scanf result to avoid 3 first checks
	long patch3 = 0x1320;
	if (!patch_position(patch3, 0x3a, 1)) // from {0f 84 08 00 00 00} to {0f 84 3a 00 00 00} this JZ jump forward 0x38 bytes instead 8
		return 0;

    printf("Program patched!\n");

    return 0;
}