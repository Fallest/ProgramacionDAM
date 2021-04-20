#include <stdio.h>

#define TAM1 3
#define TAM2 4

void rellenar_matriz(int[][TAM2]);
int pedir_num();
void operaciones(int[][TAM2], int);
void recorrer_matriz(int[][TAM2]);


void recorrer_matriz(int m[][TAM2])
{
	int i, j;

	for(i=0; i<TAM1; i++)
	{
		for (j=0; j<TAM2; j++)
		{
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
}


int pedir_num()
{
	int n;

	printf("\nIndica el numero que multiplicara la matriz: ");
	scanf("%d", &n);
	fflush(stdin);

	return n;
}


void operaciones(int m[][TAM2], int resul[][TAM2], int n)
{
	int i, j;

	for(i=0; i<TAM1; i++)
	{
		for(j=0; j<TAM2; j++)
		{
			resul[i][j]=m[i][j]*n;
		}
	}

}


void rellenar_matriz(int m[][TAM2])
{
	int i, j;

	printf("***MATRIZ***\n");
	
	for (i=0; i<TAM1; i++)
	{
		printf("\n  --FILA %d--", i+1);

		for(j=0; j<TAM2; j++)
		{
			printf("\n    --COLUMNA %d--", j+1);

			printf("\nEscribe el valor %d para la fila %d: ", j+1, i+1);
			scanf("%d", &m[i][j]);
			fflush(stdin);
		}
		printf("\n\n	");
	}
}


void main()
{
	int num, m1[TAM1][TAM2], m2[TAM1][TAM2]; 

	
	rellenar_matriz(m2);

	printf("\nMatriz original: \n");
	printf("----------------\n");
	recorrer_matriz(m2);

	num=pedir_num();

	operaciones(m2, m1, num);

	printf("\nMatriz original multiplicada por %3d: \n", num);
	printf("--------------------------------------\n");
	recorrer_matriz(m1);

}