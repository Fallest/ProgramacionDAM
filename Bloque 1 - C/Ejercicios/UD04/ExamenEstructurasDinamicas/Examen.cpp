#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CADTAM 40
/*----------------------------------------------------------------*/
// Estructuras

typedef struct {
	int dia;
	int mes;
	int anyo;
} Fecha;

typedef struct {
	int num;
	char letra;
} Dni;
/*----------------------------*/
// Visitante
typedef struct
{
	Dni dni;
	char nombre[CADTAM];
	Fecha fecha;
	int nPreso;
} Visitante;
// Lista de visitantes (estructura principal)
typedef struct nodo
{
	Visitante visitante;
	struct nodo * next;
} nodoVisitante;
/*----------------------------*/
// Nodo para la sublista para las estadisticas de los presos
typedef struct {
	Dni dniVisita;
	char nomVisita[CADTAM];
	Fecha fechaVisita;
} VisitaPreso;
// Lista principal para los presos
typedef struct nodopreso {
	int nPreso;
	VisitaPreso * visitasPreso; // Sublista
	struct nodopreso * next;
} nodoEstPreso;
/*----------------------------*/
// Nodo para la sublista para las estadisticas de los visitantes
typedef struct {
	Fecha fecha;
	int nPreso;
} Visita;
// Lista principal para los visitantes
typedef struct nodovisita {
	Dni dniVisita;
	char nomVisita[CADTAM];
	Visita * visitasVisitante; // Sublista
	struct nodovisita * next;
} nodoEstVisita;

/*----------------------------------------------------------------*/
// Prototipos

	// Para pedir datos:
void pedirDatos(nodoVisitante *listaVisitas);
char preguntar();

	// Para dar de alta nuevos nodos:
void altaVisitante(nodoVisitante *listaVisitas);
Fecha pedirFecha();
Dni pedirDni();
char * pedirNombre();
int pedirNumPreso();

	// Para mostrar las estadisticas:
void preguntarEstadistica(nodoVisitante * listaVisitas, nodoEstVisita * listaEstVisitantes, nodoEstPreso * listaEstPresos);
nodoEstVisita * crearListaEstVisitantes(nodoVisitante * listaVisitas);
nodoEstPreso * crearListaEstPresos(nodoVisitante * listaVisitas);

	// Para eliminar la lista original
void eliminarListaOriginal(nodoVisitante * listaVisitas);

	// Para mostrar los datos de las listas de estadisticas.
void mostrarDatosPorPrisionero(nodoEstPreso * listaEstPresos);
void mostrarDatosPorVisitante(nodoEstVisita * listaEstVisitas);

	// Para destruir las dos listas que quedan
void elimListaEstVis(nodoEstVisita * listaEstVisitas);
void elimListaEstPre(nodoEstPreso * listaEstPresos);
/*----------------------------------------------------------------*/// 1/1
// Main

void main() {
	nodoVisitante * listaVisitas = NULL;
	nodoEstVisita * listaEstVisitantes = NULL;
	nodoEstPreso * listaEstPresos = NULL;

	pedirDatos(listaVisitas);

	preguntarEstadistica(listaVisitas, listaEstVisitantes, listaEstPresos); // Implementación incompleta

	eliminarListaOriginal(listaVisitas);

	mostrarDatosPorVisitante(listaEstVisitantes);	// Falta por implementar
	mostrarDatosPorPrisionero(listaEstPresos);		// Falta por implementar

	elimListaEstPre(listaEstPresos);
	elimListaEstVis(listaEstVisitantes);
}

/*----------------------------------------------------------------*/// 2/2
// Función para pedir los datos de forma iterativa
void pedirDatos(nodoVisitante *listaVisitas) {
	do {
		altaVisitante(listaVisitas);
	} while (preguntar() == 's');
}

char preguntar() {
	char res;

	do {	
		printf("Quiere introducir otro visitante? (s/n): ");
		scanf("%c", res);
		fflush(stdin);
	} while (res != 's' && res != 'n');

	return res;
}


/*----------------------------------------------------------------*/// 5/5
// Funciones para registrar visitantes
void altaVisitante(nodoVisitante *listaVisitas) {
	// Reservamos espacio para el nuevo nodo.
	nodoVisitante * nuevoNodo;
	nuevoNodo = (nodoVisitante *) malloc (sizeof(nodoVisitante));

	// Asignamos valores al nodo.
	((nuevoNodo -> visitante).dni) = pedirDni();

	strcpy((nuevoNodo -> visitante).nombre, pedirNombre());

	(nuevoNodo -> visitante).fecha = pedirFecha();

	(nuevoNodo -> visitante).nPreso = pedirNumPreso();

	// Reasignación de los punteros:
	if (listaVisitas == NULL)
		listaVisitas = nuevoNodo;
	else {
		// Iteramos sobre la lista con un puntero auxiliar,
		// para llegar al último elemento insertado.
		nodoVisitante * iter = listaVisitas; // Puntero aux.
		while ((iter -> next) != NULL) 
			iter = iter -> next;

		// Intercambio de punteros.
		nuevoNodo -> next = iter -> next;
		iter -> next = nuevoNodo;
	}

	printf("Visitante registrado.\n");
}

		// Funciones auxiliares para dar de alta visitantes
	Fecha pedirFecha() {
		Fecha fechaRes;

		printf("Introduzca la fecha (DD/MM/YYYY): ");
		scanf("%d/%d/%d", &fechaRes.dia, &fechaRes.mes, &fechaRes.anyo);
		fflush(stdin);

		return fechaRes;
	}

	Dni pedirDni() {
		Dni dniRes;

		printf("Introduzca el DNI (99999999-L): \n");
		scanf("%d-%c", &dniRes.num, &dniRes.letra);
		fflush(stdin);

		return dniRes;
	}

	char * pedirNombre() {
		char nombre[CADTAM];

		printf("Introduzca el nombre del visitante: \n");
		gets(nombre);
		fflush(stdin);

		return nombre;
	}

	int pedirNumPreso() {
		int numRes;

		printf("Introduzca el numero del preso al que se va a visitar: \n");
		scanf("%d", &numRes);
		fflush(stdin);

		return numRes;
	}

/*----------------------------------------------------------------*/// 1/3
/*
	NOTA: Las funciones crearListaEstVisitantes y crearListaEstPresos, crean las listas
	para las estadísticas de lo que el usuario haya escodigo. Les falta código: crean la
	sublista, pero no añaden datos a ella.
*/
// Estadísticas:

void preguntarEstadistica(nodoVisitante * listaVisitas, nodoEstVisita * listaEstVisitantes, nodoEstPreso * listaEstPresos) {
	char res;

	// Preguntar al usuario
	do {
		printf("Escriba 'v' para consultar las estadisticas de los visitantes.\n");
		printf("Escriba 'p' para consultar las estadisticas de los presos.\n");
		scanf("%c", &res);
	} while (res != 'p' && res != 's');

	// Escoger una ruta dependiendo de la opción escogida por el usuario
	if (res == 'v') {
		// Código para mostrar las estadísticas de los visitantes
		listaEstVisitantes = crearListaEstVisitantes(listaVisitas);
	}
	else {
		// Código para mostrar las estadísticas de los presos
		listaEstPresos = crearListaEstPresos(listaVisitas);
	}
}

nodoEstVisita * crearListaEstVisitantes(nodoVisitante * listaVisitas) {
	// De momento solo crea la lista de estadísticas de visitantes, sin la sublista - Falta

	nodoEstVisita * listaEstVisitantesRES = NULL;
	nodoEstVisita * nodoNuevo;

	nodoVisitante * iter = listaVisitas; // Para iterar sobre la lista

	nodoVisitante * aux = iter;

	while (iter -> next != NULL) {
		if ((iter -> visitante).dni == (aux -> visitante).dni) {
			// Código para añadir los datos a la sublista
		}
		else {
			// Código para añadir los datos del nodo actual a la lista
			// Reservamos espacio
			nodoNuevo = (nodoEstVisita *) malloc (sizeof(nodoEstVisita));

			// Asginamos valores
			nodoNuevo -> dniVisita = (iter -> visitante).dni;
			nodoNuevo -> nomVisita = (iter -> visitante).nombre;
			nodoNuevo -> visitasVisitante = NULL; // Creo la sublista, pero no voy a añadir datos.

			// Reasignamos punteros
			if (listaEstVisitantesRES == NULL)
				listaEstVisitantesRES = nodoNuevo;

			else {
				nodoEstVisita * iterVisitas = listaEstVisitantesRES;

				while ((iterVisitas -> next) != NULL) 
					// Aquí iría código para insertarlo ordenado ---------- Falta
					iterVisitas = iterVisitas -> next;

				nodoNuevo -> next = iterVisitas -> next;
				iterVisitas -> next = nodoNuevo;
			}
		}
		// No sé cómo reasignar el aux para que siga comparando los datos correctos. - Falta
		iter = iter -> next;
	}

	return listaEstVisitantesRES;
}

nodoEstPreso * crearListaEstPresos(nodoVisitante * listaVisitas) {
	// De momento solo crea la lista de estadísticas de presos, sin la sublista - Falta

	nodoEstPreso * listaEstPresosRES = NULL;
	nodoEstPreso * nodoNuevo;

	nodoVisitante * iter = listaVisitas; // Para iterar sobre la lista

	nodoVisitante * aux = iter;

	while (iter -> next != NULL) {
		if ((iter -> visitante).dni == (aux -> visitante).dni) {
			// Código para añadir los datos a la sublista
		}
		else {
			// Código para añadir los datos del nodo actual a la lista
			// Reservamos espacio
			nodoNuevo = (nodoEstPreso *) malloc (sizeof(nodoEstPreso));

			// Asginamos valores
			nodoNuevo -> nPreso = (iter -> visitante).nPreso;
			nodoNuevo -> visitasPreso = NULL; // Creo la sublista, pero no voy a añadir datos.

			// Reasignamos punteros
			if (listaEstPresosRES == NULL)
				listaEstPresosRES = nodoNuevo;

			else {
				nodoEstPreso * iterPresos = listaEstPresosRES;

				while ((iterPresos -> next) != NULL) 
					// Aquí iría código para insertarlo ordenado ---------- Falta
					iterPresos = iterPresos -> next;

				nodoNuevo -> next = iterPresos -> next;
				iterPresos -> next = nodoNuevo;
			}
		}
		// No sé cómo reasignar el aux para que siga comparando los datos correctos. - Falta
		iter = iter -> next;
	}

	return listaEstPresosRES;
}

/*----------------------------------------------------------------*/// 1/1
// Eliminar la lista principal (la original)
void eliminarListaOriginal(nodoVisitante * listaVisitas) {
	// Hay que eliminar nodo a nodo, y luego eliminar la lista.
	nodoVisitante * iter = listaVisitas;

	while (iter != NULL) {
		listaVisitas = iter -> next;
		free(iter);
		iter = listaVisitas;
	}
}

/*----------------------------------------------------------------*/// 0/2
// Funciones para mostrar los datos de las estadísticas recogidas
void mostrarDatosPorPrisionero(nodoEstPreso * listaEstPresos) {
	if (listaEstPresos != NULL) {
		// Código para mostrar los datos de la lista de estadísticas de los prisioneros
	}
}
void mostrarDatosPorVisitante(nodoEstVisita * listaEstVisitas) {
	if (listaEstVisitas != NULL) {
		// Código para mostrar los datos de la lista de estadísticas de los visitantes
	}
}

/*----------------------------------------------------------------*/// 2/2
// Eliminar las listas de estadísticas
void elimListaEstPre(nodoEstPreso * listaEstPresos) {
	// Hay que eliminar nodo a nodo, y luego eliminar la lista.
	nodoEstPreso * iterPre = listaEstPresos;

	while (iterPre != NULL) {
		listaEstPresos = iterPre -> next;
		free(iterPre);
		iterPre = listaEstPresos;
	}
}

void elimListaEstVis(nodoEstVisita * listaEstVisitas) {
	// Hay que eliminar nodo a nodo, y luego eliminar la lista.
	nodoEstVisita * iterVis = listaEstVisitas;

	while (iterVis != NULL) {
		listaEstVisitas = iterVis -> next;
		free(iterVis);
		iterVis = listaEstVisitas;
	}
}