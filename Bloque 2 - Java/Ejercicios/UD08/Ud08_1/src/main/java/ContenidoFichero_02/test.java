package ContenidoFichero_02;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
    String cadena;
    File fiche = new File("fichero.txt"); // Crearlo en la carpeta del proyecto //
    BufferedReader flujo = new BufferedReader(new FileReader(fiche));
    if (fiche.exists())
    {
      System.out.println("\n\nEsta es la informacion que contiene el fichero: ");
	  cadena = flujo.readLine();
	  while (cadena != null)
	  {
	    if (!cadena.equals("\n"))
	      System.out.println(cadena);

	    cadena = flujo.readLine();
	  }
    }
    System.out.println("\nFIN DEL PROGRAMA\n");
  }
}