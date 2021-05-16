#include <stdio.h>
#include <stdlib.h>
#define TAM 10

// Prototipado
void introducir_valor(int vector[], int num);
void leer_cima(int vector[]);
void sacar_valores(int vector[], int num);
void imprimir_contenido(int vector[]);
void imprimir_contenido_ordenado(int vector[]);
void ordenar_vector(int vec[], int size, int aux[]);
void salir(bool *ejecucion);

void main()
{
	/* 
	Esta funcion muestra un menu, seleccionable con numeros, que permitira
	elegir cual de las otras 6 funciones se ejecutara. Solo se saldra del programa
	al escoger la opcion 6 (salir).
	*/

	// Declaracion de variables
	/* 	
	El booleano ejecucion es una variable interruptor para salir del programa.
	Sera true mientras el programa vaya a seguir funcionando, y solo cambiara
	su valor la funcion salir().
	*/
	
	int opcion, num, i;
	int vector[TAM];
	bool ejecucion = true;


	// Inicializacion del vector (igualar todo a 0)
	for(i = 0; i < TAM; i++)
		vector[i] = 0;

	// Lectura de datos
	do {
		printf("1. Introducir valor\n");
		printf("2. Leer cima\n");
		printf("3. Sacar valores\n");
		printf("4. Mostrar pila\n");
		printf("5. Mostrar pila ordenada por valor\n");
		printf("6. Salir\n");

		scanf("%d", &opcion);
		fflush(stdin);

		// Manejo de casos con un switch
		switch (opcion)
		{
			case 1:
			{
				printf("¿Que valor quieres introducir?: ");
				scanf("%d", &num);
				fflush(stdin);

				introducir_valor(vector, num);
				break;
			}
			case 2:
			{
				leer_cima(vector);
				break;
			}
			case 3:
			{
				printf("¿Cuantos valores quieres eliminar?: ");
				scanf("%d", &num);
				fflush(stdin);

				sacar_valores(vector, num);
				break;
			}
			case 4:
			{
				imprimir_contenido(vector);
				break;
			}
			case 5:
			{
				imprimir_contenido_ordenado(vector);
				break;
			}
			case 6:
			{
				salir(&ejecucion);
				break;
			}
			default:
			{
				printf("Ha ocurrido un error. Escoja una opcion valida.\n");
				break;
			}
		}
	} while (ejecucion);

}

void introducir_valor(int *vec, int num)
{
	/* 
	Esta función introduce un número (dado en los parámetros) en la
	posición 0 de la pila, desplazando los demás valores a la derecha.

	Debido a que se supondra que la entrada de elementos sera siempre positiva, se usara
	el numero 0 para representar las posicion que estan vacias.
	*/
	// Declaracion de variables
	int posicion = 1, i;

	// Comprobar que la pila no está llena
	if (vec[TAM - 1] != 0)
	{
		printf("El vector esta lleno. Si desea introducir mas datos debera eliminar otros datos.\n");
	}
	else
	{
		// Primero se desplazan todos los valores a una posicion superior
		for (i = TAM - 1; i > 0; i--)
		{
			vec[i] = vec[i - 1];
			if (vec[i] != 0)
			{posicion ++;}
		}
		
		// Ahora introducimos el valor en la posicion 0
		vec[0] = num;

		printf("Numero %d introducido en la posicion %d.\n", num, posicion);
	}
}

void leer_cima(int vector[])
{
	/* 
	Esta función va mostrar por pantalla el número en la posición 0 del vector,
	junto con su posicion en la pila.
	*/
	// Declaracion de variables
	int posicion = 0, i;

	for (i = 0; i < TAM; i++)
	{
		if(vector[i] != 0)
		{posicion ++;}
	}

	printf("La cima de la pila es el valor %d con posicion %d.\n", vector[0], posicion);
}

void sacar_valores(int vector[], int num)
{
	/* 
	Esta función elimina X valores desde la posición 0 del vector, es decir, elimina la posición
	0 y desplaza todos los valores hacia una posicion menor. Hace esto X veces.
	Se debe comprobar si la cantidad de numero a eliminar es mayor que los numeros que hay en el
	vector, y si se da mas valores a eliminar de los que hay en el vector, mostrar un mensaje de
	error por pantalla.
	*/
	// Declaracion de variables
	int i, elementos_pila = 0, posicion = 0;

	// Comprobar que el numero de valores a eliminar no es mayor que el numero de valores que hay
	// en la pila
	for (i = 0; i < TAM; i++)
	{
		if(vector[i] != 0)
		{elementos_pila ++;}
	}

	if(num > elementos_pila)
	{
		printf("No se pueden eliminar mas elementos de los que hay en la pila.\n Por favor, pruebe con una cantidad distinta.\n");
	}
	else
	{
		// Primero se eliminaran los X primeros numeros del vector
		for(i = 0; i < num; i++)
		{
			printf("Eliminando elemento %d en la posicion %d.\n", vector[i], elementos_pila - posicion);
			vector[i] = 0;
			posicion ++;
		}
		printf("\n");

		// Luego se moveran todos los valores a una posicion X posiciones menor
		for (i = 0; i + num + 1 < TAM; i++)
		{
			vector[i] = vector[i + num];
		}
	
		printf("Se han eliminado con exito los %d primeros elementos de la pila.\n", num);
	}

}

void imprimir_contenido(int vector[])
{
	/* 
	Muestra por pantalla los valores de la pila en el orden en el que están.
	*/
	// Declaracion de variables
	int i;
	
	for(i = 0; i < TAM; i ++)
	{
		printf("Pila[%d]: %d\n", i, vector[i]);
	}
}

void imprimir_contenido_ordenado(int vector[])
{
	/*
	Muestra por pantalla los valores de la pila, ordenados por valor.
	*/
	// Declaracion de variables
	int aux[TAM], i;

	// Inicializacion del vector auxiliar
	for (i = 0; i < TAM; i++)
	{aux[i] = 0;}

	ordenar_vector(vector, TAM, aux);

	imprimir_contenido(aux);

}

void ordenar_vector(int *vec, int size, int *aux)
{
	/* 
	Esta funcion va a usar un vector auxiliar para ordenarlo, y asi obtener fuera de la funcion
	los valores ordenados del vector original, segun el tamaño que se le indique.
	Va a utilizar el algoritmo de ordenacion de la burbuja "mejorado".
	*/
	
	// Declaracion de variables
	int auxiliar, i, j;
	

	// Igualar el vector auxiliar al vector dado
	for (i = 0; i < size; i++)
	{
		aux[i] = vec[i];
	}
	

	// Algoritmo de ordenacion de la burbuja "mejorado"
	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (aux[j] < aux[j - 1])
			{continue;}

			if (aux[j] > aux[j - 1])
			{
				auxiliar = aux[j];
				aux[j] = aux[j - 1];
				aux[j - 1] = auxiliar;
			}		
		}
	}
}

void salir(bool *ejecucion)
{
	/* 
	Esta función cambia el valor del booleano dado a 'false'
	*/
	
	// Modificacion de la variable ejecucion
	*ejecucion = false;
}