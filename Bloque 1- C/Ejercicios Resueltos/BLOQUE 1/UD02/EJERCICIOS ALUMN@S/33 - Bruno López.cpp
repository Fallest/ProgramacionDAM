#include <stdio.h>

void main()
{
	int numero; // Numero leido del teclado
	int contador = 0; // Cuenta el numero de cifras
	
		
	printf("Introduzca un numero entero positivo: ");
	scanf("%d", &numero);
	fflush(stdin);
	
	if(numero >= 1){
		
		while(numero >= 1){
		
			numero = numero / 10;
			contador++;
		
		}	
	
		printf("El numero introducido tiene %d cifras.\n", contador);
		
	} else {
		
		printf("El valor introducido no es un numero entero positivo.\n");	
		
	}

		


}
