#include <stdio.h>

void main()
{

  int num1, num2;   // Numeros introducidos por el teclado.
  int aux, divisor; // Variables auxiliares.
  int encontrado;   // Bandera que se "levantara" cuando encontremos un divisor comun.

  divisor = 1;      // Inicializamos el resultado a 1 porque como minimo siempre vale 1.
  encontrado = 0;   // Valdra VERDADERO si encontramos el m.c.d. distinto de 1.

  // Lectura de los dos numeros:
  printf("Introduzca el primer numero (entero): ");
  scanf("%d", &num1);  // Supondremos que son enteros positivos.
  fflush(stdin);
  
  printf("Introduzca el segundo numero (entero): ");
  scanf("%d", &num2);
  fflush(stdin);

  if (num2 > num1)   // Si el segundo es mayor que el primero, los intercambiamos.
  {
    aux = num2;
    num2 = num1;
    num1 = aux;
  }

  aux = num2;   // Usamos una variable auxiliar para no perder el valor de num2.

  do{
	// Si ambos numeros son divisibles por aux entonces hemos encontrado el m.c.d.
    if ((num1%aux == 0) && (num2%aux == 0))
    {
      divisor = aux;
      encontrado = 1;
    }
    else
	{
      aux--;   // Decrementamos el valor de aux.
	  if (aux == 1)
		encontrado = 1;
	}
  }while (encontrado == 0);

  printf("\nEl m.c.d. entre %d y %d es %d.\n", num1, num2, divisor);

  // ¿Mejora posible?
}