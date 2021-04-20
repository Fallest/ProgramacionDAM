#include <stdio.h>

#define MAX_VIAJES 5
#define EDAD_LIMITE 25
#define DESCUENTO1 0.25
#define DESCUENTO2 0.10
#define KILOMETROS_LIMITE 10000
#define REBAJA 1200
#define COSTE_KM_AVION 0.6
#define COSTE_KM_OTROS 0.3

void main()
{
	int numero_viajes;
	int contador_viajes = 0;
	int kilometros;
	char medio, edad;
	int acumulador_importe_facturas = 0;
	int factura_maxima = 0;
	int importe_bruto;
	int descuento;
	int importe_neto;

	do{
		printf("Introduzca el numero de viajes: ");
		scanf("%d", &numero_viajes);
		fflush(stdin);
	}while(numero_viajes < 0 || numero_viajes > MAX_VIAJES);

	do{
		contador_viajes++;

		descuento = 0;

		printf("\nViaje %d\n", contador_viajes);
		printf("---------\n");
		
		do{
			printf("Numero de kilometros: ");
			scanf("%d", &kilometros);
			fflush(stdin);
		}while(kilometros < 0);

		do{
			printf("Medio de transporte (A, T, B): ");
			scanf("%c", &medio);
			fflush(stdin);
		}while(medio != 'a' && medio != 'A' && 
			   medio != 't' && medio != 'T' && 
			   medio != 'b' && medio != 'B');

		do{
			printf("Menor de %d anios (S/N): ", EDAD_LIMITE);
			scanf("%c", &edad);
			fflush(stdin);
		}while(edad != 's' && edad != 'S' && edad != 'n' && edad != 'N');

		if (medio == 'A' || medio == 'a')
			importe_bruto = kilometros * COSTE_KM_AVION;
		else
			importe_bruto = kilometros * COSTE_KM_OTROS;

		printf("\nImporte bruto: %d euros", importe_bruto);

		if (edad == 's' || edad == 'S')
			descuento = DESCUENTO1 * importe_bruto;
		else
			if (medio != 'A' && medio != 'a')
				descuento = DESCUENTO2 * importe_bruto;

		if (kilometros > KILOMETROS_LIMITE)
			descuento += REBAJA;

		printf("\nDescuentos: %d euros", descuento);
		
		importe_neto = importe_bruto - descuento;
		
		printf("\nImporte factura: %d euros\n\n", importe_neto);

		acumulador_importe_facturas += importe_neto;

		if (importe_neto > factura_maxima)
			factura_maxima = importe_neto;

	}while(contador_viajes < numero_viajes);

	printf("\nVALOR MEDIO FACTURA = %d euros", acumulador_importe_facturas / contador_viajes);
	printf("\nVALOR MAXIMO FACTURA = %d euros\n\n", factura_maxima);
}