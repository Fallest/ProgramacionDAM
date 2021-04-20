#include <stdio.h>


#define ESTABLECIMIENTO 0.12
#define MINUTO_NORMAL 0.06
#define MINUTO_EXTRA 0.10


void introducir_hora (int *hh, int *mm, char x);
int diferencia_horaria (int h1, int m1, int h2, int m2);
float calcular_coste (int m);


void introducir_hora (int *hh, int *mm, char x)
{
	do{
		printf("Introducir hora y minutos de ");
		if (x == 'i')
			printf("inicio de la llamada (hh:mm): ");
		else
			printf("fin de la llamada (hh:mm): ");
		scanf("%d:%d", hh, mm);
		fflush(stdin);
	}while (((*hh) < 0) || ((*hh) > 23) || ((*mm) < 0) || ((*mm) > 59));
}


int diferencia_horaria (int h1, int m1, int h2, int m2)
{
	int m;

	if (h1 <= h2)
		if (m1 <= m2)  // Ejemplo: De 12:20 a 14:35
			m = (m2 - m1) + (60 * (h2 - h1));
		else           // Ejemplo: De 12:20 a 14:10
			m = m2 + (60 - m1) + (60 * (h2 - h1 - 1));
	else
		if (m1 <= m2)  // Ejemplo: De 23:20 a 01:30
			m = (m2 - m1) + ((24 - h1) * 60) + (h2 * 60);
		else           // Ejemplo: De 23:20 a 01:10
			m = m2 + (60 - m1) + (24 - h1 - 1) * 60 + (h2 * 60);
		
	return m;
}


float calcular_coste (int m)
{
	float coste = ESTABLECIMIENTO; // Como minimo la llamada cuesta lo que vale el establecimiento.

	if (m > 60)
		coste = coste + (60 * MINUTO_NORMAL) + ((m - 60) * MINUTO_EXTRA);
	else
		coste = coste + (m * MINUTO_NORMAL);

	return coste;

}


void main()
{
	int hora_inicio, minuto_inicio, hora_fin, minuto_fin;  // Datos introducidos por el usuario.
	int minutos;                                           // Duración de la llamada.

	// Lectura de las dos cadenas horarias:
	introducir_hora (&hora_inicio, &minuto_inicio, 'i');
	introducir_hora (&hora_fin, &minuto_fin, 'f');
	
	// Calculo de los minutos transcurridos:
	minutos = diferencia_horaria (hora_inicio, minuto_inicio, hora_fin, minuto_fin);

	// Impresion del importe:
	printf("\nLa llamada ha durado %d minutos y el coste ha sido de %.2f euros.\n\n",
		minutos, calcular_coste (minutos));
}