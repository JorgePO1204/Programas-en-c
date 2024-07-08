#include <stdio.h>


void leerDatos(int *a, int *b) {
    printf("Ingrese un numero entero: ");
    scanf("%d", a);
    printf("Ingrese otro numero entero: ");
    scanf("%d", b);
}


int hacerEuclides(int M, int N) {
    if (N == 0)
        return M;
    else
        return hacerEuclides(N, M % N);
}
int hacerEuclidesite(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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
       int mcd = hacerEuclides(a, b); 
         printf("El MCD de %d y %d es: %d\n", a, b, mcd); 
    } else if (opc == 2) {
       int mcd2 = hacerEuclidesite(a, b); 
         printf("El MCD de %d y %d es: %d\n", a, b, mcd2); 
    } else {
        printf("Opcion invalida.\n");
    }
    
}

int main(int argc, char *argv[]) {
    solicitarDatos(); 
    return 0;
}
