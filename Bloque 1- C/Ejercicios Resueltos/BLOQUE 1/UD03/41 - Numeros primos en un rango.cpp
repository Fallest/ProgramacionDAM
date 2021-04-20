/*
Algoritmo que lea un numero entero y compruebe si es primo.
*/

#include <stdio.h>

#define LIM_INF 1
#define LIM_SUP 10

int es_primo (int numero);

void main()
{
	printf("Numeros primos entre %d y %d: ", LIM_INF, LIM_SUP);
	
	for (int i = LIM_INF; i <= LIM_SUP; i++)
	{
		if (es_primo(i) == 1)
			printf("%d ", i);
	}
}



int es_primo (int numero)
{
	int contador = 2;
	
	// Hacemos repetidas divisiones del numero entre sus posibles
	// divisores (que son los valores de "contador") hasta que
	// encontremos alguno o bien lleguemos al propio numero (entre dos).
	while (contador <= numero / 2)
	{
		if (numero % contador == 0) // "Contador" es divisor de "numero"
		{
			return 0;  // He encontrado un divisor: NO ES PRIMO
		}
		contador++;
	}
	
	return 1; // He agotado los posibles divisores: ES PRIMO
}