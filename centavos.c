#include <stdio.h>

int main (int argc, char*argv[]){

 	int cuartos, decimos, quintos, valorMonetario;
 		
 		printf("Ingrese la cantidad de cuartos que tiene : ");
 		scanf ("%i",&cuartos);
 		printf("Ingrese la cantidad de decimos que tiene : ");
 		scanf ("%i",&decimos);
 	        printf("Ingrese la cantidad de quintos que tiene : ");
 		scanf ("%i",&quintos);
 		
 		
 	valorMonetario = (25*cuartos)+(10*decimos)+(5*quintos);
 	
 	        printf("Las monedas valen  %i centavos \n ",valorMonetario);


return 0;
}
