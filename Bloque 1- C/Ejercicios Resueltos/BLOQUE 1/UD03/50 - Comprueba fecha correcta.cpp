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
// DESCRIPCI�N: Recibe un a�o verifica si es bisiesto.
// PAR�METROS: anio ==> A�o (E).
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
// DESCRIPCI�N: Recibe un mes y un a?o y devuelve los d�as que tiene ese mes.
// PAR�METROS: mes  ==> Mes (E).
//             anio ==> A�o (E).
// DEVUELVE: N�mero de d�as del mes.
// **************************************************************************************** //

int dias_mes (int mes, int anio)
{

  // Dependiendo del mes devuelve 30 d�as, 31 d�as, y si se trata de febrero
  // devuelve 28 d�as o 29 d�as dependiendo de si el a�o es bisiesto.

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
// DESCRIPCI�N: Recibe un dia de un mes y de un a�o y verifica si es correcto.
// PAR�METROS: d  ==> D�a (E).
//             m  ==> Mes (E).
//             a  ==> A�o (E).
// DEVUELVE: 1 si es v�lido, 0 si no lo es.
// **************************************************************************************** //

int comprueba_dia (int d, int m, int a)
{

  // Casos posibles para descartarlo como v�lido:
  // 1) Que sea menor que 1.
  // 2) Que sea mayor que el n�mero de d�as que tiene el mes.

  if ((d < 1) || (d > dias_mes (m, a)))
    return 0;
  else
    return 1;

}


// **************************************************************************************** //
// NOMBRE: comprueba_mes
// DESCRIPCI�N: Recibe un mes y devuelve si es v�lido.
// PAR�METROS: m  ==> Mes (E).
// DEVUELVE: 1 si es v�lido, 0 si no lo es.
// **************************************************************************************** //

int comprueba_mes (int m)
{

  // La �nica comprobaci�n posible es si est� entre 1 y 12:
  if ((m < 1) || (m > 12))
    return 0;
  else
    return 1;

}


// **************************************************************************************** //
// NOMBRE: comprueba_anio
// DESCRIPCI�N: Recibe un a�o y devuelve si es v�lido.
// PAR�METROS: a  ==> A�o (E).
// DEVUELVE: 1 si es v�lido, 0 si no lo es.
// **************************************************************************************** //

int comprueba_anio (int a)
{

  // La �nica comprobaci�n posible es si es una cantidad positiva:
  if (a <= 0)
    return 0;
  else
    return 1;

}


// **************************************************************************************** //
// NOMBRE: comprueba_fecha
// DESCRIPCI�N: Recibe una fecha y devuelve si es v�lida o no.
// PAR�METROS: dd   ==> D�a de la fecha (E).
//             mm   ==> Mes de la fecha (E).
//             aaaa ==> A�o de la fecha (E).
// DEVUELVE: 1 si es v�lida, 0 si no lo es.
// **************************************************************************************** //

int comprueba_fecha (int dd, int mm, int aaaa)
{

  // Se hacen las validaciones en orden de dificultad, de menor a mayor coste:
  if (comprueba_anio (aaaa))

    if (comprueba_mes (mm))

      // Sabiendo que el a�o es una cantidad positiva y que el mes est� entre 1 y 12,
      // procedemos a comprobar si el d�a es correcto:
      if (comprueba_dia (dd, mm, aaaa))
        return 1;

  // Si el programa ha llegado hasta aqu� es porque no ha entrado en alguno de los "if"
  // anteriores, y por ello la fecha ser� falsa por alg�n motivo.
  return 0;

}


// **************************************************************************************** //
// NOMBRE: leer_fecha
// DESCRIPCI�N: Lee una fecha en formato dd/mm/aaaa.
// PAR�METROS: dd   ==> D�a de la fecha (E/S).
//             mm   ==> Mes de la fecha (E/S).
//             aaaa ==> A�o de la fecha (E/S).
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
// DESCRIPCI�N: Imprime por pantalla si la fecha es correcta o no.
// PAR�METROS: valida ==> Fecha correcta o no, V o F respectivamente (E).
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
// VERSI�N: Noviembre 2010
// DESCRIPCI�N: Lee del usuario una fecha en formato dd/mm/aaaa e imprime si es correcta o no.
// VARIABLES: "dia", "mes", "anio" ==> Componentes de la fecha le�da del usuario.
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