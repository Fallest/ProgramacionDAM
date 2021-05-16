#include <stdio.h>

//PROTOTIPOS
void intercambia (int *, int *);
int maximo_comun_divisor (int, int);
int abs (int);
void calcular_fraccion_final (int,int,int *,int *);
void calcular_suma (int,int,int,int,int *,int *);
void leer_fraccion (int *n, int *d, int numero);
void imprimir_resultado (int,int,int,int);


// FUNCIONES
void intercambia (int *num1, int *num2)
{
  int aux;

  aux = (*num2);
  (*num2) = (*num1);
  (*num1) = aux;
}


int maximo_comun_divisor (int n1, int n2)
{
  int aux;

  // Si el segundo es mayor que el primero, los intercambiamos
  if (n1 < n2)
    intercambia (&n1, &n2);

  // Si ambos números son divisibles por el inferior, entonces éste es el m.c.d.:
  if (n1 % n2 == 0)
    return n2;

  aux = n2 / 2;   // Se busca desde la mitad del número inferior.

  do{

    // Si ambos números son divisibles por aux entonces hemos encontrado el m.c.d.
    if ((n1 % aux == 0) && (n2 % aux == 0))
      return aux;
    else
      aux = aux - 1;   // Decrementamos el valor de aux.

  }while (aux != 1);

  // Si se ha llegado hasta aquí es porque no se ha encontrado m.c.d. (es 1):
  return 1;
}


int abs (int n)
{
  if (n < 0)
    return (-1) * n;
  else
    return n;
}


void calcular_fraccion_final (int nres, int dres, int *nres_simp, int *dres_simp)
{
  int mcd;

  mcd = maximo_comun_divisor (abs(nres), abs(dres));
  (*nres_simp) = nres / mcd;
  (*dres_simp) = dres / mcd;
}


void calcular_suma (int n1, int d1, int n2, int d2, int *nres, int *dres)
{
  (*nres) = (n1 * d2) + (n2 * d1);
  (*dres) = (d1 * d2);
}


void leer_fraccion (int *n, int *d, int numero)
{
  printf("Fraccion %d:\n", numero);
  printf("Introduzca el numerador: ");
  scanf("%d", n);
  fflush(stdin);
  
  do{
    printf("Introduzca el denominador: ");
    scanf("%d", d);
    fflush(stdin);
  }while ((*d) == 0);
}



void imprimir_resultado (int nres, int dres, int nres_simp, int dres_simp)
{
  printf("\n\nLa suma de ambas fracciones vale %d / %d\n", nres, dres);
  printf("La suma simplificada es de %d / %d\n", nres_simp, dres_simp);
}


// PROGRAMA PRINCIPAL
void main()
{
  int numerador1, denominador1, numerador2, denominador2; // Fracciones a sumar.
  int numer_res, denom_res;                               // Fracción suma.
  int numer_simp_res, denom_simp_res;                     // Fracción suma simplificada.

  leer_fraccion (&numerador1, &denominador1, 1);
  leer_fraccion (&numerador2, &denominador2, 2);
  calcular_suma (numerador1, denominador1, numerador2, denominador2, &numer_res, &denom_res);
  calcular_fraccion_final (numer_res, denom_res, &numer_simp_res, &denom_simp_res);
  imprimir_resultado (numer_res, denom_res, numer_simp_res, denom_simp_res);
}
