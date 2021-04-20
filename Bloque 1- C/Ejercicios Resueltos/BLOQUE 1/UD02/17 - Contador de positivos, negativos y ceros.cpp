#include <stdio.h>

#define LIMITE_ITERACIONES 20

void main()
{
	int numero;  // Numero que se lee del teclado
	int contador_positivos = 0;
	int contador_negativos = 0;
	int contador_ceros = 0;
	int suma = 0; // Acumulara la suma conforme se introduzcan
	int contador_general = 1; // Contara las iteraciones

	while (contador_general <= LIMITE_ITERACIONES)
	{
		// Lectura del numero
		printf("Introduzca el numero (%d): ", contador_general);
		scanf("%d", &numero);
		fflush(stdin);

		if (numero > 0)
		{
			contador_positivos++;
		}
		else
		{
			if (numero < 0)
			{
				contador_negativos++;
			}
			else
			{
				contador_ceros++;
			}
		}

		suma = suma + numero;
		// suma += numero;
		
		contador_general++;
	}

	printf("Se han introducido %d numeros positivos, ", contador_positivos);
	printf("%d numeros negativos y ", contador_negativos);
	printf("%d ceros.\n", contador_ceros);
	printf("La suma de los valores introducidos es de %d.\n\n", suma);
}