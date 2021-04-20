#include <stdio.h>

int calculo_dias(int mes_inicio, int dia_inicio, int mes_dev, int dia_dev);
float calculo_importe(int duracion, bool novedad);
bool hay_saldo(int saldo_inicial, float importe);

void main()
{
	// Declaracion de variables
	int mes_inicio, dia_inicio, mes_dev, dia_dev, dias_totales, saldo;
	float importe;
	bool puede_devolver = false, es_novedad = false;
	char novedad;

	// Lectura de datos
	do {
		printf("Introduza el mes y dia de alquiler (MM, DD): ");
		scanf("%d, %d", &mes_inicio, &dia_inicio);
		fflush(stdin);

		printf("Introduza el mes y dia de entrega (MM, DD): ");
		scanf("%d, %d", &mes_dev, &dia_dev);
		fflush(stdin);

		printf("La pelicula era una novedad (s/n)?: ");
		scanf("%c", &novedad);
		fflush(stdin);

		printf("Por favor, introduzca el saldo de su tarjeta: ");
		scanf("%d", &saldo);
		fflush(stdin);
	} while ((mes_inicio < 0) || (dia_inicio < 0)
		|| (mes_dev < 0) || (dia_dev < 0)
		|| (mes_inicio > mes_dev)
		|| (saldo < 0)
		|| ((novedad != 's') && (novedad != 'n')));

	if(novedad == 's') {es_novedad = true;}

	dias_totales = calculo_dias(mes_inicio, dia_inicio, mes_dev, dia_dev);
	importe = calculo_importe(dias_totales, es_novedad);
	puede_devolver = hay_saldo(saldo, importe);

	if(puede_devolver == true) 
	{printf("Pelicula devuelta.\n");}
	else {printf("No se pudo devolver por falta de saldo.\n");}

}

int calculo_dias(int mes_inicio, int dia_inicio, int mes_dev, int dia_dev)
{
	// Declaracion de variables
	int dias_totales;

	// Calculo de dias totales
	dias_totales = ((mes_dev * 30) + dia_dev) - ((mes_inicio * 30) + dia_inicio);
	return dias_totales;
}

float calculo_importe(int duracion, bool novedad)
{
	// Declaracion de variables
	float aumento_novedad, resul_importe;
	float precio_1a3, precio_mas3;

	// Asignacion de variables por separado (da syntax error si no)
	aumento_novedad = 0,04;
	precio_1a3 = 1,20;
	precio_mas3 = 0,75;

	// Calculo del importe
	if(duracion <= 3)
	{resul_importe = (float) (precio_1a3 * duracion);}
	else 
	{resul_importe = (float) (precio_mas3 * duracion);}

	if(novedad == true)
	{resul_importe = resul_importe * aumento_novedad;}

	return resul_importe;
}

bool hay_saldo(int saldo_inicial, float importe)
{
	// Declaracion de variables
	bool hay_saldo = false;

	// Comprobacion
	if((float) saldo_inicial > importe)
	{hay_saldo = true;}

	return hay_saldo;
}