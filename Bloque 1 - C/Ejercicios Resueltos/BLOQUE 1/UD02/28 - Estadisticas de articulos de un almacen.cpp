#include <stdio.h>

void main()
{
    // Variables para la lectura de datos:
	char categoria;
	float precio;
	int n_articulos;
	
	// Variables estadisticas:
	int cont_a = 0, cont_b = 0;           // Contadores de art�culos
	int cont_unid_a = 0, cont_unid_b = 0; // Acumuladores de unidades
	float importe_a = 0, importe_b = 0;     // Acumuladores de importes

	

	// Lectura de art�culos hasta que el usuario introduzca categor�a X:
	do{
		do{
			printf("\n\nIntroduzca la categoria (A o B, X para salir): ");
			scanf("%c", &categoria);
			fflush(stdin);
		}while ((categoria != 'a') && (categoria != 'A') && (categoria != 'b') &&
			    (categoria != 'B') && (categoria != 'x') && (categoria != 'X'));

		if ((categoria != 'x') && (categoria != 'X'))  // Si el articulo es de categoria A o B:
		{
			// Validaci�n del precio unitario:
			do{
				printf("Introduzca el precio unitario: ");
				scanf("%f", &precio);
				fflush(stdin);
			}while (precio <= 0);

			// Validaci�n del n�mero de art�culos:
			do{
				printf("Introduzca el numero de articulos: ");
				scanf("%d", &n_articulos);
				fflush(stdin);
			}while (n_articulos <= 0);

			if ((categoria == 'a') || (categoria == 'A'))
			{
				cont_a++; // Contamos un art�culo m�s a la categor�a A
				cont_unid_a = cont_unid_a + n_articulos; // A�adimos el n�mero de unidades de este art�culo a la cuenta
				importe_a = importe_a + (n_articulos * precio);  // Acumulamos el importe al total que llevemos
			}
			else  // �dem para la categor�a B
			{
				cont_b++;
				cont_unid_b = cont_unid_b + n_articulos; // A�adimos el n�mero de unidades de este art�culo a la cuenta
				importe_b = importe_b + (n_articulos * precio);
			}
		}
	}while ((categoria != 'x') && (categoria != 'X'));

	// Impresion de estadisticas:
	printf("\nSe han registrado %d articulos de categoria A (%d unidades) por un importe total de %f.\n",
		cont_a, cont_unid_a, importe_a);
	printf("Se han registrado %d articulos de categoria B (%d unidades) por un importe total de %f.\n",
		cont_b, cont_unid_b, importe_b);

	// Mejora: Mensajeria asociada a no existir articulos de alguna de las categorias.
}