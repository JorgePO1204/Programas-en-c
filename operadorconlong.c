#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long main (long argc, char * argv[]){
    long lx,ly,la;
    int numeroUno, numeroDos;
    int limite = 223;
    
    
    srand(time(NULL));
    
    numeroUno = rand() % limite+33;
    numeroDos = rand() % limite+33;

    lx = (long) numeroUno;
    ly = (long) numeroDos;
      
    printf ("Numero uno=  %d\n",numeroUno);
    printf ("Numero  dos =  %d\n",numeroDos);
    printf ("Numero long 1 =  %ld\n",lx);
    printf ("Numero long 2 =  %ld\n\n",ly);

       
	

    printf("\tOperadores aritmeticos\n");
    printf("%ld * %ld = %ld\n", lx, ly, lx * ly);
    printf("%ld / %ld = %ld\n", lx, ly, lx / ly);
    printf("%ld %% %ld = %ld\n", lx, ly, lx % ly);
    printf("%ld + %ld = %ld\n", lx, ly, lx + ly);
    printf("%ld - %ld = %ld\n", lx, ly, lx - ly);

    lx++;
    printf("lx++ = %ld\n", lx);
    lx--;
    printf("lx-- = %ld\n", lx);
    la = +ly;
    printf("lx = +ly: %ld\n", la);
    la = -ly;
    printf("lx = -ly: %ld\n\n", la);


   

    printf("\tRelacionales y logicos\n");
    printf("%ld > %ld: %d\n", lx, ly, lx > ly);
    printf("%ld >= %ld: %d\n", lx, ly, lx >= ly);
    printf("%ld < %ld: %d\n", lx, ly, lx < ly);
    printf("%ld <= %ld: %d\n", lx, ly, lx <= ly);
    printf("%ld == %ld: %d\n", lx, ly, lx == ly);
    printf("%ld != %ld: %d\n\n", lx, ly, lx != ly);
    

 

    printf("\tOperadores de Bits\n");
    printf(" ~%ld: %ld\n", lx, ~lx);
    printf("%ld & %ld: %ld\n",  lx, ly, lx & ly);
    printf("%ld | %ld: %ld\n",  lx, ly, lx | ly);
    printf("%ld ^ %ld: %ld\n",  lx, ly, lx ^ ly);
    printf("%ld << 1: %ld\n",  lx, lx << 1);
    printf("%ld >> 1: %ld\n\n",  lx, lx >> 1);


    

    printf("\tAsignacion compuesta\n");
    printf("%ld += %ld: ", lx, ly);
    la = (lx += ly);
    printf("%ld\n", la);
    
    printf("%ld -= %ld: ", lx, ly);
    la = (lx -= ly);
    printf("%ld\n", la);
    
    printf("%ld *= %ld: ", lx, ly);
    la = (lx *= ly);
    printf("%ld\n", la);
    
    printf("%ld /= %ld: ", lx, ly);
    la = (lx /= ly);
    printf("%ld\n", la);
    
    printf("%ld %%= %ld: ", lx, ly);
    la = (lx %= ly);
    printf("%ld\n", la);
    
    printf("%ld <<= 1: ", lx);
    la = (lx <<= 1);
    printf("%ld\n", la);
    
    printf("%ld >>= 1: ", lx);
    la = (lx >>= 1);
    printf("%ld\n", la);
    
    printf("%ld &= %ld: ", lx, ly);
    la = (lx &= ly);
    printf("%ld\n", la);
    
    printf("%ld ^= %ld: ", lx, ly);
    la = (lx ^= ly);
    printf("%ld\n", la);
    
    printf("%ld |= %ld: ", lx, ly);
    la = (lx |= ly);
    printf("%ld\n\n", la);
	

   

	printf("\tCasting o mutacion\n" ); 
    char  c = (char) lx;
    if(lx <= 31 || lx == 127){
        printf("Caracter no imprimible\n", c);
    }else{
        printf("%c\n", c);
    }
    
    short s = (short)  lx;
    printf("%d\n", s);
    
    int i   = (int)   lx;
    printf("%d\n", i);
    
    float f = (float)  lx;
    printf("%f\n", f);
    
    double d = (double) lx;
    printf("%lf\n", d);

    return 0;
}