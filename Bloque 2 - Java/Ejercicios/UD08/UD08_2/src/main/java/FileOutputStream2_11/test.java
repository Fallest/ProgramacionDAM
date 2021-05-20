package FileOutputStream2_11;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
        int c;
	FileOutputStream fichSal = new FileOutputStream("fichCopia.txt"); // Se abre el fichero donde se hara la copia //
	
	try
	{
            try (FileInputStream fichEnt = new FileInputStream("fichero.txt")) {
                System.out.println("\nSe esta realizando la copia del fichero. Por favor, espere.");
                
                while ((c = fichEnt.read()) != -1)
                {
                    fichSal.write(c);
                }
                System.out.println("\n\nHa finalizado la copia del fichero.");
            }
	}
	catch(FileNotFoundException e)
	{
	  System.out.println("\n\nNo se puede leer el fichero, no existe.");
	}
	finally
	{
	  fichSal.close();
	}
  }
}