#include <stdio.h>


void main()
{
	int numero_de_simbolos;
	char simbolo;
	int contador_filas = 1;


	// LECTURA DE DATOS
	do{
		printf("Introduzca el numero de simbolos de cada lado: ");
		scanf("%d", &numero_de_simbolos);
		fflush(stdin);
	}while (numero_de_simbolos <= 0);


	printf("Introduzca el simbolo a utilizar: ");
	scanf("%c", &simbolo);
	fflush(stdin);


	// IMPRESION DEL CUADRADO DE SIMBOLOS
	printf("\n");
	while (contador_filas <= numero_de_simbolos)
	{
		// FILAS PRIMERA Y ULTIMA
		if ((contador_filas == 1) || (contador_filas == numero_de_simbolos))
		{
			for (int i = 1; i <= numero_de_simbolos; i++)
				printf("%c", simbolo);
			printf("\n");
		}
		else // FILAS INTERMEDIAS
		{
			printf("%c", simbolo);
			if (numero_de_simbolos != 1)
			{
				for (int j = 2; j <= numero_de_simbolos - 1; j++)
					printf(" ");
				printf("%c", simbolo);
			}
			printf("\n");
		}
		contador_filas++;
	}
}