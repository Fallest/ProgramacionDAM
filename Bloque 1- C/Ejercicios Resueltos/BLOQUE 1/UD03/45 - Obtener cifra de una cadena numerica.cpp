// LIBRERÍAS
#include <stdio.h>

// CONSTANTES
#define NO_EXISTE_CIFRA -1

// PROTOTIPOS
void leer_opcion (char *);
void leer_numero (int *);
void leer_cifra (int *);
void quitar_ultima_cifra (int *);
int devolver_ultima_cifra (int);
int calcula_cifra (int, int);
void imprimir_resultado (int, int);

// FUNCIONES
void leer_opcion (char *opcion)
{
	do{
		printf("\n\n¿Desea continuar (S/N)?: ");
		scanf("%c", opcion);
		fflush(stdin);
	}while (((*opcion) != 'S') && ((*opcion) != 's') && ((*opcion) != 'N') && ((*opcion) != 'n'));
}


void leer_numero (int *numero)
{
	do{
		printf("Introduzca numero: ");
		scanf("%d", numero);
		fflush(stdin);
	}while ((*numero) < 1);
}


void leer_cifra (int *orden)
{
	do{
		printf("Introduzca numero de orden: ");
		scanf("%d", orden);
		fflush(stdin);
	}while ((*orden) < 1);
}


void quitar_ultima_cifra (int *numero)
{
	(*numero) = (*numero) / 10;
}


int devolver_ultima_cifra (int numero)
{
	return (numero % 10);
}


int calcula_cifra (int numero, int orden)
{
	int cont;
	for (cont = 1; cont <= orden - 1; cont++)
	{
      quitar_ultima_cifra (&numero);
	  if (numero == 0)
		  return NO_EXISTE_CIFRA;
	}
	return (devolver_ultima_cifra(numero));
}


void imprimir_resultado (int orden, int cifra)
{
	if (cifra == NO_EXISTE_CIFRA)
		printf("\nNo existe la cifra %d en el numero", orden);
	else
		printf("\nLa cifra con orden %d es un %d", orden, cifra);
}


// PROGRAMA PRINCIPAL
void main()
{
	int n, orden, cifra;
	char opcion;
    
	leer_numero (&n);

	do{
		leer_cifra (&orden);
		cifra = calcula_cifra (n, orden);
        imprimir_resultado (orden, cifra);
        leer_opcion (&opcion);
	} while ((opcion == 's') || (opcion == 'S'));
}
