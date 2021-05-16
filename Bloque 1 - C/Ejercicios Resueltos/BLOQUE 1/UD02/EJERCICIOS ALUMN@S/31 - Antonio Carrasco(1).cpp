#include <stdio.h>

/*Programa que calcula el MCD de dos numeros*/

void main(){

	int num,num1;//Datos que vamos a introducir
	int contador,interruptor; //contador por el que dividira los dos numeros e interruptor que se activara a 0 si no tiene divisores
	int mcd; //Variable que se igualara al contador, que actua como divisor
	mcd=0;

	interruptor=1; //Levantamos el interruptor

	printf("Introduzca el primer numero a procesar porfavor: ");
	scanf("%d",&num);
	fflush(stdin);		//Nos pide ambos datos

	printf("Introduzca el segundo numero a procesar porfavor: ");
	scanf("%d",&num1);
	fflush(stdin);


	if(num>num1){
		contador=num1;
	}//Estos dos "if" nos iguala el menor numero (sin importar el orden) a la variable contador, para luego dividirlo entre ambos
	if(num1>num){
		contador=num;
	}

	
	while(interruptor==1){ //Este bucle se ejecutara mientras el interruptor valga 1
	
		if(num%contador==0 && num1%contador==0){ 

			/*A cada vuelta de bucle comprueba si no tiene divisores, 
			Si no tiene iguala el interruptor a 0, iguala el mcd al contador y sale del bucle*/

			mcd=contador;
			interruptor=0;
		}

		contador--; //Decrementamos el contador para restarlo por un numero menor

	}
	printf("El MCD de %d y %d es %d\n\n\n",num,num1, mcd); //Nos muestra el MCD
}
