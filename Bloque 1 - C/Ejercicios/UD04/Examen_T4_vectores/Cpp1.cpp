#include <stdio.h>
#include <stdlib.h>

#define ALUM 30

// Prototipado de funciones
void actualizar_nota(int notas_alumnos[], int nota, int alumno);
void mostrar_nota(int notas_alumnos[], int alumno);
void mostrar_estadisticas(int notas_alumnos[]);
void mostrar_listado(int notas_alumnos[], bool criterio);


void main()
{
	/* 
	En esta función se encuentra el bucle de ejecucion.
	Se va a usar un switch para el funcionamiento del menu de opciones.
	*/
	// Declaracion de variables
	// notas_alumnos es el vector con las notas de los alumnos.
	// un alumno que no se ha presentado tendrá un -1
	// un alumno que no ha sido registrado es representado con un -2
	int notas_alumnos[ALUM], opcion, i;
	int alumno = 0, nota;
	char criterio = 't';

	// Inicializacion del vector notas_alumnos a -2 (nadie registrado)
	for (i = 0; i < ALUM; i++)
	{notas_alumnos[i] = -2;}

	// Bucle de ejecucion
	do {
		printf("GESTOR DE NOTAS");
		printf("---------------\n");
		printf("1. Actualizar nota de un alumno\n");
		printf("2. Mostrar la nota de un alumno\n");
		printf("3. Mostrar estadisticas generales\n");
		printf("4. Mostrar el listado de alumnos\n");
		printf("0. Salir\n");
		printf("------------------------------------\n");
		printf("Escoja una opcion: ");
		scanf("%d", &opcion);
		fflush(stdin);
		
		switch(opcion)
		{
		case 1:
			{
				// Actualizar nota
				printf("Que alumno quiere modificar (de 0 a 29)?: \n");
				scanf("%d", &alumno);
				fflush(stdin);
				printf("Que nota quiere ponerle (-1 para no presentado): \n");
				scanf("%d", &nota);
				fflush(stdin);

				actualizar_nota(notas_alumnos, nota, alumno);
				break;
			}
		case 2:
			{
				// Mostrar nota de alumno
				printf("Que alumno quiere consultar (de 0 a 29)?: \n");
				scanf("%d", &alumno);
				fflush(stdin);

				mostrar_nota(notas_alumnos, alumno);
				break;
			}
		case 3:
			{
				// Mostrar estadisticas
				printf("Estas son las estadisticas generales:\n");
				printf("-------------------------------------\n");
				mostrar_estadisticas(notas_alumnos);
				break;
			}
		case 4:
			{
				// Mostrar listado
				printf("Para consultar todos los alumnos escriba 't'.\n");
				printf("Para consultar solo los alumnos que tengan una nota, escriba 'n'.\n");
				scanf("%c", &criterio);
				fflush(stdin);

				// Depende del criterio, se llama a la funcion del listado con diferentes parametros
				switch(criterio)
				{
				case 't':
				case 'T':
					{
						mostrar_listado(notas_alumnos, true);
						break;
					}
				case 'n':
				case 'N':
					{
						mostrar_listado(notas_alumnos, false);
						break;
					}
				default:
					{
						printf("Ha ocurrido un error. Por favor, escoja una opcion valida.\n");
						break;
					}
				}

				break;
			}
		case 0:
			{
				printf("Saliendo...\n");
				break;
			}

		default:
			{
				printf("Ha ocurrido un error. Por favor, escoja una opcion valida.\n");
				break;
			}
		}
	}
	while(opcion != 0);
}

void actualizar_nota(int notas_alumnos[], int nota, int alumno)
{
	/* 
	Esta funcion va a buscar una posicion concreta del vector de notas, y va a sustituir
	el valor de esa posicion
	*/
	int i = 0;

	// Comprobar que no se ha dado la posicion de un alumno superior al tamaño del vector
	if ((alumno >= ALUM) || (alumno < 0))
	{printf("Ha ocurrido un error. Por favor, de una posicion de alumno valida.\n");}
	if ((nota > 10 ) || (nota < -2))
	{printf("Ha ocurrido un error. Por favor, de una nota valida.\n");}

	else
	{
		// Bucle para recorrer el vector
		for(i = 0; i < ALUM; i ++)
		{
			if(alumno == i)
			{
				printf("Se ha actualizado la nota del alumno %d a %d.\n", alumno, nota);
				notas_alumnos[i] = nota;
				break;
			}
		}
	}
	printf("\n");

}

void mostrar_nota(int notas_alumnos[], int alumno)
{
	/*
	Esta función va a mostrar por pantalla la nota de un alumno concreto, cuya posicion
	va a ser dada en los parametros
	*/
	// Declaracion de variables
	int i;

	// Comprobar que no se ha dado la posicion de un alumno superior al tamaño del vector
	if ((alumno >= ALUM) || (alumno < 0))
	{printf("Ha ocurrido un error. Por favor, de una posicion de alumno valida.\n");}

	else
	{
		// Bucle para recorrer el vector
		for(i = 0; i < ALUM; i++)
		{
			if((alumno == i))
			{
				switch(notas_alumnos[i])
				{
				case -1:
					{printf("El alumno no se ha presentado.\n"); break;}
				case -2:
					{printf("No hay ningun alumno registrado en esa posicion.\n"); break;}
				default:
					{printf("La nota del alumno %d es: %d\n", alumno, notas_alumnos[i]); break;}
				}
				break;
			}
		}
	}
	printf("\n");
}

void mostrar_estadisticas(int notas_alumnos[])
{
	/*
	Esta función va a mostrar las siguientes estadisticas sobre el vector dado:
		-Cuantas posiciones tienen el valor -1 (no presentado)
		-Cuantas posiciones tienen el valor -2 (no registrado)
		-Cuantas posiciones tienen un valor igual o superior a 5 (aprobado)
	*/
	// Declaracion de variables
	int no_presentado = 0, no_datos = 0, aprobados = 0, i;

	// Bucle para recorrer el vector
	for (i = 0; i < ALUM; i++)
	{
		// Usamos el switch de la funcion anterior modificado
		switch(notas_alumnos[i])
		{
		case -1:
			{no_presentado++; break;}
		case -2:
			{no_datos++; break;}
		default:
			{
				// Debemos comprobar si la nota es mayor o igual a 5
				if(notas_alumnos[i] >= 5)
				{aprobados++;}
				break;
			}
		}
	}

	// Salida por pantalla
	printf("Alumnos aprobados: %d\n", aprobados);
	printf("Alumnos no presentados: %d\n", no_presentado);
	printf("Alumnos no registrados: %d\n", no_datos);
	printf("\n");
}

void mostrar_listado(int notas_alumnos[], bool criterio)
{
	/* 
	Esta función va a mostrar las notas de todos los alumnos o solo las de los que tengan
	una nota real (es decir, solo se mostraran las notas de los alumnos registrados y que
	se han presentado).

	Para distinguir cual de las opciones se va a ejecutar, se usara el bool del parametro.
	Si es true, se mostraran los datos de todos los alumnos.
	Si es false, solo se mostraran los datos de los que tengan nota.

	En el caso de que se muestren todos los datos, se mostraran primero los alumnos que se
	hayan presentado y esten aprobados; 
	luego los alumnos que se hayan presentado pero no hayan aprobado; 
	luego los alumnos que no se hayan presentado pero esten registrados;
	y finalmente se mostraran los no registrados.
	
	En el caso de mostrarse solo los que tengan nota, se mostraran los alumnos ordenados
	de mayor a menor por nota.
	*/

	switch(criterio)
	{
	// Mostrar todas las notas
	case true:
		{
			int i;
			// Primero, hay que mostrar por pantalla los que esten aprobados
			printf("Alumnos aprobados:\n");
			for (i = 0; i < ALUM; i ++)
			{
				if(notas_alumnos[i] >= 5)
				{printf("Alumno %d: %d\n", i, notas_alumnos[i]);}
			}

			// Segundo los alumnos suspensos
			printf("--------------------\n");
			printf("Alumnos suspensos:\n");
			for (i = 0; i < ALUM; i ++)
			{
				if((notas_alumnos[i] < 5) && (notas_alumnos[i] >= 0))
				{printf("Alumno %d: %d \n", i, notas_alumnos[i]);}
			}

			// Tercero los alumnos registrados y no presentados (-1)
			printf("--------------------\n");
			printf("Alumnos no presentados:\n");
			for (i = 0; i < ALUM; i ++)
			{
				if(notas_alumnos[i] == -1)
				{printf("Alumno %d: No presentado\n", i);}
			}

			// Por ultimo, los alumnos no registrados (-2)
			printf("--------------------\n");
			printf("Alumnos no registrados:\n");
			for (i = 0; i < ALUM; i ++)
			{
				if(notas_alumnos[i] == -2)
				{printf("Alumno %d: No registrado\n", i);}
			}
			break;
		}
	// Mostrar las notas de los alumnos registrados y que se hayan presentado
	case false:
		{
			/* 
			Crear un vector auxiliar_notas[ALUM], que en un principio va a tener las
			notas de los alumnos que tengan nota en su orden original.
			Crear otro vector auxiliar_posiciones[ALUM], que va a almacenar en su posicion
			la posicion de un elemento auxiliar_notas[i] una vez haya sido recolocado 
			(es decir, van a compartir la misma posicion), y en su valor va a almacenar
			la posicion original.
			Es decir: un elemento notas_alumnos[12] = 9 va a resultar en:
				-auxiliar_notas[0] = 9	<--- Nota del alumno 12, el que tiene la nota mas alta
				-auxiliar_posiciones[0] = 12 <--- Posicion original de alumno doce
			*/
			int auxiliar_notas[ALUM], auxiliar_posiciones[ALUM];
			int i, j, aux;

			// Primero hay que copiar los datos al auxiliar_notas e inicializar el auxiliar_posiciones
			for(i = 0; i < ALUM; i++)
			{
				auxiliar_notas[i] = notas_alumnos[i];
				auxiliar_posiciones[i] = 0;
			}

			// Luego hay que ordenarlo por valor, almacenando la posicion en el otro auxiliar
			for (i = 0; i < ALUM; i++)
			{
				for (j = ALUM - 1; j > i; j--)
				{
					if ((auxiliar_notas[j] > auxiliar_notas[j - 1]) || (auxiliar_notas[j] == -2)
						|| (auxiliar_notas[j] == -1))
					{continue;}
					

					if (auxiliar_notas[j] < auxiliar_notas[j - 1])
					{
						auxiliar_posiciones[j] = j;
						aux = auxiliar_notas[j];
						auxiliar_notas[j] = auxiliar_notas[j - 1];
						auxiliar_notas[j - 1] = aux;
					}		
				}
			}

			// Mostramos los datos
			printf("Alumnos con nota: \n");

			for(i = 0; i < ALUM; i ++)
			{
				if ((auxiliar_notas[i] == -2) || (auxiliar_notas[i] == -1))
				{continue;}
				printf("Alumno %d: %d\n", auxiliar_posiciones[i], auxiliar_notas[i]);
			}
			break;
		}
	}
	printf("\n");

}

