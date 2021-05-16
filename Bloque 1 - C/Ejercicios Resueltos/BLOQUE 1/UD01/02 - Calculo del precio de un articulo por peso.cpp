#include <stdio.h>

/*
PROGRAMA bascula
  ESCRIBIR "Introduzca el peso del articulo: "
  LEER peso
  ESCRIBIR "¿Cuanto cuesta el kilo de ese articulo?: "
  LEER precio_por_kilo
  CALCULAR importe = peso x precio_por_kilo
  ESCRIBIR "El importe a pagar es de ", importe, " euros."
  ESCRIBIR "Indicar cuanto dinero se aporta: "
  LEER pago
  CALCULAR cambio = pago - importe
  ESCRIBIR "El cambio es de ", cambio, " euros."
FIN bascula
*/

void main ()
{
	float peso, precio_por_kilo, importe, pago;

	printf("Introduzca el peso del articulo: ");
	scanf("%f", &peso);
	fflush(stdin);

	printf("Cuanto cuesta el kilo de ese articulo?: ");
	scanf("%f", &precio_por_kilo);
	fflush(stdin);

	importe = peso * precio_por_kilo;

	printf("El importe a pagar es de %.2f euros.\n\n",
		importe);

	printf("Indicar cuanto dinero se aporta: ");
	scanf("%f", &pago);
	fflush(stdin);

	printf("El cambio es de %.2f euros.\n\n", 
		pago - importe);
}