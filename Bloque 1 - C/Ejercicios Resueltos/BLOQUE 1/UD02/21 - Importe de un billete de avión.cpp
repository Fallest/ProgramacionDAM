#include <stdio.h>

#define DISTANCIA_BASE 1000
#define PRECIO_BASE 220
#define PRECIO_EXTRA_POR_KM 0.30
#define PERIODO_MAXIMO_DESCUENTO 7
#define PORCENTAJE_DESCUENTO 60

void main()
{
	// Declaracion de variables
	int distancia_recorrida;
	float coste;
	int dia_ida, mes_ida, dia_vuelta, mes_vuelta;
	int dias_transcurridos_ida, dias_transcurridos_vuelta;

	// Lectura de datos (distancia y fechas):
	do{
		printf("Introduzca la distancia en kilometros: ");
		scanf("%d", &distancia_recorrida);
		fflush(stdin);
	}while(distancia_recorrida <= 0);

	do{
		printf("Introduzca el dia de ida: ");
		scanf("%d", &dia_ida);
		fflush(stdin);
	}while(dia_ida < 1 || dia_ida > 30);

	do{
		printf("Introduzca el mes de ida: ");
		scanf("%d", &mes_ida);
		fflush(stdin);
	}while (mes_ida < 1 || mes_ida > 12);

	dias_transcurridos_ida = (mes_ida - 1) * 30 + dia_ida;
	// 20/04 ==> (3 * 30) + 20

	/*
	La validacion de la fecha de vuelta debe incluir la condicion
	de que no sea anterior a la fecha de ida (ademas de que el dia
	debe estar en rango y el mes debe estar en rango).
	*/

	do{
		printf("\nSe van a pedir los datos de la vuelta. ");
		printf("No pueden ser anteriores a %02d/%02d.\n",
			dia_ida, mes_ida);
		do{
			printf("Introduzca el dia de vuelta: ");
			scanf("%d", &dia_vuelta);
			fflush(stdin);
		}while(dia_vuelta < 1 || dia_vuelta > 30);

		do{
			printf("Introduzca el mes de vuelta: ");
			scanf("%d", &mes_vuelta);
			fflush(stdin);
		}while (mes_vuelta < 1 || mes_vuelta > 12);

		dias_transcurridos_vuelta = (mes_vuelta - 1) * 30 + dia_vuelta;
	}while(dias_transcurridos_vuelta < dias_transcurridos_ida);

	// Calculo del coste en funcion de la distancia:
	if (distancia_recorrida < DISTANCIA_BASE)
		coste = PRECIO_BASE;
	else
		coste = distancia_recorrida * PRECIO_EXTRA_POR_KM;

	// Calculo del importe en caso de que se le pueda aplicar descuento:
	if (dias_transcurridos_vuelta - dias_transcurridos_ida < PERIODO_MAXIMO_DESCUENTO)
		coste = (1 - (float) PORCENTAJE_DESCUENTO / 100) * coste;
	// coste = (1 - (float) 60 / 100) * coste
	// coste = (1 - 60.0 / 100) * coste
	// coste = (1 - 0.6) * coste
	// coste = 0.4 * coste

	// Impresion del importe por pantalla:
	printf("\nEl importe del billete es de %.2f euros.\n\n", coste);
}