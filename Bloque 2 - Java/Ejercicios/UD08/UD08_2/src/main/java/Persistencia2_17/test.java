package Persistencia2_17;

import java.io.*;

public class test
{
  public static void main (String[] args) throws IOException, ClassNotFoundException
  {
    boolean seguimos = true;
	Alumno alum;
	ObjectInputStream fichLect = new ObjectInputStream(new FileInputStream("clase"));
	
	System.out.println("\nLos datos de los alumnos recuperados del fichero son: ");
	
	while (seguimos == true)
	{
	  try
	  {
	    alum = (Alumno)fichLect.readObject();
	    alum.visualizar();
	  }
	  catch(EOFException e)
	  {
	    seguimos = false;
	  }
	}
	
	System.out.println("\nFin de la visualizacion de todo el contenido del fichero.");
	System.out.println("\nFIN DEL PROGRAMA");
  }
}