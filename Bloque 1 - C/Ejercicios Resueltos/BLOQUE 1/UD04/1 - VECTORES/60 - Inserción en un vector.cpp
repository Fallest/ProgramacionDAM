#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define MAXIMO 100

void rellena_vector (int v[])
{
	int i;
	srand((unsigned)time(NULL));

	for (i=0; i<TAM; i++)
		v[i] = rand() % (MAXIMO+1);
}


void imprime_vector (int v[])
{
	int i;
	for (i=0; i<TAM; i++)
		printf("   %d", v[i]);
}


void leer_numero (int *n)
{
	do{
		printf("\nIntroduzca el numero a insertar (maximo %d): ", MAXIMO);
		scanf("%d", n);
		fflush(stdin);
	}while (((*n) < 0) || ((*n) > MAXIMO));
}

void leer_posicion (int *p)
{
	do{
		printf("\nIntroduzca la posicion donde desea realizar la operacion (maximo %d): ", TAM);
		scanf("%d", p);
		fflush(stdin);
	}while (((*p) <= 0) || ((*p) > TAM));

}


void insertar_numero (int v[], int n, int p)
{
	int i;
	for (i=TAM-1; i>=p; i--)
		v[i] = v[i-1];
	v[p-1] = n;
}


void borrar_numero (int v[], int p)
{
	int i;
	for (i=p-1; i<TAM; i++)
		v[i] = v[i+1];
	v[TAM-1] = 0;
}


void leer_opcion (char *o)
{
	do{
		printf("\n\nQue desea realizar (i = insertar, b = borrar): ");
		scanf("%c", o);
		fflush(stdin);
	} while ((*o != 'i') && (*o != 'b'));
}

void realizar_operacion (char o, int v[], int p)
{
	int numero;
	if (o == 'i')
	{
		leer_numero (&numero);
	    insertar_numero (v, numero, p);
	}
	else
		borrar_numero (v, p);
}


void main()
{
	int vector[TAM];
	int posicion;
	char opcion;

	rellena_vector(vector);

	printf("\nEl vector original es: ");
	imprime_vector(vector);

	leer_opcion (&opcion);

	leer_posicion (&posicion);

	realizar_operacion (opcion, vector, posicion);

	printf("\nEl nuevo vector es: ");
	imprime_vector(vector);
	printf("\n\n");
}
