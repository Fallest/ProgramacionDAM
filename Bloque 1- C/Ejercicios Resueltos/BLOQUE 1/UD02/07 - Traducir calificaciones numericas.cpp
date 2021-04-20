/*
Sabiendo que la correspondencia entre las notas num�ricas y sus correspondientes alfab�ticas es la que sigue, pasar cualquier nota num�rica a alfab�tica y mostrar el resultado en pantalla, siendo N la nota num�rica introducida por el usuario: 

0 <= N < 3     MUY DEFICIENTE 
3 <= N < 5     INSUFICIENTE 
5 <= N < 6     SUFICIENTE 
6 <= N < 7     BIEN 
7 <= N < 9     NOTABLE 
9 <= N <= 10   SOBREALIENTE 

*/

#include <stdio.h>

void main()
{
  int nota;

  printf("Introduzca la nota (entre 0 y 10): ");
  scanf("%d", &nota);
  fflush(stdin);

  if (nota >= 0 && nota < 3)
    printf("La nota es MUY DEFICIENTE.\n");
  else
    if(nota >= 3 && nota < 5)
      printf("La nota es MUY INSUFICIENTE.\n");
    else
      if (nota >= 5 && nota < 6)
        printf("La nota es MUY SUFICIENTE.\n");
      else
        if (nota >= 6 && nota < 7)
          printf("La nota es MUY BIEN.\n");
        else
          if (nota >= 7 && nota < 9)
            printf("La nota es NOTABLE.\n");
          else
            if (nota >= 9 && nota < 10)
              printf("La nota es MUY SOBRESALIENTE.\n");
            else
              if (nota == 10)
                printf("La nota es MATRICULA DE HONOR.\n");
              else
                printf("La nota introducida es incorrecta.\n");
}
