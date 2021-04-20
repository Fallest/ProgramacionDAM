#include <stdio.h>

void main()
{

  int numero;        // Numero introducido por el teclado.
  int contador, aux; // Variables auxiliares.

  // Lectura del numero:
  do{
	printf("Introduzca un numero positivo: ");
	scanf("%d", &numero);
	fflush(stdin);
  }while (numero <= 0);

  contador = 1;        // Como minimo tendra 1 cifra.
  aux = numero;        // Utilizamos una variable auxiliar para no perder el valor original.

  do{
    aux = aux / 10;    // Le "quitamos" la ultima cifra.
    if (aux > 0)       // Si vale mas que cero entonces es que aux era mayor o igual que 10.
      contador++;      // Contamos una cifra mas.
  }while (aux > 0);

  printf("\nEl numero %d tiene %d cifras.\n", numero, contador);

}