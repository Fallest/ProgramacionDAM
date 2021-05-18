package DataInputStream_05;

import java.io.*;

public class test
{
  public static void main(String[] args) throws IOException
  {
    DataInputStream input = new DataInputStream(System.in);
	String numInserCad;
	int numInser, suma = 0, cont = 0;
	float media;
	
	System.out.print("\nInserte un numero (pulse Enter para salir): ");
	numInserCad = input.readLine();
	
	while (!numInserCad.equals(""))
	{
	  cont++;
	  numInser = Integer.parseInt(numInserCad);
	  suma = numInser + suma;
	  
	  System.out.print("\nInserte otro numero (pulse Enter para salir): ");
	  numInserCad = input.readLine();
	}
	
	if (cont == 0)
	  System.out.println("\n\nNo visualizamos la media ya que no se ha insertado ningun numero.");
	else
	{
	  media = (float)suma/cont;
	  System.out.println("\n\nLa media de los numeros introducidos es " + media);
	}
	
	System.out.println("\n\nFIN DEL PROGRAMA\n\n");
  }
}