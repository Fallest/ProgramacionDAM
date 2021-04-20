#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10


void leer_rango (int *x, int *y)
{
	// Solicitamos el rango para los datos de entrada:
	do{
		printf("Introduzca la cota inferior para los valores: ");
		scanf("%d", x);
		fflush(stdin);
	}while(*x <= 0);

	do{
		printf("Introduzca la cota superior para los valores: ");
		scanf("%d", y);
		fflush(stdin);
	}while(*y <= *x);
}

void rellenar_vector(int vector[], int x, int y)
{
	// Generamos el vector con valores entre x e y:
	for (int i = 0; i < N; i++)
		vector[i] = (rand() % (y - x + 1)) + x;
}


void imprimir_vector(int vector[])
{
	printf("\nVector: ");
	for (int i = 0; i < N; i++)
		printf("%d ", vector[i]);
	printf("\n\n");
}


void calcular_estadisticas(int vector[], int *maximo, int *minimo, int *suma)
{
	*maximo = vector[0];
	*minimo = vector[0];
	
	for (int i = 1; i < N; i++)
	{
		if (vector[i] > *maximo)
			*maximo = vector[i];

		if (vector[i] < *minimo)
			*minimo = vector[i];

		(*suma) = (*suma) + vector[i];
	}
}


void imprimir_resultados(int maximo, int minimo, int suma)
{
	printf("\nEl valor maximo es %d.", maximo);
	printf("\nEl valor minimo es %d.", minimo);
	printf("\nLa media vale %.2f.\n\n", (float)suma / N);
}



void main()
{
	int x, y;
	int vector[N];
	int maximo, minimo, suma = 0;

	leer_rango (&x, &y);
	srand(time(NULL));
	rellenar_vector(vector, x, y);
	imprimir_vector(vector);
	calcular_estadisticas(vector, &maximo, &minimo, &suma);
	imprimir_resultados(maximo, minimo, suma);
}
