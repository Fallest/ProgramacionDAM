#include <stdio.h>

//PROTOTIPOS
void leer_fecha_nacimiento (int *, int*, int *);
void leer_fecha_actual (int *, int*, int *);
int comprueba_fecha (int, int, int);
int comprueba_anio (int);
int comprueba_mes (int);
int comprueba_dia (int, int, int);
int dias_mes (int , int);
int bisiesto (int);
void diferencia_fechas (int, int, int, int, int, int, int*, int*, int*);
void imprimir_resultado (int, int, int);

//FUNCIONES

// **************************************************************************************** //
// NOMBRE: leer_fecha_nacimiento
// DESCRIPCI�N: Lee una fecha en formato dd/mm/aaaa.
// PAR�METROS: dd   ==> D�a de la fecha (E/S).
//             mm   ==> Mes de la fecha (E/S).
//             aaaa ==> A�o de la fecha (E/S).
// DEVUELVE: -
// **************************************************************************************** //

void leer_fecha_nacimiento (int *dd, int *mm, int *aaaa)
{
  printf ("\nIntroduzca la fecha de nacimiento (dd/mm/aaaa): ");
  scanf ("%d/%d/%d", dd, mm, aaaa);
  fflush (stdin);
}

// **************************************************************************************** //
// NOMBRE: leer_fecha_actual
// DESCRIPCI�N: Lee una fecha en formato dd/mm/aaaa.
// PAR�METROS: dd   ==> D�a de la fecha (E/S).
//             mm   ==> Mes de la fecha (E/S).
//             aaaa ==> A�o de la fecha (E/S).
// DEVUELVE: -
// **************************************************************************************** //

void leer_fecha_actual (int *dd, int *mm, int *aaaa)
{
  printf ("\nIntroduzca la fecha actual (dd/mm/aaaa): ");
  scanf ("%d/%d/%d", dd, mm, aaaa);
  fflush (stdin);
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
  printf("\nLa fecha introducida es incorrecta.\n");
  return 0;
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
// NOMBRE: dias_mes
// DESCRIPCI�N: Recibe un mes y un a�o y devuelve los d�as que tiene ese mes.
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
// NOMBRE: diferencia_fechas
// DESCRIPCI�N: Recibe las dos fechas (dd/mm/aaaa) y calcula los a�os, meses y d�as entre ellas.
// PAR�METROS:  ==> .
// DEVUELVE: a�os, meses y d�as.
// **************************************************************************************** //

void diferencia_fechas (int dd_nac, int mm_nac, int aa_nac, int dd_act, int mm_act, int aa_act, int *anios, int *meses, int *dias)
{
	
// Se da por supuesto que la fecha de nacimneto es anterior ala fecha actual.

	if (aa_nac == aa_act) // si es el mismo a�o. 
	{
		(*anios) = 0; // no ha pasado 1 a�o entero.
		if (mm_act == mm_nac) //si es el mismo mes.
		{
			(*meses) = 0; // no ha pasado un mes entero.
			(*dias) = (dd_act - dd_nac); //han pasado s�lo unos d�as.
		}
		else 
		{
			if ((mm_act == (mm_nac + 1)) && (dd_act < dd_nac)) // si mm_nac es el mes anterior a mm_act pero no ha pasado 1 mes.
			{
				(*meses) = 0; // no ha pasado un mes entero.
				(*dias) = ((dias_mes (mm_nac, aa_nac) - dd_nac) + dd_act); // los dias que faltan hasta final de mes desde el nacimiento m�s los que han pasado del actual.
			}
			else // si mm_nac es anterior, osea, hace m�s de 1 mes.
			{
				if (dd_act < dd_nac) // si no se cumplen meses completo.
				{
					(*meses) = (12 - mm_act + mm_nac - 1); // meses completos menos 1 (el mes parcial).
					(*dias) = ((dias_mes (mm_nac, aa_nac) - dd_nac) + dd_act); // los dias que faltan hasta final de mes desde el nacimiento m�s los que han pasado del actual.
				}
				else 
				{
					(*meses) = (mm_act - mm_nac); // meses completos.
					(*dias) = (dd_act - dd_nac); // dias que faltan hasta dd_nac.
				}
			}
		}
	}
	else // si el a�o de nacimnento es anterior a la fecha actual.
	{
		if ((mm_act < mm_nac) || ((mm_act == mm_nac) && (dd_act < dd_nac))) // si mm_nac es anterior a mm_act o el mismo mes pero dias antes, es un a�o incompleto.
		{
			(*anios) = (aa_act - aa_nac - 1); // a�os completos menos 1 (el a�o parcial).
			if (dd_act < dd_nac) // si no se cumplen meses completos.
			{
				(*meses) = (12 - mm_nac + mm_act - 1); // meses completos menos 1 (el mes parcial).
				(*dias) = ((dias_mes (mm_nac, aa_nac) - dd_nac) + dd_act); // los dias que faltan hasta final de mes m�s los que faltan hasta dd_act.
			}
			else 
			{
				(*meses) = (12 - mm_nac + mm_act); // meses completos.
				(*dias) = (dd_act - dd_nac); // dias que faltan hasta dd_nac.
			}
		}
		else 
		{
			(*anios) = (aa_act - aa_nac);
			if (dd_act < dd_nac) // si no se cumplen meses completos.
			{
				(*meses) = (mm_act - mm_nac - 1); // meses completos.
				(*dias) = ((dias_mes (mm_nac, aa_nac) - dd_nac) + dd_act); // los dias que faltan hasta final de mes m�s los que faltan hasta dd_act.
			}
			else 
			{
				(*meses) = (mm_act - mm_nac); // meses completos.
				(*dias) = (dd_act - dd_nac); // dias que faltan hasta dd_nac.
			}
		}
	}		
}

// **************************************************************************************** //
// NOMBRE: imprimir_resultado
// DESCRIPCI�N: improme la edad actual en a�os, meses y d�as.
// PAR�METROS: anio, meses, dias ==> c�valores a imprimir
// DEVUELVE: -
// **************************************************************************************** //

void imprimir_resultado (int anios, int meses, int dias)
{
	printf("\nEdad actual: %d a�os, %d meses, y %d dias.\n", anios, meses, dias);
	printf ("\n-------------------------------\n");
}

// **************************************************************************************** //
// PROGRAMA: calcula_edad_actual
// AUTOR: JM
// DESCRIPCI�N: Realizar un programa que lea la fecha de nacimiento de una persona 
//              y la fecha y d�a actual, y  escriba la edad en a�os de la persona. 
//              Cada fecha estar� compuesta por d�a, mes y a�o.
// VARIABLES: "dd_nac, mm_nac, aa_nac" ==> fecha de nacimiento, introdicida por el usuario.
//            "dd_act, mm_act, aa_act" ==> fecha actual, introdicida por el usuario.
//            "anios, meses, dias" ==> edad actual *diferencia entre las dos fechas  
// **************************************************************************************** //

int main()
{
	int dd_nac, mm_nac, aa_nac, dd_act, mm_act, aa_act, anios, meses, dias;
	
		
	do
		leer_fecha_nacimiento (&dd_nac, &mm_nac, &aa_nac);
	while (comprueba_fecha (dd_nac, mm_nac, aa_nac) != 1);

//PRUEBA
	printf("\nLa fecha de nacimiento es el %d del %d de %d.\n", dd_nac, mm_nac, aa_nac);

	do
		leer_fecha_actual (&dd_act, &mm_act, &aa_act);
	while (comprueba_fecha (dd_act, mm_act, aa_act) != 1);

// Lo que no se comprueba es que la fecha de nacimiento sea anterior a la fecha actual.

//PRUEBA
	printf("\nLa fecha actual es el %d del %d de %d.\n", dd_act, mm_act, aa_act);

	diferencia_fechas (dd_nac, mm_nac, aa_nac, dd_act, mm_act, aa_act, &anios, &meses, &dias);

	imprimir_resultado (anios, meses, dias);
}
