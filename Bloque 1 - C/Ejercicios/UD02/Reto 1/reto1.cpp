#include <stdio.h>
#define maximo 10

void main() {
	int num;
	printf("Introduce un numero entero: ");
	scanf("%d", &num);
	fflush(stdin);
	int flag = 1;

	if((num == 0) || (num % 2 != 0)) {
		printf("El numero introducido no es par. \n");
		flag = 0;
	}
	if(num < 0) {
		num = -(num);
		printf("No se puede hacer la cuenta atras. Su equivalente en positivo es el %d.\n", num);
		flag = 0;
	}
	if(num >= maximo) {
		printf("El numero introducido es demasiado grande para hacer la cuenta atras.\n");
		flag = 0;
	}
	if(flag == 1) {
		printf("Cuenta atras: ");
		while(num > 0) {
			printf("%d ", num);
			num = num - 1;
		}
		printf("\n");
	}
}