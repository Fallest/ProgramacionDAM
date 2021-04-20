/*
El programa leera las notas que han obtenido los alumnos
de una clase en un examen de programacion.

El numero de alumnos de la clase es de 15.

Finalmente el programa preguntara al usuario si desea ver
las notas de los aprobados o de los suspensos, y el
programa las imprimira.
*/

#include <stdio.h>

#define TAM 2

void main()
{
	int notas[TAM];
	char opcion;

	// Lectura de las notas de los alumnos:
	for (int i = 0; i < TAM; i++)
	{
		do{
			printf("Introduce la nota del alumno %d: ", i + 1);
			scanf("%d", &notas[i]);
			fflush(stdin);
		}while(notas[i] < 0 || notas[i] > 10);
	}

	// Preguntamos que notas desea ver:
	do{
		printf("Indique si desea ver las notas de los aprobados o de los suspensos (a/s): ");
		scanf("%c", &opcion);
		fflush(stdin);
	}while(opcion != 'a' && opcion != 's');

	// Mostramos las notas del subgrupo elegido:
	printf("\nNotas del subgrupo elegido: ");
	
	for (int j = 0; j < TAM; j++)
	{
		if ((opcion == 'a' && notas[j] >= 5) ||
			(opcion == 's' && notas[j] < 5))
			printf("%d ", notas[j]);
	}
	printf("\n\n");
}
