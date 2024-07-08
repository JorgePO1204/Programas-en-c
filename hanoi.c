#include <stdio.h>
#include <math.h>

int contador = 1; 

void leerDatos(int *N) {
    printf("Ingrese el número de discos: ");
    scanf("%d", N);
}
void hanoi(int N, char origen, char destino, char auxiliar, int disco) {
    if (N == 1) {
        printf("%d. Mover el disco %d de %c a %c\n", contador++, disco, origen, destino);
    } else {
        hanoi(N - 1, origen, auxiliar, destino, disco - 1);
        printf("%d. Mover el disco %d de %c a %c\n", contador++, disco, origen, destino);
        hanoi(N - 1, auxiliar, destino, origen, disco - 1);
    }
}

void moverDisco(int disco, char origen, char destino) {
    printf("%d. Mover el disco %d de %c a %c\n", contador++, disco, origen, destino);
}

void hanoiIterativo(int N) {
    char torre[3] = {'A', 'B', 'C'}; 
    int totalMovimientos = pow(2, N) - 1; 

    for (int i = 1; i <= totalMovimientos; i++) {
        int disco = __builtin_ctz(i) + 1; 
        int origen, destino;

        if (N % 2 == 0) {
            switch (i % 3) {
                case 1:
                    origen = 0; destino = 1; break;
                case 2:
                    origen = 0; destino = 2; break;
                case 0:
                    origen = 1; destino = 2; break;
            }
        } else {
            switch (i % 3) {
                case 1:
                    origen = 0; destino = 2; break;
                case 2:
                    origen = 0; destino = 1; break;
                case 0:
                    origen = 1; destino = 2; break;
            }
        }

  
        if (i % 3 == 0) {
            int temp = origen;
            origen = destino;
            destino = temp;
        }

        moverDisco(disco, torre[origen], torre[destino]);
    }
}

void ingresarOpcion(int *opc) {
    printf("Seleccione una opcion : \n");
    printf("1.- Recursivo\n");
    printf("2.- Iterativo\n");
    scanf("%d", opc);
}

void solicitarDatos() {
    int N;
    int opc;
    leerDatos(&N);
    ingresarOpcion(&opc);
    if (opc == 1) {
         hanoi(N, 'A', 'C', 'B', N);
    } else if (opc == 2) {
        hanoiIterativo(N);
    } else {
        printf("Opcion invalida.\n");
    }
}

int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}
