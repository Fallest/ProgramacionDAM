#include <stdio.h>

void main()
{
	int hh, mm, minutos_retraso;
	int acumulador_minutos_retraso = 0;
	int numero_retrasos = 0;
	int numero_aviones = 0;
	char seguir;

	do{
		numero_aviones++;

		do{
			printf("\nIntroduzca hh:mm de llegada del avion: ");
			scanf("%d:%d", &hh, &mm);
			fflush(stdin);
		}while(hh < 0 || hh > 23 || mm < 0 || mm > 59);

		do{
			printf("Introduzca el numero de minutos de llegada: ");
			scanf("%d", &minutos_retraso);
			fflush(stdin);
		}while(minutos_retraso < 0 || minutos_retraso > 1440);

		if (minutos_retraso != 0)
		{
			numero_retrasos++;
			acumulador_minutos_retraso += minutos_retraso;

			hh += minutos_retraso / 60;
			mm += minutos_retraso % 60;

			if (mm > 59)
			{
				mm = mm - 60;
				hh++;
			}

			if (hh > 23)
				hh = hh - 23;
		}

		printf("El avion llegara a las %02d:%02d\n", hh, mm);

		do{
			printf("Desea registrar otro avion (s/n)?: ");
			scanf("%c", &seguir);
			fflush(stdin);
		}while(seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N');
	}while(seguir == 's' || seguir == 'S');

	printf("\n\nSe han registrado %d retrasos.\n", numero_retrasos);
	printf("En promedio, los aviones se retrasan %.2f minutos.\n\n",
		(float)acumulador_minutos_retraso / numero_aviones);
}