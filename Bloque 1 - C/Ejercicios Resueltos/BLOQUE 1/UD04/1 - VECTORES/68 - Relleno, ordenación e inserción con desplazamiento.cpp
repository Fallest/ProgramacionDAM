#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void rellena_vector (int vector[])
{
	srand (time (NULL));

	for (int i = 0; i < TAM; i++)
		vector[i] = rand() % 100; // Arbitrario, a modo de ejemplo.
}


void ordena_vector (int v[])
{
	int i, j, menor, aux;

	for (i=0; i<TAM-1; i++)
	{
		menor = i;

		for (j=i+1; j<TAM; j++)
			if (v[j] < v[menor])
				menor = j;

		aux = v[i];
		v[i] = v[menor];
		v[menor] = aux;
	}
}


void imprime_vector (int vector[])
{
	printf("\nVECTOR: ");

	for (int i = 0; i < TAM; i++)
		printf("%d ", vector[i]);

	printf("\n");
}


int pedir_valor_a_insertar ()
{
	int valor;

	printf("Introduzca el valor a insertar: ");
	scanf("%d", &valor);
	fflush(stdin);

	return valor;
}



void insercion_ordenada (int vector[])
{
	int numero = pedir_valor_a_insertar ();

	int i = 0;

	while (vector[i] < numero && i < TAM)
		i++;

	if (i < TAM) // Se va a insertar:
	{
		for (int j = TAM - 1; j > i; j--)
			vector[j] = vector[j - 1];
		vector[i] = numero;
	}
}



void main()
{
	int vector[TAM];

	rellena_vector (vector);

	// CONTROL:
	imprime_vector (vector);

	ordena_vector (vector);

	// CONTROL:
	imprime_vector (vector);

	insercion_ordenada (vector);

	// CONTROL:
	imprime_vector (vector);
}
