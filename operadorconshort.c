#include <stdio.h>
#include <time.h>
#include <stdlib.h>

short main (int argc, char * argv[]){
    short sx,sy,sa;
    int numeroUno, numeroDos;
    int limite = 223;
    
    
    srand(time(NULL));
    
 
    numeroUno = rand() % limite+33;
    numeroDos = rand() % limite+33;
      
    sx = (short) numeroUno;
    sy = (short) numeroDos;
      
     printf ("Numero uno=  %d\n",numeroUno);
    printf ("Numero  dos =  %d\n",numeroDos);
    printf ("Numero short 1 =  %d\n",sx);
    printf ("Numero short 2 =  %d\n\n",sy);


   

    printf("\tOperadores aritmeticos\n");
    printf("%hd * %hd = %hd\n", sx, sy, sx * sy);
    printf("%hd / %hd = %hd\n", sx, sy, sx / sy);
    printf("%hd %% %hd = %hd\n", sx, sy, sx % sy);
    printf("%hd + %hd = %hd\n", sx, sy, sx + sy);
    printf("%hd - %hd = %hd\n", sx, sy, sx - sy);

    sx++;
    printf("sx++ = %hd\n", sx);
    sx--;
    printf("sx-- = %hd\n", sx);
    sa = +sy;
    printf("sx = +sy: %hd\n", sa);
    sa = -sy;
    printf("sx = -sy: %hd\n\n", sa);


    

    printf("\tRelacionales y logicos\n");
    printf("%hd > %hd: %d\n", sx, sy, sx > sy);
    printf("%hd >= %hd: %d\n", sx, sy, sx >= sy);
    printf("%hd < %hd: %d\n", sx, sy, sx < sy);
    printf("%hd <= %hd: %d\n", sx, sy, sx <= sy);
    printf("%hd == %hd: %d\n", sx, sy, sx == sy);
    printf("%hd != %hd: %d\n\n", sx, sy, sx != sy);

    
    

    printf("\tOperadores de Bits\n");
    printf("%hd = ~%hd: %hd\n", sx, sx, (short)~sx);
    printf("%hd & %hd: %hd\n",  sx, sy, (short)(sx & sy));
    printf("%hd | %hd: %hd\n",  sx, sy, (short)(sx | sy));
    printf("%hd ^ %hd: %hd\n",  sx, sy, (short)(sx ^ sy));
    printf("%hd << 1: %hd\n", sx, sx, (short)(sx << 1));
    printf("%hd >> 1: %hd\n\n", sx, sx, (short)(sx >> 1));


  

    printf("\tAsignacion compuesta\n");
    printf("%hd += %hd: ", sx, sy);
    sa = (sx += sy);
    printf("%hd\n", sa);
    
    printf("%hd -= %hd: ", sx, sy);
    sa = (sx -= sy);
    printf("%hd\n", sa);
    
    printf("%hd *= %hd: ", sx, sy);
    sa = (sx *= sy);
    printf("%hd\n", sa);
    
    printf("%hd /= %hd: ", sx, sy);
    sa = (sx /= sy);
    printf("%hd\n", sa);
    
    printf("%hd %%= %hd: ", sx, sy);
    sa = (sx %= sy);
    printf("%hd\n", sa);
    
    printf("%hd <<= 1: ", sx);
    sa = (sx <<= 1);
    printf("%hd\n", sa);
    
    printf("%hd >>= 1: ", sx);
    sa = (sx >>= 1);
    printf("%hd\n", sa);
    
    printf("%hd &= %hd: ", sx, sy);
    sa = (sx &= sy);
    printf("%hd\n", sa);
    
    printf("%hd ^= %hd: ", sx, sy);
    sa = (sx ^= sy);
    printf("%hd\n", sa);
    
    printf("%hd |= %hd: ", sx, sy);
    sa = (sx |= sy);
    printf("%hd\n\n", sa);
	

    

	printf("\tCasting o mutacion\n" ); 
    char  c = (char) sx;
    if(sx <= 31 || sx == 127){
        printf("Caracter no imprimible\n", c);
    }else{
        printf("%c\n", c);
    }
    
    int i = (int) sx;
    printf("%d\n", i);
    
    long l = (long)   sx;
    printf("%ld\n", l);
    
    float f = (float) sx;
    printf("%f\n", f);
    
    double d = (double) sx;
    printf("%lf\n", d);

    return 0;
}