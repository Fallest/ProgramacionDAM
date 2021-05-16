#include <stdio.h>


void main()
{
	int numero1, numero2, aux;
	int numero_de_veces = 0;
	int copia_numero_mayor;


	// LECTURA DE LOS NUMEROS
	do{
		printf("Introduzca el numero 1: ");
		scanf("%d", &numero1);
		fflush(stdin);
	}while (numero1 <= 0);

	do{
		printf("Introduzca el numero 2: ");
		scanf("%d", &numero2);
		fflush(stdin);
	}while (numero2 <= 0);


	// COLOCAR EL MAYOR EN LA VARIABLE numero1
	if (numero1 < numero2)
	{
		aux = numero1;
		numero1 = numero2;
		numero2 = aux;
	}

	copia_numero_mayor = numero1;


	// CALCULOS
	while (copia_numero_mayor >= numero2)
	{
		copia_numero_mayor = copia_numero_mayor - numero2;
		numero_de_veces++;
	}


	// IMPRESION DE RESULTADOS
	printf("\nEl numero %d contiene %d veces al numero %d.\n", numero1, numero_de_veces, numero2);
	if (copia_numero_mayor == 0)
		printf("La division SI es exacta.\n");
	else
		printf("La division NO es exacta.\n");
}