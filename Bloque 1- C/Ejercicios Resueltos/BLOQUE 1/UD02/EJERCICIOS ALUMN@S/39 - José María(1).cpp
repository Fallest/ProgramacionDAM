/* RETO 1 - Pedir al usuario un numero entero. Tendrá que ser par (no vale el cero).
- Si el numero es negativo, escribir en pantalla su equivalente en positivo.
- Si el numero es mayor que 10 escribir en pantalla que se trata de un numero "demasiado grande".
- En cualquier otro caso, escribir una cuenta atrás desde el numero hasta el cero.
- El programa debe estar comentado convenientemente.
- El valor 10 deberá estar almacenado en una constante. */
 
#include <stdio.h>

#define LIMITE 10 //Contante para controlar rel limite de la cuenta atras.

int main()
{
	int n; // variable entera. el dato a introducir.
		
	do{ //Validamos el dato hasta que sea par y distinto de 0.
		printf("\nIntroduzca un numero par (distinto de 0): ");
		scanf("%d", &n);
		fflush(stdin);
	}while (n == 0 || n % 2 != 0);

	if(n < 0) //Si el numero es negativo, lo pasamos a positivo. Y acabamos el programa.
		printf("\nEl numero es negativo. Su equivalente en positivo es: %d.\n", -n);
	else{ //En caso contrario, es positivo
		if(n > LIMITE) //Si el numero es mayor que LIMITE 10, lo imprimimos y acabamos el programa.
			printf("\nEl numero es demasiado grande.\n");
		else{ // Si no es negativo ni mayor que LIMITE
			printf("\n");
			while(n>=0){ // hacemos la cuenta atrás hasta 0.
				if (n > 0)
					printf("%d, ", n); //Si no es ultimo digito de la cuenta atras (el 0), imprimimos una coma.
				else 
					printf("%d.\n", n); //Cuando llega a 0, lo imprimimos y acabamos con un punto (final).
				n--;
			}
		}
	}
	printf("\n--------------------------------\n");
}
