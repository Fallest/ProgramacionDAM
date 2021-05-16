/*
El usuario introduce numeros enteros. Si introduce 
un 0 debe dejar de pedirlos. Al final, el programa 
debe decir cuantos numeros pares ha introducido.
*/


#include <stdio.h>

void main()
{
	int numero;
	int contador_pares = 0;

	do{
		printf("Introduzca un numero entero (0 para salir): ");
		scanf("%d", &numero);
		fflush(stdin);

		if ((numero != 0) && (numero % 2 == 0))
			contador_pares++;
	}while(numero != 0);

	printf("Se han introducido un total de %d numeros pares.\n\n", 
		contador_pares);
}