/*
Algoritmo que lea un numero entero y compruebe si es primo.
*/

#include <stdio.h>

void main()
{
	int numero; // Numero leido del teclado
	int contador = 2; // Generara posibles divisores del numero

	// Lectura del numero a traves del teclado:
	printf("Introduzca el numero a estudiar: ");
	scanf("%d", &numero);
	fflush(stdin);

	// Si me introducen un numero negativo estudiare el positivo.
	if (numero < 0)
		numero = numero * (-1);

	// Hacemos repetidas divisiones del numero entre sus posibles
	// divisores (que son los valores de "contador") hasta que
	// encontremos alguno o bien lleguemos al propio numero (entre dos).
	while (contador <= numero / 2)
	{
		if (numero % contador == 0) // "Contador" es divisor de "numero"
		{
			printf("El numero %d no es primo ", numero);
			printf("(al menos es divisible por %d).\n\n", contador);
			break;
		}
		contador++;
	}
	
	if ((numero == 0) || (numero == 1))
		printf("El valor %d es \"especial\" y no puede estudiarse.\n\n",
		   numero);
	else
	  if (contador == numero)
		printf("El numero %d es primo.\n\n", numero);

}