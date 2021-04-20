/*
Pendiente de resolver:
- Si el primer factor es negativo (actualmente no funciona).
- Si el segundo factor es negativo (meterlo entre parentesis).
*/

#include <stdio.h>

#define LIMITE 2

void main()
{
	int factor1;
	int factor2;
	int contador_veces = 0;
	int suma, contador;

	while (contador_veces != LIMITE)
	{
		suma = 0;
		contador = 0;

		printf("\n\nPareja %d\n", contador_veces + 1);
		printf("------------------\n");

		printf("Introduzca el valor del primer factor: ");
		scanf("%d", &factor1);
		fflush(stdin);

		printf("Introduzca el valor del segundo factor: ");
		scanf("%d", &factor2);
		fflush(stdin);

		printf("%d x %d = ", factor1, factor2);

		while(contador < factor1)
		{
			suma = suma + factor2;
			contador++;
			if (contador == factor1)
				printf("%d", factor2);
			else
				printf("%d + ", factor2);
		}
		printf("\n");
		contador_veces++;
	}
}