package ejercicio1;

import java.io.*;

public class Principal1
{
  public static void main(String args[]) throws IOException
  {
    String lin;
    InputStreamReader flujo = new InputStreamReader(System.in);
    BufferedReader teclado = new BufferedReader(flujo);

    /* Tambien se puede poner todo junto:
       BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
    */

    System.out.print("Inserte la linea: ");
    lin = teclado.readLine();

    System.out.println("\tLa linea es \"" + lin + "\"");
    System.out.println("\nEl programa se da por finalizado.");
  }
} 
