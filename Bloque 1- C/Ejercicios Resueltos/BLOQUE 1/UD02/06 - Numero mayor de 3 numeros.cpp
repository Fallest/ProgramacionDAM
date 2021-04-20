/*
Introducir tres números A, B y C y visualizar el mayor de ellos. 
RETO: Indicar también si se ha producido un empate en el mayor.

*/

#include <stdio.h>

void main()
{
	int a, b, c;

	printf("Introduce el primer valor: ");
	scanf("%d", &a);
	fflush(stdin);

	printf("Introduce el segundo valor: ");
	scanf("%d", &b);
	fflush(stdin);

	printf("Introduce el tercer valor: ");
	scanf("%d", &c);
	fflush(stdin);

	if(a >= b && a >= c)
	{
		printf("El valor mayor es %d.\n\n", a);
	}
	else
	{
		if(b >= a && b >= c)
		{
			printf("El valor mayor es %d.\n\n", b);
		}
		else
		{
			printf("El valor mayor es %d.\n\n", c);
		}
	}


}