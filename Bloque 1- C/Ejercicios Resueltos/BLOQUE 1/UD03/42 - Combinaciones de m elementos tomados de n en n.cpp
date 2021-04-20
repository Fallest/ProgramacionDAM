#include <stdio.h>


int factorial (int num)
{
  // Inicializacion de variables:
  int factorial = 1;
  int cont = 1;

  // Proceso repetitivo: 
  do{
    factorial = factorial * cont;
    cont++;
  }while (cont <= num);

  return factorial;
}


int leer_operando (char op)
{
	int numero;

	do{
		printf("Introduzca el valor de %c: ", op);
		scanf("%d", &numero);
		fflush(stdin);
	}while(numero <= 0);

	return numero;
}






void main()
{
	int m, n;
	int resultado;

	// Lectura y validacion de los dos operandos:
	m = leer_operando ('m');
	n = leer_operando ('n');

	// Calculo del resultado de la formula:
	resultado = (factorial(m) * factorial(n)) / (factorial(m-n));

	// Imprimir el resultado:
	printf("Las combinaciones de %d numeros tomadas de %d en %d son %d.\n\n",
		m, n, n, resultado);
}

