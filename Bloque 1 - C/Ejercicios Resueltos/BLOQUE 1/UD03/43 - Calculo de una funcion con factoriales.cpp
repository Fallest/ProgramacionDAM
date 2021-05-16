#include <stdio.h>

// PROTOTIPOS
float funcion_calculo (int n);
int factorial (int n);
int leer_operando ();


// FUNCIONES
float funcion_calculo (int n)
{
	int suma = 0;

	for (int i = 1; i <= n; i++)
		suma = suma + factorial (i);

	return (float) suma / n;
}



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


int leer_operando ()
{
	int numero;

	do{
		printf("Introduzca el valor de n (positivo): ");
		scanf("%d", &numero);
		fflush(stdin);
	}while(numero <= 0);

	return numero;
}




void main()
{
	int n;
	float resultado;

	// Lectura y validacion de los dos operandos:
	n = leer_operando ();

	// Calculo del resultado de la formula:
	resultado = funcion_calculo (n);

	// Imprimir el resultado:
	printf("El resultado de la funcion para el valor %d vale %.2f.\n\n",
		n, resultado);
}

