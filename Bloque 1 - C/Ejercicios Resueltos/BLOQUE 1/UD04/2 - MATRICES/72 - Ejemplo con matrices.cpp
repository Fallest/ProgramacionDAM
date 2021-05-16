/*
Se van a registrar las notas de los alumnos de una clase en dos examenes.
El programa hará:
- Rellenar la matriz.
- Buscar la nota de un alumno en un examen concreto e indicar su equivalente
textual.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NALUMNOS 3
#define NEXAMENES 2


void rellenar_matriz (int m[NALUMNOS][NEXAMENES])
{
	srand(time(NULL));

	for (int i = 0; i < NALUMNOS; i++)
		for (int j = 0; j < NEXAMENES; j++)
			m[i][j] = rand() % 11;
}


void imprimir_matriz (int m[NALUMNOS][NEXAMENES])
{
	for (int i = 0; i < NALUMNOS; i++)
	{
		for (int j = 0; j < NEXAMENES; j++)
			printf("%d ", m[i][j]);

		printf("\n");
	}
}


int pedir_numero_alumno()
{
	int alumno;

	do{
		printf("\nIntroduzca el numero de alumno (de 1 a %d): ", NALUMNOS);
		scanf("%d", &alumno);
		fflush(stdin);
	}while(alumno <= 0 || alumno > NALUMNOS);

	return alumno;
}


int pedir_numero_examen()
{
	int examen;

	do{
		printf("\nIntroduzca el numero de examen (de 1 a %d): ", NEXAMENES);
		scanf("%d", &examen);
		fflush(stdin);
	}while(examen <= 0 || examen > NEXAMENES);

	return examen;
}


void imprimir_calificacion (int nota)
{
  switch (nota)
  {
    case 0: 
    case 1: 
    case 2: printf("La nota es MUY DEFICIENTE.\n");
		    break;
    case 3: 
    case 4: printf("La nota es INSUFICIENTE.\n");
		    break;
    case 5: printf("La nota es SUFICIENTE.\n");
		    break;
    case 6: printf("La nota es BIEN.\n");
		    break;
    case 7: 
    case 8: printf("La nota es NOTABLE.\n");
		    break;
    case 9: printf("La nota es SOBRESALIENTE.\n");
		    break;
    case 10: printf("La nota es MATRICULA DE HONOR.\n");
		     break;
  }
}


void main()
{
	int notas[NALUMNOS][NEXAMENES];
	int alumno, examen;

	rellenar_matriz (notas);

	// CONTROL (eliminar cuando se efectuen pruebas):
	imprimir_matriz (notas);

	alumno = pedir_numero_alumno();
	examen = pedir_numero_examen();

	imprimir_calificacion (notas[alumno-1][examen-1]);
}
