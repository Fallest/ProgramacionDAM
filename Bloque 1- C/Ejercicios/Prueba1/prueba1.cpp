#include <stdio.h>
#include <locale.h>

void main() {
	int num;

	printf("Dime un número: \n");

	scanf("%d", &num);
	fflush(stdin);
	
	printf("Tu número es %d \n", num);
}