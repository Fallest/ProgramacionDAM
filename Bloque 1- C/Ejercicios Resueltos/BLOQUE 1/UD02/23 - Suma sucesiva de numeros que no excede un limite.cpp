#include <stdio.h>

void main()
{
	int limite;
	int suma = 0;
	int contador = 1;

	do{
		printf("Introduzca el valor limite (positivo) que no debe superarse: ");
		scanf("%d", &limite);
		fflush(stdin);
	}while (limite <= 0);

	while (suma <= limite)
	{
		suma = suma + contador;
		contador++;
	}

	printf("El limite se supera sumando los primeros %d valores.\n\n",
		contador - 1);

}