#include <stdio.h>
#include <string.h>

#define MAX_ALU 33
#define MAX_MATERIAS 100


struct Materia {
    char nombre[50];
    float calificacion;
};

struct DatosPersonales {
    char genero[20];
    char nombreCompleto[50];
    char boleta[11];
    int edad;
};

struct Empleo {
    int sueldo;
    char horario[50];
};

struct Becario {
    struct DatosPersonales datosPersonales;
    struct Empleo empleo;
    int numMaterias;
    struct Materia materias[MAX_MATERIAS];
};

struct Grupo {
    struct Becario becarios[MAX_ALU];
    int conteo;
};

// Prototipos de funciones
void inscribirBecario(struct Grupo *grupo);
void verInformacionBecario(struct Becario *becario, int numero);
void verInformacionDeGrupo(struct Grupo *grupo);
void buscarPorNombre(struct Grupo *grupo, struct Becario *buscado);
void buscarPorGenero(struct Grupo *grupo, struct Becario buscados[], int *numeroEncontrados);
void buscarPorEdad(struct Grupo *grupo, struct Becario buscados[], int *numeroEncontrados);
void modificarBecario(struct Becario *becario);
void darDeBajaBecario(struct Grupo *grupo, int indice);
void generarMenu();
void limpiarBufferEntrada();
void verMenu();

// Función para inscribir un nuevo becario en el grupo
void inscribirBecario(struct Grupo *grupo) {
    int opcion;

    struct Becario *nuevoBecario = grupo->becarios + grupo->conteo;

    printf("Genero: ");
    fgets(nuevoBecario->datosPersonales.genero, 20, stdin);
    nuevoBecario->datosPersonales.genero[strcspn(nuevoBecario->datosPersonales.genero, "\n")] = '\0';

    printf("Nombre completo: ");
    fgets(nuevoBecario->datosPersonales.nombreCompleto, 50, stdin);
    nuevoBecario->datosPersonales.nombreCompleto[strcspn(nuevoBecario->datosPersonales.nombreCompleto, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &nuevoBecario->datosPersonales.edad);
    while (getchar() != '\n');

    printf("Boleta: ");
    fgets(nuevoBecario->datosPersonales.boleta, 11, stdin);
    nuevoBecario->datosPersonales.boleta[strcspn(nuevoBecario->datosPersonales.boleta, "\n")] = '\0';

    printf("Horario: ");
    fgets(nuevoBecario->empleo.horario, 50, stdin);
    nuevoBecario->empleo.horario[strcspn(nuevoBecario->empleo.horario, "\n")] = '\0';

    printf("1.- Estudiante\n");
    printf("2.- Empleado\n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion == 1) {
        int num_materias, i;
        printf("Ingrese la cantidad de materias: ");
        scanf("%d", &num_materias);
        nuevoBecario->numMaterias = num_materias;
        getchar(); 

        for (i = 0; i < num_materias; i++) {
            struct Materia *materia = nuevoBecario->materias + i;

            printf("Ingrese el nombre de la materia %d: ", i + 1);
            fgets(materia->nombre, 50, stdin);
            materia->nombre[strcspn(materia->nombre, "\n")] = '\0';

            printf("Ingrese la calificacion de la materia %d: ", i + 1);
            scanf("%f", &materia->calificacion);
            getchar(); 
        }
    } else if (opcion == 2) {
        printf("Sueldo: ");
        scanf("%d", &nuevoBecario->empleo.sueldo);
        while (getchar() != '\n'); 
    } else {
        printf("Opción no válida\n");
    }

    grupo->conteo++;
}

// Función para visualizar la información de un becario
void verInformacionBecario(struct Becario *becario, int numero) {
    printf("Becario %d:\n", numero);
    printf("Genero: %s\n", becario->datosPersonales.genero);
    printf("Nombre: %s\n", becario->datosPersonales.nombreCompleto);
    printf("Boleta: %s\n", becario->datosPersonales.boleta);
    printf("Edad: %d\n", becario->datosPersonales.edad);
    if (becario->empleo.sueldo > 0) {
        printf("Sueldo: %d\n", becario->empleo.sueldo);
    }
    if (becario->numMaterias > 0) {
        printf("Materias:\n");
        for (int i = 0; i < becario->numMaterias; i++) {
            struct Materia *materia = becario->materias + i;
            printf("- %s: %.2f\n", materia->nombre, materia->calificacion);
        }
    }
    printf("Horario: %s\n", becario->empleo.horario);
}

// Función para visualizar la información de todos los becarios en el grupo
void verInformacionDeGrupo(struct Grupo *grupo) {
    for (int n = 0; n < grupo->conteo; n++) {
        verInformacionBecario(grupo->becarios + n, n + 1);
    }
}

// Función para buscar un becario por nombre
void buscarPorNombre(struct Grupo *grupo, struct Becario *buscado) {
    char nombre[50];
    int longitud;
    printf("Nombre completo del becario: ");
    fgets(nombre, 50, stdin);
    longitud = strlen(nombre);
    nombre[longitud - 1] = '\0';
    for (int n = 0; n < grupo->conteo; n++) {
        if (strcmp(nombre, (grupo->becarios + n)->datosPersonales.nombreCompleto) == 0) {
            *buscado = *(grupo->becarios + n);
            return;
        }
    }
    printf("Becario no encontrado.\n");
}

// Función para buscar becarios por género
void buscarPorGenero(struct Grupo *grupo, struct Becario buscados[], int *numeroEncontrados) {
    char elGenero[20];
    int longitud, n, m;
    printf("Masculino o Femenino: ");
    fgets(elGenero, 20, stdin);
    longitud = strlen(elGenero);
    elGenero[longitud - 1] = '\0';
    for (n = 0, m = 0; n < grupo->conteo; n++) {
        if (strcmp(elGenero, (grupo->becarios + n)->datosPersonales.genero) == 0) {
            *(buscados + m) = *(grupo->becarios + n);
            m++;
        }
    }
    *numeroEncontrados = m;
}

// Función para buscar becarios por edad
void buscarPorEdad(struct Grupo *grupo, struct Becario buscados[], int *numeroEncontrados) {
    int edad;
    printf("Edad del becario: ");
    scanf("%d", &edad);
    while (getchar() != '\n');
    int m = 0;
    for (int n = 0; n < grupo->conteo; n++) {
        if (edad == (grupo->becarios + n)->datosPersonales.edad) {
            *(buscados + m) = *(grupo->becarios + n);
            m++;
        }
    }
    *numeroEncontrados = m;
}

// Función para modificar los datos de un becario
void modificarBecario(struct Becario *becario) {
    printf("Modificando becario...\n");
    printf("Genero: ");
    fgets(becario->datosPersonales.genero, 20, stdin);
    becario->datosPersonales.genero[strcspn(becario->datosPersonales.genero, "\n")] = '\0';

    printf("Nombre completo: ");
    fgets(becario->datosPersonales.nombreCompleto, 50, stdin);
    becario->datosPersonales.nombreCompleto[strcspn(becario->datosPersonales.nombreCompleto, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &becario->datosPersonales.edad);
    while (getchar() != '\n');

    printf("Boleta: ");
    fgets(becario->datosPersonales.boleta, 11, stdin);
    becario->datosPersonales.boleta[strcspn(becario->datosPersonales.boleta, "\n")] = '\0';

    printf("Horario: ");
    fgets(becario->empleo.horario, 50, stdin);
    becario->empleo.horario[strcspn(becario->empleo.horario, "\n")] = '\0';

    int opcion;
    printf("1.- Estudiante\n");
    printf("2.- Empleado\n");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion == 1) {
        int num_materias, i;
        printf("Ingrese la cantidad de materias: ");
        scanf("%d", &num_materias);
        becario->numMaterias = num_materias;
        getchar(); 

        for (i = 0; i < num_materias; i++) {
            struct Materia *materia = becario->materias + i;

            printf("Ingrese el nombre de la materia %d: ", i + 1);
            fgets(materia->nombre, 50, stdin);
            materia->nombre[strcspn(materia->nombre, "\n")] = '\0';

            printf("Ingrese la calificacion de la materia %d: ", i + 1);
            scanf("%f", &materia->calificacion);
            getchar(); // Limpiar el búfer de entrada
        }
    } else if (opcion == 2) {
        printf("Sueldo: ");
        scanf("%d", &becario->empleo.sueldo);
        while (getchar() != '\n'); 
    } else {
        printf("Opción no válida\n");
    }
}

// Función para dar de baja un becario del grupo
void darDeBajaBecario(struct Grupo *grupo, int indice) {
    if (indice >= 0 && indice < grupo->conteo) {
        for (int i = indice; i < grupo->conteo - 1; i++) {
            *(grupo->becarios + i) = *(grupo->becarios + i + 1);
        }
        grupo->conteo--;
    }
}


void limpiarBufferEntrada() {
    while (getchar() != '\n');
}


void generarMenu() {
    printf("*****************Menú Principal*****************\n");
    printf("1. Inscribir becario\n");
    printf("2. Ver información de becario\n");
    printf("3. Ver información de grupo\n");
    printf("4. Buscar becario por nombre\n");
    printf("5. Buscar becarios por género\n");
    printf("6. Buscar becarios por edad\n");
    printf("7. Modificar información de becario\n");
    printf("8. Dar de baja becario\n");
    printf("9. Salir\n");
    printf("************************************************\n");
}


void verMenu() {
    struct Grupo grupo = { .conteo = 0 };
    int opcion;
    do {
        generarMenu();
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                inscribirBecario(&grupo);
                break;
            case 2: {
                int numero;
                printf("Ingrese el número del becario: ");
                scanf("%d", &numero);
                while (getchar() != '\n');
                if (numero > 0 && numero <= grupo.conteo) {
                    verInformacionBecario(grupo.becarios + (numero - 1), numero);
                } else {
                    printf("Número de becario no válido.\n");
                }
                break;
            }
            case 3:
                verInformacionDeGrupo(&grupo);
                break;
            case 4: {
                struct Becario buscado;
                buscarPorNombre(&grupo, &buscado);
                break;
            }
            case 5: {
                struct Becario buscados[MAX_ALU];
                int numeroEncontrados;
                buscarPorGenero(&grupo, buscados, &numeroEncontrados);
                for (int i = 0; i < numeroEncontrados; i++) {
                    verInformacionBecario(buscados + i, i + 1);
                }
                break;
            }
            case 6: {
                struct Becario buscados[MAX_ALU];
                int numeroEncontrados;
                buscarPorEdad(&grupo, buscados, &numeroEncontrados);
                for (int i = 0; i < numeroEncontrados; i++) {
                    verInformacionBecario(buscados + i, i + 1);
                }
                break;
            }
            case 7: {
                int numero;
                printf("Ingrese el número del becario: ");
                scanf("%d", &numero);
                while (getchar() != '\n');
                if (numero > 0 && numero <= grupo.conteo) {
                    modificarBecario(grupo.becarios + (numero - 1));
                } else {
                    printf("Número de becario no válido.\n");
                }
                break;
            }
            case 8: {
                int numero;
                printf("Ingrese el número del becario a dar de baja: ");
                scanf("%d", &numero);
                while (getchar() != '\n');
                if (numero > 0 && numero <= grupo.conteo) {
                    darDeBajaBecario(&grupo, numero - 1);
                } else {
                    printf("Número de becario no válido.\n");
                }
                break;
            }
            case 9:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 9);
}

int main(int argc, char *argv[]) {
    verMenu();
    return 0;
}