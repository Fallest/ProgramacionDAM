#include <stdio.h>
#include <math.h>

#define TAM 10

#define V 1
#define F 0


int calcula_numero (int t[], int c)
{
	int i, acum = 0;

	for (i=c-1; i>=0; i--)
		acum = acum + (pow(10, i) * t[i]);

	return acum;
}


void invierte_vector (int t[], int e[], int c)
{
	int i, j = 0;

	for (i=c-1; i>=0; i--)
	{
		e[j] = t[i];
		j++;
	}
}


void rellena_vector (int t[], int n, int *c)
{
	int i = 0;

	while (n != 0)
	{
		t[i] = n % 10;
		n = n / 10;
		i++;
	}

	(*c) = i;
}


void lee_numero (int *n)
{
	do{
		printf("Introduzca el numero (positivo): ");
		scanf("%d", n);
		fflush(stdin);
	}while ((*n)<=0);
}


void main()
{
	int vector[TAM], espejo[TAM];
	int numero, ncifras, n_alreves;

    lee_numero (&numero);

    rellena_vector (vector, numero, &ncifras);

    invierte_vector (vector, espejo, ncifras);

    n_alreves = calcula_numero (espejo, ncifras);

	if (numero == n_alreves)
		printf("\nEl numero %d es capicua.\n\n", numero);
	else
		printf("\nEl numero %d no es capicua.\n\n", numero);
}