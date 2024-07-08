#include <stdio.h>

void leerDatos(int *n, int *k) {
    do {
        printf("El numero n debe ser igual o mayor a k\n");
        printf("Ingrese n: ");
        scanf("%d", n);
        printf("Ingrese k: ");
        scanf("%d", k);
    } while (*n < *k);
}

int coeficienteBinomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return coeficienteBinomial(n - 1, k - 1) + coeficienteBinomial(n - 1, k);
    }
}

int coeficienteBinomialIterativo(int n, int k) {
    int res = 1;
    if (k > n - k) {
        k = n - k;
    }
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void ingresarOpcion(int *opc) {
    printf("Seleccione una opcion: \n");
    printf("1.- Recursivo\n");
    printf("2.- Iterativo\n");
    scanf("%d", opc);
}

void solicitarDatos() {
    int n, k, opc;
    leerDatos(&n, &k);
    ingresarOpcion(&opc);
    if (opc == 1) {
        printf("El coeficiente binomial de %d sobre %d es %d\n", n, k, coeficienteBinomial(n, k));
    } else if (opc == 2) {
        printf("El coeficiente binomial de %d sobre %d es %d\n", n, k, coeficienteBinomialIterativo(n, k));
    } else {
        printf("Opcion invalida.\n");
    }
}

int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}

