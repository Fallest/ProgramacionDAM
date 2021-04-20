// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// CONSTANTES
#define MAX 10			// Número de valores del vector principal.
#define VALOR_MIN 10	// Límite inferior de los valores del vector principal.
#define VALOR_MAX 100	// Límite superior de los valores del vector principal.


// PROTOTIPOS
void mostrar_menu ();
void leer_opcion (int *op);
void ejecutar_opcion (int op, int vector[MAX], int cuenta_opciones [5]);
void rellenar_vector (int vector[MAX]);
void calcular_medias (int vector[MAX]);
int decena_cercana (float cantidad);
void almacenar_extremos (int vector[MAX]);
void ordenar_vector (int vector[MAX]);
void salir (int cuenta_opciones[5]);
void rellena_vector_auxiliar (int vector_aux[], int vector[]);


// FUNCIONES
void mostrar_menu ()
{
	printf("\nMENU PRINCIPAL");
	printf("\n-------------------------");
	printf("\n1.- Rellenar vector.");
	printf("\n2.- Calcular medias.");
	printf("\n3.- Almacenar extremos.");
	printf("\n4.- Ordenar vector.");
	printf("\n5.- Salir.\n");
}


void leer_opcion (int *op, int cuenta_opciones[5])
{
	do{
		printf("\nIntroduzca opcion (1-5): ");
		scanf("%d", op);
		fflush(stdin);

		if ( ((*op) > 1) && ((*op) < 5) && cuenta_opciones[0] == 0)
		{
			printf("\nDebe utilizar la opcion 1 antes (aun no hay ningun vector creado).");
			(*op) = 6; // Ficticio (para que vuelva a pedir un valor).
		}

	}while (((*op) < 1) || ((*op) > 5));
}


void rellena_vector_auxiliar (int vector_aux[], int vector[])
{
	for (int i = 0; i < MAX; i++)
		vector_aux[i] = vector[i];
}


void ejecutar_opcion (int op, int vector[MAX], int cuenta_opciones [5])
{
	int vector_aux[MAX];
	
	switch (op)
	{
	case 1: rellenar_vector (vector);
			break;
	case 2: calcular_medias (vector);
			break;
	case 3: almacenar_extremos (vector);
			break;
	case 4: rellena_vector_auxiliar (vector_aux, vector);
		    ordenar_vector (vector_aux);
			break;
	case 5:	salir (cuenta_opciones);
	}

	cuenta_opciones [op-1]++;
}


void rellenar_vector (int vector[MAX])
{
	for (int i = 0; i < MAX; i++)
		vector[i] = rand() % (VALOR_MAX - VALOR_MIN + 1) + VALOR_MIN;

	printf("\nSe ha generado el siguiente vector:\n");
	
	for (int j = 0; j < MAX; j++)
		printf(" %d", vector[j]);
	
	printf("\n");
}


void calcular_medias (int vector[MAX])
{
	int suma_pares = 0, suma_impares = 0, cuenta_pares = 0, cuenta_impares = 0;

	for (int i = 0; i < MAX; i++)
		if (vector[i] % 2 == 0)
		{
			cuenta_pares++;
			suma_pares += vector[i];
		}
		else
		{
			cuenta_impares++;
			suma_impares += vector[i];
		}


	printf("\nNumero de valores pares: %d - ", cuenta_pares);
	if (cuenta_pares)
		printf("Media de los valores pares: Aproximadamente %d.", decena_cercana ((float)suma_pares / cuenta_pares));
	else
		printf("No se puede calcular la media.");

	printf("\nNumero de valores impares: %d - ", cuenta_impares);
	if (cuenta_impares)
		printf("Media de los valores impares: Aproximadamente %d.", decena_cercana ((float)suma_impares / cuenta_impares));
	else
		printf("No se puede calcular la media.");

	printf("\n");
}


int decena_cercana (float cantidad)
{
	if ((int)cantidad % 10 >= 5)
		return ((int)cantidad / 10 * 10 + 10);
	else
		return ((int)cantidad / 10 * 10);
}


void almacenar_extremos (int vector[MAX])
{
	int valores [4] = {VALOR_MAX + 1, VALOR_MAX + 1, VALOR_MIN - 1,VALOR_MIN - 1};

	for (int i = 0; i < MAX; i++)
	{
		// Cálculo de los valores mínimos:
		if (vector[i] < valores[0]) // ==> Desplazamiento
		{
			valores[1] = valores[0];
			valores[0] = vector[i];
		}
		else
			if (vector[i] < valores[1])
				valores[1] = vector[i];

		// Cálculo de los valores máximos:
		if (vector[i] > valores[3]) // ==> Desplazamiento
		{
			valores[2] = valores[3];
			valores[3] = vector[i];
		}
		else
			if (vector[i] > valores[2])
				valores[2] = vector[i];
	}

	printf("\nValores extremos: ");
	
	for (int j = 0; j < 4; j++)
		printf(" %d", valores[j]);

	printf("\n");
}


void ordenar_vector (int vector[MAX])
{
	int aux;
	int recorrido_sin_cambios;

	for (int i = 1; i < MAX; i++)
	{
		recorrido_sin_cambios = 1;

		for (int j = 0; j < MAX - 1; j++)
			if (vector[j] > vector[j+1])
			{
				recorrido_sin_cambios = 0;

				aux = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = aux;
			}

		if (recorrido_sin_cambios)
			break;
	}

	printf("\nVector ordenado:");

	for (int k = 0; k < MAX; k++)
		printf(" %d", vector[k]);

	printf("\n");
}


void salir (int cuenta_opciones [5])
{
	for (int i = 0; i < 5; i++)
		if (cuenta_opciones[i])
			printf("\nOpcion %d: %d veces.", i + 1, cuenta_opciones[i]);
	
	printf("\n\n");
}


/********************************************************************************
****************************** PROGRAMA PRINCIPAL *******************************
********************************************************************************/
void main()
{
	int vector [MAX]; // Estructura principal de datos del programa.
	
	int cuenta_opciones [5] = {0, 0, 0, 0, 0}; // Contadores correspondientes a las opciones del menú.

	int opcion;

	srand ((unsigned)time(NULL));  // Inicialización de la semilla de números aleatorios.

	do{
		mostrar_menu();
		leer_opcion (&opcion, cuenta_opciones);
		ejecutar_opcion (opcion, vector, cuenta_opciones);
	}while (opcion != 5);

}