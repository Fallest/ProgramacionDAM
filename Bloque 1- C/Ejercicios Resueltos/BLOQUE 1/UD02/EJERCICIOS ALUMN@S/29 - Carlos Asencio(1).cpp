//Se dispone de un cierto número de valores de los cuáles el último es el 999 y se desea determinar el valor máximo de las medias correspondientes a parejas de valores sucesivos. 

#include<stdio.h>

void main()
{
	int num1, num2;
	float media=0, mayor=0;

		printf("Introduzca un numero (999 para salir del programa):");
		scanf("%d",&num1);
		fflush(stdin);

	
	while(num1 != 999 && num2 != 999)
	{
		printf("Introduzca el siguiente numero para realizar la media con el anterior\n(999 para salir del programa):");
		scanf("%d",&num2);
		fflush(stdin);

		if(num2 != 999)
		{
			media = ((float)num1+num2)/2;	
			num1=num2;
		}

		if(media > mayor)
			mayor=media;

	}


	if(media==0 && num2 != 999)
		printf("\n\nNo se ha introducido ningun numero\n\n");
	else
	{
		if(media==0 && num2==999)
			printf("\n\nSe ha introducido solamente el primer valor por lo que\n no se puede realizar media\n\n");
		else
			printf("\n\nLa mayor media de los numeros introducidos es %.2f\n\n", media);
	}
}