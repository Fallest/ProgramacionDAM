#include <stdio.h>

#define LIMITE 10

void main()
{
	int numero; // Numero que el usuario introducira.
	int cont;   // Lo utilizaremos para hacer la cuenta atras.

	// Lectura del numero (debe ser par y distinto de cero):
	// Si el resto de dividirlo por 2 es 1 o -1 entonces es impar.
	do{
		printf("Introduzca un numero par (no vale el 0): ");
		scanf("%d", &numero);
		fflush(stdin);
	}while(numero == 0 || numero % 2 == 1 || numero % 2 == -1);

	// (alternativa a las dos ultimas: numero % 2 != 0)

	// Aqui estan las distintas salidas del programa en funcion del valor
	// del numero:
	if (numero < 0)
		printf("El numero es negativo. Su equivalente en positivo vale %d.\n\n",
			numero * (-1));
	else
		if (numero > LIMITE)
			printf("El numero es demasiado grande.\n\n");
		else
		{
			// Rotulo inicial:
			printf("Cuenta atras: ");

			// Bucle que cuenta desde el numero hacia atras (hasta 0):
			for (cont = numero; cont >= 0; cont--)
				printf("%d ", cont);
			
			printf("\n\n");
		}
}