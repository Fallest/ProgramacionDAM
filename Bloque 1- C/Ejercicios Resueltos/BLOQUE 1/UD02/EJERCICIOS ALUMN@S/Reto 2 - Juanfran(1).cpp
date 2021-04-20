/*Realizar un programa que calcule el importe que la máquina 
de un parking le pide a un usuario del mismo cuando quiere salir. 
El programa deberá registrar la hora de entrada y la hora de salida 
(hora y minutos, de ambos), suponiendo que son del mismo día. 
La regla de cálculo del importe es la siguiente:

- Si los minutos transcurridos no son mas de 30, se cobra 0,50.
- En caso contrario, si son mas de 120, se cobra 0,08 euros por cada uno.
- En caso contrario, se cobra 0,50 euros, mas 0,10 euros por cada minuto que exceda de 30.
*/

#include <stdio.h>

#define TIEMPO_MINIMO 30
#define PRECIO_MINIMO 0.50
#define TIEMPO_MAXIMO 120
#define PRECIO_POR_TIEMPO_MAXIMO 0.08
#define PRECIO_EXTRA 0.10

void main()
{
	int hora_entrada;
	int hora_salida;
	int minutos_entrada;
	int minutos_salida;
	float precio = 0;
	int hora_total_entrada = 0;
	int hora_total_salida = 0;
	int tiempo = 0;

	
	do
	{
		printf("Introduzca la hora de llegada: ");
		scanf("%d", &hora_entrada);
		fflush(stdin);

	}while(hora_entrada < 0 || hora_entrada > 23);

	
	do
	{
		printf("Introduzca los minutos de llegada: ");
		scanf("%d", &minutos_entrada);
		fflush(stdin);

	}while(minutos_entrada < 0 || minutos_entrada > 59);

	hora_total_entrada = (hora_entrada * 60) + minutos_entrada;
	
	do
	{
		printf("Introduzca la hora de salida (no puede ser menor que la de entrada).\n\n");

		do
		{
			printf("Introduzca la hora de salida: ");
			scanf("%d", &hora_salida);
			fflush(stdin);

		}while(hora_salida < 0 || hora_salida > 23);

		do
		{
			printf("Introduzca los minutos de salida: ");
			scanf("%d", &minutos_salida);
			fflush(stdin);

		}while(minutos_salida < 0 || minutos_salida > 59);

		hora_total_salida = (hora_salida * 60) + minutos_salida;

	}while(hora_total_salida < hora_total_entrada);
	
	
	tiempo = hora_total_salida - hora_total_entrada;
	
	
	
	if(tiempo <= TIEMPO_MINIMO) 

		precio = PRECIO_MINIMO;
		
	else
		if(tiempo >= TIEMPO_MAXIMO)
		
			precio = tiempo * PRECIO_POR_TIEMPO_MAXIMO;

		else
			if(tiempo < TIEMPO_MINIMO && tiempo > TIEMPO_MAXIMO)
		
				precio = PRECIO_MINIMO * ((tiempo - TIEMPO_MINIMO) * (PRECIO_EXTRA));
		

	printf("El precio del parking es de %f euros.\n\n", precio );
}










