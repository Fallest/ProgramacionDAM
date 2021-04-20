#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM1 4		//Numero de filas
#define TAM2 4		//Numero de columnas
#define RAN 3		//Rango de valores introducidos en la matriz


void rellenar_matriz (int [TAM1][TAM2]);
void leer_dato (int *);
void buscar_dato (int [TAM1][TAM2], int, int *, int *);



void main ()
{

	srand((unsigned)time(NULL));

	int matriz[TAM1][TAM2];
	int numero, fila=0, columna=0;

	rellenar_matriz (matriz);

	leer_dato (&numero);

	buscar_dato (matriz, numero, &fila, &columna);

	if (!(fila==0 && columna==0))
		printf("\n\nEl elemento se encuentra en la fila %d y columna %d de la matriz.\n", fila, columna);
	else
		printf("\nEl elemento no se encuentra en la matriz.\n");

}



void rellenar_matriz (int m[TAM1][TAM2])
{

	int i, j;

	for (i = 0; i < TAM1; i++)

		for (j = 0; j < TAM2; j++)

			m[i][j] = rand()%RAN;

}



void leer_dato (int *num)
{

	printf("Introduzca el valor que desea buscar en la matriz: ");
	scanf("%d", num);
	fflush(stdin);

}



void buscar_dato (int m [TAM1][TAM2], int num, int *f, int *c)
{

	int i, j;
	int encontrado;

	encontrado = 0;

	for (i = 0; i < TAM1; i++)

		for (j = 0; j<TAM2 && !encontrado; j++)

			if (m[i][j] == num)
			{

				encontrado = 1;
				(*f) = i+1;
				(*c) = j+1;

			}

}