#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Empleado
struct Empleado {
    char nombre[50];
    char sexo;
    float sueldo;
    char puesto[50];
};

// Función para leer la información de cada empleado
void leerInformacion(struct Empleado *empleado) {
    printf("Ingrese el nombre del empleado: ");
    scanf("%s", empleado->nombre);
    printf("Ingrese el sexo del empleado (m/f): ");
    scanf(" %c", &empleado->sexo);
    while (getchar() != '\n');
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &empleado->sueldo);
    while (getchar() != '\n');
    printf("Ingrese el puesto del empleado: ");
    scanf("%s", empleado->puesto);
    while (getchar() != '\n');
    printf("\n");
}

// Función para encontrar el sueldo máximo
float encontrarMaxSueldo(struct Empleado *empleados, int N) {
    if (N == 0) {
        printf("No hay empleados en la lista.\n");
        return 0;
    }

    float sueldoMax = empleados->sueldo;

    // Encuentra el sueldo máximo
    for (int i = 1; i < N; i++) {
        if ((empleados + i)->sueldo > sueldoMax) {
            sueldoMax = (empleados + i)->sueldo;
        }
    }

    return sueldoMax;
}

// Función para encontrar el sueldo mínimo
float encontrarMinSueldo(struct Empleado *empleados, int N) {
    if (N == 0) {
        printf("No hay empleados en la lista.\n");
        return 0;
    }

    float sueldoMin = empleados->sueldo;

    // Encuentra el sueldo mínimo
    for (int i = 1; i < N; i++) {
        if ((empleados + i)->sueldo < sueldoMin) {
            sueldoMin = (empleados + i)->sueldo;
        }
    }

    return sueldoMin;
}

// Función para imprimir los datos de los empleados con el mayor sueldo
void imprimirSueldoMaximo(struct Empleado *empleados, int N) {
    float sueldoMax = encontrarMaxSueldo(empleados, N);

    printf("Empleados con mayor sueldo:\n");
    for (int i = 0; i < N; i++) {
        if ((empleados + i)->sueldo == sueldoMax) {
            printf("Nombre: %s\n", (empleados + i)->nombre);
            printf("Sexo: %c\n", (empleados + i)->sexo);
            printf("Sueldo: %.2f\n", (empleados + i)->sueldo);
            printf("Puesto: %s\n", (empleados + i)->puesto);
            printf("\n");
        }
    }
}

// Función para imprimir los datos de los empleados con el menor sueldo
void imprimirSueldoMinimo(struct Empleado *empleados, int N) {
    float sueldoMin = encontrarMinSueldo(empleados, N);

    printf("Empleados con menor sueldo:\n");
    for (int i = 0; i < N; i++) {
        if ((empleados + i)->sueldo == sueldoMin) {
            printf("Nombre: %s\n", (empleados + i)->nombre);
            printf("Sexo: %c\n", (empleados + i)->sexo);
            printf("Sueldo: %.2f\n", (empleados + i)->sueldo);
            printf("Puesto: %s\n", (empleados + i)->puesto);
            printf("\n");
        }
    }
}

// Función para mostrar los datos de un empleado específico
void mostrarEmpleado(struct Empleado *empleado) {
    printf("Nombre: %s\n", empleado->nombre);
    printf("Sexo: %c\n", empleado->sexo);
    printf("Sueldo: %.2f\n", empleado->sueldo);
    printf("Puesto: %s\n", empleado->puesto);
}

// Función para buscar un empleado por nombre
void buscarEmpleado(struct Empleado *empleados, int N, char nombre[]) {
    for (int i = 0; i < N; i++) {
        if (strcmp((empleados + i)->nombre, nombre) == 0) {
            mostrarEmpleado(empleados + i);
            return;
        }
    }
    printf("Empleado no encontrado.\n");
}

// Función para mostrar los empleados por puesto
void mostrarPorPuesto(struct Empleado *empleados, int N, char puesto[]) {
    int encontrado = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp((empleados + i)->puesto, puesto) == 0) {
            mostrarEmpleado(empleados + i);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron empleados con el puesto %s.\n", puesto);
    }
}

// Función para buscar empleados por puesto
void buscarEmpleadosPorPuesto(struct Empleado *empleados, int N, char puesto[]) {
    printf("Empleados con el puesto %s:\n", puesto);
    mostrarPorPuesto(empleados, N, puesto);
}
void modificarempleado(struct Empleado *empleado) {
    int opcionModificar;
    do {
        printf("Seleccione qué desea modificar de %s:\n", empleado->nombre);
        printf("1. Nombre\n");
        printf("2. Sexo\n");
        printf("3. Sueldo\n");
        printf("4. Puesto\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcionModificar);
        while (getchar() != '\n');

        switch(opcionModificar) {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                scanf("%s", empleado->nombre);
                break;
            case 2:
                printf("Ingrese el nuevo sexo (m/f): ");
                scanf(" %c", &(empleado->sexo));
                break;
            case 3:
                printf("Ingrese el nuevo sueldo: ");
                scanf("%f", &(empleado->sueldo));
                break;
            case 4:
                printf("Ingrese el nuevo puesto: ");
                scanf("%s", empleado->puesto);
                break;
            case 5:
                printf("Saliendo de la modificación...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }
    } while(opcionModificar != 5);

    printf("Empleado modificado correctamente.\n");
}

void editarEmpleado(struct Empleado *empleados, int N, char nombre[]) {
    for (int i = 0; i < N; i++) {
        if (strcmp((empleados + i)->nombre, nombre) == 0) {
            modificarempleado(&empleados[i]);
            return;
        }
    }
    printf("Empleado no encontrado.\n");
}
void borrarEmpleado(struct Empleado *empleados, int *N, int indice) {
    for (int j = indice; j < (*N - 1); j++) {
        *(empleados + j) = *(empleados + j + 1);
    }
    (*N)--;
}

void darDeBaja(struct Empleado *empleados, int *N, char nombre[]) {
    for (int i = 0; i < *N; i++) {
        if (strcmp((empleados + i)->nombre, nombre) == 0) {
            char respuesta;
            printf("¿Esta seguro de que desea dar de baja al empleado %s? (s/n): ", nombre);
            scanf(" %c", &respuesta);
            while (getchar() != '\n');

            if (respuesta == 's' || respuesta == 'S') {
                borrarEmpleado(empleados, N, i);
                printf("Empleado dado de baja correctamente.\n");
                return;
            } else {
                printf("Operacion cancelada. El empleado no ha sido dado de baja.\n");
                return;
            }
        }
    }
    printf("Empleado no encontrado.\n");
}


// Función para mostrar el menú de opciones
void mostrarMenu() {
    printf("\nSeleccione una opcion:\n");
    printf("1. Agregar empleado\n");
    printf("2. Imprimir empleado con mayor y menor sueldo\n");
    printf("3. Buscar empleado por nombre\n");
    printf("4. Buscar empleados por puesto\n");
    printf("5. Modificar empleado\n");
    printf("6. Ver todos los empleados\n");
    printf("7. Dar de baja a un empleado\n");
    printf("8. Salir\n");
    printf("Opcion: ");
}

// Función para agregar empleados
void agregarEmpleado(struct Empleado *empleados, int *N) {
    int cantidad;
    printf("Ingrese la cantidad de empleados que desea agregar: ");
    scanf("%d", &cantidad);
    for (int i = 0; i < cantidad; i++) {
        leerInformacion(empleados + *N);
        (*N)++;
    }
}

// Función para mostrar la información de empleados con mayor y menor sueldo
void mostrarInformacionSueldos(struct Empleado *empleados, int N) {
    imprimirSueldoMaximo(empleados, N);
    printf("\n");
    imprimirSueldoMinimo(empleados, N);
}

// Función para buscar empleado por nombre
void buscarEmpleadoPorNombre(struct Empleado *empleados, int N) {
    char nombre[50];
    printf("Ingrese el nombre del empleado que desea buscar: ");
    scanf("%s", nombre);
    buscarEmpleado(empleados, N, nombre);
}

// Función para buscar empleados por puesto
void buscarEmpleadosPorPuestoNombre(struct Empleado *empleados, int N) {
    char puesto[50];
    printf("Ingrese el puesto de los empleados que desea buscar: ");
    scanf("%s", puesto);
    buscarEmpleadosPorPuesto(empleados, N, puesto);
}

// Función para modificar empleado por nombre
void modificarEmpleadoPorNombre(struct Empleado *empleados, int N) {
    char nombre[50];
    printf("Ingrese el nombre del empleado que desea modificar: ");
    scanf("%s", nombre);
    editarEmpleado(empleados, N, nombre);
}

// Función para mostrar todos los empleados
void mostrarTodosEmpleados(struct Empleado *empleados, int N) {
    if (N == 0) {
        printf("No hay empleados en la lista.\n");
        return;
    }

    printf("Lista de todos los empleados:\n");
    for (int i = 0; i < N; i++) {
        mostrarEmpleado(empleados + i);
    }
}

// Función para dar de baja empleado por nombre
void darDeBajaEmpleadoPorNombre(struct Empleado *empleados, int *N) {
    char nombre[50];
    printf("Ingrese el nombre del empleado que desea dar de baja: ");
    scanf("%s", nombre);
    darDeBaja(empleados, N, nombre);
}

// Función principal para mostrar el menú y manejar las opciones
void mostrarDatos() {
    struct Empleado empleados[100]; // Espacio para hasta 100 empleados
    struct Empleado *ptrEmpleado=empleados;
    int N = 0;
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        while (getchar() != '\n'); // Limpiar el buffer de entrada
        switch(opcion) {
            case 1:
                agregarEmpleado(ptrEmpleado, &N);
                break;
            case 2:
                mostrarInformacionSueldos(ptrEmpleado, N);
                break;
            case 3:
                buscarEmpleadoPorNombre(ptrEmpleado, N);
                break;
            case 4:
                buscarEmpleadosPorPuestoNombre(ptrEmpleado, N);
                break;
            case 5:
                modificarEmpleadoPorNombre(ptrEmpleado, N);
                break;
            case 6:
                mostrarTodosEmpleados(ptrEmpleado, N);
                break;
            case 7:
                darDeBajaEmpleadoPorNombre(ptrEmpleado, &N);
                break;
            case 8:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }
    } while(opcion != 8);
}

int main(int argc, char *argv[]) {
    mostrarDatos();
    return 0;
}