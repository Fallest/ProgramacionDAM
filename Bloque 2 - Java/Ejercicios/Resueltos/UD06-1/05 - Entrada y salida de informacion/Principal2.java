package ejercicio1;

import java.io.*;

public class Principal2
{
  public static void main(String args[]) throws IOException
  {
    int numinsert = 0;
    String lin;

    InputStreamReader flujo = new InputStreamReader(System.in);
    BufferedReader teclado = new BufferedReader(flujo);

    System.out.print("Inserte un numero entero: ");
    lin = teclado.readLine();

    numinsert = Integer.parseInt(lin);

    System.out.println("\tEl numero insertado es " + numinsert);
    System.out.println("\nEl programa se da por finalizado.");
  }
} 
