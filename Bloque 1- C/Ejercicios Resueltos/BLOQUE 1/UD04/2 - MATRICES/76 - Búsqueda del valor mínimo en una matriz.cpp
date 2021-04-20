#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM_FILA 3
#define TAM_COLUMNA 4
#define N_ALEATORIOS 1000 

void buscar_menor (int matriz[][TAM_COLUMNA]);
void rellenar_matriz (int matriz[][TAM_COLUMNA]);
void mostrar_result (int matriz[][TAM_COLUMNA]);



void buscar_menor (int matriz[][TAM_COLUMNA])
{
	int pos_fila, pos_columna, fila_menor, columna_menor;

	fila_menor=0;
	columna_menor=0;

	for (pos_fila=0; pos_fila<TAM_FILA; pos_fila++)
	{
		for (pos_columna=0; pos_columna<TAM_COLUMNA; pos_columna++)
		{
			if(matriz[pos_fila][pos_columna] < matriz[fila_menor][columna_menor])
			{
				fila_menor= pos_fila;
				columna_menor= pos_columna;

			}
		}

	}
	
	printf("\nEl numero mas pequeno de la matriz se encuentra en la fila %d y en la columna %d\n\n", fila_menor+1, columna_menor+1);

}


void rellenar_matriz (int matriz[][TAM_COLUMNA])
{
	int pos_fila, pos_columna;

	for (pos_fila=0; pos_fila<TAM_FILA; pos_fila++)
	{
		for (pos_columna=0; pos_columna<TAM_COLUMNA; pos_columna++)
		{
			matriz[pos_fila][pos_columna]= rand()%N_ALEATORIOS+1; //asigna a la matriz numeros aleatorios  desde 1 hasta N_ALEATORIOS
			
		}

	}

}


void mostrar_result (int matriz[][TAM_COLUMNA])
{
	int pos_fila, pos_columna;

	for (pos_fila=0; pos_fila<TAM_FILA; pos_fila++)
	{
		printf("|");
		for (pos_columna=0; pos_columna<TAM_COLUMNA; pos_columna++)
		{
			printf("%3d", matriz[pos_fila][pos_columna]);
			printf("|");

		}

		printf("\n");

	}

}


void  main ()
{
	int matriz[TAM_FILA][TAM_COLUMNA];

	srand((unsigned)time(NULL));
	rellenar_matriz(matriz);

	printf("MATRIZ\n\n");
	mostrar_result(matriz);

	buscar_menor(matriz);

}