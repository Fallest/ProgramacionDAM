#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximo de 10 anunciantes y 30 anuncios por anunciante
#define ANUNCIANTES 10
#define ANUNCIOS 30

// Prototipado

void registrar_anunciante(char anunciantes[ANUNCIANTES][6]);
void ordenar_alfabeticamente(char matriz[ANUNCIANTES][6]);
void registrar_anuncio(char anunciantes[ANUNCIANTES][6], int auncios[ANUNCIOS][3]);
void estadisticas_anunciantes(char anunciantes[ANUNCIANTES][6], int anuncios[ANUNCIOS][3]);

void main()
{
	/* 
	Esta funcion va a tener el bucle de ejecucion del programa, incluyendo
	el menu para la gestion de datos. 
	En ella van a estar las matrices que se van a usar en las operaciones de 
	las demas funciones
	*/
	// Declaracion de variables y arrays
	/* 
	anunciantes es un array que en cada una de sus filas tiene a un anunciante 
	diferente, por lo que anunciantes[i][0] es la primera letra de cada nombre.
	*/
	int i, j;
	char anunciantes[ANUNCIANTES][6];
	int opcion, anuncios[ANUNCIOS][3];

	// Inicializacion de anunciantes a 0
	for (i = 0; i < ANUNCIANTES; i ++)
	{
		for (j = 0; j <= 6; j++)
		{anunciantes[i][j] = '0';}
	}

	// Empieza con la lectura de anunciantes
	registrar_anunciante(anunciantes);

	// Luego aparece el menu
	printf("Escoja una opcion: \n");
	printf("-----------------------\n");
	printf("1. Registrar anuncio\n");
	printf("2. Mostrar estadisticas\n");
	printf("3. Salir\n");
	printf("-----------------------\n");
	scanf("%d", &opcion);
	fflush(stdin);


	do {
		// Switch para el manejo del menu
		switch(opcion)
		{
		case 1:
			{
				registrar_anuncio(anunciantes, anuncios);
				break;
			}
			
		case 2:
			{
				estadisticas_anunciantes(anunciantes, anuncios);
				break;
			}
			
		case 3:
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
	} while (opcion != 3);
}

void registrar_anunciante(char anunciantes[ANUNCIANTES][6])
{
	/* 
	Esta funcion va a pedir nombres de anunciantes completos, hasta un limite
	de 30 caracteres por nombre, los va a abreviar a 5 caracteres 
	(6 contando el /0) y los va a poner en mayusculas.
	En realidad, que el nombre sin abreviar tenga mas de 30 caracteres da igual,
	puesto que lo vamos a usar para recortarlo nada mas, pero no puede estar
	vacio.
	Va a pedir nombres de anunciantes hasta que se le diga lo contrario o hasta
	que llegue a 10, en cuyo caso lanzara una alerta y volvera al ciclo de ejecucion
	en main().
	*/
	// Declaracion de variables
	int i, len_nombre_abr, comp;
	char nombre[30], nom_abreviado[6];
	char stop[5] = {'s','t','o','p','\0'};

	// Empezamos pidiendo nombres
	for (i = 0; i < ANUNCIANTES; i++)
	{
		printf("Introduzca el nombre del anunciante ('stop' para parar): ");
		gets(nombre);

		// Salir si ha escrito 'stop'
		comp = stricmp(stop, nombre);
		if (comp == 0)
		{printf("\n"); break;}
		// Recortar el nombre
		strncpy(nom_abreviado, nombre, 5);

		// Poner las letras del nombre abreviado en mayusculas
		strupr(nom_abreviado);

		// Añadir '-' al nombre si no llega a 5 caracteres
		len_nombre_abr = strlen(nom_abreviado);
		if ((len_nombre_abr > 1) && (len_nombre_abr < 5))
		{
			// Invertimos la cadena
			strrev(nom_abreviado);
			// Le añadimos los caracteres '-' necesarios
			strnset(nom_abreviado, '-', 5 - len_nombre_abr);
			// Ponemos bien la cadena
			strrev(nom_abreviado);
		}

		// Añadir la cadena al array anunciantes
		strcpy(anunciantes[i], nom_abreviado);
	}
	

	// Llamamos a la funcion ordenar_alfabeticamente
	ordenar_alfabeticamente(anunciantes);

	printf("\n");
}

void ordenar_alfabeticamente(char anunciantes[ANUNCIANTES][6])
{
	/* 
	Esta funcion va a ordenar por el primer valor del segundo el elemento
	el array de caracteres dado. Para comparar los elementos va a usar
	strcmp(cad1, cad2) que sera < 0 si cad1 es una letra con una posicion
	mayor en el abecedario que cad2.
	*/
	// Declaracion de variables
	int i, j, comparacion = 0;
	char aux1[2], aux2[2], nom_copia[6];

	// Empezamos creando un bucle para recorrer el array dado, accediendo a sus
	// filas (cada fila es el nombre de un anunciante).
	for (i = 0; i < ANUNCIANTES; i ++)
	{
		for (j = ANUNCIANTES - 1; j > i; j --)
		{
			// Almacenamos los valores en variables auxiliares para compararlos
			strncpy(aux1, anunciantes[j], 1);
			strncpy(aux2, anunciantes[j-1], 1);

			// Comparacion de las cadenas
			comparacion = strcmp(aux1, aux2);

			// Si aux1 esta por detras de aux2 en el diccionario, 
			// o son iguales, ya esta ordenado
			if (comparacion <= 0)
			{continue;}
			// Si aux1 esta por delante de aux2 en el diccionario, hay que
			// intercambiar los valores de anunciantes[][]
			else
			{
				strcpy(nom_copia, anunciantes[j]);
				strcpy(anunciantes[j], anunciantes[j-1]);
				strcpy(anunciantes[j-1], nom_copia);
			}
		}
	}

	printf("\n");
}

void registrar_anuncio(char anunciantes[ANUNCIANTES][6], int anuncios[ANUNCIOS][3])
{
	/* 
	Esta funcion va a pedir la hora (hh:mm) y duracion (s) de un anuncio para
	un anunciante, y va a crear una entrada en el array anuncios con otro vector que
	contenga la 
	posicion que tiene el anunciante en el array anunciantes, la hora y minutos
	en segundos, y la duracion en segundos.
	*/
	// Declaracion de variables
	
	int i, anuncio[3];
	int pos_anunciante, hora, min, duracion, hora_seg;

	// Primero se piden los datos
	printf("Escoja un anunciante: \n");
	printf("-----------------------\n");
	// Mostrar los nombres de todos los anunciantes
	for (i = 0; i < ANUNCIANTES; i++)
	{printf("%d: %s\n", i, anunciantes[i]);}
	
	scanf("%d", &pos_anunciante);
	fflush(stdin);

	// Lectura de datos hh:mm y duracion
	printf("----------------------\n");
	printf("Por favor, indique la hora a la que se mostrara el anuncio (hh:mm):");
	scanf("%d:%d", &hora, &min);
	fflush(stdin);
	printf("Por favor, indque la duracion en segundos del anuncio: ");
	scanf("%d", &duracion);
	fflush(stdin);

	// Control de errores
	if ((hora < 0) || (min < 0) || (duracion < 0) || (pos_anunciante < 0 ) || (pos_anunciante >= ANUNCIANTES))
	{printf("Ha ocurrido un error. Por favor, introduzca una hora, minutos, duracion, y posicion de anunciante validos.\n");}
	else {
	// Conversion de hh:mm a segundos
	hora_seg = ((hora * 3600) + (min * 60));

	// Crear una entrada en el array anuncios
	anuncio[0] = pos_anunciante;
	anuncio[1] = hora_seg;
	anuncio[2] = duracion;
	anuncios[pos_anunciante][0] = anuncio[0];
	anuncios[pos_anunciante][1] = anuncio[1];
	anuncios[pos_anunciante][2] = anuncio[2];
	/*
	Yo complicandome be like:
	int hora_y_seg[1][2] = {{hora_seg, duracion}};
	int anuncio[ANUNCIOS][1][2] = { {pos_anunciante}, {hora_y_seg[0][0]}, {hora_y_seg[0][1]} };

	printf("\n");
	*/
	}
}

void estadisticas_anunciantes(char anunciantes[ANUNCIANTES][6], int anuncios[ANUNCIOS][3])
{
	/* 
	Esta funcion va a mostrar por pantalla la posicion y nombre de los anunciantes,
	junto con la cantidad de anuncios que tiene cada uno y la duracion total
	en minutos y segundos de todos sus anuncios
	*/
	// Declaracion de variables
	

	
}
