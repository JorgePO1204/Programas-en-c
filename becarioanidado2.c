#include <stdio.h>
#include <string.h>

#define MAX_ALU 33
#define MAX_MATERIAS 100

struct Materia {
    char nombre[50];
    float calificacion;
};

struct Becario {
    char genero[20];
    char nombreCompleto[50];
    char boleta[11];
    int edad;
    int sueldo;
    int numMaterias;
    struct Materia materias[MAX_MATERIAS];
    char horario[50];
};

struct Grupo {
    struct Becario becarios[MAX_ALU];
    int conteo;
};

void inscribirBecario(struct Becario *unBecario) {
    int opcion;

    printf("Genero: ");
    fgets(unBecario->genero, 20, stdin);
    unBecario->genero[strcspn(unBecario->genero, "\n")] = '\0';

    printf("Nombre completo: ");
    fgets(unBecario->nombreCompleto, 50, stdin);
    unBecario->nombreCompleto[strcspn(unBecario->nombreCompleto, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &unBecario->edad);
    while (getchar() != '\n');

    printf("Boleta: ");
    fgets(unBecario->boleta, 11, stdin);
    unBecario->boleta[strcspn(unBecario->boleta, "\n")] = '\0';

    printf("Horario: ");
    fgets(unBecario->horario, 50, stdin);
    unBecario->horario[strcspn(unBecario->horario, "\n")] = '\0';

    printf("1.- Estudiante\n");
    printf("2.- Empleado\n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion == 1) {
        int num_materias;
        printf("Ingrese la cantidad de materias: ");
        scanf("%d", &num_materias);
        unBecario->numMaterias = num_materias;
        getchar(); // Limpiar el búfer de entrada

        for (int i = 0; i < num_materias; i++) {
            printf("Ingrese el nombre de la materia %d: ", i + 1);
            fgets((unBecario->materias + i)->nombre, 50, stdin);
            (unBecario->materias + i)->nombre[strcspn((unBecario->materias + i)->nombre, "\n")] = '\0';

            printf("Ingrese la calificacion de la materia %d: ", i + 1);
            scanf("%f", &(unBecario->materias + i)->calificacion);
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

void verInformacionBecario(struct Becario *becario) {
    printf("Genero: %s\n", becario->genero);
    printf("Nombre: %s\n", becario->nombreCompleto);
    printf("Boleta: %s\n", becario->boleta);
    printf("Edad: %d\n", becario->edad);
    if (becario->sueldo > 0) {
        printf("Sueldo: %d\n", becario->sueldo);
    }
    if (becario->numMaterias > 0) {
        printf("Materias:\n");
        for (int i = 0; i < becario->numMaterias; i++) {
            printf("- %s: %.2f\n", (becario->materias + i)->nombre, (becario->materias + i)->calificacion);
        }
    }
    printf("Horario: %s\n", becario->horario);
}

void modificarBecario(struct Becario *becario) {
    printf("Modificar becario:\n");
    printf("Genero: ");
    fgets(becario->genero, 20, stdin);
    becario->genero[strcspn(becario->genero, "\n")] = '\0';

    printf("Nombre completo: ");
    fgets(becario->nombreCompleto, 50, stdin);
    becario->nombreCompleto[strcspn(becario->nombreCompleto, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &becario->edad);
    while (getchar() != '\n');

    printf("Boleta: ");
    fgets(becario->boleta, 11, stdin);
    becario->boleta[strcspn(becario->boleta, "\n")] = '\0';

    printf("Horario: ");
    fgets(becario->horario, 50, stdin);
    becario->horario[strcspn(becario->horario, "\n")] = '\0';

    printf("1.- Estudiante\n");
    printf("2.- Empleado\n");
    int opcion;
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion == 1) {
        int num_materias;
        printf("Ingrese la cantidad de materias: ");
        scanf("%d", &num_materias);
        becario->numMaterias = num_materias;
        getchar(); 

        for (int i = 0; i < num_materias; i++) {
            printf("Ingrese el nombre de la materia %d: ", i + 1);
            fgets((becario->materias + i)->nombre, 50, stdin);
            (becario->materias + i)->nombre[strcspn((becario->materias + i)->nombre, "\n")] = '\0';

            printf("Ingrese la calificacion de la materia %d: ", i + 1);
            scanf("%f", &(becario->materias + i)->calificacion);
            getchar(); 
        }
    } else if (opcion == 2) {
        printf("Sueldo: ");
        scanf("%d", &becario->sueldo);
        while (getchar() != '\n'); /
    } else {
        printf("Opción no válida\n");
    }
}

void darDeBajaBecario(struct Grupo *grupo, int indice) {
    int selector;
    printf("Realmente desea dar de baja al becario (1:Si, 2:No): ");
    scanf("%d", &selector);
    if (selector == 1 && indice >= 0 && indice < grupo->conteo) {
        for (int n = indice; n < grupo->conteo - 1; n++) {
            *(grupo->becarios + n) = *(grupo->becarios + n + 1);
        }
        grupo->conteo--;
    }
}

void verInformacionDeGrupo(struct Grupo *grupo) {
    for (int n = 0; n < grupo->conteo; n++) {
        verInformacionBecario(grupo->becarios + n);
    }
}

void buscarPorNombre(struct Grupo *grupo, struct Becario *buscado) {
    char nombre[50];
    printf("Nombre completo del becario: ");
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    for (int n = 0; n < grupo->conteo; n++) {
        if (strcmp(nombre, (grupo->becarios + n)->nombreCompleto) == 0) {
            *buscado = *(grupo->becarios + n);
            return;
        }
    }
    *buscado = (struct Becario){"", "", "", 0, 0, 0, {}, ""};
}

void buscarPorGenero(struct Grupo *grupo, struct Becario buscados[], int *numeroEncontrados) {
    char elGenero[20];
    printf("Masculino o Femenino: ");
    fgets(elGenero, 20, stdin);
    elGenero[strcspn(elGenero, "\n")] = '\0';
    int m = 0;
    for (int n = 0; n < grupo->conteo; n++) {
        if (strcmp(elGenero, (grupo->becarios + n)->genero) == 0) {
            *(buscados + m) = *(grupo->becarios + n);
            m++;
        }
    }
    *numeroEncontrados = m;
}

void buscarPorEdad(struct Grupo *grupo, struct Becario buscados[], int *numeroEncontrados) {
    int edad;
    printf("Edad del becario: ");
    scanf("%d", &edad);
    while (getchar() != '\n');
    int m = 0;
    for (int n = 0; n < grupo->conteo; n++) {
        if (edad == (grupo->becarios + n)->edad) {
            *(buscados + m) = *(grupo->becarios + n);
            m++;
        }
    }
    *numeroEncontrados = m;
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
    int selector = 0;
    struct Grupo grupo;
    grupo.conteo = 0;
    struct Becario buscado;
    struct Becario becariosEncontrados[MAX_ALU];
    int numeroEncontrados;

    while (selector != 6) {
        generarMenu();
        scanf("%d", &selector);
        limpiarBufferEntrada(); 
        switch (selector) {
            case 1:
                if (grupo.conteo < MAX_ALU) {
                    inscribirBecario(grupo.becarios + grupo.conteo);
                    grupo.conteo++;
                } else {
                    printf("El grupo está lleno con %d becarios.\n", MAX_ALU);
                    printf("Para dar de alta al nuevo becario,\n");
                    printf("debe de dar de baja a alguno.\n");
                }
                break;
            case 2:
                verInformacionDeGrupo(&grupo);
                break;
            case 3:
                buscarPorNombre(&grupo, &buscado);
                if (strlen(buscado.nombreCompleto) != 0) {
                    verInformacionBecario(&buscado);
                } else {
                    printf("Becario no encontrado.\n");
                }
                break;
            case 4:
                buscarPorNombre(&grupo, &buscado);
                if (strlen(buscado.nombreCompleto) != 0) {
                    verInformacionBecario(&buscado);
                    modificarBecario(grupo.becarios + grupo.conteo);
                    verInformacionBecario(grupo.becarios + grupo.conteo);
                } else {
                    printf("Becario no encontrado.\n");
                }
                break;
            case 5:
                buscarPorNombre(&grupo, &buscado);
                if (strlen(buscado.nombreCompleto) != 0) {
                    verInformacionBecario(&buscado);
                    darDeBajaBecario(&grupo, grupo.conteo);
                    verInformacionDeGrupo(&grupo);
                } else {
                    printf("Becario no encontrado.\n");
                }
                break;
            case 6:
                printf("Hasta luego ...\n");
                break;
            default:
                printf("Opción %d no es válida.\n", selector);
        }
    }
}

int main(int argc, char *argv[]) {
    verMenu();
    return 0;
}


