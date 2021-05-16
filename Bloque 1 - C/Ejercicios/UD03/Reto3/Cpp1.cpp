#include <stdio.h>

void comprendido_entre(int num);
void doble_mas_uno(int termino);
void terminos_menores(int num);
void salir(bool *ejecucion);

void main()
{
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

		// Manejo de opciones
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
	// Declaracion de variables
	// el termino1 sera el miembro menor del intervalo
	int termino1, termino2, num_term1, num_term2;

	/* 
	Primero obtendremos el valor de la serie inmediatamente inferior
	al numero dado, y para obtener el superior solo tendremos que aumentar
	el termino en 1.
	*/

	// CALCULO DEL TERMINO MENOR
	// Declaracion de variables
	int contador = 0, i, num_anterior = 0;

	// Serie trucada
	for(i = 0; num_anterior < num; i ++)
	{
		num_anterior = (num_anterior * 2) + 1;
		contador ++;
	}
	// Asignaciones
	termino1 = num_anterior;
	num_term1 = contador;

	// CALCULO DEL TERMINO MAYOR
	// Serie:
	do {
		num_anterior = (num_anterior * 2) + 1;
		contador ++;
	} while(num_anterior < num);
	// Asignaciones
	termino2 = contador;
	num_term2 = num_anterior;

	printf("El numero %d esta comprendido entre los terminos %d y %d.", num, num_term1, num_term2);
}

void doble_mas_uno(int termino)
{
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
	// Declaracion de variables
	int contador = -1, num_anterior = 0;
	
	// Serie trucada
	do 
	{
		num_anterior = (num_anterior * 2) + 1;
		contador ++;
	} while (num_anterior <= num);

	printf("Hay %d valores de la serie no superiores a %d.\n", contador, num);
}

void salir(bool *ejecucion)
{ *ejecucion = false;}


