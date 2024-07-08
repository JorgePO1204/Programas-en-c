#include <stdio.h>

#define Alumnos 50

int cantidadDeAlumnos() {
    int numeroDeAlumnos;
    printf("Ingrese el numero de alumnos: ");
    scanf("%i", &numeroDeAlumnos);
    return numeroDeAlumnos;
}

void ingresarCalificaciones(int almacenarCalificaciones[][50], int cantidadDeItems, const char *item, int numeroDeAlumno) {
    for (int i = 0; i < cantidadDeItems; i++) {
        printf("Ingrese calificacion para %s %i del alumno %i: ", item, i + 1, numeroDeAlumno + 1);
        scanf("%i", &almacenarCalificaciones[numeroDeAlumno][i]);
    }
}

void mostrarCalificaciones(int almacenarCalificaciones[][50], int cantidadDeItems, const char *item, int numeroDeAlumno) {
    printf("\nLas calificaciones de las %s son:\n", item);
    for (int i = 0; i < cantidadDeItems; i++) {
        printf("%i ", almacenarCalificaciones[numeroDeAlumno][i]);
    }
    printf("\n\n");
}

float calcularCalificacionFinal(int almacenarTareas[][50], int almacenarTrabajos[][50], int almacenarExamenes[][50], int cantidadDeTareas, int cantidadDeTrabajos, int cantidadDeExamenes, int numeroDeAlumno) {
    float sumaTareas = 0, sumaTrabajos = 0, sumaExamenes = 0;
    for (int j = 0; j < cantidadDeTareas; j++) {
        sumaTareas += almacenarTareas[numeroDeAlumno][j];
    }
    for (int j = 0; j < cantidadDeTrabajos; j++) {
        sumaTrabajos += almacenarTrabajos[numeroDeAlumno][j];
    }
    for (int j = 0; j < cantidadDeExamenes; j++) {
        sumaExamenes += almacenarExamenes[numeroDeAlumno][j];
    }

    float calificacionFinal = (sumaTareas + sumaTrabajos + sumaExamenes) / (cantidadDeTareas + cantidadDeTrabajos + cantidadDeExamenes);
    printf("La calificacion final del alumno %i es: %.2f\n", numeroDeAlumno + 1, calificacionFinal);
    return calificacionFinal;
}

void ingresarDatos(int numeroDeAlumnos, int cantidadDeTareas, int cantidadDeTrabajos, int cantidadDeExamenes) {
    int almacenarTareas[Alumnos][50];
    int almacenarTrabajos[Alumnos][50];
    int almacenarExamenes[Alumnos][50];
    int almacenarAlumnos[Alumnos];
    float sumaCalificaciones = 0;

    for (int i = 0; i < numeroDeAlumnos; i++) {
        printf("Ingrese numero de boleta para el alumno %i: ", i + 1);
        scanf("%i", &almacenarAlumnos[i]);

        ingresarCalificaciones(almacenarTareas, cantidadDeTareas, "tareas", i);
        ingresarCalificaciones(almacenarTrabajos, cantidadDeTrabajos, "trabajos", i);
        ingresarCalificaciones(almacenarExamenes, cantidadDeExamenes, "examenes", i);

        mostrarCalificaciones(almacenarTareas, cantidadDeTareas, "tareas", i);
        mostrarCalificaciones(almacenarTrabajos, cantidadDeTrabajos, "trabajos", i);
        mostrarCalificaciones(almacenarExamenes, cantidadDeExamenes, "examenes", i);

        sumaCalificaciones += calcularCalificacionFinal(almacenarTareas, almacenarTrabajos, almacenarExamenes, cantidadDeTareas, cantidadDeTrabajos, cantidadDeExamenes, i);
    }

    float promedioGrupo = sumaCalificaciones / numeroDeAlumnos;
    printf("\nEl promedio del grupo es: %.2f\n", promedioGrupo);
}

void solicitarDatos() {
    int alumnos, tareas, trabajos, examenes;

    alumnos = cantidadDeAlumnos();
    printf("Ingrese el numero de tareas: ");
    scanf("%i", &tareas);
    printf("Ingrese el numero de trabajos: ");
    scanf("%i", &trabajos);
    printf("Ingrese el numero de examenes: ");
    scanf("%i", &examenes);

    ingresarDatos(alumnos, tareas, trabajos, examenes);
}

int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}
