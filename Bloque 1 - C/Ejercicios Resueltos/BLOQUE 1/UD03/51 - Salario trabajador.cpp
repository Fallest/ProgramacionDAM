#include <stdio.h>

#define TARIFA_ORDINARIA 12      // ...  euros por hora.
#define RAZON_HORAS_EXTRAS 1.5   //  ... veces la tarifa ordinaria.
#define LIMITE_HORAS 38          // A partir de 38 se cobran horas extras.
#define TRAMO1_IMPUESTOS 200     // Los primeros 200 euros.
#define TRAMO2_IMPUESTOS 300     // Los siguientes 300 euros.
#define TIPO2_IMPUESTOS 0.25     // Tasa aplicable al tramo 2.
#define TIPO3_IMPUESTOS 0.45     // Tasa aplicable por encima del tramo 2.

//PROTOTIPOS
float calcula_impuestos (float);
float calcula_salario_horas (int);
float calcular_salario (int,float *);
void escribir_resultados (int,int,float,float);
void leer_horas (int *);
void leer_opcion (char *);
void leer_codigo (int *);


// **************************************************************************************** //
// NOMBRE: calcula_impuestos
// DESCRIPCI�N: Calcula la cantidad a retener al empleado a cuenta de impuestos.
// PAR�METROS: sal ==> Salario bruto del empleado (E).
// DEVUELVE: Cantidad a retener.
// **************************************************************************************** //

float calcula_impuestos (float sal)
{

  // Si gana menos de TRAMO1_IMPUESTOS euros, no paga impuestos:
  if (sal < TRAMO1_IMPUESTOS)

    return 0;

  else

    // Si gana entre TRAMO1 y TRAMO2, se le retiene el TIPO2:
    if (sal < TRAMO2_IMPUESTOS)

      return (sal - TRAMO1_IMPUESTOS) * TIPO2_IMPUESTOS;

    else

      // Si gana m�s del TRAMO2, se le retiene el TIPO2 y el TIPO3:
      return ((TRAMO2_IMPUESTOS * TIPO2_IMPUESTOS)   +
              ((sal - TRAMO1_IMPUESTOS - TRAMO2_IMPUESTOS) * TIPO3_IMPUESTOS));

}


// **************************************************************************************** //
// NOMBRE: calcula_salario_horas
// DESCRIPCI�N: Calcula el salario semanal del empleado correspondiente a las horas que
//              ha trabajado.
// PAR�METROS: h ==> N�mero de horas (E).
// DEVUELVE: Salario bruto del empleado.
// **************************************************************************************** //

float calcula_salario_horas (int h)
{

  if (h <= LIMITE_HORAS)
    return h * TARIFA_ORDINARIA;
  else
    return ((LIMITE_HORAS * TARIFA_ORDINARIA) + 
            ((h - LIMITE_HORAS) * TARIFA_ORDINARIA * RAZON_HORAS_EXTRAS));

}


// **************************************************************************************** //
// NOMBRE: calcular_salario
// DESCRIPCI�N: Calcula el salario semanal del empleado.
// PAR�METROS: h ==> N�mero de horas (E).
//             i ==> Retenci�n de impuestos (E/S).
// DEVUELVE: Salario bruto del empleado.
// **************************************************************************************** //

float calcular_salario (int h, float *i)
{

  float salario;

  salario = calcula_salario_horas (h);
  (*i) = calcula_impuestos (salario);
  return salario;

}


// **************************************************************************************** //
// NOMBRE: escribir_resultados
// DESCRIPCI�N: Imprime los resultados del programa.
// PAR�METROS: cod   ==> C�digo del empleado (E).
//             horas ==> N�mero de horas (E).
//             sal   ==> Salario bruto (E).
//             imp   ==> Retenci�n de impuestos (E).
// DEVUELVE: -
// **************************************************************************************** //

void escribir_resultados (int cod, int horas, float sal, float imp)
{

  printf ("\nSalario bruto (%d horas) = %f euros.\n", horas, sal);
  printf ("Impuestos: %f euros.\n", imp);
  printf ("Salario neto del empleado %d: %f euros.\n", cod, sal - imp);

}


// **************************************************************************************** //
// NOMBRE: leer_horas
// DESCRIPCI�N: Lee el n?mero de horas semanales que ha trabajado el empleado.
// PAR�METROS: h ==> N�mero de horas (E/S).
// DEVUELVE: -
// **************************************************************************************** //

void leer_horas (int *h)
{

  do{
    printf("Introduzca el numero de horas: ");
    scanf ("%d", h);
    fflush (stdin);
  }while ((*h) <= 0);

}


// **************************************************************************************** //
// NOMBRE: leer_opcion
// DESCRIPCI�N: Lee si el usuario desea continuar con otro empleado o salir.
// PAR�METROS: o ==> S si desea continuar, N si desea salir.
// DEVUELVE: -
// **************************************************************************************** //

void leer_opcion (char *o)
{

  do{
    printf("\nDesea continuar con el siguiente empleado (s/n)?: ");
    scanf("%c", o);
    fflush (stdin);
	printf("\n\n");
  }while ((*o != 's') && (*o != 'S') && (*o != 'n') && (*o != 'N'));

}


// **************************************************************************************** //
// NOMBRE: leer_codigo
// DESCRIPCI�N: Lee el c�digo del empleado.
// PAR�METROS: c ==> C�digo del empleado (E/S).
// DEVUELVE: -
// **************************************************************************************** //

void leer_codigo (int *c)
{

  // Validamos que sea positivo (no se indica pero parece razonable):
  do{
    printf ("Introduzca el codigo del empleado: ");
    scanf ("%d", c);
    fflush (stdin);
  }while ((*c) <= 0);

}


// **************************************************************************************** //
// PROGRAMA: salario_horas
// AUTOR: Miguel Carnerero Villaverde
// VERSI�N: Noviembre 2011
// DESCRIPCI�N: Lee del usuario el c�digo de un empleado y el n?mero de horas semanales que
//              ha trabajado y devuelve su salario.
// VARIABLES: "codigo"    ==> C�digo del empleado, le�do del usuario.
//            "horas"     ==> N�mero de horas semanales de su jornada, le�do del usuario.
//            "salario"   ==> Salario del empleado, calculado por el programa.
//            "impuestos" ==> Impuestos a retener al empleado, calculado por el programa.
// **************************************************************************************** //

void main()
{

  int codigo;
  int horas;
  float salario;
  float impuestos;
  char op;

  do{

    leer_codigo (&codigo);
    leer_horas (&horas);
    salario = calcular_salario (horas, &impuestos);
    escribir_resultados (codigo, horas, salario, impuestos);

    leer_opcion (&op);

  }while ((op == 's') || (op == 'S'));

}