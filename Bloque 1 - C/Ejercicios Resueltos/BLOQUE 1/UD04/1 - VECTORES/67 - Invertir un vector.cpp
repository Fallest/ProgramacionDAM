#include <stdio.h>

#define TAM 10


void invierte_vector (int t[])
{
	int i = 0, j = TAM-1, aux;

	while (i < j)
	{
		aux = t[i];
		t[i] = t[j];
		t[j] = aux;

		j--;
		i++;
	}
}
  

void imprime_vector (int t[])
{
	int i;

	for (i=0; i<TAM; i++)
		printf("%d ", t[i]);
}


void rellena_vector (int t[])
{
	int i;

	// Relleno con enteros en lugar de con caracteres.

	for (i=0; i<TAM; i++)
	{
		printf("Introduzca el valor del elemento %d: ", i+1);
		scanf("%d", &t[i]);
		fflush(stdin);
	}
}


void main()
{
	int vector[TAM];

    rellena_vector (vector);
	
	printf("\n\nContenido del vector original: ");
    imprime_vector (vector);

    invierte_vector (vector);

	printf("\n\nContenido del vector invertido: ");
    imprime_vector (vector);

}
