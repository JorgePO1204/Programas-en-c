#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float main (float argc, char * argv[]){
    float fx,fy,fa;
    int numeroUno, numeroDos, numeroTres, numeroCuatro;
    int limite = 223;
      
    
    srand(time(NULL));
    
    
    numeroUno = rand() % limite+33;
    numeroDos = rand() % limite+33;
    numeroTres = rand() % limite+33;
    numeroCuatro = rand() % limite+33;

    fx = (float) numeroUno + numeroTres / 100.0;
    fy = (float) numeroDos + numeroCuatro / 100.0;

    printf ("Numero uno=  %d\n",numeroUno);
    printf ("Numero  dos =  %d\n",numeroDos);
	printf ("Numero tres=  %d\n",numeroTres);
    printf ("Numero  cuatro =  %d\n",numeroCuatro);
    printf ("Numero float 1 =  %f\n",fx);
    printf ("Numero float 2 =  %f\n\n",fy);


	printf("\tOperadores aritmeticos\n");
    printf("%.2f * %.2f = %.2f\n", fx, fy, fx * fy);
    printf("%.2f / %.2f = %.2f\n", fx, fy, fx / fy);
    printf("%.2f + %.2f = %.2f\n", fx, fy, fx + fy);
    printf("%.2f - %.2f = %.2f\n", fx, fy, fx - fy);
    
    fx++;
    printf("fx++ = %.2f\n", fx);
    fx--;
    printf("fx-- = %.2f\n", fx);
    fa = +fy;
    printf("fx = +iy: %.2f\n", fa);
    fa = -fy;
    printf("fx = -iy: %.2f\n\n", fa);
	

    printf("\tRelacionales y logicos\n");
    printf("%.2f > %.2f: %d\n", fx, fy, fx > fy);
    printf("%.2f >= %.2f: %d\n", fx, fy, fx >= fy);
    printf("%.2f < %.2f: %d\n", fx, fy, fx < fy);
    printf("%.2f <= %.2f: %d\n", fx, fy, fx <= fy);
    printf("%.2f == %.2f: %d\n", fx, fy, fx == fy);
    printf("%.2f != %.2f: %d\n\n", fx, fy, fx != fy);


    printf("\tAsignacion compuesta\n");
    printf("%.2f += %.2f: ", fx, fy);
    fa = (fx += fy);
    printf("%.2f\n", fa);
    
    printf("%.2f -= %.2f: ", fx, fy);
    fa = (fx-= fy);
    printf("%.2f\n", fa);
    
    printf("%.2f *= %.2f: ", fx, fy);
    fa = (fx *= fy);
    printf("%.2f\n", fa);
    
    printf("%.2f /= %.2f: ", fx, fy);
    fa = (fx /= fy);
    printf("%.2f\n\n", fa);


    printf("\tCasting o mutacion\n");
    char  c = (char) fx;
    if(fx <= 31 || fx == 127){
        printf("Caracter no imprimible\n", c);
    }else{
        printf("%c\n", c);
    }

    short s = (short)  fx;
    printf("%d\n", (s));

    int i   = (int)   fx;
    printf("%d\n", (i));

    long  l = (long)   fx;
    printf("%ld\n", (l));

    double d = (double) fx;
    printf("%.2lf\n", (d));

    return 0;
}