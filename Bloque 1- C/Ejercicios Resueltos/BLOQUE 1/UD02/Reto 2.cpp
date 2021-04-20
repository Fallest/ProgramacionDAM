#include <stdio.h>

#define LIMITE_TRAMO_1 30
#define TARIFA_TRAMO_1 0.50
#define LIMITE_TRAMO_2 120
#define TARIFA_TRAMO_2 0.08
#define TARIFA_TRAMO_3 0.10

void main()
{
	// Declaracion de variables:
	int hhee, mmee, hhss, mmss;
	int minutos_transcurridos_entrada = 0;
	int minutos_transcurridos_salida = 0;
	int minutos_en_parking;
	float importe;
	
	// Lectura y validacion de datos.
	// Hora y minutos de entrada (validaciones estandar):
	do{
		printf("Hora de llegada (hh:mm): ");
		scanf("%d:%d", &hhee, &mmee);
		fflush(stdin);
	}while(hhee < 0 || hhee > 23 || mmee < 0 || mmee > 59);

	// Se calculan los minutos transcuirridos ese dia hasta ese momento.
	minutos_transcurridos_entrada = hhee * 60 + mmee;

	// Hora y minutos de llegada.
	// Validacion extra: no puede ser una hora anterior a la de llegada:
	do{
		// Validaciones estandar:
		do{
			printf("Hora de salida (hh:mm), no anterior a %02d:%02d: ",
				hhee, mmee);
			scanf("%d:%d", &hhss, &mmss);
			fflush(stdin);
		}while(hhss < 0 || hhss > 23 || mmss < 0 || mmss > 59);
		
		// Se calculan los minutos transcuirridos ese dia hasta ese momento.
		minutos_transcurridos_salida = hhss * 60 + mmss;
	}while(minutos_transcurridos_salida < minutos_transcurridos_entrada);

	// Calculo de los minutos que el vehiculo ha permanecido en el parking:
	minutos_en_parking = minutos_transcurridos_salida - minutos_transcurridos_entrada;

	// Calculo del importe dependiendo de los minutos en el parking:
	if (minutos_en_parking <= LIMITE_TRAMO_1)
		importe = TARIFA_TRAMO_1;
	else
		if (minutos_en_parking <= LIMITE_TRAMO_2)
			importe = TARIFA_TRAMO_1 + (minutos_en_parking - LIMITE_TRAMO_1) * TARIFA_TRAMO_3;			
		else
			importe = minutos_en_parking * TARIFA_TRAMO_2;
	
		// Impresion del importe calculado:
	printf("\nEl vehiculo ha estado estacionado %d minutos y el importe a pagar es de %.2f euros.\n\n",
		minutos_en_parking, importe);
}