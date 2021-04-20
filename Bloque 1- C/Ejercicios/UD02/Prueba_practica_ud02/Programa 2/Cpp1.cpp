#include <stdio.h>

void main() 
{
	// Declaración de variables necesarias
	int lado, i, j;
	char caracter;

	// Lectura de datos
	printf("Introduzca el numero de simbolos de cada lado: ");
	scanf("%d", &lado);
	fflush(stdin);

	printf("\nIntroduzca el simbolo a utilizar: ");
	scanf("%c", &caracter);
	fflush(stdin);

	// Creacion de la primera linea
	for(i = 0; i < lado; i++)
	{
		printf("%c", caracter);
	}
	printf("\n");

	// Creacion de las lineas intermedias
	for(i = 0; i < lado - 2; i++)
	{
		printf("%c", caracter);
		for (j = 0; j < lado -2; j++)
		{
			printf(" ");
		}
		printf("%c\n", caracter);
	}

	// Creacion de la ultima linea
	for(i = 0; i < lado; i++)
	{
		printf("%c", caracter);
	}
	printf("\n");
}