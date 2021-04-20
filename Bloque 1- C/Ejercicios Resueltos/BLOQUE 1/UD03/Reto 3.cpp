#include <stdio.h>


void numero_terminos (int *cuenta, int numero)
{
	int valor = 1;
	
	(*cuenta) = 0;
	
	do{
		(*cuenta)++;
		valor = 2 * valor + 1;
	}while(valor < numero);
}


void valor_termino (int *v, int n)
{
	int n_terminos = 1;
	
	(*v) = 1;
	
	while(n_terminos < n)
	{
		n_terminos++;
		(*v) = 2 * (*v) + 1;
	}
}



void leer_numero (int *n, int op)
{
	do{
		switch (op)
		{
			case 1: printf("\nIntroduce un numero positivo: ");
					break;
			case 2: printf("\nIntroduce el termino a obtener: ");
					break;
			case 3: printf("\nIntroduce el valor tope: ");
		}
		
		scanf("%d", n);
		fflush(stdin);
	}while((*n) < 1);
}



void valores_entre (int *v1, int *v2, int n)
{
	(*v1) = 1;
	
	while ((*v1) <= n)
	{
		(*v2) = (*v1);
		(*v1) = 2 * (*v1) + 1;
	}
}



void mostrar_resultado (int op, int n1, int n2, int v)
{
	switch (op)
	{
		case 1: printf("\nEl %d esta comprendido entre los numeros %d y %d.\n", v, n1, n2);
				break;
		case 2: printf("\nEl termino %d de la serie es el %d\n", v, n1);
				break;
		case 3: printf("\nHay %d valores de la serie no superiores a %d.\n", n1, v);
				break;
		case 4: printf("\nFin del programa.\n");
	}
}



void ejecuta_opcion_elegida (int *v1, int *v2, int n, int op)
{
	switch(op)
	{
		case 1: valores_entre (v1, v2, n);
				break;
		case 2: valor_termino (v1, n);
				break;
		case 3: numero_terminos (v1, n);
	}
}


void realizar_opcion (int op)
{
	int valor1, valor2, numero;
	
	if (op != 4)
	{
		leer_numero (&numero, op);
		ejecuta_opcion_elegida (&valor1, &valor2, numero, op);
	}
	
	mostrar_resultado (op, valor1, valor2, numero);
}


void escribir_menu()
{
	printf("\nMENU PRINCIPAL\n\n");
	printf("1.- Valores entre los que esta comprendido un numero.\n");
	printf("2.- Valor de un termino de la serie.\n");
  	printf("3.- Numero de terminos no superiores a un numero.\n");
  	printf("4.- Salir del programa.\n\n");
}




void leer_opcion (int *op)
{
	do{
		printf("Introduzca a opcion que desee:");
		scanf("%d", op);
		fflush(stdin);
	}while((*op) != 1 && (*op) != 2 && (*op) != 3 && (*op) != 4);
}


void main()
{
	int opcion;
	
	do{
		escribir_menu();
		leer_opcion(&opcion);
		realizar_opcion (opcion);
	}while(opcion == 1 || opcion == 2 || opcion == 3);
}
