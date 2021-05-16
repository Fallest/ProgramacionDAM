#include <stdio.h>

#define COSTE_MINIMO 6
#define METROS_MINIMOS 10
#define LIMITE_TRAMO_1 50
#define COSTE_METRO_TRAMO_1 0.30
#define COSTE_METRO_TRAMO_2 0.45

/*
- El tramo 1 va de 10 a 50 metros.
*/

void main()
{
	int metros;
	float coste;

	printf("Introduzca el numero de metros cubicos consumidos: ");
	scanf("%d", &metros);
	fflush(stdin);

	if(metros <= METROS_MINIMOS)
	{
		coste = COSTE_MINIMO;
	}
	else
	{
		if(metros <= LIMITE_TRAMO_1)
		{
			coste = COSTE_MINIMO + (metros - METROS_MINIMOS) * COSTE_METRO_TRAMO_1;
		}
		else
		{
			coste = metros * COSTE_METRO_TRAMO_2;
		}
	}

	printf("El coste de la factura asciende a %.2f euros.\n\n", coste);
}