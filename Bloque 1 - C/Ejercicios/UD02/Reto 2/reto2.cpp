#include <stdio.h>

double Calcular_importe(int h_in,int m_in,int h_out,int m_out) {
	
	if((h_in < 0) || (m_in < 0) || (h_out < 0) || (m_out < 0)) {
		return 0;
	} else {
		int h_totales = h_out - h_in;
		int m_totales = m_out - m_in;
		double importe;
		if((h_totales == 0) && (m_totales <= 30 )){
			importe = 0.5;
			return importe;
		} else{
			if(h_totales >= 2) {
				importe = ((h_totales * 60) + m_totales) * 0.08;
				return importe;
			} else {
				importe = 0.5 + (((h_totales * 60) + m_totales) * 0.10);
				return importe;
			}// Cierre del tercer else
		} //Cierre del segundo else
	} //Cierre del primer else
}

void main(){
	int h_in, h_out, m_in, m_out;
	double importe;

	printf("Introduzca una hora de entrada:");
	scanf("%d", &h_in);
	fflush(stdin);
	printf("Introduzca unos minutos de entrada:");
	scanf("%d", &m_in);
	fflush(stdin);
	printf("Introduzca una hora de salida:");
	scanf("%d", &h_out);
	fflush(stdin);
	printf("Introduzca unos minutos de salida:");
	scanf("%d", &m_out);
	fflush(stdin);

	importe = Calcular_importe(h_in, m_in, h_out, m_out);
	if(importe == 0) {
		printf("Ha ocurrido un error en el programa. Por favor, inicialicelo con unas horas y minutos correctos.\n");
	} else {
	printf("Su importe es: %lf", importe);
	}
}