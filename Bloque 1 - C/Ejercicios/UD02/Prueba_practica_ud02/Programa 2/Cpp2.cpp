#include <stdio.h>

void main() 
{
	// Declaracion de variables necesarioas
	int x1, x2, flag, cont = 0, aux;

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
			cont ++;
			aux = x1 - x2 * cont;
		} while (aux >= 0);
	
		if(aux == 0) 
		{
			printf("El numero %d contiene %d veces al numero %d", x1, cont, x2);
			printf("La division es exacta.");
		} else {
			printf("El numero %d contiene %d veces al numero %d", x1, cont -1, x2);
			printf("La division NO es exacta.");
		}

		printf("El numero %d contiene %d veces al numero %d", x1, cont, x2);
	} else {
		do 
		{	
			cont ++;
			aux = x2 - x1 * cont;
		} while (aux >= 0);

		if(aux == 0) 
		{
			printf("El numero %d contiene %d veces al numero %d", x2, cont, x1);
			printf("La division es exacta.");
		} else {
			printf("El numero %d contiene %d veces al numero %d", x2, cont -1, x1);
			printf("La division NO es exacta.");
		}
	}
}
