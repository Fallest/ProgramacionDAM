package BufferedReader_14;

import java.io.*;

public class test
{
  public static void main (String[] args) throws IOException
  {
    FileWriter fichEsc = new FileWriter("nuevo.txt");
	String cadTecFich, cadFichPant="";
	
	System.out.println("\nInserte una frase: ");
	cadTecFich = Leer.dato();
	fichEsc.write(cadTecFich);
	fichEsc.close();
	
	FileReader fichLect = new FileReader("nuevo.txt");
	BufferedReader buffer = new BufferedReader(fichLect);
	cadFichPant = buffer.readLine();
	System.out.println("\nLa frase leida del fichero es: " + cadFichPant);
  }
}