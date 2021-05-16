#include <stdio.h>


// PROTOTIPOS DE LAS FUNCIONES
void leer_precio(float *precio);
void leer_descuento(float *descuento);
void calcular_descuento (float precio, float descuento, float *resultado);
void preguntar_si_seguir(char *seguir);


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
		leer_precio(&precio);
		leer_descuento(&descuento);

		// Calculo del importe a descontar:
		calcular_descuento(precio, descuento, &importe_descuento);
	
		// Impresion del precio final:
		printf("El precio final del producto es de %.2f euros.\n\n",
			precio - importe_descuento);

		// Preguntar al usuario si desea continuar con otro producto:
		preguntar_si_seguir(&seguir);
	}while(seguir == 's' || seguir == 'S');
}

/**********************************************
************* FUNCIONES ***********************
******************************************** */
void preguntar_si_seguir(char *seguir)
{
	do{
		printf("Desea continuar con el siguiente producto (s/n)?: ");
		scanf("%c", seguir);
		fflush(stdin);
	}while((*seguir) != 's' && (*seguir) != 'S' && (*seguir) != 'n' && (*seguir) != 'N');
}



void leer_precio(float *precio)
{
	do{
		printf("Introduzca el precio del producto: ");
		scanf("%f", precio);
		fflush(stdin);
	}while((*precio) <= 0);
}


void leer_descuento(float *descuento)
{
	do{
		printf("Introduzca el porcentaje de descuento a aplicar al producto: ");
		scanf("%f", descuento);
		fflush(stdin);
	}while((*descuento) <= 0 || (*descuento) >= 100);
}


void calcular_descuento (float precio, float descuento, float *resultado)
{
	(*resultado) = descuento * precio / 100;
}
