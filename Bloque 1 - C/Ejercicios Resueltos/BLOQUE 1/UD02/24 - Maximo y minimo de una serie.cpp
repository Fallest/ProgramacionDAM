/*
Realizar un programa que solicite una serie de números mayores
que cero por teclado e imprima el valor máximo y el valor mínimo. 
La serie termina al introducir un 0.
*/

#include <stdio.h>

void main()
{
	int maximo, minimo; // Almacenaran los valores buscados.
	int numero; // Numero introducido por el usuario cada vez.
	int primera_vez = 1; // "Bandera" utilizada para el primer numero.

	do{
		// Lectura del numero a traves del teclado:
		do{
			printf("Introduzca un numero positivo (o 0 para salir): ");
			scanf("%d", &numero);
			fflush(stdin);
		}while (numero < 0);


		if (numero != 0) // Si el numero no es cero, lo estudio.
		{
			// Si no se han introducido numeros previos,
			// el primer valor es para mi el maximo y el minimo.
			if (primera_vez == 1)
			{
				maximo = numero;
				minimo = numero;
				primera_vez = 0;
			}
			// A partir del primero, siempre que me introduzcan
			// un valor distinto de cero, lo estudio.
			else
			{
				if (numero > maximo)
					maximo = numero;
				if (numero < minimo)
					minimo = numero;
			}
		}
	}while(numero != 0);

	if (primera_vez == 0)
	{
		printf("El valor maximo introducido es %d ", maximo);
		printf("y el minimo es %d.\n\n", minimo);
	}
	else
		printf("No se ha introducido ningun numero valido.\n\n");
}