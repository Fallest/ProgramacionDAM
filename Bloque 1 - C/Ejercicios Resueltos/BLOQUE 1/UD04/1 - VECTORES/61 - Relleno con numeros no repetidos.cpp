#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15
#define MAXIMO 1000

#define V 1
#define F 0


int no_esta (int numero, int v[], int limite)
{
	int i;

	for (i=0; i<limite; i++)
		if (v[i] == numero)
			return F;

	return V;
}

void rellena_vector (int v[])
{
	int i, gen;
	srand((unsigned)time(NULL));

	v[0] = 1 + (rand() % (MAXIMO));

	for (i=1; i<TAM; i++)
	{
		do{
			gen = 1 + (rand() % (MAXIMO));
		}while (!no_esta (gen, v, i));

		v[i] = gen;
	}

}


void imprime_vector (int v[])
{
	int i;

	printf("VECTOR: ");
	for (i=0; i<TAM; i++)
		printf("%d ", v[i]);
}

void main()
{
	int vector [TAM];

	rellena_vector (vector);
	imprime_vector (vector);
}