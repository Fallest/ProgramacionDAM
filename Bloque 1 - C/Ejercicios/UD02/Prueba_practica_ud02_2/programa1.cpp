#include <stdio.h>

void main()
{
	//declaracion de variables
	int hora_llegada, min_llegada, hora_retraso, min_retraso, tiempo_retraso, ejecucion = 0;
	int retrasos = 0;
	float promedio = 0;
	char conf;
	
	// Ciclo de ejecucion del programa
	do {
		//Lectura de datos
		printf("Introduzca la hora de llegada del vuelo: ");
		scanf("%d", &hora_llegada);
		fflush(stdin);
		printf("Introduzca los minutos de llegada del vuelo: ");
		scanf("%d", &min_llegada);
		fflush(stdin);
		printf("Introduzca los minutos de retraso: ");
		scanf("%d", &tiempo_retraso);
		fflush(stdin);

		// Calculos con los datos
		hora_retraso = (hora_llegada + ((min_llegada + tiempo_retraso) / 60)) % 24;
		min_retraso = (min_llegada + tiempo_retraso) % 60;

		if(tiempo_retraso != 0) {retrasos ++; promedio += tiempo_retraso;}
		
		// Mostrar retraso
		printf("El vuelo llegara a las %d:%d", hora_retraso, min_retraso);

		// Registrar otro retraso
		printf("\nDesea registrar otro avion (s/n)?: ");
		scanf("%c", &conf);
		fflush(stdin);

		if(conf != 's') { ejecucion = 1;}

	} while(ejecucion == 0);

	//Mostrar retrasos
	printf("\nSe han registrado %d retrasos.", retrasos);

	//Calcular y mostrar promedio
	promedio = promedio / retrasos;
	printf("\nEn promedio, los vuelos se retrasan %f minutos.", promedio);
}