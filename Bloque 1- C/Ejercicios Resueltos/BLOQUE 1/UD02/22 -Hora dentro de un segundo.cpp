#include <stdio.h>

void main()
{
	// Declaracion de variables
	int hh, mm, ss;

	// Lectura de datos:
	/*
	do{
		printf("Introduzca la hora inicial (hh/mm/ss): ");
		scanf("%d/%d/%d", &hh, &mm, &ss);
		fflush(stdin);
	}while (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59);
	*/
	
	do{
		printf("Introduzca la hora (0-23): ");
		scanf("%d", &hh);
		fflush(stdin);
	}while(hh < 0 || hh > 23);

	do{
		printf("Introduzca los minutos (0-59): ");
		scanf("%d", &mm);
		fflush(stdin);
	}while(mm < 0 || mm > 59);

	do{
		printf("Introduzca los segundos (0-59): ");
		scanf("%d", &ss);
		fflush(stdin);
	}while(ss < 0 || ss > 59);
	
	ss++;

	if (ss == 60)
	{
		ss = 0;
		mm++;
		
		if (mm == 60)
		{
			mm = 0;
			hh++;

			if (hh == 24)
				hh = 0;
		}
	}

	printf("La hora nueva es %02d:%02d:%02d.\n\n", hh, mm, ss);

}