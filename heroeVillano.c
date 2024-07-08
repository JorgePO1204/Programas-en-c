#include <stdio.h>

// Función para obtener el género del usuario
int obtenerGenero() {
    int genero;
    printf("Ingrese el genero (H:1, M:0): ");
    scanf("%d", &genero);
    return genero;
}

// Función para determinar si es héroe o villano
int obtenerHeroeOvillano(int genero) {
    int heroeOvillano;
    printf("Es superheroe o villano? (heroe: 1, villano: 0): ");
    scanf("%d", &heroeOvillano);
    return heroeOvillano;
}

// Función para obtener la comida preferida
int obtenerComidaPreferida() {
    int comidaPreferida;
    printf("Le gusta sushi o bistec? (sushi: 1, bistec: 0): ");
    scanf("%d", &comidaPreferida);
    return comidaPreferida;
}

// Función para obtener si le gusta lo animado o la comedia
int obtenerComediaOAnimado(int genero) {
    int comediaOanimado;
    printf("Le gusta lo animado o comedia? (animado: 1, comedia: 0): ");
    scanf("%d", &comediaOanimado);
    return comediaOanimado;
}
void corteCopete(){
printf("\nDeberia hacerse un corte con copete\n\n");
printf("Es un hombre heroe que le gusta el sushi y se va a hacer un corte con copete\n\n");
}
void corteSupertior(){
printf("\nDeberia pedir un corte de parte superior plana\n\n");
printf("Es un hombre heroe que le gusta el bistec y se va a hacer un corte de parte superior plana\n\n");
}
void corteMohicano(){
	printf("\nDeberia pedir un corte mohicano\n\n");
    printf("Es un hombre villano que se va a hacer un mohicano\n\n");
}
void corteFlequillo(){
	printf("\nDeberia hacerse un corte con flequillo\n\n");
    printf("Es una mujer heroina que le gusta lo animado y se va a hacer un corte con flequillo\n\n");
}
void corteSacudida(){
printf("\nDeberia pedir un corte con sacudida \n\n");
printf("Es una mujer heroina que le gusta la comedia y se va a hacer un corte con sacudida\n\n");
}

// Función para determinar el corte de pelo según las preferencias
void determinarCortePelo(int genero, int heroeOvillano, int comidaPreferida, int comediaOanimado) {
    if (genero == 1) { // Hombre
        if (heroeOvillano == 1) { // Héroe
            if (comidaPreferida == 1) {
                corteCopete();
            } else {
                corteSupertior();
            }
        } else { // Villano
                corteMohicano();
        }
    } else { // Mujer
        if (heroeOvillano == 1) { // Héroe
            if (comediaOanimado == 1) {
                corteFlequillo();
            } else {
                corteSacudida();
            }
        } else { // Villana
            printf("\nEs una supervillana, deberia pedir un corte mohicano\n\n");
        }
    }
}

int main(int argc, char* argv[]) {
    int genero, heroeOvillano, comidaPreferida, comediaOanimado;

    genero = obtenerGenero();
    heroeOvillano = obtenerHeroeOvillano(genero);

    if (genero == 1 && heroeOvillano == 1) {
        comidaPreferida = obtenerComidaPreferida();
    } else if (genero == 0 && heroeOvillano == 1) {
        comediaOanimado = obtenerComediaOAnimado(genero);
    }

    determinarCortePelo(genero, heroeOvillano, comidaPreferida, comediaOanimado);

    return 0;
}