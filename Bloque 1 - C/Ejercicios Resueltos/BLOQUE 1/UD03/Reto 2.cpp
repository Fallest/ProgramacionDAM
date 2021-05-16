#include <stdio.h>
#include <stdlib.h>

#define NCIFRAS 3
#define NINTENTOS 5

#define USUARIO1 1
#define USUARIO2 2

#define V 100
#define F 0


void leer_clave (int *clave, int usuario, int n_intento);
int comprobar_si_distintas (int clave);
int comprobar_intento (int clave, int intento);
int comprobar_cifra_en_clave (int clave, int cifra);
void imprimir_datos_intento (int valores_clave, int valores_posicion);
void imprimir_resultado (int gana);


void leer_clave (int *clave, int usuario, int n_intento)
{
	// Se lee la cadena numérica (que puede ser la clave a adivinar o bien
	// uno de los intentos del jugador.
	do{
		// El mensaje en el que se pide que el usuario introduzca la cadena numérica
		// será distinto dependiendo de si se trata del que pone la clave o del adivinador.
		if (usuario == USUARIO1)
			printf("\n\nIntroduzca la clave (%d cifras distintas): ", NCIFRAS);
		else
			printf("\n\nIntento %d: ", n_intento);

		// Independientemente del usuario, se lee el dato y se almacena en "clave".
		scanf("%d", clave);
		fflush(stdin);

		// Se repetirá la petición si la cadena numérica no tiene tres cifras o si las tiene
		// pero no son distintas entre ellas.
	}while ( ( ((*clave)<100) || ((*clave)>999) ) ||
		     (!comprobar_si_distintas (*clave)  ) );

	// Corregir los valores literales:
	// 100 = 10 ^ 2 = 10 ^ (NCIFRAS - 1) ==> pow (10, NCIFRAS - 1)
	// 999 = 10 ^ 3 - 1 ==> pow (10, NCIFRAS) - 1
}

int comprobar_si_distintas (int clave)
{
	int cifra_extraida, cifra_a_comprobar;
	int clave_aux;
	int i, j;

	// Recorremos la clave cifra por cifra:
	for (i=1; i<=NCIFRAS; i++)
	{
		// Sacamos la última cifra y la quitamos de la clave (guardando la original):
		cifra_extraida = clave % 10;
		clave_aux = clave / 10;

		// Recorremos el trozo de la clave que queda (clave_aux) cifra por cifra
		// y las vamos comparando con la cifra extraída antes:
		for (j=i+1; j<=NCIFRAS; j++)
		{
			cifra_a_comprobar = clave_aux % 10;

			// Si coinciden entonces es que la clave no tiene cifras distintas (alguna se repite):
			if (cifra_a_comprobar == cifra_extraida)
				return F;

			// Quitamos la última cifra para seguir haciendo iteraciones:
			clave_aux = clave_aux / 10;
		}

		// Le quitalos la última cifra a la cadena original con el mismo fin:
		clave = clave / 10;

	}

	// Si el programa llega hasta aquí es porque los bucles han llegado hasta el final
	// y no se ha dado el caso que provoca el return F, es decir, las cifras son todas distintas:
	return V;

}


int comprobar_intento (int clave, int intento)
{
	int i;  // Contador para el bucle que "recorra" las cifras de "intento".
	int contador_valores_clave = 0, contador_valores_posicion = 0; // Contadores de "aciertos".
	int cifra, posicion_cifra; // Cifra de "intento" (y su posicion dentro de "intento").

	// Se recorren las cifras de "intento" comprobando si están en la clave (y en qué posición):
	for (i=1; i<=NCIFRAS; i++)
	{

		cifra = intento % 10; 	// Sacamos la cifra más a la derecha.

		// Llamamos a la función que comprueba si la cifra está en la clave y nos devuelve además
		// (en su caso) en qué posición se encuentra dentro de "clave".
		posicion_cifra = comprobar_cifra_en_clave(clave, cifra);

		// Si la cifra está en la clave:
		if (posicion_cifra != 0)
		{
			contador_valores_clave ++;  // Incrementamos el contador de aciertos.

			// Si además está en la misma posíción en las dos cadenas:
			if (posicion_cifra == i)
				contador_valores_posicion ++;  // Incrementamos el contador de posiciones correctas.
		}

		// Quitamos la cifra más a la derecha de "intento" y seguimos recorriéndolo:
		intento = intento / 10;

	}

	// Se imprime el contenido de los dos contadores, informando del número de aciertos y
	// del número de cifras acertadas de "intento" que además están en la misma posición en "clave".
	imprimir_datos_intento (contador_valores_clave, contador_valores_posicion);

	// Se comprueba si el usuario ha ganado el juego:
	if ((contador_valores_clave == NCIFRAS) && (contador_valores_posicion == NCIFRAS))
		return V;
	else
		return F;
}


int comprobar_cifra_en_clave (int clave, int cifra)
{
	int i, cifra_clave;
	
	// Recorremos la clave, cifra por cifra, comparándolas con la cifra que nos pasan.
	for (i=1; i<=NCIFRAS; i++)
	{
		cifra_clave = clave % 10;

		// Si la cifra extraída coincide con la que nos pasan, devolvemos su posición.
		if (cifra_clave == cifra)
			return i;
		
		// Quitamos a la clave una cifra para poder seguir comprobándola.
		clave = clave / 10;
	}

	// Si la ejecución ha llegado hasta aquí es porque la cifra que nos pasan
	// no está en la clave. Entonces devolvemos 0.
	return 0;
}


void imprimir_datos_intento (int valores_clave, int valores_posicion)
{
	printf("\nValores %d de la clave original.", valores_clave);
	printf("\nValores %d en su posicion correcta.", valores_posicion);
}


void imprimir_resultado (int gana)
{
	if (gana)
		printf("\n\nHas ganado.\n");
	else
		printf("\n\nHas perdido.\n");
}


void main()
{
	int clave_acertar, clave_intento;
	int numero_de_intentos = 1;
	int juego_terminado = F;
	int ha_ganado = F;

	// El usuario 1 escribe la clave:
	leer_clave (&clave_acertar, USUARIO1, 0);

	// Borramos la pantalla. El juego comienza:
	system("cls");

	do{
		// El jugador introduce una clave para ver si ha acertado:
		leer_clave (&clave_intento, USUARIO2, numero_de_intentos);

		// Se comparan las dos claves:
		ha_ganado = comprobar_intento (clave_acertar, clave_intento);

		// El juego termina si:
		// 1) No ha acertado y ha gastado todos sus intentos.
		// 2) Ha acertado.
		if (((!ha_ganado) && (numero_de_intentos == NINTENTOS)) || (ha_ganado))
		{
			imprimir_resultado (ha_ganado);
			juego_terminado = V;
		}
		else
			// Se incrementa el número de intentos que lleva:
			numero_de_intentos++;

	}while (!juego_terminado);

}

