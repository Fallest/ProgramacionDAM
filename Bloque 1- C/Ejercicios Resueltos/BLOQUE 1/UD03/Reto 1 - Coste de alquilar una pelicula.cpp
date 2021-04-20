#include <stdio.h>


#define INCREMENTO_NOVEDAD 0.04
#define DIAS_LIMITE 3
#define IMPORTE_BASICO 1.20
#define IMPORTE_EXTRA 0.75


float pedir_saldo();
int dias_transcurridos (int d1, int m1, int d2, int m2);
int comparar_fechas (int d1, int m1, int d2, int m2);
void leer_fechas (int *d_ida, int *m_ida, int *d_vuelta, int *m_vuelta);
int comprobar_fecha (int d, int m);
char leer_novedad();
void mostrar_resultado (char saldo, float importe);


int comprobar_fecha (int d, int m)
{

  if ((d < 1) || (m < 1) || (m > 12) || (d > 30))
    return 0;
  else
    return 1;

}


int dias_transcurridos (int d1, int m1, int d2, int m2)
{

  if (m1 == m2)   // Si los meses coinciden, se restan los días.
    return d2 - d1;
  else            // Si no coinciden:
	  if (d2 >= d1) // Si el dia de devolucion es mayor o igual que el de recogida: resto meses y dias.
		return (m2 - m1) * 30 + (d2 - d1);
	  else          // Sumo: dias del mes de recogida que faltan para fin de mes,
		            //       dias del mes de devolucion,
					//       dias intermedios (entre meses).
		return (m2 - m1 - 1) * 30 + d2 + (30 - d1);

}


int comparar_fechas (int d1, int m1, int d2, int m2)
{

  if ((m2 > m1) || ((m2 == m1) && (d2 >= d1)))
    return 1;
  else
    return 0;

}


void leer_fechas (int *d_ida, int *m_ida, int *d_vuelta, int *m_vuelta)
{

  do{
    printf("Introduzca la fecha de recogida (dd/mm): ");
    scanf("%d/%d", d_ida, m_ida);
    fflush(stdin);
  }while (!comprobar_fecha (*d_ida, *m_ida));

  do{
    printf("Introduzca la fecha de devolucion (dd/mm): ");
    scanf("%d/%d", d_vuelta, m_vuelta);
    fflush(stdin);
  }while ( (!comprobar_fecha (*d_vuelta, *m_vuelta)) || 
	       (!comparar_fechas (*d_ida, *m_ida, *d_vuelta, *m_vuelta))
		 );

}


char leer_novedad()
{
	char n;
	do{
		printf("Es novedad (S/N)?: ");
		scanf("%c", &n);
		fflush(stdin);
	}while ((n != 's') && (n != 'S') && (n != 'n') && (n != 'N'));
	return n;
}


float pedir_saldo()
{
	float s;
	
	do{
		printf("Introduzca el saldo (no negativo): ");
		scanf("%f", &s);
		fflush(stdin);
	}while (s < 0);

	return s;
}


void mostrar_resultado (char saldo, float importe)
{
	if (saldo < importe)
		printf("\n\nNo se pudo devolver por falta de saldo.\n\n");
	else
		printf("\n\nPelicula devuelta. Saldo restante: %.2f euros.\n\n", saldo - importe);
}



float calcular_importe (char n, int d1, int m1, int d2, int m2)
{
	float importe;
	int dias = dias_transcurridos (d1, m1, d2, m2);

	if (dias == 0)
		importe = 0;
	else
		if (dias < DIAS_LIMITE)
			importe = IMPORTE_BASICO;
		else
			importe = dias * IMPORTE_EXTRA;

	if ((n == 's') || (n == 'S'))
		importe = importe + INCREMENTO_NOVEDAD * importe;
	
	return importe;
}


void main()
{
	float saldo = pedir_saldo();

	int mes_recogida, dia_recogida, mes_devolucion, dia_devolucion;

	leer_fechas (&dia_recogida, &mes_recogida, &dia_devolucion, &mes_devolucion);

	char novedad = leer_novedad();

	mostrar_resultado (saldo, calcular_importe(novedad, dia_recogida, mes_recogida, dia_devolucion, mes_devolucion));
}