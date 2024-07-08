#include <stdio.h>
#include <string.h>

void cargar(int *ptr, char *cadena) {
    printf("Ingrese la cadena de texto (max. %d caracteres):\n", 3500);
    fgets(cadena, 3500, stdin);
    *ptr = strlen(cadena); // Determina la longitud de la cadena ingresada
    if (cadena[*ptr - 1] == '\n') {
        cadena[*ptr - 1] = '\0'; // Elimina el salto de línea del final
        (*ptr)--;
    }
}

void modificar(char *ptrTexto, int longitud, char buscado, char reemplazo, char *modificado) {
    strcpy(modificado, ptrTexto);
    for (int i = 0; i < longitud; i++) {
        if (modificado[i] == buscado) {
            modificado[i] = reemplazo;
        }
    }
}

void contar(char *ptrTexto, int longitud, char caracter, int *ptrCuantos) {
    *ptrCuantos = 0;
    for (int i = 0; i < longitud; i++) {
        if (ptrTexto[i] == caracter) {
            (*ptrCuantos)++;
        }
    }
}

void buscar(char *ptrTexto, int longitud) {
    char caracter;
    printf("Ingrese el caracter a buscar: ");
    getchar(); // Consumir el carácter de nueva línea pendiente
    scanf("%c", &caracter);
    for (int i = 0; i < longitud; i++) {
        if (ptrTexto[i] == caracter) {
            printf("Texto a partir de la primera ocurrencia: %s\n", &ptrTexto[i]);
            return;
        }
    }
    printf("El caracter no existe en el texto.\n");
}

int mostrarMenu() {
    int opcion;
    printf("\nMENU:\n");
    printf("1- Modificar\n");
    printf("2- Contar\n");
    printf("3- Buscar\n");
    printf("4- Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void opcionModificar(char *texto, int longitud) {
    char buscado, reemplazo;
    printf("Ingrese el caracter a reemplazar: ");
    getchar();
    scanf("%c", &buscado);
    printf("Ingrese el caracter de reemplazo: ");
    getchar();
    scanf("%c", &reemplazo);
    char modificado[3500];
    modificar(texto, longitud, buscado, reemplazo, modificado);
    printf("Texto original: %s\n", texto);
    printf("Texto modificado: %s\n", modificado);
}

void opcionContar(char *texto, int longitud) {
    char buscado;
    int cuantos = 0;
    printf("Ingrese el caracter a contar: ");
    getchar();
    scanf("%c", &buscado);
    contar(texto, longitud, buscado, &cuantos);
    printf("El caracter '%c' aparece %d veces en el texto.\n", buscado, cuantos);
}

void opcionBuscar(char *texto, int longitud) {
    buscar(texto, longitud);
}

void seleccionarDatos() {
    int longitud;
    int opcion;
    char texto[3500];
    cargar(&longitud, texto);
  
    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                opcionModificar(texto, longitud);
                break;
            case 2:
                opcionContar(texto, longitud);
                break;
            case 3:
                opcionBuscar(texto, longitud);
                break;
            case 4:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}

int main(int argc, char *argv[]) {
    seleccionarDatos();
    return 0;
}
