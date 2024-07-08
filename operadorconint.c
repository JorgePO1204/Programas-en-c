#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int ix,iy,ia;
	   int numeroUno, numeroDos;
    int limite = 223;
      
   
    srand(time(NULL));
      
    
    ix = rand() % limite+33;
    iy = rand() % limite+33;
      
    printf ("Numero uno=  %d\n",numeroUno);
    printf ("Numero  dos =  %d\n",numeroDos);
    printf ("Numero 1 =  %i\n", ix);
    printf ("Numero 2 = %i\n\n", iy);
    

    printf("\tOperadores aritmeticos\n");
	printf("%d * %d = %d\n", ix, iy, ix * iy);
    printf("%d / %d = %d\n", ix, iy, ix / iy);
    printf("%d %% %d = %d\n", ix, iy, ix % iy);
    printf("%d + %d = %d\n", ix, iy, ix + iy);
    printf("%d - %d = %d\n", ix, iy, ix - iy);
    
    ix++;
    printf("ix++ = %d\n", ix);
    ix--;
    printf("ix-- = %d\n", ix);
    ia = +iy;
    printf("ix = +iy: %d\n", ia);
    ia = -iy;
    printf("ix = -iy: %d\n\n", ia);
	

	printf("\tRelacionales y logicos\n");
    printf("%d > %d: %d\n", ix, iy, ix > iy);
    printf("%d >= %d: %d\n", ix, iy, ix >= iy);
	printf("%d < %d: %d\n", ix, iy, ix < iy);
    printf("%d <= %d: %d\n", ix, iy, ix <= iy);
    printf("%d == %d: %d\n", ix, iy, ix == iy);
    printf("%d != %d: %d\n\n", ix, iy, ix != iy);
    

    printf("\toperadores de Bits\n");
    printf("%d = ~%d: %d\n", ix, ix, ~ix);
    printf("%d & %d: %d\n",  ix, iy, ix & iy);
    printf("%d | %d: %d\n",  ix, iy, ix | iy);
    printf("%d ^ %d: %d\n",  ix, iy, ix ^ iy);
    printf("%d << 1: %d\n",  ix, ix << 1);
    printf("%d >> 1: %d\n\n", ix, ix >> 1);


    printf("\tAsignacion compuesta\n");
    printf("%d += %d: ", ix, iy);
    ia  = (ix += iy);
    printf("%d\n", ia);
    
    printf("%d -= %d: ", ix, iy);
    ia  = (ix-= iy);
    printf("%d\n", ia);
    
    printf("%d *= %d: ", ix, iy);
    ia  = (ix *= iy);
    printf("%d\n", ia);
    
    printf("%d /= %d: ", ix, iy);
    ia= (ix /= iy);
    printf("%d\n", ia);
    
    printf("%d %%= %d: ", ix, iy);
    ia=(ix %= iy);
    printf("%d\n", ia);
    
    printf("%d <<= 1: ", ix);
    ia=(ix <<= 1);
    printf("%d\n", ia);
    
    printf("%d >>= 1: ", ix);
    ia=(ix  >>= 1);
    printf("%d\n", ia);
    
    printf("%d &= %d: ", ix, iy);
    ia=(ix &= iy);
    printf("%d\n", ia);
    
    printf("%d ^= %d: ", ix, iy);
    ia=(ix ^= iy);
    printf("%d\n", ia);
    
    printf("%d |= %d: ", ix, iy);
    ia=(ix |= iy);
    printf("%d\n\n", ia);


    printf("\tCasting o mutacion\n");
    char  c = (char) ix;
    if(ix <= 31 || ix == 127){
        printf("Caracter no imprimible\n", c);
    }else{
        printf("%c\n", c);
    }

    short s = (short) ix;
    printf("%d\n", s);

    long  l = (long) ix;
    printf("%ld\n", l);

    float f = (float) ix;
    printf("%f\n", f);

    double d = (double) ix;
    printf("%lf\n", d);

    return 0;
}