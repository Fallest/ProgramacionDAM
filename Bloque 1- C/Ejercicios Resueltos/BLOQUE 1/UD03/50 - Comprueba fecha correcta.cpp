#include <stdio.h>

//PROTOTIPOS
int bisiesto (int);
int dias_mes (int,int);
int comprueba_dia (int,int,int);
int comprueba_mes (int);
int comprueba_anio (int);
int comprueba_fecha (int,int,int);
void leer_fecha (int *,int *,int *);
void escribir_resultado (int);


// **************************************************************************************** //
// NOMBRE: bisiesto
// DESCRIPCIÓN: Recibe un año verifica si es bisiesto.
// PARÁMETROS: anio ==> Año (E).
// DEVUELVE: 1 si es bisiesto, 0 si no lo es.
// **************************************************************************************** //

int bisiesto (int anio)
{

  if ((anio % 4 == 0) && !((anio % 100 == 0) && (anio % 400 != 0)))
    return 1;
  else
    return 0;

}


// **************************************************************************************** //
// NOMBRE: dias_mes
// DESCRIPCIÓN: Recibe un mes y un a?o y devuelve los días que tiene ese mes.
// PARÁMETROS: mes  ==> Mes (E).
//             anio ==> Año (E).
// DEVUELVE: Número de días del mes.
// **************************************************************************************** //

int dias_mes (int mes, int anio)
{

  // Dependiendo del mes devuelve 30 días, 31 días, y si se trata de febrero
  // devuelve 28 días o 29 días dependiendo de si el año es bisiesto.

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
    case 2: if (bisiesto (anio))
              return 29;
            else
              return 28;
  }

}


// **************************************************************************************** //
// NOMBRE: comprueba_dia
// DESCRIPCIÓN: Recibe un dia de un mes y de un año y verifica si es correcto.
// PARÁMETROS: d  ==> Día (E).
//             m  ==> Mes (E).
//             a  ==> Año (E).
// DEVUELVE: 1 si es válido, 0 si no lo es.
// **************************************************************************************** //

int comprueba_dia (int d, int m, int a)
{

  // Casos posibles para descartarlo como válido:
  // 1) Que sea menor que 1.
  // 2) Que sea mayor que el número de días que tiene el mes.

  if ((d < 1) || (d > dias_mes (m, a)))
    return 0;
  else
    return 1;

}


// **************************************************************************************** //
// NOMBRE: comprueba_mes
// DESCRIPCIÓN: Recibe un mes y devuelve si es válido.
// PARÁMETROS: m  ==> Mes (E).
// DEVUELVE: 1 si es válido, 0 si no lo es.
// **************************************************************************************** //

int comprueba_mes (int m)
{

  // La única comprobación posible es si está entre 1 y 12:
  if ((m < 1) || (m > 12))
    return 0;
  else
    return 1;

}


// **************************************************************************************** //
// NOMBRE: comprueba_anio
// DESCRIPCIÓN: Recibe un año y devuelve si es válido.
// PARÁMETROS: a  ==> Año (E).
// DEVUELVE: 1 si es válido, 0 si no lo es.
// **************************************************************************************** //

int comprueba_anio (int a)
{

  // La única comprobación posible es si es una cantidad positiva:
  if (a <= 0)
    return 0;
  else
    return 1;

}


// **************************************************************************************** //
// NOMBRE: comprueba_fecha
// DESCRIPCIÓN: Recibe una fecha y devuelve si es válida o no.
// PARÁMETROS: dd   ==> Día de la fecha (E).
//             mm   ==> Mes de la fecha (E).
//             aaaa ==> Año de la fecha (E).
// DEVUELVE: 1 si es válida, 0 si no lo es.
// **************************************************************************************** //

int comprueba_fecha (int dd, int mm, int aaaa)
{

  // Se hacen las validaciones en orden de dificultad, de menor a mayor coste:
  if (comprueba_anio (aaaa))

    if (comprueba_mes (mm))

      // Sabiendo que el año es una cantidad positiva y que el mes está entre 1 y 12,
      // procedemos a comprobar si el día es correcto:
      if (comprueba_dia (dd, mm, aaaa))
        return 1;

  // Si el programa ha llegado hasta aquí es porque no ha entrado en alguno de los "if"
  // anteriores, y por ello la fecha será falsa por algún motivo.
  return 0;

}


// **************************************************************************************** //
// NOMBRE: leer_fecha
// DESCRIPCIÓN: Lee una fecha en formato dd/mm/aaaa.
// PARÁMETROS: dd   ==> Día de la fecha (E/S).
//             mm   ==> Mes de la fecha (E/S).
//             aaaa ==> Año de la fecha (E/S).
// DEVUELVE: -
// **************************************************************************************** //

void leer_fecha (int *dd, int *mm, int *aaaa)
{

  printf ("Fecha (DD MM AAAA): ");
  scanf ("%d %d %d", dd, mm, aaaa);
  fflush (stdin);

}


// **************************************************************************************** //
// NOMBRE: escribir_resultado
// DESCRIPCIÓN: Imprime por pantalla si la fecha es correcta o no.
// PARÁMETROS: valida ==> Fecha correcta o no, V o F respectivamente (E).
// DEVUELVE: -
// **************************************************************************************** //

void escribir_resultado (int valida)
{

  if (valida)
    printf("\nLa fecha es correcta.\n");
  else
    printf("\nLa fecha es incorrecta.\n");

}


// **************************************************************************************** //
// PROGRAMA: comprueba_fecha
// AUTOR: Miguel Carnerero Villaverde
// VERSIÓN: Noviembre 2010
// DESCRIPCIÓN: Lee del usuario una fecha en formato dd/mm/aaaa e imprime si es correcta o no.
// VARIABLES: "dia", "mes", "anio" ==> Componentes de la fecha leída del usuario.
//            "fecha_correcta" ==> Flag utilizado para almacenar si la fecha es correcta o no.
// **************************************************************************************** //

void main()
{

  int dia, mes, anio;
  int fecha_correcta;

  leer_fecha (&dia, &mes, &anio);
  fecha_correcta = comprueba_fecha (dia, mes, anio);
  escribir_resultado (fecha_correcta);

}