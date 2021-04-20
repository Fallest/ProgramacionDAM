#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TPAISES 200
#define TCIUDADES 50

/* ------------------------------------------------------------ */
// Estructuras
/*  Para almacenar las ciudades de cada país, crearemos una estructura dentro de 
	la propia estructura de Pais. Usamos typedef para tener mayor facilidad de uso.*/
typedef struct {
	int cod_c; // Misma función que el cod de un país.
	char nom_ciudad[40]; 
	int num_habit_c;
	bool capital;
} Ciudad;

typedef struct {
	int cod; // El uso de cod será para controlar si está vacío o no el país. Si es 0, está vacío.
	char nom_pais[40];
	int num_habit;
	Ciudad ciudades[TCIUDADES];
} Pais;

/* ------------------------------------------------------------ */
// Prototipado
void mostrar_menu();
void leer_opcion(int *opcion);
void ejecutar_opcion(int opcion, Pais paises[], int *num_paises, int *cod_ciudades);

void alta_pais(Pais paises[], int *num_paises);
void baja_pais(Pais paises[]);

void alta_ciudad(Pais paises[], int *cod_ciudades);

void consulta_ciudades(Pais paises[]);
void listado(Pais paises[]);

void pedir_datos_pais(char nombre[], int *num_hab);
void pedir_datos_ciudad(char nombre[], int *num_hab);
void pedir_nombre(char nombre[]);
void pedir_numhab(int *num_hab);

/* ------------------------------------------------------------ */
//MAIN
void main()
{
	// Variables que se usarán en el programa.
	// num_paises y cod_ciudades son autonúmeros para asignar códigos a las ciudades y países.
	// El código solo sirve para saber si están vacíos o no.
	Pais paises[TPAISES];
	int opcion, num_paises = 0, cod_ciudades = 0;

	// Inicializar todos los códigos a 0:
	int i, j;
	for (i = 0; i < TPAISES; i++)
	{
		paises[i].cod = 0;
		for (j = 0; j < TCIUDADES; j++)
			paises[i].ciudades[j].cod_c = 0;
	}


	// Bucle de ejecución. Se saldrá de él cuando la opción escogida sea la 6.
	do {
		mostrar_menu();
		leer_opcion(&opcion);
		ejecutar_opcion(opcion, paises, &num_paises, &cod_ciudades);
	} while(opcion != 6);
	printf("\nSaliendo del programa...\n");
}

/* ------------------------------------------------------------ */// 3/3
// Funciones del menú
void mostrar_menu()
{
	printf("-----MENU-----\n");
	printf("1. Alta de pais\n");
	printf("2. Baja de pais\n");
	printf("3. Alta de ciudad\n");
	printf("4. Consultar ciudades de un pais\n");
	printf("5. Listado de datos\n");
	printf("6. Salir\n");
	printf("--------------\n");
}

void leer_opcion(int *opcion)
{
	do {
		printf("Escoja una opcion (1-6): ");
		scanf("%d", opcion);
		fflush(stdin);
	} while (((*opcion) < 1) || ((*opcion) > 6)); //Modificar
}

void ejecutar_opcion(int opcion, Pais paises[], int *num_paises, int *cod_ciudades)
{
	switch (opcion)
	{
	case 1:
		{
			alta_pais(paises, num_paises);
			break;
		}
	case 2:
		{
			baja_pais(paises);
			break;
		}
	case 3:
		{
			alta_ciudad(paises, cod_ciudades);
			break;
		}
	case 4:
		{
			consulta_ciudades(paises);
			break;
		}
	case 5:
		{
			listado(paises);
			break;
		}
	}
}

/* ------------------------------------------------------------ */// 2/2
// Funcioes de alta y baja de paises
void alta_pais(Pais paises[], int *num_paises)
{
	int i, j;
	bool flag = true;

	// Se busca una posición que cumpla:
	//	1. La letra inicial del nombre del país de la posición anterior está colocada
	//		en un lugar inferior en el abecedario que la inicial del nombre del país
	//		que queremos introducir.
	for (i = 0; i < TCIUDADES; i++)
	{
		// Si es el primer elemento que se introduce
		if (i==0 && paises[i].cod == 0)
		{
			// Asignamos código. Es un autonúmero.
			(*num_paises)++;
			paises[i].cod = (*num_paises);
			
			// Debemos pedir los datos cada vez que veamos que el país ya existe
			do {
				flag = false;
				pedir_datos_pais(paises[i].nom_pais, &paises[i].num_habit);

				printf("Datos de la capital: ");
				paises[i].ciudades[0].capital = true; // Como es capital, hay que ponerlo
				pedir_datos_ciudad(paises[i].ciudades[0].nom_ciudad, &paises[i].ciudades[0].num_habit_c);
				
				// Controlar que el pais no existe ya
				// Por alguna razón, parece que da un error aquí. No estoy seguro de qué pasa,
				// pero me pasa en todos los ejercicios, y es lo mismo que ya me pasó en otro examen
				// y todavía no he podido resolver.
				// Agradecería si al corregirlo pudieras encontrar ese error.
				for (j = 0; i < TPAISES; j++)
				{
					if (stricmp(paises[i].nom_pais, paises[j].nom_pais) == 0 && j != i
						&& paises[j].cod != 0)
					{
						flag = true; 
						printf("Ese país ya existe.\n");
					}
				}
			} while (flag);
			break;
		}

		// Si no es el primer elemento que se introduce
		// Lo introducimos en orden, comprobando que la inicial (nom_pais[0], char)
		// del elemento anterior es MENOR (está antes en el abecedario) que la del
		// país actual.
		else if (tolower(paises[i-1].nom_pais[0]) <= tolower(paises[i].nom_pais[0]))
		{
			// Asignamos código. Es un autonúmero.
			(*num_paises)++;
			paises[i].cod = (*num_paises);
			
			// Debemos de pedir los datos cada vez que veamos que el país ya existe
			do {
				flag = false;
				pedir_datos_pais(paises[i].nom_pais, &paises[i].num_habit);

				printf("Datos de la capital: ");
				paises[i].ciudades[0].capital = true; // Como es capital, hay que ponerlo
				pedir_datos_ciudad(paises[i].ciudades[0].nom_ciudad, &paises[i].ciudades[0].num_habit_c);
				
				// Controlar que el pais no existe ya
				for (j = 0; i < TPAISES; j++)
				{
					if (strcmpi(paises[i].nom_pais, paises[j].nom_pais) == 0 && j != i)
					{
						flag = true; 
						printf("Ese país ya existe.\n");
					}
				}
			} while (flag);
			break;
		}
	}
}

void baja_pais(Pais paises[])
{
	// Tiene que buscar el país por nombre, eliminar el país que coincida
	// y eliminarlo de la estructura, bajando una posición todos los valores siguientes.
	int i, j;
	char nombre[40];

	pedir_nombre(nombre);

	for (i = 0; i < TPAISES; i++)
	{
		if (strcmpi(paises[i].nom_pais, nombre) == 0)
		{
			// Establecemos su código en 0, para indicar que está vacío
			paises[i].cod = 0;
			// Iteramos sobre los paises a partir del que queremos eliminar
			for (j = i + 1; j < TPAISES; j++)
			{
				// Si el pais siguiente no está vacío, lo movemos una posición hacia abajo.
				if (paises[j].cod != 0)
					paises[j-1] = paises[j];
					paises[j].cod = 0; // Después de moverlo, eliminamos la copia que se queda detrás, para evitar que haya uno repetido.
			}
			break;
		}
	}
}

/* ------------------------------------------------------------ */// 1/1
// Funciones de alta de ciudades
void alta_ciudad(Pais paises[], int *cod_ciudades)
{
	// Debemos realizar una introducción ordenada de datos en las ciudades
	// ordenadas por su letra inicial.
	int i, j, k;
	bool flag = true;
	char nombre[40];

	// Pedir el nombre del país
	pedir_nombre(nombre);

	for (i = 0; i < TPAISES; i++)
	{
		// Si hemos encontrado el país
		if (stricmp(paises[i].nom_pais, nombre) == 0)
		{
			for (j = 1; j < TCIUDADES; j++)
			{
				// Comprobar que no esté lleno
				if (paises[i].ciudades[TCIUDADES-1].cod_c !=0)
				{
					printf("Este pais no puede tener mas ciudades.\n");
					break;
				}

				// Buscamos una ciudad cuya inicial sea menor que la inicial de la ciudad actual.
				// Así se introduce en orden.
				if (tolower(paises[i].ciudades[j-1].nom_ciudad[0]) <= tolower(paises[i].ciudades[j].nom_ciudad[0]))
				{
					// Desplazar todas las ciudades hacia delante, solo si no están vacías.
					for (k = TCIUDADES - 1; k > j; k--)
					{
						// Si la ciudad siguiente no está vacía, lo movemos una posición hacia abajo.
						paises[i].ciudades[k] = paises[i].ciudades[k-1]; 
					}

					// Aumentamos el autonúmero cod_ciudades y ponemos que no es capital
					(*cod_ciudades)++;
					paises[i].ciudades[j].cod_c = (*cod_ciudades);
					paises[i].ciudades[j].capital = false;

					do {
						flag = false;

						// Pedimos los datos de la ciudad
						pedir_datos_ciudad(paises[i].ciudades[j].nom_ciudad, &paises[i].ciudades[j].num_habit_c);
						
						// Debemos comprobar si esa ciudad ya está dentro de ese país
						for (k = 0; k < TCIUDADES; k++)
						{
							// Comparar el nombre de la ciudad actual con todas las demás
							if (strcmpi(paises[i].ciudades[j].nom_ciudad, paises[i].ciudades[k].nom_ciudad) == 0 && j != k)
							{
								printf("Esa ciudad ya existe en este país.");
								flag = true;
							}
						}
					} while (flag);
				}
			}
		}
	}
}

/* ------------------------------------------------------------ */// 2/2
// Funciones de consulta
void consulta_ciudades(Pais paises[])
{
	int cont = 0, i, j;
	char nombre[40];

	// Pedir el nombre del país:
	pedir_nombre(nombre);

	for (i = 0; i < TPAISES; i++)
	{
		// Buscamos el país por nombre
		if (stricmp(nombre, paises[i].nom_pais) == 0)
		{
			for (j = 0; j < TCIUDADES; j++)
			{
				// Tenemos que comprobar el código, porque no podemos mostrar ciudades vacías.
				if (paises[i].ciudades[j].cod_c !=0)
				{
					cont++;
					printf("Ciudad %s: .\n\tNumero de habitantes: %d\n", paises[i].ciudades[j].nom_ciudad, paises[i].ciudades[j].num_habit_c);
					if (paises[i].ciudades[j].capital)
						printf("\tEsta ciudad es capital.\n");
				}
			}
			printf("\nSe han registrado %d ciudades para el pais %s\n", cont, paises[i].nom_pais);
			break;
		}
	}
}

void listado(Pais paises[])
{
	int i, j, cont = 0;

	for (i = 0; i < TPAISES; i++)
	{
		// Solo se mostrarán los datos de los países que tengan un código.
		if (paises[i].cod != 0)
		{
			printf("Pais %s: \n", paises[i].nom_pais);
			printf("\tNumero de habitantes: %d\n", paises[i].num_habit);

			// Contamos las ciudades que no tienen código a 0.
			for (j = 0; j < TCIUDADES; j++)
			{
				if (paises[i].ciudades[j].cod_c !=0)
					cont++;
			}

			printf("\tNumero de ciudades registradas: %d\n\n", cont);

			// Tenemos que resetear el contador de ciudades para el siguiente país.
			cont = 0;
		}
	}
}

/* ------------------------------------------------------------ */// 4/4
// Funciones auxiliares
void pedir_datos_pais(char nombre[], int *num_hab)
{
	printf("\nInserte los datos del pais: \n");
	// Pedir el nombre del país
	pedir_nombre(nombre);

	// Pedir el número de habitantes del país.
	pedir_numhab(num_hab);
}

void pedir_datos_ciudad(char nombre[], int *num_hab)
{
	printf("\nInserte los datos de la ciudad: \n");
	// Pedir el nombre de la ciudad
	pedir_nombre(nombre);

	// Pedir el número de habitantes de la ciudad
	pedir_numhab(num_hab);
}

void pedir_nombre(char nombre[])
{
	printf("\tIntroduzca el nombre (40 caracteres max.): ");
	gets(nombre);
	fflush(stdin);
}

void pedir_numhab(int *num_hab)
{
	do {
		printf("\tIntroduzca el numero de habitantes: ");
		scanf("%d", num_hab);
		fflush(stdin);
	} while ((*num_hab) < 0);
}

