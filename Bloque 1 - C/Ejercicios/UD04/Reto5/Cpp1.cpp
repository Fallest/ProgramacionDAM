#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

/*
SE SUPONE ENTRADA CORRECTA DE DATOS

Son necesarios los siguientes tipos de datos:
	-Un registro que contenga los datos del curso:
		·Código numérico:		int
		·Descripción:			char [30]
		·Lugar de realización:	enum lugar_realizacion
		·Número de plazas:		int
		·Fecha de comienzo:		struct fecha
	-Un registro para los tipo fecha:
		·Día:	int
		·Mes:	int
		·Anyo:	int
	-Un enum para el lugar de realización:
		·Sevilla = 0
		·Malaga = 1
		·Cordoba = 2
*/
/*------------------------------------------------*/
enum Lugar_realizacion {Sevilla = 1, Malaga, Cordoba};
/*------------------------------------------------*/
struct Fecha {
	int dia, mes, anyo;
};
/*------------------------------------------------*/
struct Curso {
	int cod_curso;
	char descripcion[31];
	enum Lugar_realizacion lugar;
	int num_plazas;
	int matriculados;
	struct Fecha fecha_ini;
};
/*------------------------------------------------*/

/*
Funciones necesarias:
void mostrar_menu():
	Muestra el menú para elegir qué hacer. Las funciones son las siguientes:
		-Alta de curso.
		-Modificación de cursos.
		-Baja de cursos.
		-Matrícula.
		-Listado de cursos.
		-Salir.

void lectura_opcion(int *opcion):
	Lee por teclado la opcion a ejectuar.

void ejecutar_opcion(int opcion):
	Ejecuta la opcion seleccionada.

void alta_curso(struct Curso cursos[]):
	Crea una entrada de un curso en el vector de Cursos.
	Pide al usuario los datos del curso y los introduce.
	Debe controlar que no existe otro curso con el mismo código.
	Si existe otro curso con el mismo código, devolverá un error y 
	nos devolverá al menú principal.

void mod_curso(struct Curso cursos[]):
	Modifica los datos de un curso concreto. Se accederá al curso a modificar 
	mediante el código. Se preguntará qué dato se quiere modificar, hasta que ya
	no se quiera modificar ninguno. Si se quiere modificar el código del curso,
	se deberá controlar que no se repite, y también deberá controlarse que el nº de
	plazas no sea menor que el de alumnos ya matriculados.
	En el caso de que se produzca cualquiera de dichos errores se devolverá un error y
	nos devolverá al menú de elección de dato a modificar.

void baja_curso(struct Curso cursos[]):
	Retira una entrada de un curso en el vector de cursos.
	Se retira un curso usando su código, la función lo pide al usuario.
	Sin embargo, si el curso ya tiene a algún alumno matriculado,
	no se podrá eliminar, mostrará un error y nos devolverá al menú inicial.

void matricula(struct Curso cursos[]):
	Pide al usuario un códig de curso para matricular al alumno.
	Usando el código de un curso y comprobando que tenga plazas suficientes, simplemente
	se incrementa en uno el número de matriculados y se quita una plaza.

void listado(struct Curso cursos[]):
	Muestra por pantalla el vector de Cursos, ordenados por código, mostrando la descripción
	y el número de plazas vacantes.
*/

// Prototipado
/* Main */
void mostrar_menu();
void leer_opcion(int *opcion);
void ejecutar_opcion(int opcion, struct Curso *cursos);
/* Funciones del menú */
void alta_curso(struct Curso *cursos);
void mod_curso(struct Curso *cursos);
void baja_curso(struct Curso *cursos);
void matricula(struct Curso *cursos);
void listado(struct Curso *cursos);

void main () 
{
	int i, opcion = 1;
	struct Curso cursos[TAM];

	for (i = 0; i < TAM; i++)
	{cursos[i].cod_curso = 0; cursos[i].matriculados = 0;}

	do {
		mostrar_menu();
		leer_opcion(&opcion);
		ejecutar_opcion(opcion, cursos);
	} while (opcion != 6);
}

/*------------------------------------------------*/ //DONE
void mostrar_menu() 
{
	printf("-------------\n");
	printf("1. Alta de curso\n");
	printf("2. Modificacion de curso\n");
	printf("3. Baja de curso\n");
	printf("4. Matricula\n");
	printf("5. Listado de cursos\n");
	printf("6. Salir\n");
	printf("-------------\n");
}

/*------------------------------------------------*/ //DONE
void leer_opcion(int *opcion) 
{
	do {
		printf("Escoja una opcion: ");
		scanf("%d", opcion);
		fflush(stdin);
	} while ((*opcion < 1) || (*opcion > 6));
}

/*------------------------------------------------*/ //DONE
void ejecutar_opcion(int opcion, struct Curso *cursos) 
{
	switch (opcion) 
	{
		case 1:
		{
			alta_curso(cursos);
			break;
		}
		case 2:
		{
			mod_curso(cursos);
			break;
		}
		case 3:
		{
			baja_curso(cursos);
			break;
		}
		case 4:
		{
			matricula(cursos);
			break;
		}
		case 5:
		{
			listado(cursos);
			break;
		}
	}
}

/*------------------------------------------------*/ // DONE
void alta_curso(struct Curso *cursos)
{
	int i, j, flag = 1;

	for (i = 0; i < TAM; i++)
	{
		if (cursos[i].cod_curso == 0)
		{
			do {
				flag = 0;
				printf("Introduzca el codigo del curso: ");
				scanf("%d", &cursos[i].cod_curso);
				fflush(stdin);

				for (j = 0; j < TAM; j++)
				{
					if ((cursos[i].cod_curso == cursos[j].cod_curso) && (j != i))
					{flag = 1;}
				}
			} while(flag == 1);

			printf("Introduzca una descripcion para el curso: ");
			gets(cursos[i].descripcion);
			fflush(stdin);

			printf("Introduzca el lugar de realizacion \n");
			printf("(1 = Sevilla, 2 = Malaga, 3 = Cordoba): ");
			scanf("%u", &cursos[i].lugar);
			fflush(stdin);

			printf("Introduzca el numero de plazas disponibles: ");
			scanf("%d", &cursos[i].num_plazas);
			fflush(stdin);

			printf("Introduzca la fecha de comienzo: \n");
			printf("Introduzca el dia: ");
			scanf("%d", &cursos[i].fecha_ini.dia);
			fflush(stdin);
			printf("Introduzca el mes: ");
			scanf("%d", &cursos[i].fecha_ini.mes);
			fflush(stdin);
			printf("Introduzca el anyo: ");
			scanf("%d", &cursos[i].fecha_ini.anyo);
			fflush(stdin);

			break;
		}
		if (i == 9)
		{printf("No hay mas espacio para cursos. Elimina alguno para poder introducir mas. \n");}
	}
}

/*------------------------------------------------*/ //DONE
void mod_curso(struct Curso *cursos)
{
	int i, opc_mod = 1, flag, cod = 0,ind = 0;

	// Primero hay que mostrar el listado para escoger el curso que vamos a modificar
	listado(cursos);

	// El usuario escoge un curso mediante el código de dicho curso
	printf("Escoja un curso (introduzca el codigo): ");
	scanf("%d", &cod);
	fflush(stdin);
	
	// Buscamos su índice y lo almacenamos para usarlo en el resto de la función
	for (i = 0; i < TAM; i++)
	{
		if (cursos[i].cod_curso == cod)
		{ind = i; break;}
	}
	
	do {
		// Mostramos un pequeño menú
		printf("-------------\n");
		printf("1. Codigo del curso\n");
		printf("2. Descripcion\n");
		printf("3. Lugar\n");
		printf("4. Numero de plazas\n");
		printf("5. Matriculaciones\n");
		printf("6. Fecha\n");
		printf("7. Salir\n");
		printf("-------------\n");

		// Leemos la opción a escoger
		printf("Escoja una opcion: ");
		scanf("%d", &opc_mod);
		fflush(stdin);

		// Ejecutamos la opción escogida
		switch (opc_mod)
		{
			case 1:
			{
				flag = 1;
				do {
					flag = 0;
					printf("Introduzca el nuevo codigo del curso: ");
					scanf("%d", &cursos[ind].cod_curso);
					fflush(stdin);

					for (i = 0; i < TAM; i++)
					{
						if (cursos[ind].cod_curso == cursos[i].cod_curso)
						{flag = 1;}
					}
				} while(flag == 1);

				break;
			}

			case 2:
			{
				printf("Introduzca una nueva descripcion para el curso: ");
				gets(cursos[ind].descripcion);
				fflush(stdin);
				break;
			}

			case 3:
			{
				printf("Introduzca el nuevo lugar de realizacion \n");
				printf("(1 = Sevilla, 2 = Malaga, 3 = Cordoba): ");
				scanf("%u", &cursos[ind].lugar);
				fflush(stdin);
				break;
			}

			case 4:
			{
				flag = 1;
				do {
					flag = 0;
					printf("Introduzca el nuevo numero de plazas disponibles: ");
					scanf("%d", &cursos[ind].num_plazas);
					fflush(stdin);

					if (cursos[ind].num_plazas < cursos[ind].matriculados)
					{flag = 1;}
				} while (flag == 1);
				break;
			}

			case 5:
			{
				printf("Introduzca el numero de alumnos matriculados: ");
				scanf("%d", &cursos[ind].matriculados);
				fflush(stdin);
				break;
			}

			case 6:
			{
				printf("Introduzca la nueva fecha de comienzo: \n");
				printf("Introduzca el dia: ");
				scanf("%d", &cursos[i].fecha_ini.dia);
				fflush(stdin);
				printf("Introduzca el mes: ");
				scanf("%d", &cursos[i].fecha_ini.mes);
				fflush(stdin);
				printf("Introduzca el anyo: ");
				scanf("%d", &cursos[i].fecha_ini.anyo);
				fflush(stdin);
				break;
			}
		}
	} while (opc_mod != 7);
}

/*------------------------------------------------*/ // DONE
void baja_curso(struct Curso *cursos)
{
	int i, j, cod = 0, ind = 0;

	// Primero hay que mostrar el listado para escoger el curso que vamos a eliminar
	listado(cursos);

	// El usuario escoge un curso mediante el código de dicho curso
	printf("Escoja un curso (introduzca el codigo): ");
	scanf("%d", &cod);
	fflush(stdin);
	
	// Buscamos su índice y lo almacenamos para usarlo en el resto de la función
	for (i = 0; i < TAM; i++)
	{
		if (cursos[i].cod_curso == cod)
		{ind = i; break;}
	}

	// Cmoprobar si tiene alumnos matriculados
	if (cursos[ind].matriculados != 0)
	{printf("Error: No se puede dar de baja un curso que ya tiene alumnos matriculados.\n");}
	else 
	{
		for (i = 0; i < TAM; i++)
		{
			if (i == ind)
			{
				for (j = i; j < TAM; j++)
				{
					if (j != 9)
					{cursos[j] = cursos[j+1];}
					else
					{cursos[j].cod_curso = 0;}
				}
			}
		}
	}
}

/*------------------------------------------------*/
void matricula(struct Curso *cursos)
{
	int i, cod = 0, ind = 0;

	// Primero hay que mostrar el listado para escoger el curso que vamos a eliminar
	listado(cursos);

	// El usuario escoge un curso mediante el código de dicho curso
	printf("Escoja un curso (introduzca el codigo): ");
	scanf("%d", &cod);
	fflush(stdin);
	
	// Buscamos su índice y lo almacenamos para usarlo en el resto de la función
	for (i = 0; i < TAM; i++)
	{
		if (cursos[i].cod_curso == cod)
		{ind = i; break;}
	}

	// Comprobar si hay plazas en el curso
	if (cursos[ind].num_plazas == 0)
	{printf("No quedan plazas para este curso.\n");}
	else
	{
		cursos[ind].matriculados++;
		printf("Se ha matriculado al alumno.\n");
	}
}

/*------------------------------------------------*/
void listado(struct Curso *cursos)
{
	int i;
	
	for (i = 0; i < TAM; i++)
	{
		if (cursos[i].cod_curso != 0)
		{
			printf("\n");
			printf("Codigo del curso: %d\n %s\n %d/%d/%d - Plazas: %d\n", cursos[i].cod_curso,
				cursos[i].descripcion, cursos[i].fecha_ini.dia, cursos[i].fecha_ini.mes, 
				cursos[i].fecha_ini.anyo, cursos[i].num_plazas);
			printf("---------------------\n");
		}
	}
}

/*------------------------------------------------*/