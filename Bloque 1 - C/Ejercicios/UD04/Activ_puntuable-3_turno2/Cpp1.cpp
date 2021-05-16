#include <stdio.h>
#include <string.h>

#define TARTICULOS 30
#define TVENDEDORES 10
#define TVENTAS 100

/* -------------------------------------------------------------- */
// Definición de estructuras

typedef struct {
	int cod_articulo;
	char descripcion[31];
} Articulo;

// Necesario para Vendedor
struct Nif {
	int num_nif;
	char letra;
};

typedef struct {
	struct Nif nif;
	char nombre[41];
} Vendedor;

// Necesario para Venta
struct Fecha {
	int dia, mes, anyo;
};

typedef struct {
	Articulo articulo;
	Vendedor vendedor;
	struct Fecha fecha;
	int num_unidades;
	int p_unitario;
} Venta;

/* -------------------------------------------------------------- */
//Prototipado de funciones
void mostrar_menu();
void leer_opcion(int *opcion);
void ejecutar_opcion(int opcion, Articulo articulos[], Vendedor vendedores[], Venta ventas[]);

void alta_articulos(Articulo articulos[]);
void consulta_articulos(Articulo articulos[]);

void alta_vendedores(Vendedor vendedores[]);
void consulta_vendedores(Vendedor vendedores[]);

void alta_ventas(Venta ventas[]);
void consulta_ventas_vendedor(Venta ventas[]);
void consulta_ventas_articulo(Venta ventas[]);

void articulo_mas_vendido(Venta ventas[]);
void vendedor_mas_productivo(Venta ventas[]);

/* -------------------------------------------------------------- */
// MAIN
void main() 
{
	// Tiene que controlar si se escoge la opcion 10.
	// Inicializar codigos de los articulos a 0.
	// Inicializar el num del nif de los vendedores a 0.
	// Inicializar el numventas y punitario a 0. Inicializar las fechas a 0/0/0.
}

/* -------------------------------------------------------------- */// 3/3
// Funciones del menú
void mostrar_menu()
{
	printf("-----MENU-----");
	printf("1. Dar de alta articulos\n");
	printf("2. Consultar artículos\n");
	printf("3. Dar de alta vendedores");
	printf("4. Consultar vendedores\n");
	printf("5. Dar de alta ventas\n");
	printf("6. Consultar ventas por vendedor\n");
	printf("7.,Consultar ventas por articulo\n");
	printf("8. Articulo mas vendido\n");
	printf("9. Vendedor mas productivo\n");
	printf("10. Salir\n");
	printf("--------------");
}

void leer_opcion(int *opcion)
{
	do {
		printf("Escoja una opcion (1-10): ");
		scanf("%d", opcion);
		fflush(stdin);
	} while (((*opcion) < 1) || ((*opcion) > 10));
}

void ejecutar_opcion(int opcion, Articulo articulos[], Vendedor vendedores[], Venta ventas[])
{
	switch (opcion)
	{
	case 1:
		{
			alta_articulos(articulos);
			break;
		}
	case 2:
		{
			consulta_articulos(articulos);
			break;
		}
	case 3:
		{
			alta_vendedores(vendedores);
			break;
		}
	case 4:
		{
			consulta_vendedores(vendedores);
			break;
		}
	case 5:
		{
			alta_ventas(ventas);
			break;
		}
	case 6:
		{
			consulta_ventas_vendedor(ventas);
			break;
		}
	case 7:
		{
			consulta_ventas_articulo(ventas);
			break;
		}
	case 8:
		{
			articulo_mas_vendido(ventas);
			break;
		}
	case 9:
		{
			vendedor_mas_productivo(ventas);
			break;
		}
	}
}

/* -------------------------------------------------------------- */// 2/2
// Funciones para el alta y consulta de articulos
void alta_articulos(Articulo articulos[])
{
	// Vamos a realizar una insercion ordenada para que al mostrarlos ya estén en orden
	int i, j;
	char ejec = 's';
	bool flag = true;

	do {
		for (i = 0; i < TARTICULOS; i++)
		{
			// Si es el primer elemento
			if (i == 0 && articulos[i].cod_articulo == 0)
			{
				// Lectura del cod_articulo con control de errores
				do {
					flag = false;
					printf("Introduzca el codigo del articulo (tres cifras): ");
					scanf("%d", &articulos[i].cod_articulo);
					fflush(stdin);
					
					if ((articulos[i].cod_articulo < 100) || (articulos[i].cod_articulo > 999))
						flag = true;
				} while(flag);

				printf("Introduzca una descripcion para el producto (max 40 caracteres): ");
				gets(articulos[i].descripcion);
				fflush(stdin);
			}

			// Si es cualquier otro elemento
			else if (articulos[i-1].cod_articulo < articulos[i].cod_articulo)
			{
				// Lectura del cod_articulo con control de errores
				do {
					flag = false;
					printf("Introduzca el codigo del articulo (tres cifras): ");
					scanf("%d", &articulos[i].cod_articulo);
					fflush(stdin);

					if ((articulos[i].cod_articulo < 100) || (articulos[i].cod_articulo > 999))
						flag = true;


					// Comprobar que el código no existe ya
					for (j = 0; j < TARTICULOS; j++)
					{
						if ((articulos[i].cod_articulo == articulos[j].cod_articulo) && (j != i))
						{flag = true;}
					}
				} while(flag);
			
				printf("Introduzca una descripcion para el producto (max 40 caracteres): ");
				gets(articulos[i].descripcion);
				fflush(stdin);
			}
		}
		
		printf("Quiere dar de alta otro articulo (s/n)?: ");
		scanf("%c", &ejec);
		fflush(stdin);
	} while (ejec == 's');
}

void consulta_articulos(Articulo articulos[])
{
	int i;
	
	for (i = 0; i < TARTICULOS; i++)
	{
		printf("Articulo %d: %s", articulos[i].cod_articulo, articulos[i].descripcion);
	}
}

/* -------------------------------------------------------------- */// 2/2
// Funciones para el alta y consulta de vendedores
void alta_vendedores(Vendedor vendedores[])
{
	int i, j;
	char ejec = 's';
	bool flag = true;

	do {
		for (i = 0; i < TVENDEDORES; i++)
		{
			// Si es el primer elemento
			if (i == 0 && vendedores[i].nif.num_nif == 0)
			{
				// Lectura del NIF con control de errores
				do {
					flag = false;
					printf("Introduzca el NIF del vededor(8 cifras y 1 letra): ");
					scanf("%d%c", &vendedores[i].nif.num_nif, &vendedores[i].nif.letra);
					fflush(stdin);
					
					if ((vendedores[i].nif.num_nif < 10000000) || (vendedores[i].nif.num_nif > 99999999))
						flag = true;
				} while(flag);

				printf("Introduzca el nombre del vendedor (max 40 caracteres): ");
				gets(vendedores[i].nombre);
				fflush(stdin);
			}

			// Si es cualquier otro elemento
			else if (vendedores[i-1].nif.num_nif < vendedores[i].nif.num_nif)
			{
				// Lectura del cod_articulo con control de errores
				do {
					flag = false;
					printf("Introduzca el NIF del vededor(8 cifras y 1 letra): ");
					scanf("%d%c", &vendedores[i].nif.num_nif, &vendedores[i].nif.letra);
					fflush(stdin);
					
					if ((vendedores[i].nif.num_nif < 10000000) || (vendedores[i].nif.num_nif > 99999999))
						flag = true;

					// Comprobar que el nif no existe ya
					for (j = 0; j < TVENDEDORES; j++)
					{
						if (((vendedores[i].nif.num_nif == vendedores[j].nif.num_nif) || (vendedores[i].nif.letra == vendedores[j].nif.letra)) && (j != i))
						{flag = true;}
					}
				} while(flag);
			
				printf("Introduzca el nombre del vendedor (max 40 caracteres): ");
				gets(vendedores[i].nombre);
				fflush(stdin);
			}
		}
	} while (ejec == 's');
}

void consulta_vendedores(Vendedor vendedores[])
{
	// Falta implementar el mostrarlos en orden
	int i;
	
	for (i = 0; i < TVENDEDORES; i++)
	{
		printf("Vendedor %d%c: %s", vendedores[i].nif.num_nif, vendedores[i].nif.letra, vendedores[i].nombre);
	}
}

/* -------------------------------------------------------------- */// 0/3
// Funciones para  el alta y consulta de ventas
void alta_ventas(Venta ventas[])
{
	int i, j;
	char ejec = 's';
	bool flag = true;

	do {
		for (i = 0; i < TVENTAS; i++)
		{
			// Si es el primer elemento y no tiene informacion:
			if (i == 0 && ventas[i].fecha.anyo == 0)
			{
				// Lectura del NIF con control de errores
				do {
					flag = false;
					printf("Introduzca el NIF del vededor(8 cifras y 1 letra): ");
					scanf("%d%c", &ventas[i].vendedor.nif.num_nif, &ventas[i].vendedor.nif.letra);
					fflush(stdin);
					
					if ((ventas[i].vendedor.nif.num_nif < 10000000) || (ventas[i].vendedor.nif.num_nif > 99999999))
						flag = true;
				} while(flag);

				
				// Lectura de la fecha con control de errores
				do {
					flag = false;
					printf("Introduzca la fecha de la venta (dd/mm/aaaa): ");
					scanf("%d/%d/%d", ventas[i].fecha.dia, ventas[i].fecha.mes, ventas[i].fecha.anyo);
					fflush(stdin);

					if ((ventas[i].fecha.dia < 1 || ventas[i].fecha.dia > 31) || 
						(ventas[i].fecha.mes < 1 || ventas[i].fecha.mes > 12) ||
						(ventas[i].fecha.anyo < 1970 || ventas[i].fecha.anyo > 2021))
						flag = true;
				} while (flag);
			}

			// Si es cualquier otro elemento
			else if (vendedores[i-1].nif.num_nif < vendedores[i].nif.num_nif)
			{
				// Lectura del cod_articulo con control de errores
				do {
					flag = false;
					printf("Introduzca el NIF del vededor(8 cifras y 1 letra): ");
					scanf("%d%c", &vendedores[i].nif.num_nif, &vendedores[i].nif.letra);
					fflush(stdin);
					
					if ((vendedores[i].nif.num_nif < 10000000) || (vendedores[i].nif.num_nif > 99999999))
						flag = true;

					// Comprobar que el nif no existe ya
					for (j = 0; j < TVENDEDORES; j++)
					{
						if (((vendedores[i].nif.num_nif == vendedores[j].nif.num_nif) || (vendedores[i].nif.letra == vendedores[j].nif.letra)) && (j != i))
						{flag = true;}
					}
				} while(flag);
			
				printf("Introduzca el nombre del vendedor (max 40 caracteres): ");
				gets(vendedores[i].nombre);
				fflush(stdin);
			}
		}
	} while (ejec == 's');
}

void consulta_ventas_vendedor(Venta ventas[])
{}

void consulta_ventas_articulo(Venta ventas[])
{}

/* -------------------------------------------------------------- */// 0/2
// Funciones para consultas detalladas
void articulo_mas_vendido(Venta ventas[])
{}

void vendedor_mas_productivo(Venta ventas[])
{}