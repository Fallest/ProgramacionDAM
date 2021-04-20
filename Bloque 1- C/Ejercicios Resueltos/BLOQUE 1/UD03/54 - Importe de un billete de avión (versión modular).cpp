#include <stdio.h>

//CONSTANTES
#define DISTANCIA_LIMITE 1000         // ... km.
#define IMPORTE_DISTANCIA_LIMITE 300  // ... euros.
#define IMPORTE_FUERA_LIMITE 0.35     // ... euros por km.
#define LIMITE_DIAS 7                 // ... dias entre ambas fechas.
#define DESCUENTO 0.60                // Si los vuelos se efectúan en menos de LIMITE_DIAS días.


//PROTOTIPOS
int comprobar_fecha (int,int);
int dias_transcurridos (int,int,int,int);
int comparar_fechas (int,int,int,int);
int dias_mes (int);
void leer_fechas (int *,int *,int *,int *);
void leer_distancia (int *);
void imprimir_resultado (float,float);
float calcular_importe (int,int,float *);


// FUNCIONES
int comprobar_fecha (int d, int m)
{
  // NOTA: No se contempla el caso de años bisiestos.
  if ((d < 1) || (m < 1) || (m > 12) || (d > dias_mes(m)))
    return 0;
  else
    return 1;
}


int dias_transcurridos (int d1, int m1, int d2, int m2)
{
  int acum, cont;

  // Si los meses coinciden, se restan los días:
  if (m1 == m2)

    return d2 - d1;

  else  // En este caso m2 > m1 porque las fechas están validadas.
  {
    acum = 0;

    // Acumulo los días de los meses que hay entre las dos fechas
    for (cont = m1+1; cont <= m2-1; cont++)
      acum = acum + dias_mes (cont);

    // Han transcurrido: los días acumulados + los días de la fecha de vuelta +
    //                   los días que le faltan al mes de ida para acabar.
    return (acum + d2 + (dias_mes(m1) - d1));
  }
}


int comparar_fechas (int d1, int m1, int d2, int m2)
{
  if ((m2 > m1) || ((m2 == m1) && (d2 >= d1)))
    return 1;
  else
    return 0;
}


int dias_mes (int mes)
{
  // Dependiendo del mes devuelve 28, 30 ó 31 días.
  switch (mes)
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
    case 2:  return 28;
  }
}


void leer_fechas (int *d_ida, int *m_ida, int *d_vuelta, int *m_vuelta)
{
  do{
    printf("Introduzca la fecha de ida (dd/mm): ");
    scanf("%d/%d", d_ida, m_ida);
    fflush(stdin);
  }while (!comprobar_fecha (*d_ida, *m_ida));

  do{
    printf("Introduzca la fecha de vuelta (dd/mm): ");
    scanf("%d/%d", d_vuelta, m_vuelta);
    fflush(stdin);
  }while ( (!comprobar_fecha (*d_vuelta, *m_vuelta)) || 
	       (!comparar_fechas (*d_ida, *m_ida, *d_vuelta, *m_vuelta))
		 );
}


void leer_distancia (int *d)
{
  // Se admiten solamente distancias positivas.
  do{
    printf("Introduzca la distancia en km: ");
    scanf("%d", d);
    fflush(stdin);
  }while ((*d) <= 0);
}


void imprimir_resultado (float ibruto, float descuento)
{
  printf("\nImporte bruto: %f\n", ibruto);
  printf("Descuento: %f\n", descuento);
  printf("Importe neto: %f\n", ibruto - descuento);
}


float calcular_importe (int km, int dias, float *desc)
{
  float ibruto;

  // Cálculo del importe en función de la distancia:
  if (km < DISTANCIA_LIMITE)
    ibruto = IMPORTE_DISTANCIA_LIMITE;
  else
    ibruto = km * IMPORTE_FUERA_LIMITE;

  // Cálculo del descuento aplicable:
  if (dias < LIMITE_DIAS)
    (*desc) = DESCUENTO * ibruto;
  else
    (*desc) = 0;

  return ibruto;
}


// PROGRAMA PRINCIPAL
void main()
{
  int distancia;
  float importe, descuento;
  int dia_ida, mes_ida, dia_vuelta, mes_vuelta;
  int dias;

  // Lectura de la distancia del viaje:
  leer_distancia (&distancia);

  // Lectura de las fechas de ida y vuelta (validadas):
  leer_fechas (&dia_ida, &mes_ida, &dia_vuelta, &mes_vuelta);

  // Cálculo de los días que transcurren entre ambas fechas:
  dias = dias_transcurridos (dia_ida, mes_ida, dia_vuelta, mes_vuelta);

  // Cálculo del importe del billete:
  importe = calcular_importe (distancia, dias, &descuento);

  // Escritura de los resultados:
  imprimir_resultado (importe, descuento);
}
