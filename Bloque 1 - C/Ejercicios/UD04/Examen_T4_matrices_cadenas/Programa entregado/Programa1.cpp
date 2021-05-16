#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGCAD 40
#define LONGVOC 6
#define TAM 40

// Prototipado

void mostrar_menu();
void mostrar_menu_eliminar();
void leer_opcion_eliminar(int *opcion, int *pos, char *ini);
void leer_opcion(int *opcion);
void ejecutar_opcion(int opcion, int *opcion_eliminar, int pos, char ini, char cadena[], char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int  num_cadenas);
void lectura_cadena(char cadena[]);
void extraer_vocales(char cadena[], char matriz_vocales[TAM][LONGVOC], char matriz_cadenas[TAM][LONGCAD]);
void registro_cadena(char cadena[], char matriz_cadenas[TAM][LONGCAD], int num_cadenas);
void ordenar_estructura_longitud(char matriz_cadenas[TAM][LONGCAD]);
void ordenar_estructura_alfabeto(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC]);
void mostrar_listado(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC]);
void eliminar_palabra_posicion(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int pos);
void eliminar_palabra_inicial(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], char ini);
void contar_vocales(char matriz_vocales[TAM][LONGVOC]);



void main()
{
	int opcion, opcion_eliminar, num_cadenas = 0, i;
	int pos = 0;
	char ini = 'N', matriz_cadenas[TAM][LONGCAD], matriz_vocales[TAM][LONGVOC], cadena[LONGCAD];

	// Inicializar ambas matrices
	for (i = 0; i < TAM; i++)
	{
		strset(matriz_cadenas[i], ' ');
		strset(matriz_vocales[i], ' ');
	}


	do {
		mostrar_menu();
		leer_opcion(&opcion);
		ejecutar_opcion(opcion, &opcion_eliminar, pos, ini, cadena, matriz_cadenas, matriz_vocales, num_cadenas);
	} while (opcion != 5);
}
void mostrar_menu() 
{
	/**/
	printf("Escoja una opcion: \n");
	printf("-----------------------\n");
	printf("1. Alta de palabra\n");
	printf("2. Listado ordenado\n");
	printf("3. Eliminar palabras\n");
	printf("4. Contar vocales\n");
	printf("5. Salir\n");
	printf("-----------------------\n");

}
void leer_opcion(int *opcion)
{
	do{
		printf("\nIntroduzca opcion: ");
		scanf("%d", opcion);
		fflush(stdin);
	}while (((*opcion) <= 0) || ((*opcion) > 5));
}
void ejecutar_opcion(int opcion, int *opcion_eliminar, int pos, char ini, char cadena[], char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int  num_cadenas)
{
	switch(opcion)
	{
		case 1: 
			{
				lectura_cadena(cadena);
				registro_cadena(cadena, matriz_cadenas, num_cadenas);
				ordenar_estructura_longitud(matriz_cadenas);
				extraer_vocales(cadena, matriz_vocales, matriz_cadenas);
				num_cadenas ++;
		        break;
			}
		case 2: 
			{
				mostrar_listado(matriz_cadenas, matriz_vocales);
				break;
			}
		case 3: 
			{
				mostrar_menu_eliminar();
				leer_opcion_eliminar(opcion_eliminar, &pos, &ini);
				if (*opcion_eliminar == 1)
				{eliminar_palabra_posicion(matriz_cadenas, matriz_vocales, pos);}
				else
				{eliminar_palabra_inicial(matriz_cadenas, matriz_vocales, ini);}
				break;
			}
		case 4:
			{
				contar_vocales(matriz_vocales);
				break;
			}
	}
}
void lectura_cadena(char cadena[])
{
	/**/

	printf("Introduzca la cadena (max 40 caracteres): ");
	gets(cadena);
	fflush(stdin);

	strupr(cadena);

}
void extraer_vocales(char cadena[], char matriz_vocales[TAM][LONGVOC], char matriz_cadenas[TAM][LONGCAD])
{
	/**/
	int i, j, k, num, cont_aux=0;
	char cad_aux[LONGCAD], vocales[LONGVOC], cad_aux_vocal[2];

	for (i = 0; i < TAM; i++)
	{
		num = strcmp(matriz_cadenas[i], cadena);
		if (num == 0)
		{
			strcpy(cad_aux, matriz_cadenas[i]);
			for (j = 0; j < LONGCAD; j++)
			{
				if ((cad_aux[j] == 'A') || (cad_aux[j] == 'E') || (cad_aux[j] == 'I')
					|| (cad_aux[j] == 'O') ||(cad_aux[j] == 'U'))
				{
					for (k = 0; k < LONGCAD; k++)
					{
						if (vocales[k] == cad_aux[j])
						{vocales[k] = cad_aux[j];}
						else
						{
							cad_aux_vocal[0] = cad_aux[j];
							cad_aux_vocal[1] = '\0';
							strcat(vocales, cad_aux_vocal);
						}
					}
				}
			}
			break;
		}
		else 
		{continue;}

		strcpy(matriz_vocales[i], vocales);
	}

}
void registro_cadena(char cadena[], char matriz_cadenas[TAM][LONGCAD], int num_cadenas)
{
	/**/
	int i;

	for (i = 0; i < TAM; i++)
	{
		if (num_cadenas == i)
		{strcpy(matriz_cadenas[i], cadena);}
	}

}
void ordenar_estructura_longitud(char matriz_cadenas[TAM][LONGCAD])
{
	/**/
	int i, j, min = 0, aux = 0;
	char cad_aux[LONGCAD];

	// Inicializar cad_aux

	strset(cad_aux, ' ');
	
	for (i = 0; i < TAM; i++)
	{
		min = i;
		for (j = i + 1; j < TAM; j++) 
		{
			if (strlen(matriz_cadenas[j]) <= strlen(matriz_cadenas[min]))
			{min = j; aux = j;}
		}
		if (min > TAM) {break;}
		strcpy(cad_aux, matriz_cadenas[min]);
		aux = 0;
		if (min > TAM) {break;}
		strcpy(matriz_cadenas[min], matriz_cadenas[i]);
		if (min > TAM) {break;}
		strcpy(matriz_cadenas[i], cad_aux);
	}
}
void ordenar_estructura_alfabeto(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC])
{
	int i, j, min;
	char cad_aux[LONGCAD];
	
	for (i = 0; i < TAM; i++)
	{
		min = i;
		for (j = i + 1; j < TAM; j++) 
		{
			if (strcmp(matriz_cadenas[j], matriz_cadenas[min]) <= 0)
			{min = j;}
		}
		strcpy(cad_aux, matriz_cadenas[min]);
		strcpy(matriz_cadenas[min], matriz_cadenas[i]);
		strcpy(matriz_cadenas[i], cad_aux);
	}
}
void mostrar_listado(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC])
{
	/**/
	int i;
	char matriz_aux_cadenas[TAM][LONGCAD];
	char matriz_aux_vocales[TAM][LONGVOC];
	

	for(i = 0; i < TAM; i++)
	{
		strcpy(matriz_aux_cadenas[i], matriz_cadenas[i]);
		strcpy(matriz_aux_vocales[i], matriz_vocales[i]);
	}

	ordenar_estructura_alfabeto(matriz_aux_cadenas, matriz_aux_vocales);

	for (i = 0; i < TAM; i++)
	{
		printf("Cadena %d: %s - %s\n", i, matriz_aux_cadenas[i], matriz_aux_vocales[i]);
	}

}
void mostrar_menu_eliminar()
{
	printf("Escoja una opcion para eliminar (1 para posicion, 2 para letra inicial): ");
}
void leer_opcion_eliminar(int *opcion, int *pos, char *ini)
{
	do{
		printf("\nIntroduzca opcion: ");
		scanf("%d", opcion);
		fflush(stdin);
	}while (((*opcion) <= 0) || ((*opcion) > 2));

	if (*opcion == 1)
	{
		printf("Introduzca una posicion: ");
		scanf("d", pos);
		fflush(stdin);
	}
	else
	{
		printf("Introduzca una letra inicial: ");
		scanf("c", ini);
		fflush(stdin);
	}
}
void eliminar_palabra_posicion(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], int pos)
{
	/**/
	int i;

	for(i = 0; i < TAM; i++)
	{
		if(i == pos)
		{
			strset(matriz_cadenas[i], ' ');
			strset(matriz_vocales[i], ' ');
		}
	}

}
void eliminar_palabra_inicial(char matriz_cadenas[TAM][LONGCAD], char matriz_vocales[TAM][LONGVOC], char ini)
{
	/**/
	int i;

	for(i = 0; i < TAM; i++)
	{
		if (matriz_cadenas[i][0] == ini)
		{
			strset(matriz_cadenas[i], ' ');
			strset(matriz_vocales[i], ' ');
		}
		
	}
}
void contar_vocales(char matriz_vocales[TAM][LONGVOC])
{
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