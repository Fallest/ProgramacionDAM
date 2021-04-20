#include <stdio.h>

#define TAM 6  // Como máximo el número tendrá 6 cifras binarias (40 = 101000)
#define LIMITE 40


void pasar_a_binario (int t[], int n)
{
	int i;

	i = TAM-1;

	while (n != 0)
	{
		t[i] = n % 2;
		n = n / 2;
		i--;
	}
}


void imprimir_vector (int t[])
{
	int i;

	for (i=0; i<TAM; i++)
		printf("%d", t[i]);

	printf("\n\n");
}


void inicializar_vector (int t[])
{
	int i;

	for (i=0; i<TAM; i++)
		t[i] = 0;
}


void leer_dato (int *n)
{
	do{
		printf("Introduzca un numero no superior a %d: ", LIMITE);
		scanf("%d", n);
		fflush(stdin);
	}while ((*n) > LIMITE);
}


void main()
{
	int vector[TAM];
	int numero;

	leer_dato (&numero);
	inicializar_vector (vector);

	pasar_a_binario (vector, numero);

	printf("\nEl numero %d en binario es ", numero);
	imprimir_vector (vector);
}