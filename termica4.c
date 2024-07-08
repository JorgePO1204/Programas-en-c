#include <stdio.h>
#include <math.h>


float calcularSensacionTermica(float temperatura, float velocidadViento) {
    return 13.12 + (0.6215*temperatura) - (11.37*pow(velocidadViento, 0.16)) + (0.3965*temperatura*pow(velocidadViento, 0.16));
	
}
/*13.12 + 0.6215 * temperatura - 11.37 * velocidadViento + 0.16 * 0.3965 * temperatura * velocidadViento;
Temperatura (grados C)	10.0	7.5		5.0		2.5		0.0		-2.5	-5.0	-7.5	-10.0	-12.5	-15.0	-17.5	-20.0	-22.5	-25.0	-27.5	-30.0	
Viento (km/h)	8.0		-66.5	-69.4	-72.2	-75.0	-77.8	-80.7	-83.5	-86.3	-89.1	-92.0	-94.8	-97.6	-100.4	-103.2	-106.1	-108.9	-111.7	
Viento (km/h)	16.0	-152.4	-156.5	-160.6	-164.7	-168.8	-172.9	-177.0	-181.1	-185.2	-189.3	-193.3	-197.4	-201.5	-205.6	-209.7	-213.8	-217.9	
Viento (km/h)	24.0	-238.3	-243.7	-249.0	-254.4	-259.8	-265.1	-270.5	-275.8	-281.2	-286.6	-291.9	-297.3	-302.6	-308.0	-313.4	-318.7	-324.1	
Viento (km/h)	32.0	-324.2	-330.8	-337.5	-344.1	-350.7	-357.3	-364.0	-370.6	-377.2	-383.9	-390.5	-397.1	-403.8	-410.4	-417.0	-423.6	-430.3	
Viento (km/h)	40.0	-410.1	-418.0	-425.9	-433.8	-441.7	-449.6	-457.5	-465.4	-473.3	-481.2	-489.1	-497.0	-504.9	-512.8	-520.7	-528.6	-536.5	
Viento (km/h)	48.0	-496.0	-505.1	-514.3	-523.5	-532.6	-541.8	-551.0	-560.1	-569.3	-578.5	-587.6	-596.8	-606.0	-615.1	-624.3	-633.5	-642.6	
Viento (km/h)	56.0	-581.9	-592.3	-602.7	-613.2	-623.6	-634.0	-644.5	-654.9	-665.3	-675.8	-686.2	-696.6	-707.1	-717.5	-728.0	-738.4	-748.8	
Viento (km/h)	64.0	-667.7	-679.4	-691.2	-702.9	-714.6	-726.3	-738.0	-749.7	-761.4	-773.1	-784.8	-796.5	-808.2	-819.9	-831.6	-843.3	-855.0	
					Riesgo de enfriamento moderado			Riesgo de enfriamento grave		Riesgo de enfriamiento extremo*/
/*35.74 + (0.6215*temperatura) - (35.75*pow(velocidadViento, 0.16)) + (0.4275*temperatura*pow(velocidadViento, 0.16)); Formula mas utilizada en farenheit
Temperatura (grados C)	10.0	7.5		5.0		2.5		0.0		-2.5	-5.0	-7.5	-10.0	-12.5	-15.0	-17.5	-20.0	-22.5	-25.0	-27.5	-30.0	
Viento (km/h)	8.0		-1.9	-5.0	-8.0	-11.1	-14.1	-17.2	-20.2	-23.3	-26.3	-29.3	-32.4	-35.4	-38.5	-41.5	-44.6	-47.6	-50.7	
Viento (km/h)	16.0	-7.1	-10.3	-13.5	-16.8	-20.0	-23.2	-26.4	-29.6	-32.8	-36.1	-39.3	-42.5	-45.7	-48.9	-52.2	-55.4	-58.6	
Viento (km/h)	24.0	-10.4	-13.7	-17.0	-20.4	-23.7	-27.0	-30.4	-33.7	-37.0	-40.4	-43.7	-47.0	-50.4	-53.7	-57.0	-60.3	-63.7	
Viento (km/h)	32.0	-12.8	-16.3	-19.7	-23.1	-26.5	-29.9	-33.3	-36.7	-40.2	-43.6	-47.0	-50.4	-53.8	-57.2	-60.6	-64.1	-67.5	
Viento (km/h)	40.0	-14.8	-18.3	-21.8	-25.3	-28.8	-32.2	-35.7	-39.2	-42.7	-46.2	-49.7	-53.1	-56.6	-60.1	-63.6	-67.1	-70.6	
Viento (km/h)	48.0	-16.5	-20.1	-23.6	-27.1	-30.7	-34.2	-37.8	-41.3	-44.8	-48.4	-51.9	-55.5	-59.0	-62.5	-66.1	-69.6	-73.1	
Viento (km/h)	56.0	-18.0	-21.6	-25.2	-28.7	-32.3	-35.9	-39.5	-43.1	-46.7	-50.3	-53.9	-57.5	-61.0	-64.6	-68.2	-71.8	-75.4	
Viento (km/h)	64.0	-19.3	-22.9	-26.5	-30.2	-33.8	-37.4	-41.1	-44.7	-48.3	-52.0	-55.6	-59.2	-62.9	-66.5	-70.1	-73.8	-77.4	
					Riesgo de enfriamiento moderado			Riesgo de enfriamiento grave		Riesgo de enfriamiento extremo*/
/*13.12 + (0.6215*temperatura) - (11.37*pow(velocidadViento, 0.16)) + (0.3965*temperatura*pow(velocidadViento, 0.16)); Formula mas utilizada en celsius
Temperatura (grados C)	10.0	7.5		5.0		2.5		0.0		-2.5	-5.0	-7.5	-10.0	-12.5	-15.0	-17.5	-20.0	-22.5	-25.0	-27.5	-30.0	
Viento (km/h)	8.0			9.0		6.1		3.1		0.2		-2.7	-5.7	-8.6	-11.5	-14.5	-17.4	-20.4	-23.3	-26.2	-29.2	-32.1	-35.0	-38.0	
Viento (km/h)	16.0		7.8		4.7		1.6		-1.5	-4.6	-7.7	-10.8	-13.9	-17.0	-20.1	-23.2	-26.3	-29.4	-32.5	-35.6	-38.7	-41.8	
Viento (km/h)	24.0		7.0		3.8		0.6		-2.6	-5.8	-9.0	-12.2	-15.4	-18.6	-21.8	-25.0	-28.2	-31.4	-34.6	-37.8	-41.0	-44.2	
Viento (km/h)	32.0		6.4		3.2		-0.1	-3.4	-6.7	-10.0	-13.2	-16.5	-19.8	-23.1	-26.4	-29.6	-32.9	-36.2	-39.5	-42.8	-46.0	
Viento (km/h)	40.0		6.0		2.6		-0.7	-4.1	-7.4	-10.7	-14.1	-17.4	-20.8	-24.1	-27.4	-30.8	-34.1	-37.5	-40.8	-44.2	-47.5	
Viento (km/h)	48.0		5.6		2.2		-1.2	-4.6	-8.0	-11.4	-14.8	-18.2	-21.6	-25.0	-28.4	-31.8	-35.2	-38.6	-42.0	-45.4	-48.7	
Viento (km/h)	56.0		5.2		1.8		-1.6	-5.1	-8.5	-12.0	-15.4	-18.9	-22.3	-25.7	-29.2	-32.6	-36.1	-39.5	-42.9	-46.4	-49.8	
Viento (km/h)	64.0		4.9		1.4		-2.0	-5.5	-9.0	-12.5	-16.0	-19.4	-22.9	-26.4	-29.9	-33.4	-36.9	-40.3	-43.8	-47.3	-50.8	
					Riesgo de enfriamento moderado			Riesgo de enfriamento grave		Riesgo de enfriamiento extremo*/
void imprimirTabla(float tabla[17][8], float temperatura, float velocidadViento) {
    printf("Tabla de Sensacion termica:\n");
    printf("Temperatura (grados C)\t");
    for (int j = 0; j < 17; j++) {
        printf("%.1f\t", temperatura);
        temperatura -= 2.5;
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("Viento (km/h)\t%.1f\t", velocidadViento);
        velocidadViento += 8;
        for (int j = 0; j < 17; j++) {
            printf("%.1f\t", tabla[j][i]);
        }
        printf("\n");
    }
	printf("\t\t\t\t\tRiesgo de enfriamento moderado\t\t\tRiesgo de enfriamento grave\t\tRiesgo de enfriamiento extremo\n");
}


void verificarCongelacion(float temperatura, float velocidadViento) {
    if (temperatura >= -5 || temperatura <= 10) {
        printf("Riesgo moderado de congelacion para %.1f grados C y %.1f km/h.\n", temperatura, velocidadViento);
    }else  if (temperatura >= -20 || temperatura < -5) {
        printf("Riesgo de enfriamento grave para %.1f grados C y %.1f km/h.\n", temperatura, velocidadViento);
    }
    else  if (temperatura >= -30 || temperatura < -20) {
        printf("Riesgo de enfriamento extremo para %.1f grados C y %.1f km/h.\n", temperatura, velocidadViento);
    }
}
void arrojarDato(float tabla[17][8], float temperatura, float velocidadViento) {
    float sensacion = calcularSensacionTermica(temperatura, velocidadViento);
    int encontrado = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 17; j++) {
            if(tabla[i][j] == sensacion) {
                encontrado = 1;
                break;
            }
        }
        if(encontrado) {
			
            break;
        }
    }

    if(encontrado) {
        printf("El valor %.1f se encuentra en la tabla\n", sensacion);
    } else {
        printf("El valor %.1f con temeperatura %.1f y velocidad %.1f no se encuentra en la tabla\n", sensacion, temperatura, velocidadViento);
    }
}


void ingresarDatos(float *temperatura, float *velocidadViento) {
    printf("Ingrese la temperatura base (en grados Celsius): ");
    scanf("%f", temperatura);
    printf("Ingrese la velocidad del viento base (en km/h): ");
    scanf("%f", velocidadViento);
}

int mostrarMenu(float *temperatura, float *velocidadViento) {
    int opcion;
    printf("Elija una opcion\n");
    printf("1. Ver la tabla completa de sensacion termica.\n");
    printf("2. Calcular el indice de sensacion termica para un valor especifico.\n");
    printf("3. Finalizar Programa\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void generarTablaSensacionTermica(float tabla[17][8], float temperatura, float velocidadViento) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 17; j++) {
            tabla[j][i] = calcularSensacionTermica(temperatura, velocidadViento);
            temperatura -= 2.5;
        }
        temperatura = 10;
        velocidadViento += 8;
    }
	imprimirTabla(tabla, 10, 8);
}



void calcularIndice(float temperatura, float velocidadViento) {
    float indice = calcularSensacionTermica(temperatura, velocidadViento);
    printf("El indice de sensacion termica para %.1f grados C y %.1f km/h es: %.1f\n", temperatura, velocidadViento, indice);
}

void comprobarCongelacion(float temperatura, float velocidadViento) {
    verificarCongelacion(temperatura, velocidadViento);
}

void seleccionarDatos() {
    float temperatura = 10;
    float velocidadViento = 8;
	float  tabla[17][8];
    int opcion;
    do {
        opcion = mostrarMenu(&temperatura, &velocidadViento);

        switch (opcion) {
            case 1:
               generarTablaSensacionTermica(tabla, temperatura, velocidadViento);
                break;
            case 2:
                ingresarDatos(&temperatura, &velocidadViento);
			   arrojarDato(tabla, temperatura, velocidadViento);
				  comprobarCongelacion(temperatura, velocidadViento);
				  
                break;
            case 3:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 3);
}

int main(int argc, char *argv[]) {
    seleccionarDatos();

    return 0;
}