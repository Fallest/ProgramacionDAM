#include <stdio.h>

#define LIMITE 1000

void main()
{
	int numero, suma = 0, contador = 0;

	while(suma <= LIMITE)
	{
		printf("Introduzca un numero a sumar al acumulado: ");
		scanf("%d", &numero);
		fflush(stdin);

		suma = suma + numero;
		contador++;
	}

	printf("La suma ya ha superado el LIMITE (%d)",	suma);
	printf(" despues de introducir %d valores.\n\n", contador);
}