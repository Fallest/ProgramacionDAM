/*
Introducir un número desde el teclado y decir si es positivo,
negativo o cero. 
RETO: Si no es cero, indica también si es par.
*/

#include <stdio.h>

void main()
{
	int numero;  // Suponemos que el dato sera entero (no lo indica)

	printf("Introduce un numero entero: ");
	scanf("%d", &numero);
	fflush(stdin);

	if(numero > 0)
	{
		printf("El numero es positivo.\n\n");
	}
	else
	{
		if(numero < 0)
		{
			printf("El numero es negativo.\n\n");
		}
		else
		{
            printf("El numero es cero.\n\n");
		}
	}

	// Es necesario comprobar primero si el numero es cero
	// porque si lo es ya no hay que comprobar la segunda.
	// Si invertimos el orden de las condiciones siempre
	// se comprobara si el numero es par (aunque sea cero).
	if(numero != 0 && numero % 2 == 0)
	{
		printf("Ademas, el numero es par.\n\n");
	}
}