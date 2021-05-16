//LIBRERIAS
#include<stdio.h>

//PROTOTIPOS
void mostrar_menu();
int leer_opcion();
void tratar_opcion (int *op, int *saldo, int *cont_r, int *cont_i);
void pedir_saldo_inicial (int *n);
void consulta_cuenta (int saldo, int cont_r, int cont_i);
void hacer_reintegro (int *saldo, int *cont_r);
void leer_cantidad_a_sacar (int saldo, int *cantidad);
void hacer_ingreso (int *saldo, int *cont_i);
void leer_cantidad_a_ingresar (int *n);
void finalizar (int saldo, int *op);
int desea_salir ();


//*************************************
//*************************************
//PROGRAMA PRINCIPAL
//*************************************
//*************************************

void main()
{
	int opcion;
	int saldo, cont_reintegros = 0, cont_ingresos = 0;
	
	// Lectura del saldo inicial:
	pedir_saldo_inicial (&saldo);

	do{
		mostrar_menu();
		opcion = leer_opcion();
		tratar_opcion(&opcion, &saldo, &cont_reintegros, &cont_ingresos);
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
	printf("1)	Reintegro.\n");
	printf("2)	Ingreso.\n");
	printf("3)	Consulta.\n");
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


void tratar_opcion (int *op, int *saldo, int *cont_r, int *cont_i)
{
	switch(*op)
	{
	case 1: hacer_reintegro (saldo, cont_r);
			break;
	case 2: hacer_ingreso (saldo, cont_i);
			break;
	case 3: consulta_cuenta (*saldo, *cont_r, *cont_i);
			break;
	case 4: finalizar (*saldo, op);
	}
}


int desea_salir ()
{
	int salir;

	do{
		printf("Seguro que desea salir (1 = SI, 0 = NO)?: ");
		scanf("%d", &salir);
		fflush(stdin);
	}while(salir != 0 && salir != 1);

	return salir;
}

void finalizar (int saldo, int *op)
{
	if (desea_salir())
	{
		printf("\n\nEl saldo final es de %d euros.", saldo);
		printf("\nEl programa va a finalizar.\n\n");
	}
	else
		*op = 3; // Ficticio, es para que no se detenga el programa.
}


void leer_cantidad_a_sacar (int saldo, int *cantidad)
{
	do{
		printf("\n\nVa a realizar un reintegro.\n");
		printf("Introduzca la cantidad a sacar de la cuenta ");
		printf("(maximo %d): ", saldo);
		scanf("%d", cantidad);
		fflush(stdin);
	}while((*cantidad <= 0) || (*cantidad > saldo));
}


void leer_cantidad_a_ingresar (int *n)
{
	do{
		printf("Introduzca la cantidad a ingresar (positivo): ");
		scanf("%d", n);
		fflush(stdin);
	}while((*n) <= 0);
}


void hacer_ingreso (int *saldo, int *cont_i)
{
	int cantidad;
	
	leer_cantidad_a_ingresar (&cantidad);

	(*saldo) += cantidad;
	(*cont_i)++;

	printf("\nOperacion realizada con exito.\n\n");
}




void hacer_reintegro (int *saldo, int *cont_r)
{
	int cantidad;
	
	leer_cantidad_a_sacar (*saldo, &cantidad);

	(*saldo) -= cantidad;
	(*cont_r)++;

	printf("\nOperacion realizada con exito.\n\n");
}


void consulta_cuenta (int saldo, int cont_r, int cont_i)
{
	printf("\nEl saldo actual de la cuenta es de %d euros.\n", saldo);
	printf("Se han realizado hasta el momento %d reintegros y", cont_r);
	printf(" %d ingresos.\n\n", cont_i);
}


void pedir_saldo_inicial (int *n)
{
	do{
		printf("Introduzca el saldo inicial (positivo): ");
		scanf("%d", n);
		fflush(stdin);
	}while((*n) <= 0);
}
