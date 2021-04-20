#include <stdio.h>

void main()
{
  int numero; // Numero introducido por el teclado.

  // Lectura del numero:
  do{
    printf("Escriba un numero positivo: ");
    scanf("%d", &numero);
	fflush(stdin);
  }while (numero <= 0);

  // Cabecera de la salida:
  printf("\nEl numero %d invertido es ", numero);

  // Generacion de los digitos invertidos:
  while (numero > 0)
  {
    printf("%d", numero % 10);
    numero = numero / 10;
  }
  printf("\n\n");
}