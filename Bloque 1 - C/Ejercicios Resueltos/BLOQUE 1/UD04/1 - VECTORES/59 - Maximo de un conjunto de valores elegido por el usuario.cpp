#include <stdio.h>

#define N 5

void pedir_numero (int *n, int cont)
{
	printf("Introduzca el valor correspondiente a la celda %d: ", cont + 1);
	scanf("%d", n);
	fflush(stdin);
}


void llenar_vector (int v[], int *cont)
{
	int numero = 1; // Valor ficticio para que entre en el bucle.
	
	while ((*cont) != N && numero >= 0)
	{
		pedir_numero (&numero, *cont);
		if (numero >= 0)
		{
			v[(*cont)] = numero;
			(*cont)++;
		}
	}
}


void buscar_elemento (int vector[], int contador)
{
	if (contador == 0)
		printf("No hay elementos que buscar.\n\n");
	else
	{
		int maximo = vector[0];
		int posicion = 0;
		int repetido = 0; // Controla si el maximo esta repetido
		
		for (int i = 1; i < contador; i++)
		{
			if (vector[i] > maximo)
			{
				maximo = vector[i];
				posicion = i;
				repetido = 0;
			}
			else
				if (vector[i] == maximo)
					repetido = 1; // El maximo ya ha salido antes (esta repetido)
		}

		printf("El valor maximo es %d, ", maximo);
		printf("se encuentra en la posicion %d y ", posicion + 1);
		
		if (repetido)
			printf("ese valor ha salido mas de una vez.\n\n");
		else
			printf("ese valor solo ha salido una vez.\n\n");
	}
}

void main()
{
	int vector[N];
	int contador = 0; // Cuenta el numero de celdas utilizadas.

	llenar_vector (vector, &contador);
	
	// Código de control (borrar):
	/*for (int i = 0; i < contador; i++)
		printf("%d ", vector[i]);*/

	// Busqueda de un valor en el vector:
	buscar_elemento (vector, contador);
}
