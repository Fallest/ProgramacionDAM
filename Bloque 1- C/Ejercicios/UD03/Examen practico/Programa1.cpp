#include <stdio.h>

void comprendido_entre(int num);
void doble_mas_uno(int termino);
void terminos_menores(int num);
void salir(bool *ejecucion);

void main()
{
	/* 
	En esta funcion se van a realizar las llamadas a las demas funciones.
	Debe mostrar un menu con cuatro opciones (cada una de las otras funciones).
	Dependiendo de la seleccion debe ejecutar una u otra funcion. No debe salir
	del programa hasta que se llame a la funcion salir().
	*/

	// Declaracion de variables
	int num, termino;
	char opcion;
	bool ejecucion = true;

	// Creacion del menu
	do {
		printf("Elige una opcion: \n");
		printf("a) Mostrar intervalo que contiene a un numero. \n");
		printf("b) Mostrar un termino concreto.\n");
		printf("c) Mostrar el numero de terminos inferiores a un numero. \n");
		printf("d) Salir.\n");

		scanf("%c", &opcion);
		fflush(stdin);

		// Manejo de opciones mediante un switch
		switch(opcion)
		{
		case 'a':
		case 'A':
			{
				do {
					printf("Introduce un numero positivo: ");
					scanf("%d", &num);
					fflush(stdin);
				} while(num < 0);
				
				comprendido_entre(num);
				break;
			}
		case 'b':
		case 'B':
			{
				do {
					printf("Introduce el termino a obtener: ");
					scanf("%d", &termino);
					fflush(stdin);
				} while(termino <= 0);

				doble_mas_uno(termino);
				break;
			}
		case 'c':
		case 'C':
			{
				do {
					printf("Introduce el valor tope: ");
					scanf("%d", &num);
					fflush(stdin);
				} while(num < 0);

				terminos_menores(num);
				break;
			}
		case 'd':
		case 'D':
			{salir(&ejecucion); break;}
		}
	} while (ejecucion == true);

	
}

void comprendido_entre(int num)
{
	/*
	Recibe como parametro un numero entero positivo, y muestra por pantalla
	entre que terminos de la serie doble_mas_uno esta comprendido.
	*/
	// Declaracion de variables
	// el termino1 sera el miembro menor del intervalo
	int termino1, termino2;

	// CALCULO DEL TERMINO MENOR
	// Declaracion de variables
	int i, num_anterior = 0, aux;

	// Serie trucada
	for(i = 0; num_anterior < num; i ++)
	{
		aux = num_anterior;
		num_anterior = (num_anterior * 2) + 1;

		if (num_anterior > num)
		{num_anterior = aux; break;}
	}
	// Asignaciones
	termino1 = num_anterior;

	// CALCULO DEL TERMINO MAYOR
	num_anterior = 0;
	// Serie:
	do {
		num_anterior = (num_anterior * 2) + 1;
	} while(num_anterior <= num);
	// Asignaciones
	termino2 = num_anterior;

	printf("El %d esta comprendido entre los numeros %d y %d de la serie.\n", num, termino1, termino2);
}

void doble_mas_uno(int termino)
{
	/*
	Recibe como parametro un termino concreto y calcula dicho termino,
	mostrandolo por pantalla cuando lo calcule.
	*/
	// Declaracion de variables
	int num_anterior = 0, i;

	// Serie:
	for(i = 0; i < termino; i ++)
	{
		num_anterior = (num_anterior * 2) + 1;
	}

	printf("El termino %d de la serie es el %d.\n", termino, num_anterior);
}

void terminos_menores(int num)
{
	/* 
	Recibe como parametro un entero positivo mayor que cero, y muestra
	por pantalla cuantos terminos de la serie doble_mas_uno son inferiores
	a dicho entero.
	*/
	// Declaracion de variables
	int contador = -1, num_anterior = 0;
	
	// Serie 
	do 
	{
		num_anterior = (num_anterior * 2) + 1;
		contador ++;
	} while (num_anterior <= num);

	printf("Hay %d valores de la serie no superiores a %d.\n", contador, num);
}

void salir(bool *ejecucion)
{	
	/*
	Recibe como parametro la direccion de memoria de un booleano, al cual
	cambiara el valor a false.
	*/
	*ejecucion = false;
}


