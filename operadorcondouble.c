#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double main (double argc, char * argv[]){
    double dx,dy,da;
    int numeroUno, numeroDos, numeroTres, numeroCuatro;
    int limite = 100;
    
    //Creando semilla generadora de numeros aleatorios
    srand(time(NULL));
    
    //Genera cuatro numeros aleatorios
    numeroUno = rand() % limite;
    numeroDos = rand() % limite;
    numeroTres = rand() % limite;
    numeroCuatro = rand() % limite;
  
    dx = (double) numeroUno + numeroTres / 100.0;
    dy = (double) numeroDos + numeroCuatro / 100.0;  
 
    //Imprime dos numeros aleatorios
    printf ("Numero double 1 =  %lf\n",dx);
    printf ("Numero double 2 =  %lf\n\n",dy);


	printf("\tOperadores aritmeticos\n");
    printf("%.2lf * %.2lf = %.2lf\n", dx, dy, dx * dy);
    printf("%.2lf / %.2lf = %.2lf\n", dx, dy, dx / dy);
    printf("%.2lf + %.2lf = %.2lf\n", dx, dy, dx + dy);
    printf("%.2lf - %.2lf = %.2lf\n\n", dx, dy, dx - dy);
	

    printf("\tRelacionales y logicos\n");
    printf("%.2lf > %.2lf: %d\n", dx, dy, dx > dy);
    printf("%.2lf >= %.2lf: %d\n", dx, dy, dx >= dy);
    printf("%.2lf < %.2lf: %d\n", dx, dy, dx < dy);
    printf("%.2lf <= %.2lf: %d\n", dx, dy, dx <= dy);
    printf("%.2lf == %.2lf: %d\n", dx, dy, dx == dy);
    printf("%.2lf != %.2lf: %d\n\n", dx, dy, dx != dy);


    printf("\tAsignacion compuesta\n");
    printf("%.2lf += %.2lf: ", dx, dy);
    da = (dx += dy);
    printf("%.2lf\n", da);
    
    printf("%.2lf -= %.2lf: ", dx, dy);
    da = (dx -= dy);
    printf("%.2lf\n", da);
    
    printf("%.2lf *= %.2lf: ", dx, dy);
    da = (dx *= dy);
    printf("%.2lf\n", da);
    
    printf("%.2lf /= %.2lf: ", dx, dy);
    da = (dx /= dy);
    printf("%.2lf\n\n", da);
	   

    printf("\tCasting o mutacion\n");
	char  c = (char) dx;
    if(dx <= 31 || dx == 127){
        printf("Caracter no imprimible\n", c);
    }else{
        printf("%c\n", c);
    }

    short s = (short) dx;
    printf("%d\n", (s));
    
    int i = (int) dx;
    printf("%d\n", (i));
    
    long l = (long) dx;
    printf("%ld\n", (l));
    
    float f = (float) dx;
    printf("%f\n", (f));

    return 0;
}