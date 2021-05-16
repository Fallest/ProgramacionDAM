/*
Realizar una calculadora aritmetica sencilla:
- Se leen dos numeros enteros.
- Se lee un caracter: S, R, M, D (suma, resta, multiplicacion o division).
- Dependiendo de la letra, se calcula la expresion correspondiente a esa operacion.
- Se muestra el resultado.
OJO: Division por cero.
*/

#include <stdio.h>

void main()
{
  int operando1, operando2;
  char operador;

  printf("Introduzca el valor del primer operando: ");
  scanf("%d", &operando1);
  fflush(stdin);

  printf("Introduzca el valor del segundo operando: ");
  scanf("%d", &operando2);
  fflush(stdin);

  printf("Indique la operacion a realizar (s - suma, r - resta, m - multiplicacion, d - division): ");
  scanf("%c", &operador);
  fflush(stdin);

  if (operador == 's')
    printf("La suma de los dos valores introducidos vale %d.\n", operando1 + operando2);
  else
    if (operador == 'r')
      printf("La resta de los dos valores introducidos vale %d.\n", operando1 - operando2);
    else
      if (operador == 'm')
        printf("La multiplicacion de los dos valores introducidos vale %d.\n", operando1 * operando2);
      else
        if (operando2 == 0)
          printf("No puede efectuarse una division por cero.\n");
        else
          printf("La division de los dos valores introducidos vale %f.\n", (float) operando1 / operando2);
}
