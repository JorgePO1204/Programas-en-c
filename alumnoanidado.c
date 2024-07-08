#include <stdio.h>
#include <string.h>

#define MAX_ALU 33
#define MAX_MATERIAS 100

struct Materia {
    char nombre[50];
    float calificacion;
};

struct Alumno {
    char genero[20];
    char nombreCompleto[50];
    char boleta[11];
    int edad;
    int sueldo;
    int numMaterias;
    struct Materia materias[MAX_MATERIAS];
};

void verInformacionAlumno(struct Alumno *alumno) {
    printf("Genero: %s\n", alumno->genero);
    printf("Nombre: %s\n", alumno->nombreCompleto);
    printf("Boleta: %s\n", alumno->boleta);
    printf("Edad: %d\n", alumno->edad);
    if (alumno->sueldo > 0) {
        printf("Sueldo: %d\n", alumno->sueldo);
    }
    if (alumno->numMaterias > 0) {
        printf("Materias:\n");
        for (int i = 0; i < alumno->numMaterias; i++) {
            printf("- %s: %.2f\n", alumno->materias[i].nombre, alumno->materias[i].calificacion);
        }
    }
}

void inscribirAlumno(struct Alumno *unAlumno) {
    int opcion;

    printf("Genero: ");
    fgets(unAlumno->genero, 20, stdin);
    unAlumno->genero[strcspn(unAlumno->genero, "\n")] = '\0';

    printf("Nombre completo: ");
    fgets(unAlumno->nombreCompleto, 50, stdin);
    unAlumno->nombreCompleto[strcspn(unAlumno->nombreCompleto, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &unAlumno->edad);
    while (getchar() != '\n'); // Limpiar el búfer de entrada

    printf("Boleta: ");
    fgets(unAlumno->boleta, 11, stdin);
    unAlumno->boleta[strcspn(unAlumno->boleta, "\n")] = '\0';

    printf("1.- Estudiante\n");
    printf("2.- Empleado\n");
    scanf("%d", &opcion);
    while (getchar() != '\n'); // Limpiar el búfer de entrada

    if (opcion == 1) {
        int num_materias, i;
        printf("Ingrese la cantidad de materias: ");
        scanf("%d", &num_materias);
        unAlumno->numMaterias = num_materias;
        getchar(); // Limpiar el búfer de entrada

        for (i = 0; i < num_materias; i++) {
            printf("Ingrese el nombre de la materia %d: ", i + 1);
            fgets(unAlumno->materias[i].nombre, 50, stdin);
            unAlumno->materias[i].nombre[strcspn(unAlumno->materias[i].nombre, "\n")] = '\0';

            printf("Ingrese la calificacion de la materia %d: ", i + 1);
            scanf("%f", &unAlumno->materias[i].calificacion);
            getchar(); // Limpiar el búfer de entrada
        }
    } else if (opcion == 2) {
        printf("Sueldo: ");
        scanf("%d", &unAlumno->sueldo);
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    } else {
        printf("Opción no válida\n");
    }
}

void verInformacionDeGrupo(struct Alumno *alumnos, int conteo) {
    for (int n = 0; n < conteo; n++) {
        verInformacionAlumno(alumnos + n);
    }
}

void buscarPorGenero(struct Alumno *alumnos, struct Alumno *buscados,
                     int conteo, int *numeroEncontrados) {
    char elGenero[20];
    int longitud, n, m;
    printf("Masculino o Femenino: ");
    fgets(elGenero, 20, stdin);
    longitud = strlen(elGenero);
    elGenero[longitud - 1] = '\0';
    while (getchar() != '\n');
    for (n = 0, m = 0; n < conteo; n++) {
        if (strcmp(elGenero, (alumnos + n)->genero) == 0) {
            *(buscados + m) = *(alumnos + n);
            m++;
        }
    }
    *numeroEncontrados = m;
}

void buscarPorNombre(struct Alumno *alumnos, struct Alumno *buscado,
                     int conteo) {
    char nombre[50];
    int longitud;
    printf("Nombre completo del alumno: ");
    fgets(nombre, 50, stdin);
    longitud = strlen(nombre);
    nombre[longitud - 1] = '\0';
    while (getchar() != '\n');
    for (int n = 0; n < conteo; n++) {
        if (strcmp(nombre, (alumnos + n)->nombreCompleto) == 0) {
            *buscado = *(alumnos + n);
            return;
        }
    }
    *buscado = (struct Alumno){"", "", "", 0, 0, 0};
}

void buscarPorEdad(struct Alumno *alumnos, struct Alumno *buscados,
                   int conteo, int *numeroEncontrados) {
    int edad;
    printf("Edad del alumno: ");
    scanf("%d", &edad);
    while (getchar() != '\n');
    int m = 0;
    for (int n = 0; n < conteo; n++) {
        if (edad == (alumnos + n)->edad) {
            *(buscados + m) = *(alumnos + n);
            m++;
        }
    }
    *numeroEncontrados = m;
}

void buscarAlumno(struct Alumno *alumnos, int conteo) {
    int selector = 0, numeroEncontrados;
    struct Alumno buscados[MAX_ALU], buscado;
    while (selector != 5) {
        printf(" Buscar alumno por.\n");
        printf("1. Genero.\n");
        printf("2. Nombre.\n");
        printf("3. Edad.\n");
        printf("4. Regresar.\n");
        printf("  Elija una opcion ... ");
        scanf("%d", &selector);
        while (getchar() != '\n'); // Limpiar el búfer de entrada
        switch (selector) {
            case 1:
                buscarPorGenero(alumnos, buscados, conteo,
                                &numeroEncontrados);
                if (numeroEncontrados == 0) {
                    printf("No hay alumnos de ese genero\n");
                } else {
                    verInformacionDeGrupo(buscados, numeroEncontrados);
                }
                break;
            case 2:
                buscarPorNombre(alumnos, &buscado, conteo);
                if (strlen(buscado.nombreCompleto) > 0) {
                    verInformacionAlumno(&buscado);
                } else {
                    printf("Alumno no encontrado.\n");
                }
                break;
            case 3:
                buscarPorEdad(alumnos, buscados, conteo,
                              &numeroEncontrados);
                if (numeroEncontrados == 0) {
                    printf("No hay alumnos de esa edad\n");
                } else {
                    verInformacionDeGrupo(buscados, numeroEncontrados);
                }
                break;
            case 4:
                break;
            default:
                printf("Opcion %d no es valida.\n", selector);
        }
    }
}

void darDeBajaAlumno(struct Alumno *alumnos, int *conteo, int indice, int *baja) {
    int selector;
    printf("Realmente desea dar de baja al alumno (1:Si, 2:No): ");
    scanf("%d", &selector);
    *baja = selector;
    if (selector == 1 && indice >= 0 && indice < *conteo) {
        for (int n = indice; n < *conteo - 1; n++) {
            *(alumnos + n) = *(alumnos + n + 1);
        }
        *conteo = *conteo - 1;
    }
}

void modificarAlumno(struct Alumno *alumno) {
    printf("Modificar alumno:\n");
    printf("Genero: ");
    fgets(alumno->genero, 20, stdin);
    alumno->genero[strcspn(alumno->genero, "\n")] = '\0';

    printf("Nombre completo: ");
    fgets(alumno->nombreCompleto, 50, stdin);
    alumno->nombreCompleto[strcspn(alumno->nombreCompleto, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &alumno->edad);
    while (getchar() != '\n');

    printf("Boleta: ");
    fgets(alumno->boleta, 11, stdin);
    alumno->boleta[strcspn(alumno->boleta, "\n")] = '\0';

    printf("1.- Estudiante\n");
    printf("2.- Empleado\n");
    int opcion;
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion == 1) {
        int num_materias, i;
        printf("Ingrese la cantidad de materias: ");
        scanf("%d", &num_materias);
        alumno->numMaterias = num_materias;
        getchar(); // Limpiar el búfer de entrada

        for (i = 0; i < num_materias; i++) {
            printf("Ingrese el nombre de la materia %d: ", i + 1);
            fgets(alumno->materias[i].nombre, 50, stdin);
            alumno->materias[i].nombre[strcspn(alumno->materias[i].nombre, "\n")] = '\0';

            printf("Ingrese la calificacion de la materia %d: ", i + 1);
            scanf("%f", &alumno->materias[i].calificacion);
            getchar(); // Limpiar el búfer de entrada
        }
    } else if (opcion == 2) {
        printf("Sueldo: ");
        scanf("%d", &alumno->sueldo);
        while (getchar() != '\n'); // Limpiar el búfer de entrada
    } else {
        printf("Opción no válida\n");
    }
}

void generarMenu() {
    printf("Control escolar.\n");
    printf("1. Inscribir alumno.\n");
    printf("2. Ver grupo.\n");
    printf("3. Buscar alumno.\n");
    printf("4. Modificar alumno.\n");
    printf("5. Dar de baja al alumno.\n");
    printf("6. Salir del programa\n");
    printf("  Elija una opcion ... ");
}

void limpiarBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void verMenu() {
    int selector = 0, conteo = 0, indice, baja;
    struct Alumno alumnos[MAX_ALU], buscado;

    while (selector != 6) {
        generarMenu();
        scanf("%d", &selector);
        limpiarBufferEntrada(); // Limpiar el búfer de entrada
        switch (selector) {
            case 1:
                if (conteo < MAX_ALU) {
                    inscribirAlumno(alumnos + conteo);
                    conteo++;
                } else {
                    printf("El grupo esta lleno con %d alumnos.\n", MAX_ALU);
                    printf("Para dar de alta al nuevo alumno,\n");
                    printf("debe de dar de baja a alguno.\n");
                }
                break;
            case 2:
                verInformacionDeGrupo(alumnos, conteo);
                break;
            case 3:
                buscarAlumno(alumnos, conteo);
                break;
            case 4:
                buscarPorNombre(alumnos, &buscado, conteo);
                if (strlen(buscado.nombreCompleto) != 0) {
                    verInformacionAlumno(&buscado);
                    modificarAlumno(alumnos + indice);
                    verInformacionAlumno(alumnos + indice);
                } else {
                    printf("Alumno no encontrado.\n");
                }
                break;
            case 5:
                buscarPorNombre(alumnos, &buscado, conteo);
                if (strlen(buscado.nombreCompleto) != 0) {
                    verInformacionAlumno(&buscado);
                    darDeBajaAlumno(alumnos, &conteo, indice, &baja);
                    if (baja == 1) {
                        verInformacionDeGrupo(alumnos, conteo);
                    }
                } else {
                    printf("Alumno no encontrado.\n");
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