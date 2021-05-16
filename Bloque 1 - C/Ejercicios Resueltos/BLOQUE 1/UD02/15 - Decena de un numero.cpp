#include <stdio.h>

#define LIMITE_INFERIOR 10
#define LIMITE_SUPERIOR 99

void main()
{
	int numero, contador = 1;

	while(contador <= 10)
	{
		do{
			printf("Introduzca el valor ordinal %d (entre %d y %d): ",
				contador, LIMITE_INFERIOR, LIMITE_SUPERIOR);
			scanf("%d", &numero);
			fflush(stdin);
		}while (numero < LIMITE_INFERIOR || numero > LIMITE_SUPERIOR);

		printf("El numero %d pertenece a la decena %d\n\n",
			numero, numero / 10);

		contador++;
	}
}