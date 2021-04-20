#include <stdio.h>

void main()
{
	int numerador;
	int denominador;
	int cociente = 0;

	printf("Introduzca el valor del numerador: ");
	scanf("%d", &numerador);
	fflush(stdin);

	printf("Introduzca el valor del denominador: ");
	scanf("%d", &denominador);
	fflush(stdin);

	/*
	Si alguno de los operandos es negativo, lo convierto en positivo.
	Ejemplo:
	if (numerador < 0)
		numerador = numerador * (-1);
	*/

	if (denominador != 0)
	{
		while(numerador >= denominador)
		{
			numerador = numerador - denominador;
			cociente++;
		}
		printf("El cociente entero vale %d.\n\n", cociente);
	}
	else
		printf("No se puede efectuar una division por cero.\n\n");


}