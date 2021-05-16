#include <stdlib.h>
#include <string.h>

/*
Estructuras:
	-Línea: Número de teléfono, descripción y registro de llamadas.
	-Llamada: Fecha (día, mes, año), hora de inicio (hora y minutos),
	duración de la llamada en minutos.
	-Nodos para cada tipo.
*/
// Estructuras para llamada.
typedef struct {
	int dia;
	int mes;
	int anyo;
} Fecha;

typedef struct {
	int hora;
	int min;
} Hora;

typedef struct {
	Fecha fecha;
	Hora horaIni;
	int duracion;
} Llamada;

typedef struct nodoLlamada{
	Llamada llamada;
	struct nodoLlamada * next;
} NodoLlamada;


// Estructuras para Linea.
typedef struct {
	int numTlf;
	char descrip[40];
	NodoLlamada * registroLlamadas; // Lista para las llamadas. Funciona como pila.
} Linea;

typedef struct nodoLinea{
	Linea linea;
	struct nodoLinea * next;
} NodoLinea;

// Prototipos:
void mostrarMenu();
void leerOpcion(int * opcion);
void ejecOpcion(int opcion, NodoLinea * listaLineas);

void altaLinea(NodoLinea * listaLineas);

void altaLlamada(NodoLinea * listaLineas);
void introducirLlamada(NodoLinea * listaLineas, Fecha fechaIn, Hora horaIn, int duracionIn, int numTelef);
char preguntar();
Fecha pedirFecha();
Hora pedirHoraIni();
int pedirDuracion();

void listadoFact(NodoLinea * listaLineas);
float calcularFactura(int minutos);

void cancelarLinea(NodoLinea * listaLineas);
void eliminarLinea(NodoLinea * listaLineas, int numTelef);

int pedirNumero();
char comprobarNumero(NodoLinea * listaLineas, int numero);

/*---------------------------------------------------------*/// 1/1
// Main
void main() {
	int opcion;
	NodoLinea * listaLineas = NULL;

	do {
		mostrarMenu();
		leerOpcion(&opcion);
		ejecOpcion(opcion, listaLineas);
	} while (opcion != 7);
}

/*---------------------------------------------------------*/// 3/3
// Funciones de menú
void mostrarMenu() {
	printf("-----MENU-----\n");
	printf("1. Alta de linea\n");
	printf("2. Alta de llamada\n");
	printf("3. Listado de facturacion\n");
	printf("4. Cancelacion de una linea\n");
	printf("5. Salir\n");
	printf("--------------\n");
}

void leerOpcion(int * opcion) {
	do {	
		printf("Introduzca una opción: ");
		scanf("%d", opcion);
		fflush(stdin);
	} while ((*opcion) < 1 || (*opcion) > 7);
}

void ejecOpcion(int opcion, NodoLinea * listaLineas) {
	switch {
		case 1: {
			altaLinea(listaLineas);
			break;
		}
		case 2: {
			altaLlamada(listaLineas);
			break;
		}
		case 3: {
			listadoFact(listaLineas);
			break;
		}
		case 4: {
			cancelarLinea(listaLineas);
			break;
		}
	}
}

/*---------------------------------------------------------*/// 1/1
// Alta de línea
void altaLinea(NodoLinea * listaLineas) {
	char cad[40];
	int numTelef;
	// Reservamos espacio para el nuevo nodo.
	NodoLinea * nuevoNodo;
	nuevoNodo = (NodoLinea *) malloc (sizeof(NodoLinea));
	// Asignamos valores al nodo.
	printf("Introduzca el numero para la linea: \n");
	scanf("%d", &numTelef);
	fflush(stdin);
	(nuevoNodo -> linea).numTlf = numTelef;

	printf("Introduzca una descripcion para la linea: \n");
	gets(cad);
	fflush(stdin);
	strcpy((nuevoNodo -> linea).descrip, cad);

	// Reasignación de los punteros:
	NodoLinea * iter = listaLineas; // Puntero aux.

	// Iteramos sobre la lista con un puntero auxiliar,
	// para llegar al último elemento insertado.
	while (iter != NULL) 
		iter = iter -> next;

	// Intercambio de punteros.
	nodoNuevo -> next = iter -> next;
	iter -> next = nodoNuevo;
}

/*---------------------------------------------------------*/// 5/5
// Alta de llamada
void altaLlamada(NodoLinea * listaLineas) {
	int numTelef = pedirNumero();
	char existe = comprobarNumero(numTelef);

	if (existe == 's') {
		// Código para dar de alta la llamada en el teléfono.
		Fecha fechaIn = pedirFecha();
		Hora horaIn = pedirHoraIni();
		int duracionIn = pedirDuracion();

		introducirLlamada(listaLineas, fechaIn, horaIn, duracionIn, numTelef);	
	}
	else {
		// Código para preguntar si se quiere dar de alta el teléfono.
		char darAlta = preguntar();

		if (darAlta == 's') {
			altaLinea(listaLineas); // Dar de alta el teléfono.
		}
	}

	if (existe == 's' || darAlta == 's') {
		// Código para introducir los datos de la llamada al registro.
		Fecha fechaIn = pedirFecha();
		Hora horaIn = pedirHoraIni();
		int duracionIn = pedirDuracion();

		introducirLlamada(listaLineas, fechaIn, horaIn, duracionIn, numTelef);
	}
}

void introducirLlamada(NodoLinea * listaLineas, Fecha fechaIn, Hora horaIn, int duracionIn, int numTelef) {
	// Reservamos espacio para el nuevo nodo.
	NodoLlamada * nuevaLlamada;
	nuevaLlamada = (NodoLlamada *) malloc (sizeof(NodoLlamada));

	// Asignamos valores al nodo.
	(nuevaLlamada -> llamada).fecha = fechaIn;
	(nuevaLlamada -> llamada).horaIni = horaIn;
	(nuevaLlamada -> llamada).duracion = duracionIn;

	// Reasignación de los punteros:
	NodoLinea * iter = listaLineas; // Puntero aux.

	// Iteramos sobre la lista de líneas con un puntero auxiliar,
	// para llegar a la línea que buscamos.
	while (iter != NULL) {
		// Buscamos el teléfono dado por parámetros.
		if ((iter -> linea).numTlf == numTelef) {
			// Si lo encontramos, vamos a introducir la llamada en el registro.
			// Así que vamos a crear un puntero auxiliar para el registro.
			NodoLlamada * iterReg = (iter -> linea).registroLlamadas;
			// Vamos a buscar la última posición
			while (iterReg != NULL) 
				iterReg = iterReg -> next;
			// Y vamos a sustituir los punteros
			nuevaLlamada -> next = iterReg -> next;
			iterReg -> next = nuevaLlamada;
			break; // Salimos del bucle, no hay nada más que hacer.
		}
		else
			iter = iter -> next;
	}
	// Debido a que se va a entrar a esta función solo cuando exista el número
	// de teléfono en el listado, nunca se va a salir del bucle while porque
	// se llegue al final de la lista.
}

char preguntar() {
	char res;

	printf("Quiere dar el numero de alta? (s/n): ");
	scanf("%c", &res);
	fflush(stdin);

	return res;
}

Fecha pedirFecha() {
	Fecha fechaRes;

	printf("Introduzca la fecha (DD/MM/YYYY): ");
	scanf("%d/%d/%d", &fechaRes.dia, &fechaRes.mes, &fechaRes.anyo);
	fflush(stdin);

	return fechaRes;
}

Hora pedirHoraIni() {
	Hora horaRes;

	printf("Introduzca la hora de inicio de la llamada (HH:MM): ");
	scanf("%d:%d", &horaRes.hora, &horaRes.min);
	fflush(stdin);

	return horaRes;
}

int pedirDuracion() {
	int duracionRes;

	printf("Introduzca la duracion en minutos de la llamada: ");
	scanf("%d", &duracionRes);
	fflush(stdin);

	return duracionRes;
}

/*---------------------------------------------------------*/// 2/2
// Listado de facturación
void listadoFact(NodoLinea * listaLineas) {
	/* 
	Mostrará un listado con el formato:
	-----------------------------------
	Número: 123456789
	Descripción: Número de ejemplo.
	Minutos Totales: 12 minutos.
	Importe total: 1,2 euros.
	-----------------------------------
	*/
	// Necesitamos dos iteradores, uno para recorrer la lista de líneas,
	// otro interno al while que se usará para recorrer las llamadas.
	NodoLinea * iterLineas = listaLineas;
	NodoLlamada * iterReg;
	int minTotales = 0;
	float importe;

	while (iterLineas != NULL) {
		iterReg = (iterLineas -> linea).registroLlamadas;

		while (iterReg != NULL) {
			minTotales += (iterReg -> llamada).duracion;
			iterReg = iterReg -> next;
		}

		importe = calcularFactura(minTotales);

		printf("-----------------------------------\n");

		printf("Numero: %d\n", (iterLineas -> linea).numTlf);
		printf("Descripcion: %s\n", (iterLineas -> linea).descrip);
		printf("Minutos totales: %d\n", minTotales);
		printf("Importe total: %f\n", importe);

		printf("-----------------------------------\n");
	}
}

float calcularFactura(int minutos) {
	return (float) minutos * 0.1f;
}

/*---------------------------------------------------------*/// 2/2
// Cancelar línea
void cancelarLinea(NodoLinea * listaLineas) {
	// Hay que preguntar al usuario por un teléfono:
	int numTelef = pedirNumero();
	char existe = comprobarNumero(numTelef);

	if (existe == 's') {
		// Código para eliminar la línea de ese teléfono.
		eliminarLinea(listaLineas, numTelef);
	}
	else {
		printf("Ese numero no existe.\n");	
	}
}

void eliminarLinea(NodoLinea * listaLineas, int numTelef) {
	// Debemos buscar la línea con el teléfono indicado.
	NodoLinea * iterLineas = listaLineas;
	NodoLlamada * iterReg;
	NodoLinea * nodoBorrar;

	while (iterLineas != NULL) {
		nodoBorrar = iterLineas -> next;
		if ((nodoBorrar -> linea).numTlf == numTelef) {
			// Si lo encontramos, tenemos que liberar primero el registro de llamadas.
			iterReg = (nodoBorrar -> linea).registroLlamadas;
			// Liberar el espacio nodo a nodo del registro.
			while (iterReg != NULL) {
				(nodoBorrar -> linea).registroLlamadas = iterReg -> next;
				free(iterReg);
				iterReg = (nodoBorrar -> linea).registroLlamadas;
			}
			// Con el registro de llamadas vacío, liberamos el nodo a borrar.
			iterLineas -> next = nodoBorrar -> next;
			free(nodoBorrar);
			printf("Nodo borrado.\n"); // Feedback al usuario.
			break; // Salimos, no hay nada más que hacer.
		}
		else
			iterLineas = iterLineas -> next;
	}
}

/*---------------------------------------------------------*/// 2/2
// Funciones de utilidades
int pedirNumero() {
	int numeroTelef;

	printf("Introduzca un numero de telefono: ");
	scanf("%d", &numeroTelef);
	fflush(stdin);

	return numeroTelef;
}

char comprobarNumero(NodoLinea * listaLineas, int numero) {
	// Se va a iterar sobre la lista, buscando un número.
	// Devuelve 's' si existe, 'n' en caso contrario.
	NodoLinea * iter = listaLineas;
	char existe = 'n';

	while (iter != NULL) {
		if ((iter -> linea).numTlf == numero) {
			existe = 's';
			break;
		}
		else
			iter = iter -> next;
	}

	return existe;
}