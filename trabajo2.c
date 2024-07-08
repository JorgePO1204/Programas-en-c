#include <stdio.h>

#define TARIFA_NORMAL 16.78
#define TARIFA_EXTRA 1.5 * TARIFA_NORMAL
#define HORAS_MAXIMAS 40
#define IMPUESTO_SEGURO_SOCIAL 0.06
#define IMPUESTO_FEDERAL 0.14
#define IMPUESTO_ESTATAL 0.05
#define CUOTA_SINDICAL 10
#define CUOTA_SEGURO_SALUD_ADICIONAL 35


int solicitarEntero() {
    int unEntero;
    scanf("%d", &unEntero);
    return unEntero;
}



float calcularSalarioBruto(int horas_trabajadas, float horas_extra) {
    return TARIFA_NORMAL * horas_trabajadas + TARIFA_EXTRA * horas_extra;
}

float calcularImpuestoSeguroSocial(float salario_bruto) {
    return salario_bruto * IMPUESTO_SEGURO_SOCIAL;
}

float calcularImpuestoFederal(float salario_bruto) {
    return salario_bruto * IMPUESTO_FEDERAL;
}

float calcularImpuestoEstatal(float salario_bruto) {
    return salario_bruto * IMPUESTO_ESTATAL;
}

float calcularCuotaSeguroSalud(int dependientes) {
    if (dependientes >= 3) {
        return CUOTA_SEGURO_SALUD_ADICIONAL; }
        else{
           return 0.0;
        }
}

float calcularSalarioNeto(float salario_bruto, float impuesto_segurosocial, float impuesto_federal, float impuesto_estatal, float cuota_sindical, float cuota_seguro_salud) {
    return salario_bruto - impuesto_segurosocial - impuesto_federal - impuesto_estatal - cuota_sindical - cuota_seguro_salud;
}

void imprimirSalidas(float salario_bruto, float impuesto_segurosocial, float impuesto_federal, float impuesto_estatal, float cuota_sindical, float cuota_seguro_salud, float salario_neto) {
    printf("Salario bruto: %.2f\n", salario_bruto);
    printf("Retencion del Seguro Social: %.2f\n", impuesto_segurosocial);
    printf("Retencion del impuesto federal: %.2f\n", impuesto_federal);
    printf("Retencion del impuesto estatal: %.2f\n", impuesto_estatal);
    printf("Cuota sindical: %.2f\n", cuota_sindical);
    printf("Cuota de seguro de salud adicional: %.2f\n", cuota_seguro_salud);
    printf("Salario neto: %.2f\n", salario_neto);
}
void calcularHorasTrabajadas(int horas_trabajadas, int dependientes) {
    float salario_bruto, impuesto_segurosocial, impuesto_federal, impuesto_estatal, cuota_sindical, cuota_seguro_salud, salario_neto;
    float horas_extra = 0.0;
    
    if (horas_trabajadas > HORAS_MAXIMAS) {
        horas_extra = horas_trabajadas - HORAS_MAXIMAS;
        horas_trabajadas = HORAS_MAXIMAS;
    }
    
    salario_bruto = calcularSalarioBruto(horas_trabajadas, horas_extra);
    impuesto_segurosocial = calcularImpuestoSeguroSocial(salario_bruto);
    impuesto_federal = calcularImpuestoFederal(salario_bruto);
    impuesto_estatal = calcularImpuestoEstatal(salario_bruto);
    cuota_sindical = CUOTA_SINDICAL;
    cuota_seguro_salud = calcularCuotaSeguroSalud(dependientes);
    salario_neto = calcularSalarioNeto(salario_bruto, impuesto_segurosocial, impuesto_federal, impuesto_estatal, cuota_sindical, cuota_seguro_salud);
    
    imprimirSalidas(salario_bruto, impuesto_segurosocial, impuesto_federal, impuesto_estatal, cuota_sindical, cuota_seguro_salud, salario_neto);
}
void solicitarDatos() {
    int horas_trabajadas, dependientes;
    printf("Ingrese la cantidad de horas trabajadas en la semana: ");
    horas_trabajadas = solicitarEntero();
    printf("Ingrese el numero de dependientes: ");
    dependientes = solicitarEntero();
    calcularHorasTrabajadas(horas_trabajadas, dependientes);
}
int main(int argc, char *argv[]) {
    solicitarDatos();
    return 0;
}