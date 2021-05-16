#include <stdio.h>

#define CONVERSION 166.386

void main ()
{
	int pesetas;

	printf("Indique la cantidad de pesetas que desea convertir: ");
	scanf("%d", &pesetas);
	fflush(stdin);

	printf("Equivale a %.2f euros.\n\n", pesetas / CONVERSION);
}