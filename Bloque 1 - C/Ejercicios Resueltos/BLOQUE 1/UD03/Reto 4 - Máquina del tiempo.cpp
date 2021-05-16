// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>


// CONSTANTES


// PROTOTIPOS
char desea_continuar ();
char avanzar_retroceder ();
int diferencia_dias ();
int diferencia_minutos ();
void pedir_fecha (int *dd, int *mm, int *aaaa);
void pedir_hora (int *hh, int *mm);
int hora_valida (int hh, int mm);
int dias_mes (int mm, int aaaa);
int fecha_valida (int dd, int mm, int aaaa);
void calcular_nueva_fecha (int *dd, int *mm, int *aaaa, int dd_dif, char dd_movimiento);
void calcular_nueva_hora (int *dd, int *mm, int *aaaa, int *hh, int *mi, int mi_dif, char mi_movimiento);
void calcular_nueva_fecha_hora (int *dd, int *mm, int *aaaa, int *hh, int *mi, int dd_dif, int mm_dif, char dd_movimiento, char mm_movimiento);
void adelantar_un_dia (int *dd, int *mm, int *aaaa);
void retrasar_un_dia (int *dd, int *mm, int *aaaa);
void adelantar_un_minuto (int *hh, int *mi, int *dd, int *mm, int *aaaa);
void retrasar_un_minuto (int *hh, int *mi, int *dd, int *mm, int *aaaa);


// FUNCIONES
char desea_continuar ()
{
	char respuesta;
	
	do{
		printf("\nDesea continuar (s/n): ");
		scanf("%c", &respuesta);
		fflush(stdin);
	} while ((respuesta != 's') && (respuesta != 'n') && (respuesta != 'S') && (respuesta != 'N'));
	
	return respuesta;
}


char avanzar_retroceder ()
{
	char respuesta;
	
	do{
		printf("Desea avanzar o retroceder en el tiempo (a/r): ");
		scanf("%c", &respuesta);
		fflush(stdin);
	} while ((respuesta != 'a') && (respuesta != 'r') && (respuesta != 'A') && (respuesta != 'R'));
	
	return respuesta;
}


int diferencia_dias ()
{
	int respuesta;
	
	do{
		printf("\nCuantos dias desea desplazarse en el tiempo: ");
		scanf("%d", &respuesta);
		fflush(stdin);
	} while (respuesta < 0);
	
	return respuesta;	
}


int diferencia_minutos ()
{
	int respuesta;
	
	do{
		printf("Cuantos minutos desea desplazarse en el tiempo: ");
		scanf("%d", &respuesta);
		fflush(stdin);
	} while (respuesta < 0);
	
	return respuesta;	
}


int es_bisiesto (int anio)
{
	if ((anio%4 == 0) && !((anio%100 == 0) && (anio%400 != 0)))
		return 1;
	else
		return 0;
}


void pedir_fecha (int *dd, int *mm, int *aaaa)
{
	do{
		printf("Introduzca la fecha actual (dd/mm/yyyy): ");
		scanf("%d/%d/%d", dd, mm, aaaa);
		fflush(stdin);
	}while(!fecha_valida (*dd, *mm, *aaaa));
}


void pedir_hora (int *hh, int *mm)
{
	do{
		printf("Introduzca la hora actual (hh:mm): ");
		scanf("%d:%d", hh, mm);
		fflush(stdin);
	}while(!hora_valida (*hh, *mm));
}


int fecha_valida (int dd, int mm, int aaaa)
{
	// La fecha será válida si el día está en 1-dias_mes, el mes está en 1-12 y el año es positivo.
	if (dd < 1 || mm < 1 || mm > 12 || aaaa <= 0 || dd > dias_mes (mm, aaaa))
		return 0;
	else
		return 1;
}


int dias_mes (int mm, int aaaa)
{
	switch (mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31;
	case 4:
	case 6:
	case 9:
	case 11: return 30;
	case 2: if (es_bisiesto(aaaa))
				return 29;
		    else
				return 28;
	}

	return 0;  // Ficticio (evita warning).
}


int hora_valida (int hh, int mm)
{
	// La fecha será correcta si la hora está en 0-23 y los minutos en 0-59.
	if (hh > 23 || hh < 0 || mm > 59 || mm < 0)
		return 0;
	else
		return 1;
}


void adelantar_un_dia (int *dd, int *mm, int *aaaa)
{
	(*dd)++;										// Sumamos un día a la fecha.
	
	if ((*dd)> dias_mes (*mm, *aaaa))				// Si el dato original era el último día de ese mes:
	{
		(*dd) = 1;									// Ponemos a 1 el día (del mes siguiente).
		(*mm)++;									// Sumamos uno al mes.
		
		if ((*mm) == 13)							// Si el dato original era diciembre:
		{
			(*mm) = 1;								// Enero ...		
			(*aaaa)++;								// ... del año siguiente.
		}
	}
}


void retrasar_un_dia (int *dd, int *mm, int *aaaa)
{
	(*dd)--;										// Restamos un día a la fecha.
	
	if ((*dd) == 0)									// Si el dato original era el día 1:
	{
		if ((*mm) == 1)								// Si el mes original era enero:
		{
			(*mm) = 12;								// Diciembre ...
			(*aaaa)--;								// ... del año anterior.
		}
		else
			(*mm)--;								// Si el mes original no era enero, restamos uno al mes.

		(*dd) = dias_mes (*mm, *aaaa);				// En todo caso, poner como día de la fecha el último día del nuevo mes fijado.
	}
}


void calcular_nueva_fecha (int *dd, int *mm, int *aaaa, int dd_dif, char dd_movimiento)
{
	// Cambiamos la fecha dd_dif veces, adelantandola o retrasandola un día en cada iteración.
	for (int i = 1; i <= dd_dif; i++)
		if (dd_movimiento == 'a' || dd_movimiento == 'A')
			adelantar_un_dia (dd, mm, aaaa);
		else
			retrasar_un_dia (dd, mm, aaaa);
}


void adelantar_un_minuto (int *hh, int *mi, int *dd, int *mm, int *aaaa)
{
	(*mi)++;									// Sumamos un minuto.
	
	if ((*mi) == 60)							// Si el dato original era mi = 59:
	{
		(*mi) = 0;								// Ponemos los minutos a 0 (de la hora siguiente).
		(*hh)++;								// Sumamos una hora.
	
		if ((*hh) == 24)						// Si el dato original era hh = 23:
		{
			(*hh) = 0;							// Ponemos la hora a 0 (del día siguiente).
			adelantar_un_dia (dd, mm, aaaa);	// Adelantamos un día la fecha.
		}
	}
}


void retrasar_un_minuto (int *hh, int *mi, int *dd, int *mm, int *aaaa)
{
	(*mi)--;									// Quitamos un minuto.
	
	if ((*mi) == -1)							// Si el dato original era mi = 0:
	{
		(*mi) = 59;								// Ponemos los minutos a 59 (de la hora anterior).
		(*hh)--;								// Quitamos una hora.
	
		if ((*hh) == -1)						// Si el dato original era hh = 0:
		{
			(*hh) = 23;							// Ponemos la hora a 23 (del día anterior).
			retrasar_un_dia (dd, mm, aaaa);		// Retrasamos un día la fecha.
		}
	}
}


void calcular_nueva_hora (int *dd, int *mm, int *aaaa, int *hh, int *mi, int mi_dif, char mi_movimiento)
{
	// Cambiamos la hora mi_dif veces, adelantandola o retrasandola un minuto en cada iteración.
	for (int i = 1; i <= mi_dif; i++)
		if (mi_movimiento == 'a' || mi_movimiento == 'A')
			adelantar_un_minuto (hh, mi, dd, mm, aaaa);
		else
			retrasar_un_minuto (hh, mi, dd, mm, aaaa);
}


void calcular_nueva_fecha_hora (int *dd, int *mm, int *aaaa, int *hh, int *mi, int dd_dif, int mi_dif, char dd_movimiento, char mi_movimiento)
{
	// Cambiamos la fecha.
	calcular_nueva_fecha (dd, mm, aaaa, dd_dif, dd_movimiento);
	
	// Cambiamos la hora.
	// Al adelantar o retrasar la hora puede que haya que modificar la fecha,
	// por eso se pasa la fecha como parámetro por referencia.
	calcular_nueva_hora (dd, mm, aaaa, hh, mi, mi_dif, mi_movimiento); 
		
}


void mostrar_nueva_fecha_hora (int dd, int mm, int aaaa, int hh, int mi)
{
	printf("\nLos datos tras el desplazamiento son: %d/%d/%d - %d:%d\n", dd, mm, aaaa, hh, mi);
}



/* ***********************************************************************
************************* PROGRAMA PRINCIPAL *****************************
*********************************************************************** */
void main()
{
	int dd, mm, aaaa;
	int hh, mi;
	char respuesta;
	int dd_dif, mi_dif;
	char dd_movimiento, mi_movimiento;

	// PEDIR DATOS INICIALES:
	pedir_fecha (&dd, &mm, &aaaa);
	pedir_hora (&hh, &mi);

	do{
		// PEDIR DATOS DEL DESPLAZAMIENTO:
		dd_dif = diferencia_dias();
		dd_movimiento = avanzar_retroceder();
		mi_dif = diferencia_minutos();
		mi_movimiento = avanzar_retroceder();
		
		calcular_nueva_fecha_hora (&dd, &mm, &aaaa, &hh, &mi, dd_dif, mi_dif, dd_movimiento, mi_movimiento);
		
		mostrar_nueva_fecha_hora (dd, mm, aaaa, hh, mi);
		
		respuesta = desea_continuar();
		system("CLS");
	}while (respuesta == 's' || respuesta == 'S');
	
}
