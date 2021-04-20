#include <stdio.h>

int calcular_duracion(int h_inicio, int min_inicio, 
					  int h_fin, int min_fin);
float calcular_importe(int duracion);

void main() 
{
	// Declaracion de variables
	int duracion, h_inicio, min_inicio, h_fin, min_fin;
	float importe;

	// Lectura de datos
	do {
		printf("Por favor, inserte la hora y minuto de inicio de la llamada: ");
		scanf("%d:%d", &h_inicio, &min_inicio);
		fflush(stdin);

		printf("Por favor, inserte la hora y minuto de fin de la llamada: ");
		scanf("%d:%d", &h_fin, &min_fin);
		fflush(stdin);
	} while((h_inicio < 0) || (min_inicio < 0)
		|| (h_fin < 0) || (min_fin < 0) 
		|| (h_inicio > 23) || (h_fin > 23) 
		|| (min_inicio > 60) || (min_fin > 60));

	duracion = calcular_duracion(h_inicio, min_inicio, h_fin, min_fin);
	importe = calcular_importe(duracion);

	printf("La duracion de la llamada es %d minutos, y el importe es %g euros.\n", duracion, importe);
}

int calcular_duracion(int h_inicio, int min_inicio, 
					  int h_fin, int min_fin)
{
	// Declaracion de variables formales
	int duracion;

	// Calculo de la duracion de la llamada
	if(h_fin < h_inicio) {duracion = ((24 * 60) - (((h_inicio) * 60) + min_inicio)) +  (((h_fin) * 60) + min_fin);}
	else {duracion = (((h_fin) * 60) + min_fin) - (((h_inicio) * 60) + min_inicio);}
	return duracion;
}


float calcular_importe(int duracion)
{
	// Declaracion de variables formales
	float coste_base = (float) 0.12, coste_min = (float) 0.06, coste_min_hora = (float) 0.10, importe;

	// Calculo del importe
	switch (duracion / 60)
	{
	case 0:
		{
			importe = coste_base + (coste_min * duracion);
			break;
		}
	default:
		{
			importe = coste_base + (coste_min_hora * duracion);
			break;
		}
	}

	return importe;
}