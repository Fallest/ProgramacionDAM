#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGCAD 41
#define LONGVOC 6
#define TAM 100

// Prototipado

void mostrar_menu();
void leer_opcion(int *opcion);
void ejecutar_opcion(int opcion, int *opcion_eliminar, int pos, char ini, char cadena[LONGCAD], char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int *cont_cadenas);

// Alta de palabra
void lectura_cadena(char cadena[LONGCAD]);
void registro_cadena(char cadena[LONGCAD], char matriz_cadenas[TAM][LONGCAD], char matris_vocales[TAM][LONGVOC], int *cont_entradas);
void extraer_vocales(char vocales[LONGVOC], char cadena[LONGCAD]);

// Motrar listado de palabras
void mostrar_listado(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC]);
void ordenar_estructura_alfabeto(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC]);

// Eliminar palabra
void leer_opcion_eliminar(int *opcion, int *pos, char *ini);
void eliminar_palabra_posicion(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int pos, int *cont_entradas);
void eliminar_palabra_inicial(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], char ini, int *cont_entradas);

// Contar vocales
void contar_vocales(char matriz_vocales[TAM][LONGVOC]);


//--------------------------------------------------------------------------------- DONE
void main()
{
	/*
	Contiene la llamada a las dem�s funciones.
	*/
	int opcion, opcion_eliminar, pos = 1, cont_entradas = 0, i;
	char ini = 'a', cadena[LONGCAD], matriz_cadenas[TAM][LONGCAD], matriz_vocales[TAM][LONGVOC];

	// Inicializar las matrices
	for (i = 0; i < TAM; i++)
	{
		matriz_cadenas[i][0] = '\0';
		matriz_vocales[i][0] = '\0';
	}
	
	do {
		mostrar_menu();
		leer_opcion(&opcion);
		ejecutar_opcion(opcion, &opcion_eliminar, pos, ini, cadena, matriz_cadenas, matriz_vocales, &cont_entradas);
	} while (opcion != 5);
}
//--------------------------------------------------------------------------------- DONE
void mostrar_menu() 
{
	/*
	Muestra un men� por pantalla. No realiza ninguna otra funci�n.
	*/
	printf("Escoja una opcion: \n");
	printf("-----------------------\n");
	printf("1. Alta de palabra\n");
	printf("2. Listado ordenado\n");
	printf("3. Eliminar palabras\n");
	printf("4. Contar vocales\n");
	printf("5. Salir\n");
	printf("-----------------------\n");

}
//--------------------------------------------------------------------------------- DONE
void leer_opcion(int *opcion)
{
	/*
	Lee la opci�n introducida por teclado y la almacena en una variable dada por referencia.
	*/
	do {
		printf("Introduce una opcion: ");
		scanf("%d", opcion);
		fflush(stdin);
	} while((*opcion <= 0) || (*opcion > 5)); // Control de errores

	printf("\n");
}
//--------------------------------------------------------------------------------- DONE
void ejecutar_opcion(int opcion, int *opcion_eliminar, int pos, char ini, char cadena[LONGCAD], char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int *cont_entradas)
{
	/*
	Recibe la opci�n escogida en el m�todo leer_opcion() y selecciona una funcionalidad
	dependiendo de su valor.
	Recibe todos los argumentos necesarios para ejecutar todas las dem�s funcionalidades.
	*/
	switch(opcion)
	{
	case 1:
		{
			lectura_cadena(cadena);
			registro_cadena(cadena, matriz_cadenas, matriz_vocales, cont_entradas);
			break;
		}
	case 2:
		{
			mostrar_listado(matriz_cadenas, matriz_vocales);
			break;
		}
	case 3:
		{
			leer_opcion_eliminar(opcion_eliminar, &pos, &ini);

			switch(*opcion_eliminar)
			{
			case 1:
				{
					eliminar_palabra_posicion(matriz_cadenas, matriz_vocales, pos, cont_entradas);
					break;
				}
			case 2:
				{
					eliminar_palabra_inicial(matriz_cadenas, matriz_vocales, ini, cont_entradas);
					break;
				}
			}

			break;
		}
	case 4:
		{
			if (*cont_entradas == 0)
			{break;}
			contar_vocales(matriz_vocales);
			break;
		}
	}
}
//--------------------------------------------------------------------------------- DONE
void lectura_cadena(char cadena[LONGCAD])
{
	/*
	Lee la cadena introducida por teclado, con un m�ximo de 40 caracteres.
	*/

	// Pedir que se introduzca la cadena
	printf("Introduzca la cadena (max 40 caracteres): ");
	gets(cadena);
	fflush(stdin);
	// Pasar la cadena a may�sculas.
	strupr(cadena);
	
	printf("\n");
}
//--------------------------------------------------------------------------------- DONE
void registro_cadena(char cadena[LONGCAD], char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int *cont_entradas)
{
	/*
	Crea una entrada en matriz_cadenas con la cadena dada. Se meter� en la estructura de forma
	que quedar� ordenada por longitud de cadena.
	A la vez que se introduce esta cadena, habr� que actualizar de forma paralela la matriz_vocales.

	Primero hay que comprobar que hay espacio para introducir la cadena.
	Luego hay que empezar buscando una cadena en la estructura que tenga una longitud mayor que la que
	vamos a meter.
	Luego, tenemos que desplazar todas las entradas a partir de esa que hemos encontrado una vez
	hacia abajo, para dejar espacio a la nueva entrada.

	Se actualizan las posiciones de matriz_vocales a la vez que las de matriz_cadenas.
	Luego, crea una entrada en matriz_vocales, con la posici�n que tiene la cadena de la cual se
	han extra�do las vocales en matriz_cadenas.
	Es decir:	matriz_cadenas[3] = 'HOLA'
				vocales = 'OA'
				matriz_vocales[3] = 'OA'
	Esto significa que al reorganizar la matriz_cadenas cada vez que se introduzca una nueva cadena,
	habr� que actualizar paralelamente la matriz_vocales.

	Por �ltimo se actualiza la variable cont_entradas, aument�ndola en 1.
	*/
	// Declaraci�n de variables
	int i, j;
	char vocales[LONGVOC];

	// Comprobar que hay espacio suficiente.
	if (*cont_entradas >= TAM)
	{printf("No hay espacio en la matriz. Elimina entradas para poder introducir mas.\n");}
	else
	{
		if ((*cont_entradas) == 0)
		{
			strcpy(matriz_cadenas[0], cadena);
			// Extraemos las vocales de cadena y la introducimos en la misma posici�n
			// pero en la matriz_vocales
			extraer_vocales(vocales, cadena);
			strcpy(matriz_vocales[0], vocales);
			// No nos olvidemos de actualizar la variable cont_entradas
			(*cont_entradas)++;
		}
		else
		{
			// Iteramos en la matriz, buscando una cadena mas larga que la que vamos a introducir
			for (i = 0; i < TAM; i++)
			{
				if (strlen(cadena) < strlen(matriz_cadenas[i]))
				{
					// Cuando la encontramos, sustituimos desde el final hasta la posicion en la
					// que estamos
					for (j = TAM - 1; j > i; j--)
					{
						if (matriz_cadenas[j][0] == '\0')
							continue;
						strcpy(matriz_cadenas[j], matriz_cadenas[j-1]);
						strcpy(matriz_vocales[j], matriz_vocales[j-1]);
					}
					// Introducimos la cadena en la posici�n en la que estamos
					strcpy(matriz_cadenas[i], cadena);
					// Extraemos las vocales de cadena y la introducimos en la misma posici�n
					// pero en la matriz_vocales
					extraer_vocales(vocales, cadena);
					strcpy(matriz_vocales[i], vocales);
					// Salimos del bucle for principal, puesto que ya hemos colocado la cadena
					break;
				}
			}

			// No nos olvidemos de actualizar la variable cont_entradas
			(*cont_entradas)++;
		}
	}
}
//--------------------------------------------------------------------------------- DONE
void extraer_vocales(char vocales[LONGVOC], char cadena[LONGCAD])
{
	/*
	Almacena en 'vocales' las vocales de 'cadena'.

	Hay que iterar sobre la cadena 'cadena', pararse cuando encuentre una vocal,
	y a�adirla a 'vocales'.
	Si la vocal ya est� dentro de 'vocales', no se a�ade. 
	Para comprobar si la vocal ya est� dentro de 'vocales', se itera sobre la cadena
	'vocales', y si alg�n elemento coincide con la vocal, se contin�a con el bucle principal 
	y no se a�ade la vocal a la cadena.
	Para saber si la vocal ya est� o no dentro de la cadena se usar� una variable flag, cuyo valor
	ser� de 0 si la vocal no est�, y de 1 si est�.
	*/
	int i, j, flag = 0, cont = 0;

	// Iteramos sobre 'cadena' para recorrer todos sus caracteres
	for (i = 0; i < LONGCAD; i++)
	{
		// Comprobamos si el caracter en el que nos encontramos es una vocal
		if ((cadena[i] == 'A') || (cadena[i] == 'E') || (cadena[i] == 'I') || (cadena[i] == 'O') || (cadena[i] == 'U'))
		{
			// Ahora vamos a comprobar si en 'vocales' ya est� esa vocal que hemos encontrado
			for (j = 0; j < LONGVOC; j++)
			{
				// Si la vocal ya est� dentro, vamos a levantar una bandera para avisar al resto del programa
				// que no se debe a�adir a 'vocales'
				if (cadena[i] == vocales[j])
				{flag=1;break;}
			}
			
			// Si la bandera no se ha levantado, significa que la vocal que hemos encontrado no est�
			// dentro de 'vocales', asi que la a�adimos en la posicion que indique el contador
			if (flag == 0)
			{
				vocales[cont] = cadena[i];
				cont++;
			}
			// Si se habia levantado la bandera, la bajamos para la siguiente vocal
			flag = 0;
		}
	}
}
//--------------------------------------------------------------------------------- DONE
void mostrar_listado(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC])
{
	/*
	Muestra por pantalla cada entrada de matriz_cadenas, acompa�ada de sus respectivas vocales.
	Va a hacer una iteraci�n hasta TAM, mostrando cada entrada por l�nea, siempre que tenga texto.
	*/ 
	int i;

	for (i = 0; i < TAM; i++)
	{
		//if (matriz_cadenas[i][0] != '\0')
		//{
			printf("%s - %s\n", matriz_cadenas[i], matriz_vocales[i]);
	//	}
	}
}
//--------------------------------------------------------------------------------- DONE
void ordenar_estructura_alfabeto(char matriz[TAM][LONGCAD])
{
	/*
	Ordena la estructura dada alfab�ticamente (por el primer caracter del segundo elemento del
	array).
	Este programa se despreocupa de si la matriz dada es la de cadenas o no, eso se tiene que
	controlar antes de llamar a este m�dulo.

	Para ordenar va a realizar el siguietne algoritmo:
		1. Va a empezar por el primer elemento, coloc�ndose en el primer caracter y us�ndolo como m�nimo.
		2. Va a comenzar una segunda iteraci�n para comparar el primer m�nimo con los siguientes caracteres,
			hasta que encuentre un car�cter menor que el m�nimo que tenemos.
		3. Va a asignar ese nuevo car�cter al m�nimo, y va a cambiarlos de lugar.
		4. Este proceso se va a repetir para todos los elementos de la matriz.

	Por ejemplo, en la lista de numeros [3, 1, 2] har�a lo siguiente:
		1. Almacena 3 como el m�nimo.
		2. Busca un elemento menor que el m�nimo actual.
		3. Lo encuentra en el 1, le asigna el nuevo m�nimo
		4. Los intercambia = [1, 3, 2]
		5. Pasa al siguiente elemento (i=1) que vuelve a ser el tres y lo asigna como m�nimo.
		6. Busca un elemento menor que el m�nimo actual.
		7. Lo encuentra en el 2.
		8. Los intercambia = [1, 2, 3].
		9. Realiza los mismo pasos con el �ltimo elemento pero ya est� ordenado.
	*/
	int i, j, min;
	char cad_aux[LONGCAD];

	// Itera sobre todos los elementos de la matriz.
	for (i = 0; i < TAM; i++)
	{
		min = i;
		for (j = i + 1; j < TAM; j++)
		{
			// Si el primer caracter del elemento i es mayor que el primero del elemento j
			// se intercambian la posici�n
			if (strcmp(matriz[i], matriz[j]) > 0)
			{min = j;}
		}

		// Toma el minimo y el actual y los intercambia con la ayuda de una cadena auxiliar
		strcpy(cad_aux, matriz[i]);
		strcpy(matriz[i], matriz[min]);
		strcpy(matriz[min], cad_aux);
	}
	
}
//--------------------------------------------------------------------------------- DONE
void leer_opcion_eliminar(int *opcion, int *pos, char *ini)
{
	/*
	Lee la opci�n que se escoja para eliminar una entrada tanto de matriz_cadenas como de
	matriz_vocales.
	Las opciones son:	1 - Eliminar por posici�n
						2 - Eliminar por letra inicial (todas las que la tengan)
	Luego pedir� la posici�n (de 1 a 40) o la letra escogida.
	*/

	do {
		printf("Escoja una opcion para eliminar (1 para posicion, 2 para letra inicial): ");
		scanf("%d", opcion);
		fflush(stdin);
	} while((*opcion <= 0) || (*opcion > 2));

	switch (*opcion)
	{
	case 1:
		{
			do {
				printf("Escoja una posicion para eliminar (de 1 a 40): ");
				scanf("%d", pos);
				fflush(stdin);
			} while ((*pos < 1) || (*pos > 40));
			
			break;
		}
	case 2:
		{
			printf("Escoja un caracter para eliminar: ");
			scanf("%c", ini);
			fflush(stdin);
			
			break;
		}
	}
	

}
//--------------------------------------------------------------------------------- DONE
void eliminar_palabra_posicion(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int pos, int *cont_entradas)
{
	/*
	Esta funci�n solo debe ejecutarse si se ha escogido la opci�n 1 en leer_opcion_eliminar.
	Va a buscar una posici�n concreta en la estructura y va a eliminar la entrada tanto en
	matriz_cadenas como en matriz_vocales.
	Luego, va a realocar las entradas que quedan desplazadas.
	La posici�n que se da esta aumentada en uno, por lo que se tendr� que reducir en uno
	para alinearla con el orden de la estructura.
	*/
	int i, j;
	pos--;

	// Itera sobre todos los elementos de la matriz
	for (i = 0; i < TAM; i++)
	{
		// Comprueba si la posici�n actual coincide con la posici�n que buscamos
		if (i == pos)
		{
			// Si coincide, recoloca todos los elementos siguientes a una posici�n menor
			for (j = i; j < (*cont_entradas); j++)
			{

				strcpy(matriz_cadenas[j], matriz_cadenas[j + 1]);
				strcpy(matriz_vocales[j], matriz_vocales[j + 1]);
			}
			// Sale del bucle porque no tiene nada m�s que hacer
			break;
		}
	}
	// Reducir en uno la cantidad de entradas que hay en la matriz
	(*cont_entradas)--;
	
}
//--------------------------------------------------------------------------------- 
void eliminar_palabra_inicial(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], char ini, int *cont_entradas)
{
	/*
	Esta funci�n solo debe ejecutarse si se ha escogido la opci�n 2 en leer_opcion_eliminar.
	Va a iterar sobre la estructura matriz_cadenas, eliminando todas las entradas que empiecen
	por la inicial dada, eliminando a la vez la entrada an�loga en matriz_vocales.
	Luego va a realocar las entradas desplazadas.
	Esta opci�n puede eliminar 0, 1 o varias entradas.
	*/
	int i, j;

	// Itera sobre los elementos de la matriz
	for (i = 0; i < TAM; i++)
	{
		// Comprueba si el primer car�cter de la cadena actual coincide con el car�cter dado
		if (matriz_cadenas[i][0] == ini)
		{
			// Cada vez que se encuentra una inicial que coincide con la dada, ejecuta este bucle
			// Este bucle va a recolocar todos los elementos siguientes a una posici�n menor.
			for (j = i; j < (*cont_entradas); j++)
			{
				strcpy(matriz_cadenas[j], matriz_cadenas[j + 1]);
				strcpy(matriz_vocales[j], matriz_vocales[j + 1]);
			}
			// No nos olvidemos de reducir la cantidad de entradas que hay cada vez que retrasemos
			// todas las dem�s entradas
			(*cont_entradas)--;
		}
	}
}
//--------------------------------------------------------------------------------- DONE R
void contar_vocales(char matriz_vocales[TAM][LONGVOC])
{
	/*
	Va a iterar sobre matriz_vocales, que es donde est�n almacenadas todas las vocales.
	Va a contar las veces que aparece cada vocal, y va a mostrar un listado por pantalla.
	Si una vocal no aparece ninguna vez, no aparecer� en el listado.

	ESTA FUNCI�N EST� COMPLETA.
	EL PROCESO ES MEJORABLE.
	INVESTIGAR.
	*/
	int i, j, contador[5];

	for (i = 0; i < 5; i++)
	{contador[i] = 0;}

	for (i = 0; i < TAM; i++)
	{
		for (j = 0; j < LONGVOC; j++)
		{
			switch(matriz_vocales[i][j])
			{
				case 'A':
					{contador[0]++; break;}
				case 'E':
					{contador[1]++; break;}
				case 'I':
					{contador[2]++; break;}
				case 'O':
					{contador[3]++; break;}
				case 'U':
					{contador[4]++; break;}
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		if (contador[i] != 0)
		{
			switch(contador[i])
				{
					case '0':
						{printf("Vocales A: %d", contador[i]); break;}
					case '1':
						{printf("Vocales E: %d", contador[i]); break;}
					case '2':
						{printf("Vocales I: %d", contador[i]); break;}
					case '3':
						{printf("Vocales O: %d", contador[i]); break;}
					case '4':
						{printf("Vocales U: %d", contador[i]); break;}
				}
		}
	}
}