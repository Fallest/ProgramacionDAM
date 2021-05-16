
#include <stdio.h>

void main()
{
	int numero;
	int numero_invertido = 0;
	int contador = 1;

	// LECTURA DEL NUMERO
	do{
		printf("Introduzca un numero positivo: ");
		scanf("%d", &numero);
		fflush(stdin);
	}while (numero <= 0);


	// GENERACION DEL NUMERO INVERTIDO
	do{
		numero_invertido = (numero_invertido * 10) + (numero % 10);
		numero = numero / 10;
	}while (numero != 0);

	
	// GENERACION DE LA SALIDA
	printf("\n");

	do{
		printf("Cifra %d: %d\n", contador, numero_invertido % 10);
		contador++;
		numero_invertido = numero_invertido / 10;
	}while (numero_invertido != 0);
}
