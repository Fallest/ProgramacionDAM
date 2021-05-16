#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10


void main()
{
	int x, y; // Cotas inferior y superior de los valores de entrada.
	int i; // Contador auxiliar.
	int vector [N];
	int minimo, maximo;
	int suma = 0;

	// Solicitamos el rango para los datos de entrada:
	do{
		printf("Introduzca la cota inferior para los valores: ");
		scanf("%d", &x);
		fflush(stdin);
	}while(x <= 0);

	do{
		printf("Introduzca la cota superior para los valores: ");
		scanf("%d", &y);
		fflush(stdin);
	}while(y <= x);

	// Inicializamos la semilla de numeros aleatorios:
	srand(time(NULL));

	// Generamos el vector con valores entre x e y:
	for (i = 0; i < N; i++)
		vector[i] = (rand() % (y - x + 1)) + x;

	// Mostramos el contenido del vector:
	printf("\nVector: ");
	for (i = 0; i < N; i++)
		printf("%d ", vector[i]);
	printf("\n\n");

	// Calculo de los valores estadisticos que se nos pide:
	maximo = x - 1;
	minimo = y + 1;
	
	for (i = 0; i < N; i++)
	{
		if (vector[i] > maximo)
			maximo = vector[i];

		if (vector[i] < minimo)
			minimo = vector[i];

		suma = suma + vector[i];
	}

	// Impresion de los resultados:
	printf("\nEl valor maximo es %d.", maximo);
	printf("\nEl valor minimo es %d.", minimo);
	printf("\nLa media vale %.2f.\n\n", (float)suma / N);

}
