#include <stdio.h>

#define TAM 10    // Tamaño máximo del avión
#define LIMITE 4 // Límite entre las plazas de las dos categorías

#define V 1
#define F 0


void imprimir_plazas_libres (int f, int nf)
{
	int i;

	printf("\nPLAZAS LIBRES");
	printf("\n-------------");
	
	printf("\nNo fumador: ");
	if (nf == LIMITE)
		printf("Ninguna.");
	else
		printf("De la %d a la %d.", nf+1, LIMITE);
	
	printf("\nFumador: ");
	if (f == TAM)
		printf("Ninguna.");
	else
		printf("De la %d a la %d.", f+1, TAM);
}


int quiere_otra_categoria ()
{
	int respuesta;
	
	do{
		printf("Desea una plaza en la otra categoria (1 = SI, 0 = NO): ");
		scanf("%d", &respuesta);
		fflush(stdin);
	}while(respuesta != 0 && respuesta != 1);
	
	return respuesta;
}

void introducir_dni (int dni, int es_fumador, int vector[],int *cont_fuma, int *cont_no_fuma)
{
	if (es_fumador)
		if ((*cont_fuma) == TAM)
		{
			printf("\nNo hay plazas libres de fumador.\n");
			if (quiere_otra_categoria())
				introducir_dni (dni, !es_fumador, vector, cont_fuma, cont_no_fuma);
		}
		else
		{
			vector[(*cont_fuma)] = dni;
			(*cont_fuma)++;
		}
	else
		if ((*cont_no_fuma) == LIMITE)
		{
			printf("\nNo hay plazas libres de no fumador.\n");
			if (quiere_otra_categoria())
				introducir_dni (dni, !es_fumador, vector, cont_fuma, cont_no_fuma);
		}
		else
		{
			vector[(*cont_no_fuma)] = dni;
			(*cont_no_fuma)++;
		}
}



void leer_dni (int *dni, int *fuma)
{
	char f;

	printf("Introduzca el dni (0 para terminar): ");
	scanf("%d", dni);
	fflush(stdin);

	if ((*dni) != 0)
	{
		do{
			printf("\nEs fumador (s/n)?: ");
			scanf("%c", &f);
			fflush(stdin);
		}while ((f!='s') && (f!='n'));

		if (f == 's')
			(*fuma) = V;
		else
			(*fuma) = F;
	}
}

void imprimir_plazas_ocupadas (int reservas[], int cnf, int cf)
{
	int i;
	
	printf("\nPLAZAS OCUPADAS");
	printf("\n---------------");
	
	printf("\nNo fumadores:\n");
	for (i = 0; i < cnf; i++)
		printf("Plaza %d: %d\n", i + 1, reservas[i]);
		
	printf("\nFumadores:\n");
	for (i = LIMITE; i < cf; i++)
		printf("Plaza %d: %d\n", i + 1, reservas[i]);
	
	printf("\n");
}


void main()
{
	int reservas[TAM];
	int no_fuma = 0, fuma = LIMITE; // Apuntan a la primera celda libre de cada categoría.
	int dni;
	int fumador;

	// Repetimos el proceso mientras el usuario no escriba un 0 en el dni y el avion aun tenga plazas libres:
	do{
		leer_dni(&dni, &fumador);

		if (dni != 0)
			introducir_dni (dni, fumador, reservas, &fuma, &no_fuma);
	}while ((dni!=0) && (!(fuma == TAM && no_fuma == LIMITE)));

	imprimir_plazas_ocupadas (reservas, no_fuma, fuma);

	if (dni != 0)
		printf("\n\nNo hay mas plazas libres.\n");
	else
		imprimir_plazas_libres (fuma, no_fuma);
}
