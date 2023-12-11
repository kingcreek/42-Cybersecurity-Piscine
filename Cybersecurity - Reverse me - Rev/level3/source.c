#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void no()
{
	printf("Nope.\n");
	exit(1);
}

void ok()
{
	printf("Good job.\n");
}


int main(void) {
    // Declaración de variables
    unsigned int indiceClave;
    size_t longitudClave;
    int valorCaracter;
    int condicion;
    char digitoActual[4];
    char digitoSiguiente;
    char digitoSiguienteSiguiente;
    char caracterDummy;  // Variable utilizada para limpiar el búfer de entrada
    char claveIngresada[31];
    char claveProcesada[9];
    unsigned int indiceProcesado;
    int resultadoComparacion;

    // Inicialización de variables
    indiceClave = 0;
    caracterDummy = 0;

    // Solicitar al usuario que ingrese una clave
    printf("Por favor, ingrese una clave: ");
    if (scanf("%s", claveIngresada) != 1) {
        no();
    }

    // Verificar condiciones sobre los primeros dos caracteres de la clave
    if (claveIngresada[1] != '2' || claveIngresada[0] != '4') {
        no();
    }

    // Limpiar el búfer de entrada
    while ((caracterDummy = getchar()) != '\n' && caracterDummy != EOF);

    // Inicializar una cadena local con el caracter 'd' en la primera posición
    memset(claveProcesada, 0, 9);
    claveProcesada[0] = '*';
    indiceClave = 2;
    indiceProcesado = 1;

    // Procesar la clave ingresada
    while (1) {
        longitudClave = strlen(claveProcesada);
        condicion = 0;

        // Verificar si la longitud de la cadena claveProcesada es menor que 8
        if (longitudClave < 8) {
            longitudClave = strlen(claveIngresada);
            condicion = indiceClave < longitudClave;
        }

        // Salir del bucle si no se cumple la condición
        if (!condicion) {
            break;
        }

        // Obtener tres caracteres de la clave, convertirlos a entero y agregarlos a claveProcesada
        digitoActual[0] = claveIngresada[indiceClave];

		digitoActual[1] = claveIngresada[indiceClave + 1];
		digitoActual[2] = claveIngresada[indiceClave + 2];
		digitoActual[3] = '\0';
        valorCaracter = atoi(digitoActual);
        claveProcesada[indiceProcesado] = (char)valorCaracter;

        // Actualizar índices
        indiceClave = indiceClave + 3;
        indiceProcesado = indiceProcesado + 1;
    }

    // Agregar el carácter nulo al final de claveProcesada
    claveProcesada[indiceProcesado] = '\0';

    // Comparar claveProcesada con la cadena "delabere" e imprimir "OK" o "NO" en consecuencia
    resultadoComparacion = strcmp(claveProcesada, "********");
    if (resultadoComparacion == 0) {
        ok();
    } else {
        no();
    }

    return 0;
}

/*

*/