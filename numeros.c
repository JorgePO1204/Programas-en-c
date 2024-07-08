#include <stdio.h>
//Funcion para verificar que los numeros ingresados son positivos
int contarPositivo(long long int numeros[], int cantidad_numeros, long long int numero) {
    static int cantidad_total = 0; // Declarado como static para persistir entre llamadas
    if (numero >= 0 && cantidad_total < 10000) {
        numeros[cantidad_numeros] = numero;
        cantidad_total++; // Incrementa la cantidad total de números
        cantidad_numeros++; // Incrementa la cantidad de números en este array
    }
    return cantidad_numeros;
}

int ingresarDatos(long long int numeros[]) {
    int cantidad_numeros = 0;
    long long int numero;
    printf("Ingrese los numeros (Recuerda no sobrepasar el limite 10000) : \n");
    do {
        scanf("%lld", &numero); 
        cantidad_numeros = contarPositivo(numeros, cantidad_numeros, numero);
		//cuanta los numeros positivos ingresados
    } while (numero >= 0 && cantidad_numeros < 10000);
	//si sobrepasas el limite de numeros se sale del ciclo 
    return cantidad_numeros;
}
//Funccion para encontrar el valor maximo del arreglo
long long int encontrarMaximo(long long int numeros[], int cantidad_numeros) {
    long long int maximo = numeros[0];
    for (int i = 1; i < cantidad_numeros; i++) {
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
    }
    return maximo;
}
//Funcion para encontrar el valor minimo dentro del arreglo
long long int encontrarMinimo(long long int numeros[], int cantidad_numeros) {
    long long int minimo = numeros[0];
    for (int i = 1; i < cantidad_numeros; i++) {
        if (numeros[i] < minimo) {
            minimo = numeros[i];
        }
    }
    return minimo;
}

void recibirDatos() {
    long long int numeros[10000];
    int cantidad_numeros = ingresarDatos(numeros);
    if (cantidad_numeros > 0) {
        long long int maximo = encontrarMaximo(numeros, cantidad_numeros);
        long long int minimo = encontrarMinimo(numeros, cantidad_numeros);
        printf("El valor mas alto es: %lld\n", maximo);
        printf("El valor mas bajo es: %lld\n", minimo);
        printf("El numero total de numeros ingresados es: %d\n", cantidad_numeros);
    } else {
        printf("No se ingresaron numeros válidos.\n");
    }
}

int main(int argc, char *argv[]) {
    recibirDatos();
    return 0;
}

