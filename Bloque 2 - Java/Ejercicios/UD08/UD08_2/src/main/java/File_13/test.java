package File_13;

import java.io.*;

public class test
{
  public static void main (String[] args) throws IOException
  {
    FileWriter fichEsc = new FileWriter("nuevo.txt");
	String cadTecFich, cadFichPant="";
	int car;
	char cara;
	
	System.out.print("\nInserte una frase: ");
	cadTecFich = Leer.dato();
	fichEsc.write(cadTecFich);
	fichEsc.close();
	
	FileReader fichLect = new FileReader("nuevo.txt");
	car = fichLect.read();
	while(car != -1)
	{
	  cara = (char)car;
	  cadFichPant = cadFichPant + cara;
	  car = fichLect.read();
	}
	
	System.out.println("\nLa frase leida del fichero es: " + cadFichPant);
  }
}