#include <stdio.h>
#include <locale.h>

void main() {
	int num;

	printf("Dime un n�mero: \n");

	scanf("%d", &num);
	fflush(stdin);
	
	printf("Tu n�mero es %d \n", num);
}