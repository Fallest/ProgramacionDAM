#include <stdio.h>

void main()
{
	int contador; // Nos servira para contar los valores que van imprimiendose (para no pasarnos del limite).
	int limite;   // Es el numero de valores que saldra por pantalla.
	int base;     // Es el numero que tomaremos como multiplo base.

	do{
		printf("Introduzca el numero de valores: ");
		scanf("%d", &limite);
		fflush(stdin);
	}while (limite < 0);

	do{
		printf("Introduzca el valor de la base: ");
		scanf("%d", &base);
		fflush(stdin);
	}while (base < 0);

	// El primer valor que va a salir por pantalla es el propio numero base.
	contador = base; // Lo inicializamos al valor del primer múltiplo.
	printf("Multiplos de %d: ", base);

	// Imprimimos los que faltan (si es que falta alguno).
	while (limite != 0)  // Mientras queden números por imprimir:
	{
		printf ("%d ", contador);
		limite--;
		contador = contador + base;
	}
}