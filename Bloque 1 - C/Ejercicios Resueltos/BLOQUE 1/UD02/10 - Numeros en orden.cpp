/*
Algoritmo que lee tres números A, B y C, los imprime en orden
creciente e indica si fueron introducidos en ese orden.
*/

#include <stdio.h>

void main()
{
	int a, b, c;

	printf("Introduce el primer numero: ");
	scanf("%d", &a);
	fflush(stdin);

	printf("Introduce el segundo numero: ");
	scanf("%d", &b);
	fflush(stdin);

	printf("Introduce el tercer numero: ");
	scanf("%d", &c);
	fflush(stdin);

	printf("Los numeros, en orden creciente, son: ");
	
	if (a <= b)
	{
		if (a <= c)
		{
			printf("%d ", a);
			if (b <= c)
			{
				printf("%d %d\n", b, c);
				printf("Los numeros se introdujeron en ese orden.\n\n");
			}
			else
				printf("%d %d\n\n", c, b);
		}
		else
		{
			printf("%d %d %d\n\n", c, a, b);
		}
	}
	else
	{
		if (b <= c)
		{
			printf("%d ", b);
			if (a <= c)
				printf("%d %d\n\n", a, c);
			else
				printf("%d %d\n\n", c, a);		
		}
		else
		{
			printf("%d %d %d\n\n", c, b, a);
		}
	}
}