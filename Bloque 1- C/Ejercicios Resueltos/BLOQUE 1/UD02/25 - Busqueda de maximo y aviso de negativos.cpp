/*
Algoritmo que lee una secuencia de números no nulos, terminada
con la introducción de un cero, y obtiene e imprime el mayor,
visualizando un mensaje de si se ha leído algún número negativo.
*/

#include <stdio.h>

void main()
{
	int maximo; // Almacenara el valor buscado.
	int numero; // Numero introducido por el usuario cada vez.
	int primera_vez = 1; // "Bandera" utilizada para el primer numero.
	int hay_negativo = 0; // "Bandera" para indicar si se ha introducido
	                      // algun valor negativo (de momento, "bajada").

	do{
		// Lectura del numero a traves del teclado:
		printf("Introduzca un numero (0 para salir): ");
		scanf("%d", &numero);
		fflush(stdin);


		if (numero != 0) // Si el numero no es cero, lo estudio.
		{
			// Si no se han introducido numeros previos,
			// el primer valor es para mi el maximo.
			if (primera_vez == 1)
			{
				maximo = numero;
				primera_vez = 0;
			}
			// A partir del primero, siempre que me introduzcan
			// un valor distinto de cero, lo estudio.
			else
			{
				if (numero > maximo)
					maximo = numero;
				if ((hay_negativo == 0) && (numero < 0))
					hay_negativo = 1; // "Levanto" la bandera.
			}
		}
	}while(numero != 0);

	if (primera_vez == 0)
	{
		printf("El valor maximo introducido es %d.\n", maximo);
		if (hay_negativo == 1)
			printf("Se ha introducido algun valor negativo.\n\n");
		else
			printf("No se ha introducido ningun valor negativo.\n\n");
	}
	else
		printf("No se ha introducido ningun numero valido.\n\n");
}