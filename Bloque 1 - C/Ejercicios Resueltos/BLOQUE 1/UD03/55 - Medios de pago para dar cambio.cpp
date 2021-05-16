#include <stdio.h>

//PROTOTIPOS
void calcula_cuantos (int *,int,char);
void calcular_cambio (int);
void leer_pago (int,int *);
void leer_deuda (int *);


// FUNCIONES
void calcula_cuantos (int *cambio, int medio, char tipo)
{
  // Se escribe el número de monedas o billetes de ese medio que "caben" en el cambio.
  if (tipo == 'B')
    printf("\nBilletes de %d euros: %d\n", medio, (*cambio) / medio);
  else
    // Si son monedas, distingo entre las de 1 y las de 2 euros.
    if (medio == 2)
      printf("\nMonedas de %d euros: %d\n", medio, (*cambio) / medio);
    else
      printf("\nMonedas de %d euro: %d\n", medio, (*cambio) / medio);

  // El nuevo cambio será el resto de dividir el cambio por el billete o moneda, es decir, lo
  // que sobra al canjear los billetes o monedas del medio indicado.
  (*cambio) = (*cambio) % medio;
}


void calcular_cambio (int cambio)
{
  printf("\nCambio: %d euros.\n", cambio);

  if (cambio == 0)
    printf("\nImporte exacto. No hay cambio.\n");
  else
  {
    if (cambio >= 500)
      calcula_cuantos (&cambio, 500, 'B');

    if (cambio >= 200)
      calcula_cuantos (&cambio, 200, 'B');

    if (cambio >= 100)
      calcula_cuantos (&cambio, 100, 'B');

    if (cambio >= 50)
      calcula_cuantos (&cambio, 50, 'B');

    if (cambio >= 20)
      calcula_cuantos (&cambio, 20, 'B');

    if (cambio >= 10)
      calcula_cuantos (&cambio, 10, 'B');

    if (cambio >= 5)
      calcula_cuantos (&cambio, 5, 'B');

    if (cambio >= 2)
      calcula_cuantos (&cambio, 2, 'M');

    if (cambio >= 1)
      calcula_cuantos (&cambio, 1, 'M');
  }
}


void leer_pago (int deuda, int *cantidad)
{
  // Debe ser un número entero positivo y no inferior a la deuda:
  do{
    printf("Introduzca la cantidad que se entrega: ");
    scanf("%d",cantidad);
	fflush(stdin);
  }while ((*cantidad) < deuda);
}


void leer_deuda (int *cantidad)
{
  // Debe ser un número entero positivo:
  do{
    printf("Introduzca la cantidad a pagar: ");
    scanf("%d",cantidad);
	fflush(stdin);
  }while ((*cantidad) <= 0);
}


// PROGRAMA PRINCIPAL
void main()
{
  int deuda, pago;

  leer_deuda (&deuda);
  leer_pago (deuda, &pago);
  calcular_cambio (pago - deuda);
}
