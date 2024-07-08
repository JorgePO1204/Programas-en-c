#include <stdio.h>
#include <ctype.h>
#include <string.h>



void leerEntrada(char *texto[]) {
    char linea[100];
    int contador = 0;

    printf("Ingrese un texto (maximo 6 lineas):\n");

    while (contador < 6 && fgets(linea, 100, stdin)) {
        linea[strcspn(linea, "\n")] = 0; // remover el salto de línea
        strcpy(texto[contador], linea);
        contador++;
    }
}

void esVocal(char caracter, int *ptrContador) {
    switch (caracter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            (*ptrContador)++;
            break;
        default:
            break;
    }
}

void esConsonante(char caracter, int *ptrContador) {
    switch (caracter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case ' ':
        case '\n':
        case '\t':
            break; // No es una consonante
        default:
            (*ptrContador)++;
            break; // Es una consonante
    }
}


void mostrarMenu() {
    printf("\nMenu:\n");
    printf("1. Cuenta vocales\n");
    printf("2. Cuenta consonantes\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");
}

void contarVocales(char *texto[], int *contadorVocales) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; texto[i][j] != '\0'; j++) {
            esVocal(texto[i][j], contadorVocales);
        }
    }
}

void contarConsonantes(char *texto[], int *contadorConsonantes) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; texto[i][j] != '\0'; j++) {
            esConsonante(texto[i][j], contadorConsonantes);
        }
    }
}

void solicitarDatos() {
    char *texto[6];
    char buffer[6][100];
    int opcion;

    for (int i = 0; i < 6; i++) {
        texto[i] = buffer[i];
    }

    leerEntrada(texto);

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: {
                int contadorVocales = 0;
                contarVocales(texto, &contadorVocales);
                printf("Cantidad de vocales en el texto: %d\n\n", contadorVocales);
                break;
            }
            case 2: {
                int contadorConsonantes = 0;
                contarConsonantes(texto, &contadorConsonantes);
                printf("Cantidad de consonantes en el texto: %d\n\n", contadorConsonantes);
                break;
            }
            case 3:
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 3);
}

int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}
