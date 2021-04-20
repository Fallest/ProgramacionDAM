/*
Programa resuelto en una convocatoria muy anterior.
Incluye:
- Una estructura de datos global.
- Dos variables enteras globales.
- Una función de inserción ordenada basada en aritmética de punteros.
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10

unsigned pila[MAX];
int n_elementos = 0;
int cima = 0;

void Introducir_valor();
void Leer_cima();
void Extraer_valores();
void Imprimir_contenido();
void Imprimir_ordenado();

void Inserta_en_tabla(unsigned, unsigned *, int *);

void main (void)
{
  int respuesta;

  do {
	system("CLS");
	printf("GESTION DE UNA PILA\n");
	printf("-------------------\n\n");
	printf("1.- Introducir un valor en la pila.\n");
	printf("2.- Leer la cima de la pila.\n");
	printf("3.- Extraer valores de la pila.\n");
	printf("4.- Imprimir el contenido de la pila.\n");
	printf("5.- Imprimir ordenadamente el contenido de la pila.\n\n");
	printf("0.- Salir del programa.\n\n");
	printf("¨Que hacemos?: ");
	scanf("%d", &respuesta);

	switch (respuesta) {
	  case 1: Introducir_valor();
			  break;
	  case 2: Leer_cima();
			  break;
	  case 3: Extraer_valores();
			  break;
	  case 4: Imprimir_contenido();
			  break;
	  case 5: Imprimir_ordenado();
			  break;
	}
  } while (respuesta!=0);

  printf("\n\nFIN DEL PROGRAMA");
  getch();

}

void Introducir_valor()
{
  unsigned valor;
  int i;

  if (n_elementos == MAX)
	printf("\nLa pila est  llena.");
  else
  {
	printf("\nIntroduzca el valor a insertar: ");
	scanf("%d", &valor);

	for (i=n_elementos-1; i>=0; i--)
	  pila[i+1] = pila[i];

	pila[0] = valor;

	printf("\nValor introducido en la posici¢n %d", ++n_elementos);
  }

  getch();
}


void Leer_cima()
{
  if (n_elementos == 0)
	printf("\nLa pila esta vacia.");
  else
	printf("\nLa cima de la pila contiene el elemento %d en la posici¢n %d.",
			pila[0], n_elementos);
  getch();
}


void Extraer_valores()
{
  int i, n;
  if (n_elementos == 0)
	printf("\nLa pila esta vacia.");
  else
  {
	printf("\nIntroduzca el numero de elementos a extraer (no mas de %d): ",
		   n_elementos);
	scanf("%d", &n);

	if (n > n_elementos)
	  printf("\nNo hay elementos suficientes en la pila.");
	else
	{
	  for (i=n; i<n_elementos; i++)
		pila[i-n] = pila[i];
	  n_elementos = n_elementos - n;
	  printf("\nExtraccion efectuada.");
	}
  }
  getch();
}


void Imprimir_contenido()
{
  int i;
  if (n_elementos == 0)
	printf("\nLa pila esta vacia.");
  else
  {
	printf("\nContenido de la pila: ");

	for (i=n_elementos-1; i>=0; i--)
	  printf("%d ", pila[i]);

	printf("(cima)");
  }

  getch();
}

void Imprimir_ordenado()
{
  int i, cont=0;
  unsigned aux[MAX];

  if (n_elementos == 0)
	printf("\nLa pila esta vacia.");
  else
  {


	  for (i=0; i<n_elementos; i++)
		Inserta_en_tabla(pila[i], aux, &cont);

	  printf("\nContenido de la pila (ordenado): ");
	  for (i=0; i<n_elementos; i++)
		printf("%d ", aux[i]);

  }

  getch();

}


void Inserta_en_tabla(unsigned elem, unsigned *tabla, int *n)
{
  int i, j, hecho=0;
  if (*n == 0)
	*tabla = elem;
  else
  {
	/* Busco el primer elemento de la tabla auxiliar que sea mayor
	   que el elemento que voy a insertar en ella */
	for (i=0; i<(*n) && !hecho; i++)
	  if (*(tabla+i)>elem)
	  {
		/* Lo he encontrado. Entonces abro un hueco arrastrando todos
		   los elementos desde esa posici¢n hasta el final a una posicion
		   mas adelante */
		for(j=(*n)-1; j>=i; j--)
		  *(tabla+j+1) = *(tabla+j);

		/* Y finalmente inserto mi nuevo elemento */
		*(tabla+i) = elem;

		hecho = 1;
	  }

	/* Si el nuevo elemento es el mayor de todos los que hay en la tabla
	   entonces en este punto del programa todav¡a no se habr  insertado
	   en la misma. Lo que hacemos es insertarlo al final */
	if (!hecho)
	  *(tabla+(*n)) = elem;
  }

  /* Incrementamos el contador que nos dice los elementos que ya tenemos
	 en la tabla auxiliar */
  (*n)++;

}