#include <stdio.h>

#define TAM1 5


void rellena_vector_alterno (int t1[], int t2[], int alt[])
{
	int i, j = 0;

	for (i=0; i<TAM1; i++)
	{
		alt[j] = t1[i];
		alt [j+1] = t2[i];
		j = j + 2;
	}
}

void imprime_vector (int t[])
{
	int i;

	for (i=0; i<TAM1 * 2; i++)
		printf("%d ", t[i]);
}


void rellena_vector (int t[])
{
	int i;

	for (i=0; i<TAM1; i++)
	{
		printf("Introduzca el valor del elemento %d: ", i+1);
		scanf("%d", &t[i]);
		fflush(stdin);
	}
}


void main()
{
	int v1[TAM1], v2[TAM1];
	int alterno[TAM1 * 2];

	printf("\nVector 1: \n");
	rellena_vector(v1);

	printf("\nVector 2: \n");
	rellena_vector(v2);

    rellena_vector_alterno (v1, v2, alterno);

    printf("\nVector alterno: ");
    imprime_vector(alterno);
}
