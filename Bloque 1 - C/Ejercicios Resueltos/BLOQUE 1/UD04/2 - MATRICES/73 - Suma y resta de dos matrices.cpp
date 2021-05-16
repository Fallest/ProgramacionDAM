#include <stdio.h>

#define FILA 3
#define COLUMNA 3


void realiza_calculos (int m1[FILA][COLUMNA], int m2[FILA][COLUMNA], int s[FILA][COLUMNA], int r[FILA][COLUMNA])
{
	int i, j;

	for (i=0; i<FILA; i++)
		for (j=0; j<COLUMNA; j++)
		{
			s[i][j] = m1[i][j] + m2[i][j];
			r[i][j] = m1[i][j] - m2[i][j];
		}
}


void imprime_matriz (int m[FILA][COLUMNA])
{
	int i, j;

	for (i=0; i<FILA; i++)
	{
			for (j=0; j<COLUMNA; j++)
				printf("%d ", m[i][j]);
			printf("\n");
	}
}


void rellena_matriz (int m[FILA][COLUMNA])
{
	int i, j;

	for (i=0; i<FILA; i++)
			for (j=0; j<COLUMNA; j++)
			{
				printf("Introduzca el valor de la celda (%d,%d): ", i+1, j+1);
				scanf("%d", &m[i][j]);
				fflush(stdin);
			}
}

void main()
{
	int m1 [FILA][COLUMNA], m2 [FILA][COLUMNA], s [FILA][COLUMNA], r [FILA][COLUMNA];

	printf("\nPrimera matriz:\n");
	rellena_matriz(m1);
	imprime_matriz (m1);

	printf("\nSegunda matriz:\n");
	rellena_matriz(m2);
	imprime_matriz (m2);

	realiza_calculos (m1, m2, s, r);

	printf("\nMatriz Suma:\n");
	imprime_matriz (s);

	printf("\nMatriz Resta:\n");
	imprime_matriz (r);
}