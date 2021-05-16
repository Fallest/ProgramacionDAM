#include <stdio.h>

void main()
{
  int contador, numero, suma_divisores;

  do{
    printf("Introduzca un numero (>0): ");
    scanf("%d", &numero);
	fflush(stdin);
  }while (numero <= 0);

  suma_divisores = 1;

  for (contador = 2; contador <= numero/2; contador++)
    if (numero % contador == 0)
      suma_divisores = suma_divisores + contador;

  if (suma_divisores == numero)
    printf("\nEs perfecto.\n");
  else
    printf("\nNo es perfecto.\n");
}