#include <stdio.h>
#include <math.h>

void main ()
{
	int a, b, c;
	//float resultado_raiz;

	printf("Indica el valor del coeficiente de x cuadrado: ");
	scanf("%d", &a);
	fflush(stdin);

	printf("Indica el valor del coeficiente de x: ");
	scanf("%d", &b);
	fflush(stdin);

	printf("Indica el valor del termino independiente: ");
	scanf("%d", &c);
	fflush(stdin);

	if((b * b - 4 * a * c) >= 0)
	{
	  printf("Las soluciones de la ecuacion son %.0f y %.0f.\n\n",
		(- b + sqrt (b * b - 4 * a * c)) / (2 * a),
		(- b - sqrt (b * b - 4 * a * c)) / (2 * a));
	}
	else
	{
		printf("La ecuacion no tiene soluciones reales.\n\n");
	}

	
}