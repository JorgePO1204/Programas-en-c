#include <stdio.h>

int main (int argc, char*argv[]){
     
     int numeroUno,numeroDos,suma,producto;
     
     printf("Escribe el primer numero : ");
     scanf ("%i", &numeroUno);
     
     printf("Escribe el segundo numero : ");
     scanf ("%i", &numeroDos);
     
     suma = numeroUno + numeroDos;
     producto= numeroUno * numeroDos;
     
     
     printf("El resultado de la suma es  :   %i + %i = %i \n ",numeroUno,numeroDos,suma);
     
     
     printf("El resultado del producto es :  %i * %i = %i \n ",numeroUno,numeroDos,producto);


     printf("Este es el fin del programa\n ");

return 0;
}
