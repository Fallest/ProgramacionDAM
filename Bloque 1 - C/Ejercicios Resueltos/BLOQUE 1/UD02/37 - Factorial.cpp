#include <stdio.h>

void main()
{
  int num; // Numero que introduce el usuario para calcularle su factorial.
  int factorial; // Acumulara el resultado de cada producto (y al final nos dara el resultado que buscamos).
  int cont; // Contara el numero de productos que llevamos.

  do{
    printf("Introduzca un numero (>0): ");
    scanf("%d", &num);
	fflush(stdin);
  }while (num <= 0);

  // Inicializacion de variables:
  factorial = 1;
  cont = 1;

  // Proceso repetitivo: 
  do{
    factorial = factorial * cont;
    cont++;
  }while (cont <= num);

  // Impresion del resultado:
  printf("\nEl factorial del numero %d es %d.\n", num, factorial);
}