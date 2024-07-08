#include <stdio.h>
// Función para encontrar el máximo de dos números
int encontrarMaximo(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
// Función para encontrar el mínimo de dos números
int encontrarMinimo(int a, int b) {
     if (a < b) {
        return a;
    } else {
        return b;
    }
}
void imprimirResultados(int max_num,int min_num,int contador){
      printf("El valor mas alto ingresado es: %d\n", max_num);
    printf("El valor mas bajo ingresado es: %d\n", min_num);
    printf("El numero total de numeros ingresados es: %d\n", contador);
}

void solicitarDatos(){
      int num, max_num = -999999, min_num = 999999, contador = 0;

    // Lectura de números
    printf("Ingrese numeros enteros (ingrese un numero negativo para terminar):\n");
    do {
        scanf("%d", &num);

        // Verificar si el número es negativo
        if (num >= 0) {
            max_num = encontrarMaximo(max_num, num);
            min_num = encontrarMinimo(min_num, num);
            contador++;
        }
    } while (num >= 0);
  imprimirResultados(max_num,min_num,contador);
}

// Función principal
int main(int argc, char *argv[]) {
  solicitarDatos();
    return 0;
}
