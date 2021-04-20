#include <stdio.h>

//PROTOTIPOS
void acumular_cifras_pares (int,int,int *);
void quitar_cifra (int *);
int ultima_cifra (int);
int invertir_numero (int);
void leer_numero (int *);


// **************************************************************************************** //
// NOMBRE: acumular_cifras_pares
// DESCRIPCI�N: Actualiza la suma si la cifra par�metro est� en posici�n par.
// PAR�METROS: cifra ==> cifra del n�mero(E).
//             posicion ==> posici�n de la cifra en el n�mero original, de der.a izq. (E).
//             suma ==> Acumulador de cifras de posici�n par (E/S)
// DEVUELVE: -
// **************************************************************************************** //

void acumular_cifras_pares (int cifra, int posicion, int *suma)
{

  if (posicion % 2 == 0)  // Si el indicador de posici�n es par:
    (*suma) = (*suma) + cifra;  // Acumulamos la cifra a la suma existente.

}


// **************************************************************************************** //
// NOMBRE: quitar_cifra
// DESCRIPCI�N: Recibe como par�metro un n�mero y devuelve el resultado de quitarle la cifra
//              m�s a la derecha.
// PAR�METROS: n ==> N�mero (E/S).
// DEVUELVE: -
// **************************************************************************************** //

void quitar_cifra (int *n)
{

  *n = *n / 10;

}


// **************************************************************************************** //
// NOMBRE: ultima_cifra
// DESCRIPCI�N: Recibe como par�metro un n�mero y devuelve su cifra de las unidades.
// PAR�METROS: n ==> N�mero (E).
// DEVUELVE: Cifra m�s a la derecha del n�mero (unidades).
// **************************************************************************************** //

int ultima_cifra (int n)
{

  return (n % 10);

}


// **************************************************************************************** //
// NOMBRE: invertir_numero
// DESCRIPCI�N: Recibe como par�metro el n�mero original, va imprimiendo cifra a cifra 
//              el mismo n�mero pero le�do al rev�s y conforme lo va recorriendo acumula
//              el valor de las cifras pares.
// PAR�METROS: n ==> N�mero introducido por el usuario (E).
// DEVUELVE: Suma de las cifras de posici�n par.
// **************************************************************************************** //

int invertir_numero (int n)
{

  int cont_cifras; // Marcar� la posici�n de la cifra que se est� extrayendo del n�mero.
  int suma_pares;  // Acumular� la suma de las cifras de posici�n par.
  int ult_cifra;   // Ser� la cifra que se va extrayendo del n�mero en cada iteraci�n.

  printf ("El numero en orden inverso es el ");  // Cabecera del mensaje.

  cont_cifras = 0;
  suma_pares = 0;

  while (n > 0)  // El bucle recorrer� el n�mero hasta quedar sin cifras:
  {
    ult_cifra = ultima_cifra (n);  // Se obtiene la cifra m�s a la derecha.
    cont_cifras++;                 // Se incrementa el indicador de posici�n.
    quitar_cifra (&n);             // Se quita la cifra m�s a la derecha del n�mero.
    printf ("%d", ult_cifra);      // Se escribe esa cifra.
    acumular_cifras_pares (ult_cifra, cont_cifras, &suma_pares); // Se actualiza la suma.
  }

  return suma_pares;

}


// **************************************************************************************** //
// NOMBRE: leer_numero
// DESCRIPCI�N: Lee un n�mero introducido por el usuario. Repite la operaci�n hasta que el
//              n�mero candidato sea positivo.
// PAR�METROS: n ==> N�mero introducido por el usuario (E/S).
// DEVUELVE: -
// **************************************************************************************** //

void leer_numero (int *n)
{

  do{
    printf("Introduzca el numero: ");
    scanf("%d", n);
    fflush(stdin);
  }while ((*n) < 1);

}


// **************************************************************************************** //
// PROGRAMA: invertir_numero
// AUTOR: Miguel Carnerero Villaverde
// VERSI�N: Noviembre 2010
// DESCRIPCI�N: Imprime por pantalla el resultado de invertir las cifras de un n�mero
//              previamente introducido por el usuario y muestra la suma de las cifras
//              con posiciones pares del n�mero original (de derecha a izquierda)
// VARIABLES: "numero" ==> Contendr� el n�mero original.
// **************************************************************************************** //

void main()
{
  int numero;
  leer_numero (&numero);
  printf("\nLa suma de las posiciones pares es de %d unidades.\n", invertir_numero (numero));
}