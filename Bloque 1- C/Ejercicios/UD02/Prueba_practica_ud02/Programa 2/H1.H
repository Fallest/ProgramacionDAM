#include <stdio.h>

void main() 
{
	// Declaracion de variables necesarioas
	int x1, x2, flag, cont, aux;

	// Lectura de datos
	printf("Introduzca el numero 1: ");
	scanf("%d", &x1);
	fflush(stdin);

	printf("Introduzca el numero 2: ");
	scanf("%d", &x2);
	fflush(stdin);

	// Comprobacion de cual es el mayor
	if (x1 > x2){flag = 1;}
	else {flag = 0;}

	if (flag == 1)
	{
		do 
		{	
			aux = x1 - x2 * cont;
			cont ++;
		} while (aux != 0);

		printf("El numero %d contiene %d veces al numero %d", x1, cont, x2);
	}
}