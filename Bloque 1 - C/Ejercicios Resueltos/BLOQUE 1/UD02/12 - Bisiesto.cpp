#include <stdio.h>

void main()
{
	int anio;

	printf("Introduzca el anio: ");
	scanf("%d", &anio);
	fflush(stdin);

	if ((anio%4 == 0) && !((anio%100 == 0) && (anio%400 != 0)))
		printf("Es bisiesto.\n");
	else
		printf("No es bisiesto.\n");
}
