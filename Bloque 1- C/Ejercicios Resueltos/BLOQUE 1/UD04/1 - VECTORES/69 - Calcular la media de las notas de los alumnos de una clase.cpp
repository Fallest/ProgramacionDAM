#include <stdio.h>

#define TAM 5

void ordena_seleccion (int v[])
{
	int i, j, mayor, aux;

	for (i=0; i<TAM-1; i++)
	{
		mayor = i;

		for (j=i+1; j<TAM; j++)
			if (v[j] > v[mayor])
				mayor = j;

		aux = v[i];
		v[i] = v[mayor];
		v[mayor] = aux;
	}
}


float calcula_media (int t[])
{
	int i, acum = 0;

	for (i=0; i<TAM; i++)
		acum = acum + t[i];

	return (float) acum / TAM;
}


void imprime_vector (int t[])
{
	int i;

	for (i=0; i<TAM; i++)
		printf("%d ", t[i]);
}


void rellena_vector (int t[])
{
	int i;

	for (i=0; i<TAM; i++)
	{
		do{
		   printf("Introduzca la calificacion %d (no negativa): ", i+1);
		   scanf("%d", &t[i]);
		   fflush(stdin);
		}while (t[i] < 0);
	}
}

void main()
{
	int vector [TAM];

    rellena_vector(vector);
    ordena_seleccion(vector);

	printf("\nVector de calificaciones ordenado: ");
    imprime_vector(vector);

    printf("\n\nLa media de las calificaciones es de %f.\n\n", calcula_media(vector));
}




