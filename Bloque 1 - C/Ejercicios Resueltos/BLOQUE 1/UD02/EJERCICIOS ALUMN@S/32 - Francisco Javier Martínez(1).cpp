#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int numeroa;
	
	int contadora;
	
	int acumuladora;
	
	int numerob;
	
	int contadorb;
	
	int acumuladorb;
	
	printf("\n Introduce el numero a:");
	scanf("%d", &numeroa);
	
	contadora = numeroa;
	
	contadora--;
	
	while (contadora > 1){
		
		if (numeroa % contadora == 0){
			
			acumuladora += contadora;
			
		}
		
		contadora--;
	}
	
	// numero b:
	
	printf("\n Introduce el numero b:");
	scanf("%d", &numerob);
	
	contadorb = numerob;
	
	contadorb--;
	
	while (contadorb > 1){
		
		if (numerob % contadorb == 0){
			
			acumuladorb += contadorb;
			
		}
		
		contadorb--;
	}
	
	acumuladorb++;
	
	if( acumuladora == numerob && acumuladorb == numeroa ){
		printf("\n Los numeros:");
		printf("\n A: %d", numeroa);
		printf("\n B: %d", numerob);
		printf("\n son amigos.");
	}
	if( acumuladora != numerob && acumuladorb != numeroa ){
		printf("\n Los numeros:");
		printf("\n A: %d", numeroa);
		printf("\n B: %d", numerob);
		printf("\n no son amigos.");
	}
		
	
	acumuladorb = 0;
	
	acumuladora = 0;
	
}
