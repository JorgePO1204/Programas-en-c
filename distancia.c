#include <stdio.h>
#include <math.h>



int main ( int argc,char * argv []){

    int tiempo, producto;
    int aceleracion = 32;
    float distancia;
    
    printf("Ingrese el tiempo en segundos : ");
    
    scanf ("%i",&tiempo);
    
    tiempo = pow(tiempo,2);
    
    producto = (aceleracion * tiempo) ;
    
    
    distancia= producto / 2;
    
    printf ("El objetivo avanza una distancia de %.2f pies en caida libre \n  ",distancia);
    


return 0;
}
