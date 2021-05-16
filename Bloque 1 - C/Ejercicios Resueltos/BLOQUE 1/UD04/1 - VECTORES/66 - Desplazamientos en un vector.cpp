#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10


int leer_posiciones()
{
	int n;
	
	do{
		printf("Cuantas posiciones desea desplazar el vector?: ");
		scanf("%d", &n);
		fflush(stdin);
	}while(n <= 0);
	
	return n;
}


char leer_direccion()
{
	char d;
	
	do{
		printf("En que direccion (i = izquierda, d = derecha): ");
		scanf("%c", &d);
		fflush(stdin);
	}while(d != 'i' && d != 'd');
	
	return d;
}


void desplaza_izquierda (int t[])
{
	int i, aux = t[0];

	for (i=0; i<TAM-1; i++)
		t[i] = t[i+1];

	t[TAM-1] = aux;
}


void desplaza_derecha (int t[])
{
	int i, aux = t[TAM-1];

	for (i=TAM-1; i>0; i--)
		t[i] = t[i-1];

	t[0] = aux;
}


void desplaza_vector (int t[])
{
	int posiciones;
	char direccion;
	int i;
	
	posiciones = leer_posiciones ();
	direccion = leer_direccion ();
	
	if (direccion == 'i')
		for (i = 0; i < posiciones; i++)
			desplaza_izquierda (t);
	else
		for (i = 0; i < posiciones; i++)
			desplaza_derecha (t);
}


void imprime_vector (int t[])
{
	int i;

	for (i=0; i<TAM; i++)
		printf("%d ", t[i]);
	printf("\n\n");
}


void rellena_vector (int t[])
{
	int i;
	
	srand (time(NULL));

	for (i=0; i<TAM; i++)
		t[i] = rand() % 100; // Es simplemente un ejemplo, el enunciado no indica nada.
}


void main()
{
	int vector[TAM];

    rellena_vector (vector);
	
	printf("\n\nContenido del vector original: ");
    imprime_vector (vector);

    desplaza_vector (vector);

	printf("\n\nContenido del vector desplazado: ");
    imprime_vector (vector);
}
