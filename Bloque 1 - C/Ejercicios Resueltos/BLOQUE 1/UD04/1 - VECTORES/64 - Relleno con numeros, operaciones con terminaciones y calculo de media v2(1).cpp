#include <stdio.h>

#define TAM 10
#define LIMITE_INFERIOR 1
#define LIMITE_SUPERIOR 1000


void calcula_terminaciones_nulas (int d[]);
int calcula_terminacion_maxima (int d[]);
void imprime_numeros_digitos (int d[]);
float rellenar_vector (int t[], int *c, int d[]);



void calcula_terminaciones_nulas (int d[])
{
	int i;

	printf("\nTerminaciones que no se dan entre los valores introducidos: ");

	for (i=0; i<10; i++)
		if (d[i] == 0)
			printf("%d ", i);
}


int calcula_terminacion_maxima (int d[])
{
	int i, max=0, terminacion = 0;

	for (i=0; i<10; i++)
		if (d[i] > max)
		{
			max = d[i];
			terminacion = i;
		}

	if (d[terminacion] == 0)
		return -1;
	return terminacion;
}


void imprime_numeros_digitos (int d[])
{
	int i;

	for (i=0; i<10; i++)
		if (d[i] != 0)
			printf("\nHay %d numeros terminados en %d.", d[i], i);
}


float rellenar_vector (int t[], int *c, int d[])
{
	int numero;
	int suma = 0;

	(*c) = 0;

	do{
		do{
			printf("Introduzca un valor entre %d y %d: ", LIMITE_INFERIOR, LIMITE_SUPERIOR);
			scanf("%d", &numero);
			fflush(stdin);
		}while (((numero < LIMITE_INFERIOR) || (numero > LIMITE_SUPERIOR)) && (numero != 0));

		if (numero != 0)
		{
			t[(*c)] = numero;
			(*c)++;
			suma += numero;
			d[numero % 10]++;
		}
	}while ((numero != 0) && ((*c) < TAM));

	if ((*c) != 0)
		return (float)suma / (*c);
	else
		return -1;

}


void main()
{
	int vector[TAM];   // Vector con las cadenas numéricas que introduce el usuario.
	int digitos[] = {0,0,0,0,0,0,0,0,0,0};  // Vector de contadores de terminaciones.
	int ncadenas;  // Nº de cadenas numéricas introducidas.
	int termina;  // Terminación más repetida.
	float media;  // Media de los valores introducidos.

	// Se rellena el vector con todas las cadenas que introduce el usuario.
	// ncadenas almacenará cuántas cadenas se han introducido.
	// Se devuelve la media de los valores introducidos (-1 si no hay ninguno).
	// Se genera el vector de terminaciones.
    media = rellenar_vector (vector, &ncadenas, digitos);

	if (media != -1)
		printf("\nLa media de los valores introducidos es de %f.\n", media);

	// Se imprime cuántas cadenas terminan en cada uno de los números del 0 al 9.
	// Se omiten las terminaciones sin cadenas candidatas.
    imprime_numeros_digitos (digitos);

	// Se calcula la terminación más repetida (si hay varias sólo guarda la primera).
	// Si no hay cadenas la función devuelve -1.
	termina = calcula_terminacion_maxima (digitos);
	if (termina != -1)
	{
		printf("\n\nLa terminacion mas repetida es %d.\n", termina);
		calcula_terminaciones_nulas (digitos);
		printf("\n\n");
	}

}
