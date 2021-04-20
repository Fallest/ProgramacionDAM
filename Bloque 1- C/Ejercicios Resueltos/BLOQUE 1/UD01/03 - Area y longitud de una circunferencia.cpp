#include <stdio.h>
#include <math.h>

#define PI 3.14

void main ()
{
	int radio;

	printf("Indica el valor del radio (en centimetros): ");
	scanf("%d", &radio);
	fflush(stdin);

	printf("La longitud de la circunferencia es de %.2f centimetros",
		2 * PI * radio);
	/*printf(" y el area es de %.2f centimetros cuadrados.\n\n",
		PI * radio * radio);*/
	printf(" y el area es de %.2f centimetros cuadrados.\n\n",
		PI * pow (radio, 2));
}