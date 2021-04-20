#include <stdio.h>


// CONSTANTES
#define SI 1
#define NO 0


//PROTOTIPOS
void leer_fecha_nacimiento (int *dn, int *mn, int *an);
void leer_fecha_actual (int dn, int mn, int an, int *da, int *ma, int *aa);
void calcular_edad (int dn, int mn, int an, int da, int ma, int aa,
					int *dias, int *meses, int *anios);
int fecha_actual_no_posterior (int dn, int mn, int an, int da, int ma, int aa);
int bisiesto (int anio);
int comprueba_fecha (int dd, int mm, int aaaa);
int comprueba_anio (int a);
int comprueba_mes (int m);
int comprueba_dia (int d, int m, int a);
int dias_mes (int mes, int anio);


// FUNCIONES
void leer_fecha_nacimiento (int *dn, int *mn, int *an)
{
	int fecha_incorrecta;
	do{
		printf("Introduzca la fecha de nacimiento (dd/mm/aaaa): ");
		scanf("%d/%d/%d", dn, mn, an);
		fflush(stdin);

		if (!comprueba_fecha (*dn, *mn, *an))
		{
			printf("La fecha introducida es incorrecta.\n");
			fecha_incorrecta = SI;
		}
		else
			fecha_incorrecta = NO;
	}while (fecha_incorrecta);
}


void leer_fecha_actual (int dn, int mn, int an, int *da, int *ma, int *aa)
{
	int fecha_incorrecta;
	do{
		printf("Introduzca la fecha actual (dd/mm/aaaa): ");
		scanf("%d/%d/%d", da, ma, aa);
		fflush(stdin);

		if (!comprueba_fecha (*da, *ma, *aa))
		{
			printf("La fecha introducida es incorrecta.\n");
			fecha_incorrecta = SI;
		}
		else
			if (fecha_actual_no_posterior (dn, mn, an, *da, *ma, *aa))
			{
				printf("La fecha introducida es correcta pero no es posterior a la de nacimiento.\n");
				fecha_incorrecta = SI;
			}
			else
				fecha_incorrecta = NO;
	}while (fecha_incorrecta);
}


int fecha_actual_no_posterior (int dn, int mn, int an, int da, int ma, int aa)
{
	/*
	Casos no validos:
	1) El a�o actual es inferior al de nacimiento.
	2) Los a�os coinciden pero el mes actual es anterior al de nacimiento.
	3) Los a�os y los meses coinciden pero el dia actual es anterior al de nacimiento.
	*/
	if (
		(aa < an) ||
		((aa == an) && (ma < mn)) ||
		((aa == an) && (ma == mn) && (da < dn))
		)
		return SI;
	else
		return NO;
}


void calcular_edad (int dn, int mn, int an, int da, int ma, int aa,
					int *dias, int *meses, int *anios)
{
	/*
	Pasos a seguir:
	1) Restamos los a�os.
	2A) Si el mes actual es anterior al de nacimiento hay que:
		2A.1) Rectificar la resta anterior rest�ndole una unidad.
		2A.2) Calcular los meses de diferencia sin restarlos directamente.
		2A.3A) Si el dia actual es anterior al de nacimiento hay que:
			2A.3.1) Rectificar la resta de meses rest�ndole una unidad.
			2A.3.2) Calcular los dias de diferencia sin restarlos directamente.
		2A.3B) En caso contrario, restar los d�as directamente.
	2B) En caso contrario:
		2B.1) Restamos los meses.
		2B.2A) Si el dia actual es anterior al de nacimiento hay que:
			2B.2A.1) Rectificar la resta de meses rest�ndole una unidad.
			2B.2A.2) Calcular los dias de diferencia sin restarlos directamente.
		2B.2B) En caso contrario, restar los d�as directamente.
	*/

	*anios = aa - an; // 1)

	if (ma < mn) // 2A)
	{
		(*anios)--; // 2A.1)
		*meses = ma + (12 - mn); // 2A.2)

		if (da < dn) // 2A.3A)
		{
			(*meses)--; // 2A.3A.1)
			*dias = da + ((dias_mes (ma, aa) - dn)); // 2A.3A.2)
		}
		else // 2A.3B
			*dias = da - dn;
	}
	else // 2B)
	{
		*meses = ma - mn; // 2B.1)
		
		if (da < dn) //2B.2A)
		{
			(*meses)--; //2B.2A.1)
			*dias = da + ((dias_mes (ma, aa) - dn)); //2B.2A.2)
		}
		else // 2B.2B)
			*dias = da - dn;
	}
}


int comprueba_fecha (int dd, int mm, int aaaa)
{
  // Se hacen las validaciones en orden de dificultad, de menor a mayor coste:
  if (comprueba_anio (aaaa))

    if (comprueba_mes (mm))

      // Sabiendo que el a�o es una cantidad positiva y que el mes est� entre 1 y 12,
      // procedemos a comprobar si el d�a es correcto:
      if (comprueba_dia (dd, mm, aaaa))
        return SI;

  // Si el programa ha llegado hasta aqu� es porque no ha entrado en alguno de los "if"
  // anteriores, y por ello la fecha ser� falsa por alg�n motivo.
  return NO;
}


int comprueba_anio (int a)
{
  // La �nica comprobaci�n posible es si es una cantidad positiva:
  if (a <= 0)
    return NO;
  else
    return SI;
}


int comprueba_mes (int m)
{
  // La �nica comprobaci�n posible es si est� entre 1 y 12:
  if ((m < 1) || (m > 12))
    return NO;
  else
    return SI;
}


int comprueba_dia (int d, int m, int a)
{
  // Casos posibles para descartarlo como v�lido:
  // 1) Que sea menor que 1.
  // 2) Que sea mayor que el n�mero de d�as que tiene el mes.

  if ((d < 1) || (d > dias_mes (m, a)))
    return NO;
  else
    return SI;
}


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


int bisiesto (int anio)
{
  if ((anio % 4 == 0) && !((anio % 100 == 0) && (anio % 400 != 0)))
    return SI;
  else
    return NO;
}


// PROGRAMA PRINCIPAL
void main()
{
	int dnacimiento, mnacimiento, anacimiento;
	int dactual, mactual, aactual;
	int dias, meses, anios;

	leer_fecha_nacimiento (&dnacimiento, &mnacimiento, &anacimiento);
	leer_fecha_actual (dnacimiento, mnacimiento, anacimiento,
		&dactual, &mactual, &aactual);

	calcular_edad (dnacimiento, mnacimiento, anacimiento,
		dactual, mactual, aactual,
		&dias, &meses, &anios);

	printf("\n\nEdad actual: %d dias, %d meses, %d anios.\n\n",
		dias, meses, anios);
}
