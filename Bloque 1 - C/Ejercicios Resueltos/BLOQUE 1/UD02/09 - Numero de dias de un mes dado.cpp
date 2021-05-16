/*
Imprimir por pantalla el numero de dias de un mes introducido por el teclado (se lee el
numero del mes)
*/

#include <stdio.h>

void main()
{
  int mes;

  printf("Introduzca el numero del mes (1-12): ");
  scanf("%d", &mes);
  fflush(stdin);

  switch(mes)
  {
    case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: printf("Tiene 31 dias.\n\n");
		     break;
	case 4:
	case 6:
	case 9:
	case 11: printf("Tiene 30 dias.\n\n");
		     break;
    case 2: printf("Tiene 28 dias.\n\n");
		    break;
    default: printf("Ha introducido un numero de mes incorrecto.\n\n");
  }
}
