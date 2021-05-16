#include <stdio.h>

void main()
{

  int n;  // Numero de terminos (lo introduce el usuario).
  int ultimo, penultimo, suma; // Variables que almacenaran los valores de los dos ultimos numeros y de su suma.
  int cont; // Nos servira para contar cuantos terminos llevamos.

  // Lectura de "N":
  do{
    printf("Introduzca el numero de terminos: ");
    scanf("%d", &n);
	fflush(stdin);
  }while (n <= 0);

  // Inicializacion de variables:
  ultimo = 1;
  penultimo = 1;
  suma = 1;

  // El primer termino (1) sale siempre:
  printf("\n%d ", penultimo);

  // Si el usuario quiere mas de un numero:
  if (n > 1)
  {
	// El segundo termino (1) saldra siempre, en este caso (porque como minimo n valdra 2).
    printf("%d ", ultimo);

	// Si n es mayor que 2 debo obtener el resto de valores sumando los dos ultimos de la serie:
    if (n > 2)
      for (cont = 2; cont < n; cont++)
      {
		// 1) "Desplazo" las variables "ultimo" y "penultimo".
		// 2) Actualizo la suma.
        penultimo = ultimo;
        ultimo = suma;
        suma = ultimo + penultimo;

		// Imprimo la suma, que sera en realidad el siguiente termino de la serie:
        printf("%d ", suma);
      }
  }
}
