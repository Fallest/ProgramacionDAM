#include <stdio.h>

int leer_numero_valores()
{
	int numero;

	do{
		printf("Introduzca el numero de valores (positivo): ");
		scanf("%d", &numero);
		fflush(stdin);
	}while (numero <= 0);

	return numero;
}


int leer_valor(int orden)
{
	int numero;

	do{
		printf("Introduzca el valor (%d): ", orden);
		scanf("%d", &numero);
		fflush(stdin);
	}while (numero <= 0);

	return numero;
}


void comprueba_si_perfecto (int numero)
{
  int suma_divisores = 1;

  for (int contador = 2; contador <= numero/2; contador++)
    if (numero % contador == 0)
      suma_divisores = suma_divisores + contador;

  if (suma_divisores == numero)
    printf("\nEs perfecto.\n");
  else
    printf("\nNo es perfecto.\n");
}


void main()
{
	int contador = 1;
	int limite = leer_numero_valores();
	int numero;

	for (;contador <= limite; contador++)
	{
		numero = leer_valor(contador);
		comprueba_si_perfecto(numero);
	}
}