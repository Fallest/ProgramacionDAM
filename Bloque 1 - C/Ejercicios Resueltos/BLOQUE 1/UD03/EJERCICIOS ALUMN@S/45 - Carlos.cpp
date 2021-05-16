/*45) Realizar un programa que solicite un número estrictamente positivo. A continuación solicitará que cifra queremos obtener del citado número. Si esa cifra no existe se mostrará el mensaje 
"No existe la cifra en el número".

Ejemplo: 
Introduce un número: 149877

¿Qué orden de cifra quieres?  3
La cifra con orden 3 es un 8
¿Otra cifra (S/N)? S

¿Qué orden de cifra quieres?  4
La cifra con orden 4 es un 9
¿Otra cifra (S/N)? S

¿Qué orden de cifra quieres?  7
No existe la cifra 7 en el número
¿Otra cifra (S/N)? N
*/

//LAS FUNCIONES COMENTADAS ES LA VERSIÓN CON PUNTEROS

//LIBRERIAS

#include<stdio.h>

//PROTOTIPOS

int obtener_valor();
//void obtener_valor(int *numero);

int orden_cifra();
//void orden_cifra(int *cifra);

void obtener_cifra(int num, int orden);
void imprimir_resultado(int copia_num, int orden);

char preguntar_si_repetir();
//void preguntar_si_repetir(char *continuacion);


//*************************************
//*************************************
//PROGRAMA PRINCIPAL
//*************************************
//*************************************

void main()
{
	int num;	//numero con el que vamos a trabajar
	int orden; //para almacenar el orden de cifra que quiere el usuario
	char repetir;	//si el usuario quiere repetir la accion

	
	num = obtener_valor();	//funcion para la obtencion del valor 
	//obtener_valor(&num);

	do
	{
		orden = orden_cifra();	//funcion para pedir al usuario el numero de la cifra que quiere obtener
		//orden_cifra(&orden);

		obtener_cifra(num, orden);	//funcion para saber cual es la cifra teniendo el orden que buscamos

		repetir = preguntar_si_repetir();	//funcion para preguntar al usuario si quiere volver a realizar la operacion
		//preguntar_si_repetir(&repetir);

		printf("\n\n");
	}while(repetir == 'S');
}

//*************************************
//*************************************
//FUNCIONES
//*************************************
//*************************************

int obtener_valor()
{
	int numero;

		printf("Introduce un numero:  ");
		scanf("%d",&numero);
		fflush(stdin);

	if(numero < 0)
		numero = numero * (-1);	//si el numero es negativo, lo transformamos a positivo (el enunciado pide que sea positivo)

	return numero;
}

/*
void obtener_valor(int *numero)
{

		printf("Introduce un numero:  ");
		scanf("%d", numero);
		fflush(stdin);

	if(*numero < 0)
		*numero = *numero * (-1);	//si el numero es negativo, lo transformamos a positivo (el enunciado pide que sea positivo)

}
*/

//**************************

int orden_cifra()
{
	int cifra;

	do
	{
		printf("Que orden de cifra quieres?: ");
		scanf("%d",&cifra);
		fflush(stdin);
	}while(cifra<=0);

	return cifra;
}
/*
void orden_cifra(int *cifra)
{
	do
	{
		printf("Que orden de cifra quieres?: ");
		scanf("%d", cifra);
		fflush(stdin);
	}while(*cifra<=0);
}
*/

//**************************

void obtener_cifra(int num, int orden)
{
	int copia_num=num;	//realizamos una copia al numero original para trabajar con esta
	int cont=1;		
	
	while(cont<orden)	//vamos desde cont=1 hasta el numero del orden que ha escrito el usuario
	{
		copia_num = copia_num/10;	//vamos dividiendo la cifra para posteriormente imprimir el ultimo valor (el del orden)	
		cont++;
	}
		
	
	imprimir_resultado(copia_num, orden);	//funcion para imprimir el resultado sabiendo el numero que nos ha quedado en copia_num y el orden que pediamos

}

void imprimir_resultado(int copia_num, int orden)
{
	if(orden!=1 && copia_num==0)	//si ha llegado a cero es porque se ha pasado del numero de cifras que tiene y el numero es distinto de cero
		printf("No existe la cifra %d en el numero\n",orden);
	else
		printf("La cifra con orden %d es un %d\n", orden, copia_num%10);	//imprimimos la ultima cifra del numero con el %
}

//**************************

char preguntar_si_repetir()
{
	char continuacion;

	do
	{
		printf("Otra cifra (S/N)? ");
		scanf("%c",&continuacion);
		fflush(stdin);
	}while(continuacion != 'S' && continuacion != 'N');

	return continuacion;
}
/*
void preguntar_si_repetir(char *continuacion)
{
	do
	{
		printf("Otra cifra (S/N)? ");
		scanf("%c",continuacion);
		fflush(stdin);
	}while(*continuacion != 'S' && *continuacion != 'N');

}
*/