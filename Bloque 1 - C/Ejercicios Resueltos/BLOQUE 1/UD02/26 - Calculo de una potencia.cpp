#include <stdio.h>

void main()
{
	int base, exponente, contador = 0, potencia = 1;

	do{
		printf("Introduzca el valor de la base (positivo): ");
		scanf("%d", &base);
		fflush(stdin);
	}while(base <= 0);

	do{
		printf("Introduzca el valor del exponente (positivo): ");
		scanf("%d", &exponente);
		fflush(stdin);
	}while(exponente <= 0);

	while (contador <= base)
	{
		potencia = potencia * base;
		contador++;
	}

	printf("%d elevado a %d vale %d.\n\n", base, exponente, potencia);
}