package ModosAcceso_15;

import java.io.*;

public class test
{
  public static void main (String[] args) throws IOException
  {
    RandomAccessFile fiche;
	String nomNuevo, nombre;
	fiche = new RandomAccessFile("directo.txt","rw");
	
	System.out.println("\nInserte un nombre (ninguno para salir): ");
	nomNuevo = Leer.dato();
	
	while (!nomNuevo.equals("ninguno"))
	{
	  fiche.seek(fiche.length());
	  fiche.writeBytes(nomNuevo);
	  fiche.write('\n'); // Para separarlo del siguiente nombre que se inserte //
	  System.out.println("\nInserte otro nombre (ninguno para salir): ");
	  nomNuevo = Leer.dato();
	}
	
	fiche.seek(0);
	nombre = fiche.readLine();
	
	while(nombre != null)
	{
	  System.out.println("El nombre leido es: " + nombre);
	  nombre = fiche.readLine();
	}
	
	fiche.close();
  }
}