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
// DESCRIPCIÓN: Lee una fecha en formato dd/mm/aaaa.
// PARÁMETROS: dd   ==> Día de la fecha (E/S).
//             mm   ==> Mes de la fecha (E/S).
//             aaaa ==> Año de la fecha (E/S).
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
// DESCRIPCIÓN: Lee una fecha en formato dd/mm/aaaa.
// PARÁMETROS: dd   ==> Día de la fecha (E/S).
//             mm   ==> Mes de la fecha (E/S).
//             aaaa ==> Año de la fecha (E/S).
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
  printf("\nLa fecha introducida es incorrecta.\n");
  return 0;
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
// NOMBRE: dias_mes
// DESCRIPCIÓN: Recibe un mes y un año y devuelve los días que tiene ese mes.
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
// NOMBRE: diferencia_fechas
// DESCRIPCIÓN: Recibe las dos fechas (dd/mm/aaaa) y calcula los años, meses y días entre ellas.
// PARÁMETROS:  ==> .
// DEVUELVE: años, meses y días.
// **************************************************************************************** //

void diferencia_fechas (int dd_nac, int mm_nac, int aa_nac, int dd_act, int mm_act, int aa_act, int *anios, int *meses, int *dias)
{
	
// Se da por supuesto que la fecha de nacimneto es anterior ala fecha actual.

	if (aa_nac == aa_act) // si es el mismo año. 
	{
		(*anios) = 0; // no ha pasado 1 año entero.
		if (mm_act == mm_nac) //si es el mismo mes.
		{
			(*meses) = 0; // no ha pasado un mes entero.
			(*dias) = (dd_act - dd_nac); //han pasado sólo unos días.
		}
		else 
		{
			if ((mm_act == (mm_nac + 1)) && (dd_act < dd_nac)) // si mm_nac es el mes anterior a mm_act pero no ha pasado 1 mes.
			{
				(*meses) = 0; // no ha pasado un mes entero.
				(*dias) = ((dias_mes (mm_nac, aa_nac) - dd_nac) + dd_act); // los dias que faltan hasta final de mes desde el nacimiento más los que han pasado del actual.
			}
			else // si mm_nac es anterior, osea, hace más de 1 mes.
			{
				if (dd_act < dd_nac) // si no se cumplen meses completo.
				{
					(*meses) = (12 - mm_act + mm_nac - 1); // meses completos menos 1 (el mes parcial).
					(*dias) = ((dias_mes (mm_nac, aa_nac) - dd_nac) + dd_act); // los dias que faltan hasta final de mes desde el nacimiento más los que han pasado del actual.
				}
				else 
				{
					(*meses) = (mm_act - mm_nac); // meses completos.
					(*dias) = (dd_act - dd_nac); // dias que faltan hasta dd_nac.
				}
			}
		}
	}
	else // si el año de nacimnento es anterior a la fecha actual.
	{
		if ((mm_act < mm_nac) || ((mm_act == mm_nac) && (dd_act < dd_nac))) // si mm_nac es anterior a mm_act o el mismo mes pero dias antes, es un año incompleto.
		{
			(*anios) = (aa_act - aa_nac - 1); // años completos menos 1 (el año parcial).
			if (dd_act < dd_nac) // si no se cumplen meses completos.
			{
				(*meses) = (12 - mm_nac + mm_act - 1); // meses completos menos 1 (el mes parcial).
				(*dias) = ((dias_mes (mm_nac, aa_nac) - dd_nac) + dd_act); // los dias que faltan hasta final de mes más los que faltan hasta dd_act.
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
				(*dias) = ((dias_mes (mm_nac, aa_nac) - dd_nac) + dd_act); // los dias que faltan hasta final de mes más los que faltan hasta dd_act.
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
// DESCRIPCIÓN: improme la edad actual en años, meses y días.
// PARÁMETROS: anio, meses, dias ==> cçvalores a imprimir
// DEVUELVE: -
// **************************************************************************************** //

void imprimir_resultado (int anios, int meses, int dias)
{
	printf("\nEdad actual: %d años, %d meses, y %d dias.\n", anios, meses, dias);
	printf ("\n-------------------------------\n");
}

// **************************************************************************************** //
// PROGRAMA: calcula_edad_actual
// AUTOR: JM
// DESCRIPCIÓN: Realizar un programa que lea la fecha de nacimiento de una persona 
//              y la fecha y día actual, y  escriba la edad en años de la persona. 
//              Cada fecha estará compuesta por día, mes y año.
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
