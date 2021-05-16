#include <stdio.h>

//PROTOTIPOS
void acumular_cifras_pares (int,int,int *);
void quitar_cifra (int *);
int ultima_cifra (int);
int invertir_numero (int);
void leer_numero (int *);


// **************************************************************************************** //
// NOMBRE: acumular_cifras_pares
// DESCRIPCIÓN: Actualiza la suma si la cifra parámetro está en posición par.
// PARÁMETROS: cifra ==> cifra del número(E).
//             posicion ==> posición de la cifra en el número original, de der.a izq. (E).
//             suma ==> Acumulador de cifras de posición par (E/S)
// DEVUELVE: -
// **************************************************************************************** //

void acumular_cifras_pares (int cifra, int posicion, int *suma)
{

  if (posicion % 2 == 0)  // Si el indicador de posición es par:
    (*suma) = (*suma) + cifra;  // Acumulamos la cifra a la suma existente.

}


// **************************************************************************************** //
// NOMBRE: quitar_cifra
// DESCRIPCIÓN: Recibe como parámetro un número y devuelve el resultado de quitarle la cifra
//              más a la derecha.
// PARÁMETROS: n ==> Número (E/S).
// DEVUELVE: -
// **************************************************************************************** //

void quitar_cifra (int *n)
{

  *n = *n / 10;

}


// **************************************************************************************** //
// NOMBRE: ultima_cifra
// DESCRIPCIÓN: Recibe como parámetro un número y devuelve su cifra de las unidades.
// PARÁMETROS: n ==> Número (E).
// DEVUELVE: Cifra más a la derecha del número (unidades).
// **************************************************************************************** //

int ultima_cifra (int n)
{

  return (n % 10);

}


// **************************************************************************************** //
// NOMBRE: invertir_numero
// DESCRIPCIÓN: Recibe como parámetro el número original, va imprimiendo cifra a cifra 
//              el mismo número pero leído al revés y conforme lo va recorriendo acumula
//              el valor de las cifras pares.
// PARÁMETROS: n ==> Número introducido por el usuario (E).
// DEVUELVE: Suma de las cifras de posición par.
// **************************************************************************************** //

int invertir_numero (int n)
{

  int cont_cifras; // Marcará la posición de la cifra que se está extrayendo del número.
  int suma_pares;  // Acumulará la suma de las cifras de posición par.
  int ult_cifra;   // Será la cifra que se va extrayendo del número en cada iteración.

  printf ("El numero en orden inverso es el ");  // Cabecera del mensaje.

  cont_cifras = 0;
  suma_pares = 0;

  while (n > 0)  // El bucle recorrerá el número hasta quedar sin cifras:
  {
    ult_cifra = ultima_cifra (n);  // Se obtiene la cifra más a la derecha.
    cont_cifras++;                 // Se incrementa el indicador de posición.
    quitar_cifra (&n);             // Se quita la cifra más a la derecha del número.
    printf ("%d", ult_cifra);      // Se escribe esa cifra.
    acumular_cifras_pares (ult_cifra, cont_cifras, &suma_pares); // Se actualiza la suma.
  }

  return suma_pares;

}


// **************************************************************************************** //
// NOMBRE: leer_numero
// DESCRIPCIÓN: Lee un número introducido por el usuario. Repite la operación hasta que el
//              número candidato sea positivo.
// PARÁMETROS: n ==> Número introducido por el usuario (E/S).
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
// VERSIÓN: Noviembre 2010
// DESCRIPCIÓN: Imprime por pantalla el resultado de invertir las cifras de un número
//              previamente introducido por el usuario y muestra la suma de las cifras
//              con posiciones pares del número original (de derecha a izquierda)
// VARIABLES: "numero" ==> Contendrá el número original.
// **************************************************************************************** //

void main()
{
  int numero;
  leer_numero (&numero);
  printf("\nLa suma de las posiciones pares es de %d unidades.\n", invertir_numero (numero));
}