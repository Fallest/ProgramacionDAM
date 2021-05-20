package Tarea_11;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
        int c;
	FileOutputStream fichSal = new FileOutputStream("tarea_11/fichCopia.txt"); // Se abre el fichero donde se hara la copia //
	
	try
	{
                FileInputStream fichEnt = new FileInputStream("tarea_11/fichero.txt");
                System.out.println("\nSe esta realizando la copia del fichero. Por favor, espere.");
                int caracteres = fichEnt.available();
                while ((c = fichEnt.read()) != -1)
                {
                    fichSal.write(c);
                }
                System.out.println("\n\nHa finalizado la copia del fichero.");
                System.out.println("Caracteres en el fichero original: " + caracteres);
                
                fichEnt = new FileInputStream("tarea_11/fichero.txt");
                System.out.println("\nContenido del original: ");
                while ((c=fichEnt.read()) != -1) {
                    System.out.print((char)c);
                }
	}
	catch(FileNotFoundException e)
	{
	  System.out.println("\n\nNo se puede leer el fichero, no existe.");
	}
	finally
	{
            try (FileInputStream fichCopiaSal = new FileInputStream("tarea_11/fichCopia.txt")) {
                int c2;
                System.out.println("\nContenido de la copia: \n");
                while ((c2=fichCopiaSal.read()) != -1) {
                    System.out.print((char)c2);
                }
            }
            fichSal.close();
	}
  }
}