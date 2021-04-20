#include <stdio.h>

bool n_coincidentes(int a, int b, int n);

void main()
{
	//Declaracion de variables
	int a, b, n;
	bool coincidentes; // true si son n coincidentes.

	// Lectura de datos
	// Como tienen que ser enteros positivos,
	// se comprueba en cada ciclo del bucle si son positivos.
	do {
		printf("Que numeros quiere comprobar (a, b)?: ");
		scanf("%d, %d", &a, &b);
		fflush(stdin);

		printf("Cuantas cifras quiere comprobar (desde la unidad)?: ");
		scanf("%d", &n);
		fflush(stdin);
	} while ((a < 0) || (b < 0) || (n < 0));

	coincidentes = n_coincidentes(a, b, n);

	if(coincidentes == true) {printf("Los numeros %d y %d son n coincidentes.\n", a, b);}
	else {printf("Los numeros %d y %d NO son n coincidentes.\n", a, b);}
}

bool n_coincidentes(int a, int b, int n)
{
	// Declaracion de variables formales
	/*
	Las variables suma_a y suma_b hay que inicializarlas
	a 0, para evitar errores al hacer la primera suma en el bucle
	for.
	*/
	int suma_a = 0, suma_b = 0, i;
	bool resultado = false;

	for(i = 0; i < n; i++)
	{
		suma_a = suma_a + (a % 10);
		suma_b = suma_b + (b % 10);
		a = a / 10;
		b = b / 10;
	}

	if(suma_a == suma_b) {resultado = true;}
	
	return resultado;
}