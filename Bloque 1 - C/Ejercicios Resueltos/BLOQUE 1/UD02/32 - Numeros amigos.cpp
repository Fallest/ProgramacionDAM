#include <stdio.h>

void main()
{

  int contador, numero1, numero2, suma_divisores1, suma_divisores2;

  do{
    printf("Introduzca el primer numero (>0): ");
    scanf("%d", &numero1);
	fflush(stdin);
  }while (numero1 <= 0);

  do{
    printf("\nIntroduzca el segundo numero (>0): ");
    scanf("%d", &numero2);
	fflush(stdin);
  }while (numero2 <= 0);

  suma_divisores1 = 1;
  suma_divisores2 = 1;

  for (contador = 2; contador <= numero1/2; contador++)
    if (numero1 % contador == 0)
      suma_divisores1 = suma_divisores1 + contador;

  if (suma_divisores1 == numero2)  // Si no es así, no hago comprobaciones con el otro número porque ya sé que no son "amigos".
  {
    for (contador = 2; contador <= numero2/2; contador++)
      if (numero2 % contador == 0)
        suma_divisores2 = suma_divisores2 + contador;

    if (suma_divisores2 == numero1)
      printf("\nSon amigos.\n");
    else
      printf("\nNo son amigos.\n");
  }
  else
    printf("\nNo son amigos.\n");
}