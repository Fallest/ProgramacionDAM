#include <stdio.h>

#define TAM1 5
#define TAM2 10

void rellena_resto (int ordenado[TAM2], int ind, int contador, int vec[TAM1])
{
	int i;

    // Se rellenan las posiciones de i a TAM2 con los valores que quedan del vector vec
    // a partir de su posición "contador":
    for (i=ind; i<TAM2; i++)
	{
		ordenado[i] = vec[contador];
        contador = contador + 1;
	}
}

void compone_vector_ordenado (int t1[TAM1], int t2[TAM1], int tord[TAM2])
{
	int i, c1 = 0, c2 = 0;

	for (i=0; i<TAM2; i++)
          // Si no quedan elementos del vector 1 se rellena con los que quedan del vector 2:
		  if (c1 >= TAM1)
		  {
              rellena_resto (tord, i, c2, t2);
			  break;
		  }
		  else
              // Si no quedan elementos del vector 2 se rellena con los que quedan del vector 1:
              if (c2 >= TAM1)
			  {
                  rellena_resto (tord, i, c1, t1);
				  break;
			  }
			  else
                  // Quedan elementos en los dos vectores: se rellena con el menor de los que queden:
				  if (t1[c1] < t2[c2])
				  {
					  tord[i] = t1[c1]; // Se añade al vector ordenado
					  c1++;             // Se incrementa el apuntador
				  }
				  else
				  {
					  tord[i] = t2[c2]; // Se añade al vector ordenado
					  c2++;
				  }
}


void imprime_vector (int t[])
{
	int i;

	for (i=0; i<TAM2; i++)
		printf("%d ", t[i]);
}


void rellena_vector (int t[TAM1])
{
	int i;

	for (i=0; i<TAM1; i++)
	{
		printf("Introduzca el valor del elemento %d: ", i+1);
		scanf("%d", &t[i]);
		fflush(stdin);
	}
}


void ordena_seleccion (int v[])
{
	int i, j, menor, aux;

	for (i=0; i<TAM1-1; i++)
	{
		menor = i;

		for (j=i+1; j<TAM1; j++)
			if (v[j] < v[menor])
				menor = j;

		aux = v[i];
		v[i] = v[menor];
		v[menor] = aux;
	}
}


void main()
{
	int v1[TAM1], v2[TAM1];
	int vord[TAM2];

	printf("Primer vector:\n");
	rellena_vector (v1);

	printf("Segundo vector:\n");
	rellena_vector (v2);

    ordena_seleccion(v1);
    ordena_seleccion(v2); 

    compone_vector_ordenado(v1, v2, vord);

    printf("\nVector ordenado:\n");
    imprime_vector(vord);
}
