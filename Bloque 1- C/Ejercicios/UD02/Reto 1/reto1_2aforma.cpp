#include <stdio.h>

void main() {
	int num;
	printf("Introduce un numero par: ");
	scanf("%d", &num);
	fflush(stdin);
	

	if((num == 0) || (num % 2 != 0)) {
		printf("El numero introducido no es par. \n");
	} else {
	if(num < 0) {
		num = -(num);
		printf("No se puede hacer la cuenta atras. Su equivalente en positivo es el %d.\n", num);
	} else {
	if(num >= 10) {
		printf("El numero introducido es demasiado grande para hacer la cuenta atras.\n");
	} else {
		printf("Cuenta atras: ");
		while(num > 0) {
			printf("%d ", num);
			num = num - 1;
		}
		printf("\n");
	} //Del último else
	} //Del segundo else
	} //Del primer else
}