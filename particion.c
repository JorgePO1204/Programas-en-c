#include <stdio.h>

void leerDatos(int *a, int *b) {
    printf("Ingrese un numero entero: ");
    scanf("%d", a);
    printf("Ingrese otro numero entero: ");
    scanf("%d", b);
}

int particion(int M, int N) {
    if (M == 1 || N == 1) {
        return 1;
    } else if (M < N) {
        return particion(M, M);
    } else if (M == N) {
        return 1 + particion(M, M - 1);
    } else {
        return particion(M, N - 1) + particion(M - N, N);
    }
}

int partiIterativa(int M, int N) {
    int table[M + 1][N + 1];
    int i, j;

    for (i = 0; i <= M; i++) {
        for (j = 0; j <= N; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (i == 1 || j == 1)
                table[i][j] = 1;
            else if (i < j)
                table[i][j] = table[i][i];
            else if (i == j)
                table[i][j] = 1 + table[i][i - 1];
            else
                table[i][j] = table[i][j - 1] + table[i - j][j];
        }
    }
    return table[M][N];
}

void ingresarOpcion(int *opc) {
    printf("Seleccione una opcion : \n ");
    printf("1.- Recursivo\n");
    printf("2.- Iterativo\n");
    scanf("%d", opc);
}

void solicitarDatos() {
    int a, b;
    int opc;
	 
    leerDatos(&a, &b);
    ingresarOpcion(&opc);

    if (opc == 1) {
        int resultado = particion(a, b);
        printf("El numero de formas de descomponer %d en %d partes es: %d\n", a, b, resultado);
    } else if (opc == 2) {
        int resultado2 = partiIterativa(a, b);
        printf("El numero de formas de descomponer %d en %d partes es: %d\n", a, b, resultado2);
    } else {
        printf("Opcion invalida.\n");
    }
}

int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}