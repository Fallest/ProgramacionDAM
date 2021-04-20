#include <stdio.h>
#include <windows.h>

bool lectura_valida(int);
bool comparar_cifras(int, int);
void desglose_cifras(int, int *, int *, int *);

void main()
{
	// Declaracion de variables
	int num1, num2, contador = 0, oportunidades;
	bool fin_juego = false;

	// Lectura de datos
	do {
		printf("Introduzca la clave (tres cifras distintas): ");
		scanf("%d", &num1);
		fflush(stdin);

		printf("Cuantas oportunidades quiere dar?: ");
		scanf("%d", &oportunidades);
		fflush(stdin);
	} while ((lectura_valida(num1) == false) || (oportunidades <= 0));
	system("cls");

	// Lectura de num2, comprobacion de cifras
	// y conteo de oportunidades
	do {
		contador ++;
		printf("Intento %d: ", contador);
		scanf("%d", &num2);
		fflush(stdin);

		fin_juego = comparar_cifras(num1, num2);
	} while ((contador < oportunidades) && (fin_juego == false));
	
	if(fin_juego == false)
	{printf("Has perdido.\n");}
}

bool lectura_valida(int num)
{
	// Declaracion de variables
	bool resultado = false;

	// Comprobación de que es un número de 3 cifras
	if((num > 999) || (num < 100))
	{return resultado;}
	else
	{resultado = true; return resultado;}
}

bool comparar_cifras(int num1, int num2)
{
	// Declaracion de variables
	int num1_c1, num1_c2, num1_c3;
	int num2_c1, num2_c2, num2_c3;
	int cifras_presentes = 0, cifras_correctas = 0;
	bool resultado = false;

	// Comprobacion que num2 es valido
	if(lectura_valida(num2) == false)
	{printf("Ese numero no es valido (tiene mas o menos de 3 cifras).");
	return resultado;}

	else
	{
		// Asignacion de cifras
		desglose_cifras(num1, &num1_c1, &num1_c2, &num1_c3);
		desglose_cifras(num2, &num2_c1, &num2_c2, &num2_c3);

		// Comprobar cifras, una a una:
		if ((num1_c1 == num2_c1) || (num1_c1 == num2_c2) || (num1_c1 == num2_c3))
		{
			cifras_presentes ++;
			if(num1_c1 == num2_c1) {cifras_correctas ++;}
		}
		if ((num1_c2 == num2_c1) || (num1_c2 == num2_c2) || (num1_c2 == num2_c3))
		{
			cifras_presentes ++;
			if(num1_c2 == num2_c2) {cifras_correctas ++;}
		}
		if ((num1_c3 == num2_c1) || (num1_c3 == num2_c2) || (num1_c3 == num2_c3))
		{
			cifras_presentes ++;
			if(num1_c3 == num2_c3) {cifras_correctas ++;}
		}
		// Si el numero es el mismo:
		if ((num1_c1 == num2_c1) && (num1_c2 == num2_c2) && (num1_c3 == num2_c3))
		{
			resultado = true;
			printf("Has ganado.");
			return resultado;
		}
		else
		{
			// Si los numeros no son iguales, mostrar por pantalla
			// el numero de cifras presentes en la clave original y el
			// numero de cifras posicionadas correctamente.
			printf("%d valores de la clave original.\n", cifras_presentes);
			printf("%d valores en su posicion correcta.\n", cifras_correctas);
			return resultado;
		}
	}
}

void desglose_cifras(int num, int *c1, int *c2, int *c3)
{
	// Declaracion de vaiables
	int num_inv = 0;

	// Generar el numero invertido:
	do{
		num_inv = (num_inv * 10) + (num% 10);
		num = num / 10;
	}while (num != 0);
	// Extraccion de las cifras
	*c1 = num_inv % 10;
	num_inv = num_inv / 10;
	*c2 = num_inv % 10;
	num_inv = num_inv / 10;
	*c3 = num_inv % 10;
}