#include <stdio.h>

bool es_primo(int num);

void main() 
{
	// PARTE 1
	// Declaración de variables
	int num = 0, cifras = 0;
	int contador1 = 0, aux1; 
	int cifra; // Esta variable es para la parte 2
	bool valido = false;

	// Lectura del número
	do {
		printf("Por favor, introduzca un numero entero positivo: \n");
		scanf("%d", &num);
		fflush(stdin);
	} while((num >= (10000)) || (num < 0));
	
	aux1 = num;
	do
	{
		contador1 ++;
		aux1 = aux1 / 10;
	} while (aux1 > 0);
	
	switch (contador1)
	{
	case 1:
		{
			cifra = num;

			if((num % 2 == 0) && (num != 0))
			{valido = true;}
			break;
		}
	case 2:
		{
			// Declaración de variables para las cifras
			// c1 es la cifra de la unidad
			int aux2, c1, c2;

			aux2 = num;
			c1 = aux2 % 10;
			aux2 = aux2 / 10;
			c2 = aux2 % 10;

			if(c1 > c2) {cifra = c1;}
			else{cifra = c2;}

			int copia_num = num, divisor = num / 2;
			bool resultado = false;

			do {
				if (copia_num % divisor == 0)
				{resultado = true; break;}
				divisor = divisor - 1;
			} while (divisor > 0);

			if (resultado == false)
			{valido = true;}

			break;
		}
	case 3:
		{
			// Declaración de variables para las cifras
			// c1 es la cifra de la unidad, c2 las decenas...
			int aux3, c1, c2, c3;
			
			aux3 = num;
			c1 = aux3 % 10;
			aux3 = aux3 / 10;
			c2 = aux3 % 10;
			aux3 = aux3 / 10;
			c3 = aux3 % 10;

			if((c1 > c2) && (c1 > c3)) {cifra = c1;}
			else {
				if((c2 > c1) && (c2 > c3)) {cifra = c2;}
				else {
					if ((c3 > c1) && (c3 > c2)) {cifra = c3;}
				}
			}

			if (c1 == c3)
			{valido = true;}

			break;
		}
	case 4:
		{
			// Declaración de variables para las cifras
			// c1 es la cifra de la unidad, c2 las decenas, ...
			int aux4, c1, c2, c3, c4;

			aux4 = num;
			c1 = aux4 % 10;
			aux4 = aux4 / 10;
			c2 = aux4 % 10;
			aux4 = aux4 / 10;
			c3 = aux4 % 10;
			aux4 = aux4 / 10;
			c4 = aux4 % 10;

			
			if((c1 > c2) && (c1 > c3) && (c1 > c4)) {cifra = c1;}
			else {
				if((c2 > c1) && (c2 > c3) && (c2 > c4)) {cifra = c2;}
				else {
					if ((c3 > c1) && (c3 > c2) && (c3 > c4)) {cifra = c3;}
					else {
						if((c4 > c1) && (c4 > c2) && (c4 > c3)) {cifra = c4;}
					}
				}
			}

			if (num % c3 != 0)
			{valido = true;}

			break;
		}
	}

	if(valido == true) 
	{
		printf("El numero es valido.\n");
	} else 
	{printf("El numero NO es valido.\n");}

	// PARTE 2
	// Declaración de variables necesarias para esta parte
	int lado, i, j, contador2 = 0;

	// Comprobar que cifra es impar
	if (cifra % 2 == 0) {cifra = cifra - 1;}
	lado = cifra;

	// Hasta llegar al centro
	do {
		// Espacios de la izquierda
		for (j = 0; j < contador2; j++)
		{printf(" ");}

		// Mostrar la primera cifra
		printf("%d", cifra);

		// Espacios intermedios
		for (i = 0; i < (lado - (2 + 2*contador2)) ; i++)
		{printf(" ");}
		
		// Mostrar la segunda cifra, si aparece
		if (contador2 == ((lado / 2))) 
		{printf("\n");} else 
		{ printf("%d\n", cifra);}

		contador2 ++;
	} while(contador2 < (lado / 2) + 1);

	// Desde el centro hasta el final
	
	contador2 = (lado / 2) - 1;
	do {
		// Espacios de la izquierda
		for (j = 0; j < contador2; j++)
		{printf(" ");}

		// Mostrar la primera cifra
		printf("%d", cifra);

		// Espacios intermedios
		for (i = 0; i < (lado - (2 + 2*contador2)) ; i++)
		{printf(" ");}
		
		// Mostrar la segunda cifra, si aparece
		printf("%d\n", cifra);

		contador2 --;
	} while(contador2 >= 0);
	

	// PARTE 3
	// Declaracion de variables
	int num2, aux_resta, cont_resta = 0;

	// Lectura de datos
	do {
		printf("Por favor, introduzca otro numero entero positivo: \n");
		scanf("%d", &num2);
		fflush(stdin);
	} while((num2 >= (100)) || (num2 < 0));

	
	if(num < num2) 
	{printf("El numero de partida no contiene ninguna vez al segundo numero");}
	else {
		aux_resta = num;
		do {
			aux_resta = aux_resta - num2;
			cont_resta ++;
		} while (aux_resta != 0);

		printf("El número %d contiene %d veces al numero %d.\n", num, cont_resta, num2);
	}
	
}
