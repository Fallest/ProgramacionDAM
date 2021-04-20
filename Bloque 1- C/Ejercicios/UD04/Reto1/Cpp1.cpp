#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define RAND_MAX 100

// Prototipado
void rellenar_vector(int vec[], int llamado);
void calcular_medias(int vec[]);
void almacenar_extremos(int vec[]);
void ordenar_vector(int vec[], int size, bool salida);
void salir(bool *ejecucion, int op_realizadas[]);

void main()
{
	/* 
	Esta funcion muestra un menu, seleccionable con numeros, que permitira
	elegir cual de las otras 5 funciones se ejecutara. Solo se saldra del programa
	al escoger la opcion 5 (salir).
	*/

	// Declaracion de variables
	/* 
	El array op_realizadas[4] es un array de enteros, cuyos elementos van a 
	servir de contadores para saber cuantas veces se ha ejecutado cada opcion.
	Respectivamente: op_realizadas[0] -> opcion 1
					 op_realizadas[1] -> opcion 2
					 op_realizadas[2] -> opcion 3
					 op_realizadas[3] -> opcion 4
	El booleano ejecucion es una variable interruptor para salir del programa.
	Sera true mientras el programa vaya a seguir funcionando, y solo cambiara
	su valor la funcion salir().
	*/
	
	int opcion;
	int op_realizadas[4], vector[TAM];
	bool ejecucion = true;

	op_realizadas[0] = 0;
	op_realizadas[1] = 0;
	op_realizadas[2] = 0;
	op_realizadas[3] = 0;

	// Lectura de datos
	do {
		printf("1. Rellenar vector\n");
		printf("2. Calcular medias\n");
		printf("3. Almacenar extremos\n");
		printf("4. Ordenar vector\n");
		printf("5. Salir\n");

		scanf("%d", &opcion);
		fflush(stdin);

		// Manejo de casos con un switch
		// En todos se aumenta el contador interno del vector op_realizadas.
		switch (opcion)
		{
			case 1:
			{
				rellenar_vector(vector, op_realizadas[0]);
				op_realizadas[0] ++;
				break;
			}
			case 2:
			{
				calcular_medias(vector);
				op_realizadas[1] ++;
				break;
			}
			case 3:
			{
				almacenar_extremos(vector);
				op_realizadas[2] ++;
				break;
			}
			case 4:
			{
				ordenar_vector(vector, TAM, true);
				op_realizadas[3] ++;
				break;
			}
			case 5:
			{
				salir(&ejecucion, op_realizadas);
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

void rellenar_vector(int *vec, int llamado)
{
	/* 
	Este vector genera numeros enteros aleatorios y los introduce en el vector
	dado. Genera numeros entre el 10 y el 100.
	*/
	// Inicializacion del generador. SOLO LLAMAR UNA VEZ
	if (llamado = 0)
	{srand(time(NULL));}

	// Declaracion de variables
	int num, i;

	// Generacion e introduccion de numeros en el vector
	for (i = 0; i < TAM; i++)
	{
		num = rand();
		if ((num >= 10) && (num <= 100))
		{vec[i] = num;}		
		else { i --;}
	}

	// Mostrar por pantalla los valores del vector
	printf("Se ha generado el siguiente vector:\n");
	for (i = 0; i < TAM; i++)
	{
		printf("%d ", vec[i]);
	}
	printf("\n");	
}

void calcular_medias(int *vec)
{
	/* 
	Esta funcion calcula la media de los valores pares e impares del vector 
	y muestra por pantalla la decena mas cercana a esa media.
	Tambien cuenta el numero de valores pares e impares y las muestra por
	pantalla.
	Si cualquiera de estas dos cantidades resultara ser 0, mostrara un error por
	pantalla, indicando que no se puede calcular la media.
	*/

	// Declaracion de variables
	/* 
	Los valores de paridad y los de las sumas_totales se inicializan a 0
	para evitar errores.
	Los primeros elementos de cada vector son los referentes a los pares.
	*/
	int dec_cercana[2], sumas_totales[2], medias[2], paridad[2], i;
	
	sumas_totales[0] = 0;
	sumas_totales[1] = 0;
	paridad[0] = 0;
	paridad[1] = 0;
	
	// Acceso a los elementos individuales del vector
	for (i = 0; i < TAM; i++)
	{
		// Discriminar entre pares e impares para contarlos y sumarlos.
		if (vec[i] % 2 == 0) 
		{
			sumas_totales[0] = sumas_totales[0] + vec[i];
			paridad[0] ++;
		}
		else
		{
			sumas_totales[1] = sumas_totales[1] + vec[i];
			paridad[1] ++;
		}
	}

	// Calculo de las medias
	medias[0] = sumas_totales[0] / paridad[0]; // Media de pares
	medias[1] = sumas_totales[1] / paridad[1]; // Media de impares


	// Calculo de la decena mas cercana a la media
	dec_cercana[0] = ((medias[0] / 10) * 10); // Aproximacion de la media de pares
	dec_cercana[1] = ((medias[1] / 10) * 10); // Aproximacion de la media de impares


	// Salida por pantalla de datos

	// Manejo de excepciones
	if ((paridad[0] != 0) && (paridad[1] != 0))
	{
		printf("Nº de valores pares: %d - Media de los valores pares: Aproximadamente %d.\n",
			paridad[0], dec_cercana[0]);
		printf("Nº de valores impares: %d - Media de los valores impares: Aproximadamente %d.\n",
			paridad[1], dec_cercana[1]);
	}
	// Si no hay pares
	if (paridad[0] == 0)
	{
		printf("Nº de valores pares: %d - No se puede calcular la media.\n",
			paridad[0]);
		printf("Nº de valores impares: %d - Media de los valores impares: Aproximadamente %d.\n",
			paridad[1], dec_cercana[1]);
	}
	// Si no hay impares
	if (paridad[0] == 0)
	{
		printf("Nº de valores pares: %d - Media de los valores impares: Aproximadamente %d.\n",
			paridad[0], dec_cercana[0]);
		printf("Nº de valores impares: %d - No se puede calcular la media.\n",
			paridad[1]);
	}
}

void almacenar_extremos(int *vec)
{
	/* 
	Esta funcion extrae los dos valores mas bajos y los dos mas altos del vector
	y los añade a un vector auxiliar, que luego mostrara por pantalla.
	*/

	// Declaracion de variables
	/* 
	Se usara un vector auxiliar del mismo tamaño que el vector dado.
	Este vector auxiliar se ordenara y se escogeran los dos primeros y los dos
	ultimos elementos.
	*/
	int extremos[4], auxiliar[TAM], i;

	// Igualar el vector auxiliar al original
	for (i = 0; i < TAM; i++)
	{auxiliar[i] = vec[i];}
	
	// Ordenar el vector auxiliar
	ordenar_vector(auxiliar, TAM, false);
	
	// Extraccion de los extremos y añadido al vector extremos
	for (i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			// Escoge los valores ultimo y primero, y avanza hacia el centro con cada uno
			extremos[i] = auxiliar[i];
			extremos[3 - i] = auxiliar[(TAM - 1) - i];
		}
		else {break;}
	}
	
	// Salida por pantalla de datos
	printf("Valores extremos: ");
	for (i = 0; i < 4; i++)
	{printf("%d ", extremos[i]);}
	printf("\n");
}

void ordenar_vector(int *vec, int size, bool salida)
{
	/* 
	Esta funcion va a ordenar en orden ascendente el vector que reciba como
	parametro, segun el tamaño que se le indique.
	Va a utilizar el algoritmo de ordenacion de la burbuja "mejorado".
	*/
	
	// Declaracion de variables
	int aux, i, j;

	// Algoritmo de ordenacion de la burbuja "mejorado"
	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (vec[j] > vec[j - 1])
			{continue;}

			if (vec[j] < vec[j - 1])
			{
				aux = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = aux;
			}		
		}
	}

	// Salida por pantalla del vector ordenado
	if(salida)
	{
		printf("Vector ordenado: ");
		for (i = 0; i < size; i++)
		{printf("%d ", vec[i]);}
		printf("\n");
	}
}

void salir(bool *ejecucion, int op_realizadas[])
{
	/* 
	Esta funcion muestra por pantalla cuantas veces se ha realizado
	cada una de las opciones, y luego sale del programa.
	*/
	
	// Declaracion de variables
	int i;

	// Recorrido por el vector op_realizadas
	for (i = 0; i < 4; i++)
	{printf("Opcion %d: %d veces.\n", i, op_realizadas[i]);}

	// Modificacion de la variable ejecucion y salida
	*ejecucion = false;
}