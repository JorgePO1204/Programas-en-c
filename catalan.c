#include <stdio.h>

void leerDato(int *a) {
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", a);
}

long long catalan(int n) {
    if (n <= 1) {
        return 1;
    }else{
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += catalan(i) * catalan(n - i - 1);
    }
    return s;
    }
}
long long catalanite(int n) {
    if (n <= 1) {
        return 1;
    }else{
    
    long long result = 1;
    
    for (int i = 2; i <= n; i++) {
        result = result * (4 * i - 2) / (i + 1);
    }
    
    return result;
    }
}
void ingresarOpcion(int *opc) {
    printf("Seleccione una opcion : \n ");
    printf("1.- Recursivo\n");
    printf("2.- Iterativo\n");
    scanf("%d", opc);
}

void solicitarDatos() {
    int a;
    int opc;
    leerDato(&a);
    ingresarOpcion(&opc);
    if (opc == 1) {
          printf("El numero de Catalan para %d es: %lld\n", a, catalan(a));
    } else if (opc == 2) {
          printf("El numero de Catalan para %d es: %lld\n", a, catalanite(a));
    } else {
        printf("Opcion invalida.\n");
    }
  
}

int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}

