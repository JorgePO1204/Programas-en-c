#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (int argc, char * argv[]){
    unsigned char cx, cy, ca;
    int numeroUno, numeroDos;
    int limite = 223;
    
    
    srand(time(NULL));
    
   
    numeroUno = (rand() % limite) + 33;
    numeroDos = (rand() % limite) + 33;
      
    cx = (char) numeroUno;
    cy =  (char) numeroDos;
      
	 printf ("Numero uno =  %d\n",numeroUno);
    printf ("Numero dos =  %d\n\n",numeroDos);  
    printf ("Char 1 =  %c\n",cx);
    printf ("Char 2 =  %c\n\n",cy);
	


    printf("\tOperadores aritmeticos\n");
    printf("%c * %c = %c\n", cx, cy, cx * cy);
    int vueltas = cx * cy;
    printf("El resultado es: %d\n", vueltas);
    printf("Las vueltas que dio son: %d\n", vueltas / 223);
	printf("El valor del caracter obtenido es : %d\n",(vueltas%256));
    printf("%c / %c = %c\n", cx, cy, cx / cy);
	vueltas= cx/cy;
	if (vueltas<=33){
	printf("Caracter no imprimible %d\n",(vueltas%256));
	}
    printf("%c %% %c = %c\n", cx, cy, cx % cy);
	vueltas= cx%cy;
	if (vueltas<=33){
	printf("Caracter no imprimible %d\n",(vueltas%256));
	}
    printf("%c + %c = %c\n", cx, cy, cx + cy);
    printf("%c - %c = %c\n", cx, cy, cx - cy);

    cx++;
    printf("cx++ = %c\n", cx);
    cx--;
    printf("cx-- = %c\n", cx);
    ca = +cy;
    printf("cx = +cy: %c\n", ca);
    ca = -cy;
    printf("cx = -cy: %c\n\n", ca);

    
    
    printf("\t Relacional y logicos\n");
    printf("%c > %c: %c", cx, cy, cx > cy);
	vueltas =(cx > cy);
	if (vueltas<=33){
	printf("\t%d\n",(vueltas%256));
	}
    printf("%c >= %c: %c", cx, cy, cx >= cy);
	vueltas =(cx >= cy);
	if (vueltas<=33){
	printf("\t%d\n",(vueltas%256));
	}
    printf("%c < %c: %c", cx, cy, cx < cy);
	vueltas =(cx < cy);
	if (vueltas<=33){
	printf("\t%d\n",(vueltas%256));
	}
    printf("%c <= %c: %c", cx, cy, cx <= cy);
	vueltas =(cx <= cy);
	if (vueltas<=33){
	printf("\t%d\n",(vueltas%256));
	}
    printf("%c == %c: %c", cx, cy, cx == cy);
	vueltas =(cx == cy);
	if (vueltas<=33){
	printf("\t%d\n",(vueltas%256));
	}
    printf("%c != %c: %c", cx, cy, cx != cy);
	vueltas =(cx != cy);
	if (vueltas<=33){
	printf("\t%d\n\n",(vueltas%256));
	}
    

   

    printf("\tOperadores de Bits\n");
    printf("%c = ~%c: %c\n", cx, cx, ~cx);
	vueltas =(~cx);
	if (vueltas<=33){
	printf("Caracter no imprimible %d\n",(vueltas%256));
	}
    printf("%c = %c & %c: %c\n", cx, cx, cy, cx & cy);
    printf("%c = %c | %c: %c\n", cx, cx, cy, cx | cy);
    printf("%c = %c ^ %c: %c\n", cx, cx, cy, cx ^ cy);
    printf("%c = %c << 1: %c\n", cx, cx, cx << 1);
    printf("%c = %c >> 1: %c\n\n", cx, cx, cx >> 1);

    

    printf("\tAsignacion compuesta\n");
    printf("%c += %c: ", cx, cy);
    ca = (cx += cy);
    printf("%c\n", ca);
    
    printf("%c -= %c: ", cx, cy);
    ca = (cx -= cy);
    printf("%c\n", ca);
    
    printf("%c *= %c: ", cx, cy);
    ca = (cx *= cy);
    printf("%c\n", ca);
    
    printf("%c /= %c: ", cx, cy);
    ca = (cx /= cy);
    printf("%c\n", ca);
	vueltas= (cx/=cy);
	if (vueltas<33){
	printf("Caracter no imprimible %d\n",(vueltas%256));
	}
    
    printf("%c %%= %c: ", cx, cy);
    ca = (cx %= cy);
    printf("%c\n", ca);
    vueltas= (cx%=cy);
	if (vueltas<33){
	printf("Caracter no imprimible %d\n",(vueltas%256));
	}
    printf("%c <<= 1: ", cx);
    ca = (cx <<= 1);
    printf("%c\n", ca);
    vueltas= (cx <<= 1);
	if (vueltas<33){
	printf("Caracter no imprimible %d\n",(vueltas%256));
	}
    printf("%c >>= 1: ", cx);
    ca = (cx >>= 1);
    printf("%c\n", ca);
    vueltas= (cx >>= 1);
	if (vueltas<33){
	printf("Caracter no imprimible %d\n",(vueltas%256));
	}
    printf("%c &= %c: ", cx, cy);
    ca = (cx &= cy);
    printf("%c\n", ca);
	vueltas= (cx &= cy);
	if (vueltas<33){
	printf("Caracter no imprimible %d\n",(vueltas%256));
	}
    
    printf("%c ^= %c: ", cx, cy);
    ca = (cx ^= cy);
    printf("%c\n", ca);
    
    printf("%c |= %c: ", cx, cy);
    ca = (cx |= cy);
    printf("%c\n\n", ca);


   
	   
	printf("\tCasting o mutacion\n" ); 
    short s = (short)  cx;
    printf("%d\n", s);
    
    int i = (int)    cx;
    printf("%d\n", i);
    
    long  l = (long)   cx;
    printf("%ld\n", l);
    
    float f = (float)  cx;
    printf("%f\n", f);
    
    double d = (double) cx;
    printf("%lf\n", d);

    return 0;
}