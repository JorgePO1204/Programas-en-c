#include <stdio.h>


void sumar(int a, int b, int *ptr) {
    *ptr = a + b;
}


void dividir(int a, int b, float *ptr) {
    if (b != 0) {
        *ptr = (float)a / b;
    } else {
        *ptr = 0.0; 
    }
}


int *multiplicar(int a, int b, int *resultado) {
    *resultado = a * b;
    return resultado;
}


int *restar(int a, int b, int *resultado) {
    *resultado = a - b;
    return resultado;
}


void imprimirArreglo(int *arreglo) {
    printf("Arreglo: [ ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(arreglo + i));
    }
    printf("]\n");
}

void imprimirresultado(int suma, int resta, int multiplicacion, float division, int *arreglo) {
    int *p = arreglo;
    printf("Suma: %d + %d = %d \n", arreglo[*(p + 7)], *(arreglo + 4), suma);
    printf("Resta: %d - %d = %d \n", *(arreglo + 3), *++p, resta);
    printf("Multiplicacion: %d * %d = %d\n", *(arreglo + 7), *(arreglo + 1), multiplicacion);
    printf("Division: %d / %d = %.2f\n", *(++p), *(arreglo + 8), division);
}


void realizarOperacion(int *arreglo) {
    imprimirArreglo(arreglo);
    int *p = arreglo;

    int resultadoSuma;
    sumar(arreglo[*(p + 7)], *(arreglo + 4), &resultadoSuma);

    int resultadoResta;
    int *resultadoRestaPtr = restar(*(arreglo + 3), *++p, &resultadoResta);

    int resultadoMultiplicacion;
    int *resultadoMultiplicacionPtr = multiplicar(*(arreglo + 7), *(arreglo + 1), &resultadoMultiplicacion);

    float resultadoDivision;
    dividir(*++p, *(arreglo + 8), &resultadoDivision);

    imprimirresultado(resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, arreglo);
}

int main(int argc, char *argv[]) {
    int arreglo[10] = {23, 5, 98, 65, 3, 55, 73, 9, 21, 85};
    realizarOperacion(arreglo);
    return 0;
}