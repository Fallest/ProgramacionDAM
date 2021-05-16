#include <stdio.h>

#define SI 1
#define NO 0

void main()
{
  int n1, n2;
  float media, max;
  int primera_pareja_no_valida = NO; // Sera verdadera si el usuario introduce un 999 en alguno de los dos valores la primera vez.
  int no_hay_maximo = SI;  // Sera falso si puede calcularse al menos una media.

  printf("Introduzca numero: ");
  scanf("%d", &n1);
  fflush(stdin);

  if (n1 != 999)   // Si el primer valor no es 999 leemos el segundo
  {
     printf("Introduzca numero: ");
     scanf("%d", &n2);    
     fflush(stdin);

     if (n2 == 999)  // El usuario ha escrito un 999 en el segundo valor la primera vez

       primera_pareja_no_valida = SI;

     else   // El usuario ha introducido dos valores distintos de 999 la primera vez. Empieza el proceso repetitivo.:

       while (n2 != 999)   // Saldra del bucle cuando el usuario introduzca un 999
       {
         media = float (n1 + n2) / 2;

		 if (no_hay_maximo == SI)  // No se puede comparar la media con una anterior: Se guarda.
		 {
			 max = media;
			 no_hay_maximo = NO;
		 }
		 else
	         if (media > max)
		       max = media;

		 n1 = n2;   // Guardamos el ultimo valor para no perderlo

         printf("Introduzca numero: ");
         scanf("%d", &n2);   // Ahora haremos la media (si n2 no es 999) del ultimo valor de antes con este que se lee ahora
         fflush(stdin);
       }
  }
  else   // El usuario ha escrito un 999 en el primer valor la primera vez
    primera_pareja_no_valida = SI;

  if (primera_pareja_no_valida == SI)
    printf("\nNo se ha llegado a introducir una pareja valida de valores.\n");
  else
    printf("\nMedia maxima = %f\n", max);
}