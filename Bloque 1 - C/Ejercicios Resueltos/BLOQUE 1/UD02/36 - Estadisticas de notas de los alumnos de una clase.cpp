#include <stdio.h>

void main()
{

  int n_alumnos; // Numero de alumnos de la clase (lo da el usuario).
  int cont;      // Nos servira para contar cuantos llevamos procesados.
  int aprobados, suspensos; // Contadores de aprobados y de suspensos.
  float nota;    // Nota de cada alumno (usaremos la misma variable para todos ellos).

  // Inicializamos los contadores de aprobados y de suspensos a cero.
  aprobados = 0;
  suspensos = 0;

  // Lectura del numero de alumnos:
  do{
    printf("Introduzca el numero de alumnos: ");
    scanf("%d", &n_alumnos);
	fflush(stdin);
  }while (n_alumnos <= 0);

  // Peticion de notas de cada uno de los alumnos:
  for (cont=1; cont <= n_alumnos; cont++)
  {
	// Lectura de la nota:
    do{
      printf("Introduzca la nota del alumno %d en el examen: ", cont);
      scanf("%f", &nota);
	  fflush(stdin);
    }while ((nota < 0) || (nota > 10));

	// Aumentamos el contador correspondiente dependiendo del valor de la nota:
    if (nota < 5)
      suspensos++;
    else
      aprobados++;
  }

  // Impresion de los resultados:
  printf("\nHan aprobado %d alumnos (%f por ciento)\n", aprobados, ((float)(aprobados) / n_alumnos) * 100);
  printf("Han suspendido %d alumnos (%f por ciento)\n", suspensos, ((float)(suspensos) / n_alumnos) * 100);

}