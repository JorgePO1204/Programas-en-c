#include <stdio.h>


int leerNumero() {
    int num;
    printf("Ingrese un numero: ");
    scanf("%i", &num);
    return num;
}


int encontrarMinimo(int num1, int num2, int num3) {
    if (num1 <= num2 && num1 <= num3) {
        return num1;
    } else if (num2 <= num1 && num2 <= num3) {
        return num2;
    } else {
        return num3;
    }
}

void mostrarOrden(int num1, int num2, int num3){

       printf("El orden ascendente es: %i %i %i\n", num1, num2, num3);

}

void mostrarOrdenAscendente(int num1, int num2, int num3) {
    int min = encontrarMinimo(num1, num2, num3);

    if (min == num1) {
        if (num2 <= num3) {
            mostrarOrden(num1, num2, num3);
        } else {
            mostrarOrden( num1, num3, num2);
        }
    } else if (min == num2) {
        if (num1 <= num3) {
            mostrarOrden( num2, num1, num3);
        } else {
            mostrarOrden(num2, num3, num1);
        }
    } else {
        if (num1 <= num2) {
            mostrarOrden(num3, num1, num2);
        } else {
            mostrarOrden(num3, num2, num1);
        }
    }
}

void solicitarDatos(){
 int numeroUno = leerNumero();
    int numeroDos = leerNumero();
    int numeroTres = leerNumero();

    
    mostrarOrdenAscendente(numeroUno, numeroDos, numeroTres);
}

int main(int argc, char *argv[]) {
  
   solicitarDatos();

    return 0;
}