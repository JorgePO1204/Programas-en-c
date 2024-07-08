#include <stdio.h>
#include <string.h>

struct Dato {
    char nombre[40];
    char pais[25];
};

struct Atleta {
    char deporte[30];
    struct Dato personal;
    int numeroMedallas;
};

void leerAtletas(struct Atleta *atletas, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nAtleta %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", (atletas + i)->personal.nombre);
        printf("Pais: ");
        scanf("%s", (atletas + i)->personal.pais);
        printf("Deporte: ");
        scanf("%s", (atletas + i)->deporte);
        printf("Numero de medallas: ");
        scanf("%d", &(atletas + i)->numeroMedallas);
    }
}

void mostrarMasMedallas(struct Atleta *atletas, int cantidad, int maxMedallas) {
    printf("\nAtletas con más medallas:\n");
    for (int i = 0; i < cantidad; i++) {
        if ((atletas + i)->numeroMedallas == maxMedallas) {
            printf("Nombre: %s, Pais: %s, Deporte: %s, Numero de medallas: %d\n",
                   (atletas + i)->personal.nombre, (atletas + i)->personal.pais,
                   (atletas + i)->deporte, (atletas + i)->numeroMedallas);
        }
    }
}

void mostrarMenosMedallas(struct Atleta *atletas, int cantidad, int minMedallas) {
    printf("\nAtletas con menos medallas:\n");
    for (int i = 0; i < cantidad; i++) {
        if ((atletas + i)->numeroMedallas == minMedallas) {
            printf("Nombre: %s, Pais: %s, Deporte: %s, Numero de medallas: %d\n",
                   (atletas + i)->personal.nombre, (atletas + i)->personal.pais,
                   (atletas + i)->deporte, (atletas + i)->numeroMedallas);
        }
    }
}

void imprimirAtletasMasMedallas(struct Atleta *atletas, int cantidad) {
    int maxMedallas = (atletas + 0)->numeroMedallas;

    // Encuentra el máximo número de medallas
    for (int i = 1; i < cantidad; i++) {
        if ((atletas + i)->numeroMedallas > maxMedallas) {
            maxMedallas = (atletas + i)->numeroMedallas;
        }
    }
    mostrarMasMedallas(atletas, cantidad, maxMedallas);
}

void imprimirAtletasMenosMedallas(struct Atleta *atletas, int cantidad) {
    int minMedallas = (atletas + 0)->numeroMedallas;

    // Encuentra el mínimo número de medallas
    for (int i = 1; i < cantidad; i++) {
        if ((atletas + i)->numeroMedallas < minMedallas) {
            minMedallas = (atletas + i)->numeroMedallas;
        }
    }
    mostrarMenosMedallas(atletas, cantidad, minMedallas);
}

void mostrarAtleta(struct Atleta *atletas, int cantidad, int i) {
    printf("\nAtleta encontrado:\n");
    printf("Nombre: %s\n", (atletas + i)->personal.nombre);
    printf("Pais: %s\n", (atletas + i)->personal.pais);
    printf("Deporte: %s\n", (atletas + i)->deporte);
    printf("Numero de medallas: %d\n", (atletas + i)->numeroMedallas);
}

void buscarAtleta(struct Atleta *atletas, int cantidad, char *nombre) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp((atletas + i)->personal.nombre, nombre) == 0) {
            mostrarAtleta(atletas, cantidad, i);
            return;
        }
    }
    printf("Atleta no encontrado.\n");
}

int mostrarMenu() {
    int opcion;
    printf("\nMenu:\n");
    printf("1. Mostrar atletas con más y menos medallas\n");
    printf("2. Buscar atleta por nombre\n");
    printf("3. Cambiar datos de un atleta\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int ingresarAtletas() {
    int cantidadAtletas;
    printf("Ingrese la cantidad de atletas (max. 30): ");
    scanf("%d", &cantidadAtletas);
    return cantidadAtletas;
}

void buscarAtletaMenu(struct Atleta atletas[], int cantidadAtletas) {
    char nombreBuscar[40];
    printf("Ingrese el nombre del atleta a buscar: ");
    scanf("%s", nombreBuscar);
    buscarAtleta(atletas, cantidadAtletas, nombreBuscar);
}

int mostrarMenuCambio() {
    int opcion;
    printf("\n¿Qué dato desea modificar?\n");
    printf("1. Nombre\n");
    printf("2. Pais\n");
    printf("3. Deporte\n");
    printf("4. Numero de medallas\n");
    printf("5. Volver al menu anterior\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void editarAtleta(struct Atleta *atletas, int cantidadAtletas, int i) {
    int opcion;
    do {
        opcion = mostrarMenuCambio();

        switch (opcion) {
            case 1:
                printf("Nuevo nombre: ");
                scanf("%s", (atletas + i)->personal.nombre);
                break;
            case 2:
                printf("Nuevo país: ");
                scanf("%s", (atletas + i)->personal.pais);
                break;
            case 3:
                printf("Nuevo deporte: ");
                scanf("%s", (atletas + i)->deporte);
                break;
            case 4:
                printf("Nuevo numero de medallas: ");
                scanf("%d", &(atletas + i)->numeroMedallas);
                break;
            case 5:
                printf("Volviendo al menú anterior...\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 5);
}

void cambiarDatosAtletaMenu(struct Atleta atletas[], int cantidadAtletas) {
    char nombreCambiar[40];
    printf("Ingrese el nombre del atleta cuyos datos desea cambiar: ");
    scanf("%s", nombreCambiar);

    for (int i = 0; i < cantidadAtletas; i++) {
        if (strcmp((atletas + i)->personal.nombre, nombreCambiar) == 0) {
            editarAtleta(atletas, cantidadAtletas, i);
            return;
        }
    }
    printf("Atleta no encontrado.\n");
}

void ingresarDatos() {
    struct Atleta atletas[30];
    struct Atleta *ptratletas=&atletas[0];
    int cantidadAtletas;

    cantidadAtletas = ingresarAtletas();
    leerAtletas(atletas, cantidadAtletas);

    int opcion;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                imprimirAtletasMasMedallas(ptratletas, cantidadAtletas);
                imprimirAtletasMenosMedallas(ptratletas, cantidadAtletas);
                break;
            case 2:
                buscarAtletaMenu(ptratletas, cantidadAtletas);
                break;
            case 3:
                cambiarDatosAtletaMenu(ptratletas, cantidadAtletas);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 4);
}

int main(int argc, char *argv[]) {
    ingresarDatos();
    return 0;
}