//LIBRERIAS
#include<stdio.h>

//PROTOTIPOS
void mostrar_menu();
int leer_opcion();
void tratar_opcion (int op);
void pedir_numero (int *n);
float suma_naturales (int n);
float producto_naturales (int n);
float suma_inversos (int n);



//*************************************
//*************************************
//PROGRAMA PRINCIPAL
//*************************************
//*************************************

void main()
{
	int opcion;
	
	do{
		mostrar_menu();
		opcion = leer_opcion();
		tratar_opcion(opcion);
	}while(opcion != 4);
}

//*************************************
//*************************************
//FUNCIONES
//*************************************
//*************************************
void mostrar_menu()
{
	printf("\n\nMENU PRINCIPAL\n");
	printf("--------------------------------------\n");
	printf("1)	Suma de numeros naturales.\n");
	printf("2)	Factorial.\n");
	printf("3)	Suma de los inversos.\n");
	printf("4)	Fin.\n\n");
}


int leer_opcion()
{
	int opcion;

	do{
		printf("Introduzca opcion: ");
		scanf("%d", &opcion);
		fflush(stdin);
	}while(opcion < 1 || opcion > 4);

	return opcion;
}


void tratar_opcion (int op)
{
	int n;
	float resultado;

	if (op != 4)
		pedir_numero (&n);
	
	switch(op)
	{
	case 1: resultado = suma_naturales (n);
			break;
	case 2: resultado = producto_naturales (n);
			break;
	case 3: resultado = suma_inversos (n);
			break;
	case 4: printf("El programa va a finalizar.\n\n");
	}

	if (op != 4)
		printf("\nEl resultado de la operacion solicitada es %.2f\n\n",
			resultado);
}


void pedir_numero (int *n)
{
	do{
		printf("Introduzca el valor limite (positivo): ");
		scanf("%d", n);
		fflush(stdin);
	}while((*n) <= 0);
}


float suma_naturales (int n)
{
	float suma = 0;

	for (int i = 1; i <= n; i++)
		suma = suma + i;
	
	return suma;
}


float producto_naturales (int n)
{
	float producto = 1;

	for (int i = 1; i <= n; i++)
		producto = producto * i;

	return producto;
}


float suma_inversos (int n)
{
	float suma = 0;

	for (int i = 1; i <= n; i++)
		suma = suma + (float) 1/i;
	
	return suma;
}