/*
Sabiendo que la correspondencia entre las notas numéricas y sus correspondientes alfabéticas es la que sigue, pasar cualquier nota numérica a alfabética y mostrar el resultado en pantalla, siendo N la nota numérica introducida por el usuario: 

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

  switch (nota)
  {
    case 0: 
    case 1: 
    case 2: printf("La nota es MUY DEFICIENTE.\n");
		    break;
    case 3: 
    case 4: printf("La nota es INSUFICIENTE.\n");
		    break;
    case 5: printf("La nota es SUFICIENTE.\n");
		    break;
    case 6: printf("La nota es BIEN.\n");
		    break;
    case 7: 
    case 8: printf("La nota es NOTABLE.\n");
		    break;
    case 9: printf("La nota es SOBRESALIENTE.\n");
		    break;
    case 10: printf("La nota es MATRICULA DE HONOR.\n");
		     break;
    default: printf("Ha introducido una nota incorrecta.\n\n");
  }
}
