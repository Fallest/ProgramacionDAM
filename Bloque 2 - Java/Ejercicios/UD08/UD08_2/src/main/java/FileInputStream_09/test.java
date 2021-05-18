package FileInputStream_09;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
        int c;
	try
	{
	  FileInputStream f = new FileInputStream("fichero.txt"); // Vale / o \ //
	  // Buscara en la raiz del disco donde esta el proyecto, si no pongo la barra buscara en la carpeta actual //
	  
	  while ((c=f.read()) != -1)
	    System.out.println((char)c); // Si no se hace la conversion visualiza su codigo ASCII //
	
	  f.close();
	}
	catch (FileNotFoundException e)
	{
	  System.out.println("\nEl fichero no existe.\n");
	}
  }
}