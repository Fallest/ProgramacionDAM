#include <stdio.h>


// PROTOTIPOS DE LAS FUNCIONES
float leer_precio();
float leer_descuento();
float calcular_descuento (float precio, float descuento);
char preguntar_si_seguir();


/*****************************************
************** PROGRAMA PRINCIPAL ********
*************************************** */
void main()
{
	// Declaración de variables:
	float precio;
	float descuento;
	float importe_descuento;
	char seguir;

	do{
		// Lectura de datos:
		precio = leer_precio();
		descuento = leer_descuento();

		// Calculo del importe a descontar:
		importe_descuento = calcular_descuento(precio, descuento);
	
		// Impresion del precio final:
		printf("El precio final del producto es de %.2f euros.\n\n",
			precio - importe_descuento);

		// Preguntar al usuario si desea continuar con otro producto:
		seguir = preguntar_si_seguir();
	}while(seguir == 's' || seguir == 'S');
}

/**********************************************
************* FUNCIONES ***********************
******************************************** */
char preguntar_si_seguir()
{
	char seguir;
	
	do{
		printf("Desea continuar con el siguiente producto (s/n)?: ");
		scanf("%c", &seguir);
		fflush(stdin);
	}while(seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N');
	
	return seguir;
}



float leer_precio()
{
	float precio;
	do{
		printf("Introduzca el precio del producto: ");
		scanf("%f", &precio);
		fflush(stdin);
	}while(precio <= 0);
	
	return precio;
}


float leer_descuento()
{
	float descuento;
	do{
		printf("Introduzca el porcentaje de descuento a aplicar al producto: ");
		scanf("%f", &descuento);
		fflush(stdin);
	}while(descuento <= 0 || descuento >= 100);
	
	return descuento;
}


float calcular_descuento (float precio, float descuento)
{
	return descuento * precio / 100;
}
