package Persistencia1_16;

import java.io.*;

public class test
{
  public static void main (String[] args) throws IOException, ClassNotFoundException
  {
        int numAl;
	
        Alumno clase[];
	ObjectOutputStream fich = new ObjectOutputStream(new FileOutputStream("clase"));
	
	System.out.println("\nCuantos alumnos tiene la clase: ");
	numAl = Leer.datoInt();
	
	clase = new Alumno[numAl];
	for (int posal = 0; posal < numAl; posal++)
	{
	  System.out.println("\nVamos a insertar los datos del alumno que ocupa la posicion " + (posal+1));
	  clase[posal] = new Alumno();
	}
	
	System.out.println("\nProcederemos a visualizar los datos de los alumnos insertados: ");
	for (int posal = 0; posal < numAl; posal++)
	{
	  System.out.println("\nLos datos del alumno insertado en la posicion " + (posal+1) + " son: ");
	  clase[posal].visualizar();
	}
	
	System.out.println("\nAntes de cerrar el programa procederemos a guardar la informacion de los alumnos en el fichero clase.");
	for (int posal = 0; posal < numAl; posal++)
	  fich.writeObject(clase[posal]);
	
	fich.close();
  }
}