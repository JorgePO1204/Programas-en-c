#include <stdio.h>


void ingresarEnteros(int *arreglo) {
    int i = 0;
    while (i < 30) {
        printf("Ingrese el entero: ");
        scanf("%d", arreglo);
        if (*arreglo == 0)
            break;
        arreglo++;
        i++;
    }
}


int *buscar(int *arreglo) {
    int *ptr = NULL;
    int i;

    for (i = 0; *(arreglo + i) != 0 && i < 30 - 1; i++) {
        if (*(arreglo + i) > *(arreglo + i + 1)) {
            ptr = arreglo + i + 1;
            break;
        }
    }

    return ptr;
}


void mostrarResultado(int *ptr_desordenado, int *arreglo) {
    if (ptr_desordenado != NULL) {
        printf("El %d esta desordenado y es el elemento numero %d del arreglo.\n", *ptr_desordenado, (int)(ptr_desordenado - arreglo) + 1);
    } else {
        printf("El arreglo está ordenado.\n");
    }
}

void solicitarDatos() {
    int arreglo[30];
    int *ptr_desordenado;

    
    ingresarEnteros(arreglo);

   
    ptr_desordenado = buscar(arreglo);

    
    mostrarResultado(ptr_desordenado, arreglo);
}

int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}


