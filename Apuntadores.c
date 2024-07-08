#include <stdio.h>

void imprimirSalida(int arreglo[]) {
int *p;
p = arreglo;
    for(int i=0; i<10; i++){
        printf("%p  ", &arreglo[i]);
    }

    printf("\n\n");
	printf(" [");
    for(int i=0; i<10; i++){
        printf("%d  ", arreglo[i]);
    }

printf(" ] \n \n");
printf("{23, 5, 98, 65, 3, 55, 73, 9, 21, 85} la aritmetica de apuntadores  hace que apunte arreglo  Arreglo[Arreglo[7]]=Arreglo[9] enconce  reorre el arreglo hasta la posicion  Arreglo[9]=85\n");
printf (" %d\n", arreglo[*(p + 7)]);
printf (" %p\n\n", &arreglo[*(p + 7)]);
printf("{23, 5, 98, 65, 3, 55, 73, 9, 21, 85} el puntero esta apuntando a la posicion Arreglo[0]=23, y despues a ese elemento le suma 3 siendo igal a 26 \n");
printf (" %d\n", *arreglo + 3);
printf (" %p\n\n", p);
printf("incrementa el valor del puntero p y lo mueve a la siguiente posicion\n");
printf("{23, 5, 98, 65, 3, 55, 73, 9, 21, 85} imprime el valor de la posicion el la que esta apuntado A[0]=23 y luego recorre el apuntador a la siguiente posicion A[1]=5 \n");
printf (" %d\n", *p++);
printf (" %p\n\n", p);
printf("{23, 5, 98, 65, 3, 55, 73, 9, 21, 85} la aritmetica de apuntadores hace que se imprima el valor que se encuentra en la posicion Arreglo[2]=5 \n");
printf(" %d\n", *(arreglo + 1));
printf(" %p\n\n", p);
printf("Aumenta el valor del numero en la posicion arreglo[1] +1 siendo igual a 6\n");
printf("{23, 5, 98, 65, 3, 55, 73, 9, 21, 85} imprime el valor de la posicion Arreglo[1]=5  y luego al elemento le suma uno y la aritmetica de apuntadores lo  guarda en esa posicion Arreglo[1]=6 \n");
printf(" %d\n", (*p)++);
printf(" %p\n\n", p);
printf("imprime el valor del numero que se en la que se ubica el puntero que es 6 por ser aumentado en el renglo anterior\n");
printf("{23, 6, 98, 65, 3, 55, 73, 9, 21, 85} imprime el valor al que esta apuntando Arreglo[1]=6 \n");
printf(" %d\n", *p);
printf(" %p\n\n", p);
printf("incrementa el valor del puntero p y lo mueve a la siguiente posicion\n");
printf("{23, 6, 98, 65, 3, 55, 73, 9, 21, 85} imprime el valor al que esta apuntando Arreglo[1]=6 y luego lo recorre a la siguiente posicion Arreglo[2]=98\n");
printf(" %d\n", *p++);
printf(" %p\n\n", p);
printf("Imprime el valor de la posicion en la que se encuentra el puntero arreglo[2]\n");
printf("{23, 6, 98, 65, 3, 55, 73, 9, 21, 85} imprime el elemento al que esta apuntando Arreglo[2]=98 \n");
printf(" %d\n", *p);
printf(" %p\n\n", p);
//impresion
//85
//26
//23
//5
//5
//6
//6
//98
printf("Arreglo Final [ ");
for(int j=0;j<10;j++){
    printf("%d ",arreglo[j]);
}
printf(" ] \n\n ");


}

int main(int argc, char *argv[]) {
//Se declara el arreglo 
int arreglo[10] = {23, 5, 98, 65, 3, 55, 73, 9, 21, 85};
//Hace que se ejecute la funcion imprimir salida
imprimirSalida(arreglo);
return 0;
}