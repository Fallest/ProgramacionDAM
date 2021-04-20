#include <stdio.h>

void escribe_cabecera (int);
void escribe_vector (int, int);
void escribe_tabla (int);
void leer_numero (int *);


void escribe_cabecera (int n)
{
	int columna;

    printf("\n\n  ");
    // Escribe las cabeceras de columnas
    for (columna=1; columna <= n; columna++)
	  printf("|%2d", columna);
    // Salto de linea
    printf("|\n--");
	// Escribe una línea separadora
    for (columna=1; columna <= n; columna++)
	  printf("---");
	// Salto de linea
    printf("-\n");
}


void escribe_vector (int fila, int n)
{
	int columna;

	//Escribimos la cabecera de la fila
	printf("%2d|", fila);

	//Escribimos los valores de cada fila
	for (columna=1;columna <= n; columna++)
		printf("%2d|", fila + columna);

	//Antes de escribir la fila siguiente, saltamos de linea
    printf("\n");
}


void escribe_tabla (int n)
{
	int fila, columna;

	escribe_cabecera (n);

	for (fila=1; fila <= n; fila++)
        escribe_vector (fila, n);

	// Escribe una línea separadora
	printf("--");
    for (columna=1; columna <= n; columna++)
	  printf("---");
	printf("-\n");
}


void leer_numero (int *num)
{
    do{
        printf("Introduzca numero: ");
	    scanf("%d", num);
		fflush(stdin);
	}while (((*num) <= 0) || ((*num) > 20));
}


void main()
{
	int n;
	
	leer_numero(&n);
	
	escribe_tabla(n);
}
