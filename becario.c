#include <stdio.h>
#include <string.h>

#define MAX_ALU 33
#define MAX_MATERIAS 100

struct Becario {
    char genero[20];
    char nombreCompleto[50];
    char boleta[11];
    int edad;
    int sueldo;
    int numMaterias;
    char materias[MAX_MATERIAS][50];
    float calificaciones[MAX_MATERIAS];
    char horario[50];
};

void verInformacionBecario(struct Becario becario) {
    printf("Genero: %s\n", becario.genero);
    printf("Nombre: %s\n", becario.nombreCompleto);
    printf("Boleta: %s\n", becario.boleta);
    printf("Edad: %d\n", becario.edad);
    if (becario.sueldo > 0) {
        printf("Sueldo: %d\n", becario.sueldo);
    }
    if (becario.numMaterias > 0) {
        printf("Materias:\n");
        for (int i = 0; i < becario.numMaterias; i++) {
            printf("- %s: %.2f\n", *(becario.materias + i), *(becario.calificaciones + i));
        }
    }
    printf("Horario: %s\n", becario.horario);
}

void inscribirBecario(struct Becario *unBecario) {
    int opcion;

    printf("Genero: ");
    fgets(unBecario->genero, 20, stdin);
    *(unBecario->genero + strcspn(unBecario->genero, "\n")) = '\0';

    printf("Nombre completo: ");
    fgets(unBecario->nombreCompleto, 50, stdin);
    *(unBecario->nombreCompleto + strcspn(unBecario->nombreCompleto, "\n")) = '\0';

    printf("Edad: ");
    scanf("%d", &unBecario->edad);
    while (getchar() != '\n'); 

    printf("Boleta: ");
    fgets(unBecario->boleta, 11, stdin);
    *(unBecario->boleta + strcspn(unBecario->boleta, "\n")) = '\0';

    printf("Horario: ");
    fgets(unBecario->horario, 50, stdin);
    *(unBecario->horario + strcspn(unBecario->horario, "\n")) = '\0';

    printf("1.- Estudiante\n");
    printf("2.- Empleado\n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion == 1) {
        int num_materias, i;
        printf("Ingrese la cantidad de materias: ");
        scanf("%d", &num_materias);
        unBecario->numMaterias = num_materias;
        getchar(); 

        for (i = 0; i < num_materias; i++) {
            printf("Ingrese el nombre de la materia %d: ", i + 1);
            fgets(*(unBecario->materias + i), 50, stdin);
            *(*(unBecario->materias + i) + strcspn(*(unBecario->materias + i), "\n")) = '\0';

            printf("Ingrese la calificacion de la materia %d: ", i + 1);
            scanf("%f", unBecario->calificaciones + i);
            getchar(); 
        }
    } else if (opcion == 2) {
        printf("Sueldo: ");
        scanf("%d", &unBecario->sueldo);
        while (getchar() != '\n'); 
    } else {
        printf("Opción no válida\n");
    }
}

void verInformacionDeGrupo(struct Becario *becarios, int conteo) {
    int n;
    for (n = 0; n < conteo; n++) {
        verInformacionBecario(*(becarios + n));
    }
}

void buscarPorGenero(struct Becario *becarios, struct Becario *buscados, int conteo, int *numeroEncontrados) {
    char elGenero[20];
    int longitud, n, m;
    printf("Masculino o Femenino: ");
    fgets(elGenero, 20, stdin);
    longitud = strlen(elGenero);
    *(elGenero + longitud - 1) = '\0';
    while (getchar() != '\n');
    for (n = 0, m = 0; n < conteo; n++) {
        if (strcmp(elGenero, (becarios + n)->genero) == 0) {
            *(buscados + m) = *(becarios + n);
            m++;
        }
    }
    *numeroEncontrados = m;
}

void buscarPorNombre(struct Becario *becarios, struct Becario *buscado, int conteo) {
    char nombre[50];
    int longitud;
    printf("Nombre completo del becario: ");
    fgets(nombre, 50, stdin);
    longitud = strlen(nombre);
    *(nombre + longitud - 1) = '\0';
    while (getchar() != '\n');
    for (int n = 0; n < conteo; n++) {
        if (strcmp(nombre, (becarios + n)->nombreCompleto) == 0) {
            *buscado = *(becarios + n);
            return;
        }
    }
    *buscado = (struct Becario){"", "", "", 0, 0, 0, {}, {}, ""};
}

void buscarPorEdad(struct Becario *becarios, struct Becario *buscados, int conteo, int *numeroEncontrados) {
    int edad;
    printf("Edad del becario: ");
    scanf("%d", &edad);
    while (getchar() != '\n');
    int m = 0;
    for (int n = 0; n < conteo; n++) {
        if (edad == (becarios + n)->edad) {
            *(buscados + m) = *(becarios + n);
            m++;
        }
    }
    *numeroEncontrados = m;
}

void darDeBajaBecario(struct Becario *becarios, int *conteo, int indice, int *baja) {
    int selector, n;
    printf("Realmente desea dar de baja al becario (1:Si, 2:No): ");
    scanf("%d", &selector);
    *baja = selector;
    if (selector == 1 && indice >= 0 && indice < *conteo) {
        for (n = indice; n < *conteo - 1; n++) {
            *(becarios + n) = *(becarios + n + 1);
        }
        *conteo = *conteo - 1;
    }
}

void modificarBecario(struct Becario *becario) {
    printf("Modificar becario:\n");
    printf("Genero: ");
    fgets(becario->genero, 20, stdin);
    *(becario->genero + strcspn(becario->genero, "\n")) = '\0';

    printf("Nombre completo: ");
    fgets(becario->nombreCompleto, 50, stdin);
    *(becario->nombreCompleto + strcspn(becario->nombreCompleto, "\n")) = '\0';

    printf("Edad: ");
    scanf("%d", &becario->edad);
    while (getchar() != '\n');

    printf("Boleta: ");
    fgets(becario->boleta, 11, stdin);
    *(becario->boleta + strcspn(becario->boleta, "\n")) = '\0';

    printf("Horario: ");
    fgets(becario->horario, 50, stdin);
    *(becario->horario + strcspn(becario->horario, "\n")) = '\0';

    printf("1.- Estudiante\n");
    printf("2.- Empleado\n");
    int opcion;
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion == 1) {
        int num_materias, i;
        printf("Ingrese la cantidad de materias: ");
        scanf("%d", &num_materias);
        becario->numMaterias = num_materias;
        getchar(); 

        for (i = 0; i < num_materias; i++) {
            printf("Ingrese el nombre de la materia %d: ", i + 1);
            fgets(*(becario->materias + i), 50, stdin);
            *(*(becario->materias + i) + strcspn(*(becario->materias + i), "\n")) = '\0';

            printf("Ingrese la calificacion de la materia %d: ", i + 1);
            scanf("%f", becario->calificaciones + i);
            getchar(); 
        }
    } else if (opcion == 2) {
        printf("Sueldo: ");
        scanf("%d", &becario->sueldo);
        while (getchar() != '\n'); 
    } else {
        printf("Opción no válida\n");
    }
}

void generarMenu() {
    printf("Control escolar.\n");
    printf("1. Inscribir becario.\n");
    printf("2. Ver grupo.\n");
    printf("3. Buscar becario.\n");
    printf("4. Modificar becario.\n");
    printf("5. Dar de baja al becario.\n");
    printf("6. Salir del programa\n");
    printf("  Elija una opcion ... ");
}

void limpiarBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void verMenu() {
    int selector = 0, conteo = 0, indice, baja;
    struct Becario becarios[MAX_ALU], buscado;

    while (selector != 6) {
        generarMenu();
        scanf("%d", &selector);
        limpiarBufferEntrada(); // Limpiar el búfer de entrada
        switch (selector) {
            case 1:
                if (conteo < MAX_ALU) {
                    inscribirBecario(becarios + conteo);
                    conteo++;
                } else {
                    printf("El grupo esta lleno con %d becarios.\n", MAX_ALU);
                    printf("Para dar de alta al nuevo becario,\n");
                    printf("debe de dar de baja a alguno.\n");
                }
                break;
            case 2:
                verInformacionDeGrupo(becarios, conteo);
                break;
            case 3:
                buscarPorNombre(becarios, &buscado, conteo);
                if (strlen(buscado.nombreCompleto) != 0) {
                    verInformacionBecario(buscado);
                } else {
                    printf("Becario no encontrado.\n");
                }
                break;
            case 4:
                buscarPorNombre(becarios, &buscado, conteo);
                if (strlen(buscado.nombreCompleto) != 0) {
                    verInformacionBecario(buscado);
                    modificarBecario(becarios + indice);
                    verInformacionBecario(*(becarios + indice));
                } else {
                    printf("Becario no encontrado.\n");
                }
                break;
            case 5:
                buscarPorNombre(becarios, &buscado, conteo);
                if (strlen(buscado.nombreCompleto) != 0) {
                    verInformacionBecario(buscado);
                    darDeBajaBecario(becarios, &conteo, indice, &baja);
                    if (baja == 1) {
                        verInformacionDeGrupo(becarios, conteo);
                    }
                } else {
                    printf("Becario no encontrado.\n");
                }
                break;
            case 6:
                printf("Hasta luego ...\n");
                break;
            default:
                printf("Opcion %d no es valida.\n", selector);
        }
    }
}

int main(int argc, char *argv[]) {
    verMenu();
    return 0;
}