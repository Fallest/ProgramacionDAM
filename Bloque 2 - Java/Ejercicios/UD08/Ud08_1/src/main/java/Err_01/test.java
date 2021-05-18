package Err_01;

import java.io.IOException;

public class test
{

  public static void main(String args[]) throws IOException
  {
    int var = 9;
    System.err.println("\tEl valor de la variable var es " + var + ". Lanzado con la propiedad err.\n");
    System.out.println("\tEl valor de la variable var es " + var + ". Lanzado con la propiedad out.\n");
    System.err.println("\tFin del programa. Lanzado con la propiedad err.\n");
    System.out.println("\tFin del programa. Lanzado con la propiedad out.\n");
  }

}