#include <stdio.h>

/*
Realizar un programa que lea dos numeros, los sume e informe del resultado.
*/

// PROTOTIPOS DE LAS FUNCIONES
int calcular_suma (int n1, int n2);
int leer_valor_sumando (int orden);




void main()
{
	int sumando1, sumando2, suma;

	// Lectura de los datos de los sumandos:
	sumando1 = leer_valor_sumando (1);
	sumando2 = leer_valor_sumando (2);

	// Calculo de la suma:
	suma = calcular_suma (sumando1, sumando2);

	// Impresion del resultado:
	// imprimir_resultado_suma (suma, sumando1, sumando2); Descartado.
	printf("%d + %d = %d\n\n", sumando1, sumando2, suma);
}


int calcular_suma (int n1, int n2)
{
	/*
	int suma;
	suma = n1 + n2;
	return suma;
	*/

	return (n1 + n2);
}


int leer_valor_sumando (int orden)
{
	int numero;

	printf("Introduce el valor del sumando %d: ", orden);
	scanf("%d", &numero);
	fflush(stdin);

	return numero;
}