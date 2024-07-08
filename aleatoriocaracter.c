#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	char rep;
	
	do{
		srand(time(NULL));

		int caracter = (rand() % 223) + 33;
		
		printf("%c\n", caracter);
		printf("Desea generar otro caracter ? (S/N): ");
		scanf("%c", &rep);
		getchar();
	}while(rep != 'N');
	
	return 0;
}
