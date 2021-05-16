#include <stdio.h>

#define LIMITE_ITERACIONES 20

void main()
{
	int numero;  // Numero que se lee del teclado
	int contador_positivos = 0;
	int suma_positivos = 0;
	int contador_negativos = 0;
	int suma_negativos = 0;

	do {
		// Lectura del numero
		printf("Introduzca un numero (0 para salir): ");
		scanf("%d", &numero);
		fflush(stdin);

		if (numero != 0)
		{
			if (numero > 0)
			{
				contador_positivos++;
				suma_positivos = suma_positivos + numero;
			}
			else
			{
				contador_negativos++;
				suma_negativos = suma_negativos + numero;
			}
		}
	}while(numero != 0);

	if (contador_positivos == 0)
		printf("No ha introducido ningun numero positivo. ");
	else
		printf("La media de los positivos introducidos es de %f. ",
		   (float) suma_positivos / contador_positivos);

	if (contador_negativos == 0)
		printf("No ha introducido ningun numero negativo.\n\n");
	else
		printf("La media de los negativos introducidos es de %f.\n\n",
		   (float) suma_negativos / contador_negativos);
}