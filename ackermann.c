#include <stdio.h>

void leerDatos(int *a, int *b) {
    printf("Ingrese un numero entero: ");
    scanf("%d", a);
    printf("Ingrese otro numero entero: ");
    scanf("%d", b);
}

int hacerAckermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return hacerAckermann(m - 1, 1);
    } else {
        return hacerAckermann(m - 1, hacerAckermann(m, n - 1));
    }
}
int ackermannite(int m, int n) {
    while (m > 0) {
        if (n == 0) {
            n = 1;
            m = m - 1;
        } else {
            n = n - 1;
            n = ackermannite(m, n);
            m = m - 1;
        }
    }
    return n + 1;
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
       int resul = hacerAckermann(a, b);
    printf("Ackermann ( %d , %d ) = %d\n", a, b, resul);
    } else if (opc == 2) {
       int resul2 =ackermannite(a, b);
    printf("Ackermann ( %d , %d ) = %d\n", a, b, resul2);
    } else {
        printf("Opcion invalida.\n");
    }
    
}

int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}