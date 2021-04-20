/*
Determinar la cantidad total a pagar por una llamada telefónica
de acuerdo a las siguientes premisas: 
-   Toda llamada que dure no mas de tres minutos tiene 
un coste de 0,25 euros. 
-   Cada minuto adicional a partir de los tres primeros es un paso de
contador y cuesta 0,1 euros. 
*/

#include <stdio.h>

#define MINUTOS_FIJOS 3
#define COSTE_FIJO 0.25
#define COSTE_MINUTO_ADICIONAL 0.10

void main()
{
	int minutos;
	float coste;

	printf("Introduzca el numero de minutos de la llamada: ");
	scanf("%d", &minutos);
	fflush(stdin);
/*
	if(minutos <= MINUTOS_FIJOS)
	{
		coste = COSTE_FIJO;
	}
	else
	{
		coste = COSTE_FIJO + (minutos - MINUTOS_FIJOS) * COSTE_MINUTO_ADICIONAL;
	}
*/
	coste = COSTE_FIJO;
	
	if (minutos > MINUTOS_FIJOS)
		coste = coste + (minutos - MINUTOS_FIJOS) * COSTE_MINUTO_ADICIONAL;

	printf("El coste de la llamada asciende a %.2f euros.\n\n", coste);
}