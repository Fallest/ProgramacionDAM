#include <stdio.h>


// Prototipado
bool cifra_iguales(int a, int b);
void extraccion_cifras(int num, int *c1, int *c2, int *c3, int *c4);

void main()
{
	/* 
	Esta funcion va a realizar tres operaciones:
		-Leer los datos
		-Comprobar que los datos introducidos son correctos
		-Mostrar salida por pantalla
	Esta funcion NO va a realizar las siguientes operaciones:
		-Almacenar las variables para las cifras
		-Extraccion de cifras de los numeros
		-Comprobar que las cifras de los numeros son iguales
		-Comprobar que el orden de las cifras es diferente

	*/
	//Declaracion de variables
	int a, b;
	bool coincidentes; // true si son cifra-iguales.

	// Lectura de datos
	/*
	Como tienen que ser enteros positivos,
	se comprueba en cada ciclo del bucle si son positivos.
	Ademas, tienen que ser menores que 10000.
	*/
	do {
		printf("Introduzca el primer numero: ");
		scanf("%d", &a);
		fflush(stdin);

		printf("Introduzca el segundo numero: ");
		scanf("%d", &b);
		fflush(stdin);
	} while ((a < 0) || (b < 0) || (a > 9999) || (b > 9999));

	// Comprobar si son cifra-iguales mediante una funcion exterior
	coincidentes = cifra_iguales(a, b);

	// Salida por pantalla
	if(coincidentes == true) 
	{printf("Los numeros introducidos si son cifra_iguales.\n", a, b);}
	else 
	{printf("Los numeros introducidos no son cifra_iguales.\n", a, b);}
}

bool cifra_iguales(int a, int b)
{
	/*
	Esta función va a realizar tres operaciones:
		-Declarar las variables para almacenar las cifras
		-Comprobar si los numeros a y b tienen las mismas cifras
		-Comprobar que las cifras no estan en las mismas posiciones

	Esta funcion NO va a realizar las siguientes operaciones:
		-Lectura de datos
		-Comprobacion de datos introducidos correctos
		-Mostrar salidas por pantalla
		-Extraccion de las cifras de los numeros
	*/

	// Declaracion de variables formales
	/*
	Debemos desglosar los numeros en sus cifras, y almacenarlas
	por separado. Para ello usamos las variables a_cX, b_cX.
	Además, hay que iniciarlas todas a 0, para evitar errores
	al operar con ellas mas tarde.
	*/
	int a_c1, a_c2, a_c3, a_c4;
	int b_c1, b_c2, b_c3, b_c4;
	bool resultado = false, cifras_iguales = false, orden_distinto = false;

	a_c1 = 0;
	a_c2 = 0;
	a_c3 = 0;
	a_c4 = 0;

	b_c1 = 0;
	b_c2 = 0;
	b_c3 = 0;
	b_c4 = 0;

	/* Ahora debemos extraer las cifras de cada numero */
	extraccion_cifras(a, &a_c1, &a_c2, &a_c3, &a_c4);
	extraccion_cifras(b, &b_c1, &b_c2, &b_c3, &b_c4);
	
	// Comprobar si las cifras son iguales
	/* 
	Como se estan comprobando cifras (numeros menores de 10)
	la suma que resulte de ellos sera una suma unica. Por esto,
	la suma de todas las cifras de un numero sera diferente de todos
	los demas que no tengan las mismas cifras pero en distinto orden.
	Nos podemos ayudar de este hecho para comprobar si los numeros
	tienen las mismas cifras.
	*/
	if ((a_c1 + a_c2 + a_c3 + a_c4) == (b_c1 + b_c2 + b_c3 + b_c4))
	{cifras_iguales = true;}
	
	// Comprobar si su orden es distinto
	/* 
	Además, el enunciado requiere que tengan un orden distinto.
	Para ello solo hay que comprobar si las cifras homologas de a en b
	son equivalentes.
	*/
	if ((a_c1 != b_c1) && (a_c2 != b_c2) && (a_c3 != b_c3) && (a_c4 != b_c4))
	{orden_distinto = true;}

	// Por ultimo, comprobados que tanto cifras_iguales como orden_distinto son true
	if((cifras_iguales == true) && (orden_distinto == true))
	{resultado = true;}


	return resultado;
}

void extraccion_cifras(int num, int *c1, int *c2, int *c3, int *c4)
{
	/* 
	Esta funcion realiza una unica operacion:
		-Extraccion y asignacion de cifras a sus variables designadas
	Esta funcion NO realiza las siguientes operaciones:
		-Leer los datos
		-Comprobar que los datos introducidos son correctos
		-Mostrar salida por pantalla
		-Declarar las variables para almacenar las cifras
		-Comprobar si los numeros a y b tienen las mismas cifras
		-Comprobar que las cifras no estan en las mismas posiciones
		
	*/

	// Extraccion y asignacion de cifras
	*c1 = num % 10;
	num = num / 10;
	*c2 = num % 10;
	num = num / 10;
	*c3 = num % 10;
	num = num / 10;
	*c4 = num % 10;
}