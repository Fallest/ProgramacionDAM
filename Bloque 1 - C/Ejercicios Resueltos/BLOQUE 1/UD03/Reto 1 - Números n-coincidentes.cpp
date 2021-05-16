#include <stdio.h>


void leer_numero (int *numero, int indice);
int comprueba_n_coincidentes (int n1, int n2, int ncifras);
int suma_n_ultimas_cifras (int n, int c);


void leer_numero (int *numero, int indice)
{
	do{
		if (indice == 3) // Se quiere leer el numero de cifras
			printf("Introduzca el numero de cifras que quiere comprobar: ");
		else
			printf("Introduzca el numero %d (positivo): ", indice);

		scanf("%d", numero);
		fflush(stdin);
	}while ((*numero) <= 0);
}


int suma_n_ultimas_cifras (int n, int c)
{
	int suma = 0;

	// Mientras quede alguna cifra del numero y no se hayan comprobado todas:
	while ((n != 0) && (c != 0))
	{
		suma = suma + n % 10;  // Acumulamos el valor de la ultima cifra.
		n = n / 10;     // Quitamos la ultima cifra del numero.
		c--;            // Quitamos uno al numero de cifras a mirar
	}

	return suma;
}


int comprueba_n_coincidentes (int n1, int n2, int ncifras)
{
	if (suma_n_ultimas_cifras (n1, ncifras) == suma_n_ultimas_cifras (n2, ncifras))
		return 1;
	else
		return 0;
}


void main()
{
	int numero1, numero2, ncifras;
	
	// La regla de validacion es la misma para todos los datos de entrada
	// y por ello se utiliza la misma funcion:
	leer_numero (&numero1, 1);
	leer_numero (&numero2, 2);
	leer_numero (&ncifras, 3);  // 3 es el valor asignado a la lectura del numero de cifras.

	// Proceso y mensaje de salida:
	if (comprueba_n_coincidentes (numero1, numero2, ncifras))
		printf("Los numeros %d y %d son %d-coincidentes.\n\n", numero1, numero2, ncifras);
	else
		printf("Los numeros %d y %d no son %d-coincidentes.\n\n", numero1, numero2, ncifras);
}